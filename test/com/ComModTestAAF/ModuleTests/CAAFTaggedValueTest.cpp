// @doc INTERNAL
// @com This file implements the module test for CAAFTaggedValue
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

static aafWChar *slotNames[5] = { L"SLOT1", L"SLOT2", L"SLOT3", L"SLOT4", L"SLOT5" };
static const aafUID_t *	slotDDefs[5] = {&DDEF_Picture, &DDEF_Sound, &DDEF_Sound, &DDEF_Picture, &DDEF_Picture};
static aafLength_t	slotsLength[5] = { 297, 44100, 44100, 44100, 44100};

static aafSourceRef_t sourceRef; 
static aafWChar* TagNames =  L"TAG01";
static aafWChar* Comments =  L"Comment 1";	
static aafWChar* AltComment = L"Alternate Comment";

static const 	aafMobID_t	TEST_MobID =
{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
0x13, 0x00, 0x00, 0x00,
{0xebf452a8, 0x0404, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}};

static const 	aafMobID_t	TEST_referencedMobID =
{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
0x13, 0x00, 0x00, 0x00,
{0x25ede122, 0x0405, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}};


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
	IAAFFile *			pFile = NULL;
	bool				bFileOpen = false;
	IAAFHeader *        pHeader = NULL;
	IAAFDictionary*		pDictionary = NULL;
	IAAFMob				*pMob = NULL;
	IAAFMob*			pRMob = NULL;
	IAAFMasterMob*		pReferencedMob = NULL;
	IAAFCompositionMob* pCompMob = NULL;
	IAAFTimelineMobSlot	*newSlot = NULL;
	IAAFSegment			*seg = NULL;
	IAAFSourceClip		*sclp = NULL;
	aafProductIdentification_t	ProductInfo;
	HRESULT				hr = S_OK;

	aafProductVersion_t v;
	v.major = 1;
	v.minor = 0;
	v.tertiary = 0;
	v.patchLevel = 0;
	v.type = kAAFVersionUnknown;
	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"AAFTaggedValue Test";
	ProductInfo.productVersion = &v;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = UnitTestProductID;
	ProductInfo.platform = NULL;

	try
	{
		// Remove the previous test file if any.
		RemoveTestFile(pFileName);

		// Create the file.
		checkResult(AAFFileOpenNewModify(pFileName, 0, &ProductInfo, &pFile));
		bFileOpen = true;
 
		// We can't really do anthing in AAF without the header.
		checkResult(pFile->GetHeader(&pHeader));

		// Get the AAF Dictionary so that we can create valid AAF objects.
		checkResult(pHeader->GetDictionary(&pDictionary));
		CAAFBuiltinDefs defs (pDictionary);
 		
		//Make the first mob
		long	test;

		// Create a  Composition Mob
		checkResult(defs.cdCompositionMob()->
					CreateInstance(IID_IAAFCompositionMob, 
								   (IUnknown **)&pCompMob));

		checkResult(pCompMob->QueryInterface(IID_IAAFMob, (void **)&pMob));
		checkResult(pMob->SetMobID(TEST_MobID));
		checkResult(pMob->SetName(L"AAFTaggedValuesTest"));

		// append a comment to this mob !!
		checkResult(pMob->AppendComment(TagNames, Comments));
	  
		checkResult(pMob->AppendComment(TagNames, AltComment));

		// Create a master mob to be referenced
		checkResult(defs.cdMasterMob()->
					CreateInstance(IID_IAAFMasterMob, 
								   (IUnknown **)&pReferencedMob));

		checkResult(pReferencedMob->QueryInterface(IID_IAAFMob, (void **)&pRMob));
		checkResult(pRMob->SetMobID(TEST_referencedMobID));
		checkResult(pRMob->SetName(L"AAFTaggedValueTest::ReferencedMob"));

		// Add some slots
		for(test = 0; test < 5; test++)
		{
 			checkResult(defs.cdSourceClip()->
						CreateInstance(IID_IAAFSourceClip, 
									   (IUnknown **)&sclp));		
			// Set the properties for the SourceClip
			sourceRef.sourceID = TEST_referencedMobID;
			sourceRef.sourceSlotID = 0;
			sourceRef.startTime = 0;
			IAAFDataDefSP pDataDef;
			checkResult(pDictionary->LookupDataDef(*slotDDefs[test], &pDataDef));
			checkResult(sclp->Initialize(pDataDef, slotsLength[test], sourceRef));

			checkResult(sclp->QueryInterface (IID_IAAFSegment, (void **)&seg));
			
			aafRational_t editRate = { 0, 1};
			checkResult(pMob->AppendNewTimelineSlot (editRate,
													 seg,
													 test+1,
													 slotNames[test],
													 0,
													 &newSlot));

			newSlot->Release();
			newSlot = NULL;

			seg->Release();
			seg = NULL;

			sclp->Release();
			sclp = NULL;
		}

		// Add the mob to the file.
		checkResult(pHeader->AddMob(pMob));
		checkResult(pHeader->AddMob(pRMob));
	}
	catch (HRESULT& rResult)
	{
		hr = rResult;
	}


  // Cleanup and return
  if (newSlot)
    newSlot->Release();

  if (seg)
    seg->Release();

  if (sclp)
    sclp->Release();

  if (pCompMob)
	  pCompMob->Release();

  if (pMob)
    pMob->Release();

  if (pReferencedMob)
	  pReferencedMob->Release();

  if (pRMob)
	  pRMob->Release();

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

