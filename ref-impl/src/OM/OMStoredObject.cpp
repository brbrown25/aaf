// @doc OMEXTERNAL
#include "OMStoredObject.h"
#include "OMStoredPropertySetIndex.h"
#include "OMProperty.h"
#include "OMPropertySet.h"
#include "OMStoredVectorIndex.h"
#include "OMTypes.h"

#include "OMAssertions.h"
#include "OMUtilities.h"

#include <iostream.h>

#if defined(_MAC) || defined(macintosh)
#include "wintypes.h"
#include <storage.h>
#else
#include <objbase.h>
#endif

const int currentVersion = 4;

const size_t indexHeaderSize = sizeof(OMByteOrder) +  // Byte order flag
                               sizeof(OMUInt32) +     // Version number
                               sizeof(OMUInt32);      // Count of entries

const size_t indexEntrySize  = sizeof(OMPropertyId) + // Property id
                               sizeof(OMUInt32) +     // Type
                               sizeof(OMUInt32) +     // Offset
                               sizeof(OMUInt32);      // Length

#if defined(__sgi)
#define OMQUADPART(x) x.u.QuadPart
#define OMSETQUADPART(x,y) (OMQUADPART(x) = (y))
#elif defined(_MAC) || defined(macintosh)

// The mac declarations for LARGE_INTEGER and ULARGE_INTEGER don't
// have a QuadPart because the HighPart and LowPart components on that
// platform are not in the natural platform order.

static inline OMUInt64 swapHighLowParts(ULARGE_INTEGER &x)
{
  OMUInt64 y = (x.HighPart << 32) + (x.LowPart);
  return y;
}

static inline void setHighLowParts(ULARGE_INTEGER &x, const OMUInt64& y)
{
  x.HighPart = (unsigned long)((0xFFFFFFFF00000000 & (OMUInt64)y) >> 32);
  x.LowPart  = (unsigned long) (0x00000000FFFFFFFF & (OMUInt64)y);
}

#define OMQUADPART(x) (swapHighLowParts(x))
#define OMSETQUADPART(x,y) (setHighLowParts((x),(y)))
#else
#define OMQUADPART(x) x.QuadPart
#define OMSETQUADPART(x,y) (OMQUADPART(x) = (y))
#endif

#if defined(_WIN32) && defined(UNICODE)
  typedef wchar_t OMCHAR;
#else
  typedef char OMCHAR;
#endif

static void convert(wchar_t* wcName, size_t length, const char* name);

static void convert(char* cName, size_t length, const wchar_t* name);

static void convert(char* cName, size_t length, const char* name);

static void convert(wchar_t* wcName, size_t length, const wchar_t* name);

static void formatError(DWORD errorCode);

static int check(HRESULT resultCode);

static int checkFile(HRESULT resultCode, const wchar_t* fileName);

static int checkStream(HRESULT resultCode, const char* streamName);

static int checkStorage(HRESULT resultCode, const char* storageName);

static void printError(const char* prefix, const char* type);

static void printName(const char* name);

static void printName(const wchar_t* name);

OMStoredObject::OMStoredObject(IStorage* s)
: _storage(s), _index(0), _indexStream(0), _propertiesStream(0),
  _offset(0), _open(false), _mode(readOnlyMode),
  _byteOrder(hostByteOrder()), _reorderBytes(false)
{
}

OMStoredObject::~OMStoredObject(void)
{
}

  // @mfunc Open the root <c OMStoredObject> in the disk file
  //        <p fileName> for reading only.
  //   @parm The name of the file to open. The file must already exist.
  //   @rdesc An <c OMStoredObject> representing the root object in
  //          the disk file.
OMStoredObject* OMStoredObject::openRead(const wchar_t* fileName)
{
  OMStoredObject* newStoredObject = OMStoredObject::open(fileName,
                                                         readOnlyMode);
  newStoredObject->open(readOnlyMode);

  return newStoredObject;
}

  // @mfunc Open the root <c OMStoredObject> in the disk file
  //        <p fileName> for modification.
  //   @parm The name of the file to open. The file must already exist.
  //   @rdesc An <c OMStoredObject> representing the root object in
  //          the disk file.
OMStoredObject* OMStoredObject::openModify(const wchar_t* fileName)
{
  OMStoredObject* newStoredObject = OMStoredObject::open(fileName,
                                                         modifyMode);
  newStoredObject->open(modifyMode);

  return newStoredObject;
}

  // @mfunc Create a new root <c OMStoredObject> in the disk file
  //        <p fileName>. The byte order of the newly created root
  //        is given by <p byteOrder>.
  //   @parm The name of the file to create. The file must not exist.
  //   @parm The desired byte ordering for the new file.
  //   @rdesc An <c OMStoredObject> representing the root object in
  //          the disk file.
