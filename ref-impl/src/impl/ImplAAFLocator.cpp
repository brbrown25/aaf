//=---------------------------------------------------------------------=
//
// $Id: ImplAAFLocator.cpp,v 1.9 2004/02/27 14:26:47 stuart_hc Exp $ $Name:  $
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





#include "AAFStoredObjectIDs.h"

#ifndef __ImplAAFLocator_h__
#include "ImplAAFLocator.h"
#endif

#include <assert.h>
#include <string.h>


ImplAAFLocator::ImplAAFLocator ()
{}


ImplAAFLocator::~ImplAAFLocator ()
{}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFLocator::GetPath (
      aafCharacter *  /*pPathBuf*/,
      aafUInt32  /*bufSize*/)
{
  return AAFRESULT_ABSTRACT_CLASS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFLocator::GetPathBufLen (
      aafUInt32 *  /*pLen*/)
{
  return AAFRESULT_ABSTRACT_CLASS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFLocator::SetPath (
      const aafCharacter *  /*pPathBuf*/)
{
  return AAFRESULT_ABSTRACT_CLASS;
}



