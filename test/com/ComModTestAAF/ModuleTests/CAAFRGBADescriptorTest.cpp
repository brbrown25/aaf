// @doc INTERNAL
// @com This file implements the module test for CAAFRGBADescriptor
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

#include <iostream.h>
#include <stdio.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "AAFDefUIDs.h"

#include "CAAFBuiltinDefs.h"


// default test values
#define kStoredHeightTestVal			248
#define kStoredWidthTestVal				720
#define kFrameLayoutTestVal				kAAFSeparateFields
#define kVideoLineMapMaxElement			2
#define kVideoLineMap1TestVal			10
#define kVideoLineMap2TestVal			11
#define kImageAspectRatioNumTestVal		4
#define kImageAspectRatioDenTestVal		3
#define kSampledHeightTestVal			247
#define kSampledWidthTestVal			719
#define kSampledXOffsetTestVal			5
#define kSampledYOffsetTestVal			6
#define kDisplayHeightTestVal			246
#define kDisplayWidthTestVal			718
#define kDisplayXOffsetTestVal			7
#define kDisplayYOffsetTestVal			8
#define kAlphaTransparencyTestVal		kAAFMaxValueTransparent
#define kImageAlignmentFactorTestVal	0
#define kGammaNumTestVal				7
#define kGammaDenTestVal				8

#define NUM_TEST_ELEMENTS	3
aafRGBAComponent_t	testElements[NUM_TEST_ELEMENTS] = { {kAAFCompRed,8}, {kAAFCompGreen,8}, {kAAFCompBlue,8} };
aafRGBAComponent_t	testElements2[NUM_TEST_ELEMENTS] = { {kAAFCompGreen,8}, {kAAFCompBlue,8}, {kAAFCompRed,8} };
#define TEST_PALETTE_SIZE	16
aafUInt8	bogusPalette[TEST_PALETTE_SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 };

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


static HRESULT OpenAAFFile(aafWChar*			pFileName,
						   aafMediaOpenMode_t	mode,
						   IAAFFile**			ppFile,
						   IAAFHeader**			ppHeader)
{
	aafProductIdentification_t	ProductInfo;
	HRESULT						hr = AAFRESULT_SUCCESS;

	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFRGBADescriptor Test";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kAAFVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = UnitTestProductID;
	ProductInfo.platform = NULL;

	*ppFile = NULL;

	switch (mode)
	{
	case kAAFMediaOpenReadOnly:
		hr = AAFFileOpenExistingRead(pFileName, 0, ppFile);
		break;

	case kAAFMediaOpenAppend:
		hr = AAFFileOpenNewModify(pFileName, 0, &ProductInfo, ppFile);
		break;

	default:
		hr = AAFRESULT_TEST_FAILED;
		break;
	}

	if (FAILED(hr))
	{
		if (*ppFile)
		{
			(*ppFile)->Release();
			*ppFile = NULL;
		}
		return hr;
	}
  
  	hr = (*ppFile)->GetHeader(ppHeader);
	if (FAILED(hr))
	{
		(*ppFile)->Release();
		*ppFile = NULL;
		return hr;
	}
 	
	return hr;
}

