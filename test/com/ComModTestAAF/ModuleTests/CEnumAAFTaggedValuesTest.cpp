// @doc INTERNAL
// @com This file implements the module test for CEnumAAFTaggedValues
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
 *  prior written permission of Avid Technology, Inc.
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

static aafWChar *slotNames[5] = { L"SLOT1", L"SLOT2", L"SLOT3", L"SLOT4", L"SLOT5" };
static aafWChar* TagNames[3] = { L"TAG01", L"TAG02", L"TAG03" };
static aafWChar* Comments[3] = { L"Comment 1", L"Comment 2", L"Comment 3"};	


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
  IAAFHeader *        pHeader = NULL;
  IAAFDictionary*  pDictionary = NULL;
	IAAFMob						*pMob = NULL;
	IAAFMobSlot		*newSlot = NULL;
	IAAFSegment		*seg = NULL;
	IAAFSourceClip	*sclp = NULL;
	aafProductIdentification_t	ProductInfo;
	aafUID_t					newUID;
	HRESULT						hr = S_OK;

	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"EnumAAFTaggedValues Test";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kVersionUnknown;
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
 		
  //Make the first mob
	  long	test;
	  aafRational_t	audioRate = { 44100, 1 };

	  // Create a Mob
	  checkResult(pDictionary->CreateInstance(&AUID_AAFMob,
							  IID_IAAFMob, 
							  (IUnknown **)&pMob));

		checkResult(CoCreateGuid((GUID *)&newUID));
	  checkResult(pMob->SetMobID(&newUID));
	  checkResult(pMob->SetName(L"EnumAAFTaggedValuesTest"));
		// append some comments to this mob !!
	  for (test = 0; test < 3; test++)
	  {
		  checkResult(pMob->AppendComment(TagNames[test], Comments[test]));
	  }
	  // Add some slots
	  for(test = 0; test < 5; test++)
	  {
 		  checkResult(pDictionary->CreateInstance(&AUID_AAFSourceClip,
							     IID_IAAFSourceClip, 
							     (IUnknown **)&sclp));		

		  checkResult(sclp->QueryInterface (IID_IAAFSegment, (void **)&seg));

		  checkResult(pMob->AppendNewSlot (seg, test+1, slotNames[test], &newSlot));

		  newSlot->Release();
      newSlot = NULL;

		  seg->Release();
      seg = NULL;

      sclp->Release();
      sclp = NULL;
	  }

    // Add the mob to the file.
	  checkResult(pHeader->AppendMob(pMob));
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

