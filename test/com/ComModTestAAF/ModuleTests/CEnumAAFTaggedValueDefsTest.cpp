// @doc INTERNAL
// @com This file implements the module test for CEnumAAFTaggedValueDefs
//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: CEnumAAFTaggedValueDefsTest.cpp,v 1.1.2.2 2004/05/24 19:06:21 jptrainor Exp $ $Name:  $
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

#include <ModuleTest.h>

#include "AAFTypes.h" //Use #include "AAF.h" for functional module test.
#include "AAFResult.h"

HRESULT TaggedValueDefinitionTest( aafCharacter* pFileName,
				   aafCharacter* pTestName,
				   testMode_t mode );

// Required function prototype.
extern "C" HRESULT CEnumAAFTaggedValueDefs_test(testMode_t mode);

HRESULT CEnumAAFTaggedValueDefs_test(testMode_t mode)
{
  return TaggedValueDefinitionTest( L"EnumAAFTaggedValueDefTest.aaf", 
				    L"CEnumAAFTaggedValueDef_test",
				    mode );
}
