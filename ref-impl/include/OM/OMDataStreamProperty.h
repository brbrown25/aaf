/***********************************************************************
*
*              Copyright (c) 1998-2000 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted,
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
* prior written permission of Avid Technology, Inc.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
* LIABILITY.
*
************************************************************************/

// @doc OMEXTERNAL
#ifndef OMDATASTREAMPROPERTY_H
#define OMDATASTREAMPROPERTY_H

#include "OMDataTypes.h"

#include "OMProperty.h"

struct IStream;

  // @class Persistent data stream properties supported by the Object
  //        Manager.
  //   @base | public <c OMProperty>.
class OMDataStreamProperty : public OMProperty {
public:
  // @access Public members.

    // @cmember Constructor.
  OMDataStreamProperty(const OMPropertyId propertyId, const wchar_t* name);

    // @cmember Destructor.
  virtual ~OMDataStreamProperty(void);

    // @cmember Save this <c OMDataStreamProperty>.
  virtual void save(void) const;

    // @cmember Restore this <c OMDataStreamProperty>, the size of the
    //          <c OMDataStreamProperty> is <p externalSize>.
  virtual void restore(size_t externalSize);

    // @cmember Close this  <c OMDataStreamProperty>.
  virtual void close(void);

    // @cmember The size, in bytes, of the data in this
    //          <c OMDataStreamProperty>.
  OMUInt64 size(void) const;

    // @cmember Set the size, in bytes, of the data in this
    //          <c OMDataStreamProperty>.
  void setSize(const OMUInt64 newSize);

    // @cmember The current position for <f read()> and <f write()>, as an
    //          offset in bytes from the begining of the data stream.
  OMUInt64 position(void) const;

    // @cmember Set the current position for <f read()> and <f write()>, as an
    //          offset in bytes from the begining of the data stream.
  void setPosition(const OMUInt64 offset) const;

  // Raw access interface - these functions do not use the OMType interface

    // @cmember Attempt to read the number of bytes given by <p bytes>
    //          from the data stream into the buffer at address
    //          <p buffer>. The actual number of bytes read is returned
    //          in <p bytesRead>.
  void read(OMByte* buffer,
            const OMUInt32 bytes,
            OMUInt32& bytesRead) const;

    // @cmember Attempt to write the number of bytes given by <p bytes>
    //          to the data stream from the buffer at address
    //          <p buffer>. The actual number of bytes written is returned
    //          in <p bytesWritten>.
  void write(const OMByte* buffer,
             const OMUInt32 bytes,
             OMUInt32& bytesWritten);

  // Typed access interface - these functions use the OMType interface

    // @cmember Attempt to read the number of elements given by
    //          <p elementCount> and described by <p elementType> and
    //          <p externalElementSize> from the data stream into the buffer
    //          at address <p elements>. The actual number of elements read
    //          is returned in <p elementsRead>.
  void readTypedElements(const OMType* elementType,
                         size_t externalElementSize,
                         OMByte* elements,
                         OMUInt32 elementCount,
                         OMUInt32& elementsRead) const;


    // @cmember Attempt to write the number of elements given by
    //          <p elementCount> and described by <p elementType> and
    //          <p externalElementSize> to the data stream from the buffer
    //          at address <p elements>. The actual number of elements written
    //          is returned in <p elementsWritten>.
  void writeTypedElements(const OMType* elementType,
                          size_t externalElementSize,
                          const OMByte* elements,
                          OMUInt32 elementCount,
                          OMUInt32& elementsWritten);

  // Direct property access interface

    // @cmember The size of the raw bits of this
    //          <c OMDataStreamProperty>. The size is given in bytes.
  virtual size_t bitsSize(void) const;

    // @cmember Get the raw bits of this <c OMDataStreamProperty>. The
    //          raw bits are copied to the buffer at address <p bits>
    //          which is <p size> bytes in size.
  virtual void getBits(OMByte* bits, size_t size) const;

    // @cmember Set the raw bits of this <c OMDataStreamProperty>. The raw
    //          bits are copied from the buffer at address <p bits> which
    //          is <p size> bytes in size.
  virtual void setBits(const OMByte* bits, size_t size);

    // @cmember Is a byte order specifed for this stream ?
  virtual bool hasByteOrder(void) const;

    // @cmember Specify a byte order for this stream.
  virtual void setByteOrder(OMByteOrder byteOrder);

    // @cmember The byte order of this stream.
  virtual OMByteOrder byteOrder(void) const;

    // @cmember Clear the byte order of this stream
  virtual void clearByteOrder(void);

protected:

  virtual const wchar_t* storedName(void) const;

private:

  void open(void);
  void create(void);

  IStream* _stream;
  OMByteOrder _byteOrder;

};

#endif
