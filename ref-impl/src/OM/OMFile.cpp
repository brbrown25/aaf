//=---------------------------------------------------------------------=
//
// The contents of this file are subject to the AAF SDK Public
// Source License Agreement (the "License"); You may not use this file
// except in compliance with the License.  The License is available in
// AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
// Association or its successor.
// 
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.
// 
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMFile

#include "OMFile.h"

#include "OMAssertions.h"
#include "OMStoredObject.h"
#include "OMMSSStoredObject.h"
#include "OMXMLStoredObject.h"
#include "OMKLVStoredObject.h"
#include "OMClassFactory.h"
#include "OMObjectDirectory.h"
#include "OMPropertyTable.h"
#include "OMUtilities.h"
#include "OMDictionary.h"
#include "OMRootStorable.h"
#include "OMRawStorage.h"
#include "OMUniqueObjectIdentType.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

  // @mfunc Destructor.
OMFile::~OMFile(void)
{
  TRACE("OMFile::~OMFile");

  delete _objectDirectory;
  _objectDirectory = 0;
  delete _referencedProperties;
  _referencedProperties = 0;
  delete _fileName;
  _fileName = 0;

  delete _rawStorage;
  _rawStorage = 0;
}

  // @mfunc Open an existing <c OMFile> for read-only access, the
  //        <c OMFile> is named <p fileName>, use the <c OMClassFactory>
  //        <p factory> to create the objects. The file must already
  //        exist.
  //   @parm The name of the file to open.
  //   @parm The factory to use for creating objects.
  //   @parm Specifies the use of lazy or eager loading.
  //   @rdesc The newly opened <c OMFile>.
OMFile* OMFile::openExistingRead(const wchar_t* fileName,
                                 const OMClassFactory* factory,
                                 void* clientOnRestoreContext,
                                 const OMLoadMode loadMode,
                                 OMDictionary* dictionary)
{
  TRACE("OMFile::openExistingRead");

  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid dictionary", dictionary != 0);

  OMFileSignature signature;
  readSignature(fileName, signature);
  OMStoredObject* store = OMMSSStoredObject::openRead(fileName);
  OMFile* newFile = new OMFile(fileName,
                               clientOnRestoreContext,
                               signature,
                               readOnlyMode,
                               store,
                               factory,
                               dictionary,
                               loadMode);
  ASSERT("Valid heap pointer", newFile != 0);
  POSTCONDITION("Object Manager file", newFile->isOMFile());
  POSTCONDITION("File is open", newFile->isOpen());
  return newFile;
}

  // @mfunc Open an existing <c OMFile> for modify access, the
  //        <c OMFile> is named <p fileName>, use the <c OMClassFactory>
  //        <p factory> to create the objects. The file must already
  //        exist.
  //   @parm The name of the file to open.
  //   @parm The factory to use for creating objects.
  //   @parm Specifies the use of lazy or eager loading.
  //   @rdesc The newly opened <c OMFile>.
OMFile* OMFile::openExistingModify(const wchar_t* fileName,
                                   const OMClassFactory* factory,
                                   void* clientOnRestoreContext,
                                   const OMLoadMode loadMode,
                                   OMDictionary* dictionary)
{
  TRACE("OMFile::openExistingModify");

  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid dictionary", dictionary != 0);

  OMFileSignature signature;
  readSignature(fileName, signature);
  OMStoredObject* store = OMMSSStoredObject::openModify(fileName);
  OMFile* newFile = new OMFile(fileName,
                               clientOnRestoreContext,
                               signature,
                               modifyMode,
                               store,
                               factory,
                               dictionary,
                               loadMode);
  ASSERT("Valid heap pointer", newFile != 0);
  POSTCONDITION("Object Manager file", newFile->isOMFile());
  POSTCONDITION("File is open", newFile->isOpen());
  return newFile;
}

  // @mfunc Open a new <c OMFile> for modify access, the
  //        <c OMFile> is named <p fileName>, use the <c OMClassFactory>
  //        <p factory> to create the objects. The file must not already
  //        exist. The byte ordering on the newly created file is given
  //        by <p byteOrder>. The client root <c OMStorable> in the newly
  //        created file is given by <p clientRoot>.
  //   @parm The name of the file to create.
  //   @parm The factory to use for creating objects.
  //   @parm The byte order to use for the newly created file.
  //   @parm The client root <c OMStorable> in the newly created file.
  //   @rdesc The newly created <c OMFile>.