static HRESULT CreateAAFFile(aafWChar * pFileName)
{
	IAAFFile*		pFile = NULL;
	IAAFHeader*		pHeader = NULL;
	IAAFDictionary*	pDictionary = NULL;
	IAAFSourceMob*	pSourceMob = NULL;
	IAAFMob*	pMob = NULL;
	IAAFDigitalImageDescriptor*	pDIDesc = NULL;
	IAAFRGBADescriptor*	pRGBADesc = NULL;
	IAAFEssenceDescriptor*	pEssDesc = NULL;
	aafMobID_t		newMobID;
	HRESULT			hr = AAFRESULT_SUCCESS;


  try
  {  
    // Remove the previous test file if any.
    RemoveTestFile(pFileName);

    // Create the AAF file
    checkResult(OpenAAFFile(pFileName, kAAFMediaOpenAppend, &pFile, &pHeader));

    // Get the AAF Dictionary so that we can create valid AAF objects.
    checkResult(pHeader->GetDictionary(&pDictionary));
	CAAFBuiltinDefs defs (pDictionary);

    // Create a source mob
    checkResult(defs.cdSourceMob()->
				CreateInstance(IID_IAAFSourceMob, 
							   (IUnknown **)&pSourceMob));
    checkResult(pSourceMob->QueryInterface(IID_IAAFMob, (void **)&pMob));

    checkResult(CoCreateGuid((GUID *)&newMobID));
    checkResult(pMob->SetMobID(newMobID));
    checkResult(pMob->SetName(L"RGBADescriptorTest"));


    // Create a digitial image descriptor.
    checkResult(defs.cdRGBADescriptor()->
				CreateInstance(IID_IAAFRGBADescriptor, 
							   (IUnknown **)&pRGBADesc));		
    checkResult(pRGBADesc->QueryInterface(IID_IAAFDigitalImageDescriptor, (void **)&pDIDesc));

    aafRational_t	ratio;
    aafInt32		VideoLineMap[kVideoLineMapMaxElement] = {kVideoLineMap1TestVal,kVideoLineMap2TestVal};
    aafUID_t		compression;
    memset(&compression, 0, sizeof(aafUID_t));

    // Add all RGBA properties
    // Reguired Properties
    checkResult(pDIDesc->SetStoredView(kStoredHeightTestVal, kStoredWidthTestVal));
    checkResult(pDIDesc->SetFrameLayout(kFrameLayoutTestVal));
    checkResult(pDIDesc->SetVideoLineMap(kVideoLineMapMaxElement, VideoLineMap));

    ratio.numerator = kImageAspectRatioNumTestVal;
    ratio.denominator = kImageAspectRatioDenTestVal;
    checkResult(pDIDesc->SetImageAspectRatio(ratio));

    // Optional Properties
    checkResult(pDIDesc->SetCompression(compression));
    checkResult(pDIDesc->SetSampledView(kSampledHeightTestVal, kSampledWidthTestVal, kSampledXOffsetTestVal, kSampledYOffsetTestVal));
    checkResult(pDIDesc->SetDisplayView(kDisplayHeightTestVal, kDisplayWidthTestVal, kDisplayXOffsetTestVal, kDisplayYOffsetTestVal));
    checkResult(pDIDesc->SetAlphaTransparency(kAlphaTransparencyTestVal));
    checkResult(pDIDesc->SetImageAlignmentFactor(kImageAlignmentFactorTestVal));

    ratio.numerator = kGammaNumTestVal;
    ratio.denominator = kGammaDenTestVal;
    checkResult(pDIDesc->SetGamma(ratio));

    checkResult(pRGBADesc->SetPixelLayout(NUM_TEST_ELEMENTS, testElements));
    checkResult(pRGBADesc->SetPallete(sizeof(bogusPalette), bogusPalette));
    checkResult(pRGBADesc->SetPaletteLayout(NUM_TEST_ELEMENTS, testElements2));
  
	// Save the initialized descriptor with the source mob.
    checkResult(pDIDesc->QueryInterface(IID_IAAFEssenceDescriptor, (void **)&pEssDesc));
    checkResult(pSourceMob->SetEssenceDescriptor(pEssDesc));

    // Add the MOB to the file
    checkResult(pHeader->AddMob(pMob));
  }
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }

  // Cleanup and return
  if (pEssDesc)
    pEssDesc->Release();

  if (pDIDesc)
    pDIDesc->Release();

  if (pMob)
    pMob->Release();

  if (pSourceMob)
    pSourceMob->Release();

	if (pDictionary)
    pDictionary->Release();

	if (pHeader)
    pHeader->Release();

	if (pFile)
	{
		pFile->Save();
		pFile->Close();
		pFile->Release();
	}

	return hr;
}

