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

// @doc OMINTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMMSSStoredStream 
#include "OMMSSStoredStream.h"

#include "OMMSStructuredStorage.h"
#include "OMAssertions.h"

OMMSSStoredStream::OMMSSStoredStream(IStream* stream)
: _stream(stream)
{
  TRACE("OMMSSStoredStream::OMMSSStoredStream");
  PRECONDITION("Valid stream", _stream != 0);
}

OMMSSStoredStream::~OMMSSStoredStream(void)
{
  TRACE("OMMSSStoredStream::~OMMSSStoredStream");
  PRECONDITION("Stream not open", _stream == 0);
}

void OMMSSStoredStream::read(void* data, size_t size) const
{
  TRACE("OMMSSStoredStream::read");
  PRECONDITION("Valid stream", _stream != 0);
  PRECONDITION("Valid data buffer", data != 0);
  PRECONDITION("Valid size", size > 0);

  unsigned long bytesRead;
  HRESULT result = _stream->Read(data, size, &bytesRead);
  ASSERT("Succeeded", SUCCEEDED(result)); // tjb - error

  ASSERT("Successful read", bytesRead == size);
}

void OMMSSStoredStream::read(OMByte* data,
                             const OMUInt32 bytes,
                             OMUInt32& bytesRead) const
{
  TRACE("OMMSSStoredStream::read");
  PRECONDITION("Valid stream", _stream != 0);
  PRECONDITION("Valid data buffer", data != 0);
  PRECONDITION("Valid size", bytes > 0);

  HRESULT result = _stream->Read(data, bytes, &bytesRead);
  ASSERT("Succeeded", SUCCEEDED(result)); // tjb - error
}

void OMMSSStoredStream::write(void* data, size_t size)
{
  TRACE("OMMSSStoredStream::write");
  PRECONDITION("Valid stream", _stream != 0);
  PRECONDITION("Valid data", data != 0);
  PRECONDITION("Valid size", size > 0);

  unsigned long bytesWritten;
  HRESULT resultCode = _stream->Write(data, size, &bytesWritten);
  ASSERT("Succeeded", SUCCEEDED(resultCode)); // tjb - error

  ASSERT("Successful write", bytesWritten == size);
}

void OMMSSStoredStream::write(const OMByte* data,
                              const OMUInt32 bytes,
                              OMUInt32& bytesWritten)
{
  TRACE("OMMSSStoredStream::write");
  PRECONDITION("Valid stream", _stream != 0);
  PRECONDITION("Valid data", data != 0);
  PRECONDITION("Valid size", bytes > 0);

  HRESULT resultCode = _stream->Write(data, bytes, &bytesWritten);
  ASSERT("Succeeded", SUCCEEDED(resultCode)); // tjb - error
}

OMUInt64 OMMSSStoredStream::size(void) const
{
  TRACE("OMMSSStoredStream::size");
  PRECONDITION("Valid stream", _stream != 0);

  STATSTG statstg;
  HRESULT status = _stream->Stat(&statstg, STATFLAG_NONAME);
  ASSERT("Succeeded", SUCCEEDED(status)); // tjb - error

  OMUInt64 result = toOMUInt64(statstg.cbSize);
  return result;
}

void OMMSSStoredStream::setSize(const OMUInt64 newSize)
{
  TRACE("OMMSSStoredStream::setSize");

  ULARGE_INTEGER newStreamSize = fromOMUInt64(newSize);
  HRESULT status = _stream->SetSize(newStreamSize);
  ASSERT("Succeeded", SUCCEEDED(status)); // tjb - error
}

OMUInt64 OMMSSStoredStream::position(void) const
{
  TRACE("OMMSSStoredStream::position");
  PRECONDITION("Valid stream", _stream != 0);

  OMUInt64 result;
  LARGE_INTEGER zero = {0, 0};
  ULARGE_INTEGER position;
  HRESULT status = _stream->Seek(zero, STREAM_SEEK_CUR, &position);
  ASSERT("Succeeded", SUCCEEDED(status)); // tjb - error

  result = toOMUInt64(position);
  return result;
}

void OMMSSStoredStream::setPosition(const OMUInt64 offset)
{
  TRACE("OMMSSStoredStream::setPosition");
  PRECONDITION("Valid stream", _stream != 0);

  ULARGE_INTEGER newPosition = fromOMUInt64(offset);
  ULARGE_INTEGER oldPosition;
  LARGE_INTEGER position;
  memcpy(&position, &newPosition, sizeof(LARGE_INTEGER));
  HRESULT status = _stream->Seek(position, STREAM_SEEK_SET, &oldPosition);
  ASSERT("Succeeded", SUCCEEDED(status)); // tjb - error
}

void OMMSSStoredStream::close(void)
{
  TRACE("OMMSSStoredStream::close");
  PRECONDITION("Valid stream", _stream != 0);

  _stream->Release();
  _stream = 0;
}
