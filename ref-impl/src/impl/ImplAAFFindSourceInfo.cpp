//=---------------------------------------------------------------------=
//
// $Id: ImplAAFFindSourceInfo.cpp,v 1.22 2005/02/07 18:51:00 stuart_hc Exp $ $Name:  $
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


#ifndef __ImplAAFFindSourceInfo_h__
#include "ImplAAFFindSourceInfo.h"
#endif

#include <assert.h>
#include <string.h>
#include "aafErr.h"
#include "ImplAAFMob.h"
#include "ImplAAFOperationGroup.h"
#include "AAFDefUIDs.h"

ImplAAFFindSourceInfo::ImplAAFFindSourceInfo ()
{
	_mob = NULL;
	_cpnt = NULL;
	_editRate.numerator = 0;
	_editRate.denominator = 1;
	_position = 0;
	_length = 0;
	_operationGroup = NULL;
}


ImplAAFFindSourceInfo::~ImplAAFFindSourceInfo ()
{
	if (_mob)
	{
		_mob->ReleaseReference();
		_mob = NULL;
	}
	if (_cpnt)
	{
		_cpnt->ReleaseReference();
		_cpnt = NULL;
	}
	if (_operationGroup)
	{
		_operationGroup->ReleaseReference();
		_operationGroup = NULL;
	}
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::Init(ImplAAFMob *mob, aafSlotID_t slotID, aafPosition_t position,
							aafRational_t editRate, aafLength_t length,
							ImplAAFComponent *cpnt)
{
	if (_mob)
	  {
		_mob->ReleaseReference();
		_mob = 0;
	  }
	_mob = mob;
	if (mob)
		mob->AcquireReference();
	_slotID = slotID;
	_position = position;
	_editRate = editRate;
	_length = length;
	if (_cpnt)
	  {
		_cpnt->ReleaseReference();
		_cpnt = 0;
	  }
	_cpnt = cpnt;
	if (cpnt)
		cpnt->AcquireReference();
	return(AAFRESULT_SUCCESS);
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::AddPulldown(ImplAAFPulldown * /*pdwn*/)
{
	return AAFRESULT_NOT_IN_CURRENT_VERSION;
}

//AAFRESULT STDMETHODCALLTYPE
//ImplAAFFindSourceInfo::Duplicate(ImplAAFFindSourceInfo * /*result*/)
//{
//	return AAFRESULT_NOT_IN_CURRENT_VERSION;
//}


AAFRESULT STDMETHODCALLTYPE ImplAAFFindSourceInfo::Clear(void)
{
	if (_mob)
	  {
		_mob->ReleaseReference();
		_mob = 0;
	  }
	_mob = NULL;
	if (_cpnt)
	  {
		_cpnt->ReleaseReference();
		_cpnt = 0;
	  }
	_cpnt = NULL;
	_editRate.numerator = 0;
	_editRate.denominator = 1;
	_position = 0;
	_length = 0;
	if (_operationGroup)
		_operationGroup->ReleaseReference();
	_operationGroup = NULL;

	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::SetOperationGroup(
				ImplAAFOperationGroup *group)
{
	if (_operationGroup)
	  {
		_operationGroup->ReleaseReference();
		_operationGroup = 0;
	  }
	_operationGroup = group;
	if (group)
	  group->AcquireReference();
	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::SetComponent(
				ImplAAFComponent *cpnt)
{
	if (_cpnt)
	  {
		_cpnt->ReleaseReference();
		_cpnt = 0;
	  }
	_cpnt = cpnt;
	if (cpnt)
	  cpnt->AcquireReference();
	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
		ImplAAFFindSourceInfo::GetSourceReference(aafSourceRef_t *pSourceRef)
{
	if (pSourceRef == NULL)
		return AAFRESULT_NULL_PARAM;

	XPROTECT()
	{
		pSourceRef->sourceSlotID = _slotID;
		pSourceRef->startTime = _position;
		if(_mob != NULL)
		{
			CHECK(_mob->GetMobID(&pSourceRef->sourceID));
		}
		else
		{
			memset(&pSourceRef->sourceID, 0, sizeof(pSourceRef->sourceID));
		}
	}
	XEXCEPT
	XEND;

	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::GetMob(ImplAAFMob **ppMob)
{
	if(ppMob == NULL)
		return AAFRESULT_NULL_PARAM;
	*ppMob = _mob;
	if (*ppMob)
	  (*ppMob)->AcquireReference();
	else
	  return AAFRESULT_NULLOBJECT;
	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::GetEditRate(aafRational_t *pEditRate)
{
	if(pEditRate == NULL)
		return AAFRESULT_NULL_PARAM;
	*pEditRate = _editRate;
	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFFindSourceInfo::GetLength(aafLength_t *pLength)
{
	if(pLength == NULL)
		return AAFRESULT_NULL_PARAM;
	*pLength = _length;
	return AAFRESULT_SUCCESS;
}