static HRESULT ReadAAFFile(aafWChar * pFileName)
{
	IAAFFile *					pFile = NULL;
	bool bFileOpen = false;
	IAAFHeader *				pHeader = NULL;
	IEnumAAFMobs *mobIter = NULL;
	IAAFMob			*aMob = NULL;
	IEnumAAFMobSlots	*slotIter = NULL;
	IEnumAAFTaggedValues* pCommentIterator = NULL;
	IAAFTaggedValue*		pComment = NULL;

	IAAFMobSlot		*slot = NULL;
	aafNumSlots_t	numMobs, n, slt;
	aafUInt32		numComments, bytesRead, com;
	HRESULT						hr = S_OK;
	aafWChar		tag[64];
	aafWChar		Value[64];
	aafSearchCrit_t	criteria;

	try
	{
		// Open the file
		checkResult(AAFFileOpenExistingRead(pFileName, 0, &pFile));
		bFileOpen = true;

		// We can't really do anthing in AAF without the header.
  		checkResult(pFile->GetHeader(&pHeader));

		criteria.searchTag = kAAFByMobKind;
		criteria.tags.mobKind = kAAFCompMob;


		checkResult(pHeader->CountMobs(kAAFCompMob, &numMobs));
		checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);


		checkResult(pHeader->GetMobs (&criteria, &mobIter));

		for(n = 0; n < numMobs; n++)
		{
			aafWChar		name[500], slotName[500];
			aafNumSlots_t	numSlots;
			aafMobID_t		mobID;
			aafSlotID_t		trackID;

			checkResult(mobIter->NextOne (&aMob));
			checkResult(aMob->GetName (name, sizeof(name)));
			checkResult(aMob->GetMobID (&mobID));

			// Check for comments
			checkResult(aMob->CountComments(&numComments));
			checkExpression(1 == numComments, AAFRESULT_TEST_FAILED);
			checkResult(aMob->GetComments(&pCommentIterator));
			for(com = 0; com < numComments; com++)
			{
				checkResult(pCommentIterator->NextOne(&pComment));
				checkResult(pComment->GetName(tag, sizeof(tag)));
				checkResult(pComment->GetValue( sizeof(Value), (unsigned char *)Value, &bytesRead));
				checkExpression(wcscmp(tag, TagNames)== 0, AAFRESULT_TEST_FAILED);
				checkExpression(wcscmp(Value, AltComment)== 0, AAFRESULT_TEST_FAILED);
				pComment->Release();
			}
			pCommentIterator->Release();
			
			checkResult(aMob->CountSlots (&numSlots));
			checkExpression(5 == numSlots, AAFRESULT_TEST_FAILED);

			checkResult(aMob->GetSlots(&slotIter));

			for(slt = 0; slt < numSlots; slt++)
			{
				checkResult(slotIter->NextOne (&slot));
				checkResult(slot->GetName (slotName, sizeof(slotName)));
				checkResult(slot->GetSlotID(&trackID));
				checkExpression (wcscmp(slotName, slotNames[slt]) == 0, AAFRESULT_TEST_FAILED);

				slot->Release();
				slot = NULL;
			}

			aMob->Release();
			aMob = NULL;
		}
	}
	catch (HRESULT& rResult)
	{
    hr = rResult;
	}

	// Cleanup object references
  if (slot)
    slot->Release();

  if (slotIter)
    slotIter->Release();

  if (aMob)
    aMob->Release();

  if (mobIter)
    mobIter->Release();

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
 

extern "C" HRESULT CAAFTaggedValue_test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
 	aafWChar * pFileName = L"AAFTaggedValueTest.aaf";

	try
	{
		hr = CreateAAFFile(	pFileName );
		if(hr == AAFRESULT_SUCCESS)
			hr = ReadAAFFile( pFileName );
	}
	catch (...)
	{
	  cerr << "CTaggedValues_test...Caught general C++"
		   << " exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

  return hr;
}










  // 
  // Succeeds if all of the following are true:
  // - the ppTypeDef pointer is valid.
  // 
  // If this method fails nothing will be written to *ppTypeDef.
  // 
  // This method will return the following codes.  If more than one of
  // the listed errors is in effect\, it will return the first one
  // encountered in the order given below:
  //
  // AAFRESULT_SUCCESS
  //   - succeeded.  \(This is the only code indicating success.\)
  //
  // AAFRESULT_NOT_INITIALIZED
  //   - This object has not yet had Initialize\(\) called on it.
  //
  // AAFRESULT_PROP_NOT_PRESENT
  //   - This property does not exist in the file.
  //
  // AAFRESULT_NULL_PARAM
  //   - ppTypeDef arg is NULL.)






/****/




