// @doc INTERNAL
// @com This file implements the module test for CAAFPluginDescriptor
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
#include "AAFPluginDefs.h"

#include <iostream.h>


static wchar_t *manuf1URL = L"www.microsoft.com";
static wchar_t *manuf2URL = L"www.avid.com";

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "AAFDataDefs.h"
#include "AAFDefUIDs.h"
#include "aafUtils.h"

#include "CAAFBuiltinDefs.h"

const aafUID_t MANUF_JEFFS_PLUGINS = { 0xA6487F21, 0xE78F, 0x11d2, { 0x80, 0x9E, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expPixelFormat */
// {E4E190C8-EA4A-11d3-A352-009027DFCA6A}
const aafUID_t CODEC_DEF_ID = 
{ 0xe4e190c8, 0xea4a, 0x11d3, { 0xa3, 0x52, 0x0, 0x90, 0x27, 0xdf, 0xca, 0x6a } };
aafVersionType_t samplePluginVersion = { 0, 0 };//, 0, 0, kVersionReleased };
aafVersionType_t sampleMinPlatformVersion = { 1, 2 }; //, 3, 4, kVersionDebug };
aafVersionType_t sampleMinEngineVersion = { 5, 6 }; //7, 9, kVersionPatched };
aafVersionType_t sampleMinAPIVersion = { 10, 11 };//, 12, 13, kAAFVersionBeta };
aafVersionType_t sampleMaxPlatformVersion = { 31, 32 };//3, 34, kVersionDebug };
aafVersionType_t sampleMaxEngineVersion = { 35, 36 };//, 37, 39, kVersionPatched };
aafVersionType_t sampleMaxAPIVersion = { 40, 41 };//, 42, 43, kAAFVersionBeta };

#define	MobName			L"MasterMOBTest"
#define	NumMobSlots		3

static wchar_t *manufName = L"Jeff's Plugin-O-Rama";
static wchar_t *manufRev = L"Rev0.0.0a0";

aafBool	EqualVersion(aafVersionType_t *vers1, aafVersionType_t *vers2)
{
	return(memcmp((char *)vers1, (char *)vers2, sizeof(aafVersionType_t)) == 0 ? kAAFTrue : kAAFFalse);
}

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

static aafUID_t TestPluginDesc = { 0x7C77C181, 0x2283, 0x11d2, { 0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

static HRESULT OpenAAFFile(aafWChar*			pFileName,
						   aafMediaOpenMode_t	mode,
						   IAAFFile**			ppFile,
						   IAAFHeader**			ppHeader)
{
	aafProductIdentification_t	ProductInfo;
	HRESULT						hr = AAFRESULT_SUCCESS;

	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFPluginDescriptor Test";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kAAFVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = UnitTestProductID;
	ProductInfo.platform = NULL;

	*ppFile = NULL;

	if(mode == kAAFMediaOpenAppend)
		hr = AAFFileOpenNewModify(pFileName, 0, &ProductInfo, ppFile);
	else
		hr = AAFFileOpenExistingRead(pFileName, 0, ppFile);

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
  IAAFHeader *      pHeader = NULL;
  IAAFDictionary*	pDictionary = NULL;
  IAAFDefObject*	pPlugDef = NULL;
  IAAFCodecDef*		pCodecDef = NULL;
  IAAFPluginDescriptor *pDesc = NULL;
  IAAFNetworkLocator *pNetLoc = NULL, *pNetLoc2 = NULL, *pNetLoc3 = NULL;
  IAAFLocator		*pLoc = NULL, *pLoc2 = NULL, *pLoc3 = NULL;
  aafUID_t			category = AUID_AAFDefObject, manufacturer = MANUF_JEFFS_PLUGINS;
  bool				bFileOpen = false;
  aafUInt32			numLocators;
	HRESULT			hr = S_OK;
/*	long			test;
*/

  try
  {
    // Remove the previous test file if any.
    RemoveTestFile(pFileName);


	  // Create the AAF file
	  checkResult(OpenAAFFile(pFileName, kAAFMediaOpenAppend, /*&pSession,*/ &pFile, &pHeader));
    bFileOpen = true;

    // Get the AAF Dictionary so that we can create valid AAF objects.
    checkResult(pHeader->GetDictionary(&pDictionary));
	CAAFBuiltinDefs defs (pDictionary);

	checkResult(defs.cdCodecDef()->
				CreateInstance(IID_IAAFDefObject, 
							   (IUnknown **)&pPlugDef));
	checkResult(defs.cdPluginDescriptor()->
				CreateInstance(IID_IAAFPluginDescriptor, 
							   (IUnknown **)&pDesc));
	checkResult(defs.cdNetworkLocator()->
				CreateInstance(IID_IAAFNetworkLocator, 
							   (IUnknown **)&pNetLoc));
	checkResult(pNetLoc->QueryInterface (IID_IAAFLocator,
                                          (void **)&pLoc));
	checkResult(pLoc->SetPath (manuf2URL));

	checkResult(pDesc->Initialize (TestPluginDesc, L"Test Plugin", L"TestPlugin Description"));
	checkResult(pDesc->SetCategoryClass(category));
	checkResult(pDesc->SetPluginVersionString(manufRev));
    checkResult(pDesc->SetManufacturerInfo(pNetLoc));
    checkResult(pDesc->SetManufacturerID(manufacturer));
    checkResult(pDesc->SetPluginManufacturerName(manufName));
    checkResult(pDesc->SetIsSoftwareOnly(kAAFTrue));
    checkResult(pDesc->SetIsAccelerated(kAAFFalse));
    checkResult(pDesc->SetSupportsAuthentication(kAAFFalse));
 
//!!!	aafProductVersion_t samplePluginVersion = { 0, 0, 0, 0, kVersionReleased };
    /**/
    checkResult(pDesc->SetHardwarePlatform(kAAFPlatformIndependant));
    checkResult(pDesc->SetPlatformMinimumVersion(sampleMinPlatformVersion));
    checkResult(pDesc->SetPlatformMaximumVersion(sampleMaxPlatformVersion));
    /**/
 	checkResult(pDesc->SetEngine(kAAFNoEngine));
    checkResult(pDesc->SetEngineMinimumVersion(sampleMinEngineVersion));
    checkResult(pDesc->SetEngineMaximumVersion(sampleMaxEngineVersion));
    /**/
	checkResult(pDesc->SetPluginAPI(kAAFEssencePluginAPI));
    checkResult(pDesc->SetPluginAPIMinimumVersion(sampleMinAPIVersion));
    checkResult(pDesc->SetPluginAPIMaximumVersion(sampleMaxAPIVersion));

	checkResult(pDictionary->RegisterPluginDef (	pDesc));

	  /**/
	checkResult(defs.cdNetworkLocator()->
				CreateInstance(IID_IAAFNetworkLocator, 
							   (IUnknown **)&pNetLoc2));
	checkResult(pNetLoc2->QueryInterface (IID_IAAFLocator,
                                          (void **)&pLoc2));
	checkResult(pLoc2->SetPath (manuf2URL));
    checkResult(pDesc->AppendLocator(pLoc2));
	/**/
	checkResult(pPlugDef->AppendPluginDef(pDesc));

	
	checkResult(pPlugDef->QueryInterface (IID_IAAFCodecDef,
                                          (void **)&pCodecDef));
    checkResult(pCodecDef->Initialize (CODEC_DEF_ID, L"Test", L"Really, just a test."));
	checkResult(pCodecDef->AddEssenceKind (defs.ddMatte()));
	checkResult(pDictionary->RegisterCodecDef(pCodecDef));
	/**/
	checkResult(defs.cdNetworkLocator()->
				CreateInstance(IID_IAAFNetworkLocator, 
							   (IUnknown **)&pNetLoc3));
	checkResult(pNetLoc3->QueryInterface (IID_IAAFLocator,
                                          (void **)&pLoc3));
	checkResult(pLoc3->SetPath (manuf1URL));
    checkResult(pDesc->PrependLocator(pLoc3));
	pLoc3->Release();
	pLoc3 = NULL;
	// Create a second locator, check for three locators, then delete it and recheck for two.
	checkResult(defs.cdNetworkLocator()->
				CreateInstance(IID_IAAFNetworkLocator, 
							   (IUnknown **)&pNetLoc3));
	checkResult(pNetLoc3->QueryInterface (IID_IAAFLocator,
                                          (void **)&pLoc3));
	checkResult(pLoc3->SetPath (manuf1URL));
    checkResult(pDesc->AppendLocator(pLoc3));
	pLoc3->Release();
	pLoc3 = NULL;
    checkResult(pDesc->CountLocators (&numLocators));
	checkExpression(3 == numLocators, AAFRESULT_TEST_FAILED);
    checkResult(pDesc->RemoveLocatorAt(2));
    checkResult(pDesc->CountLocators (&numLocators));
	checkExpression(2 == numLocators, AAFRESULT_TEST_FAILED);
  }
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }


  // Cleanup and return
  if (pDesc)
    pDesc->Release();

  if (pPlugDef)
    pPlugDef->Release();

  if (pNetLoc)
    pNetLoc->Release();

  if (pNetLoc2)
    pNetLoc2->Release();

  if (pNetLoc3)
    pNetLoc3->Release();

  if (pLoc)
    pLoc->Release();

  if (pLoc2)
    pLoc2->Release();

  if (pLoc3)
    pLoc3->Release();

  if (pCodecDef)
    pCodecDef->Release();

  if (pDictionary)
    pDictionary->Release();

  if (pHeader)
    pHeader->Release();
      
  if (pFile)
  {  // Close file
    if (bFileOpen)
	{
		pFile->Save();
		pFile->Close();
	}
     pFile->Release();
  }

  return hr;
}

static HRESULT ReadAAFFile(aafWChar* pFileName)
{
	IAAFFile*		pFile = NULL;
	IAAFHeader*		pHeader = NULL;
	IAAFDictionary*  pDictionary = NULL;
	IEnumAAFCodecDefs *pEnumPluggable = NULL;
	IAAFCodecDef *pCodecDef = NULL;
	IAAFDefObject *pDefObj = NULL;
	IEnumAAFPluginDescriptors *pEnumDesc;
	IAAFPluginDescriptor *pPlugin = NULL;
	IAAFNetworkLocator	*pNetLoc = NULL;
	IAAFLocator			*pLoc = NULL;
	IEnumAAFPluginLocators *pEnumLoc = NULL;

  bool bFileOpen = false;
	HRESULT			hr = S_OK;
	aafUID_t		testUID;
	aafUInt32		testUInt32;
	aafUInt32		count;
	wchar_t			testString[256];
	aafBool			testBool;
	aafHardwarePlatform_t testPlatform;
	aafPluginAPI_t	testAPI;
	aafEngine_t		testEngine;
	aafVersionType_t testMinVersion, testMaxVersion;
  aafUID_t			category = AUID_AAFDefinitionObject, manufacturer = MANUF_JEFFS_PLUGINS;

	try
	{
		// Open the AAF file
		checkResult(OpenAAFFile(pFileName, kAAFMediaOpenReadOnly, &pFile, &pHeader));
		bFileOpen = true;

		checkResult(pHeader->GetDictionary(&pDictionary));
	
		checkResult(pDictionary->GetCodecDefs(&pEnumPluggable));
		checkResult(pEnumPluggable->NextOne (&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject, (void **)&pDefObj));
		checkResult(pDefObj->GetPluginDefs (&pEnumDesc));
		checkResult(pEnumDesc->NextOne (&pPlugin));

	  
		checkResult(pPlugin->GetCategoryClass(&testUID));
		checkExpression(EqualAUID(&testUID, &category) == kAAFTrue, AAFRESULT_TEST_FAILED);

//	checkResult(pPlugin->GetPluginVersion(aafProductVersion_t *  pVersion));
		checkResult(pPlugin->GetPluginVersionString(testString, sizeof(testString)));
		checkExpression (wcscmp(testString, manufRev) == 0, AAFRESULT_TEST_FAILED);

//	checkResult(pPlugin->GetProductVersionStringLen(aafInt32 *  pLen));
		checkResult(pPlugin->GetPluginManufacturerName(testString, sizeof(testString)));
		checkExpression (wcscmp(testString, manufName) == 0, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetPluginManufacturerNameBufLen(&testUInt32));
//		checkExpression(testUInt32 == (aafInt32)wcslen(testString), AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetManufacturerInfo(&pNetLoc));
		checkResult(pNetLoc->QueryInterface (IID_IAAFLocator,
                                          (void **)&pLoc));
		checkResult(pLoc->GetPath (testString, sizeof(testString)));
		pNetLoc->Release();
		pNetLoc = NULL;
		pLoc->Release();
		pLoc = NULL;
		checkExpression (wcscmp(testString, manuf2URL) == 0, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetManufacturerID(&testUID));
		checkExpression(EqualAUID(&testUID, &manufacturer) == kAAFTrue, AAFRESULT_TEST_FAILED);

		/**/
		checkResult(pPlugin->GetHardwarePlatform(&testPlatform));
		checkExpression(EqualAUID(&testPlatform, &kAAFPlatformIndependant) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetPlatformVersionRange(&testMinVersion, &testMaxVersion));
		checkExpression(EqualVersion(&testMinVersion, &sampleMinPlatformVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkExpression(EqualVersion(&testMaxVersion, &sampleMaxPlatformVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);

		/**/
 		checkResult(pPlugin->GetEngine(&testEngine));
		checkExpression(EqualAUID(&testEngine, &kAAFNoEngine) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetEngineVersionRange(&testMinVersion, &testMaxVersion));
		checkExpression(EqualVersion(&testMinVersion, &sampleMinEngineVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkExpression(EqualVersion(&testMaxVersion, &sampleMaxEngineVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);

		/**/
		checkResult(pPlugin->GetPluginAPI(&testAPI));
		checkExpression(EqualAUID(&testAPI, &kAAFEssencePluginAPI) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetPluginAPIVersionRange(&testMinVersion, &testMaxVersion));
		checkExpression(EqualVersion(&testMinVersion, &sampleMinAPIVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkExpression(EqualVersion(&testMaxVersion, &sampleMaxAPIVersion) == kAAFTrue, AAFRESULT_TEST_FAILED);

		/**/
		checkResult(pPlugin->CountLocators(&count));
		checkExpression (count == 2, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->GetLocators(&pEnumLoc));

		checkResult(pEnumLoc->NextOne (&pLoc));
 		checkResult(pLoc->GetPath (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, manuf1URL) == 0, AAFRESULT_TEST_FAILED);

		pLoc->Release(); // this local variable was already has a reference that must be released!
		pLoc = NULL;
		checkResult(pEnumLoc->NextOne (&pLoc));
 		checkResult(pLoc->GetPath (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, manuf2URL) == 0, AAFRESULT_TEST_FAILED);
		
		checkResult(pPlugin->IsSoftwareOnly(&testBool));
 		checkExpression(testBool == kAAFTrue, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->IsAccelerated(&testBool));
 		checkExpression(testBool == kAAFFalse, AAFRESULT_TEST_FAILED);
		checkResult(pPlugin->SupportsAuthentication(&testBool));
		checkExpression(testBool == kAAFFalse, AAFRESULT_TEST_FAILED);
	}
	catch (HRESULT& rResult)
	{
		hr = rResult;
	}

	// Cleanup and return
	if (pEnumLoc)
		pEnumLoc->Release();

	if (pEnumPluggable)
		pEnumPluggable->Release();

	if (pLoc)
		pLoc->Release();

  if (pNetLoc)
		pNetLoc->Release();

	if (pPlugin)
		pPlugin->Release();

	if (pEnumDesc)
		pEnumDesc->Release();

	if (pCodecDef)
		pCodecDef->Release();
	if (pDefObj)
		pDefObj->Release();

	if (pDictionary)
		pDictionary->Release();

	if (pHeader)
		pHeader->Release();

	if (pFile)
	{  // Close file
		if (bFileOpen)
			pFile->Close();
		pFile->Release();
	}

	return hr;
}
 

extern "C" HRESULT CAAFPluginDescriptor_test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
	aafWChar * pFileName = L"AAFPluginDescriptorTest.aaf";

	try
	{
		hr = CreateAAFFile(pFileName);
		if (SUCCEEDED(hr))
			hr = ReadAAFFile(pFileName);
	}
	catch (...)
	{
		cerr << "CAAFPluginDescriptor_test...Caught general C++ exception!" << endl; 
	}

	return hr;
}
