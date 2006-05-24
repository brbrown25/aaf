//=---------------------------------------------------------------------=
//
// $Id: ImplAAFSourceReference.cpp,v 1.28 2006/05/24 18:01:53 tbingham Exp $ $Name:  $
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

#ifndef __ImplAAFSourceReference_h__
#include "ImplAAFSourceReference.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include "AAFResult.h"
#include "AAFUtils.h"

#include <OMVariableSizeProperty.h>

ImplAAFSourceReference::ImplAAFSourceReference ():
	_sourceID(			PID_SourceReference_SourceID,		L"SourceID"),
	_sourceMobSlotId(	PID_SourceReference_SourceMobSlotID,	L"SourceMobSlotID"),
	_channelIDs( PID_SourceReference_ChannelIDs, L"ChannelIDs" ),
	_monoSourceSlotIDs( PID_SourceReference_MonoSourceSlotIDs, L"MonoSourceSlotIDs" )
{
	_persistentProperties.put( _sourceID.address() );
	_persistentProperties.put( _sourceMobSlotId.address() );
	_persistentProperties.put( _channelIDs.address() );
	_persistentProperties.put( _monoSourceSlotIDs.address() );
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


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::SetChannelIDs (
      aafUInt32  numberElements,
      aafUInt32*  pChannelIDs )
{
  if( NULL == pChannelIDs ) {
    return AAFRESULT_NULL_PARAM;
  }
  if( (numberElements * sizeof(aafUInt32)) > OMPROPERTYSIZE_MAX ) {
    return AAFRESULT_BAD_SIZE;
  }

  _channelIDs.setValue(pChannelIDs, numberElements * sizeof(*pChannelIDs));
  
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetChannelIDs (
      aafUInt32 numberElements,
      aafUInt32* pChannelIDs )
{
  if( NULL == pChannelIDs ) {
    return AAFRESULT_NULL_PARAM;
  }

  if( !_channelIDs.isPresent() ) {
    return AAFRESULT_PROP_NOT_PRESENT;
  }

  if ( _channelIDs.size() > (numberElements * sizeof(*pChannelIDs)) ) {
    return AAFRESULT_SMALLBUF;
  }

  _channelIDs.copyToBuffer( pChannelIDs, numberElements * sizeof(*pChannelIDs));
  
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetChannelIDsSize (
      aafUInt32 *  pSize)
{
  if ( NULL == pSize ) {
    return AAFRESULT_NULL_PARAM;
  }

  if( !_channelIDs.isPresent() ) {
    *pSize = 0;
  }
  else {
    *pSize = _channelIDs.size();
  }

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::SetMonoSourceSlotIDs (
      aafUInt32 numberElements,
      aafUInt32* pMonoSourceSlotIDs)
{
  if( NULL == pMonoSourceSlotIDs ) {
    return AAFRESULT_NULL_PARAM;
  }
  if( (numberElements * sizeof(aafUInt32)) > OMPROPERTYSIZE_MAX ) {
    return AAFRESULT_BAD_SIZE;
  }

  _monoSourceSlotIDs.setValue(pMonoSourceSlotIDs, numberElements * sizeof(*pMonoSourceSlotIDs));
  
  return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetMonoSourceSlotIDs (
      aafUInt32  numberElements,
      aafUInt32*  pMonoSourceSlotIDs )
{
  if( NULL == pMonoSourceSlotIDs ) {
    return AAFRESULT_NULL_PARAM;
  }

  if( !_monoSourceSlotIDs.isPresent() ) {
    return AAFRESULT_PROP_NOT_PRESENT;
  }

  if ( _monoSourceSlotIDs.size() > (numberElements * sizeof(*pMonoSourceSlotIDs)) ) {
    return AAFRESULT_SMALLBUF;
  }

  _monoSourceSlotIDs.copyToBuffer( pMonoSourceSlotIDs, numberElements * sizeof(*pMonoSourceSlotIDs));


  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFSourceReference::GetMonoSourceSlotIDsSize (
      aafUInt32 *  pSize )
{
  if ( NULL == pSize) {
    return AAFRESULT_NULL_PARAM;
  }

  if( !_monoSourceSlotIDs.isPresent() ) {
    *pSize = 0;
  }
  else {
    *pSize = _monoSourceSlotIDs.size();
  }

  return AAFRESULT_SUCCESS;
}


AAFRESULT ImplAAFSourceReference::ChangeContainedReferences(aafMobID_constref from,
															aafMobID_constref to)
{
	aafMobID_t			myID = _sourceID;

	if(memcmp(&myID, &from, sizeof(aafMobID_t)) == 0)
		SetSourceID(to);

	return AAFRESULT_SUCCESS;
}



