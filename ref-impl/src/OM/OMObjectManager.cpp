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
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMObjectManager

#include "OMObjectManager.h"

#include "OMAssertions.h"
#include "OMUtilities.h"
#include "OMDictionary.h"
#include "OMFile.h"
#include "OMUniqueObjectIdentType.h"
#include "OMIntegerType.h"

void OMObjectManager::initialize(void)
{
  TRACE("OMObjectManager::initalize");

#if defined(OM_DEBUG)
  checkTypes();
#endif
  OMFile::initialize();
  OMDictionary::initialize();
}

void OMObjectManager::finalize(void)
{
  TRACE("OMObjectManager::finalize");

  OMInteger08Type::destroy();
  OMInteger16Type::destroy();
  OMInteger32Type::destroy();
  OMInteger64Type::destroy();
  OMUniqueObjectIdentificationType::destroy();

  OMDictionary::finalize();
  OMFile::finalize();
}
