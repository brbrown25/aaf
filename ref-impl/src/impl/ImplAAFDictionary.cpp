/************************************************\
*												*
* Advanced Authoring Format						*
*												*
* Copyright (c) 1998-1999 Avid Technology, Inc. *
* Copyright (c) 1998-1999 Microsoft Corporation *
*												*
\************************************************/


#ifndef __ImplAAFClassDef_h__
#include "ImplAAFClassDef.h"
#endif

#ifndef __ImplEnumAAFClassDefs_h__
#include "ImplEnumAAFClassDefs.h"
#endif

#ifndef __ImplAAFTypeDef_h__
#include "ImplAAFTypeDef.h"
#endif

#ifndef __ImplEnumAAFTypeDefs_h__
#include "ImplEnumAAFTypeDefs.h"
#endif

#ifndef __ImplAAFDataDef_h__
#include "ImplAAFDataDef.h"
#endif

#ifndef __ImplEnumAAFDataDefs_h__
#include "ImplEnumAAFDataDefs.h"
#endif

#ifndef __ImplAAFEffectDef_h__
#include "ImplAAFEffectDef.h"
#endif

#ifndef __ImplEnumAAFEffectDefs_h__
#include "ImplEnumAAFEffectDefs.h"
#endif







#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include "ImplAAFObjectCreation.h"
#include "ImplEnumAAFPluggableDefs.h"

#ifndef __ImplAAFDictionary_h__
#include "ImplAAFDictionary.h"
#endif

#include "ImplAAFMob.h"

#include <assert.h>
#include <string.h>
#include "aafErr.h"

extern "C" const aafClassID_t CLSID_EnumAAFPluggableDefs;

ImplAAFDictionary::ImplAAFDictionary ()
: _pluginDefinitions(PID_Dictionary_PluginDefinitions, "PluginDefinitions")
{
  _persistentProperties.put(_pluginDefinitions.address());
}


ImplAAFDictionary::~ImplAAFDictionary ()
{
	ImplAAFPluggableDef *pPlug = NULL;
	size_t size, i;

	// Release the pluginDefinitions
	_pluginDefinitions.getSize(size);
	for (i = 0; i < size; i++)
	{
		_pluginDefinitions.getValueAt(pPlug, i);
		if (pPlug)
		{
		  pPlug->ReleaseReference();
		  // Set value to 0 so OM can perform necessary cleanup.
		  _pluginDefinitions.setValueAt(0, i);
		}
	}
}



#ifndef __ImplAAFBaseClassFactory_h__
#include "ImplAAFBaseClassFactory.h"
#endif

// Creates a single uninitialized AAF object of the class associated 
  // with a specified stored object id.
AAFRESULT STDMETHODCALLTYPE 
  ImplAAFDictionary::CreateInstance (
    // Class identifier (AUID) of the stored object. This is the
    // corresponding SMPTE identifier (as a GUID) for all predefined
    // built-in classes.
    aafUID_t * pAUID,

    // Address of output variable that receives the 
    // object pointer requested in pAUID
    ImplAAFObject ** ppvObject)
{
  if (NULL == pAUID || NULL == ppvObject)
    return AAFRESULT_NULL_PARAM;
  
  // Look for the object in the built-in base class factory.
  *ppvObject = ImplAAFBaseClassFactory::CreateInstance(pAUID);

  if (NULL == *ppvObject)
  {
    // TBD:
    // Search the rest of the dictionary for extension classes.
    // 
  }
  

  if (NULL == *ppvObject)
    return AAFRESULT_INVALID_CLASS_ID;
  else
    return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::LookupClass (
      aafUID_t *  /*pClassID*/,
      ImplAAFClassDef ** /*ppClassDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::RegisterClass (
      ImplAAFClassDef * /*pClassDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::GetClassDefinitions (
      ImplEnumAAFClassDefs ** /*ppEnum*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::RegisterType (
      ImplAAFTypeDef * /*pTypeDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::LookupType (
      aafUID_t *  /*pTypeID*/,
      ImplAAFTypeDef ** /*ppTypeDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::GetTypeDefinitions (
      ImplEnumAAFTypeDefs ** /*ppEnum*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::RegisterDataDefintion (
      ImplAAFDataDef * /*pDataDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::LookupDataDefintion (
      aafUID_t *  /*pDataDefintionID*/,
      ImplAAFDataDef ** /*ppDataDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::GetDataDefinitions (
      ImplEnumAAFDataDefs ** /*ppEnum*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::RegisterEffectDefinition (
      ImplAAFEffectDef * /*pEffectDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::LookupEffectDefinition (
      aafUID_t *  /*effectID*/,
      ImplAAFEffectDef ** /*ppEffectDef*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::GetEffectDefinitions (
      ImplEnumAAFEffectDefs ** /*ppEnum*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::RegisterPluggableDefinition (
      ImplAAFPluggableDef *pPlugDef)
{
	if (NULL == pPlugDef)
		return AAFRESULT_NULL_PARAM;
	
	_pluginDefinitions.appendValue(pPlugDef);
	// trr - We are saving a copy of pointer in _pluginDefinitions
	// so we need to bump its reference count.
	pPlugDef->AcquireReference();
	
	return(AAFRESULT_SUCCESS);
}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFDictionary::GetPluggableDefinitions (
	ImplEnumAAFPluggableDefs **ppEnum)
{
	if (NULL == ppEnum)
		return AAFRESULT_NULL_PARAM;
	*ppEnum = 0;
	
	ImplEnumAAFPluggableDefs *theEnum = (ImplEnumAAFPluggableDefs *)CreateImpl (CLSID_EnumAAFPluggableDefs);
	
	XPROTECT()
	{
		CHECK(theEnum->SetDictionary(this));
		*ppEnum = theEnum;
	}
	XEXCEPT
	{
		if (theEnum)
			theEnum->ReleaseReference();
		return(XCODE());
	}
	XEND;
	
	return(AAFRESULT_SUCCESS);
}


AAFRESULT
    ImplAAFDictionary::GetNumPluggableDefs(aafUInt32 *  pNumPluggableDefs)
{
  size_t siz;

  if(pNumPluggableDefs == NULL)
    return AAFRESULT_NULL_PARAM;
  
  _pluginDefinitions.getSize(siz);
  
  *pNumPluggableDefs = siz;
  return AAFRESULT_SUCCESS;
}

AAFRESULT
    ImplAAFDictionary::GetNthPluggableDef (aafInt32 index, ImplAAFPluggableDef **ppPluggableDefs)
{
  if (NULL == ppPluggableDefs)
    return AAFRESULT_NULL_PARAM;

  ImplAAFPluggableDef *obj = NULL;
  _pluginDefinitions.getValueAt(obj, index);
  *ppPluggableDefs = obj;
	
  // trr - We are returning a copy of pointer stored in _mobs so we need
  // to bump its reference count.
  if (obj)
    obj->AcquireReference();
  else
    return AAFRESULT_NO_MORE_OBJECTS;

  return AAFRESULT_SUCCESS;
}


OMDEFINE_STORABLE(ImplAAFDictionary, AUID_AAFDictionary);


