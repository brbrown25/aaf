// @doc INTERNAL
// @com This file implements the module test for CAAFTimecodeStream
/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 * prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/


#include "AAF.h"
#include "AAFResult.h"
#include "AAFStoredObjectIDs.h"
#include "AAFDefUIDs.h"

#include "CAAFBuiltinDefs.h"

#include <iostream.h>
#include <stdio.h>

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

static char				testPattern[] = "ATestBuffer Pattern";
static aafRational_t	testSpeed = { 2997, 100 };
static aafUInt32		userData1 = 0x526F626E;
static aafUInt32		userData2 = 0x42656361;
static aafUInt32		userData3 = 0x53617261;

static HRESULT CreateAAFFile(aafWChar * pFileName)
{
	IAAFFile *					pFile = NULL;
	bool bFileOpen = false;
	IAAFHeader *				pHeader = NULL;
  IAAFDictionary*  pDictionary = NULL;
	IAAFCompositionMob*			pCompMob=NULL;
	IAAFMob						*pMob = NULL;
	IAAFTimelineMobSlot			*pNewSlot = NULL;
	IAAFTimecodeStream12M		*pTimecodeStream12M = NULL;
	IAAFTimecodeStream			*pTimecodeStream = NULL;
	IAAFSegment					*pSeg = NULL;
	IAAFComponent*		pComponent = NULL;

	aafMobID_t					newMobID;
	aafProductIdentification_t	ProductInfo;
	HRESULT						hr = S_OK;
	aafLength_t					zero;
	aafTimecode_t				startTC;
	aafUInt32					n;

	zero = 0;
	aafProductVersion_t v;
	v.major = 1;
	v.minor = 0;
	v.tertiary = 0;
	v.patchLevel = 0;
	v.type = kAAFVersionUnknown;
	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFTimecodeStream12M Test";
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
		
		// Create a CompositionMob
		checkResult(defs.cdCompositionMob()->
					CreateInstance(IID_IAAFCompositionMob, 
								   (IUnknown **)&pCompMob));
		
		// Get a MOB interface
		checkResult(pCompMob->QueryInterface (IID_IAAFMob, (void **)&pMob));
		checkResult(CoCreateGuid((GUID *)&newMobID));
		checkResult(pMob->SetMobID(newMobID));
		
		checkResult(pCompMob->Initialize(L"COMPMOB01"));
		
		checkResult(defs.cdTimecodeStream12M()->
					CreateInstance(IID_IAAFTimecodeStream12M, 
								   (IUnknown **)&pTimecodeStream12M));		
		 checkResult(pTimecodeStream12M->QueryInterface(IID_IAAFComponent, (void **)&pComponent));
		 checkResult(pComponent->SetDataDef(defs.ddPicture()));
		pComponent->Release();
		pComponent = NULL;
		 

		checkResult(pTimecodeStream12M->QueryInterface (IID_IAAFSegment, (void **)&pSeg));
		aafRational_t editRate = { 0, 1};
		checkResult(pMob->AppendNewTimelineSlot (editRate,
												 pSeg,
												 0,
												 L"TimecodeStream12M",
												 0,
												 &pNewSlot));
		checkResult(pHeader->AddMob(pMob));

		/* Can we do this bottom up?? !!! */
		checkResult(pTimecodeStream12M->QueryInterface (IID_IAAFTimecodeStream, (void **)&pTimecodeStream));
		checkResult(pTimecodeStream->SetSampleRate(testSpeed));
		checkResult(pTimecodeStream->SetSourceType(kAAFTimecodeLTC));

		startTC.startFrame = 108000;		// 1 hour, non-drop
		startTC.drop = kAAFTcNonDrop;
		startTC.fps = 30;

		// Set up:
		// 60 frames counting from 1:0:0:0 to 1:0:1:29
		// Tape discontinuity from 1:0:2:0 to 1:0:2:29 (short)
		// 30 frames counting from 1:0:3:0 to 1:0:4:0
		// Tape discontinuity from 1:0:4:0 to 1:59:59:29
		// 60 frames counting from 2:0:0:0 to 2:0:1:29
		// Tape discontinuity (non incrementing) from 2:0:2:0 to 23:59:59:29
		// 30 frames counting from 0:0:0:0 to 0:0:0:29

		// Segment #1
		for(n = 0; n < 60; n++)
		{
			checkResult(pTimecodeStream->SetPositionTimecode(n, startTC));
			checkResult(pTimecodeStream->SetUserDataAtPosition(n, sizeof(userData1), (aafUInt8*)&userData1));
			startTC.startFrame++;
		}

		// Segment #2
		startTC.startFrame = 108090;
		for(n = 60; n < 120; n++)
		{
			checkResult(pTimecodeStream->SetPositionTimecode(n, startTC));
			checkResult(pTimecodeStream->SetUserDataAtPosition(n, sizeof(userData3), (aafUInt8*)&userData3));
			startTC.startFrame++;
		}

		// Segment #3
		startTC.startFrame = (108000L * 2L);		// 2 hour, non-drop
		for(n = 120; n < 180; n++)
		{
			checkResult(pTimecodeStream->SetPositionTimecode(n, startTC));
			checkResult(pTimecodeStream->SetUserDataAtPosition(n, sizeof(userData2), (aafUInt8*)&userData2));
			startTC.startFrame++;
		}

		// Segment #4
		startTC.startFrame = 0;
		for(n = 180; n < 210; n++)
		{
			checkResult(pTimecodeStream->SetPositionTimecode(n, startTC));
			checkResult(pTimecodeStream->SetUserDataAtPosition(n, sizeof(userData3), (aafUInt8*)&userData3));
			startTC.startFrame++;
		}
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

	if (pComponent)
		pComponent->Release();
	if (pTimecodeStream12M)
		pTimecodeStream12M->Release();

	if (pTimecodeStream)
		pTimecodeStream->Release();

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
		  {
			pFile->Save();
			pFile->Close();
		  }
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
  IEnumAAFMobs*				pMobIter = NULL;
  IEnumAAFMobSlots*			pEnum = NULL;
  IAAFMob*					pMob = NULL;
  IAAFMobSlot*				pMobSlot = NULL;
  IAAFSegment*				pSeg = NULL;
  IAAFTimecodeStream12M*		pTimecodeStream12M = NULL;
  IAAFTimecodeStream*			pTimecodeStream = NULL;
  aafTimecode_t				startTC;
  aafTimecodeSourceType_t		checkType;
  aafRational_t				checkSpeed, testRate;
  aafUInt32					checkSampleSize, checkUserData;
  // aafUInt32				checkUserDataLen;
  aafPosition_t				offset;
  AAFRESULT					status;
  aafProductIdentification_t	ProductInfo;
  aafNumSlots_t				numMobs;
  HRESULT						hr = S_OK;

  aafProductVersion_t v;
  v.major = 1;
  v.minor = 0;
  v.tertiary = 0;
  v.patchLevel = 0;
  v.type = kAAFVersionUnknown;
  ProductInfo.companyName = L"AAF Developers Desk. NOT!";
  ProductInfo.productName = L"AAFTimecodeStream12M Test. NOT!";
  ProductInfo.productVersion = &v;
  ProductInfo.productVersionString = NULL;
  ProductInfo.platform = NULL;

  try
  {
    // Open the file
		checkResult(AAFFileOpenExistingRead(pFileName, 0, &pFile));
		bFileOpen = true;
 
    // We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

		// Get the number of mobs in the file (should be one)
		checkResult(pHeader->CountMobs(kAAFAllMob, &numMobs));
		checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);

    checkResult(pHeader->GetMobs( NULL, &pMobIter));
		while (AAFRESULT_SUCCESS == pMobIter->NextOne(&pMob))
		{
      checkResult(pMob->GetSlots (&pEnum));

      while (AAFRESULT_SUCCESS == pEnum->NextOne (&pMobSlot))
      {
        checkResult(pMobSlot->GetSegment (&pSeg));
        // Get a TimecodeStream12M interface 
        checkResult(pSeg->QueryInterface (IID_IAAFTimecodeStream12M, (void **)&pTimecodeStream12M));

		checkResult(pTimecodeStream12M->QueryInterface (IID_IAAFTimecodeStream, (void **)&pTimecodeStream));
        checkResult(pTimecodeStream->GetSampleRate(&checkSpeed));
        checkExpression(testSpeed.numerator == testSpeed.numerator, AAFRESULT_TEST_FAILED);
        checkExpression(testSpeed.denominator == testSpeed.denominator, AAFRESULT_TEST_FAILED);

        checkResult(pTimecodeStream->GetSourceType(&checkType));
        checkExpression(checkType == kAAFTimecodeLTC, AAFRESULT_TEST_FAILED);

        // A 12M stream is 10 bytes long
		checkResult(pTimecodeStream->GetSampleSize(&checkSampleSize));
        checkExpression(checkSampleSize == 10, AAFRESULT_TEST_FAILED);

		checkResult(pTimecodeStream->GetPositionTimecode(0, &startTC));
        checkExpression(startTC.startFrame == 108000, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);


//		checkResult(pTimecodeStream12M->GetUserDataLength((aafInt32*)&checkUserDataLen));
//       checkExpression(checkUserDataLen == 4, AAFRESULT_TEST_FAILED);	// For 12M
		checkResult(pTimecodeStream->GetUserDataAtPosition(0, sizeof(checkUserData), (aafUInt8*)&checkUserData));
        checkExpression(checkUserData == userData1, AAFRESULT_TEST_FAILED);
		checkResult(pTimecodeStream->GetUserDataAtPosition(120, sizeof(checkUserData), (aafUInt8*)&checkUserData));
        checkExpression(checkUserData == userData2, AAFRESULT_TEST_FAILED);
		checkResult(pTimecodeStream->GetUserDataAtPosition(180, sizeof(checkUserData), (aafUInt8*)&checkUserData));
        checkExpression(checkUserData == userData3, AAFRESULT_TEST_FAILED);

		/**********/
		offset = 0;		// Group 1 lower bound	 
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == 108000, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
		/****/
		offset = 60;	// Group 2 lower bound
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == 108090, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
		/****/
		offset = 120;	// Group 3 Lower Bound
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == (108000L * 2L), AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
		/****/
		offset = 121;	// Group 3 Middle
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == (108000L * 2L)+1, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
		/****/
		offset = 179;	// Group 3 UpperBound
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == (108000L * 2L)+59, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);
		/****/
		offset = 180;	// Group 3 lower bound
		checkResult(pSeg->SegmentOffsetToTC(&offset, &startTC));
        checkExpression(startTC.startFrame == 0, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.drop == kAAFTcNonDrop, AAFRESULT_TEST_FAILED);
        checkExpression(startTC.fps == 30, AAFRESULT_TEST_FAILED);

		/**********/
        startTC.drop = kAAFTcNonDrop;
        startTC.fps = 30;
        startTC.startFrame = 108000;		// Group 1 lower bound (Tests path #1 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 0, AAFRESULT_TEST_FAILED);
  		/****/
        startTC.startFrame = 108090;				// Group 2 lower bound (Tests path #2 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 60, AAFRESULT_TEST_FAILED);
		/****/
        startTC.startFrame = (108000L * 2L);		// Group 3 lower bound (Tests path #3 & #6 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 120, AAFRESULT_TEST_FAILED);
		/****/
        startTC.startFrame = (108000L * 2L)+1;		// Group 3 middle (Tests path #3 & #6 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 121, AAFRESULT_TEST_FAILED);
		/****/
        startTC.startFrame = (108000L * 2L)+59;		// Group 3 upper bound (Tests path #3 & #6 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 179, AAFRESULT_TEST_FAILED);
		/****/
        startTC.startFrame = 0;						// Group 4 lower bound (Tests path #3 & #6 through code)
		checkResult(pSeg->SegmentTCToOffset(&startTC, &testRate, &offset));
        checkExpression(testRate.numerator == 2997, AAFRESULT_TEST_FAILED);
        checkExpression(testRate.denominator == 100, AAFRESULT_TEST_FAILED);
        checkExpression(offset == 180, AAFRESULT_TEST_FAILED);

		/****/
        startTC.startFrame = 23L*60L*60L*30L;		// Out of bounds TC (Tests path #8 through code)
		status = pSeg->SegmentTCToOffset(&startTC, &testRate, &offset);
        checkExpression(status == AAFRESULT_TIMECODE_NOT_FOUND, AAFRESULT_TEST_FAILED);

		pTimecodeStream12M->Release();
        pTimecodeStream12M = NULL;

		pSeg->Release();
        pSeg = NULL;
      }

      pEnum->Release();
      pEnum = NULL;

      pMob->Release();
      pMob = NULL;
	  }
	}
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }
	

	// Cleanup and return
	if (pTimecodeStream12M)
		pTimecodeStream12M->Release();

	if (pTimecodeStream)
		pTimecodeStream->Release();

	if (pSeg)
		pSeg->Release();

	if (pMobSlot)
		pMobSlot->Release();

	if (pEnum)
		pEnum->Release();

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

extern "C" HRESULT CAAFTimecodeStream12M_test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
	aafWChar * pFileName = L"AAFTimecodeStream12MTest.aaf";

	try
	{
		hr = CreateAAFFile(	pFileName );
		if(hr == AAFRESULT_SUCCESS)
			hr = ReadAAFFile( pFileName );
	}
	catch (...)
	{
	  cerr << "CAAFTimecodeStream12M::test...Caught general C++"
		" exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

	// When all of the functionality of this class is tested, we can return success.
	// When a method and its unit test have been implemented, remove it from the list.
//	if (SUCCEEDED(hr))
//	{
//		cout << "The following IAAFDefObject methods have not been tested:" << endl; 
//		cout << "     SegmentOffsetToTC" << endl; 
//		cout << "     SegmentTCToOffset" << endl; 
//		hr = AAFRESULT_TEST_PARTIAL_SUCCESS;
//	}

	// Cleanup our object if it exists.
	return hr;
}


