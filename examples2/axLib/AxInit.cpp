//=---------------------------------------------------------------------=
//
// $Id: AxInit.cpp,v 1.3 2004/02/27 14:26:38 stuart_hc Exp $ $Name:  $
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

#include "AxInit.h"

#include "AxSmartPointer.h"
#include "AxEx.h"
#include "AxHrMap.h"
#include "AxPluginMgr.h"

#include <AAF.h>

#include <stdlib.h>

bool AxInit::once = false;

AxInit::AxInit()
{
	if ( once ) {
		throw AxEx( L"Multiple AxInit instances not permited." );
	}
	
	// Force the AxHrMap singleton to init to that it doesn't happen
	// the first time an exception is handled.
	AxHrMap::getInstance();

	const char *dllname = getenv("AX_AAF_COMAPI");

	CHECK_HRESULT( AAFLoad( dllname ) );

	AxPluginMgr mgr;
	mgr.RegisterSharedPlugins();
 
	once = true;
}

AxInit::~AxInit()
{
	AAFUnload();

	once = false;
}