OMStoredObject* OMStoredObject::createModify(const wchar_t* fileName,
                                             const OMByteOrder byteOrder)
{
  OMStoredObject* newStoredObject = OMStoredObject::create(fileName);
  newStoredObject->create(byteOrder);

  return newStoredObject;
}

OMStoredObject* OMStoredObject::openStoragePath(const char* storagePathName)
{
  TRACE("OMStoredObject::openStoragePath");
  PRECONDITION("Valid stream path name", validString(storagePathName));
  PRECONDITION("Path name is absolute", storagePathName[0] == '/');

  char* path = new char[strlen(storagePathName) + 1];
  ASSERT("Valid heap pointer", path != 0);
  strcpy(path, storagePathName);
  
  char* element = path;
  element++; // skip first '/'

  OMStoredObject* storage = this;
  OMStoredObject* result = 0;

  char* end = strchr(element, '/');
  
  while (end != 0) {
    *end = 0;
    storage = storage->open(element);
    ASSERT("Valid storage pointer", storage != 0);
    element = ++end;
    end = strchr(element, '/');
  }

  if ((element != 0) && (strlen(element) > 0)) {
    result = storage->open(element);
  } else {
    result = storage;
  }
  
  return result;
}

  // @mfunc Save the <c OMPropertSet> <p p properties> in this
  //        <c OMStoredObject>.
  //   @parm The <c OMPropertySet> to save.
void OMStoredObject::save(const OMPropertySet& properties)
{
  TRACE("OMStoredObject::save(OMPropertySet)");
  PRECONDITION("Already open", _open);

  size_t count = properties.count();
  size_t context = 0;
  for (size_t i = 0; i < count; i++) {
    OMProperty* p = 0;
    properties.iterate(context, p);
    ASSERT("Valid property", p != 0);
    p->save();
  }

  validate(&properties, _index);

  save(_index);

}

void OMStoredObject::save(OMStoredPropertySetIndex* index)
{
  TRACE("OMStoredObject::save(OMStoredPropertySetIndex*)");
  PRECONDITION("Already open", _open);
  PRECONDITION("Valid index", index->isValid());
  PRECONDITION("At start of index stream", streamPosition(_indexStream) == 0);

  // The number of entries in the index.
  //
  OMUInt32 entries = index->entries();

  // Compute the size of the index stream.
  //
  size_t indexStreamSize = indexHeaderSize + (entries * indexEntrySize);

  // Set the index stream size. This avoids paying the cost of growing
  // the stream during writes, it also avoids leaving garbage at the
  // end of the stream if the index has shrunk.
  //
  streamSetSize(_indexStream, indexStreamSize);

  // Write byte order flag.
  //
  ASSERT("Index in native byte order", _byteOrder == hostByteOrder());
  writeToStream(_indexStream, &_byteOrder, sizeof(_byteOrder));

  // Write version number.
  //
  OMUInt32 version = currentVersion;
  writeToStream(_indexStream, &version, sizeof(version));
  
  // Write count of entries.
  //
  writeToStream(_indexStream, &entries, sizeof(entries));
  
  // Write entries.
  //
  OMPropertyId propertyId;
  OMUInt32 type;
  OMUInt32 offset;
  OMUInt32 length;
  size_t context = 0;
  for (size_t i = 0; i < entries; i++) {
    index->iterate(context, propertyId, type, offset, length);
    writeToStream(_indexStream, &propertyId, sizeof(propertyId));
    writeToStream(_indexStream, &type, sizeof(type));
    writeToStream(_indexStream, &offset, sizeof(length));
    writeToStream(_indexStream, &length, sizeof(length));
  }

  streamSetPosition(_indexStream, 0);
  POSTCONDITION("At start of index stream", streamPosition(_indexStream) == 0);
  POSTCONDITION("Consistent index stream size",
                                  indexStreamSize == streamSize(_indexStream));
}

