//=---------------------------------------------------------------------=
//
// $Id: ImplAAFPhysicalDescriptor.cpp,v 1.4 2006/05/24 18:01:52 tbingham Exp $ $Name:  $
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


#ifndef __ImplAAFPhysicalDescriptor_h__
#include "ImplAAFPhysicalDescriptor.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include "AAFResult.h"


ImplAAFPhysicalDescriptor::ImplAAFPhysicalDescriptor ()
{
}


ImplAAFPhysicalDescriptor::~ImplAAFPhysicalDescriptor ()
{}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPhysicalDescriptor::GetOwningMobKind (aafMobKind_t *pMobKind)
{
	if(pMobKind  == NULL)
		return(AAFRESULT_NULL_PARAM);
	*pMobKind = kAAFPhysicalMob;
	return(AAFRESULT_SUCCESS);
}
