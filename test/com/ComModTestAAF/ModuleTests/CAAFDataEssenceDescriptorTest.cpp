//=---------------------------------------------------------------------=
//
//
// $Id: CAAFDataEssenceDescriptorTest.cpp,v 1.1 2006/03/24 18:28:29 jlow Exp $ $Name:  $
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



// Required function prototype.

extern "C" HRESULT CAAFDataEssenceDescriptor_test(
    testMode_t mode)
{
  // DataEssenceDescriptor is an abstract base class.  By itself, there
  // is nothing to test other than that a concrete instance of a
  // DataEssenceDescriptor can be correctly contained by concrete class.
	HRESULT  hr = AAFRESULT_NOT_IMPLEMENTED;
	return hr;
}
