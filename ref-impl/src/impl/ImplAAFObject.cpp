/***********************************************\
*                                               *
* Advanced Authoring Format                     *
*                                               *
* Copyright (c) 1998-1999 Avid Technology, Inc. *
* Copyright (c) 1998-1999 Microsoft Corporation *
*                                               *
\***********************************************/


#ifndef __ImplAAFObject_h__
#include "ImplAAFObject.h"
#endif

#ifndef __ImplAAFCollection_h__
#include "ImplAAFCollection.h"
#endif

#ifndef __ImplAAFEnumerator_h__
#include "ImplAAFEnumerator.h"
#endif

#ifndef __ImplEnumAAFPropertyDefs_h__
#include "ImplEnumAAFPropertyDefs.h"
#endif

#include <assert.h>
#include "aafErr.h"
#include "AAFResult.h"
#include "OMFile.h"
#include "ImplAAFHeader.h"
#include "ImplAAFDictionary.h"
#include "ImplAAFClassDef.h"
#include "ImplAAFProperty.h"
#include "ImplAAFPropertyDef.h"
#include "ImplAAFPropertyValue.h"
#include "ImplEnumAAFProperties.h"

#include "ImplAAFObjectCreation.h"
#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"
#include "OMProperty.h"


extern "C" const aafClassID_t CLSID_AAFProperty;
extern "C" const aafClassID_t CLSID_EnumAAFProperties;


//
// Private class for implementing collections of properties.
//
class ImplPropertyCollection : public ImplAAFCollection<ImplAAFProperty *>
{
public:
  ImplPropertyCollection ();
  ~ImplPropertyCollection ();

  // overrides
  virtual AAFRESULT
    GetNumElements
        (aafUInt32 * pCount);

  virtual AAFRESULT
    GetNthElement
        (aafUInt32  index,
         ImplAAFProperty* * pElem);

  AAFRESULT
    Initialize (ImplAAFObject * pObj,
				OMPropertySet * pOMPropSet);

private:
  ImplAAFPropertySP * _pProperties;
  aafUInt32           _count;
};



ImplPropertyCollection::ImplPropertyCollection ()
  : _pProperties (0),
	_count (0)
{}


AAFRESULT ImplPropertyCollection::Initialize
(
 ImplAAFObject * pObj,
 OMPropertySet * pOMPropSet
)
{
  ImplAAFPropertyDefSP pPropDef;
  AAFRESULT rReturned = AAFRESULT_SUCCESS;

  // make sure we haven't called this before
  assert (! _pProperties);

  if (! pOMPropSet)
	return AAFRESULT_NULL_PARAM;

  // includes count of props both present and absent
  const aafUInt32 numPropsDefined = pOMPropSet->count();
  // only includes props that are present
  aafUInt32 numPropsPresent = 0;

  // count number of properties that are present
  size_t omContext = 0;
  OMProperty * pOmProp = NULL;
  for (aafUInt32 i = 0; i < numPropsDefined; i++)
	{
	  pOmProp = 0;
	  pOMPropSet->iterate (omContext, pOmProp);
	  assert (pOmProp);
	  // count it if it's mandatory, or (optional AND present)
	  if (!pOmProp->isOptional() || pOmProp->isPresent())
		numPropsPresent++;
	}

  _count = numPropsPresent;

  _pProperties = new ImplAAFPropertySP [numPropsPresent];
  if (! _pProperties)
	return AAFRESULT_NOMEMORY;

  ImplAAFHeaderSP pHead;
  ImplAAFDictionarySP pDict;
  try
	{
	  AAFRESULT hr;
	  assert (pObj);
	  hr = pObj->MyHeadObject(&pHead);
	  if (AAFRESULT_OBJECT_NOT_ATTACHED == hr)
		{
		  // this must be the head object
		  pHead = dynamic_cast<ImplAAFHeader*>(pObj);
		  if (!pHead)
			throw AAFRESULT_OBJECT_NOT_ATTACHED;
		  // smart pointers don't require this
		  // pHead->AcquireReference();
		}
	  else
		{
		  if (AAFRESULT_FAILED(hr)) throw hr;
		}
	  assert (pHead);
	  hr = (pHead->GetDictionary(&pDict));
	  if (AAFRESULT_FAILED(hr)) throw hr;
	  assert (pDict);

	  size_t omContext = 0;
	  OMProperty * pOmProp = NULL;
	  aafUInt32 presentPropIdx = 0;
	  for (aafUInt32 definedPropIdx = 0;
		   definedPropIdx < numPropsDefined;
		   definedPropIdx++)
		{
		  pOMPropSet->iterate (omContext, pOmProp);
		  assert (pOmProp);
		  if (pOmProp->isOptional() && !pOmProp->isPresent())
			// optional property not present
			continue;

		  OMPropertyId opid = pOmProp->propertyId ();
		  assert (pDict);
		  AAFRESULT hr = pDict->LookupPropDefByOMPid (opid, &pPropDef);
		  if (AAFRESULT_FAILED (hr)) throw hr;
		  assert (pPropDef);

		  // Create property; array is smart pointers, which will
		  // maintain their own reference counts.  First assign new
		  // prop to temp, so we can release it after the sp
		  // assignment.
		  ImplAAFProperty * tmp = (ImplAAFProperty*) CreateImpl (CLSID_AAFProperty);
		  if (! tmp) 
			throw AAFRESULT_NOMEMORY;
		  _pProperties[presentPropIdx] = tmp;
		  tmp->ReleaseReference ();

		  hr = _pProperties[presentPropIdx]->Initialize (pPropDef, pOmProp);
		  if (AAFRESULT_FAILED (hr)) throw hr;

		  presentPropIdx++;
		  assert (presentPropIdx <= numPropsPresent);
		}
	  assert (presentPropIdx == numPropsPresent);
	}
  catch (AAFRESULT &rCaught)
	{
	  rReturned = rCaught;
	  if (_pProperties)
		{
		  delete[] _pProperties;
		  _pProperties = NULL;
		}
	}

  return rReturned;
}


