//=---------------------------------------------------------------------=
//
// $Id: OMVariableArrayType.h,v 1.1.2.2 2005/05/03 10:04:07 philipn Exp $ $Name:  $
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

// @doc OMEXTERNAL
#ifndef __OMVARIABLEARRAYTYPE_H__
#define __OMVARIABLEMARRAYTYPE_H__

#include "OMArrayType.h"

class OMVariableArrayType : virtual public OMArrayType
{
public:
    virtual bool initialise(const OMUniqueObjectIdentification& id, const wchar_t* name,
        const wchar_t* description, const OMUniqueObjectIdentification& elementTypeId,
        OMPropertyTag typeDefsTag) = 0;
};


#endif
