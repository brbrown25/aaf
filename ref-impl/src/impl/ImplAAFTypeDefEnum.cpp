//=---------------------------------------------------------------------=
//
// $Id: ImplAAFTypeDefEnum.cpp,v 1.40 2006/05/24 18:01:53 tbingham Exp $ $Name:  $
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

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#ifndef __ImplAAFTypeDefEnum_h__
#include "ImplAAFTypeDefEnum.h"
#endif

#ifndef __ImplAAFTypeDefInt_h__
#include "ImplAAFTypeDefInt.h"
#endif

#ifndef __ImplAAFHeader_h__
#include "ImplAAFHeader.h"
#endif

#ifndef __ImplAAFPropValData_h__
#include "ImplAAFPropValData.h"
#endif

#ifndef __AAFTypeDefUIDs_h__
#include "AAFTypeDefUIDs.h"
#endif

#include "OMAssertions.h"
#include <string.h>
#include <wchar.h>

extern "C" const aafClassID_t CLSID_AAFPropValData;

//some macros
#define check_hr(expr)\
{\
	HRESULT  the_hresult = (expr);\
	if (FAILED(the_hresult))\
	   return the_hresult;\
}


ImplAAFTypeDefEnum::ImplAAFTypeDefEnum ()
: _ElementType   ( PID_TypeDefinitionEnumeration_ElementType,
				  L"ElementType",
				  L"/MetaDictionary/TypeDefinitions",
				  PID_MetaDefinition_Identification),
				  _ElementNames  ( PID_TypeDefinitionEnumeration_ElementNames,  L"ElementNames"),
				  _ElementValues ( PID_TypeDefinitionEnumeration_ElementValues, L"ElementValues"),
				  _isRegistered (kAAFFalse),
				  _registrationAttempted (kAAFFalse)
{
	_persistentProperties.put(_ElementType.address());
	_persistentProperties.put(_ElementNames.address());
	_persistentProperties.put(_ElementValues.address());
}


ImplAAFTypeDefEnum::~ImplAAFTypeDefEnum ()
{}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::Initialize (
								const aafUID_t & id,
								ImplAAFTypeDef * pType,
								aafInt64 * pElementValues,
								aafString_t * pElementNames,
								aafUInt32 numElements,
								const wchar_t * pTypeName)
{
	if (!pType)
		return AAFRESULT_NULL_PARAM;
	
	eAAFTypeCategory_t baseTypeCat;  
	ASSERTU (pType);
	AAFRESULT hr = pType->GetTypeCategory(&baseTypeCat);
	if (AAFRESULT_FAILED(hr))
		return hr;
	if (kAAFTypeCatInt != baseTypeCat)
		return AAFRESULT_BAD_TYPE;
	
	if( !aafLookupTypeDef( this, pType ) )
		return AAFRESULT_TYPE_NOT_FOUND;

	return pvtInitialize (id,
		pType,
		pElementValues,
		pElementNames,
		numElements,
		pTypeName);
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::pvtInitialize (
								   const aafUID_t & id,
								   const ImplAAFTypeDef * pType,
								   aafInt64 * pElementValues,
								   aafString_t * pElementNames,
								   aafUInt32 numElements,
								   const wchar_t * pTypeName)
{
	if (!pTypeName)
		return AAFRESULT_NULL_PARAM;
	
	if ((numElements*sizeof(aafInt64)) > OMPROPERTYSIZE_MAX)
		return(AAFRESULT_BAD_SIZE);

	AAFRESULT hr;
	
	hr = ImplAAFMetaDefinition::Initialize(id, pTypeName, NULL);
	if (AAFRESULT_FAILED (hr))
		return hr;
	
	aafUInt32 i;
	aafUInt32 totalNameSize = 0;
	for (i = 0; i < numElements; i++)
	{
		if ( !pElementNames[i])
			return AAFRESULT_NULL_PARAM;
		
		totalNameSize += (wcslen (pElementNames[i]) + 1);
	}
	
	if ((totalNameSize * sizeof(OMCharacter)) > OMPROPERTYSIZE_MAX)
		return(AAFRESULT_BAD_SIZE);


	wchar_t * namesBuf = new wchar_t[totalNameSize];
	if (!namesBuf)
		return AAFRESULT_NOMEMORY;
	// make it an empty string
	*namesBuf = 0;
	wchar_t * tmpNamePtr = namesBuf;
	
	ASSERTU (0 == _ElementValues.count());
	for (i = 0; i < numElements; i++)
	{
		ASSERTU (pElementNames[i]);
		wcscpy(tmpNamePtr, pElementNames[i]);
		// +1 to go past embedded null
		tmpNamePtr += wcslen (pElementNames[i]) + 1;
	}
	
	_ElementType = pType;
	
	_ElementNames.setValue (namesBuf, totalNameSize * sizeof(wchar_t));
	delete[] namesBuf;
	_ElementValues.setValue (pElementValues, numElements*sizeof(aafInt64));
	ASSERTU (numElements == _ElementValues.count());

	//Register the size

	ImplAAFTypeDefInt *pTDInt;
	// This cast should succeed since only int's are allowed
	pTDInt = dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef *)_ElementType);
	
	ASSERTU (pTDInt);
	
	aafUInt32 elem_size;
	check_hr ( pTDInt->GetSize(&elem_size) );
	ASSERTU(elem_size);
	
	//finally, call the Register function
	RegisterSize(elem_size);   

	return AAFRESULT_SUCCESS;
}



