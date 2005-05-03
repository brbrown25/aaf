//=---------------------------------------------------------------------=
//
// $Id: OMEnumeratedType.h,v 1.4.6.2 2005/05/03 10:04:06 philipn Exp $ $Name:  $
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

// @doc OMEXTERNAL
#ifndef OMENUMERATEDTYPE_H
#define OMENUMERATEDTYPE_H

#include "OMType.h"
#include "OMVector.h"

class OMEnumeratedType : virtual public OMType
{
public:
    virtual OMType* elementType(void) const = 0;
    virtual OMUInt32 elementCount(void) const = 0;
    virtual wchar_t* elementName(OMUInt32 index) const = 0;
    virtual OMInt64 elementValue(OMUInt32 index) const = 0;
    virtual wchar_t* elementNameFromValue(OMInt64 value) const = 0;
    virtual OMInt64 elementValueFromName(const wchar_t* name) const = 0;
    virtual bool initialise(const OMUniqueObjectIdentification& id, const wchar_t* name,
        const wchar_t* description, const OMUniqueObjectIdentification& elementTypeId,
        OMPropertyTag typeDefsTag, OMVector<wchar_t*>& elementNames, 
        OMVector<OMInt64>& elementValues) = 0;
};


#endif
