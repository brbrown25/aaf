#ifndef __AxHrMap_h__
#define __AxHrMap_h__

//=---------------------------------------------------------------------=
//
// $Id: AxHrMap.h,v 1.6 2005/01/11 09:21:06 jfpanisset Exp $ $Name:  $
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

#include <AAFCOMPlatform.h>

#include <map>

// gcc3 complains that AxHrMap has a private destructor
// and no friends.  This prevents the warning.
class AxHrMapFriend_nonexistant;

class AxHrMap {

public:
	virtual ~AxHrMap();

	static const AxHrMap& getInstance();

	const AxString& getStr( HRESULT hr ) const;

private:

	friend class AxHrMapFriend_nonexistant;

	AxHrMap();
	AxHrMap( const AxHrMap& );
	AxHrMap& operator=( const AxHrMap& );

	std::map<HRESULT,AxString> _map;
};

#endif



