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

#include "AxObject.h"

#include <AAF.h>

#include "AxEx.h"
#include "AxUtil.h"

//=---------------------------------------------------------------------=

AxObject::AxObject()
{}

AxObject::AxObject( const AxObject& other )
:	_spIaafObject( other._spIaafObject )
{}

AxObject::AxObject( IAAFObjectSP spIaafObject )
:	AxBaseObj( AxQueryInterface<IAAFObject, IUnknown>(
				spIaafObject, IID_IUnknown) ),
	_spIaafObject( spIaafObject )
{}

AxObject::~AxObject()
{}

std::auto_ptr< AxString > AxObject::GetClassName() const
{
	return AxDefNameToString< IAAFObject, IAAFClassDef >( _spIaafObject );
}
	
AxPropertyIter AxObject::CreatePropertyIter() const
{
	IEnumAAFPropertiesSP spIEnumProperties;

	CHECK_HRESULT( _spIaafObject->GetProperties( &spIEnumProperties ) );
		
	AxPropertyIter propertyIter( spIEnumProperties );

	return propertyIter;
}

//=---------------------------------------------------------------------=
