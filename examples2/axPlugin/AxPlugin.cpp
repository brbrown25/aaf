//=---------------------------------------------------------------------=
//
// $Id: AxPlugin.cpp,v 1.3 2004/02/27 14:26:39 stuart_hc Exp $ $Name:  $
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



#include "AxPlugin.h"

#include "AxPluginRegistry.h"
#include "CAxClassFactory.h"
#include "CAxNullEssenceCodec.h"
#include "CAxUnknown.h"

bool AxPlugin::CanUnloadNow()
{
	// CanUnload if:
	//	- no CAxUnknown objects still exist
	//	- no factory objects still exist
	//	- the lock count is zero

	if ( 0 == CAxUnknown::GetActiveComponents() &&
		 0 == CAxClassFactoryCounters::GetInstanceCount() &&
		 0 == CAxClassFactoryCounters::GetLockCount() ) {
		return true;
	}

	return false;
}

unsigned int AxPlugin::GetClassCount()
{
	return AxPluginRegistry::GetInstance().GetClassCount();
}

HRESULT AxPlugin::GetClassObjectID(ULONG index, CLSID *pClassID)
{
	return AxPluginRegistry::GetInstance().GetClassObjectID( index, pClassID );
}

HRESULT AxPlugin::GetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return AxPluginRegistry::GetInstance().GetClassObject( rclsid, riid, ppv );
}
