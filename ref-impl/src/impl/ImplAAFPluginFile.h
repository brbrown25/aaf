//=---------------------------------------------------------------------=
//
// $Id: ImplAAFPluginFile.h,v 1.5 2004/02/27 14:26:48 stuart_hc Exp $ $Name:  $
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

#ifndef __ImplAAFPluginFile_h__
#define __ImplAAFPluginFile_h__


#include "AAFTypes.h"

//***********************************************************
// Define function prototypes in a manner consistent with the 
// ActiveX and OLE SDK's.

#if !defined(_MSC_VER)

typedef STDAPICALLTYPE HRESULT (* LPFNAAFCANUNLOADNOW)();

typedef STDAPICALLTYPE HRESULT (* LPFNAAFGETCLASSOBJECT)(
    REFCLSID rclsid, REFIID riid, LPVOID* ppv);

typedef STDAPICALLTYPE ULONG (* LPFNAAFGETCLASSCOUNT)();

typedef STDAPICALLTYPE HRESULT (* LPFNAAFGETCLASSOBJECTID)(
    ULONG index, CLSID* pclsid);



#else

typedef HRESULT (STDAPICALLTYPE * LPFNAAFCANUNLOADNOW)();

typedef HRESULT (STDAPICALLTYPE * LPFNAAFGETCLASSOBJECT)(
    REFCLSID rclsid, REFIID riid, LPVOID* ppv);

typedef ULONG (STDAPICALLTYPE * LPFNAAFGETCLASSCOUNT)();

typedef HRESULT (STDAPICALLTYPE * LPFNAAFGETCLASSOBJECTID)(
    ULONG index, CLSID* pclsid);

#endif




class ImplAAFPluginFile
{
protected:
  ImplAAFPluginFile(const char *name);

  ~ImplAAFPluginFile();

  
public:
  // Factory method. Objects are created in a "loaded" (ie IsLoaded() will return true)
  // A file is successfully loaded if ALL of the expected entry points could
  // found.
  static HRESULT CreatePluginFile(const char* name, ImplAAFPluginFile** ppPluginFile);

  // Reference Counting interface
  virtual aafUInt32 AcquireReference() const;
  virtual aafUInt32 ReleaseReference();
  virtual aafUInt32 ReferenceCount() const;
  
  //
  // Wrapper methods for exported dll functions:
  //
  HRESULT CanUnloadNow();
  HRESULT GetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);

  ULONG GetClassCount();
  HRESULT GetClassObjectID(ULONG index, CLSID* pclsid);

  //
  // Utility methods
  //
  bool IsLoaded() const;
  HRESULT Load();
  HRESULT Unload();

protected:
  void ClearEntryPoints();


private:
  //
  // Reference count for this instance:
  aafUInt32 _refCount;
  //
  // Name of the loaded plugin.
  //
  const char* _name;

	//
	// Platform independent (opaque) handle to the loaded dynamic library.
	//
	void * _libHandle;

  //
  // Callback function member data
  //

  // COM DLL callbacks
  LPFNAAFCANUNLOADNOW _pfnCanUnloadNow;
  LPFNAAFGETCLASSOBJECT _pfnGetClassObject;

  // AAF Plugins must implement and export these callbacks
  LPFNAAFGETCLASSCOUNT _pfnGetClassCount;
  LPFNAAFGETCLASSOBJECTID _pfnGetClassObjectID;
};


#endif /* __ImplAAFPluginFile_h__ */