ImplPropertyCollection::~ImplPropertyCollection ()
{
  if (_pProperties)
	{
	  delete[] _pProperties;
	  _pProperties = NULL;
	}
}


AAFRESULT ImplPropertyCollection::GetNumElements
(aafUInt32 * pCount)
{
  if (! pCount)
	return AAFRESULT_NULL_PARAM;
  *pCount = _count;
  return AAFRESULT_SUCCESS;
}

AAFRESULT ImplPropertyCollection::GetNthElement
(
 aafUInt32  index,
 ImplAAFProperty ** pElem
)
{
  if (! pElem)
	return AAFRESULT_NULL_PARAM;

  if (index >= _count)
	return AAFRESULT_NO_MORE_OBJECTS;

  assert (_pProperties);
  assert (_pProperties[index]);
  assert (pElem);
  *pElem = _pProperties[index];
  (*pElem)->AcquireReference();
  return AAFRESULT_SUCCESS;
}


ImplAAFObject::ImplAAFObject ()
  : _pProperties (0),
	_cachedDefinition (0),
	_OMPropsInited (AAFFalse)
{}


ImplAAFObject::~ImplAAFObject ()
{
  _cachedDefinition = 0; // we don't need to reference count this defintion

  if (_pProperties)
	delete _pProperties;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::SetGeneration (aafUID_t *  /*pGeneration*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetGeneration (aafUID_t *  /*pGeneration*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetDefinition (ImplAAFClassDef ** ppClassDef)
{
  if (! ppClassDef)
	return AAFRESULT_NULL_PARAM;

  if (! _cachedDefinition)
	{
	  AAFRESULT hr;
	  ImplAAFDictionarySP pDict;
	  hr = GetDictionary(&pDict);
	  if (AAFRESULT_FAILED (hr))
		return hr;
	  assert (pDict);

	  aafUID_t classID;
	  hr = GetObjectClass (&classID);
	  assert (AAFRESULT_SUCCEEDED (hr));

	  hr = pDict->LookupClass(&classID, &_cachedDefinition);
	  if (AAFRESULT_FAILED (hr))
		return hr;
	  assert (_cachedDefinition);
		
	  // We don't need to reference count the definitions since
	  // they are owned by the dictionary.
	  aafInt32 count = _cachedDefinition->ReleaseReference();
	  assert(0 < count);
	}
  assert (ppClassDef);
  *ppClassDef = _cachedDefinition;
  assert (*ppClassDef);
  (*ppClassDef)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::GetObjectClass (aafUID_t * pClass)
{
  if (NULL == pClass)
    return AAFRESULT_NULL_PARAM;

  //
  // Take advantage of the virtual method that 
  // returns the stored class id for a given class of OMStorable.
  //
#ifndef _DEBUG
  *pClass = *reinterpret_cast<const aafUID_t *>(&classId());
#else
  // In a debug build copy all of the fields separately so
  // that we can detect changes in the definitions of public aafUID_t
  // and private OMClassId types.
  const OMClassId& id = classId();
  pClass->Data1 = id.Data1;
  pClass->Data2 = id.Data2;
  pClass->Data3 = id.Data3;
  pClass->Data4[0] = id.Data4[0];
  pClass->Data4[1] = id.Data4[1];
  pClass->Data4[2] = id.Data4[2];
  pClass->Data4[3] = id.Data4[3];
  pClass->Data4[4] = id.Data4[4];
  pClass->Data4[5] = id.Data4[5];
  pClass->Data4[6] = id.Data4[6];
  pClass->Data4[7] = id.Data4[7];
#endif

  return AAFRESULT_SUCCESS;
}


AAFRESULT ImplAAFObject::InitProperties ()
{
  if (! _pProperties)
	{
	  _pProperties = new ImplPropertyCollection;
	  if (! _pProperties)
		return AAFRESULT_NOMEMORY;
	  OMPropertySet * ps = propertySet();
	  assert (ps);
	  AAFRESULT hr = _pProperties->Initialize (this, ps);
	  if (AAFRESULT_FAILED (hr)) return hr;
	}
  assert (_pProperties);
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::GetProperties (ImplEnumAAFProperties ** ppEnum)
{
  if (! ppEnum)
	return AAFRESULT_NULL_PARAM;

  if (! _pProperties)
	{
	  AAFRESULT hr = InitProperties();
	  if (! AAFRESULT_SUCCEEDED (hr)) return hr;
	}
  assert (_pProperties);
  
  ImplEnumAAFProperties * pEnum = NULL;
  pEnum = (ImplEnumAAFProperties*) CreateImpl (CLSID_EnumAAFProperties);
  if (! pEnum)
	return E_FAIL;
  assert (pEnum);
  
  AAFRESULT hr = pEnum->Initialize (_pProperties);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;
  
  assert (ppEnum);
  *ppEnum = pEnum;
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::CountProperties (aafUInt32 * pCount)
{
  if (! pCount)
	return AAFRESULT_NULL_PARAM;

  assert (pCount);
  if (! _pProperties)
	{
	  AAFRESULT hr = InitProperties();
	  if (! AAFRESULT_SUCCEEDED (hr)) return hr;
	}
  assert (_pProperties);
  AAFRESULT hr = _pProperties->GetNumElements (pCount);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::GetPropertyValue (ImplAAFPropertyDef * /*pPropDef*/,
									 ImplAAFPropertyValue ** /*ppPropVal*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::SetPropertyValue (ImplAAFPropertyDef * /*pPropDef*/,
									 ImplAAFPropertyValue * /*pPropVal*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
	ImplAAFObject::IsPropertyPresent (ImplAAFPropertyDef * /*pPropDef*/,
									  aafBool * /*pResult*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetStoredByteOrder (eAAFByteOrder_t *  /*pOrder*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetNativeByteOrder (eAAFByteOrder_t *  /*pOrder*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}

//************
// Interfaces ivisible inside the toolkit, but not exposed through the API

// Gets the head object of the file containing this object.
// This function is used to maintain MOB and Definition tables in the
// head object.
AAFRESULT ImplAAFObject::MyHeadObject
	(ImplAAFHeader **header) const
{
	OMFile			*myFile;
	OMStorable		*theRoot;
	ImplAAFHeader	*theHeader;

	XPROTECT()
	{
		if(header == NULL)
			RAISE(AAFRESULT_NULL_PARAM);

		if(!attached())
			RAISE(AAFRESULT_OBJECT_NOT_ATTACHED); 

                if(!inFile())
			RAISE(AAFRESULT_OBJECT_NOT_IN_FILE); 

		myFile = file();
		if(myFile == NULL)
			RAISE(AAFRESULT_OBJECT_NOT_IN_FILE);

		theRoot = myFile->root();
		if(theRoot == NULL)
			RAISE(AAFRESULT_BADHEAD);

		theHeader = dynamic_cast<ImplAAFHeader*>(theRoot);
		if(theRoot == NULL)
			RAISE(AAFRESULT_BADHEAD);
		theHeader->AcquireReference();

		*header = theHeader;
	}
	XEXCEPT
	XEND;

	return(AAFRESULT_SUCCESS);
}

// Gets the dictionary used to create this instance.
AAFRESULT STDMETHODCALLTYPE
ImplAAFObject::GetDictionary(ImplAAFDictionary **ppDictionary) const
{
  if(NULL == ppDictionary)
    return AAFRESULT_NULL_PARAM;

  *ppDictionary = dynamic_cast<ImplAAFDictionary *>(classFactory());
  assert(NULL != *ppDictionary);
  if (NULL == *ppDictionary)
    return AAFRESULT_INVALID_OBJ;
  
  // Bump the reference count...
  (*ppDictionary)->AcquireReference();
  
  return AAFRESULT_SUCCESS;
}


//
// Here is the mapping of DM type defs to OMProperty concrete
// classes.
//
// DM TypeDef				Treatment
// ----------				-------------------------
// AAFTypeDefEnum			FixedData(sizeof rep'd type)
//
// AAFTypeDefExtEnum		FixedData(sizeof auid)
//
// AAFTypeDefFixedArray     FixedData(sizeof elem * num elems)
//
// AAFTypeDefInt			FixedData(sizeof int)
//
// AAFTypeDefRecord         FixedData(sum of sizes of elements)
//
// AAFTypeDefRename         <refer to referenced type>
//
// AAFTypeDefSet:
//   if elem type is StrRef	OMStrongReferenceVectorProperty<AAFObject>
//   if elem type is WkRef  VariableData(sizeof auid)
//   if elem is fixed data  VariableData(sizeof elem)
//   else                   <not yet supported; maybe never!>
//
// AAFTypeDefStream			<not yet supported>
//
// AAFTypeDefString			VariableData(sizeof elem)
//
// AAFTypeDefStrongObjRef	OMStrongReferenceProperty<AAFObject>
//
// AAFTypeDefVariableArray
//   if elem type is StrRef	OMStrongReferenceVectorProperty<AAFObject>
// 	 if elem type is WkRef  VariableData(sizeof auid)
// 	 if elem is fixed data  VariableData(sizeof elem)
//   else                   <not yet supported; maybe never!>
//
// AAFTypeDefWeakObjRef     FixedData(sizeof auid)
//


//
// Private infrastructure to cache property values
//
struct propDefPair
{
  OMPropertyId         pid;
  ImplAAFPropertyDefSP pPropDef;
};

static const int kMaxProps = 100;

static void fillPropDefs (ImplAAFClassDef * pClassDef,
						  propDefPair * props,
						  aafUInt32 & numPropsFound)
{
  assert (pClassDef);
  assert (props);

  AAFRESULT hr;

  ImplEnumAAFPropertyDefsSP pEnum;
  hr = pClassDef->GetPropertyDefs (&pEnum);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (pEnum);

  ImplAAFPropertyDefSP pPropDef;
  hr = pEnum->NextOne (&pPropDef);
  while (AAFRESULT_SUCCEEDED (hr))
	{
	  props->pid = pPropDef->OmPid();
	  props->pPropDef = pPropDef;
	  assert (++numPropsFound <= kMaxProps);
	  hr = pEnum->NextOne (&pPropDef);
	  props++;
	}

  ImplAAFClassDefSP pParent;
  hr = pClassDef->GetParent (&pParent);
  assert (AAFRESULT_SUCCEEDED (hr));
  if (pParent)
	fillPropDefs (pParent, props, numPropsFound);
}


static ImplAAFPropertyDef * sLookupPropDefByOmpid (propDefPair * props,
												 aafUInt32 numProps,
												 OMPropertyId pidToLookup)
{
  assert (props);

  while (numProps--)
	{
	  if (pidToLookup == props->pid)
		return (ImplAAFPropertyDef*) props->pPropDef;
	  props++;
	}
  return 0;
}


void ImplAAFObject::InitOMProperties (void)
{
  if (_OMPropsInited)
	return;

  // Set this first to prevent calls below from re-attempting this
  // method.
  //
  _OMPropsInited = AAFTrue;

  //
  // We want to do two things.
  //
  // 1. Iterate across the properties in the classdef; for each one,
  //    see if there currently is an OMProperty to match it.  If not,
  //    allocate one.
  //
  // 2. Iterate across all existing OM properties.  For each one:
  //
  // 2a. See if this currently existing OM property is defined in the
  //     ClassDef, and the definition matches that of the property to
  //     the best of our ability to test.
  //
  // 2b. If the property is there (and it's an error caught in the
  //     previous stepif it isn't), then initialize it with whatever
  //     info we have at hand from the class definition.
  //

  AAFRESULT hr;

  // See if currently existing OM properties are defined in the class
  // def.
  //
  ImplAAFClassDefSP spDef;
  hr = GetDefinition (&spDef);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (spDef);

  propDefPair propDefs[kMaxProps];
  aafUInt32 numPropDefs = 0;
  fillPropDefs (spDef, propDefs, numPropDefs);
  assert (numPropDefs <= kMaxProps);

  OMPropertySet * ps = propertySet();
  assert (ps);
  const size_t propCount = ps->count();

  ImplAAFDictionarySP pDict;
  hr = GetDictionary(&pDict);
  assert (AAFRESULT_SUCCEEDED (hr));

  // Step 1: look through defined properties and see if there is an OM
  // prop to match each.
  ImplEnumAAFPropertyDefsSP pdEnumSP;

  ImplAAFPropertyDefSP pdSP;
#if 0 // BobT hack! comment this out to avoid some time-consuming
	  // stuff until we can profile and determine the culprit.
  hr = spDef->GetPropertyDefs (&pdEnumSP);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (pdEnumSP);
  while (AAFRESULT_SUCCEEDED (pdEnumSP->NextOne (&pdSP)))
	{
	  assert (pdSP);
	  OMPropertyId defPid = pdSP->OmPid ();
	  OMPropertyId propPid = defPid + 1; // make sure it's set to
										 // something different
	  size_t context = 0;
	  for (size_t i = 0; i < propCount; i++)
		{
		  OMProperty * pProp = 0;
		  ps->iterate (context, pProp);
		  assert (pProp);
		  propPid = pProp->propertyId ();
		  if (defPid == propPid)
			break;
		}
	  if (defPid != propPid)
		{
		  // Defined property wasn't found in OM property set.  We'll
		  // have to install one.

		  // Get type info for the prop to be installed
		  ImplAAFTypeDefSP ptd;
		  hr = pdSP->GetTypeDef (&ptd);
		  assert (AAFRESULT_SUCCEEDED (hr));
		  assert (ptd);

		  // Get the property name from the property def.
		  aafUInt32 wNameLen = 0;
		  hr = pdSP->GetNameBufLen (&wNameLen);
		  assert (AAFRESULT_SUCCEEDED (hr));
		  assert (wNameLen > 0);
		  aafCharacter * wNameBuf =
			(aafCharacter *) new aafUInt8[wNameLen];
		  assert (wNameBuf);
		  hr = pdSP->GetName (wNameBuf, wNameLen);
		  assert (AAFRESULT_SUCCEEDED (hr));

		  // Create the property with the given name.
		  OMProperty * pNewProp =
			ptd->pvtCreateOMProperty (defPid, wNameBuf);
		  // Bobt hack! this assertion was removed when optional
		  // properties were put into service...
		  //
		  // assert (pNewProp->bitsSize ());
		  delete[] wNameBuf;

		  // Add the property to the property set.
		  ps->put (pNewProp);
		}
	}
#endif // 0
  // Step 2: look through OM properties.  2a. See if each is defined
  // in the class def.  It's an error if it isn't. 2b. Initialize it
  // with any info we can.
  size_t context = 0;
  for (size_t i = 0; i < propCount; i++)
	{
	  OMProperty * pProp = 0;
	  ps->iterate (context, pProp);
	  assert (pProp);
	  OMPropertyId opid = pProp->propertyId ();

	  pdSP = sLookupPropDefByOmpid (propDefs, numPropDefs, opid);
	  // The following assertion will fail if the property is not
	  // defined in the class definition for this object.
	  assert (pdSP);

	  ImplAAFTypeDefSP ptd;
	  hr = pdSP->GetTypeDef (&ptd);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  assert (ptd);

	  // The only info we can compare is sizes of properties.  Let's
	  // make sure they match.
	  size_t omPropSize  = pProp->bitsSize ();
	  // Hack!  We don't think internalsize() actually needs the
	  // pointer to bits, so we'll pass zero since bits ptr is
	  // difficult to get.
	  size_t definedSize = ptd->internalSize (0, omPropSize);

	  // If the assertion below fails, try un-commenting the lines
	  // which follow it to find out which property is defined with
	  // the wrong size.  You'll also have to add an include to
	  // iostream.h .  Be sure to reinstate the comments, and remove
	  // the include<iostream.h> before you check in any changes!
	  assert (definedSize == omPropSize);
	  /*
	  if (definedSize != omPropSize)
		{
		  cerr << "Property size error: "
			   <<   "pid=0x"         << hex << opid
			   << ", definedSize=0x" << hex << definedSize
			   << ", omPropSize=0x"  << hex << omPropSize
			   << endl;
		}
	  */

	  // Fill in other OMProp info that the property def can offer.
	  // Specifically, the property type, and 'optionality'.
	  assert (pProp);
	  const char * propName = pProp->name ();
	  assert (propName);
	  aafBool isOptional;
	  hr = pdSP->GetIsOptional (&isOptional);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  pProp->initialize (opid,
						 propName,
						 ptd,
						 isOptional ? true : false);
	}
}


//
// Define the symbol for the stored object id
//
OMDEFINE_STORABLE(ImplAAFObject, AUID_AAFObject)
