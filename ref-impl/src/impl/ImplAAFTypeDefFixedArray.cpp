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
#include "AAFStoredObjectIDs.h"

#ifndef __ImplAAFTypeDefFixedArray_h__
#include "ImplAAFTypeDefFixedArray.h"
#endif

#ifndef __ImplAAFPropertyValue_h__
#include "ImplAAFPropertyValue.h"
#endif

#ifndef __ImplAAFHeader_h_
#include "ImplAAFHeader.h"
#endif

#include "AAFPropertyIDs.h"
#include "ImplAAFObjectCreation.h"

#include <assert.h>
#include <string.h>

extern "C" const aafClassID_t CLSID_AAFPropertyValue;


ImplAAFTypeDefFixedArray::ImplAAFTypeDefFixedArray ()
  : _ElementType  ( PID_TypeDefinitionFixedArray_ElementType,  "Element Type"),
    _ElementCount ( PID_TypeDefinitionFixedArray_ElementCount, "Element Count")
{
  _persistentProperties.put(_ElementType.address());
  _persistentProperties.put(_ElementCount.address());
}


ImplAAFTypeDefFixedArray::~ImplAAFTypeDefFixedArray ()
{}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefFixedArray::GetType (
      ImplAAFTypeDef ** ppTypeDef) const
{
  if (! ppTypeDef) return AAFRESULT_NULL_PARAM;

  if (!_cachedBaseType)
	{
	  ImplAAFTypeDefFixedArray * pNonConstThis =
		  (ImplAAFTypeDefFixedArray *) this;

	  // Make sure this is already done!
	  pNonConstThis->InitOMProperties ();

	  ImplAAFDictionarySP pDict;

	  AAFRESULT hr;
	  hr = GetDictionary(&pDict);
	  if (AAFRESULT_FAILED(hr))
		return hr;
	  assert (pDict);

	  aafUID_t id = _ElementType;
	  hr = pDict->LookupType (&id, &pNonConstThis->_cachedBaseType);
	  if (AAFRESULT_FAILED(hr))
		return hr;
	  assert (_cachedBaseType);
	}
  assert (ppTypeDef);
  *ppTypeDef = _cachedBaseType;
  assert (*ppTypeDef);
  (*ppTypeDef)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
   ImplAAFTypeDefFixedArray::Initialize (
      const aafUID_t *  pID,
      ImplAAFTypeDef * pTypeDef,
      aafUInt32  nElements,
      wchar_t *  pTypeName)
{
  if (! pTypeName) return AAFRESULT_NULL_PARAM;
  if (! pTypeDef)  return AAFRESULT_NULL_PARAM;
  if (! pID)       return AAFRESULT_NULL_PARAM;

  HRESULT hr;

  hr = SetName (pTypeName);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;

  hr = SetAUID (pID);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;

  aafUID_t id;
  assert (pTypeDef);
  hr = pTypeDef->GetAUID(&id);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;
  _ElementType = id;

  _ElementCount = nElements;

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefFixedArray::GetCount (
      aafUInt32 *  pCount) const
{
  if (! pCount) return AAFRESULT_NULL_PARAM;
  *pCount = _ElementCount;
  return AAFRESULT_SUCCESS;
}


// Override from AAFTypeDef
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefFixedArray::GetTypeCategory (eAAFTypeCategory_t *  pTid)
{
  if (!pTid) return AAFRESULT_NULL_PARAM;
  *pTid = kAAFTypeCatFixedArray;
  return AAFRESULT_SUCCESS;
}


aafUInt32 ImplAAFTypeDefFixedArray::pvtCount
(
 ImplAAFPropertyValue * /*pInPropVal*/ /*arg unused*/
) const
{
  return _ElementCount;
}


ImplAAFTypeDefSP ImplAAFTypeDefFixedArray::BaseType (void) const
{
  ImplAAFTypeDefSP result;
  AAFRESULT hr = GetType (&result);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (result);
  return result;
}


void ImplAAFTypeDefFixedArray::reorder(OMByte* externalBytes,
									   size_t externalBytesSize) const
{
  aafUInt32 numElems = _ElementCount;
  aafUInt32 elem = 0;

  ImplAAFTypeDefSP ptd = BaseType ();
  aafUInt32 elemSize = ptd->NativeSize ();
  aafInt32 numBytesLeft = externalBytesSize;

  for (elem = 0; elem < numElems; elem++)
	{
	  ptd->reorder (externalBytes, elemSize);
	  externalBytes += elemSize;
	  numBytesLeft -= elemSize;
	  assert (numBytesLeft >= 0);
	}
}


size_t ImplAAFTypeDefFixedArray::externalSize(OMByte* /*internalBytes*/,
											  size_t /*internalBytesSize*/) const
{
  ImplAAFTypeDefSP ptd = BaseType ();
  size_t result = _ElementCount * ptd->externalSize (0, 0);
  return result;
}


void ImplAAFTypeDefFixedArray::externalize(OMByte* internalBytes,
										   size_t internalBytesSize,
										   OMByte* externalBytes,
										   size_t externalBytesSize,
										   OMByteOrder byteOrder) const
{
  aafUInt32 numElems = _ElementCount;
  aafUInt32 elem = 0;

  ImplAAFTypeDefSP ptd = BaseType ();
  aafUInt32 internalSize = ptd->NativeSize ();
  aafUInt32 externalSize = ptd->PropValSize ();
  if (internalSize == externalSize)
	{
	  copy (internalBytes,
			externalBytes,
			externalBytesSize);
	}
  else
	{
	  aafInt32 internalBytesLeft = internalBytesSize;
	  aafInt32 externalBytesLeft = externalBytesSize;

	  for (elem = 0; elem < numElems; elem++)
		{
		  ptd->externalize (internalBytes,
							internalSize,
							externalBytes,
							externalSize,
							byteOrder);
		  internalBytes += internalSize;
		  externalBytes += externalSize;
		  internalBytesLeft -= internalSize;
		  externalBytesLeft -= externalSize;
		  assert (internalBytesLeft >= 0);
		  assert (externalBytesLeft >= 0);
		}
	}
}


size_t ImplAAFTypeDefFixedArray::internalSize(OMByte* /*externalBytes*/,
											  size_t /*externalBytesSize*/) const
{
  ImplAAFTypeDefSP ptd = BaseType ();
  size_t result = _ElementCount * ptd->internalSize (0, 0);
  return result;
}


void ImplAAFTypeDefFixedArray::internalize(OMByte* externalBytes,
										   size_t externalBytesSize,
										   OMByte* internalBytes,
										   size_t internalBytesSize,
										   OMByteOrder byteOrder) const
{
  aafUInt32 numElems = _ElementCount;
  aafUInt32 elem = 0;

  ImplAAFTypeDefSP ptd = BaseType ();
  aafUInt32 internalElemSize = ptd->internalSize (0, 0);
  aafUInt32 externalElemSize = ptd->externalSize (0, 0);
  if (internalElemSize == externalElemSize)
	{
	  copy (externalBytes,
			internalBytes,
			internalBytesSize);
	}
  else
	{
	  aafInt32 internalBytesLeft = internalBytesSize;
	  aafInt32 externalBytesLeft = externalBytesSize;

	  for (elem = 0; elem < numElems; elem++)
		{
		  ptd->internalize (externalBytes,
							externalElemSize,
							internalBytes,
							internalElemSize,
							byteOrder);
		  internalBytes += internalElemSize;
		  externalBytes += externalElemSize;
		  internalBytesLeft -= internalElemSize;
		  externalBytesLeft -= externalElemSize;
		  assert (internalBytesLeft >= 0);
		  assert (externalBytesLeft >= 0);
		}
	}
}


aafBool ImplAAFTypeDefFixedArray::IsFixedSize (void) const
{
  return BaseType()->IsFixedSize();
}

size_t ImplAAFTypeDefFixedArray::PropValSize (void) const
{
  return (BaseType()->PropValSize()) * _ElementCount;
}


aafBool ImplAAFTypeDefFixedArray::IsRegistered (void) const
{
  return BaseType()->IsRegistered();
}


size_t ImplAAFTypeDefFixedArray::NativeSize (void) const
{
  assert (IsRegistered());

  size_t result;
  ImplAAFTypeDefSP elemType;
  elemType = BaseType ();
  assert (elemType);
  result = elemType->NativeSize() * _ElementCount;
  return result;
}


OMProperty * ImplAAFTypeDefFixedArray::pvtCreateOMPropertyMBS
  (OMPropertyId pid,
   const char * name) const
{
  assert (name);
  size_t elemSize = PropValSize ();
  OMProperty * result = new OMSimpleProperty (pid, name, elemSize);
  assert (result);
  return result;
}


OMDEFINE_STORABLE(ImplAAFTypeDefFixedArray, AUID_AAFTypeDefFixedArray);
