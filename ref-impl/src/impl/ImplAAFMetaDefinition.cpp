/***********************************************************************
 *
 *              Copyright (c) 1998-2000 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 * prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/

/*************************************************************************
 * 
 * @module AAFMetaDefinition | AAFMetaDefinition is an abstract class
 *		  that defines an item to be referenced in the AAF file. 
 *		  AAFMetaDefinition specifies the AUID unique identifier.
 *
 * @base public | AAFObject
 *
 *************************************************************************/



#ifndef __ImplAAFMetaDefinition_h__
#include "ImplAAFMetaDefinition.h"
#endif


#ifndef __ImplAAFClassDef_h_
#include "ImplAAFClassDef.h"
#endif

#ifndef __ImplAAFDictionary_h_
#include "ImplAAFDictionary.h"
#endif

#ifndef __ImplAAFMetaDictionary_h_
#include "ImplAAFMetaDictionary.h"
#endif

#ifndef __ImplEnumAAFPropertyDefs_h__
#include "ImplEnumAAFPropertyDefs.h"
#endif

//#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include <assert.h>
#include <string.h>


ImplAAFMetaDefinition::ImplAAFMetaDefinition ()
: _name           (PID_MetaDefinition_Name,           L"Name"),
  _description    (PID_MetaDefinition_Description,    L"Description"),
  _identification (PID_MetaDefinition_Identification, L"Identification")
{
  _persistentProperties.put(_name.address());
  _persistentProperties.put(_description.address());
  _persistentProperties.put(_identification.address());
}


