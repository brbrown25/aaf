//=---------------------------------------------------------------------=
//
// $Id: OMObjectReferenceType.h,v 1.7 2009/06/01 11:46:58 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
#ifndef OMOBJECTREFERENCETYPE_H
#define OMOBJECTREFERENCETYPE_H

#include "OMType.h"
#include "OMSingleton.h"
#include "OMClassDefinition.h"
#include "OMVector.h"

// @author Tim Bingham | tjb | Avid Technology, Inc. |
//         OMObjectReferenceType
class OMObjectReferenceType : public OMType {
public:

  virtual const OMUniqueObjectIdentification& referencedType(void) const = 0;

  virtual OMClassDefinition* referencedClass(void) const = 0;
};

// @author Tim Bingham | tjb | Avid Technology, Inc. |
//         OMStrongObjectReferenceType
class OMStrongObjectReferenceType : public OMObjectReferenceType {
public:

  virtual OMType::Tag tag(void) const;

};

// @author Tim Bingham | tjb | Avid Technology, Inc. |
//         OMWeakObjectReferenceType
class OMWeakObjectReferenceType : public OMObjectReferenceType {
public:

  virtual OMType::Tag tag(void) const;

  virtual OMUInt32 targetPathElementCount(void) const = 0;

  virtual const OMUniqueObjectIdentification& targetPathElement(OMUInt32 index) const = 0;

  virtual const OMPropertyId* targetPath(void) const = 0;
};


#endif
