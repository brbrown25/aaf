//=---------------------------------------------------------------------=
//
// $Id: OMByteArray.h,v 1.2 2007/03/26 16:00:56 philipn Exp $
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
// Licensor of the AAF Association is British Broadcasting Corporation.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef __OMBYTEARRAY_H__
#define __OMBYTEARRAY_H__

#include "OMDataTypes.h"

class OMByteArray
{
public:
    OMByteArray();
    OMByteArray(OMUInt32 size);
    ~OMByteArray();

    void append(const OMByte* bytes, OMUInt32 size);

    OMUInt32 size() const { return _bytesSize; }
    OMByte* bytes() const { return _bytes; }
    void setSize(OMUInt32 size);

    void grow(OMUInt32 size);
    void setBufferIncrement(OMUInt32 increment);

    void clear();
    void reset();

private:
    OMByte* _bytes;
    OMUInt32 _bytesSize;

    OMUInt32 _increment;
    OMUInt32 _initialBufferSize;
    OMUInt32 _bufferSize;
};


#endif

