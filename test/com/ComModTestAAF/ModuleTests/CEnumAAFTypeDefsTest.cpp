// @doc INTERNAL
// @com This file implements the module test for CEnumAAFTypeDefs
//=---------------------------------------------------------------------=
//
// $Id: CEnumAAFTypeDefsTest.cpp,v 1.14 2004/02/27 14:26:51 stuart_hc Exp $ $Name:  $
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

#include <iostream>
using namespace std;

#include <stdio.h>
#include <wchar.h>
#include <string.h>

#include "AAF.h"
#include "AAFResult.h"
#include "ModuleTest.h"

#include "CEnumeratorTest.h"

class CEnumAAFTypeDefsTest: public CEnumeratorTest<IEnumAAFTypeDefs,IAAFTypeDef>
{
public:
	HRESULT CountItems(IAAFDictionary *pDictionary,aafUInt32 *piCount)
	{
		return(pDictionary->CountTypeDefs(piCount));
	}
	HRESULT GetItems(IAAFDictionary *pDictionary,IEnumAAFTypeDefs **ppEnumerator)
	{
		return(pDictionary->GetTypeDefs(ppEnumerator));
	}
	aafBool ItemIsPresent(IAAFDictionary *pDictionary,aafUID_t& Id)
	{
		IAAFSmartPointer<IAAFTypeDef> pTypeDef;
		return(pDictionary->LookupTypeDef(Id,&pTypeDef)==AAFRESULT_SUCCESS?
			kAAFTrue:kAAFFalse);
	}
};

extern "C" HRESULT CEnumAAFTypeDefs_test(testMode_t mode);
extern "C" HRESULT CEnumAAFTypeDefs_test(testMode_t mode)
{
	try
	{
		CEnumAAFTypeDefsTest Test;
		Test.Run(mode);
	}
	catch(HRESULT& rResult)
	{
		return(rResult);
	}

	return AAFRESULT_SUCCESS;
}