OMStoredPropertySetIndex* OMStoredObject::restore(void)
{
  TRACE("OMStoredObject::restore");
  PRECONDITION("Already open", _open);
  PRECONDITION("At start of index stream", streamPosition(_indexStream) == 0);

  // Read byte order flag.
  //
  readFromStream(_indexStream, &_byteOrder, sizeof(_byteOrder));
  if (_byteOrder == hostByteOrder()) {
    _reorderBytes = false;
  } else {
    _reorderBytes = true;
  }

  // Read version number.
  //
  OMUInt32 version;
  readUInt32FromStream(_indexStream, version, _reorderBytes);
  ASSERT("Recognized version number", version == currentVersion);
  
  // Read count of entries.
  //
  OMUInt32 entries;
  readUInt32FromStream(_indexStream, entries, _reorderBytes);
  OMStoredPropertySetIndex* index = new OMStoredPropertySetIndex(entries);
  ASSERT("Valid heap pointer", index != 0);

  // Read entries.
  //
  OMPropertyId propertyId;
  OMUInt32 type;
  OMUInt32 offset;
  OMUInt32 length;
  for (size_t i = 0; i < entries; i++) {
    readUInt32FromStream(_indexStream, propertyId, _reorderBytes);
    readUInt32FromStream(_indexStream, type, _reorderBytes);
    readUInt32FromStream(_indexStream, offset, _reorderBytes);
    readUInt32FromStream(_indexStream, length, _reorderBytes);
    index->insert(propertyId, type, offset, length);
  }
  
  streamSetPosition(_indexStream, 0);
  POSTCONDITION("At start of index stream", streamPosition(_indexStream) == 0);
  POSTCONDITION("Valid index", index->isValid());
  return index;
}

  // @mfunc Restore the <c OMPropertySet> <p properties> into
  //        this <c OMStoredObject>.
  //   @parm The <c OMPropertySet> to restore.
void OMStoredObject::restore(OMPropertySet& properties)
{
  TRACE("OMStoredObject::restore");
  PRECONDITION("Already open", _open);
  PRECONDITION("At start of properties stream",
               streamPosition(_propertiesStream) == 0);

  size_t entries = _index->entries();
  
  OMPropertyId propertyId;
  OMUInt32 type;
  OMUInt32 offset;
  OMUInt32 length;
  size_t context = 0;
  for (size_t i = 0; i < entries; i++) {
    _index->iterate(context, propertyId, type, offset, length);
    OMProperty* p = properties.get(propertyId);
    ASSERT("Valid property", p != 0);
    p->restoreFrom(*this, length);
  }

  validate(&properties, _index);

  streamSetPosition(_propertiesStream, 0);
  POSTCONDITION("At start of properties stream",
                streamPosition(_propertiesStream) == 0);
}

OMStoredObject* OMStoredObject::open(const wchar_t* fileName,
                                     const OMAccessMode mode)
{
  TRACE("OMStoredObject::open");
  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid mode", (mode == modifyMode) || (mode == readOnlyMode));

  DWORD openMode;
  if (mode == modifyMode) {
    openMode = STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
  } else if (mode == readOnlyMode) {
    openMode = STGM_DIRECT | STGM_READ      | STGM_SHARE_EXCLUSIVE;
  }

  OMCHAR omFileName[256];
  convert(omFileName, 256, fileName);

  HRESULT result;
  IStorage* storage = 0;

  result = StgOpenStorage(
    omFileName,
    0,
    openMode,
    0,
    0,
    &storage);
  if (!checkFile(result, fileName)) {
    exit(FAILURE);
  }

  OMStoredObject* newStoredObject = new OMStoredObject(storage);
  ASSERT("Valid heap pointer", newStoredObject != 0);

  return newStoredObject;
}

OMStoredObject* OMStoredObject::create(const wchar_t* fileName)
{
  TRACE("OMStoredObject::create");
  PRECONDITION("Valid file name", validWideString(fileName));

  OMCHAR omFileName[256];
  convert(omFileName, 256, fileName);

  HRESULT result;
  IStorage* storage = 0;

  result = StgCreateDocfile(
    omFileName,
    STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_FAILIFTHERE,
    0,
    &storage);
  if (!checkFile(result, fileName)) {
    exit(FAILURE);
  }

  OMStoredObject* newStoredObject = new OMStoredObject(storage);
  ASSERT("Valid heap pointer", newStoredObject != 0);

  return newStoredObject;
}

static const char* const propertyIndexStreamName = "property index";
static const char* const propertyValueStreamName = "property values";
 
void OMStoredObject::create(const OMByteOrder byteOrder)
{
  TRACE("OMStoredObject::create");
  PRECONDITION("Not already open", !_open);

  _byteOrder = byteOrder;
  _mode = modifyMode;
  _index = new OMStoredPropertySetIndex(50);
  ASSERT("Valid heap pointer", _index != 0);
  _indexStream = createStream(_storage, propertyIndexStreamName);
  _propertiesStream = createStream(_storage, propertyValueStreamName);
  _open = true;
}

void OMStoredObject::open(const OMAccessMode mode)
{
  TRACE("OMStoredObject::open");
  PRECONDITION("Not already open", !_open);
  PRECONDITION("Valid mode", (mode == modifyMode) || (mode == readOnlyMode));

  _mode = mode;
  _indexStream = openStream(_storage, propertyIndexStreamName);
  _propertiesStream = openStream(_storage, propertyValueStreamName);
  _open = true;
  _index = restore();
}

  // @mfunc Close this <c OMStoredObject>.
