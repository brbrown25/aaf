//=---------------------------------------------------------------------=
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

#ifndef __ImplAAFSourceReference_h__
#include "ImplAAFSourceReference.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include <assert.h>
#include "AAFResult.h"
#include "AAFUtils.h"

ImplAAFSourceReference::ImplAAFSourceReference ():
	_sourceID(			PID_SourceReference_SourceID,		L"SourceID"),
	_sourceMobSlotId(	PID_SourceReference_SourceMobSlotID,	L"SourceMobSlotID")
{
	_persistentProperties.put(		_sourceID.address());
	_persistentProperties.put(		_sourceMobSlotId.address());
}


ImplAAFSourceReference::~ImplAAFSourceReference ()
{}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetSourceID (aafMobID_t*	pSourceID)
{
    AAFRESULT aafError = AAFRESULT_SUCCESS;
	if (pSourceID == NULL)
	{
		aafError = AAFRESULT_NULL_PARAM;
	}
	else if (!_sourceID.isPresent())
	{
		aafError = AAFRESULT_PROP_NOT_PRESENT;
	}
	else
	{
		*pSourceID = _sourceID;
	}

	return aafError;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::SetSourceID (aafMobID_constref	sourceID)
{
    AAFRESULT aafError = AAFRESULT_SUCCESS;

	_sourceID = sourceID;

	return aafError;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetSourceMobSlotID (aafSlotID_t*	pMobSlotID)
{
    AAFRESULT aafError = AAFRESULT_SUCCESS;
	if (pMobSlotID == NULL)
	{
		aafError = AAFRESULT_NULL_PARAM;
	}
	else
	{
		*pMobSlotID = _sourceMobSlotId;
	}

	return aafError;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::SetSourceMobSlotID (aafSlotID_t		mobSlotID)
{
    AAFRESULT aafError = AAFRESULT_SUCCESS;

	_sourceMobSlotId = mobSlotID;

	return aafError;
}


AAFRESULT ImplAAFSourceReference::ChangeContainedReferences(aafMobID_constref from,
															aafMobID_constref to)
{
	aafMobID_t			myID = _sourceID;

	if(memcmp(&myID, &from, sizeof(aafMobID_t)) == 0)
		SetSourceID(to);

	return AAFRESULT_SUCCESS;
}



