//=---------------------------------------------------------------------=
//
// $Id: ImplAAFTypeDefRecord.cpp,v 1.46 2005/11/02 22:14:36 rodrigc Exp $ $Name:  $
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

#ifndef __ImplAAFTypeDefRecord_h__
#include "ImplAAFTypeDefRecord.h"
#endif

#ifndef __ImplAAFPropValData_h__
#include "ImplAAFPropValData.h"
#endif

#ifndef __ImplEnumAAFPropertyValues_h__
#include "ImplEnumAAFPropertyValues.h"
#endif

#ifndef __ImplAAFDictionary_h__
#include "ImplAAFDictionary.h"
#endif

#ifndef __ImplAAFTypeDefExtEnum_h__
#include "ImplAAFTypeDefExtEnum.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"
#include "ImplAAFObjectCreation.h"

#include <assert.h>
#include <string.h>
#include <wchar.h>

extern "C" const aafClassID_t CLSID_AAFPropValData;

ImplAAFTypeDefRecord::ImplAAFTypeDefRecord ()
  : _memberTypes ( PID_TypeDefinitionRecord_MemberTypes, 
                   L"MemberTypes", 
                   L"/MetaDictionary/TypeDefinitions", 
                   PID_MetaDefinition_Identification),
    _memberNames ( PID_TypeDefinitionRecord_MemberNames, 
                   L"MemberNames"),
	_registeredOffsets (0),
	_registeredSize (0),
	_internalSizes (0),
	_cachedMemberTypes (0),
	_cachedCount ((aafUInt32) -1),
	_registrationAttempted (kAAFFalse),
	_defaultRegistrationUsed (kAAFFalse)
{
  _persistentProperties.put(_memberTypes.address());
  _persistentProperties.put(_memberNames.address());
}


ImplAAFTypeDefRecord::~ImplAAFTypeDefRecord ()
{
  if (_registeredOffsets)
	delete[] _registeredOffsets;

  if (_internalSizes)
	delete[] _internalSizes;

  // these weren't ref counted here
  if (_cachedMemberTypes)
	delete[] _cachedMemberTypes;
}


