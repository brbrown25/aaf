//=---------------------------------------------------------------------=
//
// $Id: OMXMLStoredStream.cpp,v 1.15 2007/03/26 16:00:51 philipn Exp $
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
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMINTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMXMLStoredStream
#include "OMXMLStoredStream.h"

#include "OMAssertions.h"
#include "OMRawStorage.h"
#include "OMTransparentStoredStreamFilter.h"
#include "OMUtilities.h"

OMXMLStoredStream::OMXMLStoredStream(OMRawStorage* store)
: _store(store),
  _position(0)
{
  TRACE("OMXMLStoredStream::OMXMLStoredStream");
  PRECONDITION("Valid store", _store != 0);
}

OMXMLStoredStream::~OMXMLStoredStream(void)
{
  TRACE("OMXMLStoredStream::~OMXMLStoredStream");
  PRECONDITION("Stream not open", _store == 0);
}

void OMXMLStoredStream::read(void* data, OMUInt32 size) const
{
  TRACE("OMXMLStoredStream::read");
  PRECONDITION("Valid store", _store != 0);
  PRECONDITION("Valid data buffer", data != 0);
  PRECONDITION("Valid size", size > 0);

  OMUInt32 bytesRead;
  read(reinterpret_cast<OMByte*>(data), size, bytesRead);

  ASSERT("Successful read", bytesRead == size);
}

void OMXMLStoredStream::read(OMByte* data,
                             const OMUInt32 bytes,
                             OMUInt32& bytesRead) const
{
  TRACE("OMXMLStoredStream::read");
  PRECONDITION("Valid store", _store != 0);
  PRECONDITION("Valid data buffer", data != 0);
  PRECONDITION("Valid size", bytes > 0);

  _store->readAt(_position, data, bytes, bytesRead);

  OMXMLStoredStream* nonConstThis = const_cast<OMXMLStoredStream*>(this);
  nonConstThis->_position = _position + bytesRead;
}

void OMXMLStoredStream::write(void* data, OMUInt32 size)
{
  TRACE("OMXMLStoredStream::write");
  PRECONDITION("Valid store", _store != 0);
  PRECONDITION("Valid data", data != 0);
  PRECONDITION("Valid size", size > 0);

  OMUInt32 bytesWritten;
  write(reinterpret_cast<OMByte*>(data), size, bytesWritten);

  ASSERT("Successful write", bytesWritten == size);
}

void OMXMLStoredStream::write(const OMByte* data,
                              const OMUInt32 bytes,
                              OMUInt32& bytesWritten)
{
  TRACE("OMXMLStoredStream::write");
  PRECONDITION("Valid store", _store != 0);
  PRECONDITION("Valid data", data != 0);
  PRECONDITION("Valid size", bytes > 0);

  _store->writeAt(_position, data, bytes, bytesWritten);
  _position = _position + bytesWritten;
}

OMUInt64 OMXMLStoredStream::size(void) const
{
  TRACE("OMXMLStoredStream::size");
  PRECONDITION("Valid store", _store != 0);

  OMUInt64 result = _store->extent();
  return result;
}

void OMXMLStoredStream::setSize(const OMUInt64 newSize)
{
  TRACE("OMXMLStoredStream::setSize");
  PRECONDITION("Valid store", _store != 0);

  _store->extend(newSize);
}

OMUInt64 OMXMLStoredStream::position(void) const
{
  TRACE("OMXMLStoredStream::position");
  PRECONDITION("Valid store", _store != 0);

  return _position;
}

void OMXMLStoredStream::setPosition(const OMUInt64 offset) const
{
  TRACE("OMXMLStoredStream::setPosition");
  PRECONDITION("Valid store", _store != 0);

  const_cast<OMXMLStoredStream*>(this)->_position = offset;
}

void OMXMLStoredStream::close(void)
{
  TRACE("OMXMLStoredStream::close");
  PRECONDITION("Valid store", _store != 0);

  delete _store;
  _store = 0;
  _position = 0;
}

bool OMXMLStoredStream::hasEssenceElementKey(void) const
{
  TRACE("OMXMLStoredStream::hasEssenceElementKey");

  return false;
}

OMKLVKey OMXMLStoredStream::essenceElementKey(void) const
{
  TRACE("OMXMLStoredStream::essenceElementKey");
  PRECONDITION("Stream supports essence element keys", false);

  return nullOMKLVKey;
}
void OMXMLStoredStream::setEssenceElementKey(const OMKLVKey& /*key*/)
{
  TRACE("OMXMLStoredStream::setEssenceElementKey");
  PRECONDITION("Stream supports essence element keys", false);
}

OMStoredStreamFilter* OMXMLStoredStream::createFilter(void)
{
  TRACE("OMXMLStoredStream::createFilter");

  OMStoredStreamFilter* result = new OMTransparentStoredStreamFilter(this);
  ASSERT("Valid heap pointer", result != 0);
  return result;
}


