// @doc INTERNAL
// @com This file implements the module test for CEnumAAFEssenceData
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
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "AAFDefUIDs.h"

#include "CAAFBuiltinDefs.h"


// Utility class to implement the test.
struct EnumEssenceDataTest
{
  EnumEssenceDataTest();
  ~EnumEssenceDataTest();

  void createFile(wchar_t *pFileName);
  void openFile(wchar_t *pFileName);

  void createFileMob(int itemNumber);
  void createEssenceData(IAAFSourceMob *pSourceMob);
  void openEssenceData();


  void cleanupReferences();
  void check(HRESULT hr);
  void removeTestFile(const wchar_t* pFileName);

  // Shared member data:
  HRESULT _hr;
  aafProductVersion_t _productVersion;
  aafProductIdentification_t _productInfo;
  IAAFFile *_pFile;
  bool _bFileOpen;
  IAAFHeader *_pHeader;
  IAAFDictionary *_pDictionary;
  IAAFMob *_pMob;
  IAAFSourceMob *_pSourceMob;
  IAAFEssenceDescriptor *_pEssenceDescriptor;
  IAAFFileDescriptor *_pFileDescriptor;
  IEnumAAFEssenceData *_pEnumEssenceData;
  IAAFEssenceData *_pEssenceData;

  static const aafUInt32 _maxMobCount;
};

extern "C" HRESULT CEnumAAFEssenceData_test()
{
  HRESULT hr = AAFRESULT_SUCCESS;
  wchar_t fileName[] = L"EnumAAFEssenceDataTest.aaf";
  EnumEssenceDataTest edt;

  try
  {
    edt.createFile(fileName);
    edt.openFile(fileName);
  }
  catch (HRESULT& ehr)
  {
    // thrown by EnumEssenceDataTest_check() method.
    hr = ehr;
  }
  catch (...)
  {
    cerr << "CAAFEssenceData_test...Caught general C++"
		 << " exception!" << endl; 
	hr = AAFRESULT_TEST_FAILED;
  }

  // Cleanup our object if it exists.

  return hr;
}


const aafUInt32 EnumEssenceDataTest::_maxMobCount = 5;

