//=---------------------------------------------------------------------=
//
// $Id: AxObject.cpp,v 1.8.2.1 2004/06/08 13:45:23 stuart_hc Exp $ $Name:  $
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
//=---------------------------------------------------------------------=

#include "AxObject.h"

#include <AAF.h>

#include "AxEx.h"
#include "AxUtil.h"

//=---------------------------------------------------------------------=

//AxObject::AxObject()
//{}

AxObject::AxObject( const AxObject& other )
:	AxBaseObj( AxQueryInterface<IAAFObject, IUnknown>(other._spIaafObject) ),
	_spIaafObject( other._spIaafObject )
{}

AxObject::AxObject( IAAFObjectSP spIaafObject )
:	AxBaseObj( AxQueryInterface<IAAFObject, IUnknown>(spIaafObject) ),
	_spIaafObject( spIaafObject )
{}

AxObject::~AxObject()
{}

IAAFDictionarySP AxObject::GetDictionary()
{
	IAAFDictionarySP spIaafDictionary;

	CHECK_HRESULT( _spIaafObject->GetDictionary( &spIaafDictionary ) );

	return spIaafDictionary;
}

IEnumAAFPropertiesSP AxObject::GetProperties()
{
  IEnumAAFPropertiesSP spIEnumProperties;

  CHECK_HRESULT( _spIaafObject->GetProperties( &spIEnumProperties ) );

  return spIEnumProperties;
}

//=---------------------------------------------------------------------=

IAAFClassDefSP AxObject::GetDefinition()
{
  IAAFClassDefSP spIaafClassDef;

  CHECK_HRESULT( _spIaafObject->GetDefinition( &spIaafClassDef ) );

  return spIaafClassDef;
}


//=---------------------------------------------------------------------=