void OMStoredObject::close(void)
{
  TRACE("OMStoredObject::close");
  PRECONDITION("Already open", _open);

  closeStream(_indexStream);
  closeStream(_propertiesStream);
  
  delete _index;
  _index = 0;

  closeStorage(_storage);

  _open = false;
}

  // @mfunc Write a property value to this <c OMStoredObject>. The
  //        property value to be written occupies <p size> bytes at
  //        the address <p start>. The property id is <p propertyId>.
  //        The property type is <p type>.
  //   @parm The property id.
  //   @parm The property type.
  //   @parm The start address of the property value.
  //   @parm The size of the property value in bytes.
void OMStoredObject::write(OMPropertyId propertyId,
                           int type,
                           void* start,
                           size_t size)
{
  TRACE("OMStoredObject::write");

  _index->insert(propertyId, type, _offset, size);

  // Write property value.
  //
  writeToStream(_propertiesStream, start, size);
  _offset += size;
}

  // @mfunc Read a property value from this <c OMStoredObject>.
  //        The property value is read into a buffer which occupies
  //        <p size> bytes at the address <p start>. The property id
  //        is <p propertyId>. The property type is <p type>.
  //   @parm The property id.
  //   @parm The property type.
  //   @parm The start address of the buffer to hold the property value.
  //   @parm The size of the buffer in bytes.
void OMStoredObject::read(OMPropertyId propertyId,
                          int type,
                          void* start,
                          size_t size)
{
  TRACE("OMStoredObject::read");

  // Consistency check - look up propertyId in _index and check that
  // the property type is the expected (passed in) type.  and that the
  // property length is the expected (passed in as size) length.
  // 
  //
  // NYI
  // int actualType;
  // size_t actualOffset;
  // size_t actualLength;
  // _index->find(propertyId, actualType, actualOffset, actualLength);
  //
  // ASSERT("Matching property types", type == actualType);
  // ASSERT("Matching property sizes", size == actualLength);

  // Since random access is not yet supported, check that the stream
  // is synchronized with the index.
  //
  // ASSERT("Sequential access",
  //        actualOffset == streamPosition(_propertiesStream));

  // Read property value.
  //
  readFromStream(_propertiesStream, start, size);
}

  // @mfunc Size of <p stream> in bytes.
  //   @parm An open stream.
  //   @rdesc The size of <p stream> in bytes
  //   @this const
OMUInt64 OMStoredObject::streamSize(IStream* stream) const
{
  TRACE("OMStoredObject::streamSize");
  PRECONDITION("Valid stream", stream != 0);

  STATSTG statstg;
  HRESULT status = stream->Stat(&statstg, STATFLAG_NONAME);
  if (!check(status)) {
    exit(FAILURE);
  }
  OMUInt64 result = OMQUADPART(statstg.cbSize);
  return result;
}

  // @mfunc Set the size, in bytes, of <p stream>
  //   @parm An open stream.
  //   @parm The new size for the stream.
void OMStoredObject::streamSetSize(IStream* stream, const OMUInt64 newSize)
{
  TRACE("OMStoredObject::streamSetSize");

  ULARGE_INTEGER newStreamSize;
  OMSETQUADPART(newStreamSize, newSize);
  HRESULT status = stream->SetSize(newStreamSize);
  if (!check(status)) {
    exit(FAILURE);
  }
}

  // @mfunc Open a stream called <p streamName> contained within this
  //        <c OMStoredObject>.
  //   @parm The name of the stream to open.
  //   @rdesc An open stream.
IStream* OMStoredObject::openStream(const char* streamName)
{
  TRACE("OMStoredObject::openStream");
  return openStream(_storage, streamName);
}

  // @mfunc Create a stream called <p streamName> contained within
  //        this <c OMStoredObject>.
  //   @parm The name of the stream to create.
  //   @rdesc An open stream.
IStream* OMStoredObject::createStream(const char* streamName)
{
  TRACE("OMStoredObject::createStream");
  return createStream(_storage, streamName);
}

  // @mfunc Save the <c OMClassId> <p cid> in this <c OMStoredObject>.
  //   @parm The <c OMClassId> of this <c OMStoredObject>.
void OMStoredObject::save(const OMClassId& cid)
{
  TRACE("OMStoredObject::save");

  setClass(_storage, cid);
}

  // @mfunc Restore the class id of this <c OMStoredObject>.
  //   @parm The <c OMClassId> of this <c OMStoredObject>.
void OMStoredObject::restore(OMClassId& cid)
{
  TRACE("OMStoredObject::restore");

  getClass(_storage, cid);
}

  // @mfunc Create a new <c OMStoredObject>, named <p name>,
  //        contained by this <c OMStoredObject>.
  //   @parm The name to be used for the new <c OMStoredObject>.
  //   @rdesc A new <c OMStoredObject> contained by this
  //          <c OMStoredObject>.
