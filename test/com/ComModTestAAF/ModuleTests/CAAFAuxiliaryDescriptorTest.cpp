// @doc INTERNAL
// @com This file implements the module test for CAAFAuxiliaryDescriptor
//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: CAAFAuxiliaryDescriptorTest.cpp,v 1.1.2.2 2004/05/11 02:12:58 jptrainor Exp $ $Name:  $
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

#include "ModuleTestsCommon.h"

#include <ModuleTest.h>

#include <AAF.h>
#include <AAFResult.h>
#include <AAFTypes.h>
#include <AAFStoredObjectIDs.h>

#include <wchar.h>
#include <iostream>
using namespace std;

static HRESULT CreateAAFFile(aafWChar * pFileName)
{
  try {
    using namespace mtc;

    IAAFSmartPointer<IAAFHeader> pHeader;
    IAAFSmartPointer<IAAFDictionary> pDict;
    SimpleFilePointers filePointers;
    CreateSimpleAAFFile( pFileName, 
			 L"AuxiliaryDesciptor Test",
			 &filePointers );

    IAAFSmartPointer<IAAFSourceMob> spSourceMob = AddChainedSourceMob( &filePointers );

    // Finally... add the aux descriptor.
    IAAFSmartPointer<IAAFAuxiliaryDescriptor> pAuxDesc;
    CheckResult( filePointers.pDictionary->CreateInstance( AUID_AAFAuxiliaryDescriptor,
							   IID_IAAFAuxiliaryDescriptor,
							   (IUnknown**)&pAuxDesc ) );
    
    CheckResult( pAuxDesc->Initialize() );
    CheckResult( pAuxDesc->SetMimeType( L"Marcel Marceau" ) );
    CheckResult( pAuxDesc->SetCharSet( L"csISO069French" ) );

    IAAFSmartPointer<IAAFEssenceDescriptor> pDesc;
    CheckResult( pAuxDesc->QueryInterface( IID_IAAFEssenceDescriptor, (void**)&pDesc ) );
    CheckResult( spSourceMob->SetEssenceDescriptor( pDesc ) );

    CheckResult( filePointers.pFile->Save() );
    CheckResult( filePointers.pFile->Close() );
  }
  catch( const AAFRESULT& hr ) {
    return hr;
  }

  return AAFRESULT_SUCCESS;
}

static HRESULT ReadAAFFile(aafWChar * pFileName)
{
  try {
    using namespace mtc;

    SimpleFilePointers filePointers;
    ReadSimpleAAFFile( pFileName, &filePointers );

    // Get the source mob, and check that the RecordingDescriptor is
    // attached.
    IAAFSmartPointer<IAAFSourceClip> pSourceClip
      = GetSourceClipFromSlot( filePointers.pReferencedMasterMob, 1 );

    IAAFSmartPointer<IAAFMob> pMob;
    CheckResult( pSourceClip->ResolveRef( &pMob ) );
    
    IAAFSmartPointer<IAAFSourceMob> pSourceMob;
    CheckResult( pMob->QueryInterface( IID_IAAFSourceMob, (void**)&pSourceMob ) );

    IAAFSmartPointer<IAAFEssenceDescriptor> pDesc;
    CheckResult( pSourceMob->GetEssenceDescriptor( &pDesc ) );

    // Finally...
    IAAFSmartPointer<IAAFAuxiliaryDescriptor> pAuxDesc;
    CheckResult( pDesc->QueryInterface( IID_IAAFAuxiliaryDescriptor, (void**)&pAuxDesc ));

    // FIXME - Why is a 30 wchar buffer required to read a 15
    // character string???  The OM returns the correct string, but
    // returns SMALL_BUF if less than 30 is used?
    const unsigned int bufSize = 30;
    aafCharacter* stringBuf[bufSize];
    CheckResult( pAuxDesc->GetMimeType( (aafCharacter*)stringBuf, 2*bufSize ) );
    CheckExpression( ::wcscmp( (aafCharacter*)stringBuf, L"Marcel Marceau" ) == 0,
		     AAFRESULT_TEST_FAILED );
    
    CheckResult( pAuxDesc->GetCharSet( (aafCharacter*)stringBuf, 2*bufSize ) );
    CheckExpression( ::wcscmp( (aafCharacter*)stringBuf, L"csISO069French" ) == 0,
		     AAFRESULT_TEST_FAILED );

    CheckResult( filePointers.pFile->Close() );
  }
  catch( const AAFRESULT& hr ) {
    cout << "failed hr = " << hr << endl;
    return hr;
  }

  return AAFRESULT_SUCCESS;
}

// Required function prototype.
extern "C" HRESULT CAAFAuxiliaryDescriptor_test(testMode_t mode);

HRESULT CAAFAuxiliaryDescriptor_test(testMode_t mode)
{
  HRESULT hr = AAFRESULT_SUCCESS;
  aafCharacter* pFileName = L"AAFAuxiliaryDescriptorTest.aaf";

  try {
    if ( kAAFUnitTestReadWrite == mode ) {
      hr = CreateAAFFile(pFileName);
    }
    else {
      hr = AAFRESULT_SUCCESS;
    }

    if ( AAFRESULT_SUCCESS == hr ) {
      hr = ReadAAFFile(pFileName);
    }
  }
  catch (...) {
    cerr << "CAAFAuxiliaryDescriptor_test...Caught general C++"
	 << " exception!" << endl; 
    hr = AAFRESULT_TEST_FAILED;
  }

  return hr;
}
