/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/



#ifndef __ImplAAFClassDef_h__
#include "ImplAAFClassDef.h"
#endif

#ifndef __ImplEnumAAFCodecFlavours_h__
#include "ImplEnumAAFCodecFlavours.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include "ImplAAFObjectCreation.h"

#ifndef __ImplAAFCodecDef_h__
#include "ImplAAFCodecDef.h"
#endif

#include "ImplAAFDataDef.h"

#include <assert.h>
#include <string.h>
#include "aafErr.h"
#include "AafUtils.h"

extern "C" const aafClassID_t CLSID_EnumAAFDataDefs;

ImplAAFCodecDef::ImplAAFCodecDef ()
:  _dataDefs(		PID_CodecDefinition_DataDefinitions,			"DataDefinitions")
{
	_persistentProperties.put(_dataDefs.address());
}


ImplAAFCodecDef::~ImplAAFCodecDef ()
{
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::IsEssenceKindSupported (
      aafUID_t *pEssenceKind,
      aafBool* pIsSupported)
{
	ImplEnumAAFDataDefs	*dataEnum = NULL;
	ImplAAFDataDef		*aVal = NULL;
	aafBool				result = AAFFalse;
	aafUID_t			essenceUID;

	XPROTECT()
	{
		CHECK(GetDataDefinitions (&dataEnum));
		while((dataEnum->NextOne(&aVal) == AAFRESULT_SUCCESS)
		   && (result == AAFFalse))
		{
			CHECK(aVal->IsDataDefOf(pEssenceKind, &result));
			aVal->ReleaseReference();
			aVal = NULL;
		}
		*pIsSupported = result;
		dataEnum->ReleaseReference();
		dataEnum = NULL;

	}
	XEXCEPT
	{
		if(aVal)
			aVal->ReleaseReference();
		if(dataEnum)
			dataEnum->ReleaseReference();
	}
	XEND;

	return AAFRESULT_SUCCESS;
}

 
 AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::AppendEssenceKind (
      aafUID_t *pEssenceKind)
{
	aafUID_t	*tmp, newUID;
	aafInt32	oldBufSize;
	aafInt32	newBufSize;

	if(pEssenceKind == NULL)
		return AAFRESULT_NULL_PARAM;
	
	XPROTECT()
	{
		oldBufSize = _dataDefs.size();
		newBufSize = oldBufSize + sizeof(aafUID_t);
		tmp = new aafUID_t[newBufSize];
		newUID = *pEssenceKind;
		if(tmp == NULL)
			RAISE(AAFRESULT_NOMEMORY);
		if(oldBufSize != 0)
			_dataDefs.copyToBuffer(tmp, oldBufSize);
		tmp[oldBufSize/sizeof(aafUID_t)] = newUID;
		_dataDefs.setValue(tmp, newBufSize);
		delete [] tmp;
	}
	XEXCEPT
	{
		if(tmp != NULL)
			delete [] tmp;
	}
	XEND;

	return AAFRESULT_SUCCESS;
}




AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::AreThereFlavours (
      aafBool *  /*pResult*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::GetFileDescriptorClass (
      ImplAAFClassDef ** /*ppClass*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::SetFileDescriptorClass (
      ImplAAFClassDef * /*pClass*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::EnumCodecFlavours (
      ImplEnumAAFCodecFlavours ** /*ppEnum*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}

  
// SDK-private
AAFRESULT STDMETHODCALLTYPE
    ImplAAFCodecDef::GetDataDefinitions (
      ImplEnumAAFDataDefs  **ppEnum)
{
	if(ppEnum == NULL)
		return(AAFRESULT_NULL_PARAM);

	*ppEnum = (ImplEnumAAFDataDefs *)CreateImpl(CLSID_EnumAAFDataDefs);
	if(*ppEnum == NULL)
		return(AAFRESULT_NOMEMORY);
	(*ppEnum)->SetEnumProperty(this, &_dataDefs);

	return(AAFRESULT_SUCCESS);
}

OMDEFINE_STORABLE(ImplAAFCodecDef, AUID_AAFCodecDef);


