// @doc INTERNAL
// @com This file implements the module test for CAAFDefinitionObject
/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/


#ifndef __CAAFTimecode_h__
#include "CAAFTimecode.h"
#endif

#include <iostream.h>
#include <stdio.h>

#include "AAFStoredObjectIDs.h"
#include "aafCvt.h"
#include "AAFResult.h"



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



static HRESULT CreateAAFFile(aafWChar * pFileName)
{
	IAAFFile *					pFile = NULL;
	bool bFileOpen = false;
	IAAFHeader *				pHeader = NULL;
  IAAFDictionary*  pDictionary = NULL;
	IAAFCompositionMob*			pCompMob=NULL;
	IAAFMob						*pMob = NULL;
	IAAFMobSlot					*pNewSlot = NULL;
	IAAFTimecode				*pTimecode = NULL;
	IAAFSegment					*pSeg = NULL;

	aafUID_t					newMobID;
	aafProductIdentification_t	ProductInfo;
	HRESULT						hr;
	aafLength_t					zero;
	aafTimecode_t				startTC;

	CvtInt32toLength(0, zero);
	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"Make AVR Example";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = -1;
	ProductInfo.platform = NULL;


  try
  {
    // Remove the previous test file if any.
    RemoveTestFile(pFileName);


    // Create the file
		checkResult(CoCreateInstance(CLSID_AAFFile,
								 NULL, 
								 CLSCTX_INPROC_SERVER, 
								 IID_IAAFFile, 
								 (void **)&pFile));
		checkResult(pFile->Initialize());
		checkResult(pFile->OpenNewModify(pFileName, 0, &ProductInfo));
		bFileOpen = true;
 
    // We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

    // Get the AAF Dictionary so that we can create valid AAF objects.
    checkResult(pHeader->GetDictionary(&pDictionary));
 		
		// Create a CompositionMob
		checkResult(pDictionary->CreateInstance(&AUID_AAFCompositionMob,
							IID_IAAFCompositionMob, 
							(IUnknown **)&pCompMob));

    // Get a MOB interface
		checkResult(pCompMob->QueryInterface (IID_IAAFMob, (void **)&pMob));
		checkResult(CoCreateGuid((GUID *)&newMobID));
		checkResult(pMob->SetMobID(&newMobID));

		checkResult(pCompMob->Initialize(L"COMPMOB01"));
		
    checkResult(pDictionary->CreateInstance(&AUID_AAFTimecode,
								IID_IAAFTimecode, 
								(IUnknown **)&pTimecode));		

		startTC.startFrame = 108000;	// One hour
		startTC.drop = kTcNonDrop;
		startTC.fps = 30;
	  checkResult(pTimecode->Initialize (zero, &startTC));
		checkResult(pTimecode->QueryInterface (IID_IAAFSegment, (void **)&pSeg));

		checkResult(pMob->AppendNewSlot (pSeg, 0, L"timecode", &pNewSlot));
		
		checkResult(pHeader->AppendMob(pMob));
	}
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }
	

	// Cleanup and return
	if (pNewSlot)
		pNewSlot->Release();

	if (pSeg)
		pSeg->Release();

  if (pTimecode)
		pTimecode->Release();

	if (pMob)
		pMob->Release();

	if (pCompMob)
		pCompMob->Release();

	if (pDictionary)
		pDictionary->Release();

	if (pHeader)
		pHeader->Release();

	if (pFile) 
	{
		if (bFileOpen)
			pFile->Close();
		pFile->Release();
	}

	return hr;
}


static HRESULT ReadAAFFile(aafWChar * pFileName)
{
    // IAAFSession *				pSession = NULL;
	IAAFFile *					pFile = NULL;
	bool bFileOpen = false;
	IAAFHeader *				pHeader = NULL;
  IAAFDictionary*  pDictionary = NULL;
	IEnumAAFMobs*				pMobIter = NULL;
	IEnumAAFMobSlots*			pEnum = NULL;
	IAAFMob*					pMob = NULL;
	IAAFMobSlot*				pMobSlot = NULL;
	IAAFSegment*				pSeg = NULL;
	IAAFTimecode*				pTimecode = NULL;
	aafTimecode_t				startTC;

	aafProductIdentification_t	ProductInfo;
	aafNumSlots_t				numMobs;
	HRESULT						hr;

	ProductInfo.companyName = L"AAF Developers Desk. NOT!";
	ProductInfo.productName = L"Make AVR Example. NOT!";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = -1;
	ProductInfo.platform = NULL;


  try
  {
    // Open the file
		checkResult(CoCreateInstance(CLSID_AAFFile,
								 NULL, 
								 CLSCTX_INPROC_SERVER, 
								 IID_IAAFFile, 
								 (void **)&pFile));
		checkResult(pFile->Initialize());
		checkResult(pFile->OpenExistingRead(pFileName, 0));
		bFileOpen = true;
 
    // We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

		// Get the number of mobs in the file (should be one)
		checkResult(pHeader->GetNumMobs(kAllMob, &numMobs));
		checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);

    checkResult(pHeader->EnumAAFAllMobs( NULL, &pMobIter));
		while (AAFRESULT_SUCCESS == pMobIter->NextOne(&pMob))
		{
      checkResult(pMob->EnumAAFAllMobSlots (&pEnum));

      while (AAFRESULT_SUCCESS == pEnum->NextOne (&pMobSlot))
      {
        checkResult(pMobSlot->GetSegment (&pSeg));
        // Get a Timecode interface 
        checkResult(pSeg->QueryInterface (IID_IAAFTimecode, (void **)&pTimecode));
        checkResult(pTimecode->GetTimecode (&startTC));

        // Check results !!
        checkExpression(startTC.startFrame == 108000, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
      }

      pMob->Release();
      pMob = NULL;
	  }
	}
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }
	

	// Cleanup and return
  if (pTimecode)
		pTimecode->Release();

	if (pSeg)
		pSeg->Release();

  if (pMobSlot)
		pMobSlot->Release();

  if (pEnum)
    pEnum->Release();

	if (pMob)
		pMob->Release();

	if (pDictionary)
		pDictionary->Release();

	if (pHeader)
		pHeader->Release();

	if (pFile) 
	{
		if (bFileOpen)
			pFile->Close();
		pFile->Release();
	}

	return hr;
}

HRESULT CAAFTimecode::test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
	aafWChar * pFileName = L"TimecodeTest.aaf";

	try
	{
		hr = CreateAAFFile(	pFileName );
		if(hr == AAFRESULT_SUCCESS)
			hr = ReadAAFFile( pFileName );
	}
	catch (...)
	{
	  cerr << "CAAFTimecodeMob::test...Caught general C++"
		" exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

  	// When all of the functionality of this class is tested, we can return success
	if(hr == AAFRESULT_SUCCESS)
		hr = AAFRESULT_TEST_PARTIAL_SUCCESS;

	// Cleanup our object if it exists.
	return hr;
}