OMStoredObject* OMStoredObject::create(const char* name)
{
  TRACE("OMStoredObject::create");

  IStorage* newStorage = createStorage(_storage, name);
  OMStoredObject* result = new OMStoredObject(newStorage);
  ASSERT("Valid heap pointer", result != 0);
  result->create(_byteOrder);
  return result;
}

  // @mfunc Open an exsiting <c OMStoredObject>, named <p name>,
  //        contained by this <c OMStoredObject>.
  //   @parm The name of the existing <c OMStoredObject>.
  //   @rdesc The existing <c OMStoredObject> contained by this
  //          <c OMStoredObject>.
OMStoredObject* OMStoredObject::open(const char* name)
{
  TRACE("OMStoredObject::open");

  IStorage* newStorage = openStorage(_storage, name, _mode);
  OMStoredObject* result = new OMStoredObject(newStorage);
  ASSERT("Valid heap pointer", result != 0);
  result->open(_mode);
  return result;
}

  // @mfunc Check that the <c OMPropertySet> <p propertySet> is
  //        consistent with the <c OMStoredPropertySetIndex>
  //        propertySetIndex.
  //   @parm The <c OMPropertySet> to validate.
  //   @parm The <c OMStoredPropertySetIndex> to validate.
void OMStoredObject::validate(
                        const OMPropertySet* propertySet,
                        const OMStoredPropertySetIndex* propertySetIndex) const
{
  OMPropertyId propertyId;
  OMUInt32 type;
  OMUInt32 offset;
  OMUInt32 length;
  size_t context;

  // Check that all required properties are present.
  //
  size_t count = propertySet->count();
  context = 0;
  for (size_t j = 0; j < count; j++) {
    OMProperty* p = 0;
    propertySet->iterate(context, p);
    ASSERT("Valid property", p != 0);
    propertyId = p->propertyId();
    bool found = propertySetIndex->find(propertyId, type, offset, length);
    ASSERT("Required property present", found);
  }

  // Check that there are no spurious properties.
  //
  OMUInt32 entries = propertySetIndex->entries();
  context = 0;
  for (size_t k = 0; k < entries; k++) {
    propertySetIndex->iterate(context, propertyId, type, offset, length);
    OMProperty* p = propertySet->get(propertyId);
    ASSERT("Property allowed", p != 0);
  }

}

  // @mfunc  Save the <c OMStoredVectorIndex> <p vector> in this
  //         <c OMStoredObject>, the vector is named <p vectorName>.
  //   @parm The <c OMStoredVectorIndex> to save.
  //   @parm The name of the vector.
void OMStoredObject::save(const OMStoredVectorIndex* vector,
                          const char* vectorName)
{
  TRACE("OMStoredObject::save");

  // Calculate the stream name for the index.
  //
  char* vectorIndexName = vectorIndexStreamName(vectorName);

  // Create the stream.
  //
  IStream* vectorIndexStream = createStream(_storage, vectorIndexName);

  // Write the high water mark.
  //
  OMUInt32 highWaterMark = vector->highWaterMark();
  writeToStream(vectorIndexStream, &highWaterMark, sizeof(highWaterMark));

  // Write the count of elements.
  //
  OMUInt32 entries = vector->entries();
  writeToStream(vectorIndexStream, &entries, sizeof(entries));

  // Write the element names.
  //
  size_t context = 0;
  OMUInt32 name;
  for (size_t i = 0; i < entries; i++) {
    vector->iterate(context, name);
    writeToStream(vectorIndexStream, &name, sizeof(name));
  }

  // Close the stream.
  //
  closeStream(vectorIndexStream);

  delete [] vectorIndexName;
}

  // @mfunc Restore the vector named <p vectorName> into this
  //        <c OMStoredObject>.
  //   @parm The name of the vector.
  //   @rdesc The newly restored <c OMStoredVectorIndex>.

void OMStoredObject::restore(OMStoredVectorIndex*& vector,
                             const char* vectorName)
{
  TRACE("OMStoredObject::restore");
  
  // Calculate the stream name for the index.
  //
  char* vectorIndexName = vectorIndexStreamName(vectorName);

  // Open the stream.
  //
  IStream* vectorIndexStream = openStream(_storage, vectorIndexName);

  // Read the high water mark.
  //
  OMUInt32 highWaterMark;
  readUInt32FromStream(vectorIndexStream, highWaterMark, _reorderBytes);

  // Read the count of elements.
  //
  OMUInt32 entries;
  readUInt32FromStream(vectorIndexStream, entries, _reorderBytes);

  // Create an index.
  //
  OMStoredVectorIndex* vectorIndex = new OMStoredVectorIndex(entries);
  ASSERT("Valid heap pointer", vectorIndex != 0);

  // Read the element names, placing them in the index.
  //
  for (size_t i = 0; i < entries; i++) {
    OMUInt32 name;
    readUInt32FromStream(vectorIndexStream, name, _reorderBytes);
    vectorIndex->insert(i, name);
  }

  // Close the stream.
  //
  closeStream(vectorIndexStream);

  delete [] vectorIndexName;

  vector = vectorIndex;
}

