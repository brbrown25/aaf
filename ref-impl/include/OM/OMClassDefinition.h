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
// The Original Code of this file is Copyright 1998-2003, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
#ifndef OMCLASSDEFINITION_H
#define OMCLASSDEFINITION_H

#include "OMDataTypes.h"

class OMPropertyDefinition;
class OMStorable;

  // @class Abstract base class used to define persistent classes
  //        supported by the Object Manager.
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMClassDefinition {
public:

  virtual ~OMClassDefinition(void) {}

    // @cmember The <c OMPropertyDefinition> for properties (members
    //          of classes defined by this <c OMClassDefinition>) defined
    //          by <p id>.
  virtual const OMPropertyDefinition* propertyDefinition(
                             const OMUniqueObjectIdentification& id) const = 0;


  virtual const OMPropertyDefinition* propertyDefinition(
			     const  OMStorable* pDstStorable,
			     const OMPropertyDefinition* pSrcProperty ) = 0;

};

#endif