OMFile* OMFile::openNewModify(const wchar_t* fileName,
                              const OMClassFactory* factory,
                              void* clientOnRestoreContext,
                              const OMByteOrder byteOrder,
                              OMStorable* clientRoot,
                              const OMFileSignature& signature,
                              OMDictionary* dictionary)
{
  TRACE("OMFile::openNewModify");

  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid byte order",
                    ((byteOrder == littleEndian) || (byteOrder == bigEndian)));
  PRECONDITION("Valid client root", clientRoot != 0);
  PRECONDITION("Valid signature", validSignature(signature));
  PRECONDITION("Valid dictionary ", dictionary != 0);

  OMStoredObject* store = OMMSSStoredObject::createModify(fileName, byteOrder);
  OMRootStorable* root = new OMRootStorable(clientRoot, dictionary);
  ASSERT("Valid heap pointer", root != 0);

  OMFile* newFile = new OMFile(fileName,
                               clientOnRestoreContext,
                               signature,
                               modifyMode,
                               store,
                               factory,
                               dictionary,
                               root);
  ASSERT("Valid heap pointer", newFile != 0);
  POSTCONDITION("File is open", newFile->isOpen());
  return newFile;
}

  // @mfunc Is the given <c OMRawStorage> compatible with the given file
  //        access mode and signature ? Can a file of the encoding
  //        specified by <p signature> be created successfully on
  //        <p rawStorage> and then accessed successfully in the mode
  //        specified by <p accessMode> ?
  //   @parm The <c OMRawStorage> on which the file is to be created.
  //   @parm TBS
  //   @parm TBS
  //   @rdesc TBS
bool OMFile::compatibleRawStorage(const OMRawStorage* rawStorage,
                                  const OMAccessMode accessMode,
                                  const OMFileSignature& signature)
{
  TRACE("OMFile::compatibleRawStorage");
  PRECONDITION("Consistent raw storage access mode",
                IMPLIES(accessMode == readOnlyMode, rawStorage->isReadable()));
  PRECONDITION("Consistent raw storage access mode",
               IMPLIES(accessMode == writeOnlyMode, rawStorage->isWritable()));
  PRECONDITION("Consistent raw storage access mode",
                  IMPLIES(accessMode == modifyMode, rawStorage->isReadable() &&
                                                    rawStorage->isWritable()));

  // Most combinations of raw storage access mode and file encoding
  // (denoted by the signature) are valid.
  //
  bool result = true;

  // Write only Microsoft Structured Storage files are allowed
  // only on a read/write OMRawStorage.
  //
  OMFileEncoding encoding = encodingOf(signature);
  if ((encoding == MSSBinaryEncoding) &&
      (accessMode == writeOnlyMode) &&
      (!rawStorage->isReadable())) {
    result = false;
  }
  return result;
}

OMFile* OMFile::openExistingRead(OMRawStorage* rawStorage,
                                 const OMClassFactory* factory,
                                 void* clientOnRestoreContext,
                                 const OMLoadMode loadMode,
                                 OMDictionary* dictionary)
{
  TRACE("OMFile::openExistingRead");

  PRECONDITION("Valid raw storage", rawStorage != 0);
  PRECONDITION("Compatible raw storage access mode", rawStorage->isReadable());
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid dictionary", dictionary != 0);

  OMFile* newFile = new OMFile(rawStorage,
                               clientOnRestoreContext,
                               readOnlyMode,
                               factory,
                               dictionary,
                               loadMode);
  ASSERT("Valid heap pointer", newFile != 0);
  return newFile;
}

OMFile* OMFile::openExistingModify(OMRawStorage* rawStorage,
                                   const OMClassFactory* factory,
                                   void* clientOnRestoreContext,
                                   const OMLoadMode loadMode,
                                   OMDictionary* dictionary)
{
  TRACE("OMFile::openExistingModify");

  PRECONDITION("Valid raw storage", rawStorage != 0);
  PRECONDITION("Compatible raw storage access mode",
                         rawStorage->isReadable() && rawStorage->isWritable());
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid dictionary", dictionary != 0);

  OMFile* newFile = new OMFile(rawStorage,
                               clientOnRestoreContext,
                               modifyMode,
                               factory,
                               dictionary,
                               loadMode);
  ASSERT("Valid heap pointer", newFile != 0);
  return newFile;
}

OMFile* OMFile::openNewWrite(OMRawStorage* rawStorage,
                             const OMClassFactory* factory,
                             void* clientOnRestoreContext,
                             const OMByteOrder byteOrder,
                             OMStorable* clientRoot,
                             const OMFileSignature& signature,
                             OMDictionary* dictionary)
{
  TRACE("OMFile::openNewWrite");

  PRECONDITION("Valid raw storage", rawStorage != 0);
  PRECONDITION("Compatible raw storage access mode", rawStorage->isWritable());
  PRECONDITION("Compatible raw storage",
                   compatibleRawStorage(rawStorage, writeOnlyMode, signature));
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid byte order",
                    ((byteOrder == littleEndian) || (byteOrder == bigEndian)));
  PRECONDITION("Valid client root", clientRoot != 0);
  PRECONDITION("Valid signature", validSignature(signature));
  PRECONDITION("Valid dictionary ", dictionary != 0);

  OMRootStorable* root = new OMRootStorable(clientRoot, dictionary);
  ASSERT("Valid heap pointer", root != 0);

  OMFile* newFile = new OMFile(rawStorage,
                               clientOnRestoreContext,
                               signature,
                               writeOnlyMode,
                               factory,
                               dictionary,
                               root,
                               byteOrder);
  ASSERT("Valid heap pointer", newFile != 0);
  return newFile;
}