char* OMStoredObject::vectorIndexStreamName(const char* vectorName)
{
  char* suffix = " index";
  char* vectorIndexName = new char[strlen(vectorName) + strlen(suffix) + 1];
  ASSERT("Valid heap pointer", vectorIndexName != 0);
  strcpy(vectorIndexName, vectorName);
  strcat(vectorIndexName, suffix);

  return vectorIndexName;
}

IStream* OMStoredObject::createStream(IStorage* storage,
                                      const char* streamName)
{
  TRACE("OMStoredObject::createStream");
  PRECONDITION("Valid storage", storage != 0);

  DWORD mode;
  if (_mode == modifyMode) {
    mode = STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE;
  } else if (_mode == readOnlyMode) {
    mode = STGM_DIRECT | STGM_READ      | STGM_SHARE_EXCLUSIVE | STGM_CREATE;
  }

  IStream* stream = 0;
  OMCHAR omStreamName[256];
  convert(omStreamName, 256, streamName);

  HRESULT resultCode = storage->CreateStream(
    omStreamName,
    mode,
    0,
    0,
    &stream);
  if (!checkStream(resultCode, streamName)) {
    exit(FAILURE);
  }

  return stream;
}

IStream* OMStoredObject::openStream(IStorage* storage, const char* streamName)
{
  TRACE("OMStoredObject::openStream");
  PRECONDITION("Valid storage", storage != 0);
  PRECONDITION("Valid stream name", validString(streamName));
  
  DWORD mode;
  if (_mode == modifyMode) {
    mode = STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
  } else if (_mode == readOnlyMode) {
    mode = STGM_DIRECT | STGM_READ      | STGM_SHARE_EXCLUSIVE;
  }

  IStream* stream = 0;
  OMCHAR omStreamName[256];
  convert(omStreamName, 256, streamName);
  
  HRESULT resultCode = storage->OpenStream(
    omStreamName,
    0,
    mode,
    0,
    &stream);
  if (!checkStream(resultCode, streamName)) {
    exit(FAILURE);
  }

  return stream;
  
}

  // @mfunc Close <p stream>.
  //   @parm The stream to close.
void OMStoredObject::closeStream(IStream*& stream)
{
  TRACE("OMStoredObject::closeStream");
  PRECONDITION("Valid stream", stream != 0);

  HRESULT resultCode = stream->Release();
  stream = 0;
  ASSERT("Reference count is 0.", resultCode == 0);
}

OMByteOrder OMStoredObject::byteOrder(void) const
{
  return _byteOrder;
}

IStorage* OMStoredObject::createStorage(IStorage* storage,
                                        const char* storageName)
{
  TRACE("createStorage");
  PRECONDITION("Valid storage", storage != 0);
  PRECONDITION("Valid storage name", validString(storageName));

  DWORD mode;
  if (_mode == modifyMode) {
    mode = STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE;
  } else if (_mode == readOnlyMode) {
    mode = STGM_DIRECT | STGM_READ      | STGM_SHARE_EXCLUSIVE | STGM_CREATE;
  }

  IStorage* newStorage = 0;
  OMCHAR omStorageName[256];
  convert(omStorageName, 256, storageName);

  HRESULT resultCode = storage->CreateStorage(
    omStorageName,
    mode,
    0,
    0,
    &newStorage);
  if (!checkStorage(resultCode, storageName)) {
    exit(FAILURE);
  }

  return newStorage;
}

IStorage* OMStoredObject::openStorage(IStorage* storage,
                                      const char* storageName,
                                      const OMAccessMode mode)
{
  TRACE("openStorage");
  PRECONDITION("Valid storage", storage != 0);
  PRECONDITION("Valid storage name", validString(storageName));
  PRECONDITION("Valid mode", (mode == modifyMode) || (mode == readOnlyMode));

  DWORD openMode;
  if (mode == modifyMode) {
    openMode = STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
  } else if (mode == readOnlyMode) {
    openMode = STGM_DIRECT | STGM_READ      | STGM_SHARE_EXCLUSIVE;
  }

  IStorage* newStorage = 0;
  OMCHAR omStorageName[256];
  convert(omStorageName, 256, storageName);

  HRESULT resultCode = storage->OpenStorage(
    omStorageName,
    0,
    openMode,
    0,
    0,
    &newStorage);
  if (!checkStorage(resultCode, storageName)) {
    exit(FAILURE);
  }

  return newStorage;
}

