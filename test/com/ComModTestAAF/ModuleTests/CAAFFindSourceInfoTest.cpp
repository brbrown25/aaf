// @doc INTERNAL
// @com This file implements the module test for CAAFFindSourceInfo
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
#include <stdlib.h>
#include <wchar.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "AAFDataDefs.h"
#include "AAFDefUIDs.h"

#include "CAAFBuiltinDefs.h"

#include "AAFSmartPointer.h"
typedef IAAFSmartPointer<IAAFDataDef> IAAFDataDefSP;

#define	MobName			L"MasterMOBTest"
#define	NumMobSlots		3

static aafWChar *		slotNames[NumMobSlots] = { L"VIDEO SLOT", L"AUDIO SLOT1", L"AUDIO SLOT2"};
static const aafUID_t *	slotDDefs[NumMobSlots] = {&DDEF_Picture, &DDEF_Sound, &DDEF_Sound};
static aafRational_t	slotRates[NumMobSlots] = { {2997,100}, {44100, 1}, {48000, 1}};
static aafWChar* Manufacturer = L"Sony";
static aafWChar* Model = L"MyModel";
static aafTapeCaseType_t FormFactor = kAAFVHSVideoTape;
static aafVideoSignalType_t VideoSignalType = kAAFPALSignal;
static aafTapeFormatType_t TapeFormat = kAAFVHSFormat;
static aafUInt32 TapeLength = 3200 ;

//static aafMobID_t		NewMobID;
//--cf  This will require some work!!! 
static const 	aafMobID_t	TEST_Master_MobID =
{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
0x13, 0x00, 0x00, 0x00,
{0x8056f1f4, 0x03ff, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}};