/****/
//
// LSB-justifies and zero-fills the input value, copying the result
// into the output value.  Requires that inVal and outVal are valid
// pointers, and that inValSize is no larger than outValSize.  Also
// requires that in/outValSize are supported values from the set {1,
// 2, 4, 8} bytes.
//
static void pvtZeroFill (const aafMemPtr_t inVal,
						   aafUInt32   inValSize,
						   aafMemPtr_t outVal,
						   aafUInt32   outValSize)
{
  aafUInt32 localValue = 0;	// only 4 bytes; see below for why it's OK.

  ASSERTU (inVal);
  ASSERTU (outVal);
  ASSERTU (inValSize <= outValSize);
  ASSERTU ((1 == inValSize) ||
		  (2 == inValSize) ||
		  (4 == inValSize) ||
		  (8 == inValSize));
  ASSERTU ((1 == outValSize) ||
		  (2 == outValSize) ||
		  (4 == outValSize) ||
		  (8 == outValSize));
  if (inValSize == outValSize)
	{
	  memcpy (outVal, inVal, inValSize);
	}
  else
	{
	  // At this point we know that inSize < outSize; the largest
	  // outSize can be is 8 bytes, so the largest inSize can be is 4
	  // bytes; that's why localValue can work as only a 4-byte int.
	  switch (inValSize)
		{
		case 1:
		  localValue = *((aafUInt8*) inVal);
		  break;
		case 2:
		  localValue = *((aafUInt16*) inVal);
		  break;
		case 4:
		  localValue = *((aafUInt32*) inVal);
		  break;
		case 8:
		  // inval can't be 8 bytes
		  ASSERTU (0);
		default:
		  ASSERTU (0);
		}

	  switch (outValSize)
		{
		case 1:
		  // inval can't be 1 byte
		  ASSERTU (0);
		case 2:
		  *((aafUInt16*) outVal) = (aafUInt16) localValue;
		  break;
		case 4:
		  *((aafUInt32*) outVal) = localValue;
		  break;
		case 8:
		  // hack! we don't have unsigned 64-bit, so we'll depend on
		  // the compiler to sign-extend and zero-fill the unsigned
		  // localValue, even though the dest (64bit) is signed.
		  *((aafInt64*) outVal) = localValue;
		  break;
		default:
		  ASSERTU (0);
		}
	}
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefEnum::CreateValue (
      aafMemPtr_t  pVal,
      aafUInt32  valSize,
      ImplAAFPropertyValue ** ppPropVal)
{
  if (! pVal)
	return AAFRESULT_NULL_PARAM;
  if (! ppPropVal)
	return AAFRESULT_NULL_PARAM;

  // Get the size of the base integer type
  aafUInt32	localIntSize = NativeSize();

  if (valSize > localIntSize)
	return AAFRESULT_BAD_SIZE;

  // current impl only allows 1, 2, 4, and 8-byte ints.
  if( (1 != valSize) && (2 != valSize) &&
      (4 != valSize) && (8 != valSize) )
	return AAFRESULT_BAD_SIZE;

  // zero-fill the value.
  aafUInt8 valBuf[8];
  pvtZeroFill (pVal, valSize, valBuf, localIntSize);

  // Create a temporary pointer to copy to the smartptr
  ImplAAFPropValData * tmp = (ImplAAFPropValData *)CreateImpl(CLSID_AAFPropValData);
  if (NULL == tmp)
	return AAFRESULT_NOMEMORY;
  ImplAAFPropValDataSP pv;
  pv = tmp;

  // Bobt: Hack bugfix! SmartPointer operator= will automatically
  // AddRef; CreateImpl *also* will addref, so we've got one too
  // many.  Put us back to normal.
  tmp->ReleaseReference(); // we don't need this reference anymore.
  tmp = 0;

  AAFRESULT hr;
  hr = pv->Initialize(this);
  if (! AAFRESULT_SUCCEEDED (hr))
	return hr;

  aafMemPtr_t pBits = NULL;
  hr = pv->AllocateBits (localIntSize, &pBits);
  if (! AAFRESULT_SUCCEEDED (hr))
	return hr;

  ASSERTU (pBits);
  memcpy (pBits, valBuf, localIntSize);

  *ppPropVal = pv;
  (*ppPropVal)->AcquireReference ();
  return AAFRESULT_SUCCESS;
}
/****/


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetElementType (
									ImplAAFTypeDef ** ppTypeDef) const
{
	if (! ppTypeDef)
		return AAFRESULT_NULL_PARAM;
	
	if(_ElementType.isVoid())
		return AAFRESULT_OBJECT_NOT_FOUND;
	ImplAAFTypeDef *pTypeDef = bootstrapTypeWeakReference(_ElementType);
	
	*ppTypeDef = pTypeDef;
	ASSERTU (*ppTypeDef);
	(*ppTypeDef)->AcquireReference ();
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::CountElements (
								   aafUInt32 * pCount)
{
	if (!pCount) return AAFRESULT_NULL_PARAM;
	*pCount = _ElementValues.count();
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetElementValue (
									 aafUInt32 index,
									 aafInt64 * pOutValue)
{
	if (! pOutValue)
		return AAFRESULT_NULL_PARAM;
	
	aafUInt32 count;
	AAFRESULT hr;
	hr = CountElements (&count);
	if (AAFRESULT_FAILED(hr))
		return hr;
	if (index >= count)
		return AAFRESULT_BADINDEX;
	
	aafInt64 val;
	_ElementValues.getValueAt (&val, index);
	ASSERTU (pOutValue);
	*pOutValue = val;
	
	return AAFRESULT_SUCCESS;
}

AAFRESULT ImplAAFTypeDefEnum::LookupValByName(aafInt64 *pVal, const aafCharacter *pName)
{
	aafUInt32 i=0;
	aafUInt32 count=0;
	aafBoolean_t  bFound = kAAFFalse;
	aafCharacter Name_buf[256]; 
	aafUInt32 bufSize = 256;
	
	check_hr ( CountElements(&count) );
	while ( (i<count) && !bFound)
	{
		check_hr ( GetElementName (i, Name_buf, bufSize) );
		if ( wcscmp (Name_buf, pName) == 0 ) //matched
		{
			bFound = kAAFTrue;
			
			check_hr (GetElementValue(i, pVal));
			break;
			
		}//if

		i++;
	}//while

	if (!bFound)
	    return AAFRESULT_INVALID_PARAM;
	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::CreateValueFromName (
										 /*[in]*/ aafCharacter_constptr  Name,
										 /*[out]*/ ImplAAFPropertyValue ** ppPropVal)
{
	if (! ppPropVal )
		return AAFRESULT_NULL_PARAM;
	
	if (! Name )
		return AAFRESULT_NULL_PARAM;
	
	if (!IsRegistered())
		return AAFRESULT_NOT_INITIALIZED;
	
	
	//Now try to do a Name lookup
	aafInt64 the_value = 0;
	AAFRESULT rc;
	rc = LookupValByName(&the_value, Name);

	if (rc == AAFRESULT_INVALID_PARAM)
	{
	    // Built-In names changed from v1.0 -> v1.1
	    // to remove kAAF prefix. so we have to deal with both
	    // old and new style names. 
	    // The lookup on the originally provided name failed due to
	    // the name not being found (not some other error).
	    // So here we add kAAF if it isn't there or 
	    // remove kAAF if it is there. Then look up again.
	    aafCharacter *Name_mod;

	    if ( wcsncmp (Name, L"kAAF", 4) == 0 )
	    {
		// Look past kAAF
		Name_mod = new aafCharacter[wcslen(Name) - 3];
		wcscpy(Name_mod, Name + 4);
	    }
	    else
	    {
		// Prepend kAAF
		Name_mod = new aafCharacter[wcslen(Name) + 5];
		if (!Name_mod)
		    return AAFRESULT_NOMEMORY;
		wcscpy(Name_mod, L"kAAF");
		wcscat(Name_mod, Name);
	    }

	    // Look up again - Return checked later.
	    rc = LookupValByName(&the_value, Name_mod);

	    // Cleanup of allocated memory
	    delete[] Name_mod;
	}

	// At this point, we have a successful lookup and the_val is
	// set, the name was not found (even with variation), or
	// some other error occurred. Check the result and return
	// if we are not successful.
	check_hr( rc );
	
	//else FOUND
	
	// Get the size of the base integer type
	aafUInt32 localIntSize = NativeSize();

	switch (localIntSize)
	{
	case 1:
		aafInt8 i8Val;
		i8Val = (aafInt8) the_value;
		check_hr (  CreateValue (
			(aafMemPtr_t) &i8Val,
			1,  //size in bytes
			ppPropVal) );
		break;
		
	case 2:
		aafInt16 i16Val;
		i16Val = (aafInt16) the_value;
		check_hr (  CreateValue (
			(aafMemPtr_t) &i16Val,
			2,  //size in bytes
			ppPropVal) );
		break;
		
	case 4:
		aafInt32 i32Val;
		i32Val = (aafInt32) the_value;
		check_hr (  CreateValue (
			(aafMemPtr_t) &i32Val,
			4,  //size in bytes
			ppPropVal) );
		break;
		
	case 8:
		//64 bit ... which is the same as "the_value"
		check_hr (  CreateValue (
			(aafMemPtr_t) &the_value,
			8,  //size in bytes
			ppPropVal) );
		break;
	}//switch
	
	return AAFRESULT_SUCCESS;
	
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetNameFromValue (
									  ImplAAFPropertyValue * pValue,
									  wchar_t *  pName,
									  aafUInt32  bufSize)
{
	if (! pValue)
		return AAFRESULT_NULL_PARAM;
	
	if (! pName)
		return AAFRESULT_NULL_PARAM;
	

	//Extract the integer value from the PV;  use existing method on integer!
	// pValue type is validated in GetIntegerValue().
	aafInt64 val = 0;
	HRESULT	 hr = GetIntegerValue(pValue, &val);
	if( AAFRESULT_FAILED( hr ) )
	    return hr;
	
	//Use an existing method on integer, to find out the name!!! 
	return (GetNameFromInteger(val, pName, bufSize));
	
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetNameBufLenFromValue (
											ImplAAFPropertyValue * pValue,
											aafUInt32 *  pLen)
{
	if (! pValue)
		return AAFRESULT_NULL_PARAM;
	
	if (! pLen)
		return AAFRESULT_NULL_PARAM;
	
	//Extract the integer value from the PV;  use existing method on integer!
	// pValue type is validated in GetIntegerValue().
	aafInt64 val = 0;
	HRESULT	 hr = GetIntegerValue(pValue, &val);
	if( AAFRESULT_FAILED( hr ) )
	    return hr;
	
	//Use an existing method on integer, to find out the Buffer Length!!! 
	return (GetNameBufLenFromInteger(val, pLen));
	
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetNameFromInteger (
										aafInt64 value,
										wchar_t * pName,
										aafUInt32 bufSize)
{
	if (! pName)
		return AAFRESULT_NULL_PARAM;
	
	AAFRESULT hr;
	aafUInt32 len;
	// following call may return AAFRESULT_ILLEGAL_VALUE if value isn't
	// recognized
	hr = GetNameBufLenFromInteger (value, &len);
	if (AAFRESULT_FAILED(hr)) return hr;
	
	// len includes space for trailing null
	if (bufSize < len)
		return AAFRESULT_SMALLBUF;
	
	aafUInt32 i;
	aafUInt32 count;
	hr = CountElements(&count);
	if (AAFRESULT_FAILED(hr)) return hr;
	for (i = 0; i < count; i++)
	{
		aafInt64 val;
		hr = GetElementValue (i, &val);
		if (AAFRESULT_FAILED(hr)) return hr;
		if (val == value)
		{
			// given integer value matches value of "i"th element.
			hr = GetElementName(i, pName, bufSize);
			if (AAFRESULT_FAILED(hr)) return hr;
			return AAFRESULT_SUCCESS;
		}
	}
	// fell out of for() loop, so we didn't find it.
	// redundant, since GetNameBufLenFromInteger() should have already
	// found it.
	return AAFRESULT_ILLEGAL_VALUE;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetNameBufLenFromInteger (
											  aafInt64 value,
											  aafUInt32 * pLen)
{
	if (! pLen)
		return AAFRESULT_NULL_PARAM;
	
	aafUInt32 i;
	aafUInt32 count;
	AAFRESULT hr;
	hr = CountElements(&count);
	if (AAFRESULT_FAILED(hr))
		return hr;
	for (i = 0; i < count; i++)
	{
		aafInt64 val;
		hr = GetElementValue (i, &val);
		if (AAFRESULT_FAILED(hr)) return hr;
		if (val == value)
		{
			aafUInt32 len;
			hr = GetElementNameBufLen(i, &len);
			if (AAFRESULT_FAILED(hr)) return hr;
			ASSERTU (pLen);
			*pLen = len;
			return AAFRESULT_SUCCESS;
		}
	}
	// fell out of for() loop, so we didn't find it.
	return AAFRESULT_ILLEGAL_VALUE;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetIntegerValue (
									 ImplAAFPropertyValue * pPropValIn,
									 aafInt64 * pValueOut)
{
	if (! pPropValIn)
		return AAFRESULT_NULL_PARAM;
	if (! pValueOut)
		return AAFRESULT_NULL_PARAM;
	

	// Get the property value's embedded type and 
	// check if it's the same as the local type.
	ImplAAFTypeDefSP	spPropType;
	if( AAFRESULT_FAILED( pPropValIn->GetType( &spPropType ) ) )
		return AAFRESULT_BAD_TYPE;
	ASSERTU (spPropType);
	if( (ImplAAFTypeDef *)spPropType != this )
		return AAFRESULT_BAD_TYPE;


	ImplAAFTypeDefSP pBaseType;
	AAFRESULT hr;
	
	hr = GetElementType (&pBaseType);
	if (AAFRESULT_FAILED(hr)) return hr;
	
	eAAFTypeCategory_t baseTypeCat;
	hr = pBaseType->GetTypeCategory(&baseTypeCat);
	if (AAFRESULT_FAILED(hr)) return hr;
	ASSERTU(kAAFTypeCatInt == baseTypeCat);
	ImplAAFTypeDefIntSP ptdi;
	// This cast should succeed since we've already checked the type
	// category
	ptdi = dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef*)pBaseType);
	ASSERTU (ptdi);
	
	// Get the size of the base integer type
	aafUInt32 localIntSize;
	
	// BobT: Don't check the size of the underlying integral type;
	// instead check the native size of this enumeration to determine
	// the local representation.
	// hr = ptdi->GetSize (&baseIntSize);
	// if (AAFRESULT_FAILED(hr)) return hr;
	localIntSize = NativeSize();
	
	ImplAAFDictionarySP pDict;
	hr = GetDictionary(&pDict);
	ASSERTU (AAFRESULT_SUCCEEDED (hr));
	
	// Use a locally-looked-up type def to represent the local
	// underlying integer type.  This might be different than the
	// underlying integer type declared by AAF.
	ImplAAFTypeDefSP ptd;
	switch (localIntSize)
	{
	case 1:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int8, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 2:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int16, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 4:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int32, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 8:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int64, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	}
	ASSERTU (ptd);
	ImplAAFTypeDefInt * pLocalTd =
		dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef*) ptd);
	ASSERTU (pLocalTd);

	ASSERTU (pPropValIn);
	aafInt64 retval = 0;
	switch (localIntSize)
	{
	case 1:
		aafInt8 i8Val;
		hr = pLocalTd->GetInteger (pPropValIn,
			(aafMemPtr_t) &i8Val,
			sizeof (i8Val));
		if (AAFRESULT_FAILED(hr)) return hr;
		retval = i8Val;
		break;
		
	case 2:
		aafInt16 i16Val;
		hr = pLocalTd->GetInteger (pPropValIn,
			(aafMemPtr_t) &i16Val,
			sizeof (i16Val));
		if (AAFRESULT_FAILED(hr)) return hr;
		retval = i16Val;
		break;
		
	case 4:
		aafInt32 i32Val;
		hr = pLocalTd->GetInteger (pPropValIn,
			(aafMemPtr_t) &i32Val,
			sizeof (i32Val));
		if (AAFRESULT_FAILED(hr)) return hr;
		retval = i32Val;
		break;
		
	case 8:
		aafInt64 i64Val;
		hr = pLocalTd->GetInteger (pPropValIn,
			(aafMemPtr_t) &i64Val,
			sizeof (i64Val));
		if (AAFRESULT_FAILED(hr)) return hr;
		retval = i64Val;
		break;
		
	default:
		ASSERTU (0);
	}
	
	ASSERTU (pValueOut);
	*pValueOut = retval;
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::SetIntegerValue (
									 ImplAAFPropertyValue * pPropValToSet,
									 aafInt64 valueIn)
{
	if (! pPropValToSet)
		return AAFRESULT_NULL_PARAM;
	
	// Get the property value's embedded type and 
	// check if it's the same as the local type.
	ImplAAFTypeDefSP	spPropType;
	if( AAFRESULT_FAILED( pPropValToSet->GetType( &spPropType ) ) )
		return AAFRESULT_BAD_TYPE;
	ASSERTU (spPropType);
	if( (ImplAAFTypeDef *)spPropType != this )
		return AAFRESULT_BAD_TYPE;

	AAFRESULT hr;

	//check to see if the valueIn is a VALID enumeration 
	aafUInt32 actual_len = 0;
	hr =  GetNameBufLenFromInteger(valueIn, &actual_len) ;
	if (AAFRESULT_FAILED(hr)) 
		return hr;

	//valueIn is VALID.  Proceed .....

	ImplAAFTypeDefSP pBaseType;
	
	hr = GetElementType (&pBaseType);
	if (AAFRESULT_FAILED(hr)) return hr;
	
	eAAFTypeCategory_t baseTypeCat;
	hr = pBaseType->GetTypeCategory(&baseTypeCat);
	if (AAFRESULT_FAILED(hr)) return hr;
	ASSERTU(kAAFTypeCatInt == baseTypeCat);
	ImplAAFTypeDefIntSP ptdi;
	// This cast should succeed since we've already checked the type
	// category
	ptdi = dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef*)pBaseType);
	ASSERTU (ptdi);
	
	// Get the size of the base integer type
	aafUInt32 localIntSize;
	
	// BobT: Don't check the size of the underlying integral type;
	// instead check the native size of this enumeration to determine
	// the local representation.
	// hr = ptdi->GetSize (&baseIntSize);
	// if (AAFRESULT_FAILED(hr)) return hr;
	localIntSize = NativeSize();
	
	ImplAAFDictionarySP pDict;
	hr = GetDictionary(&pDict);
	ASSERTU (AAFRESULT_SUCCEEDED (hr));
	
	// Use a locally-looked-up type def to represent the local
	// underlying integer type.  This might be different than the
	// underlying integer type declared by AAF.
	ImplAAFTypeDefSP ptd;
	switch (localIntSize)
	{
	case 1:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int8, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 2:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int16, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 4:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int32, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	case 8:
		hr = pDict->LookupTypeDef (kAAFTypeID_Int64, &ptd);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		break;
	}
	ASSERTU (ptd);
	ImplAAFTypeDefInt * pLocalTd =
		dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef*) ptd);
	ASSERTU (pLocalTd);
	
	ASSERTU (pPropValToSet);
	switch (localIntSize)
	{
	case 1:
		aafInt8 i8Val;
		i8Val = (aafInt8) valueIn;
		check_hr (  pLocalTd->SetInteger (pPropValToSet,
			(aafMemPtr_t) &i8Val,
			1)  //size in bytes
			);
		break;
		
	case 2:
		aafInt16 i16Val;
		i16Val = (aafInt16) valueIn;
		check_hr (  pLocalTd->SetInteger (pPropValToSet,
			(aafMemPtr_t) &i16Val,
			2)  //size in bytes
			);
		break;
		
	case 4:
		aafInt32 i32Val;
		i32Val = (aafInt32) valueIn;
		check_hr (  pLocalTd->SetInteger (pPropValToSet,
			(aafMemPtr_t) &i32Val,
			4)  //size in bytes
			);
		break;
		
	case 8:
		aafInt64 i64Val;
		i64Val = (aafInt64) valueIn;
		check_hr (  pLocalTd->SetInteger (pPropValToSet,
			(aafMemPtr_t) &i64Val,
			8)  //size in bytes
			);
		break;
		
	default:
		ASSERTU (0);
	}
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::RegisterSize (aafUInt32  enumSize)
{
	_registeredSize = enumSize;
	_isRegistered = kAAFTrue;
	return AAFRESULT_SUCCESS;
}


// Override from AAFTypeDef
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetTypeCategory (eAAFTypeCategory_t * pTid)
{
	if (! pTid)
		return AAFRESULT_NULL_PARAM;
	
	ASSERTU (pTid);
	*pTid = kAAFTypeCatEnum;
	return AAFRESULT_SUCCESS;
}


//
// private method
//
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetElementName (
									aafUInt32 index,
									wchar_t * pName,
									aafUInt32  bufSize)
{
	AAFRESULT hr;
	aafUInt32 count;
	aafUInt32 indexIntoProp;
	aafUInt32 currentIndex;
	
	if (!pName) return AAFRESULT_NULL_PARAM;
	
	hr = CountElements(&count);
	if (AAFRESULT_FAILED(hr)) return hr;
	
	if (index >= count) return AAFRESULT_ILLEGAL_VALUE;
	
	wchar_t c;
	size_t numChars = _ElementNames.count();
	indexIntoProp = 0;
	currentIndex = 0;
	if (0 != index)
	{
		for (size_t i = 0; i < numChars; i++)
		{
			indexIntoProp++;
			_ElementNames.getValueAt(&c, i);
			if (0 == c)
			{
				// We've found the null just before the string we want.
				// We'll increment the indexIntoProp to the start of the
				// string and break out of the loop, but first make sure
				// there's more string there to index into.
				ASSERTU (i < numChars);
				currentIndex++;
				if (index == currentIndex)
					break;
			}
		}
		// Make sure we didn't terminate the loop by dropping out before
		// the correct index was found.
		ASSERTU (indexIntoProp < numChars);
	}
	
	// indexIntoProp now indicates the starting char we want.  Copy it
	// into the client's buffer.
	do
	{
		if (! bufSize) return AAFRESULT_SMALLBUF;
		_ElementNames.getValueAt(&c, indexIntoProp++);
		// BobT Note!!! We're cheating here, modifying client data
		// before we're sure this method will succeed.
		*pName++ = c;
		bufSize--;
	}
	while (c);
	return AAFRESULT_SUCCESS;
}



//
// private method
//
AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefEnum::GetElementNameBufLen (
										  aafUInt32  index,
										  aafUInt32 * pLen)
{
	AAFRESULT hr;
	aafUInt32 count;
	aafUInt32 indexIntoProp;
	aafUInt32 currentIndex;
	
	if (!pLen) return AAFRESULT_NULL_PARAM;
	
	hr = CountElements(&count);
	if (AAFRESULT_FAILED(hr)) return hr;
	
	if (index >= count) return AAFRESULT_ILLEGAL_VALUE;
	
	wchar_t c;
	size_t numChars = _ElementNames.count();
	indexIntoProp = 0;
	currentIndex = 0;
	if (0 != index)
	{
		for (size_t i = 0; i < numChars; i++)
		{
			indexIntoProp++;
			_ElementNames.getValueAt(&c, i);
			if (0 == c)
			{
				// We've found the null just before the string we want.
				// We'll increment the indexIntoProp to the start of the
				// string and break out of the loop, but first make sure
				// there's more string there to index into.
				ASSERTU (i < numChars);
				currentIndex++;
				if (index == currentIndex)
					break;
			}
		}
		// Make sure we didn't terminate the loop by dropping out before
		// the correct index was found.
		ASSERTU (indexIntoProp < numChars);
	}
	
	// indexIntoProp now indicates the starting char we want.  Start
	// counting until we get to the next null.
	aafUInt32 nameLength = 0;
	do
	{
		_ElementNames.getValueAt(&c, indexIntoProp++);
		if (c) nameLength += sizeof(wchar_t);
	}
	while (c);
	
	// increment once more for trailing null
	nameLength += sizeof (wchar_t);
	
	ASSERTU (pLen);
	*pLen = nameLength;
	return AAFRESULT_SUCCESS;
}


ImplAAFTypeDefSP ImplAAFTypeDefEnum::BaseType () const
{
	ImplAAFTypeDefSP result;
	AAFRESULT hr = GetElementType (&result);
	ASSERTU (AAFRESULT_SUCCEEDED (hr));
	ASSERTU (result);
	return result;
}

void ImplAAFTypeDefEnum::reorder(OMByte* externalBytes,
								 size_t externalBytesSize) const
{
	BaseType()->reorder (externalBytes, externalBytesSize);
}


size_t ImplAAFTypeDefEnum::externalSize(const OMByte* /*internalBytes*/,
										size_t /*internalBytesSize*/) const
{
	return PropValSize ();
}


void ImplAAFTypeDefEnum::externalize(const OMByte* internalBytes,
									 size_t internalBytesSize,
									 OMByte* externalBytes,
									 size_t externalBytesSize,
									 OMByteOrder byteOrder) const
{
	BaseType()->externalize (internalBytes,
		internalBytesSize,
		externalBytes,
		externalBytesSize,
		byteOrder);
}


size_t ImplAAFTypeDefEnum::internalSize(const OMByte* /*externalBytes*/,
										size_t /*externalBytesSize*/) const
{
	if (IsRegistered ())
		return NativeSize ();
	else
		return PropValSize ();
}


void ImplAAFTypeDefEnum::internalize(const OMByte* externalBytes,
									 size_t externalBytesSize,
									 OMByte* internalBytes,
									 size_t internalBytesSize,
									 OMByteOrder byteOrder) const
{
	BaseType()->internalize (externalBytes,
		externalBytesSize,
		internalBytes,
		internalBytesSize,
		byteOrder);
}



aafBool ImplAAFTypeDefEnum::IsFixedSize (void) const
{
	return kAAFTrue;
}


size_t ImplAAFTypeDefEnum::PropValSize (void) const
{
	return BaseType()->PropValSize ();
}


void ImplAAFTypeDefEnum::AttemptBuiltinRegistration (void)
{
	if (! _registrationAttempted)
	{
		ImplAAFDictionarySP pDict;
		AAFRESULT hr = GetDictionary(&pDict);
		ASSERTU (AAFRESULT_SUCCEEDED (hr));
		pDict->pvtAttemptBuiltinSizeRegistration (this);
		_registrationAttempted = kAAFTrue;
	}
}

aafBool ImplAAFTypeDefEnum::IsRegistered (void) const
{
	((ImplAAFTypeDefEnum*)this)->AttemptBuiltinRegistration ();
	return (_isRegistered ? kAAFTrue : kAAFFalse);
}


size_t ImplAAFTypeDefEnum::NativeSize (void) const
{
	if  (!IsRegistered())
	{
		//ASSERTU(0);  //hmmmm ... drastic

		//instead ... look to the _ElementType to get the size ...
		ImplAAFTypeDefInt *pTDInt;
		pTDInt = dynamic_cast<ImplAAFTypeDefInt*>((ImplAAFTypeDef *)_ElementType);
		ASSERTU (pTDInt);
		
		aafUInt32 elem_size = 0;
		pTDInt->GetSize(&elem_size);
		ASSERTU(elem_size);
		return elem_size;

	}
	return _registeredSize;
}


static OMProperty * pvtMakeProperty (OMPropertyId pid,
									 const wchar_t * name,
									 size_t size)
{
	if (0 == size) { ASSERTU (0); return 0; }
	else if (1 == size) { return new OMFixedSizeProperty<aafUInt8>(pid, name); }
	else if (2 == size) { return new OMFixedSizeProperty<aafUInt16>(pid, name); }
	else if (4 == size) { return new OMFixedSizeProperty<aafUInt32>(pid, name); }
	else if (8 == size) { return new OMFixedSizeProperty<aafInt64>(pid, name); }
	else if (sizeof(aafUID_t) == size) { return new OMFixedSizeProperty<aafUID_t>(pid, name); }
	else { ASSERTU (0); return 0; }
}


OMProperty * ImplAAFTypeDefEnum::pvtCreateOMProperty
(OMPropertyId pid,
 const wchar_t * name) const
{
	ASSERTU (name);
	size_t elemSize; // = NativeSize ();
	
	if (_isRegistered)
		elemSize = NativeSize();
	else
	{
		ImplAAFTypeDefInt *pTDInt;
		//look to the _ElementType to get the size ...
		pTDInt = dynamic_cast<ImplAAFTypeDefInt*>(bootstrapTypeWeakReference(_ElementType));
		ASSERTU (pTDInt);
		
		aafUInt32 elem_size = 0;
		pTDInt->GetSize(&elem_size);
		elemSize = (size_t) elem_size;
		ASSERTU(elemSize);

		//mark as REGISTERED .... Can't do this: l-value's are const!!!
		//_registeredSize = elemSize;
		//_isRegistered = kAAFTrue;
	}
	
	OMProperty * result = pvtMakeProperty (pid, name, elemSize);
	ASSERTU (result);
	return result;
}


bool ImplAAFTypeDefEnum::IsAggregatable () const
{ return true; }

bool ImplAAFTypeDefEnum::IsStreamable () const
{ return true; }

bool ImplAAFTypeDefEnum::IsFixedArrayable () const
{ return true; }

bool ImplAAFTypeDefEnum::IsVariableArrayable () const
{ return true; }

bool ImplAAFTypeDefEnum::IsStringable () const
{ return true; }






// override from OMStorable.
const OMClassId& ImplAAFTypeDefEnum::classId(void) const
{
	return (*reinterpret_cast<const OMClassId *>(&AUID_AAFTypeDefEnum));
}

// Override callbacks from OMStorable
void ImplAAFTypeDefEnum::onSave(void* clientContext) const
{
	ImplAAFTypeDef::onSave(clientContext);
}

void ImplAAFTypeDefEnum::onRestore(void* clientContext) const
{
	ImplAAFTypeDef::onRestore(clientContext);
}