void OMStoredObject::closeStorage(IStorage*& storage)
{
  TRACE("closeStorage");
  PRECONDITION("Valid storage", storage != 0);

  HRESULT resultCode = storage->Release();
  storage = 0;
  ASSERT("Reference count is 0.", resultCode == 0);
}

  // @mfunc Write <p size> bytes from the buffer at address <p data>
  //        to <p stream>.
  //   @parm The stream on which to write.
  //   @parm The buffer to write.
  //   @parm The number of bytes to write.   
void OMStoredObject::writeToStream(IStream* stream, void* data, size_t size)
{
  TRACE("OMStoredObject::writeToStream");
  PRECONDITION("Valid stream", stream != 0);
  PRECONDITION("Valid data", data != 0);
  PRECONDITION("Valid size", size > 0);

  HRESULT resultCode = stream->Write(data, size, NULL);
  if (!check(resultCode)) {
    exit(FAILURE);
  }
}

  // @mfunc Read <p size> bytes from <p stream> into the buffer at
  //        address <p data>.
  //   @parm The stream from which to read.
  //   @parm The buffer to write.
  //   @parm The number of bytes to read.   
void OMStoredObject::readFromStream(IStream* stream, void* data, size_t size)
{
  TRACE("OMStoredObject::readFromStream");

  unsigned long bytesRead;
  HRESULT result = stream->Read(data, size, &bytesRead);
  if (!check(result)) {
    exit(FAILURE);
  }
  ASSERT("Successful read", bytesRead == size);
}

  // @mfunc Read a UInt32 from <p stream> into <p i>. If
  //        <p reorderBytes> is true then the bytes are reordered.
  //   @parm The stream from which to read.
  //   @parm The resulting OMUInt32.
  //   @parm If true then reorder the bytes.
void OMStoredObject::readUInt32FromStream(IStream* stream,
                                          OMUInt32& i,
                                          bool reorderBytes)
{
  readFromStream(stream, &i, sizeof(OMUInt32));
  if (reorderBytes) {
    reorderOMUInt32(i);
  }
}

  // @mfunc Reorder the UInt32 from <p i>.
  //   @parm The OMUInt32 to reorder.
void OMStoredObject::reorderOMUInt32(OMUInt32& i)
{
  OMUInt8* p = (OMUInt8*)&i;
  OMUInt8 temp;

  temp = p[0];
  p[0] = p[3];
  p[3] = temp;

  temp = p[1];
  p[1] = p[2];
  p[2] = temp;

}

void OMStoredObject::setClass(IStorage* storage, const OMClassId& cid)
{
  TRACE("OMStoredObject::setClass");
  PRECONDITION("Valid storage", storage != 0);

  GUID g;
  memcpy(&g, &cid, sizeof(GUID));
  HRESULT resultCode = storage->SetClass(g);
  if (!check(resultCode)) {
    exit(FAILURE);
  }

}

void OMStoredObject::getClass(IStorage* storage, OMClassId& cid)
{
  TRACE("OMStoredObject::getClass");

  STATSTG statstg;
  HRESULT result = storage->Stat(&statstg, STATFLAG_NONAME);
  if (!check(result)) {
    exit(FAILURE);
  }
  memcpy(&cid, &statstg.clsid, sizeof(OMClassId));
}

  // @mfunc The current position for <f readFromStream()> and
  //        <f writeToStream()>, as an offset in bytes from the begining
  //        of the data stream.
  //   @rdesc The current position for <f readFromStream()> and
  //          <f writeToStream()>, as an offset in bytes from the begining
  //          of the data stream.
  //   @this const
OMUInt64 OMStoredObject::streamPosition(IStream* stream) const
{
  TRACE("OMStoredObject::streamPosition");

  OMUInt64 result;
  LARGE_INTEGER zero = {0, 0};
  ULARGE_INTEGER position;
  HRESULT status = stream->Seek(zero, STREAM_SEEK_CUR, &position);
  if (!check(status)) {
    exit(FAILURE);
  }
  result = OMQUADPART(position);
  return result;
}

  // @mfunc Set the current position for <f readFromStream()> and
  //        <f writeToStream()>, as an offset in bytes from the begining of
  //        the data stream.
  //   @parm The position to use for subsequent calls to readFromStream() and
  //         writeToStream() on this stream. The position is specified as an
  //         offset in bytes from the begining of the data stream.
  //   @this const
void OMStoredObject::streamSetPosition(IStream* stream, const OMUInt64 offset)
{
  TRACE("OMStoredObject::streamSetPosition");

  ULARGE_INTEGER newPosition;
  ULARGE_INTEGER oldPosition;
  OMSETQUADPART(newPosition, offset);
  LARGE_INTEGER position;
  memcpy(&position, &newPosition, sizeof(LARGE_INTEGER));
  HRESULT status = stream->Seek(position, STREAM_SEEK_SET, &oldPosition);
  if (!check(status)) {
    exit(FAILURE);
  }
}