static const 	aafMobID_t	TEST_Source_MobIDs[NumMobSlots] =
{	//start mobid block
	
	//first id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
		0x13, 0x00, 0x00, 0x00,
	{0x9f66346a, 0x03ff, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//second id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xbc0e582c, 0x03ff, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//third id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xcaab21c6, 0x03ff, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}}
	
};	//end mobid block


static const aafPosition_t	TAPE_MOB_OFFSET_ARR[NumMobSlots] = { 15, 25, 35 };
static const aafLength_t	TAPE_MOB_LENGTH_ARR[NumMobSlots] = { 90, 80, 70 };
static aafMobID_t			TAPE_MOB_ID = {0};

#define TAPE_MOB_NAME	L"A Tape Mob"

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
	
	aafProductVersion_t v;
	v.major = 1;
	v.minor = 0;
	v.tertiary = 0;
	v.patchLevel = 0;
	v.type = kAAFVersionUnknown;

	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFFindSourceInfo Test";
	ProductInfo.productVersion = &v;
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
	bool bFileOpen = false;
	IAAFHeader *        pHeader = NULL;
	IAAFDictionary*  pDictionary = NULL;
	IAAFMob*		pMob = NULL;
	IAAFMasterMob*	pMasterMob = NULL;
	IAAFSourceMob* pSrcMob = NULL;
	IAAFSourceMob* pTapeMob = NULL;
	IAAFEssenceDescriptor*	pDesc = NULL;
	IAAFMob*				pTempMob = NULL;
	HRESULT			hr = S_OK;
	long			test;
	aafSourceRef_t	ref;
	aafMobID_t		tapeMobID;
	IAAFEssenceDescriptor*		pEssDesc = NULL;
	IAAFTapeDescriptor*			pTapeDesc = NULL;
	
	
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
		
		// Create a Master Mob
		checkResult(defs.cdMasterMob()->
			CreateInstance(IID_IAAFMob, 
			(IUnknown **)&pMob));
		
		// Set the IAAFMob properties
		checkResult(pMob->SetMobID(TEST_Master_MobID));
		checkResult(pMob->SetName(MobName));
		
		checkResult(pMob->QueryInterface(IID_IAAFMasterMob, (void **) &pMasterMob));
		
		// Create source mob to associate with our MasterMob.
		checkResult(defs.cdSourceMob()->
			CreateInstance(IID_IAAFSourceMob, 
			(IUnknown **)&pTapeMob));		
		hr = defs.cdTapeDescriptor()->
			CreateInstance(IID_IAAFTapeDescriptor, 
			(IUnknown **)&pTapeDesc);		
		if (AAFRESULT_SUCCESS == hr)
		{
			hr = pTapeDesc->QueryInterface(IID_IAAFEssenceDescriptor, (void **)&pEssDesc);
			if (AAFRESULT_SUCCESS == hr)
			{
				hr = pTapeMob->SetEssenceDescriptor(pEssDesc);
				if (AAFRESULT_SUCCESS == hr)
				{
					hr = pTapeDesc->SetTapeManufacturer( Manufacturer );
					if (AAFRESULT_SUCCESS == hr )
					{
						hr = pTapeDesc->SetTapeModel( Model );
						if (AAFRESULT_SUCCESS == hr )
						{
							hr = pTapeDesc->SetTapeFormFactor( FormFactor );
							if (AAFRESULT_SUCCESS == hr )
							{
								hr = pTapeDesc->SetSignalType( VideoSignalType );
								if (AAFRESULT_SUCCESS == hr )
								{
									hr = pTapeDesc->SetTapeFormat( TapeFormat );
									if (AAFRESULT_SUCCESS == hr )
										hr = pTapeDesc->SetTapeLength( TapeLength );
								}
							}
						}
					}
				}
				pEssDesc->Release();
				pEssDesc = NULL;
			}
			pTapeDesc->Release();
			pTapeDesc = NULL;
		}
		for (test = 0; test < NumMobSlots; test++)
		{
			IAAFDataDefSP pDataDef;
			checkResult (pDictionary->LookupDataDef (*slotDDefs[test], &pDataDef));
			checkResult(pTapeMob->AddNilReference (test, TAPE_MOB_LENGTH_ARR[test], pDataDef, slotRates[test]));
		}
		checkResult(pTapeMob->QueryInterface(IID_IAAFMob, (void **) &pTempMob));
		checkResult(pTempMob->SetName(TAPE_MOB_NAME));
		checkResult(pTempMob->GetMobID(&tapeMobID));
		//save the id for future (test) reference
		TAPE_MOB_ID = tapeMobID;

		checkResult(pHeader->AddMob(pTempMob));
		pTempMob->Release();
		pTempMob = NULL;
		
		// Add some slots
		for (test = 0; test < NumMobSlots; test++)
		{
			// Create source mob to associate with our MasterMob.
			checkResult(defs.cdSourceMob()->
				CreateInstance(IID_IAAFSourceMob, 
				(IUnknown **)&pSrcMob));		
			
			ref.sourceID = tapeMobID;
			ref.sourceSlotID = test;
			ref.startTime = TAPE_MOB_OFFSET_ARR[test];
			IAAFDataDefSP pDDef;
			checkResult(pDictionary->LookupDataDef(*slotDDefs[test], &pDDef));
			checkResult(pSrcMob->AppendPhysSourceRef (slotRates[test],
				test,
				pDDef,
				ref,
				TAPE_MOB_LENGTH_ARR[test]));
			
			// Create a concrete subclass of EssenceDescriptor
			checkResult(defs.cdAIFCDescriptor()->
				CreateInstance(IID_IAAFEssenceDescriptor, 
				(IUnknown **)&pDesc));	

			IAAFAIFCDescriptor*			pAIFCDesc = NULL;
			checkResult(pDesc->QueryInterface (IID_IAAFAIFCDescriptor, (void **)&pAIFCDesc));
			checkResult(pAIFCDesc->SetSummary (5, (unsigned char*)"TEST"));
			pAIFCDesc->Release();
			pAIFCDesc = NULL;

			checkResult(pSrcMob->SetEssenceDescriptor(pDesc));
			pDesc->Release();
			pDesc = NULL;
			
			// Append source MOB to header
			checkResult(pSrcMob->QueryInterface(IID_IAAFMob, (void **) &pTempMob));
			checkResult(pTempMob->SetMobID(TEST_Source_MobIDs[test]));
			checkResult(pTempMob->SetName(L"source mob"));
			
			checkResult(pHeader->AddMob(pTempMob));
			pTempMob->Release();
			pTempMob = NULL;
			
			IAAFDataDefSP pDataDef;
			checkResult (pDictionary->LookupDataDef (*slotDDefs[test], &pDataDef));
			checkResult(pMasterMob->AddMasterSlot(pDataDef, test, pSrcMob, test+1, slotNames[test]));
			
			pSrcMob->Release();
			pSrcMob = NULL;
		}
		
		// Add the master mob to the file and cleanup
		checkResult(pHeader->AddMob(pMob));
	}
	catch (HRESULT& rResult)
	{
		hr = rResult;
	}
	
	
	// Cleanup and return
	if (pTempMob)
		pTempMob->Release();
	
	if (pEssDesc)
		pEssDesc->Release();
	
	if (pTapeDesc)
		pTapeDesc->Release();
	
	
	if (pDesc)
		pDesc->Release();
	
	if (pSrcMob)
		pSrcMob->Release();
	
	if (pTapeMob)
		pTapeMob->Release();
	
	if (pMasterMob)
		pMasterMob->Release();
	
	if (pMob)
		pMob->Release();
	
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
	bool bFileOpen = false;
	IAAFHeader*		pHeader = NULL;
	IEnumAAFMobs*	pMobIter = NULL;
	IAAFMob*		pMob = NULL;
	IAAFMasterMob*		pMasterMob = NULL;
	IEnumAAFMobSlots*	pSlotIter = NULL;
	IAAFMobSlot*		pSlot;
	aafNumSlots_t	numMobs;
	aafSearchCrit_t	criteria;
	IAAFSearchSource*  pSearchSource = NULL;
	IAAFFindSourceInfo*  pSourceInfo = NULL;
	IAAFMob* si_mob = NULL;  //mob used by SourceInfo intf.

	HRESULT			hr = S_OK;
	
	
	
	try
	{
		// Open the AAF file
		checkResult(OpenAAFFile(pFileName, kAAFMediaOpenReadOnly, &pFile, &pHeader));
		bFileOpen = true;
		
		// Validate that there is on one master mob in the test file.
		checkResult(pHeader->CountMobs(kAAFMasterMob, &numMobs));
		checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);
		
		// Enumerate over Master MOBs
		criteria.searchTag = kAAFByMobKind;
		criteria.tags.mobKind = kAAFMasterMob;
		checkResult(pHeader->GetMobs(&criteria, &pMobIter));
		while (pMobIter && pMobIter->NextOne(&pMob) == AAFRESULT_SUCCESS)
		{
			aafWChar			name[500];
			aafNumSlots_t		numSlots = 0;
			aafMobID_t				mobID;
			
			// TODO: Test Master MOB specific methods here
			checkResult(pMob->QueryInterface(IID_IAAFMasterMob, (void **) &pMasterMob));
			
			checkResult(pMob->GetName(name, sizeof(name)));
			checkExpression(wcscmp(name, MobName) == 0, AAFRESULT_TEST_FAILED);
			
			checkResult(pMob->GetMobID(&mobID));
			checkExpression(0 == memcmp(&mobID, &TEST_Master_MobID, sizeof(mobID)), AAFRESULT_TEST_FAILED);
			
			checkResult(pMob->CountSlots(&numSlots));
			checkExpression(NumMobSlots == numSlots, AAFRESULT_TEST_FAILED);
			
			//AAFRESULT STDMETHODCALLTYPE
			//   ImplAAFMasterMob::GetTapeNameBufLen (0,
			//										 aafInt32*  pLen)
			unsigned long	s = 0;
			
			// Enumerate over all MOB slots for this MOB
			checkResult(pMob->GetSlots(&pSlotIter));
			while (pSlotIter && pSlotIter->NextOne(&pSlot) == AAFRESULT_SUCCESS)
			{
				aafWChar			slotName[500];
				aafSlotID_t			slotID;
				//aafUInt32			bufSize = 0;
				
				// Validate the slot name
				checkResult(pSlot->GetName(slotName, sizeof(slotName)));
				checkExpression(wcscmp(slotName, slotNames[s]) == 0, AAFRESULT_TEST_FAILED);
				
				// Validate the slot id.
				checkResult(pSlot->GetSlotID(&slotID));
				checkExpression(slotID == s+1, AAFRESULT_TEST_FAILED);

				//Now, do a search source  ...............

				//Get a search source intf.
				checkResult( pMasterMob->QueryInterface(IID_IAAFSearchSource, (void**)&pSearchSource) );

				//From the searchsource inft, get a FindSourceINfo intf.
				checkResult ( pSearchSource->SearchSource(
					slotID,
					0,
					kAAFTapeMob,
					NULL, //don't care about Media Criteria
					NULL, //don't care about operation choice
					&pSourceInfo));

				//This is an important milestone! At this point, we were successful - about getting a pSourceInfo intf.
				//  so, release the search source intf.
				if (pSearchSource)
				{
					pSearchSource->Release();
					pSearchSource=NULL;
				}

				//NOw, simply test the methods on the (final) SourceInfo intf.
				aafRational_t si_editRate = {-1};
				aafLength_t  si_length = {-1};
				aafSourceRef_t  si_sourceRef = {-1};
				aafMobID_t  si_MobID = {-1};

				//Call the methods
				pSourceInfo->GetEditRate( &si_editRate);
				pSourceInfo->GetLength(&si_length);
				pSourceInfo->GetMob(&si_mob);
				pSourceInfo->GetSourceReference(&si_sourceRef);

				//Check the values returned by the methods
				//edit rate
				checkExpression(si_editRate.numerator == slotRates[s].numerator, AAFRESULT_TEST_FAILED);
				checkExpression(si_editRate.denominator == slotRates[s].denominator, AAFRESULT_TEST_FAILED);
				//Length
				checkExpression(si_length == TAPE_MOB_LENGTH_ARR[s], AAFRESULT_TEST_FAILED);
				//Mob
				checkExpression(si_mob!=NULL, AAFRESULT_TEST_FAILED); 
				si_mob->GetMobID(&si_MobID);
				checkExpression(memcmp(&si_MobID, &TAPE_MOB_ID, sizeof(aafMobID_t))==0,
										AAFRESULT_TEST_FAILED);
				//Source Reference
				checkExpression(si_sourceRef.sourceSlotID == s,					AAFRESULT_TEST_FAILED);
				checkExpression(si_sourceRef.startTime == TAPE_MOB_OFFSET_ARR[s], AAFRESULT_TEST_FAILED);


				//Done with tests .. release the FindSourceInfo intf .. 
				if (pSourceInfo)
				{
					pSourceInfo->Release();
					pSourceInfo=NULL;
				}

				//Also don't forget to release the si_mob intf.
				if (si_mob)
				{
					si_mob->Release();
					si_mob=NULL;
				}


				
				pSlot->Release();
				pSlot = NULL;
				s++;
			}
			
			pSlotIter->Release();
			pSlotIter = NULL;
			pMob->Release();
			pMob = NULL;
			pMasterMob->Release();
			pMasterMob = NULL;
		}
		
	}
	catch (HRESULT& rResult)
	{
		hr = rResult;
	}
	
	
	// Cleanup and return

	if (pSearchSource)
		pSearchSource->Release();
	
	if (pSourceInfo)
		pSourceInfo->Release();
	
	if (si_mob)
		si_mob->Release();
				
	
	if (pSlot)
		pSlot->Release();
	
	if (pMasterMob)
		pMasterMob->Release();
	
	if (pMob)
		pMob->Release();
	
	if (pMobIter)
		pMobIter->Release();
	
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


extern "C" HRESULT CAAFFindSourceInfo_test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
	aafWChar * pFileName = L"AAFFindSourceInfoTest.aaf";
	
	try
	{
		hr = CreateAAFFile(pFileName);
		if (SUCCEEDED(hr))
			hr = ReadAAFFile(pFileName);
	}
	catch (...)
	{
	  cerr << "CAAFFindSourceInfo_test..."
		   << "Caught general C++ exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}
	
	if (SUCCEEDED(hr))
	{
		hr = AAFRESULT_SUCCESS;
	}
	
	return hr;
}




