/***********************************************************************
*
*              Copyright (c) 1998-1999 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying 
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted, 
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
*  prior written permission of Avid Technology, Inc.
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

#ifndef __ImplAAFTypeDefSet_h__
#include "ImplAAFTypeDefSet.h"
#endif


#ifndef __ImplAAFPropertyValue_h__
#include "ImplAAFPropertyValue.h"
#endif

#ifndef __ImplAAFPropValData_h__
#include "ImplAAFPropValData.h"
#endif

#ifndef __ImplEnumAAFPropertyValues_h__
#include "ImplEnumAAFPropertyValues.h"
#endif




#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"
#include "ImplAAFTypeDefObjectRef.h"
#include "ImplAAFObjectCreation.h"


#include <assert.h>
#include <string.h>

// Weak references may not be in v1.0...
#ifndef ENABLE_TYPE_DEF_SET
#define ENABLE_TYPE_DEF_SET 0
#endif

extern "C" const aafClassID_t CLSID_AAFPropValData;

ImplAAFTypeDefSet::ImplAAFTypeDefSet () :
_ElementType  ( PID_TypeDefinitionSet_ElementType, 
			   L"ElementType", 
			   L"/Dictionary/TypeDefinitions", 
			   PID_MetaDefinition_Identification)
{
	_persistentProperties.put(_ElementType.address());
}


ImplAAFTypeDefSet::~ImplAAFTypeDefSet ()
{}

AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::Initialize (
      aafUID_constref  id,
      ImplAAFTypeDef * pTypeDef,
      aafCharacter_constptr  pTypeName)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (! pTypeName) 
		return AAFRESULT_NULL_PARAM;
	if (! pTypeDef)
		return AAFRESULT_NULL_PARAM;
	
	//
	// TBD: Validate that the given type definition exists in the
	// dictionary.
	//
	
	return pvtInitialize(id, pTypeDef, pTypeName);
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::pvtInitialize (
								  aafUID_constref  id,
								  ImplAAFTypeDef * pTypeDef,
								  aafCharacter_constptr  pTypeName)
{
#ifndef ENABLE_TYPE_DEF_SET
	ImplAAFTypeDefObjectRef	*objRef;
	AAFRESULT				result;
	
	if (! pTypeName) 
		return AAFRESULT_NULL_PARAM;
	if (! pTypeDef)
		return AAFRESULT_NULL_PARAM;
	
	
	// JeffB: only allow strong and weak references to objects
	objRef = dynamic_cast<ImplAAFTypeDefObjectRef*>(pTypeDef);
	if(objRef == NULL)
		result = AAFRESULT_ELEMENT_NOT_OBJECT;
	else
	{
		result = ImplAAFMetaDefinition::Initialize(id, pTypeName, NULL);
		if (AAFRESULT_SUCCEEDED(result))
		{
			_ElementType = pTypeDef;
		}
	}
	return result;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::GetElementType (
							ImplAAFTypeDef ** ppTypeDef)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (! ppTypeDef)
		return AAFRESULT_NULL_PARAM;
	
	if(_ElementType.isVoid())
		return AAFRESULT_OBJECT_NOT_FOUND;
	
	*ppTypeDef = _ElementType;
	assert (*ppTypeDef);
	
	(*ppTypeDef)->AcquireReference ();
	
	return AAFRESULT_SUCCESS;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::AddElement (
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplAAFPropertyValue * pElementPropertyValue)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pElementPropertyValue)
		return AAFRESULT_NULL_PARAM;

  return AAFRESULT_NOT_IMPLEMENTED;

#if 0
	if (!pInPropVal)
		return AAFRESULT_NULL_PARAM;
	if (!pMemberPropVal)
		return AAFRESULT_NULL_PARAM;
	
	AAFRESULT hr;
	
	ImplAAFPropValData* inPvd =
		dynamic_cast<ImplAAFPropValData*> (pInPropVal);
	assert (inPvd);
	
	ImplAAFPropValData* memPvd =
		dynamic_cast<ImplAAFPropValData*> (pMemberPropVal);
	assert (memPvd);
	
	aafUInt32 oldSize = 0;
	hr = inPvd->GetBitsSize (&oldSize);
	assert (AAFRESULT_SUCCEEDED (hr));
	
	aafUInt32 newElemSize = 0;
	hr = memPvd->GetBitsSize (&newElemSize);
	assert (AAFRESULT_SUCCEEDED (hr));
	
	aafUInt32 newSize = oldSize + newElemSize;
	assert (newSize);
	// sizeof (*buf) must be 1
	aafUInt8* buf = new aafUInt8[newSize];
	assert (buf);
	
	aafMemPtr_t pBits = 0;
	
	// Copy old bits into our buffer
	if (oldSize)
	{
		pBits = 0;
		hr = inPvd->GetBits (&pBits);
		assert (AAFRESULT_SUCCEEDED (hr));
		assert (pBits);
		memcpy (buf, pBits, oldSize);
	}
	
	// Append new prop val onto end of our buffer
	pBits = 0;
	hr = memPvd->GetBits (&pBits);
	assert (AAFRESULT_SUCCEEDED (hr));
	assert (pBits);
	// Following ptr addition depends on buf being a byte pointer
	memcpy (buf+oldSize, pBits, newElemSize);
	
	// Re-allocate prop val bits to hold newly expanded data
	pBits = 0;
	hr = inPvd->AllocateBits (newSize, &pBits);
	assert (AAFRESULT_SUCCEEDED (hr));
	assert (pBits);
	memcpy (pBits, buf, newSize);
	
	delete[] buf;
	return AAFRESULT_SUCCESS;
#endif // #if 0
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::RemoveElement(
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplAAFPropertyValue * pElementPropertyValue)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pElementPropertyValue)
		return AAFRESULT_NULL_PARAM;

  return AAFRESULT_NOT_IMPLEMENTED;

#if 0
	if (!pInPropVal)
		return AAFRESULT_NULL_PARAM;
	if (!pMemberPropVal)
		return AAFRESULT_NULL_PARAM;
	
	AAFRESULT	hr;
	bool		found;
	aafUInt32	numElem, n;
	
	ImplAAFPropValData* inPvd =
		dynamic_cast<ImplAAFPropValData*> (pInPropVal);
	assert (inPvd);
	
	ImplAAFPropValData* memPvd =
		dynamic_cast<ImplAAFPropValData*> (pMemberPropVal);
	assert (memPvd);
	
	aafUInt32 oldSize = 0;
	hr = inPvd->GetBitsSize (&oldSize);
	assert (AAFRESULT_SUCCEEDED (hr));
	
	aafUInt32 newElemSize = 0;
	hr = memPvd->GetBitsSize (&newElemSize);
	assert (AAFRESULT_SUCCEEDED (hr));
	
	aafMemPtr_t pPropBits = 0, pMemberBits = 0, pDestBits = 0, srcPtr;
	
	// Copy old bits into our buffer
	if (oldSize)
	{
		pPropBits = 0;
		hr = inPvd->GetBits (&pPropBits);
		assert (AAFRESULT_SUCCEEDED (hr));
		assert (pPropBits);
		
		pMemberBits = 0;
		hr = memPvd->GetBits (&pMemberBits);
		assert (AAFRESULT_SUCCEEDED (hr));
		assert (pMemberBits);
		
		numElem = oldSize / newElemSize;
		found = false;
		for(n = 0, srcPtr = pPropBits; n < numElem && !found; n++, srcPtr += newElemSize)
		{
			if(memcmp(srcPtr, pMemberBits, newElemSize) == 0)
			{
				found = true;
				aafUInt32 newSize = oldSize - newElemSize;
				assert (newSize);
				aafUInt32	beforeBytes, afterBytes;
				// sizeof (*buf) must be 1
				aafUInt8* buf = new aafUInt8[newSize];
				assert (buf);
				// Following ptr addition depends on buf being a byte pointer
				beforeBytes = srcPtr-pPropBits;
				afterBytes = newSize - beforeBytes;
				memcpy (buf, pPropBits, beforeBytes);
				memcpy (buf+beforeBytes, pPropBits+beforeBytes+newElemSize, afterBytes);
				
				// Re-allocate prop val bits to hold newly deflated data
				pDestBits = 0;
				hr = inPvd->AllocateBits (newSize, &pDestBits);
				assert (AAFRESULT_SUCCEEDED (hr));
				assert (pDestBits);
				memcpy (pDestBits, buf, newSize);
				
				delete[] buf;
			}
		}
	}
	else
		found = false;
	
	if(found)
		return AAFRESULT_SUCCESS;
	else
		return AAFRESULT_ELEMENT_NOT_PRESENT;
#endif // #if 0
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}

//****************
// ContainsElement()
//
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::ContainsElement(
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplAAFPropertyValue * pElementPropertyValue,
      aafBoolean_t*  pContainsElement)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pElementPropertyValue || !pContainsElement)
		return AAFRESULT_NULL_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefSet::GetCount (
      ImplAAFPropertyValue * pSetPropertyValue,
      aafUInt32 *  pCount)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pCount)
		return AAFRESULT_NULL_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;

#if 0
	ImplAAFTypeDefSP ptd;
	AAFRESULT hr;
	
	if (! pPropVal) return AAFRESULT_NULL_PARAM;
	if (! pCount) return AAFRESULT_NULL_PARAM;
	// Bobt semi-hack: need non-const this in order to call
	// non-const GetType. We know we aren't mangling it, so it
	// technically is OK...
	ImplAAFTypeDefSet * pNonConstThis = (ImplAAFTypeDefSet *) this;
	hr = pNonConstThis->GetElementType (&ptd);
	if (AAFRESULT_FAILED(hr)) return hr;
	assert (ptd);
	assert (ptd->IsFixedSize());
	aafUInt32 elemSize = ptd->PropValSize();
	aafUInt32 propSize;
	assert (pPropVal);
	
	ImplAAFPropValDataSP pvd;
	pvd = dynamic_cast<ImplAAFPropValData *>(pPropVal);
	
	assert (pvd);
	hr = pvd->GetBitsSize (&propSize);
	if (AAFRESULT_FAILED(hr)) return hr;
	assert (pCount);
	*pCount = propSize / elemSize;
	
	return AAFRESULT_SUCCESS;
#endif // #if 0
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}



//***********************************************************
// CreateKey()
//
AAFRESULT ImplAAFTypeDefSet::CreateKey (
      aafDataBuffer_t  pKeyPtr,
      aafUInt32  length,
      ImplAAFPropertyValue ** ppKey)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pKeyPtr || !ppKey)
		return AAFRESULT_NULL_PARAM;
	if (0 == length)
	  return AAFRESULT_INVALID_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;

#if 0
	AAFRESULT	hr;
	aafMemPtr_t	theBits;
	
	ImplAAFPropValData	*result = (ImplAAFPropValData*) CreateImpl (CLSID_AAFPropValData);
	if (!result)
		return AAFRESULT_NOMEMORY;
	hr = result->AllocateBits (pLength, &theBits);
	if(hr == AAFRESULT_SUCCESS)
	{
		memcpy(theBits, pKeyPtr, pLength);
	}
	
	return hr;
#endif // #if 0
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}


//***********************************************************
// LookupElement()
//
AAFRESULT ImplAAFTypeDefSet::LookupElement (
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplAAFPropertyValue * pKey,
      ImplAAFPropertyValue ** ppElementPropertyValue)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pKey || !ppElementPropertyValue)
		return AAFRESULT_NULL_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}

//***********************************************************
// ContainsKey()
//
AAFRESULT ImplAAFTypeDefSet::ContainsKey (
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplAAFPropertyValue * pKey,
      aafBoolean_t*  pContainsKey)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !pKey || !pContainsKey)
		return AAFRESULT_NULL_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}


AAFRESULT
ImplAAFTypeDefSet::GetElements (
      ImplAAFPropertyValue * pSetPropertyValue,
      ImplEnumAAFPropertyValues ** ppEnum)
{
#ifndef ENABLE_TYPE_DEF_SET
	if (!pSetPropertyValue || !ppEnum)
		return AAFRESULT_NULL_PARAM;

	return AAFRESULT_NOT_IMPLEMENTED;
#else // #if ENABLE_TYPE_DEF_SET
    
  return AAFRESULT_NOT_IN_CURRENT_VERSION;
    
#endif // #else // #if ENABLE_TYPE_DEF_SET
}


bool ImplAAFTypeDefSet::IsAggregatable () const
{ return false; }

bool ImplAAFTypeDefSet::IsStreamable () const
{ return false; }

bool ImplAAFTypeDefSet::IsFixedArrayable () const
{ return false; }

bool ImplAAFTypeDefSet::IsVariableArrayable () const
{ return false; }

bool ImplAAFTypeDefSet::IsStringable () const
{ return false; }






// override from OMStorable.
const OMClassId& ImplAAFTypeDefSet::classId(void) const
{
	return (*reinterpret_cast<const OMClassId *>(&AUID_AAFTypeDefSet));
}

// Override callbacks from OMStorable
void ImplAAFTypeDefSet::onSave(void* clientContext) const
{
	ImplAAFTypeDef::onSave(clientContext);
}

void ImplAAFTypeDefSet::onRestore(void* clientContext) const
{
	ImplAAFTypeDef::onRestore(clientContext);
}
