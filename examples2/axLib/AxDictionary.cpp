//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
//=---------------------------------------------------------------------=

#include "AxDictionary.h"

#include <AAFResult.h>

AxDictionary::AxDictionary( IAAFDictionarySP spIaafDictionary )
:	AxObject( AxQueryInterface<IAAFDictionary, IAAFObject>(spIaafDictionary) ),
	_spIaafDictionary( spIaafDictionary )
{}

AxDictionary::~AxDictionary()
{}

bool AxDictionary::isKnownTypeDef( const aafUID_t& typeId )
{
	IAAFTypeDefSP spIaafTypeDef;

	HRESULT hr = _spIaafDictionary->LookupTypeDef( typeId, &spIaafTypeDef );

	bool result = true;

	// We accept AAFRESULT_NO_MORE_OBJECTS (i.e. not known), or 
	// AAFRESULT_SUCCESS (known).  Anything else throws.

	// FIXME - This is not a documented return value!  (FIXDOCS)
	if ( AAFRESULT_NO_MORE_OBJECTS == hr ) {
		result = false;
	}
	else if ( AAFRESULT_SUCCESS != hr ) {
		CHECK_HRESULT( hr );
	}

	return result;
}

bool AxDictionary::isKnownOperationDef( const aafUID_t& opId )
{
	IAAFOperationDefSP spIaafOperationDef;

	HRESULT hr = _spIaafDictionary->LookupOperationDef( opId, &spIaafOperationDef );

	bool result = true;

	// We accept AAFRESULT_NO_MORE_OBJECTS (i.e. not known), or 
	// AAFRESULT_SUCCESS (known).  Anything else throws.

	// FIXME - This is not a documented return value!  (FIXDOCS)
	if ( AAFRESULT_NO_MORE_OBJECTS == hr ) {
		result = false;
	}
	else if ( AAFRESULT_SUCCESS != hr ) {
		CHECK_HRESULT( hr );
	}

	return result;
}

void AxDictionary::RegisterClassDef( IAAFClassDefSP spIaafClassDef )
{
	CHECK_HRESULT( _spIaafDictionary->RegisterClassDef( spIaafClassDef ) );
}

IAAFTypeDefSP AxDictionary::LookupTypeDef( const aafUID_t& typeId )
{
	IAAFTypeDefSP spTypeDef;

	CHECK_HRESULT( _spIaafDictionary->LookupTypeDef( typeId, &spTypeDef ) );

	return spTypeDef;
}

IAAFClassDefSP AxDictionary::LookupClassDef( aafUID_constref  classId )
{
	IAAFClassDefSP spIaafClassDef;

	CHECK_HRESULT( _spIaafDictionary->LookupClassDef( classId, &spIaafClassDef ) );

	return spIaafClassDef;
}

IAAFDataDefSP AxDictionary::LookupDataDef( aafUID_constref  dataDefinitionId )
{
	IAAFDataDefSP spDataDef;

	CHECK_HRESULT( _spIaafDictionary->LookupDataDef( dataDefinitionId, &spDataDef ) );

	return spDataDef;
}

IAAFOperationDefSP AxDictionary::LookupOperationDef( const aafUID_t& opDefId )
{
	IAAFOperationDefSP spIaafOperationDef;

	CHECK_HRESULT( _spIaafDictionary->LookupOperationDef( opDefId, &spIaafOperationDef ) );

	return spIaafOperationDef;
}

IAAFContainerDefSP AxDictionary::LookupContainerDef( const aafUID_t& contDefId )
{
	IAAFContainerDefSP spIaafContainerDef;

	CHECK_HRESULT( _spIaafDictionary->LookupContainerDef( contDefId, &spIaafContainerDef ) );

	return spIaafContainerDef;
}

IAAFCodecDefSP AxDictionary::LookupCodecDef( const aafUID_t& codecDefId )
{
	IAAFCodecDefSP spIaafCodecDef;

	CHECK_HRESULT( _spIaafDictionary->LookupCodecDef( codecDefId, &spIaafCodecDef ) );

	return spIaafCodecDef;
}

IEnumAAFClassDefsSP AxDictionary::GetClassDefs()
{
	IEnumAAFClassDefsSP spIEnumAAFClassDefs;

	CHECK_HRESULT( _spIaafDictionary->GetClassDefs( &spIEnumAAFClassDefs ) );

	return spIEnumAAFClassDefs;
}

IEnumAAFTypeDefsSP AxDictionary::GetTypeDefs()
{
	IEnumAAFTypeDefsSP spIEnumAAFTypeDefs;

	CHECK_HRESULT( _spIaafDictionary->GetTypeDefs( &spIEnumAAFTypeDefs ) );

	return spIEnumAAFTypeDefs;
}

IEnumAAFDataDefsSP AxDictionary::GetDataDefs()
{
	IEnumAAFDataDefsSP spIEnumAAFDataDefs;

	CHECK_HRESULT( _spIaafDictionary->GetDataDefs( &spIEnumAAFDataDefs ) );

	return spIEnumAAFDataDefs;
}

IEnumAAFOperationDefsSP AxDictionary::GetOperationDefs()
{
	IEnumAAFOperationDefsSP spIEnumAAFOperationDefs;

	CHECK_HRESULT( _spIaafDictionary->GetOperationDefs( &spIEnumAAFOperationDefs ) );

	return spIEnumAAFOperationDefs;
}

IEnumAAFParameterDefsSP AxDictionary::GetParameterDefs()
{
	IEnumAAFParameterDefsSP spIEnumAAFParameterDefs;

	CHECK_HRESULT( _spIaafDictionary->GetParameterDefs( &spIEnumAAFParameterDefs ) );

	return spIEnumAAFParameterDefs;
}

void AxDictionary::RegisterOpaqueTypeDef( IAAFTypeDefSP spTypeDef )
{
	CHECK_HRESULT( _spIaafDictionary->RegisterOpaqueTypeDef( spTypeDef ) );
}

void AxDictionary::RegisterKLVDataKey( const aafUID_t& uuid,
				       IAAFTypeDefSP spTypeDef )
{
	CHECK_HRESULT( _spIaafDictionary->RegisterKLVDataKey( uuid, spTypeDef ) );
}

void AxDictionary::RegisterOperationDef( IAAFOperationDefSP spIaafOperationDef )
{
	CHECK_HRESULT( _spIaafDictionary->RegisterOperationDef( spIaafOperationDef ) );
}

void AxDictionary::RegisterCodecDef( IAAFCodecDefSP spIaafCodecDef)
{
	CHECK_HRESULT( _spIaafDictionary->RegisterCodecDef( spIaafCodecDef ) );
}

IUnknownSP AxDictionary::CreateInstance( const aafUID_t& auid,
				  					     const IID& iid )
{
	IUnknownSP spIUnknown;

	CHECK_HRESULT( _spIaafDictionary->CreateInstance( auid, iid, &spIUnknown ) );

	return spIUnknown;
}

IUnknownSP AxDictionary::CreateMetaInstance( const aafUID_t& auid,
				  				 		     const IID& iid )
{
	IUnknownSP spIUnknown;

	CHECK_HRESULT( _spIaafDictionary->CreateMetaInstance( auid, iid, &spIUnknown ) );

	return spIUnknown;
}

aafUInt32 AxDictionary::CountOpaqueTypeDefs()
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafDictionary->CountOpaqueTypeDefs( &count ) );

	return count;
}