static HRESULT ReadAAFFile(aafWChar * pFileName)
{
	IAAFFile *					pFile = NULL;
  bool bFileOpen = false;
	IAAFHeader *				pHeader = NULL;
	IEnumAAFMobs *mobIter = NULL;
	IAAFMob			*aMob = NULL;
	IEnumAAFMobSlots	*slotIter = NULL;
	IEnumAAFTaggedValues* pCommentIterator = NULL;
	IEnumAAFTaggedValues* pCloneIterator = NULL;
	IAAFTaggedValue*		pComment = NULL;

	IAAFMobSlot		*slot = NULL;
	aafProductIdentification_t	ProductInfo;
	aafNumSlots_t	numMobs, n, slt;
	aafUInt32		numComments, bytesRead, com;
	HRESULT						hr = S_OK;
	aafWChar		tag[64];
	aafWChar		Value[64];

	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"EnumAAFTaggedValues Test";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.platform = NULL;

  try
  {
    // Open the file
		checkResult(AAFFileOpenExistingRead(pFileName, 0, &pFile));
		bFileOpen = true;

    // We can't really do anthing in AAF without the header.
  	checkResult(pFile->GetHeader(&pHeader));


	  checkResult(pHeader->GetNumMobs(kAllMob, &numMobs));
	  checkExpression(1 == numMobs, AAFRESULT_TEST_FAILED);


	  aafSearchCrit_t		criteria;
	  criteria.searchTag = kNoSearch;
    checkResult(pHeader->EnumAAFAllMobs (&criteria, &mobIter));

    for(n = 0; n < numMobs; n++)
	  {
		  aafWChar		name[500], slotName[500];
		  aafNumSlots_t	numSlots;
		  aafUID_t		mobID;
		  aafSlotID_t		trackID;

		  checkResult(mobIter->NextOne (&aMob));
		  checkResult(aMob->GetName (name, sizeof(name)));
		  checkResult(aMob->GetMobID (&mobID));

		  // Check for comments
		  checkResult(aMob->GetNumComments(&numComments));
		  checkExpression(3 == numComments, AAFRESULT_TEST_FAILED);
		  checkResult(aMob->EnumAAFAllMobComments(&pCommentIterator));
		  for(com = 0; com < numComments; com++)
		  {
			  checkResult(pCommentIterator->NextOne(&pComment));
			  checkResult(pComment->GetName(tag, sizeof(tag)));
			  checkResult(pComment->GetValue( sizeof(Value), (unsigned char *)Value, &bytesRead));
			  checkExpression(wcscmp(tag, TagNames[com])== 0, AAFRESULT_TEST_FAILED);
			  checkExpression(wcscmp(Value, Comments[com])== 0, AAFRESULT_TEST_FAILED);
			  pComment->Release();
		  }
		  // now check reset
		  checkResult(pCommentIterator->Reset());
		  checkResult(pCommentIterator->NextOne(&pComment));
		  checkResult(pComment->GetName(tag, sizeof(tag)));
		  checkResult(pComment->GetValue( sizeof(Value), (unsigned char *)Value, &bytesRead));
		  checkExpression(wcscmp(tag, TagNames[0])== 0, AAFRESULT_TEST_FAILED);
		  checkExpression(wcscmp(Value, Comments[0])== 0, AAFRESULT_TEST_FAILED);
		  pComment->Release();
		  // test skip
		  checkResult(pCommentIterator->Skip(1));
		  checkResult(pCommentIterator->NextOne(&pComment));
		  checkResult(pComment->GetName(tag, sizeof(tag)));
		  checkResult(pComment->GetValue( sizeof(Value), (unsigned char *)Value, &bytesRead));
		  checkExpression(wcscmp(tag, TagNames[2])== 0, AAFRESULT_TEST_FAILED);
		  checkExpression(wcscmp(Value, Comments[2])== 0, AAFRESULT_TEST_FAILED);
		  pComment->Release();
		  // test clone
		  checkResult(pCommentIterator->Clone(&pCloneIterator));
		  checkResult(pCloneIterator->Reset());
		  checkResult(pCloneIterator->NextOne(&pComment));
		  checkResult(pComment->GetName(tag, sizeof(tag)));
		  checkResult(pComment->GetValue( sizeof(Value), (unsigned char *)Value, &bytesRead));
		  checkExpression(wcscmp(tag, TagNames[0])== 0, AAFRESULT_TEST_FAILED);
		  checkExpression(wcscmp(Value, Comments[0])== 0, AAFRESULT_TEST_FAILED);
		  pComment->Release();
		  
		
		  pCommentIterator->Release();
		  pCloneIterator->Release();
			
		  checkResult(aMob->GetNumSlots (&numSlots));
		  checkExpression(5 == numSlots, AAFRESULT_TEST_FAILED);

			checkResult(aMob->EnumAAFAllMobSlots(&slotIter));

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
 
	    
extern "C" HRESULT CEnumAAFTaggedValues_test()
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
 	aafWChar * pFileName = L"EnumAAFTaggedValuesTest.aaf";

	try
	{
		hr = CreateAAFFile(	pFileName );
		if(hr == AAFRESULT_SUCCESS)
			hr = ReadAAFFile( pFileName );
	}
	catch (...)
	{
	  cerr << "CEnumAAFTaggedValues_test...Caught general C++"
		" exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

  // Cleanup our object if it exists.

  	// When all of the functionality of this class is tested, we can return success

  return hr;
}






























































////////////////////////////////////////////////////////////////////////////////
