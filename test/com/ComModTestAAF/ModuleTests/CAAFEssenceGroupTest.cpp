// @doc INTERNAL
// @com This file implements the module test for CAAFEssenceGroup
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

#include "AAF.h"

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "ModuleTest.h"
#include "AAFDataDefs.h"
#include "AAFDefUIDs.h"

#include "CAAFBuiltinDefs.h"

static aafWChar *slotName = L"SLOT1";
//static aafInt32 fadeInLen  = 1000;
//static aafInt32 fadeOutLen = 2000;
//static aafFadeType_t fadeInType = kAAFFadeLinearAmp;
//static aafFadeType_t fadeOutType = kAAFFadeLinearPower;
//!!!static aafSourceRef_t sourceRef; 


static const	aafMobID_t	TEST_MobID = 
{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
0x13, 0x00, 0x00, 0x00,
{0xc2cbfef4, 0x03fe, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}};

static const	aafMobID_t	TEST_referencedMobID = 
{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
0x13, 0x00, 0x00, 0x00,
{0xc6690f5c, 0x03fe, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}};


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
inline void checkExpression(bool expression, HRESULT r=AAFRESULT_TEST_FAILED)
{
  if (!expression)
    throw r;
}

#define SUBSEG_LENGTH	60

static HRESULT CreateAAFFile(aafWChar * pFileName)
{
	IAAFFile*					pFile = NULL;
	IAAFHeader*					pHeader = NULL;
	IAAFDictionary*  pDictionary = NULL;
	IAAFMob*					pMob = NULL;
	IAAFMob*					pReferencedMob = NULL;
	IAAFTimelineMobSlot*		newSlot = NULL;
	IAAFEssenceGroup*			essenceGroup = NULL;
	IAAFSegment*				pSeg = NULL;
	IAAFSegment*				pSegment = NULL;
	IAAFSourceClip*				pSourceClip = NULL;
	IAAFComponent*				pComponent = NULL;
	bool bFileOpen = false;
	aafProductIdentification_t	ProductInfo;
	aafLength_t					stillLength = 1, segLen = SUBSEG_LENGTH;
	AAFRESULT					hr = AAFRESULT_SUCCESS;
	aafUInt32					numChoices;
	aafProductVersion_t			testRev;

	aafProductVersion_t v;
	v.major = 1;
	v.minor = 0;
	v.tertiary = 0;
	v.patchLevel = 0;
	v.type = kAAFVersionUnknown;
	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFEssenceGroup Test";
	ProductInfo.productVersion = &v;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = UnitTestProductID;
	ProductInfo.platform = NULL;

	try
	{
	    // Remove the previous test file if any.
	    RemoveTestFile(pFileName);

		// Create the file
		checkResult(AAFFileOpenNewModify(pFileName, 0, &ProductInfo, &pFile));
		bFileOpen = true;
 
		// We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

		// Get the AAF Dictionary so that we can create valid AAF objects.
		checkResult(pHeader->GetDictionary(&pDictionary));
		CAAFBuiltinDefs defs (pDictionary);
 		
		//Make the MOB to be referenced
		checkResult(defs.cdMasterMob()->
					CreateInstance(IID_IAAFMob, 
								   (IUnknown **)&pReferencedMob));
		checkResult(pReferencedMob->SetMobID(TEST_referencedMobID));
		checkResult(pReferencedMob->SetName(L"AAFSourceClipTest::ReferencedMob"));

		// Create a Mob
		checkResult(defs.cdCompositionMob()->
					CreateInstance(IID_IAAFMob, 
								   (IUnknown **)&pMob));
		checkResult(pMob->SetMobID(TEST_MobID));
		checkResult(pMob->SetName(L"AAFSourceClipTest"));

		// Create an EssenceGroup
		checkResult(defs.cdEssenceGroup()->
					CreateInstance(IID_IAAFEssenceGroup, 
								   (IUnknown **)&essenceGroup));
		checkResult(essenceGroup->QueryInterface (IID_IAAFComponent, (void **)&pComponent));
		checkResult(pComponent->SetDataDef (defs.ddSound()));
		checkResult(pComponent->SetLength (segLen));
		pComponent->Release();
		pComponent = NULL;
		// Add a source clip still frame
		checkResult(defs.cdSourceClip()->
					CreateInstance(IID_IAAFSourceClip, 
								   (IUnknown **)&pSourceClip));
		checkResult(pSourceClip->QueryInterface (IID_IAAFComponent, (void **)&pComponent));
		checkResult(pComponent->SetDataDef (defs.ddSound()));
		checkResult(pComponent->SetLength (stillLength));
		checkResult(essenceGroup->SetStillFrame(pSourceClip)); 
		pComponent->Release();
		pComponent = NULL;
		pSourceClip->Release();
		pSourceClip = NULL;
		// Add a source clip alternate
		aafSourceRef_t sourceRef={0};
		checkResult(defs.cdSourceClip()->
					CreateInstance(IID_IAAFSourceClip, 
								   (IUnknown **)&pSourceClip));
		sourceRef.startTime=2;
		checkResult(pSourceClip->Initialize(defs.ddSound(),segLen,sourceRef));
		checkResult(pSourceClip->QueryInterface (IID_IAAFSegment, (void **)&pSegment));
		checkResult(essenceGroup->AppendChoice(pSegment)); 
		pSegment->Release();
		pSegment = NULL;
		pSourceClip->Release();
		pSourceClip = NULL;
		checkResult(essenceGroup->CountChoices(&numChoices));
		checkExpression(1 == numChoices, AAFRESULT_TEST_FAILED);

		checkResult(GetAAFVersions(pHeader, &testRev, NULL));

		if(DR4TestSupported(testRev))
		{
			// Add another source clip alternate
			checkResult(defs.cdSourceClip()->
				CreateInstance(IID_IAAFSourceClip, 
				(IUnknown **)&pSourceClip));
			sourceRef.startTime=0;
			checkResult(pSourceClip->Initialize(defs.ddSound(),segLen,sourceRef));
			checkResult(pSourceClip->QueryInterface (IID_IAAFSegment, (void **)&pSegment));
			checkResult(essenceGroup->PrependChoice(pSegment)); 
			pSegment->Release();
			pSegment = NULL;
			pSourceClip->Release();
			pSourceClip = NULL;
			checkResult(essenceGroup->CountChoices(&numChoices));
			checkExpression(2 == numChoices, AAFRESULT_TEST_FAILED);
			// Insert a third choice in the middle
			checkResult(defs.cdSourceClip()->
				CreateInstance(IID_IAAFSourceClip, 
				(IUnknown **)&pSourceClip));
			sourceRef.startTime=1;
			checkResult(pSourceClip->Initialize(defs.ddSound(),segLen,sourceRef));
			checkResult(pSourceClip->QueryInterface (IID_IAAFSegment, (void **)&pSegment));
			checkResult(essenceGroup->InsertChoiceAt(1,pSegment)); 
			pSegment->Release();
			pSegment = NULL;
			pSourceClip->Release();
			pSourceClip = NULL;
			checkResult(essenceGroup->CountChoices(&numChoices));
			checkExpression(3 == numChoices, AAFRESULT_TEST_FAILED);
			// Remove the third alternate, check for count of 2
			checkResult(essenceGroup->RemoveChoiceAt(2));
			checkResult(essenceGroup->CountChoices(&numChoices));
			checkExpression(2 == numChoices, AAFRESULT_TEST_FAILED);
		}

		checkResult(essenceGroup->QueryInterface (IID_IAAFSegment, (void **)&pSeg));
		aafRational_t editRate = { 0, 1};
		checkResult(pMob->AppendNewTimelineSlot (editRate,
												 pSeg,
												 1,
												 slotName,
												 0,
												 &newSlot));
		pSeg->Release();
		pSeg = NULL;

		checkResult(pHeader->AddMob(pMob));
		checkResult(pHeader->AddMob(pReferencedMob));
	}
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }

  // Cleanup and return
  if (pSourceClip)
	{
	  pSourceClip->Release();
	  pSourceClip = 0;
	}

  if (pSeg)
	{
	  pSeg->Release();
	  pSeg = 0;
	}

  if (pComponent)
	{
	  pComponent->Release();
	  pComponent = 0;
	}

  if (newSlot)
	{
	  newSlot->Release();
	  newSlot = 0;
	}

  if (essenceGroup)
	{
	  essenceGroup->Release();
	  essenceGroup = 0;
	}

  if (pMob)
	{
	  pMob->Release();
	  pMob = 0;
	}

  if (pReferencedMob)
	{
	  pReferencedMob->Release();
	  pReferencedMob = 0;
	}

  if (pDictionary)
	{
	  pDictionary->Release();
	  pDictionary = 0;
	}

  if (pHeader)
	{
	  pHeader->Release();
	  pHeader = 0;
	}

  if (pFile) 
	{
	  if (bFileOpen)
		{
		  pFile->Save();
		  pFile->Close();
		}
	  pFile->Release();
	  pFile = 0;
	}


	return hr;
}

