#ifndef __AxObject_h__
#define __AxObject_h__

//=---------------------------------------------------------------------=
//
// $Id: AxObject.h,v 1.8 2004/04/10 14:22:54 jptrainor Exp $ $Name:  $
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


#include "AxTypes.h"
#include "AxSmartPointer.h"
#include "AxBaseObj.h"

#include <memory>

class AxObject : public AxBaseObj {
public:

	AxObject();
	AxObject( const AxObject& );
	AxObject( IAAFObjectSP spIaafObject );
	virtual ~AxObject();

	AxString GetClassName();
	IAAFDictionarySP GetDictionary();

	IEnumAAFPropertiesSP GetProperties();

	IAAFClassDefSP GetDefinition();

	inline operator IAAFObjectSP ()
	{ return _spIaafObject; }

private:

	AxObject& operator=( const AxObject& );
	
	mutable IAAFObjectSP _spIaafObject;
};

#include "AxUtil.h"
inline AxString AxObject::GetClassName()
{
	return AxDefNameToString< IAAFObject, IAAFClassDef >( _spIaafObject );
}


#endif
