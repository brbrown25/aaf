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






#ifndef __ImplAAFWAVEDescriptor_h__
#include "ImplAAFWAVEDescriptor.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include <assert.h>
#include <string.h>


ImplAAFWAVEDescriptor::ImplAAFWAVEDescriptor ()
:   _summary(PID_WAVEDescriptor_Summary,	L"Summary")
{
	_persistentProperties.put(_summary.address());
}


ImplAAFWAVEDescriptor::~ImplAAFWAVEDescriptor ()
{
	// TODO: free summary
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFWAVEDescriptor::Initialize ()
{
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFWAVEDescriptor::GetSummary (aafUInt32 size, aafDataValue_t pSummary)
{
	if(pSummary == NULL)
		return(AAFRESULT_NULL_PARAM);

	if (_summary.size() > size)
	  return AAFRESULT_SMALLBUF;

	_summary.copyToBuffer(pSummary, size);

	return(AAFRESULT_SUCCESS); 
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFWAVEDescriptor::GetSummaryBufferSize (aafUInt32* pSize)
{
	if(pSize == NULL)
		return(AAFRESULT_NULL_PARAM);

	*pSize = _summary.size();

	return(AAFRESULT_SUCCESS); 
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFWAVEDescriptor::SetSummary (aafUInt32 size, aafDataValue_t  pSummary)
{
	if(pSummary == NULL)
		return(AAFRESULT_NULL_PARAM);

	_summary.setValue(pSummary, size);

	return(AAFRESULT_SUCCESS); 
}
