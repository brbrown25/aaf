//=---------------------------------------------------------------------=
//
//
// $Id: ImplAAFDescriptiveClip.cpp,v 1.3 2006/07/14 18:49:08 heydowns Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=





#include "AAFStoredObjectIDs.h"

#ifndef __ImplAAFDescriptiveClip_h__
#include "ImplAAFDescriptiveClip.h"
#endif

#include "AAFPropertyIDs.h"

#include <string.h>


ImplAAFDescriptiveClip::ImplAAFDescriptiveClip ()
: _sourceTrackIDs( PID_DescriptiveClip_SourceTrackIDs, L"SourceTrackIDs" )
{
    _persistentProperties.put( _sourceTrackIDs.address() );
}


ImplAAFDescriptiveClip::~ImplAAFDescriptiveClip ()
{}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::Initialize (ImplAAFDataDef *    pDataDef,
								  const aafLength_t &    length,
								  const aafSourceRef_t & sourceRef)
{
    if( isInitialized() )
    {
        return AAFRESULT_ALREADY_INITIALIZED;
    }
    
    // Call parent class' Initialize.
    AAFRESULT  ar = ImplAAFSourceClip::Initialize(pDataDef, length, sourceRef);

    // Initialize this class required properties
    // and set the object initialized.
    if( ar == AAFRESULT_SUCCESS )
    {
        setInitialized();
    }
    
    return ar;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::CountSourceTrackIDs (
      aafUInt32*  pCount)
{
    if (NULL == pCount) {
        return AAFRESULT_NULL_PARAM;
    }

    if (!_sourceTrackIDs.isPresent()) {
        return AAFRESULT_PROP_NOT_PRESENT;
    }

    *pCount = _sourceTrackIDs.count();

    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::GetSourceTrackIDs (
      aafUInt32  maxSourceTrackIDCount,
      aafUInt32 *  pSourceTrackIDs)
{
    if (!pSourceTrackIDs) {
        return AAFRESULT_NULL_PARAM;
    }

    if (_sourceTrackIDs.count() > maxSourceTrackIDCount) {
        return AAFRESULT_SMALLBUF;
    }

    if (!_sourceTrackIDs.isPresent()) {
        return AAFRESULT_PROP_NOT_PRESENT;
    }

    aafUInt32* pNextSourceTrackID = pSourceTrackIDs;
    OMSetPropertyIterator<aafUInt32> iter( _sourceTrackIDs, OMBefore );
    while (++iter) {
        *pNextSourceTrackID = iter.value();
        pNextSourceTrackID++;
    }

    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::IsSourceTrackIDPresent (
      aafUInt32  sourceTrackID,
      aafBoolean_t*  pIsPresent)
{
    if (NULL == pIsPresent) {
        return AAFRESULT_NULL_PARAM;
    }

    if (!_sourceTrackIDs.isPresent()) {
        return AAFRESULT_PROP_NOT_PRESENT;
    }
    
    *pIsPresent = _sourceTrackIDs.contains(sourceTrackID) ? kAAFTrue :
                                                            kAAFFalse;

    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::AddSourceTrackID (
      aafUInt32  sourceTrackID)
{
    if (_sourceTrackIDs.isPresent()) {
        if (_sourceTrackIDs.contains(sourceTrackID))
            return AAFRESULT_INVALID_PARAM;
    }
    
    _sourceTrackIDs.insert(sourceTrackID);
    
    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDescriptiveClip::RemoveSourceTrackID (
      aafUInt32  sourceTrackID)
{
    if (!_sourceTrackIDs.isPresent())
        return AAFRESULT_PROP_NOT_PRESENT;
    
    if (!_sourceTrackIDs.contains(sourceTrackID))
        return AAFRESULT_INVALID_PARAM;
    
    _sourceTrackIDs.remove(sourceTrackID);
    
    if (_sourceTrackIDs.count() == 0) {
        _sourceTrackIDs.removeProperty();
    }
    
    return AAFRESULT_SUCCESS;
}

