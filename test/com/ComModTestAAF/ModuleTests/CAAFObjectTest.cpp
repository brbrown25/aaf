// @doc INTERNAL
// @com This file implements the module test for CAAFObject
/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/

#include "AAF.h"
#include "AAFResult.h"
#include "AAFStoredObjectIDs.h"
#include "AAFDefUIDs.h"

#include <iostream.h>
#include <stdio.h>
#include <assert.h>


static aafUID_t    fillerUID = DDEF_Timecode;
static aafLength_t  fillerLength = 3200;


// convenient error handlers.
inline void checkResult(HRESULT r)
{
  if (FAILED(r))
    throw r;
}
inline void checkExpression(bool expression, HRESULT r)
{
  if (!expression)
    throw r;
}

static wchar_t testFileName[] = L"AAFObjectTest.aaf";


// Cross-platform utility to delete a file.
static void RemoveTestFile(const wchar_t* pFileName)
{
  const size_t kMaxFileName = 512;
  char cFileName[kMaxFileName];

  size_t status = wcstombs(cFileName, pFileName, kMaxFileName);
  if (status != (size_t)-1)
  { // delete the file.
    remove(cFileName);
  }
}


static HRESULT ObjectTest ()
{
  HRESULT hr = AAFRESULT_SUCCESS;

  aafProductIdentification_t ProductInfo;
  IAAFFile* pFile = NULL;
  IAAFHeader * pHeader = NULL;
  IAAFDictionary * pDict = NULL;
  IAAFCompositionMob * pCMob = NULL;
  IAAFMob * pMob = NULL;
  IAAFObject * pObj = NULL;
  IEnumAAFProperties * pEnum = NULL;

  try
	{
	  ProductInfo.companyName = L"AAF Developers Desk";
	  ProductInfo.productName = L"AAFObject Test";
	  ProductInfo.productVersion.major = 1;
	  ProductInfo.productVersion.minor = 0;
	  ProductInfo.productVersion.tertiary = 0;
	  ProductInfo.productVersion.patchLevel = 0;
	  ProductInfo.productVersion.type = kVersionUnknown;
	  ProductInfo.productVersionString = NULL;
	  ProductInfo.productID = -1;
	  ProductInfo.platform = NULL;

	  RemoveTestFile (testFileName);
	  checkResult (AAFFileOpenNewModify(testFileName, 0, &ProductInfo, &pFile));
	  assert (pFile);
	  checkResult (pFile->GetHeader (&pHeader));
	  assert (pHeader);
	  checkResult (pHeader->GetDictionary (&pDict));
	  assert (pDict);

	  checkResult (pDict->CreateInstance (&AUID_AAFCompositionMob,
										  IID_IAAFCompositionMob,
										  (IUnknown **) &pCMob));
	  assert (pCMob);
	  checkResult (pCMob->Initialize (L"TestMob"));
	  
	  checkResult (pCMob->QueryInterface (IID_IAAFMob,
										  (void **) &pMob));
	  assert (pMob);
	  checkResult (pHeader->AppendMob (pMob));

	  checkResult (pCMob->QueryInterface (IID_IAAFObject,
										  (void **) &pObj));
	  assert (pObj);

	  aafUInt32 propCount = 0;
	  checkResult (pObj->CountProperties (&propCount));
	  checkExpression(9 == propCount, AAFRESULT_TEST_FAILED);

	  checkResult (pObj->GetProperties (&pEnum));
	  checkExpression (pEnum != 0, AAFRESULT_TEST_FAILED);
	  while (propCount--)
		{
		  IAAFProperty * pProp = NULL;
		  checkResult (pEnum->NextOne (&pProp));
		  checkExpression (pProp != 0, AAFRESULT_TEST_FAILED);
		  pProp->Release();
		}
	}
  catch (HRESULT & rResult)
	{
	  hr = rResult;
	}

  if (pEnum) pEnum->Release();
  if (pCMob) pCMob->Release();
  if (pObj) pObj->Release();
  if (pDict) pDict->Release();
  if (pHeader) pHeader->Release();
  if (pFile)
	{
	  AAFRESULT temphr = pFile->Save();
	  if (! SUCCEEDED (temphr)) return temphr;
	  temphr = pFile->Close();
	  if (! SUCCEEDED (temphr)) return temphr;
	  pFile->Release();
	}
  
  return hr;
}


extern "C" HRESULT CAAFObject_test()
{
  HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;

  try
	{
	  hr = ObjectTest ();

	  if (FAILED(hr))
		{
		  cerr << "CAAFObject_test...FAILED!" << endl;
		  return hr;
		}

	}
  catch (...)
	{
	  cerr << "CAAFObject_test...Caught general C++"
		" exception!" << endl; 
	}

  return hr;
}
