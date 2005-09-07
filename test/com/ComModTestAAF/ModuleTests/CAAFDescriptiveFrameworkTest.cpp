//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: CAAFDescriptiveFrameworkTest.cpp,v 1.3 2005/09/07 19:52:58 montrowe Exp $ $Name:  $
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

#include "ModuleTest.h"

#include "AAFTypes.h" //Use #include "AAF.h" for functional module test.
#include "AAFResult.h"

// Test routine defined in CAAFDescriptiveMarkerTest.cpp
extern "C" HRESULT CAAFDescriptiveMarker_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID);

// Required function prototype.
extern "C" HRESULT CAAFDescriptiveFramework_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID);
extern "C" HRESULT CAAFDescriptiveFramework_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID)
{
  // DescriptiveFramework is an abstract base class.  By itself, there
  // is nothing to test other than that a concrete instance of a
  // DescriptiveFramework can be correctly contained by a
  // DescriptiveMarker.  This is tested in
  // CAAFDescriptiveMarkerTest.cpp and there is little point in
  // repeating the code here.  The test is re-executed here to ensure
  // "ComModAAF AAFDescriptiveFramework" executes a meaningful test in
  // the event it is run on its own.

  return CAAFDescriptiveMarker_test( mode,
					    fileKind,
					    rawStorageType,
					    productID);
}