static HRESULT ReadAAFFile(aafWChar * pFileName)
{
	// IAAFSession *				pSession = NULL;
	IAAFFile *					pFile = NULL;
	IAAFHeader *				pHeader = NULL;
	IEnumAAFMobs*				pMobIter = NULL;
	IAAFMob*					pMob = NULL;
	IAAFMob*					pReferencedMob = NULL;
	IEnumAAFMobSlots*			pSlotIter = NULL;
	IAAFMobSlot*				pSlot = NULL;
	IAAFEssenceGroup*			pEssenceGroup = NULL;
	IAAFSegment*				pSegment = NULL;
	IAAFSourceClip*				pSourceClip = NULL;
	IAAFComponent*				pComponent = NULL;
	aafLength_t					readLength;
	bool bFileOpen = false;
	aafSearchCrit_t				criteria;
	aafNumSlots_t				numMobs, numSlots;
	aafUInt32					readNumChoices;
	aafInt32					expectedChoices;
	HRESULT						hr = AAFRESULT_SUCCESS;


	try
	{ 
    // Open the file
		checkResult(AAFFileOpenExistingRead(pFileName, 0, &pFile));
		bFileOpen = true;
 
    // We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

		aafProductVersion_t testRev, testFileRev;
		checkResult(GetAAFVersions(pHeader, &testRev, &testFileRev));

		// Get the number of mobs in the file (should be two)
		checkResult(pHeader->CountMobs(kAAFAllMob, &numMobs));
		checkExpression(2 == numMobs, AAFRESULT_TEST_FAILED);

		// Enumerate over all Composition Mobs
		criteria.searchTag = kAAFByMobKind;
		criteria.tags.mobKind = kAAFCompMob;
		checkResult(pHeader->GetMobs(&criteria, &pMobIter));
		while (AAFRESULT_SUCCESS == pMobIter->NextOne(&pMob))
		{
			checkResult(pMob->CountSlots(&numSlots));
			checkExpression(1 == numSlots, AAFRESULT_TEST_FAILED);

			checkResult(pMob->GetSlots(&pSlotIter));
			while (AAFRESULT_SUCCESS == pSlotIter->NextOne(&pSlot))
			{
				// The segment should be a source clip...
				checkResult(pSlot->GetSegment(&pSegment));
				checkResult(pSegment->QueryInterface (IID_IAAFEssenceGroup, (void **)&pEssenceGroup));
				pSegment->Release();
				pSegment = NULL;
				/***/
				checkResult(pEssenceGroup->GetStillFrame(&pSourceClip));
				checkResult(pSourceClip->QueryInterface (IID_IAAFComponent, (void **)&pComponent));
				checkResult(pComponent->GetLength(&readLength));
				checkExpression(1 == readLength, AAFRESULT_TEST_FAILED);
				pSourceClip->Release();
				pSourceClip = NULL;
				pComponent->Release();
				pComponent = NULL;
				/***/
				checkResult(pEssenceGroup->CountChoices(&readNumChoices));

				if ( DR4TestSupported(testRev) && DR4TestSupported(testFileRev) )
					expectedChoices = 2;
				else
					expectedChoices = 1;
				checkExpression(expectedChoices == (aafInt32)readNumChoices, AAFRESULT_TEST_FAILED);

				/***/
				for(int n=0;n<(aafInt32)readNumChoices;n++)
				{
					checkResult(pEssenceGroup->GetChoiceAt (n, &pSegment));
					checkResult(pSegment->QueryInterface (IID_IAAFComponent, (void **)&pComponent));
					checkResult(pComponent->GetLength(&readLength));
					checkExpression(SUBSEG_LENGTH == readLength, AAFRESULT_TEST_FAILED);
					checkResult(pSegment->QueryInterface(IID_IAAFSourceClip,
						(void**)&pSourceClip));
					aafSourceRef_t sourceRef;
					checkResult(pSourceClip->GetSourceReference(&sourceRef));
					if(expectedChoices != 1)
					{
						checkExpression(sourceRef.startTime==n);
					}
					pSegment->Release();
					pSegment = NULL;
					pComponent->Release();
					pComponent = NULL;
					pSourceClip->Release();
					pSourceClip = NULL;
				}

				pEssenceGroup->Release();
				pEssenceGroup = NULL;
				pSlot->Release();
				pSlot = NULL;
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
	if (pReferencedMob)
		pReferencedMob->Release();

	if (pSourceClip)
		pSourceClip->Release();

	if (pComponent)
		pComponent->Release();

	if (pEssenceGroup)
		pEssenceGroup->Release();

	if (pSlot)
		pSlot->Release();

	if (pSlotIter)
		pSlotIter->Release();

	if (pMob)
		pMob->Release();

	if (pMobIter)
		pMobIter->Release();

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
 


extern "C" HRESULT CAAFEssenceGroup_test(testMode_t mode);
extern "C" HRESULT CAAFEssenceGroup_test(testMode_t mode)
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
 	aafWChar * pFileName = L"AAFEssenceGroupTest.aaf";

	try
	{
		if(mode == kAAFUnitTestReadWrite)
			hr = CreateAAFFile(pFileName);
		else
			hr = AAFRESULT_SUCCESS;
		if(hr == AAFRESULT_SUCCESS)
			hr = ReadAAFFile( pFileName );
	}
	catch (...)
	{
	  cerr << "CAAFEssenceGroup_test...Caught general C++"
		   << " exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

	return hr;
}