OMFile* OMFile::openNewModify(OMRawStorage* rawStorage,
                              const OMClassFactory* factory,
                              void* clientOnRestoreContext,
                              const OMByteOrder byteOrder,
                              OMStorable* clientRoot,
                              const OMFileSignature& signature,
                              OMDictionary* dictionary)
{
  TRACE("OMFile::openNewModify");

  PRECONDITION("Valid raw storage", rawStorage != 0);
  PRECONDITION("Compatible raw storage access mode",
                         rawStorage->isReadable() && rawStorage->isWritable());
  PRECONDITION("Compatible raw storage",
                   compatibleRawStorage(rawStorage, modifyMode, signature));
  PRECONDITION("Valid class factory", factory != 0);
  PRECONDITION("Valid byte order",
                    ((byteOrder == littleEndian) || (byteOrder == bigEndian)));
  PRECONDITION("Valid client root", clientRoot != 0);
  PRECONDITION("Valid signature", validSignature(signature));
  PRECONDITION("Valid dictionary ", dictionary != 0);

  OMRootStorable* root = new OMRootStorable(clientRoot, dictionary);
  ASSERT("Valid heap pointer", root != 0);

  OMFile* newFile = new OMFile(rawStorage,
                               clientOnRestoreContext,
                               signature,
                               modifyMode,
                               factory,
                               dictionary,
                               root,
                               byteOrder);
  ASSERT("Valid heap pointer", newFile != 0);
  return newFile;
}

   // @mfunc Is <p signature> a valid signature for an <c OMFile> ?
   //   @parm The signature to check.
   //   @rdesc True if <p signature> is a valid signature for an
   //          <c OMFile>, false otherwise.