static const 	aafMobID_t	TEST_MobIDs[EnumEssenceDataTest::_maxMobCount] =
{//start mobid block
	//first id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
		0x13, 0x00, 0x00, 0x00,
	{0xb1b11414, 0x040e, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//second id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xc1a2cdf4, 0x040e, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//third id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xc8681b8a, 0x040e, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//fourth id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xceaf0c7e, 0x040e, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}},
	
	//fifth id
	{{0x06, 0x0c, 0x2b, 0x34, 0x02, 0x05, 0x11, 0x01, 0x01, 0x00, 0x10, 0x00},
	0x13, 0x00, 0x00, 0x00,
	{0xd755f518, 0x040e, 0x11d4, 0x8e, 0x3d, 0x00, 0x90, 0x27, 0xdf, 0xca, 0x7c}}
	
}; //end mobid block


EnumEssenceDataTest::EnumEssenceDataTest():
  _hr(AAFRESULT_SUCCESS),
  _pFile(NULL),
  _bFileOpen(false),
  _pHeader(NULL),
  _pDictionary(NULL),
  _pMob(NULL),
  _pSourceMob(NULL),
  _pEssenceDescriptor(NULL),
  _pFileDescriptor(NULL),
  _pEnumEssenceData(NULL),
  _pEssenceData(NULL)
{
  _productVersion.major = 1;
  _productVersion.minor = 0;
  _productVersion.tertiary = 0;
  _productVersion.patchLevel = 0;
  _productVersion.type = kAAFVersionUnknown;
  _productInfo.companyName = L"AAF Developers Desk";
  _productInfo.productName = L"EnumAAFEssenceData Module Test";
  _productInfo.productVersion = &_productVersion;
  _productInfo.productVersionString = NULL;
  _productInfo.productID = UnitTestProductID;
  _productInfo.platform = NULL;
}

EnumEssenceDataTest::~EnumEssenceDataTest()
{
  cleanupReferences();
}

void EnumEssenceDataTest::cleanupReferences()
{
  if (NULL != _pEssenceData)
  {
    _pEssenceData->Release();
    _pEssenceData = NULL;
  }

  if (NULL != _pEnumEssenceData)
  {
    _pEnumEssenceData->Release();
    _pEnumEssenceData = NULL;
  }

  if (NULL != _pFileDescriptor)
  {
    _pFileDescriptor->Release();
    _pFileDescriptor = NULL;
  }

  if (NULL != _pEssenceDescriptor)
  {
    _pEssenceDescriptor->Release();
    _pEssenceDescriptor = NULL;
  }

  if (NULL != _pSourceMob)
  {
    _pSourceMob->Release();
    _pSourceMob = NULL;
  }

  if (NULL != _pMob)
  {
    _pMob->Release();
    _pMob = NULL;
  }

  
  if (NULL != _pDictionary)
  {
    _pDictionary->Release();
    _pDictionary = NULL;
  }

  if (NULL != _pHeader)
  {
    _pHeader->Release();
    _pHeader = NULL;
  }

  if (NULL != _pFile)
  {
    if (_bFileOpen)
      _pFile->Close();
    _pFile->Release();
    _pFile = NULL;
  }
}

inline void EnumEssenceDataTest::check(HRESULT hr)
{
  if (AAFRESULT_SUCCESS != (_hr = hr))
    throw hr;
}

// Cross-platform utility to delete a file.
void EnumEssenceDataTest::removeTestFile(const wchar_t* pFileName)
{
  const size_t kMaxFileName = 512;
  char cFileName[kMaxFileName];

  size_t status = wcstombs(cFileName, pFileName, kMaxFileName);
  if (status != (size_t)-1)
  { // delete the file.
    remove(cFileName);
  }
}

void EnumEssenceDataTest::createFile(wchar_t *pFileName)
{
  // Remove the previous test file if any.
  removeTestFile(pFileName);


  check(AAFFileOpenNewModify(pFileName, 0, &_productInfo, &_pFile));
  _bFileOpen = true;
  check(_pFile->GetHeader(&_pHeader));
  check(_pHeader->GetDictionary(&_pDictionary));

  for (aafUInt32 item = 0; item < _maxMobCount; ++item)
    createFileMob(item);
 
  check(_pFile->Save());

  cleanupReferences();
}

void EnumEssenceDataTest::openFile(wchar_t *pFileName)
{
  check(AAFFileOpenExistingRead(pFileName, 0, &_pFile));
  _bFileOpen = true;
  check(_pFile->GetHeader(&_pHeader));

  openEssenceData();

  cleanupReferences();
}

void EnumEssenceDataTest::createFileMob(int itemNumber)
{
  assert(_pFile && _pHeader && _pDictionary);
  assert(NULL == _pSourceMob);
  assert(NULL == _pMob);
  assert(NULL == _pFileDescriptor);
  assert(NULL == _pEssenceDescriptor);
  assert(NULL == _pSourceMob);

  // Format the mob name.
  wchar_t wcBuffer[512];
  char cBuffer[256];
  sprintf(cBuffer, "EnumEssenceDataTest File Mob %d", itemNumber);
  size_t count = mbstowcs(wcBuffer, cBuffer, strlen(cBuffer) + 1);
  if (-1 == count)
    check(AAFRESULT_INTERNAL_ERROR);


  CAAFBuiltinDefs defs (_pDictionary);
  // Create a Mob
  check(defs.cdSourceMob()->
		CreateInstance(IID_IAAFSourceMob, 
					   (IUnknown **)&_pSourceMob));

  check(_pSourceMob->QueryInterface (IID_IAAFMob, (void **)&_pMob));
  
  check(_pMob->SetMobID(TEST_MobIDs[itemNumber]));
  check(_pMob->SetName(wcBuffer));
  
  // Create a concrete subclass of FileDescriptor
  check(defs.cdAIFCDescriptor()->
		CreateInstance(IID_IAAFFileDescriptor, 
					   (IUnknown **)&_pFileDescriptor));


	IAAFAIFCDescriptor*			pAIFCDesc = NULL;
	check(_pFileDescriptor->QueryInterface (IID_IAAFAIFCDescriptor, (void **)&pAIFCDesc));
	check(pAIFCDesc->SetSummary (5, (unsigned char*)"TEST"));
	pAIFCDesc->Release();
	pAIFCDesc = NULL;

  check(_pFileDescriptor->QueryInterface (IID_IAAFEssenceDescriptor,
                                          (void **)&_pEssenceDescriptor));
  check(_pSourceMob->SetEssenceDescriptor (_pEssenceDescriptor));

  check(_pHeader->AddMob(_pMob));

  createEssenceData(_pSourceMob);

  // Cleanup instance data for reuse...
  _pEssenceDescriptor->Release();
  _pEssenceDescriptor = NULL;

  _pFileDescriptor->Release();
  _pFileDescriptor = NULL;

  _pMob->Release();
  _pMob = NULL;

  _pSourceMob->Release();
  _pSourceMob = NULL;
}

void EnumEssenceDataTest::createEssenceData(IAAFSourceMob *pSourceMob)
{
  assert(_pFile && _pHeader && _pDictionary);
  assert(pSourceMob);
  assert(NULL == _pEssenceData);

  CAAFBuiltinDefs defs (_pDictionary);

  // Attempt to create an AAFEssenceData.
  check(defs.cdEssenceData()->
		CreateInstance(IID_IAAFEssenceData,
					   (IUnknown **)&_pEssenceData));

  check(_pEssenceData->SetFileMob(pSourceMob));
  check(_pHeader->AddEssenceData(_pEssenceData));
  
  _pEssenceData->Release();
  _pEssenceData = NULL;
}

void EnumEssenceDataTest::openEssenceData()
{
  assert(_pFile && _pHeader);
  assert(NULL == _pEnumEssenceData);
  assert(NULL == _pEssenceData);
  assert(NULL == _pSourceMob);

  aafUInt32 essenceDataCount = 0;
  check(_pHeader->CountEssenceData(&essenceDataCount));
  if (_maxMobCount != essenceDataCount)
    check(AAFRESULT_TEST_FAILED);
 
  check(_pHeader->EnumEssenceData(&_pEnumEssenceData));
  for (aafUInt32 item = 0; item < essenceDataCount; ++item)
  {
    check(_pEnumEssenceData->NextOne(&_pEssenceData));

    // Make sure that the essence data still references
    // a valid mob.
    check(_pEssenceData->GetFileMob(&_pSourceMob));

    _pSourceMob->Release();
    _pSourceMob = NULL;

    _pEssenceData->Release();
    _pEssenceData = NULL;
  }


  _pEnumEssenceData->Release();
  _pEnumEssenceData = NULL;
}