static HRESULT ReadAAFFile(aafWChar * pFileName)
{
	IAAFFile*		pFile = NULL;
	IAAFHeader*		pHeader = NULL;
	IEnumAAFMobs*	pMobIter = NULL;
	IAAFMob*	pMob = NULL;
	IAAFSourceMob*	pSourceMob = NULL;
	IAAFEssenceDescriptor*	pEssDesc = NULL;
	IAAFDigitalImageDescriptor*	pDIDesc = NULL;
	IAAFRGBADescriptor*	pRGBADesc = NULL;
	aafNumSlots_t	numMobs = 0;
	HRESULT			hr = AAFRESULT_SUCCESS;
	aafRGBAComponent_t	readElements[NUM_TEST_ELEMENTS];
	aafInt32		n;
	aafUInt32		readPaletteSize;
	aafUInt8		readPalette[TEST_PALETTE_SIZE];

  try
  {
	  // Open the AAF file
	  checkResult(OpenAAFFile(pFileName, kAAFMediaOpenReadOnly, &pFile, &pHeader));

    // Make sure there is one a single mob in the file.
	  checkResult(pHeader->CountMobs(kAAFAllMob, &numMobs));
	  checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);

    // Loop to the first mob.
	  checkResult(pHeader->GetMobs(NULL, &pMobIter));
	  checkResult(pMobIter->NextOne(&pMob));

	  checkResult(pMob->QueryInterface(IID_IAAFSourceMob, (void **)&pSourceMob));

    // Back into testing mode
	  checkResult(pSourceMob->GetEssenceDescriptor(&pEssDesc));

    // if there is an Essence Descriptor then it MUST be an (essence) RGBA Descriptor
	  checkResult(pEssDesc->QueryInterface(IID_IAAFDigitalImageDescriptor, (void **) &pDIDesc));
	  checkResult(pEssDesc->QueryInterface(IID_IAAFRGBADescriptor, (void **) &pRGBADesc));

    // TODO: test for expected DigitalImage properties
	  aafUInt32				val1, val2;
	  aafInt32				val3, val4;
	  aafFrameLayout_t		framelayout;
	  aafAlphaTransparency_t	alphaTrans;
	  aafRational_t			ratio;
	  aafInt32				VideoLineMap[kVideoLineMapMaxElement];
	  aafUID_t				compression, compTestVal;

	  memset(&compTestVal, 0, sizeof(aafUID_t));

	  // Add all DigitalImage properties
	  // Reguired Properties
	  checkResult(pDIDesc->GetStoredView(&val1, &val2));
	  checkExpression(val1 == kStoredHeightTestVal && val2 == kStoredWidthTestVal,
						        AAFRESULT_TEST_FAILED);

	  checkResult(pDIDesc->GetFrameLayout(&framelayout));
	  checkExpression(framelayout == kFrameLayoutTestVal, AAFRESULT_TEST_FAILED);

	  checkResult(pDIDesc->GetVideoLineMapSize(&val1));
	  checkExpression(val1 == kVideoLineMapMaxElement, AAFRESULT_TEST_FAILED);

	  checkResult(pDIDesc->GetVideoLineMap(kVideoLineMapMaxElement, VideoLineMap));
	  checkExpression(VideoLineMap[0] == kVideoLineMap1TestVal && 
                    VideoLineMap[1] == kVideoLineMap2TestVal,
                    AAFRESULT_TEST_FAILED);
						  
	  checkResult(pDIDesc->GetImageAspectRatio(&ratio));
    checkExpression(ratio.numerator == kImageAspectRatioNumTestVal &&
                    ratio.denominator == kImageAspectRatioDenTestVal,
                    AAFRESULT_TEST_FAILED);

	  // Optional Properties
	  checkResult(pDIDesc->GetCompression(&compression));
	  checkExpression(memcmp(&compression, &compTestVal, sizeof(aafUID_t)) == 0,
                    AAFRESULT_TEST_FAILED);

	  checkResult(pDIDesc->GetSampledView(&val1, &val2, &val3, &val4));
	  checkExpression(val1 == kSampledHeightTestVal && val2 == kSampledWidthTestVal &&
                    val3 == kSampledXOffsetTestVal && val4 == kSampledYOffsetTestVal,
                    AAFRESULT_TEST_FAILED);

		checkResult(pDIDesc->GetDisplayView(&val1, &val2, &val3, &val4));
		checkExpression(val1 == kDisplayHeightTestVal && val2 == kDisplayWidthTestVal &&
                    val3 == kDisplayXOffsetTestVal && val4 == kDisplayYOffsetTestVal,
                    AAFRESULT_TEST_FAILED);

		checkResult(pDIDesc->GetAlphaTransparency(&alphaTrans));
		checkExpression(alphaTrans == kAlphaTransparencyTestVal,
                    AAFRESULT_TEST_FAILED);

		checkResult(pDIDesc->GetImageAlignmentFactor(&val3));
		checkExpression(val3 == kImageAlignmentFactorTestVal,
                    AAFRESULT_TEST_FAILED);

		checkResult(pDIDesc->GetGamma(&ratio));
		checkExpression(ratio.numerator == kGammaNumTestVal &&
			              ratio.denominator == kGammaDenTestVal,
                    AAFRESULT_TEST_FAILED);

		checkResult(pRGBADesc->GetPixelLayout(NUM_TEST_ELEMENTS, readElements));
		for(n = 0; n < NUM_TEST_ELEMENTS; n++)
		{
			if(readElements[n].Code != testElements[n].Code)
				throw AAFRESULT_TEST_FAILED;
			if(readElements[n].Size != testElements[n].Size)
				throw AAFRESULT_TEST_FAILED;
		}
		checkResult(pRGBADesc->GetPaletteSize(&readPaletteSize));
 		if(readPaletteSize != TEST_PALETTE_SIZE)
			throw AAFRESULT_TEST_FAILED;
		checkResult(pRGBADesc->GetPalette(TEST_PALETTE_SIZE, readPalette));
 		for(n = 0; n < TEST_PALETTE_SIZE; n++)
		{
			if(readPalette[n] != bogusPalette[n])
				throw AAFRESULT_TEST_FAILED;
		}
		checkResult(pRGBADesc->GetPaletteLayout(NUM_TEST_ELEMENTS, readElements));
		for(n = 0; n < NUM_TEST_ELEMENTS; n++)
		{
			if(readElements[n].Code != testElements2[n].Code)
				throw AAFRESULT_TEST_FAILED;
			if(readElements[n].Size != testElements2[n].Size)
				throw AAFRESULT_TEST_FAILED;
		}
  }
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }

  // Cleanup and return
  if (pEssDesc)
    pEssDesc->Release();

  if (pDIDesc)
    pDIDesc->Release();

  if (pMob)
    pMob->Release();

  if (pMobIter)
    pMobIter->Release();

  if (pSourceMob)
    pSourceMob->Release();

	if (pHeader)
    pHeader->Release();

	if (pFile)
	{
		pFile->Close();
		pFile->Release();
	}

	return hr;
}

extern "C" HRESULT CAAFRGBADescriptor_test()
{
	aafWChar*	pFileName = L"AAFRGBADescripTest.aaf";
	HRESULT		hr = AAFRESULT_NOT_IMPLEMENTED;

	try
	{
		hr = CreateAAFFile(pFileName);
		if (SUCCEEDED(hr))
			hr = ReadAAFFile(pFileName);
	}
	catch (...)
	{
		cerr << "CAAFRGBADescriptor_test...Caught general C++ exception!" << endl; 
	}

	// When all of the functionality of this class is tested, we can return success.
	// When a method and its unit test have been implemented, remove it from the list.
//	if (SUCCEEDED(hr))
//	{
//		cout << "The following IAAFParameter methods have not been implemented:" << endl; 
//		cout << "     GetPalette" << endl; 
//		cout << "     GetPaletteSize" << endl; 
//		cout << "     GetPaletteLayout" << endl; 
//		hr = AAFRESULT_TEST_PARTIAL_SUCCESS;
//	}

	return hr;
}


    
    
    
    
    
    
    