ImplAAFMetaDefinition::~ImplAAFMetaDefinition ()
{
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::Initialize (
    aafUID_constref id,
	  aafCharacter_constptr pName,
    aafCharacter_constptr pDescription)
{
  AAFRESULT result = AAFRESULT_SUCCESS;
	//validate pName
  if (pName == NULL)
  {
    return AAFRESULT_NULL_PARAM;
  }

  result = SetIdentification (id);
  if (AAFRESULT_SUCCEEDED(result))
  {
    result = SetName (pName);
    if (AAFRESULT_SUCCEEDED(result))
    {
      if (pDescription)
      {
        result = SetDescription (pDescription);
      }
    }
  }

  return result;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::GetAUID (
      aafUID_t *pAuid) const
{
  if (pAuid == NULL)
	{
	  return AAFRESULT_NULL_PARAM;
	}
  else
	{
	  *pAuid = _identification;
	}

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::SetName (
      aafCharacter_constptr  pName)
{
  if (! pName)
	{
	  return AAFRESULT_NULL_PARAM;
	}

  _name = pName;

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::GetName (
      aafCharacter * pName,
      aafUInt32  bufSize)
{
  bool stat;
  if (! pName)
	{
	  return AAFRESULT_NULL_PARAM;
	}
  stat = _name.copyToBuffer(pName, bufSize);
  if (! stat)
	{
	  return AAFRESULT_SMALLBUF;
	}

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::GetNameBufLen (
      aafUInt32 *  pBufSize)  //@parm [in,out] Definition Name length
{
  if (! pBufSize)
	{
	  return AAFRESULT_NULL_PARAM;
	}
  *pBufSize = _name.size();
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::SetDescription (
      aafCharacter_constptr pDescription)
{
  if (! pDescription)
	{
	  return AAFRESULT_NULL_PARAM;
	}

  _description = pDescription;

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::GetDescription (
      aafCharacter * pDescription,
      aafUInt32 bufSize)
{
	bool stat;
	if (! pDescription)
	{
		return AAFRESULT_NULL_PARAM;
	}
	if (!_description.isPresent())
	{
		return AAFRESULT_PROP_NOT_PRESENT;
	}
	stat = _description.copyToBuffer(pDescription, bufSize);
	if (! stat)
	{
		return AAFRESULT_SMALLBUF;
	}
	
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMetaDefinition::GetDescriptionBufLen (
      aafUInt32 * pBufSize)  //@parm [in,out] Definition Name length
{
	if (! pBufSize)
	{
		return AAFRESULT_NULL_PARAM;
	}
	if (!_description.isPresent())
		*pBufSize = 0;
	else
		*pBufSize = _description.size();
	
	return AAFRESULT_SUCCESS;
}



// Gets the dictionary used to create this instance.
AAFRESULT STDMETHODCALLTYPE
ImplAAFMetaDefinition::GetDictionary(ImplAAFDictionary **ppDictionary) const
{
  if(NULL == ppDictionary)
    return AAFRESULT_NULL_PARAM;

  *ppDictionary = dynamic_cast<ImplAAFDictionary *>(classFactory());

  if (NULL == *ppDictionary)
  {
    // The other OMFactory is the meta dictionary. If so, then return the 
    // data dictionary set when the meta dictionary was created.
    // (NOTE: This may be temporary code...transdel:2000-APR-14)
    ImplAAFMetaDictionary *pMetaDictionary = dynamic_cast<ImplAAFMetaDictionary *>(classFactory());
    if (pMetaDictionary)
    {
      *ppDictionary = pMetaDictionary->dataDictionary(); // not reference counted!
    }
  }  
  
  assert(NULL != *ppDictionary);
  if (NULL == *ppDictionary)
    return AAFRESULT_INVALID_OBJ;
  
  // Bump the reference count...
  (*ppDictionary)->AcquireReference();
  
  return AAFRESULT_SUCCESS;
}



// Associate the existing OMProperties with corresponding property definitions from
// the given class definition. NOTE: This call is recursive, it calls itself again
// for the parent class of the given class until current class is a "root" class.
void ImplAAFMetaDefinition::InitOMProperties (ImplAAFClassDef * pClassDef)
{
#if 0
  // Since ImplAAFMetaDefinition is still a subclass of ImplAAFObject we
  // should just delegate property initialization:
  ImplAAFObject::InitOMProperties(pClassDef);
#else //#if 0

  assert (pClassDef);
  AAFRESULT hr;

  //
  // Init base class properties first
  //
  ImplAAFClassDefSP parentSP;
  hr = pClassDef->GetParent (&parentSP);
  // check that only a "root" will have no parent class definition.
  assert (AAFRESULT_SUCCEEDED(hr) || (AAFRESULT_FAILED(hr) && AAFRESULT_IS_ROOT_CLASS == hr));
  if(AAFRESULT_SUCCEEDED(hr))
  {
    assert (parentSP);
    InitOMProperties (parentSP);
  }

  // See if currently existing OM properties are defined in the class
  // def.
  //
  OMPropertySet * ps = propertySet();
  assert (ps);
  const size_t propCount = ps->count();

  // Loop through properties of this class
  ImplEnumAAFPropertyDefsSP pdEnumSP;
  hr = pClassDef->GetPropertyDefs (&pdEnumSP);
  assert (AAFRESULT_SUCCEEDED (hr));

  ImplAAFPropertyDefSP propDefSP;
  while (AAFRESULT_SUCCEEDED (pdEnumSP->NextOne (&propDefSP)))
  {
    OMPropertyId defPid = propDefSP->OmPid ();
    // assert (ps->isAllowed (defPid));
    OMProperty * pProp = 0;
    if (ps->isPresent (defPid))
    {
      // Defined property was already in property set.  (Most
      // probably declared in the impl constructor.)  Get that
      // property.
      pProp = ps->get (defPid);
    }      
    else if(defPid != PID_InterchangeObject_ObjClass
      && (defPid != PID_InterchangeObject_Generation))
    {
      assert (0);
#if 0
      // Defined property wasn't found in OM property set.
      // We'll have to install one.
      pProp = propDefSP->CreateOMProperty ();
      assert (pProp);
      
      // Remember this property so we can delete it later.
      RememberAddedProp (pProp);
      
      // Add the property to the property set.
      ps->put (pProp);
#endif
    }
    
  if(defPid != PID_InterchangeObject_ObjClass
      && (defPid != PID_InterchangeObject_Generation))
  {
      ImplAAFPropertyDef * pPropDef =
        (ImplAAFPropertyDef*) propDefSP;
      OMPropertyDefinition * pOMPropDef =
        dynamic_cast<OMPropertyDefinition*>(pPropDef);
      assert (pOMPropDef);
      
      assert (pProp);
      pProp->initialize (pOMPropDef);
      
      pPropDef = 0;
      pOMPropDef = 0;
    }
    propDefSP = 0;
    pProp = 0;
  }
#endif // #else // #if 0
}

const OMUniqueObjectIdentification&
  ImplAAFMetaDefinition::identification(void) const
{
  return *reinterpret_cast<const OMUniqueObjectIdentification*>(&_identification.reference());
}



// Private method to install the AAFObjectModel definition associated with
// this meta definition.
AAFRESULT ImplAAFMetaDefinition::SetIdentification(aafUID_constref identification)
{
  _identification = identification;

  return AAFRESULT_SUCCESS;
}



// override from OMStorable.
const OMClassId& ImplAAFMetaDefinition::classId(void) const
{
  // This method needs to be overridden for all subclasses.
  // All meta definitions class id's are known statically.
  // The corresponding class defintions cannot be extended
  // at runtime.
  static OMObjectIdentification null = {0};
  return null;
}

// Override callbacks from OMStorable
void ImplAAFMetaDefinition::onSave(void* /*clientContext*/) const
{
  // MetaDefinitions are not generation-tracked since they are
  // immutable.
}

void ImplAAFMetaDefinition::onRestore(void* /*clientContext*/) const
{
  // clientContext currently unused

  // Cast away constness (maintaining logical constness)
  ((ImplAAFMetaDefinition*) this)->setInitialized ();
}
