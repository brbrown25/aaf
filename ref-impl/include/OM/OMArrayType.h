//=---------------------------------------------------------------------=
//
// $Id: OMArrayType.h,v 1.6 2007/02/06 15:46:07 wschilp Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
#ifndef OMARRAYTYPE_H
#define OMARRAYTYPE_H

#include "OMType.h"

class OMArrayType : public OMType {
public:

  virtual OMType* elementType(void) const = 0;

};

// @author Tim Bingham | tjb | Avid Technology, Inc. | OMFixedArrayType
class OMFixedArrayType : public OMArrayType {
public:

  virtual OMType::Tag tag(void) const;

  virtual OMUInt32 elementCount(void) const = 0;

};

// @author Tim Bingham | tjb | Avid Technology, Inc. | OMVaryingArrayType
class OMVaryingArrayType : public OMArrayType {
public:

  virtual OMType::Tag tag(void) const;


};

#endif