bool OMFile::validSignature(const OMFileSignature& signature)
{
  TRACE("OMFile::validSignature");

  bool result;

  if (signature.Data3 == 0x4D4F) { // "OM"
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc Is the file named <p fileName> a recognized file ?
  //        If so, the result is true, and the signature is returned
  //        in <p signature> and the encoding in <p encoding>.
  //   @parm The name of the file to check.
  //   @parm If recognized, the file signature.
  //   @parm If recognized, the file encoding.
  //   @rdesc True if the file is recognized, false otherwise.
bool OMFile::isRecognized(const wchar_t* fileName,
                          OMFileSignature& signature,
                          OMFileEncoding& encoding)
{
  TRACE("OMFile::isRecognized");
  bool result = false;

  if (OMMSSStoredObject::isRecognized(fileName, signature)) {
    result = true;
    encoding = MSSBinaryEncoding;
  } else if (OMKLVStoredObject::isRecognized(fileName, signature)) {
    result = true;
    encoding = KLVBinaryEncoding;
  } else if (OMXMLStoredObject::isRecognized(fileName, signature)) {
    result = true;
    encoding = XMLTextEncoding;
  } else {
    result = false;
  }
  POSTCONDITION("Valid encoding", IMPLIES(result,
                                          (encoding == MSSBinaryEncoding) ||
                                          (encoding == KLVBinaryEncoding) ||
                                          (encoding == XMLTextEncoding)));
  return result;
}

  // @mfunc Does <p rawStorage> contain a recognized file ?
  //        If so, the result is true, and the signature is returned
  //        in <p signature> and the encoding in <p encoding>.
  //   @parm The <c OMRawStorage> to check.
  //   @parm If recognized, the file signature.
  //   @parm If recognized, the file encoding.
  //   @rdesc True if the <c OMRawStorage> contains a recognized
  //          file, false otherwise.
bool OMFile::isRecognized(OMRawStorage* rawStorage,
                          OMFileSignature& signature,
                          OMFileEncoding& encoding)
{
  TRACE("OMFile::isRecognized");
  bool result = false;

  if (OMMSSStoredObject::isRecognized(rawStorage, signature)) {
    result = true;
    encoding = MSSBinaryEncoding;
  } else if (OMKLVStoredObject::isRecognized(rawStorage, signature)) {
    result = true;
    encoding = KLVBinaryEncoding;
  } else if (OMXMLStoredObject::isRecognized(rawStorage, signature)) {
    result = true;
    encoding = XMLTextEncoding;
  } else {
    result = false;
  }
  POSTCONDITION("Valid encoding", IMPLIES(result,
                                          (encoding == MSSBinaryEncoding) ||
                                          (encoding == KLVBinaryEncoding) ||
                                          (encoding == XMLTextEncoding)));
  return result;
}

  // @mfunc Is <p signature> recognized ?
  //        If so, the result is true, and the encoding in <p encoding>.
  //   @parm If recognized, the encoding.
  //   @rdesc True if the signature is recognized, false otherwise.
bool OMFile::isRecognized(const OMFileSignature& signature,
                          OMFileEncoding& encoding)
{
  TRACE("OMFile::isRecognized");
  bool result = false;

  if (OMMSSStoredObject::isRecognized(signature)) {
    result = true;
    encoding = MSSBinaryEncoding;
  } else if (OMKLVStoredObject::isRecognized(signature)) {
    result = true;
    encoding = KLVBinaryEncoding;
  } else if (OMXMLStoredObject::isRecognized(signature)) {
    result = true;
    encoding = XMLTextEncoding;
  } else {
    result = false;
  }
  POSTCONDITION("Valid encoding", IMPLIES(result,
                                          (encoding == MSSBinaryEncoding) ||
                                          (encoding == KLVBinaryEncoding) ||
                                          (encoding == XMLTextEncoding)));
  return result;
}

  // @mfunc Save all changes made to the contents of this
  //        <c OMFile>. It is not possible to save
  //        read-only or transient files.
  //   @parm Client context for callbacks.
  //   @precondition <f isOpen()>
void OMFile::saveFile(void* clientOnSaveContext)
{
  TRACE("OMFile::saveFile");
  PRECONDITION("File is open", isOpen());

  _clientOnSaveContext = clientOnSaveContext;

  _isValid = false; // failing save() leaves the file invalid
  if (isWritable()) {
    _rootStore->save(*this);
  }
  _isValid = true; // successful save() leaves the file valid
}

  // @mfunc Save the entire contents of this <c OMFile> as well as
  //        any unsaved changes in the new file <p destFile>. <p destFile>
  //        must be open, writeable and not yet contain any objects.
  //        <mf OMFile::saveAsFile> may be called
  //        for files opened in modify mode and for files opened in
  //        read-only and transient modes.
  //   @parm OMFile* | destFile | The destination file.
  //   @this const
void OMFile::saveAsFile(OMFile* ANAME(destFile)) const
{
  TRACE("OMFile::saveAsFile");

  PRECONDITION("Valid file", destFile != 0);

  ASSERT("Unimplemented code not reached", false);
}

void OMFile::saveCopyAs(OMFile* ANAME(destFile)) const
{
  TRACE("OMFile::saveCopyAs");

  PRECONDITION("Valid file", destFile != 0);

  ASSERT("Unimplemented code not reached", false);
}

  // @mfunc Discard all changes made to this <c OMFile> since the
  //        last <mf OMFile::save> or <mf OMFile::open>.
void OMFile::revert(void)
{
  TRACE("OMFile::revert");

  ASSERT("Unimplemented code not reached", false);
}

  // @mfunc Restore the client root <c OMStorable> object from this <c OMFile>.
  //   @rdesc The newly restored root <c OMStorable>.
    //   @precondition <f isOpen()>
OMStorable* OMFile::restore(void)
{
  TRACE("OMFile::restore");
  PRECONDITION("File is open", isOpen());
  PRECONDITION("Valid root", _root != 0);

  return _root->clientRoot();
}

  // @mfunc Open this <c OMFile>.
  //   @precondition <f !isOpen()>
  //   @precondition <f !isClosed()>
  //   @postcondition <f isOpen()>
void OMFile::open(void)
{
  TRACE("OMFile::open");
  PRECONDITION("Not already open", !isOpen());
  PRECONDITION("Never been opened", !isClosed());
  PRECONDITION("Valid mode", (_mode == readOnlyMode) ||
                             (_mode == writeOnlyMode) ||
                             (_mode == modifyMode));

  if (_isNew) { // new file - create
    ASSERT("Correct mode for new file", _mode != readOnlyMode);
    if (_mode == modifyMode) {
      createModify();
    } else { // _mode == writeOnly
      createWrite();
    }
  } else {      // existing file - open
    ASSERT("Correct mode for existing file", (_mode == readOnlyMode) ||
                                             (_mode == modifyMode));
    if (_mode == readOnlyMode) {
      openRead();
    } else { // _mode == modifyMode
      openModify();
	}
    ASSERT("No root object", _root == 0);
    _root = restoreRoot();
    ASSERT("Object Manager file", isOMFile());
  }

  _isOpen = true;
  POSTCONDITION("Open", isOpen());
}

  // @mfunc Close this <c OMFile>, any unsaved changes are discarded.
  //   @precondition <f isOpen()>
  //   @postcondition <f !isOpen()>
  //   @postcondition <f isClosed()>
void OMFile::close(void)
{
  TRACE("OMFile::close");
  PRECONDITION("Open", isOpen());

  _root->close();

  // TBS - tjb delete _rootStore; _rootStore = 0;

  _root->detach();
  delete _root;
  _root = 0;
  _isOpen = false;
  _isClosed = true;
  POSTCONDITION("Closed", isClosed());
  POSTCONDITION("Closed", !isOpen());
}

  // @mfunc Is this <c OMFile> open ?
bool OMFile::isOpen(void) const
{
  TRACE("OMFile::isOpen");
  return _isOpen;
}

  // @mfunc Is this <c OMFile> closed ? Note that <f isClosed()> is not the
  //        same as !<f isOpen()> since before open() is called,
  //        <f isClosed()> is false. That is, <f isClosed()> means
  //        "was once open and is now closed".
bool OMFile::isClosed(void) const
{
  TRACE("OMFile::isClosed");
  return _isClosed;
}

bool OMFile::isValid(void) const
{
  TRACE("OMFile::isValid");
  return _isValid;
}

  // @mfunc Retrieve the client root <c OMStorable> from this <c OMFile>.
  //   @rdesc The root <c OMStorable>.
OMStorable* OMFile::clientRoot(void)
{
  TRACE("OMFile::clientRoot");

  OMStorable* result;
  result = _root->clientRoot();
  return result;
}

OMStorable* OMFile::root(void)
{
  TRACE("OMFile::root");

  return _root;
}

OMDictionary* OMFile::dictionary(void) const
{
  TRACE("OMFile::dictionary");
  PRECONDITION("Valid root", _root != 0);

  return _root->dictionary();
}

  // @mfunc Retrieve the <c OMPropertyTable> from this <c OMFile>.
  //   @rdesc The table of referenced properties.
OMPropertyTable* OMFile::referencedProperties(void)
{
  TRACE("OMFile::referencedProperties");

  if (_referencedProperties == 0) {
    _referencedProperties = new OMPropertyTable();
    ASSERT("Valid heap pointer", _referencedProperties != 0);
  }
  return _referencedProperties;
}

  // @mfunc Retrieve the <c OMObjectDirectory> from this <c OMFile>.
  //   @rdesc The <c OMObjectDirectory> associated with this file.
OMObjectDirectory* OMFile::objectDirectory(void)
{
  TRACE("OMFile::objectDirectory");

#if defined(OM_ENABLE_DEBUG)
  // Create the object directory on demand (debugging only) 
  if (_objectDirectory == 0) {
    _objectDirectory = new OMObjectDirectory();
    ASSERT("Valid heap pointer", _objectDirectory != 0);
  }
#endif
  return _objectDirectory;
}

  // @mfunc The byte order of this <c OMFile>.
  //   @rdesc The byte order of this <c OMFile>.
  //   @this const
OMByteOrder OMFile::byteOrder(void) const
{
  TRACE("OMFile::byteOrder");

  ASSERT("Valid root", _rootStore != 0);
  return _rootStore->byteOrder();
}

  // @mfunc The loading mode (eager or lazy) of this <c OMFile>.
  //   @rdesc The loading mode (eager or lazy) of this <c OMFile>.
  //   @this const
OMFile::OMLoadMode OMFile::loadMode(void) const
{
  TRACE("OMFile::loadMode");

  return _loadMode;
}

  // @mfunc The access mode of this <c OMFile>.
  //   @rdesc The access mode of this <c OMFile>. 
  //   @this const
OMFile::OMAccessMode OMFile::accessMode(void) const
{
  TRACE("OMFile::acessMode");

  return _mode;
}

  // @cmember Is it possible to read from this <c OMFile> ?
  //  @rdesc True if this <c OMFile> is readable, false otherwise.
  //   @this const
bool OMFile::isReadable(void) const
{
  TRACE("OMFile::isReadable");

  bool result;
  if ((accessMode() == readOnlyMode) || (accessMode() == modifyMode)) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @cmember Is it possible to write to this <c OMFile> ?
  //  @rdesc True if this <c OMFile> is writable, false otherwise.
  //   @this const
bool OMFile::isWritable(void) const
{
  TRACE("OMFile::isWritable");

  bool result;
  if ((accessMode() == writeOnlyMode) || (accessMode() == modifyMode)) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc Is this file recognized by the Object Manager ?
  //   @rdesc True if this file is recognized by the Object Manager,
  //          false otherwise.
  //   @this const
bool OMFile::isOMFile(void) const
{
  TRACE("OMFile::isOMFile");

  bool result;

  if (validSignature(_signature)) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc The name of this <c OMFile>.
  //   @rdesc The name of this <c OMFile>.
const wchar_t* OMFile::fileName(void) const
{
  return _fileName;
}

  // @mfunc The signature of this <c OMFile>.
  //   @rdesc The signature of this <c OMFile>.
OMFileSignature OMFile::signature(void) const
{
  return _signature;
}

  // @mfunc The encoding of this <c OMFile>.
  //   @rdesc The encoding of the <c OMFile>.
OMFile::OMFileEncoding OMFile::encoding(void) const
{
  TRACE("OMFile::encoding");

  return _encoding;
}

  // @mfunc The raw storage on which this <c OMFile> is stored.
  //   @rdesc The raw storage on which the raw bytes of
  //          this <c OMFile> reside.
OMRawStorage* OMFile::rawStorage(void) const
{
  TRACE("OMFile::rawStorage");

  return _rawStorage;
}

  // @mfunc Find the property instance in this <c OMFile>
  //        named by <p propertyPathName>.
  //   @parm The pathname to the desired property.
  //   @rdesc The property instance.
  //   @this const
OMProperty* OMFile::findPropertyPath(const wchar_t* propertyPathName) const
{
  TRACE("OMFile::findPropertyPath");

  PRECONDITION("Valid property path name", validWideString(propertyPathName));
  PRECONDITION("Path name is absolute", propertyPathName[0] == L'/');
  PRECONDITION("Valid root", _root != 0);

  wchar_t* path = saveWideString(propertyPathName);

  wchar_t* element = path;
  element++; // skip first '/'

  const OMStorable* storable = _root;
  OMProperty* result = 0;

  wchar_t* end = findWideCharacter(element, L'/');

  while (end != 0) {
    *end = 0;
    storable = storable->find(element);
    ASSERT("Valid storable pointer", storable != 0);
    element = ++end;
    end = findWideCharacter(element, L'/');
  }

  if ((element != 0) && (lengthOfWideString(element) > 0)) {
    result = storable->findProperty(element);
  } else {
    result = 0;
  }

  delete [] path;
  return result;
}

OMPropertyId* OMFile::path(const wchar_t* propertyPathName) const
{
  TRACE("OMFile::path");

  wchar_t delimiter = L'/';
  PRECONDITION("Valid property path name", validWideString(propertyPathName));
  PRECONDITION("Path name is absolute", propertyPathName[0] == delimiter);
  PRECONDITION("Valid root", _root != 0);

  // Allocate result
  //
  size_t count = countWideCharacter(propertyPathName, delimiter);
  OMPropertyId* result = new OMPropertyId[count + 1];
  ASSERT("Valid heap pointer", result != 0);

  // Parse path name
  //
  wchar_t* path = saveWideString(propertyPathName);
  wchar_t* element = path;
  element++; // skip first '/'
  const OMStorable* storable = _root;
  OMProperty* property = 0;

  size_t index = 0;
  wchar_t* end = findWideCharacter(element, delimiter);

  while (end != 0) {
    *end = 0;
    property = storable->findProperty(element);
    result[index] = property->propertyId();
    index = index + 1;
    storable = storable->find(element);
    ASSERT("Valid storable pointer", storable != 0);
    element = ++end;
    end = findWideCharacter(element, delimiter);
  }

  if ((element != 0) && (lengthOfWideString(element) > 0)) {
    property = storable->findProperty(element);
    result[index] = property->propertyId();
    index = index + 1;
  }

  result[index] = 0;

  delete [] path;
  return result;
}

OMProperty* OMFile::findProperty(const OMPropertyId* path) const
{
  TRACE("OMFile::findProperty");

  PRECONDITION("Valid root", _root != 0);

  size_t count = lengthOfPropertyPath(path);
  const OMStorable* storable = _root;

  for (size_t index = 0; index < count - 1; index++) {
    OMPropertyId pid = path[index];
    storable = storable->find(pid);
    ASSERT("Valid storable pointer", storable != 0);
  }

  OMProperty* result = storable->findProperty(path[count - 1]);

  return result;
}

const OMClassId& OMFile::classId(void) const
{
  TRACE("OMFile::classId");

  return nullOMClassId;
}

OMFile* OMFile::file(void) const
{
  TRACE("OMFile::file");

  return const_cast<OMFile*>(this);
}

bool OMFile::inFile(void) const
{
  TRACE("OMFile::inFile");
  return true;
}

bool OMFile::persistent(void) const
{
  TRACE("OMFile::persistent");

  // Transient files NYI so by definition a file is persistent.
  //
  return true;
}

void* OMFile::clientOnSaveContext(void)
{
  return _clientOnSaveContext;
}

void* OMFile::clientOnRestoreContext(void)
{
  return _clientOnRestoreContext;
}

  // @mfunc Constructor. Create an <c OMFile> object representing
  //        an existing named external file.
  //   @parm The name of this <c OMFile>.
  //   @parm The access mode of this <c OMFile>.
  //   @parm The <c OMStoredObject> containing the root
  //         <c OMStorable> object.
  //   @parm The <c OMClassFactory> to use to restore objects from
  //         this <c OMFile>.
  //   @parm The <e OMFile::OMLoadMode> for this <c OMFile>.
OMFile::OMFile(const wchar_t* fileName,
               void* clientOnRestoreContext,
               OMFileSignature signature,
               const OMAccessMode mode,
               OMStoredObject* store,
               const OMClassFactory* factory,
               OMDictionary* dictionary,
               const OMLoadMode loadMode)
: _root(0),
  _rootStore(store),
  _dictionary(dictionary),
  _objectDirectory(0),
  _referencedProperties(0),
  _mode(mode),
  _loadMode(loadMode),
  _fileName(0),
  _signature(signature),
  _clientOnSaveContext(0),
  _clientOnRestoreContext(clientOnRestoreContext),
  _encoding(MSSBinaryEncoding),
  _rawStorage(0),
  _isOpen(false),
  _isClosed(false),
  _isNew(false),
  _isValid(true),
  _byteOrder(unspecified)
{
  TRACE("OMFile::OMFile");

  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid dictionary", _dictionary != 0);
  _fileName = saveWideString(fileName);
  setClassFactory(factory);
  setName(L"/");
  ASSERT("No root object", _root == 0);
  _root = restoreRoot();
  _isOpen = true;
}

  // @mfunc Constructor. Create an <c OMFile> object representing
  //        a new named external file.
  //   @parm The name of this <c OMFile>.
  //   @parm The signature of this <c OMFile>.
  //   @parm The access mode of this <c OMFile>.
  //   @parm The <c OMStoredObject> in which to store the root
  //         <c OMStorable> object.
  //   @parm The <c OMClassFactory> to use to restore objects from
  //         this <c OMFile>.
  //   @parm The root <c OMStorable> object to save in this file.
OMFile::OMFile(const wchar_t* fileName,
               void* clientOnRestoreContext,
               OMFileSignature signature,
               const OMAccessMode mode,
               OMStoredObject* store,
               const OMClassFactory* factory,
               OMDictionary* dictionary,
               OMRootStorable* root)
: _root(root),
  _rootStore(store),
  _dictionary(dictionary),
  _objectDirectory(0),
  _referencedProperties(0),
  _mode(mode),
  _loadMode(lazyLoad),
  _fileName(0),
  _signature(signature),
  _clientOnSaveContext(0),
  _clientOnRestoreContext(clientOnRestoreContext),
  _encoding(MSSBinaryEncoding),
  _rawStorage(0),
  _isOpen(false),
  _isClosed(false),
  _isNew(true),
  _isValid(true),
  _byteOrder(unspecified)
{
  TRACE("OMFile::OMFile");

  PRECONDITION("Valid file name", validWideString(fileName));
  PRECONDITION("Valid dictionary", _dictionary != 0);
  _fileName = saveWideString(fileName);
  setClassFactory(factory);
  setName(L"<file>");
  _root->attach(this, L"/");
  _root->setStore(_rootStore);
  _isOpen = true;
}

  // @mfunc Constructor. Create an <c OMFile> object representing
  //        an existing external file on the given <c OMRawStorage>.
OMFile::OMFile(OMRawStorage* rawStorage,
               void* clientOnRestoreContext,
               const OMAccessMode mode,
               const OMClassFactory* factory,
               OMDictionary* dictionary,
               const OMLoadMode loadMode)
: _root(0),
  _rootStore(0),
  _dictionary(dictionary),
  _objectDirectory(0),
  _referencedProperties(0),
  _mode(mode),
  _loadMode(loadMode),
  _fileName(0),
  _signature(nullOMFileSignature),
  _clientOnSaveContext(0),
  _clientOnRestoreContext(clientOnRestoreContext),
  _encoding(MSSBinaryEncoding), // tjb
  _rawStorage(rawStorage),
  _isOpen(false),
  _isClosed(false),
  _isNew(false),
  _isValid(true),
  _byteOrder(unspecified)
{
  TRACE("OMFile::OMFile");

  PRECONDITION("Valid raw storage", _rawStorage != 0);
  PRECONDITION("Consistent access modes",
                     IMPLIES(((mode == modifyMode) || (mode == writeOnlyMode)),
                     rawStorage->isWritable()));
  PRECONDITION("Valid dictionary", _dictionary != 0);

  setClassFactory(factory);
  setName(L"/");
}

  // @mfunc Constructor. Create an <c OMFile> object representing
  //          a new external file on the given <c OMRawStorage>.
OMFile::OMFile(OMRawStorage* rawStorage,
               void* clientOnRestoreContext,
               OMFileSignature signature,
               const OMAccessMode mode,
               const OMClassFactory* factory,
               OMDictionary* dictionary,
               OMRootStorable* root,
               const OMByteOrder byteOrder)
: _root(root),
  _rootStore(0),
  _dictionary(dictionary),
  _objectDirectory(0),
  _referencedProperties(0),
  _mode(mode),
  _loadMode(lazyLoad),
  _fileName(0),
  _signature(signature),
  _clientOnSaveContext(0),
  _clientOnRestoreContext(clientOnRestoreContext),
  _encoding(MSSBinaryEncoding), // tjb
  _rawStorage(rawStorage),
  _isOpen(false),
  _isClosed(false),
  _isNew(true),
  _isValid(true),
  _byteOrder(byteOrder)
{
  TRACE("OMFile::OMFile");

  PRECONDITION("Valid dictionary", _dictionary != 0);
  PRECONDITION("Valid raw storage", rawStorage != 0);
  PRECONDITION("Consistent access modes",
                     IMPLIES(((mode == modifyMode) || (mode == writeOnlyMode)),
                     rawStorage->isWritable()));

  setClassFactory(factory);
  setName(L"<file>");
  _root->attach(this, L"/");
}

  // @mfunc Read the signature from the given file.
  //   @parm The file name.
  //   @parm The signature.
void OMFile::readSignature(const wchar_t* fileName,
                           OMFileSignature& signature)
{
  TRACE("OMFile::readSignature");

  PRECONDITION("Valid file name", validWideString(fileName));

  FILE* f = wfopen(fileName, L"rb");
  ASSERT("File exists", f != 0);
  size_t status = fseek(f, 8, SEEK_SET);
  ASSERT("Seek succeeded", status == 0);
  status = fread(&signature, sizeof(signature), 1, f);
  ASSERT("Read succeeded", status == 1);

  fclose(f);

  if (hostByteOrder() != littleEndian) {
    OMByte* s = reinterpret_cast<OMByte*>(&signature);
    size_t size = sizeof(OMUniqueObjectIdentification);
    OMUniqueObjectIdentificationType::instance()->reorder(s, size);
  }
}

  // @mfunc Read the signature from the given raw storage.
  //   @parm The raw storage.
  //   @parm The signature.
void OMFile::readSignature(OMRawStorage* rawStorage,
                           OMFileSignature& signature)
{
  TRACE("OMFile::readSignature");

  PRECONDITION("Valid raw storage", rawStorage != 0);

  OMUInt32 count;
  rawStorage->readAt(8,
                     reinterpret_cast<OMByte*>(&signature),
                     sizeof(signature),
                     count);
  ASSERT("All bytes read", count == sizeof(signature));

  if (hostByteOrder() != littleEndian) {
    OMByte* s = reinterpret_cast<OMByte*>(&signature);
    size_t size = sizeof(OMUniqueObjectIdentification);
    OMUniqueObjectIdentificationType::instance()->reorder(s, size);
  }
}

OMFile::OMFileEncoding OMFile::encodingOf(const OMFileSignature& signature)
{
  TRACE("OMFile::encodingOf");
  
  OMFileEncoding result;
  char tag = ((char)((signature.Data1 & 0xff000000) >> 24));
  switch (tag) {
  case 'B': // structured storage (binary)
    result = MSSBinaryEncoding;
    break;
  case 'K': // SMPTE KLV (binary)
    result = KLVBinaryEncoding;
    break;
  case 'X': // XML (text)
    result = XMLTextEncoding;
    break;
  default:
    ASSERT("Recognized encoding", false);
    break;
  }
  return result;
}

void OMFile::openRead(void)
{
  TRACE("OMFile::openRead");

  readSignature(_rawStorage, _signature);
  _encoding = encodingOf(_signature);
  ASSERT("Valid encoding", (_encoding == MSSBinaryEncoding) ||
                           (_encoding == KLVBinaryEncoding) ||
                           (_encoding == XMLTextEncoding));
  switch (_encoding) {
  case MSSBinaryEncoding:
    _rootStore = OMMSSStoredObject::openRead(_rawStorage);
    break;
  case KLVBinaryEncoding:
    _rootStore = OMKLVStoredObject::openRead(_rawStorage);
    break;
  case XMLTextEncoding:
    _rootStore = OMXMLStoredObject::openRead(_rawStorage);
    break;
  }
  POSTCONDITION("Valid store", _rootStore != 0);
}

void OMFile::openModify(void)
{
  TRACE("OMFile::openModify");

  readSignature(_rawStorage, _signature);
  _encoding = encodingOf(_signature);
  ASSERT("Valid encoding", (_encoding == MSSBinaryEncoding) ||
                           (_encoding == KLVBinaryEncoding) ||
                           (_encoding == XMLTextEncoding));
  switch (_encoding) {
  case MSSBinaryEncoding:
    _rootStore = OMMSSStoredObject::openModify(_rawStorage);
    break;
  case KLVBinaryEncoding:
    _rootStore = OMKLVStoredObject::openModify(_rawStorage);
    break;
  case XMLTextEncoding:
    _rootStore = OMXMLStoredObject::openModify(_rawStorage);
    break;
  }
  ASSERT("Valid store", _rootStore != 0);
}

void OMFile::createModify(void)
{
  TRACE("OMFile::createModify");

  _encoding = encodingOf(_signature);
  ASSERT("Valid encoding", (_encoding == MSSBinaryEncoding) ||
                           (_encoding == KLVBinaryEncoding) ||
                           (_encoding == XMLTextEncoding));
  switch (_encoding) {
  case MSSBinaryEncoding:
    _rootStore = OMMSSStoredObject::createModify(_rawStorage, _byteOrder);
    break;
  case KLVBinaryEncoding:
    _rootStore = OMKLVStoredObject::createModify(_rawStorage, _byteOrder);
    break;
  case XMLTextEncoding:
    _rootStore = OMXMLStoredObject::createModify(_rawStorage, _byteOrder);
    break;
  }
  ASSERT("Valid store", _rootStore != 0);
  _root->setStore(_rootStore);
}

void OMFile::createWrite(void)
{
  TRACE("OMFile::createWrite");

  _encoding = encodingOf(_signature);
  ASSERT("Valid encoding", (_encoding == MSSBinaryEncoding) ||
                           (_encoding == KLVBinaryEncoding) ||
                           (_encoding == XMLTextEncoding));
  switch (_encoding) {
  case MSSBinaryEncoding:
    _rootStore = OMMSSStoredObject::createWrite(_rawStorage, _byteOrder);
    break;
  case KLVBinaryEncoding:
    _rootStore = OMKLVStoredObject::createWrite(_rawStorage, _byteOrder);
    break;
  case XMLTextEncoding:
    _rootStore = OMXMLStoredObject::createWrite(_rawStorage, _byteOrder);
    break;
  }
  ASSERT("Valid store", _rootStore != 0);
  _root->setStore(_rootStore);
}

OMRootStorable* OMFile::restoreRoot(void)
{
  TRACE("OMFile::restoreRoot");

  enum OMLoadMode savedLoadMode = _loadMode;
  _loadMode = lazyLoad;

  _rootStore->restore(_referencedProperties);

  OMClassId id;
  _rootStore->restore(id);
  ASSERT("Valid root stored object", id == OMRootStorable::_rootClassId);

  OMRootStorable* root = new OMRootStorable();
  ASSERT("Valid heap pointer", root != 0);
  root->attach(this, L"/");
  root->setStore(_rootStore);
  root->setClassFactory(_dictionary);

  root->restoreContents();

  OMDictionary *metaDictionary = root->dictionary();
  ASSERT("Consistent dictionaries", metaDictionary == _dictionary);
  root->setClassFactory(classFactory());

  _loadMode = savedLoadMode;
  return root;
}
