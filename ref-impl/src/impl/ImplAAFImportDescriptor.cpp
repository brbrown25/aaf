//=---------------------------------------------------------------------=
//
// $Id: ImplAAFImportDescriptor.cpp,v 1.1.2.2 2004/06/29 14:34:14 akharkev Exp $ $Name:  $
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


#ifndef __ImplAAFImportDescriptor_h__
#include "ImplAAFImportDescriptor.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include <assert.h>
#include "AAFResult.h"


ImplAAFImportDescriptor::ImplAAFImportDescriptor ()
{
}


ImplAAFImportDescriptor::~ImplAAFImportDescriptor ()
{}


AAFRESULT STDMETHODCALLTYPE
ImplAAFImportDescriptor::Initialize ()
{
  return AAFRESULT_SUCCESS;
}