static void convert(wchar_t* wcName, size_t length, const char* name)
{
  TRACE("convert");
  PRECONDITION("Valid input name", validString(name));
  PRECONDITION("Valid output buffer", wcName != 0);
  PRECONDITION("Valid output buffer size", length > 0);
  
  ASSERT("Valid program name", validString(getProgramName()));

  size_t status = mbstowcs(wcName, name, length);
  if (status == (size_t)-1) {
    cerr << getProgramName()
      << "Error : Failed to convert \""
      << name
      << "\" to a wide character string."
      << endl;
    exit(FAILURE);  
  }
}

static void convert(char* cName, size_t length, const wchar_t* name)
{
  ASSERT("Valid program name", validString(getProgramName()));

  size_t status = wcstombs(cName, name, length);
  if (status == (size_t)-1) {
    cerr << getProgramName()
      << ": Error : Conversion failed."
      << endl;
    exit(FAILURE);  
  }
}

static void convert(char* cName, size_t length, const char* name)
{
  TRACE("convert");
  PRECONDITION("Valid input name", validString(name));
  PRECONDITION("Valid output buffer", cName != 0);
  PRECONDITION("Valid output buffer size", length > 0);

  size_t sourceLength = strlen(name);
  if (sourceLength + 1 < length) {
    strncpy(cName, name, sourceLength + 1);
  } else {
    cerr << getProgramName()
      << ": Error : Conversion failed."
      << endl;
    exit(FAILURE);  
  }
}

static void convert(wchar_t* wcName, size_t length, const wchar_t* name)
{
  TRACE("convert");
  PRECONDITION("Valid input name", validWideString(name));
  PRECONDITION("Valid output buffer", wcName != 0);
  PRECONDITION("Valid output buffer size", length > 0);

  size_t sourceLength = wideStringLength(name);
  if (sourceLength + 1 < length) {
    wideStringCopy(wcName, name, sourceLength + 1);
  } else {
    cerr << getProgramName()
      << ": Error : Conversion failed."
      << endl;
    exit(FAILURE);  
  }
}

static void formatError(DWORD errorCode)
{
#if defined(_WIN32) || defined(WIN32)
  OMCHAR buffer[256];

  int status = FormatMessage(
    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    errorCode,
    LANG_SYSTEM_DEFAULT,
    buffer, 256,
    NULL);

  if (status != 0) {
    char message[256];
    convert(message, 256, buffer);

    int length = strlen(message);
    // zap cr/lf
    if (length >= 2) {
      message[length - 2] = '\0';
    }
    cerr << "Error text = \"" << message << "\"" << endl;
  } else {
    cerr << "Error code = " << hex << errorCode << dec << endl;
  }
#else
  cerr << "Error code = " << hex << errorCode << dec << endl;
#endif
}

static int check(HRESULT resultCode)
{
  TRACE("check");

  ASSERT("Valid program name", validString(getProgramName()));

  if (FAILED(resultCode)) {
    printError(getProgramName(), "Error");
    formatError(resultCode);
    return FALSE;
  } else {
    return TRUE;
  }
}

static int checkFile(HRESULT resultCode, const wchar_t* fileName)
{
  TRACE("checkFile");
  PRECONDITION("Valid file name", validWideString(fileName));

  ASSERT("Valid program name", validString(getProgramName()));

  if (FAILED(resultCode)) {
    printError(getProgramName(), "File error");
    printName(fileName);
    formatError(resultCode);
    return FALSE;
  } else {
    return TRUE;
  }
}

static int checkStream(HRESULT resultCode, const char* streamName)
{
  TRACE("checkStream");
  PRECONDITION("Valid stream name", validString(streamName));

  ASSERT("Valid program name", validString(getProgramName()));

  if (FAILED(resultCode)) {
    printError(getProgramName(), "Stream error");
    printName(streamName);
    formatError(resultCode);
    return FALSE;
  } else {
    return TRUE;
  }

}

static int checkStorage(HRESULT resultCode, const char* storageName)
{
  TRACE("checkStorage");
  PRECONDITION("Valid storage name", validString(storageName));

  ASSERT("Valid program name", validString(getProgramName()));

  if (FAILED(resultCode)) {
    printError(getProgramName(), "Storage error");
    printName(storageName);
    formatError(resultCode);
    return FALSE;
  } else {
    return TRUE;
  }

}

static void printError(const char* prefix, const char* type)
{
  cerr << prefix << " : " << type << " : ";
}

static void printName(const char* name)
{
  cerr << "\"" << name << "\" : ";
}

static void printName(const wchar_t* name)
{
  TRACE("printName");
  char cName[256];

  convert(cName, 256, name);
  cerr << "\"" << cName << "\" : ";
}
