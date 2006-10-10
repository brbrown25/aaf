//=---------------------------------------------------------------------=
//
// $Id: CAAFGetFileBitsTest.cpp,v 1.9 2006/10/10 17:52:32 akharkev Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include "AAF.h"
#include "AAFResult.h"
#include "AAFFileMode.h"
#include "AAFDefUIDs.h"
#include "AAFFileKinds.h"

#include "ModuleTest.h"
#include "CAAFBuiltinDefs.h"

#include <iostream>
using namespace std;
#include <stdio.h>
#include <assert.h>

#include "AAFSmartPointer.h"
typedef IAAFSmartPointer<IAAFRawStorage>  IAAFRawStorageSP;
typedef IAAFSmartPointer<IAAFFile>        IAAFFileSP;
typedef IAAFSmartPointer<IAAFRandomFile>  IAAFRandomFileSP;
typedef IAAFSmartPointer<IAAFGetFileBits> IAAFGetFileBitsSP;

// Required function prototype.
extern "C" HRESULT CAAFGetFileBits_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID);

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

static void fillJunk (aafMemPtr_t buf, size_t size)
{
  for (size_t i = 0; i < size; i++)
	{
	  buf[i] = 0xa5;
	}
}

static bool testJunk (aafMemPtr_t buf, size_t size)
{
  for (size_t i = 0; i < size; i++)
	{
	  if (buf[i] != 0xa5)
		return false;
	}
  return true;
}

static HRESULT GetFileBitsTest (
    aafUID_constref fileKind,
    aafProductIdentification_constref productID)
{
  // Create a memory raw storage and a file on it, to be opened for
  // writing.  We'll use this to get the GetFileBits to be tested.
  IAAFRawStorageSP pWriteStg;
  checkResult
	(AAFCreateRawStorageMemory (kAAFFileAccess_modify,
								&pWriteStg));
  IAAFFileSP pWriteFile;
  checkResult
	(AAFCreateAAFFileOnRawStorage (pWriteStg,
								   kAAFFileExistence_new,
								   kAAFFileAccess_modify,
								   &kAAFFileKind_Aaf4KBinary,
								   0,
								   &productID,
								   &pWriteFile));
  assert (pWriteFile);
  checkExpression (0 != (IAAFFile*)pWriteFile,
				   AAFRESULT_TEST_FAILED);
  
  IAAFRandomFileSP pWriteRandFile;
  checkResult(pWriteFile->QueryInterface(IID_IAAFRandomFile,
										 (void **)&pWriteRandFile));

  checkResult (pWriteFile->Open());
  checkResult (pWriteFile->Save());
  checkResult (pWriteFile->Close());

  //
  // Cool.  Now we can get the GetFileBits interface to test.
  //

  IAAFGetFileBitsSP pgfb;
  checkResult (pWriteRandFile->GetFileBits (&pgfb));

  //
  // test GetSize
  //
  HRESULT hr;

  // null param
  hr = pgfb->GetSize (0);
  checkExpression (AAFRESULT_NULL_PARAM == hr, AAFRESULT_TEST_FAILED);

  // Get the size
  aafUInt64 size = 0;
  checkResult (pgfb->GetSize (&size));
  // we know the file is not empty
  checkExpression (0 != size);

  //
  // test ReadAt
  //

  // null param
  hr = pgfb->ReadAt (0, 1, 0);
  checkExpression (AAFRESULT_NULL_PARAM == hr, AAFRESULT_TEST_FAILED);

  // Offset too large
  aafUInt8 foo[100];
  fillJunk (foo, sizeof (foo));
  checkExpression (testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);
  hr = pgfb->ReadAt (foo, sizeof (foo), size);
  checkExpression (AAFRESULT_OFFSET_SIZE == hr, AAFRESULT_TEST_FAILED);
  checkExpression (testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);

  // Size too large
  hr = pgfb->ReadAt (foo, 0x7fffffff, size);
  checkExpression (AAFRESULT_OFFSET_SIZE == hr, AAFRESULT_TEST_FAILED);
  checkExpression (testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);

  // Size/offset too large
  hr = pgfb->ReadAt (foo, sizeof (foo), size-(sizeof (foo)/2));
  checkExpression (AAFRESULT_OFFSET_SIZE == hr, AAFRESULT_TEST_FAILED);
  checkExpression (testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);

  // See if we can read at start
  checkResult (pgfb->ReadAt (foo, sizeof (foo), 0));
  checkExpression (!testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);

  // See if we can read at end
  fillJunk (foo, sizeof (foo));
  checkResult (pgfb->ReadAt (foo, sizeof (foo), size-sizeof(foo)));
  checkExpression (!testJunk (foo, sizeof (foo)), AAFRESULT_TEST_FAILED);

  return AAFRESULT_SUCCESS;
}

HRESULT CAAFGetFileBits_test(
    testMode_t /* mode */,
    aafUID_t fileKind,
    testRawStorageType_t /* rawStorageType */,
    aafProductIdentification_t productID)
{
  HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
  try
	{
	  hr = GetFileBitsTest (fileKind, productID);
	}
  catch (...)
	{
	  cerr << "CAAFGetFileBitsTest_test...Caught general C++"
		   << " exception!" << endl; 
	  hr = AAFRESULT_TEST_FAILED;
	}

  return hr;
}
