/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/



#ifndef __ImplAAFGroup_h__
#include "ImplAAFGroup.h"
#endif

#ifndef __ImplAAFDataDef_h__
#include "ImplAAFDataDef.h"
#endif

#ifndef __ImplAAFParameter_h__
#include "ImplAAFParameter.h"
#endif

#ifndef __ImplAAFSourceReference_h__
#include "ImplAAFSourceReference.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIds.h"

#include <assert.h>
#include <string.h>

#include "AAFTypes.h"
#include "AAFResult.h"
#include "aafErr.h"
#include "aafCvt.h"
#include "aafUtils.h"
#include "AAFDefUIDs.h"


/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/


#ifndef __ImplAAFTransition_h__
#include "ImplAAFTransition.h"
#endif

#include <assert.h>
#include <string.h>


ImplAAFTransition::ImplAAFTransition ():
_effect( PID_Transition_Effect, "Effect"),
_cutPoint( PID_Transition_CutPoint, "CutPoint")
{
	_persistentProperties.put(_effect.address());
	_persistentProperties.put(_cutPoint.address());
}


ImplAAFTransition::~ImplAAFTransition ()
{
	if (_effect)
	{
		_effect->ReleaseReference();
		_effect = NULL;
	}
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFTransition::Create (aafUID_t*		pDatadef,
							   aafLength_t		length,
							   aafPosition_t	cutPoint,
							   ImplAAFGroup*	pEffect)
{
	HRESULT		rc = AAFRESULT_SUCCESS;

	if (pDatadef == NULL || pEffect == NULL)
		return AAFRESULT_NULL_PARAM;

	XPROTECT()
	{
		CHECK(SetNewProps(length, pDatadef));
		_cutPoint = cutPoint;
		if (_effect)
			_effect->ReleaseReference();
		_effect = pEffect;
		if (pEffect)
			pEffect->AcquireReference();

	}
	XEXCEPT
	XEND;
	
	return rc;
}
	 

AAFRESULT STDMETHODCALLTYPE
    ImplAAFTransition::GetCutPoint (aafPosition_t*  pCutPoint)
{
	HRESULT		rc = AAFRESULT_SUCCESS;

	if (pCutPoint == NULL )
		return AAFRESULT_NULL_PARAM;

	*pCutPoint = _cutPoint;
	return rc;
}

	//@comm Replaces part of omfsTransitionGetInfo

AAFRESULT STDMETHODCALLTYPE
    ImplAAFTransition::GetEffect (ImplAAFGroup ** ppEffObj)
{
	if (ppEffObj == NULL)
		return AAFRESULT_NULL_PARAM;

	*ppEffObj = _effect;
	if (*ppEffObj)
		(*ppEffObj)->AcquireReference();

	return AAFRESULT_SUCCESS; 
}

	//@comm Replaces part of omfsTransitionGetInfo

AAFRESULT STDMETHODCALLTYPE
    ImplAAFTransition::SetCutPoint (aafPosition_t  cutPoint)
{
	_cutPoint = cutPoint;

	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTransition::SetEffect (ImplAAFGroup * pEffObj)
{

	if (pEffObj == NULL)
		return AAFRESULT_NULL_PARAM;
	
	_effect = pEffObj;
	return AAFRESULT_SUCCESS; 
}



OMDEFINE_STORABLE(ImplAAFTransition, AUID_AAFTransition);