void ImplAAFTypeDefRecord::pvtInitInternalSizes (void) const
{
  if (_internalSizes)
	return;

  ImplAAFTypeDefRecord * pNonConstThis =
	  (ImplAAFTypeDefRecord*) this;
  AAFRESULT hr;
  aafUInt32 count = 0;
  hr = GetCount(&count);
  assert (AAFRESULT_SUCCEEDED (hr));

  pNonConstThis->_internalSizes = new aafUInt32[count];
  assert(_internalSizes);

  aafUInt32 i;

  for (i = 0; i < count; i++)
	{
	  ImplAAFTypeDefSP ptd;
	  hr = pNonConstThis->GetMemberType (i, &ptd);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  assert (ptd);
	  _internalSizes[i] = ptd->PropValSize ();
	}
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::Initialize (
      const aafUID_t & id,
      ImplAAFTypeDef ** ppMemberTypes,
      aafString_t * pMemberNames,
      aafUInt32 numMembers,
      const aafCharacter * pTypeName)
{
  if (isInitialized ()) return AAFRESULT_ALREADY_INITIALIZED;

  if (!ppMemberTypes && !pMemberNames && !pTypeName)
    return AAFRESULT_NULL_PARAM;

  AAFRESULT hr;

  hr = ImplAAFMetaDefinition::Initialize(id, pTypeName, NULL);
  if (AAFRESULT_FAILED (hr))
    return hr;

  _cachedCount = numMembers;

  aafUInt32 i;
  aafUInt32 totalNameSize = 0;
  for (i = 0; i < numMembers; i++)
	{
	  if ( !pMemberNames[i])
		return AAFRESULT_NULL_PARAM;
	  if ( !ppMemberTypes[i])
		return AAFRESULT_NULL_PARAM;
	  if (! ppMemberTypes[i]->IsAggregatable())
		return AAFRESULT_BAD_TYPE;

	  // Check if specified type definition is in the dictionary.
	  if( !aafLookupTypeDef( this, ppMemberTypes[i] ) )
		return AAFRESULT_TYPE_NOT_FOUND;

	  totalNameSize += (wcslen (pMemberNames[i]) + 1);
	}

  if ((totalNameSize * sizeof(aafCharacter)) > OMPROPERTYSIZE_MAX)
	return AAFRESULT_BAD_SIZE;

  aafCharacter * namesBuf = new aafCharacter[totalNameSize];
  if (!namesBuf)
	return AAFRESULT_NOMEMORY;
  // make it an empty string
  *namesBuf = 0;
  aafCharacter * tmpNamePtr = namesBuf;

  assert (0 == _memberTypes.count());
//  aafUID_t * buf = new aafUID_t[numMembers];
//  if (!buf)
//  {
//    delete[] namesBuf;
///    return AAFRESULT_NOMEMORY;
//  }
  for (i = 0; i < numMembers; i++)
	{
	  assert (ppMemberTypes[i]);
	  _memberTypes.insertAt(ppMemberTypes[i], i);
//	  aafUID_t typeUID;
//	  AAFRESULT hr = ppMemberTypes[i]->GetAUID(&typeUID);
//	  assert (AAFRESULT_SUCCEEDED(hr));
//   if (AAFRESULT_FAILED(hr))
//   {
//      delete[] buf;
//    delete[] namesBuf;
//      return hr;
//    }
//	  buf[i] = typeUID;

	  assert (pMemberNames[i]);
	  wcscpy(tmpNamePtr, pMemberNames[i]);
	  // +1 to go past embedded null
	  tmpNamePtr += wcslen (pMemberNames[i]) + 1;
	}
//  _memberTypes.setValue(buf, numMembers*sizeof(aafUID_t));
//  delete[] buf;
  _memberNames.setValue (namesBuf, totalNameSize * sizeof(aafCharacter));
  delete[] namesBuf;

  setInitialized ();

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::pvtInitialize (
      const aafUID_t & id,
      ImplAAFTypeDef ** pMemberTypes,
      aafString_t * pMemberNames,
      aafUInt32 numMembers,
      const aafCharacter * pTypeName)
{
  if (!pMemberTypes && !pMemberNames && !pTypeName)
    return AAFRESULT_NULL_PARAM;

  AAFRESULT hr;

  hr = ImplAAFMetaDefinition::Initialize(id, pTypeName, NULL);
	if (AAFRESULT_FAILED (hr))
    return hr;

  _cachedCount = numMembers;

  aafUInt32 i;
  aafUInt32 totalNameSize = 0;
  for (i = 0; i < numMembers; i++)
	{
	  if ( !pMemberNames[i])
		return AAFRESULT_NULL_PARAM;
	  if ( !pMemberTypes[i])
		return AAFRESULT_NULL_PARAM;

	  totalNameSize += (wcslen (pMemberNames[i]) + 1);
	}

  aafCharacter * namesBuf = new aafCharacter[totalNameSize];
  if (!namesBuf)
	return AAFRESULT_NOMEMORY;
  // make it an empty string
  *namesBuf = 0;
  aafCharacter * tmpNamePtr = namesBuf;

  assert (0 == _memberTypes.count());
//  aafUID_t * buf = new aafUID_t[numMembers];
//  if (!buf)
//  {
 //   delete[] namesBuf;
 //   return AAFRESULT_NOMEMORY;
//  }
  for (i = 0; i < numMembers; i++)
	{
//	  buf[i] = *pMemberTypeIDs[i];
	  _memberTypes.insertAt(pMemberTypes[i], i);

	  wcscpy(tmpNamePtr, pMemberNames[i]);
	  // +1 to go past embedded null
	  tmpNamePtr += wcslen (pMemberNames[i]) + 1;
	}
//  _memberTypes.setValue(buf, numMembers*sizeof(aafUID_t));
 // delete[] buf;
  _memberNames.setValue (namesBuf, totalNameSize * sizeof(aafCharacter));
  delete[] namesBuf;

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetMemberType (
      aafUInt32 index,
      ImplAAFTypeDef ** ppTypeDef)
{
  AAFRESULT hr;
  aafUInt32 count;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (!ppTypeDef) return AAFRESULT_NULL_PARAM;
  
  hr = GetCount(&count);
  if (AAFRESULT_FAILED(hr)) return hr;

  if (index >= count) return AAFRESULT_ILLEGAL_VALUE;

  if (! _cachedMemberTypes)
	{
	  _cachedMemberTypes = new ImplAAFTypeDef *[count];
	  if (! _cachedMemberTypes)
		return AAFRESULT_NOMEMORY;
	  aafUInt32 i;
	  for (i = 0; i < count; i++)
		_cachedMemberTypes[i] = 0;
	}

  if (! _cachedMemberTypes[index])
	{
	  ImplAAFTypeDef *pMemberType;
	  pMemberType = bootstrapTypeWeakReferenceVectorElement(_memberTypes, index);

//	  ImplAAFDictionarySP pDict;
//	  hr = GetDictionary (&pDict);
//	  assert (AAFRESULT_SUCCEEDED(hr));
//	  assert (pDict);
//	  hr = pDict->LookupTypeDef (memberUID, &pMemberType);
//	  assert (AAFRESULT_SUCCEEDED(hr));
	  assert (pMemberType);
	  _cachedMemberTypes[index] = pMemberType;
	}
  assert (ppTypeDef);
  *ppTypeDef = _cachedMemberTypes[index];
  assert (*ppTypeDef);
  (*ppTypeDef)->AcquireReference();
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetMemberName (
      aafUInt32 index,
      aafCharacter * pName,
      aafUInt32  bufSize)
{
  AAFRESULT hr;
  aafUInt32 count;
  aafUInt32 indexIntoProp;
  aafUInt32 currentIndex;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (!pName) return AAFRESULT_NULL_PARAM;
  
  hr = GetCount(&count);
  if (AAFRESULT_FAILED(hr)) return hr;

  if (index >= count) return AAFRESULT_ILLEGAL_VALUE;

  aafUInt32 requiredSize;
  hr = GetMemberNameBufLen (index, &requiredSize);
  if (AAFRESULT_FAILED (hr))
	return hr;
  if (bufSize < requiredSize)
	return AAFRESULT_SMALLBUF;

  aafCharacter c;
  size_t numChars = _memberNames.count();
  indexIntoProp = 0;
  currentIndex = 0;
  if (0 != index)
	{
	  for (size_t i = 0; i < numChars; i++)
		{
		  indexIntoProp++;
		  _memberNames.getValueAt(&c, i);
		  if (0 == c)
			{
			  // We've found the null just before the string we want.
			  // We'll increment the indexIntoProp to the start of the
			  // string and break out of the loop, but first make sure
			  // there's more string there to index into.
			  assert (i < numChars);
			  currentIndex++;
			  if (index == currentIndex)
				  break;
			}
		}
	  // Make sure we didn't terminate the loop by dropping out before
	  // the correct index was found.
	  assert (indexIntoProp < numChars);
	}

  // indexIntoProp now indicates the starting char we want.  Copy it
  // into the client's buffer.
  do
	{
	  _memberNames.getValueAt(&c, indexIntoProp++);
	  *pName++ = c;
	}
  while (c);
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetMemberNameBufLen (
      aafUInt32  index,
      aafUInt32 * pLen)
{
  AAFRESULT hr;
  aafUInt32 count;
  aafUInt32 indexIntoProp;
  aafUInt32 currentIndex;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (!pLen) return AAFRESULT_NULL_PARAM;
  
  hr = GetCount(&count);
  if (AAFRESULT_FAILED(hr)) return hr;

  if (index >= count) return AAFRESULT_ILLEGAL_VALUE;

  aafCharacter c;
  size_t numChars = _memberNames.count();
  indexIntoProp = 0;
  currentIndex = 0;
  if (0 != index)
	{
	  for (size_t i = 0; i < numChars; i++)
		{
		  indexIntoProp++;
		  _memberNames.getValueAt(&c, i);
		  if (0 == c)
			{
			  // We've found the null just before the string we want.
			  // We'll increment the indexIntoProp to the start of the
			  // string and break out of the loop, but first make sure
			  // there's more string there to index into.
			  assert (i < numChars);
			  currentIndex++;
			  if (index == currentIndex)
				  break;
			}
		}
	  // Make sure we didn't terminate the loop by dropping out before
	  // the correct index was found.
	  assert (indexIntoProp < numChars);
	}

  // indexIntoProp now indicates the starting char we want.  Start
  // counting until we get to the next null.
  aafUInt32 nameLength = 0;
  do
	{
	  _memberNames.getValueAt(&c, indexIntoProp++);
	  if (c) nameLength++;
	}
  while (c);

  // increment once more for trailing null
  nameLength++;

  assert (pLen);
  // nameLength is in number of aafCharacters; returned length must be
  // in bytes
  *pLen = (nameLength * sizeof (aafCharacter)) / sizeof (aafUInt8);
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::CreateValueFromValues (
      ImplAAFPropertyValue ** pMemberValues,
      aafUInt32  numMembers,
      ImplAAFPropertyValue ** ppPropVal)
{
  aafUInt32 count;
  AAFRESULT hr;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (!pMemberValues) return AAFRESULT_NULL_PARAM;
  if (!ppPropVal) return AAFRESULT_NULL_PARAM;

  hr = GetCount (&count);
  if (AAFRESULT_FAILED(hr)) return hr;
  if (numMembers != count) return AAFRESULT_ILLEGAL_VALUE;

  ImplAAFPropValDataSP pvd;
  aafMemPtr_t pBits = NULL;
  ImplAAFTypeDefSP ptd;

  // Get total property value size from sum of all member prop vals
  assert (pMemberValues);
  aafUInt32 size = 0;
  aafUInt32 i;
  for (i = 0; i < count ; i++)
	{
	  hr = pMemberValues[i]->GetType (&ptd);
	  if (AAFRESULT_FAILED(hr)) return hr;
	  assert (ptd);
	  assert (ptd->IsFixedSize());
	  size += ptd->PropValSize();
	}
  assert (PropValSize() == size);

  // create new ueber-prop-val and set it up
  pvd = (ImplAAFPropValData*) CreateImpl (CLSID_AAFPropValData);
  if (!pvd) return AAFRESULT_NOMEMORY;

  // Bobt: Hack bugfix! SmartPointer operator= will automatically
  // AddRef; CreateImpl *also* will addref, so we've got one too
  // many.  Put us back to normal.
  pvd->ReleaseReference ();

  hr = pvd->Initialize (this);
  if (AAFRESULT_FAILED(hr)) return hr;

  hr = pvd->AllocateBits (size, &pBits);
  if (AAFRESULT_FAILED(hr)) return hr;

  // copy bits of each subordinate prop val into correct place in
  // the ueber one
  size_t curOffset = 0;
  for (i = 0; i < count; i++)
	{
	  aafUInt32 curSize;
	  hr = pMemberValues[i]->GetType (&ptd);
	  if (AAFRESULT_FAILED(hr)) return hr;
	  assert (ptd);
	  curSize = ptd->PropValSize();
	  aafMemPtr_t inBits = NULL;
	  assert (dynamic_cast<ImplAAFPropValData*>(pMemberValues[i]));
	  hr = dynamic_cast<ImplAAFPropValData*>(pMemberValues[i])
		->GetBits (&inBits);
	  if (AAFRESULT_FAILED(hr)) return hr;
	  assert (inBits);
	  memcpy (pBits+curOffset, inBits, curSize);
	  curOffset += curSize;
	  assert (curOffset <= size);
	}
  assert (ppPropVal);
  *ppPropVal = pvd;
  (*ppPropVal)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::CreateValueFromStruct (
      aafMemPtr_t pInitData,
      aafUInt32 initDataSize,
      ImplAAFPropertyValue ** ppPropVal)
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (! pInitData)
	return AAFRESULT_NULL_PARAM;
  if (! ppPropVal)
	return AAFRESULT_NULL_PARAM;
  if (! IsRegistered ())
	return AAFRESULT_NOT_REGISTERED;
  if (initDataSize != NativeSize())
	return AAFRESULT_ILLEGAL_VALUE;

  ImplAAFPropValData * pvd = 0;
  pvd = (ImplAAFPropValData*) CreateImpl (CLSID_AAFPropValData);
  if (!pvd) return AAFRESULT_NOMEMORY;

  ImplAAFPropValDataSP spPvd;
  spPvd = pvd;
  // Bobt: Hack bugfix! SmartPointer operator= will automatically
  // AddRef; CreateImpl *also* will addref, so we've got one too
  // many.  Put us back to normal.
  pvd->ReleaseReference ();
  pvd = 0;

  AAFRESULT hr;
  hr = spPvd->Initialize (this);
  if (AAFRESULT_FAILED (hr)) return hr;

  aafMemPtr_t pBits = 0;
  hr = spPvd->AllocateBits (initDataSize, &pBits);
  if (AAFRESULT_FAILED(hr)) return hr;
  assert (pBits);

  // Simply copy struct bits into property value.
  memcpy (pBits, pInitData, initDataSize);

  assert (ppPropVal);
  *ppPropVal = spPvd;
  assert (*ppPropVal);
  (*ppPropVal)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetValue (
      ImplAAFPropertyValue * pInPropVal,
      aafUInt32 index,
      ImplAAFPropertyValue ** ppOutPropVal)
{
  aafUInt32 count;
  AAFRESULT hr;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (!pInPropVal)   return AAFRESULT_NULL_PARAM;
  if (!ppOutPropVal) return AAFRESULT_NULL_PARAM;

  // Get the property value's embedded type
  ImplAAFTypeDefSP pInPropType;
  if( AAFRESULT_FAILED( pInPropVal->GetType( &pInPropType ) ) )
	return AAFRESULT_BAD_TYPE;
  assert (pInPropType);

  // determine if the property value's embedded type is compatible
  // with this one for reading.  For now, we'll only allow record
  // and extendable enumeration type properties to be read by this 
  // type def.
  eAAFTypeCategory_t        type_category = kAAFTypeCatUnknown;
  ImplAAFTypeDefRecordSP    pActualRecordType;

  pInPropType->GetTypeCategory( &type_category );

  if( type_category == kAAFTypeCatExtEnum )
  {
      // Cast input prop value type to ExtEnum.
      ImplAAFTypeDefExtEnum	*pExtEnumType = 
	  dynamic_cast<ImplAAFTypeDefExtEnum*>( (ImplAAFTypeDef*)pInPropType );
      if( !pExtEnumType )
	return AAFRESULT_BAD_TYPE;

      // Now get base type of ExtEnum and cast it to Record.
      ImplAAFTypeDefSP	pBaseType;
      pBaseType = pExtEnumType->BaseType();
      pActualRecordType = dynamic_cast<ImplAAFTypeDefRecord*>( (ImplAAFTypeDef*)pBaseType );
      if( pActualRecordType == NULL )
	  return AAFRESULT_BAD_TYPE;
  }
  else if( type_category == kAAFTypeCatRecord )
  {
      pActualRecordType = this;
  }
  else
      return AAFRESULT_BAD_TYPE;


  hr = pActualRecordType->GetCount (&count);
  if (AAFRESULT_FAILED(hr)) return hr;
  if (index >= count) return AAFRESULT_ILLEGAL_VALUE;

  ImplAAFPropValData * pvdIn = NULL;
  ImplAAFPropValDataSP pvdOut;
  ImplAAFTypeDefSP ptd;

  aafUInt32 offset = 0;
  // add up offsets of previous items
  for (aafUInt32 i = 0; i < index; i++)
	{
	  hr = pActualRecordType->GetMemberType (i, &ptd);
	  assert (AAFRESULT_SUCCEEDED(hr));
	  assert (ptd);
	  if(pActualRecordType->IsRegistered())
		  offset += ptd->NativeSize();
	  else
		  offset += ptd->PropValSize();
	}

  // offset now points into prop storage

  pvdOut = (ImplAAFPropValData*) CreateImpl (CLSID_AAFPropValData);
  if (!pvdOut) return AAFRESULT_NOMEMORY;

  // Bobt: Hack bugfix! SmartPointer operator= will automatically
  // AddRef; CreateImpl *also* will addref, so we've got one too
  // many.  Put us back to normal.
  pvdOut->ReleaseReference ();

  hr = pActualRecordType->GetMemberType (index, &ptd);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (ptd);

  hr = pvdOut->Initialize (ptd);
  if (AAFRESULT_FAILED(hr)) return hr;

  assert (pInPropVal);
  pvdIn = dynamic_cast<ImplAAFPropValData*>(pInPropVal);
  assert (pvdIn);


  if(pActualRecordType->IsRegistered())
  {
	  hr = pvdOut->AllocateFromPropVal (pvdIn,
									offset,
									ptd->NativeSize(),
									NULL);
  }
  else
  {
	  hr = pvdOut->AllocateFromPropVal (pvdIn,
									offset,
									ptd->PropValSize(),
									NULL);
  }
  if (AAFRESULT_FAILED(hr)) return hr;
  assert (ppOutPropVal);
  *ppOutPropVal = pvdOut;
  (*ppOutPropVal)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetStruct (
      ImplAAFPropertyValue * pPropVal,
      aafMemPtr_t pData,
      aafUInt32 dataSize)
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (! pPropVal)
	return AAFRESULT_NULL_PARAM;
  if (! pData)
	return AAFRESULT_NULL_PARAM;
  if (! IsRegistered ())
	return AAFRESULT_NOT_REGISTERED;
  if (dataSize != NativeSize())
	return AAFRESULT_ILLEGAL_VALUE;

  // Get the property value's embedded type
  ImplAAFTypeDefSP pInPropType;
  if( AAFRESULT_FAILED( pPropVal->GetType( &pInPropType ) ) )
	return AAFRESULT_BAD_TYPE;
  assert (pInPropType);

  // determine if the property value's embedded type is compatible
  // with this one for reading.  For now, we'll only allow integral
  // and enumeration type properties to be read by this integral type def.
  //
  eAAFTypeCategory_t	type_category = kAAFTypeCatUnknown;
  pInPropType->GetTypeCategory( &type_category );
  if( type_category != kAAFTypeCatExtEnum  &&  
      type_category != kAAFTypeCatRecord )
	return AAFRESULT_BAD_TYPE;

  aafUInt32 bitsSize = 0;
  ImplAAFPropValData * pvd = 0;
  assert (pPropVal);
  pvd = dynamic_cast<ImplAAFPropValData*>(pPropVal);
  assert (pvd);
  AAFRESULT hr;
  hr = pvd->GetBitsSize (&bitsSize);
  if (AAFRESULT_FAILED(hr))
	return hr;
  if (dataSize < bitsSize)
	return AAFRESULT_ILLEGAL_VALUE;

  aafMemPtr_t pBits;
  hr = pvd->GetBits (&pBits);
  if (AAFRESULT_FAILED(hr))
	return hr;

  memcpy (pData, pBits, dataSize);
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::SetValue (
      ImplAAFPropertyValue * pPropVal,
      aafUInt32 index,
      ImplAAFPropertyValue * pMemberPropVal)
{
  aafUInt32 count;
  AAFRESULT hr;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (!pPropVal)   return AAFRESULT_NULL_PARAM;
  if (!pMemberPropVal) return AAFRESULT_NULL_PARAM;

  // Get the property value's embedded type
  ImplAAFTypeDefSP pInPropType;
  if( AAFRESULT_FAILED( pPropVal->GetType( &pInPropType ) ) )
	return AAFRESULT_BAD_TYPE;
  assert (pInPropType);

  // determine if the property value's embedded type is compatible
  // with this one for reading.  For now, we'll only allow integral
  // and enumeration type properties to be read by this integral type def.
  //
  eAAFTypeCategory_t        type_category = kAAFTypeCatUnknown;
  ImplAAFTypeDefRecordSP    pActualRecordType;

  pInPropType->GetTypeCategory( &type_category );

  if( type_category == kAAFTypeCatExtEnum )
  {
      // Cast input prop value type to ExtEnum.
      ImplAAFTypeDefExtEnum	*pExtEnumType = 
	  dynamic_cast<ImplAAFTypeDefExtEnum*>( (ImplAAFTypeDef*)pInPropType );
      if( !pExtEnumType )
	return AAFRESULT_BAD_TYPE;

      // Now get base type of ExtEnum and cast it to Record.
      ImplAAFTypeDefSP	pBaseType;
      pBaseType = pExtEnumType->BaseType();
      pActualRecordType = dynamic_cast<ImplAAFTypeDefRecord*>( (ImplAAFTypeDef*)pBaseType );
      if( pActualRecordType == NULL )
	  return AAFRESULT_BAD_TYPE;
  }
  else if( type_category == kAAFTypeCatRecord )
  {
      pActualRecordType = this;
  }
  else
      return AAFRESULT_BAD_TYPE;

  hr = pActualRecordType->GetCount (&count);
  if (AAFRESULT_FAILED(hr)) return hr;
  if (index >= count) return AAFRESULT_ILLEGAL_VALUE; // wol 031230 typo fix (was <=)

  ImplAAFPropValDataSP pvdIn;
  ImplAAFPropValDataSP pvdOut;
  ImplAAFTypeDefSP ptd;

  aafUInt32 offset = 0;
  // add up offsets of previous items
  for (aafUInt32 i = 0; i < index; i++)
	{
	  hr = pActualRecordType->GetMemberType (i, &ptd);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  assert (ptd);
	  offset += ptd->PropValSize();
	}

  // offset now points into prop storage

  hr = pActualRecordType->GetMemberType (index, &ptd);
  assert (AAFRESULT_SUCCEEDED (hr));
  assert (ptd);

  assert (pMemberPropVal);
  pvdIn = dynamic_cast<ImplAAFPropValData*>(pMemberPropVal);
  assert (pvdIn);

  assert (pPropVal);
  pvdOut = dynamic_cast<ImplAAFPropValData*>(pPropVal);
  assert (pvdOut);

  assert ((offset+ptd->PropValSize()) <= this->PropValSize());

  aafMemPtr_t pInBits = NULL;
  aafMemPtr_t pOutBits = NULL;

  hr = pvdIn->GetBits (&pInBits);
  if (AAFRESULT_FAILED(hr)) return hr;

  hr = pvdOut->GetBits (&pOutBits);
  if (AAFRESULT_FAILED(hr)) return hr;

	/*	
		this seems areasonable and worthwhile defensive addition

		but whence comes the real problem?

		pOutBits will be 0 if the PropValData has not been initialized
		which will be the case if the ImplAAFProperty for the member believes it is Optional
		which of course record members are not - they are mandatory

		perhaps this is the real bug?
	*/
	if( !pOutBits )
	{
		aafUInt32 bitsSize; pvdOut->GetBitsSize( &bitsSize );

		hr = pvdOut->AllocateBits ( bitsSize, &pOutBits);
		if (AAFRESULT_FAILED(hr)) return hr;
	}

  memcpy (pOutBits+offset, pInBits, ptd->PropValSize());

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::SetStruct (
      ImplAAFPropertyValue * pPropVal,
      aafMemPtr_t pData,
      aafUInt32 dataSize)
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (! pPropVal)
	return AAFRESULT_NULL_PARAM;
  if (! pData)
	return AAFRESULT_NULL_PARAM;

  // Get the property value's embedded type
  ImplAAFTypeDefSP pInPropType;
  if( AAFRESULT_FAILED( pPropVal->GetType( &pInPropType ) ) )
	return AAFRESULT_BAD_TYPE;
  assert (pInPropType);

  // determine if the property value's embedded type is compatible
  // with this one for reading.  For now, we'll only allow integral
  // and enumeration type properties to be read by this integral type def.
  //
  eAAFTypeCategory_t	type_category = kAAFTypeCatUnknown;
  pInPropType->GetTypeCategory( &type_category );
  if( type_category != kAAFTypeCatExtEnum  &&  
      type_category != kAAFTypeCatRecord )
	return AAFRESULT_BAD_TYPE;

  // Bobt hack implementation! Not platform-independent!
  aafUInt32 bitsSize = 0;
  ImplAAFPropValData * pvd = 0;
  AAFRESULT hr;
  assert (pPropVal);
  pvd = dynamic_cast<ImplAAFPropValData*>(pPropVal);
  assert (pvd);
  hr = pvd->GetBitsSize (&bitsSize);
  if (AAFRESULT_FAILED(hr))
	return hr;
  if (dataSize != bitsSize)
	return AAFRESULT_ILLEGAL_VALUE;

  aafMemPtr_t pBits;
  hr = pvd->GetBits (&pBits);
  if (AAFRESULT_FAILED(hr))
	return hr;

  // Bobt hack!!! should be registered size, not bitsSize.
  memcpy (pBits, pData, bitsSize);
  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::GetCount (
      aafUInt32 *  pCount) const
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (!pCount) return AAFRESULT_NULL_PARAM;
  if (_cachedCount == ((aafUInt32) -1))
	((ImplAAFTypeDefRecord*)this)->_cachedCount =
	  _memberTypes.count();
  *pCount = _cachedCount;

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::RegisterMembers (
      aafUInt32 * pOffsets,
      aafUInt32 numMembers,
      aafUInt32 structSize)
{
  aafUInt32 count;
  AAFRESULT hr;

  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;

  if (! pOffsets) return AAFRESULT_NULL_PARAM;

  hr = GetCount (&count);
  if (AAFRESULT_FAILED(hr)) return hr;

  if (numMembers != count) return AAFRESULT_ILLEGAL_VALUE;


  if (_defaultRegistrationUsed)
	{
	  return AAFRESULT_DEFAULT_ALREADY_USED;
	}

  aafUInt32 i;
  for (i = 0; i < numMembers; i++)
	{
	  ImplAAFTypeDefSP ptd;
	  hr = GetMemberType (i, &ptd);
	  if (AAFRESULT_FAILED (hr))
		return hr;
	  if (! ptd->IsRegistered())
		{
		  return AAFRESULT_NOT_REGISTERED;
		}
	}

  if (_registeredOffsets) delete[] _registeredOffsets;
  _registeredOffsets = new aafUInt32[numMembers];
  if (! _registeredOffsets) return AAFRESULT_NOMEMORY;

  pvtInitInternalSizes ();
  assert (_internalSizes);

  for (i = 0; i < numMembers; i++)
	{
	  _registeredOffsets[i] = pOffsets[i];
	  if ((numMembers-1) == i)
		{
		  // Last (or perhaps only) member; take total struct size and
		  // subtract last offset for this size
		  _internalSizes[i] = structSize - pOffsets[i];
		}
	  else
		{
		  // We know it's not the last member, so it's safe to index
		  // to the next element in pOffsets array.
		  _internalSizes[i] = pOffsets[i+1] - pOffsets[i];
		}
	}

  _registeredSize = structSize;
  return AAFRESULT_SUCCESS;
}


// Override from AAFTypeDef
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefRecord::GetTypeCategory (eAAFTypeCategory_t *  pTid)
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  if (!pTid) return AAFRESULT_NULL_PARAM;
  *pTid = kAAFTypeCatRecord;
  return AAFRESULT_SUCCESS;
}


void ImplAAFTypeDefRecord::reorder(OMByte* externalBytes,
								   size_t externalBytesSize) const
{
  AAFRESULT hr;
  aafUInt32 numMembers = 0;
  aafUInt32 member = 0;
  aafUInt32 externalMemberSize = 0;
  ImplAAFTypeDefSP ptdm;

  ImplAAFTypeDefRecord * pNonConstThis =
	(ImplAAFTypeDefRecord *) this;

  hr = pNonConstThis->GetCount (&numMembers);
  assert (AAFRESULT_SUCCEEDED (hr));

  aafInt32 numBytesLeft = externalBytesSize;

  for (member = 0; member < numMembers; member++)
	{
	  hr = pNonConstThis->GetMemberType (member, &ptdm);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  externalMemberSize = ptdm->PropValSize ();

	  ptdm->reorder (externalBytes, externalMemberSize);
	  externalBytes += externalMemberSize;
	  numBytesLeft -= externalMemberSize;
	  assert (numBytesLeft >= 0);
	}
}


size_t ImplAAFTypeDefRecord::externalSize(const OMByte* /*internalBytes*/,
										  size_t /*internalBytesSize*/) const
{
  return PropValSize ();
}


void ImplAAFTypeDefRecord::externalize(const OMByte* internalBytes,
									   size_t internalBytesSize,
									   OMByte* externalBytes,
									   size_t externalBytesSize,
									   OMByteOrder byteOrder) const
{
  AAFRESULT hr;
  aafUInt32 numMembers = 0;
  aafUInt32 member = 0;
  aafUInt32 externalMemberSize = 0;
  aafUInt32 internalMemberSize = 0;
  ImplAAFTypeDefSP ptdm;

  ImplAAFTypeDefRecord * pNonConstThis =
	(ImplAAFTypeDefRecord *) this;

  hr = pNonConstThis->GetCount (&numMembers);
  assert (AAFRESULT_SUCCEEDED (hr));

  aafInt32 internalNumBytesLeft = internalBytesSize;
  aafInt32 externalNumBytesLeft = externalBytesSize;

  pvtInitInternalSizes ();
  assert (_internalSizes);
  for (member = 0; member < numMembers; member++)
	{
	  hr = pNonConstThis->GetMemberType (member, &ptdm);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  externalMemberSize = ptdm->PropValSize ();
	  //internalMemberSize = _internalSizes[member];
          internalMemberSize = ptdm->internalSize (externalBytes, externalMemberSize);

	  ptdm->externalize (internalBytes,
						 internalMemberSize,
						 externalBytes,
						 externalMemberSize,
						 byteOrder);
	  externalBytes += externalMemberSize;
	  internalBytes += _internalSizes[member]; //internalMemberSize;
	  externalNumBytesLeft -= externalMemberSize;
	  internalNumBytesLeft -= _internalSizes[member]; //internalMemberSize;
	  assert (externalNumBytesLeft >= 0);
	  assert (internalNumBytesLeft >= 0);
	}

  if (! _defaultRegistrationUsed && (! IsRegistered ()))
	{
	  // cast away const-ness
	  ((ImplAAFTypeDefRecord*)this)->
		_defaultRegistrationUsed = kAAFTrue;
	}
}


size_t ImplAAFTypeDefRecord::internalSize(void) const
{
  if (IsRegistered ())
	return NativeSize ();
  else
	return PropValSize ();
}

size_t ImplAAFTypeDefRecord::internalSize(const OMByte* /*externalBytes*/,
										  size_t /*externalBytesSize*/) const
{
  if (IsRegistered ())
	return NativeSize ();
  else
	return PropValSize ();
}


void ImplAAFTypeDefRecord::internalize(const OMByte* externalBytes,
									   size_t externalBytesSize,
									   OMByte* internalBytes,
									   size_t internalBytesSize,
									   OMByteOrder byteOrder) const
{
  AAFRESULT hr;
  aafUInt32 numMembers = 0;
  aafUInt32 member = 0;
  aafUInt32 externalMemberSize = 0;
  aafUInt32 internalMemberSize = 0;
  ImplAAFTypeDefSP ptdm;

  ImplAAFTypeDefRecord * pNonConstThis =
	(ImplAAFTypeDefRecord *) this;

  hr = pNonConstThis->GetCount (&numMembers);
  assert (AAFRESULT_SUCCEEDED (hr));

  aafInt32 internalNumBytesLeft = internalBytesSize;
  aafInt32 externalNumBytesLeft = externalBytesSize;

  pvtInitInternalSizes ();
  assert (_internalSizes);
  for (member = 0; member < numMembers; member++)
	{
	  hr = pNonConstThis->GetMemberType (member, &ptdm);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  externalMemberSize = ptdm->PropValSize ();
	  //internalMemberSize = _internalSizes[member];
          internalMemberSize = ptdm->internalSize (externalBytes, externalMemberSize);

	  ptdm->internalize (externalBytes,
						 externalMemberSize,
						 internalBytes,
						 internalMemberSize,
						 byteOrder);
	  externalBytes += externalMemberSize;
	  internalBytes += _internalSizes[member]; //internalMemberSize;
	  externalNumBytesLeft -= externalMemberSize;
	  internalNumBytesLeft -= _internalSizes[member]; //internalMemberSize;
	  assert (externalNumBytesLeft >= 0);
	  assert (internalNumBytesLeft >= 0);
	}

  if (! _defaultRegistrationUsed && (! IsRegistered ()))
	{
	  // cast away const-ness
	  ((ImplAAFTypeDefRecord*)this)->
		_defaultRegistrationUsed = kAAFTrue;
	}
}



aafBool ImplAAFTypeDefRecord::IsFixedSize (void) const
{
  return kAAFTrue;
}


size_t ImplAAFTypeDefRecord::PropValSize (void) const
{
  aafUInt32 count;
  size_t totalSize = 0;
  AAFRESULT hr;

  hr = GetCount (&count);
  if (AAFRESULT_FAILED(hr)) return hr;

  for (aafUInt32 i = 0; i < count; i++)
	{
	  ImplAAFTypeDefSP pMemType;
	  // Bobt semi-hack: need non-const this in order to call
	  // non-const GetMemberType. We know we aren't mangling it, so it
	  // technically is OK...
	  ImplAAFTypeDefRecord * pNonConstThis =
		(ImplAAFTypeDefRecord*) this;
	  hr = pNonConstThis->GetMemberType (i, &pMemType);
	  assert (AAFRESULT_SUCCEEDED(hr));
	  assert (pMemType);
	  assert (pMemType->IsFixedSize());
	  totalSize += pMemType->PropValSize();
	}
  return totalSize;
}


void ImplAAFTypeDefRecord::AttemptBuiltinRegistration (void)
{
  if (! _registrationAttempted)
	{
	  ImplAAFDictionarySP pDict;
	  AAFRESULT hr = GetDictionary(&pDict);
	  assert (AAFRESULT_SUCCEEDED (hr));
	  pDict->pvtAttemptBuiltinSizeRegistration (this);
	  _registrationAttempted = kAAFTrue;
	}
}


aafBool ImplAAFTypeDefRecord::IsRegistered (void) const
{
  ((ImplAAFTypeDefRecord*)this)->AttemptBuiltinRegistration ();
  return (_registeredOffsets ? kAAFTrue : kAAFFalse);
}


size_t ImplAAFTypeDefRecord::NativeSize (void) const
{
  ((ImplAAFTypeDefRecord*)this)->AttemptBuiltinRegistration ();
  assert (IsRegistered());
  return _registeredSize;
}


OMProperty * ImplAAFTypeDefRecord::pvtCreateOMProperty
  (OMPropertyId pid,
   const wchar_t * name) const
{
  assert (name);
  size_t elemSize = PropValSize ();
  OMProperty * result = new OMSimpleProperty (pid, name, elemSize);
  assert (result);
  return result;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefRecord::RawAccessType (
      ImplAAFTypeDef ** ppRawTypeDef)
{
  if (! isInitialized ()) return AAFRESULT_NOT_INITIALIZED;
  // Return variable array of unsigned char
  return pvtGetUInt8Array8Type (ppRawTypeDef);
}


bool ImplAAFTypeDefRecord::IsAggregatable () const
{ return true; }

bool ImplAAFTypeDefRecord::IsStreamable () const
{ return true; }

bool ImplAAFTypeDefRecord::IsFixedArrayable () const
{ return true; }

bool ImplAAFTypeDefRecord::IsVariableArrayable () const
{ return true; }

bool ImplAAFTypeDefRecord::IsStringable () const
{ return false; }






// override from OMStorable.
const OMClassId& ImplAAFTypeDefRecord::classId(void) const
{
  return (*reinterpret_cast<const OMClassId *>(&AUID_AAFTypeDefRecord));
}

// Override callbacks from OMStorable
void ImplAAFTypeDefRecord::onSave(void* clientContext) const
{
  ImplAAFTypeDef::onSave(clientContext);
}

void ImplAAFTypeDefRecord::onRestore(void* clientContext) const
{
  ImplAAFTypeDef::onRestore(clientContext);
}
