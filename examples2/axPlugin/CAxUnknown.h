#ifndef __CAxUnknown_h__
#define __CAxUnknown_h__

//=---------------------------------------------------------------------=
//
// $Id: CAxUnknown.h,v 1.6 2004/02/27 14:26:39 stuart_hc Exp $ $Name:  $
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

#include <AAFCOMPlatform.h>

#include "AxPluginUtil.h"

// CAxUnkown is a standard implementation of IUnkown.
//
// Credits:
//
// The CAxUnknown implementation is a (very) slightly modified version
// of the IUnknown implementation presented in:
// "Inside COM", Dale Rogerson, Microsoft Press
//
// Modifications include:
// - The CAxUnknown class methods have been declared using the AAF SDK
// STDMETHOD macros.
// - The use of the windows specific InterlockedIncrement,
// and InterlockedDecrement, have been removed.  This version
// of the code is, therefor, not thread safe.  The AAF SDK, is not
// thread safe to begin with, hence, this is a non-issue.
//
// "Inside COM" should be referenced for a full explanation of the
// "INondelegatingUnkown" interface.  Suffice to say, the
//  INondelegatingUnknown interface exists to satisfy the requirements
//  of COM object aggregation.  Classes that derive from CAxUnkown
//  must provide an implementation of IUnknown that delagates calls
//  to the aggregating (i.e. "outer") object if it exists.  At the
//  same time, CAxUnkown must provide the outer object with an independent
//  implementation of IUnknown that does not delegate to the outer object.
//  This is the purpose of INondelegatingUnknown.  Insofar as the vtable
//  (and the COM binary interface specification) is concerned,
//  INondelgatingUnkonw is identical to IUnkown.  Hence,
//  a pointer to INondelegatingUnkown can be used in place of a pointer
//  to IUnkown.  CAxUnknown::QueryInterface() uses this fact to provide
//  its own independent implementation of IUnkown (the non delegating implementation).
//  At the same time, classes that derive from CAxUnkown can implement IUnknown
//  by delegating the IUknown interface calls to the outer object.
//
//  HOW TO USE CAxUnkown:
// 
//  Classes that derive from CAxUnkown *must* use the
//  CAXUNKNOWN_DECLARE_IUNKNOWN_METHODS to declare (and define)
//  their IUnkown implementation.  For example:
//
//     class CMyComponent : public IAnInterface : CAxUnkown {
//        public:
//          // IUnkown methods provided by the following macro
//          CAXUNKNOWN_DECLARE_IUNKNOWN_METHODS
//		
//          // IAnInterface method declarations follow...
//		    .
//		    .
//		    .
//       };
//
//       ... in case you are wondering, IAnInterface is assumed to derive
//       from IUnknown.
//

///////////////////////////////////////////////////////////
//
// Nondelegating IUnknown interface
//   - Nondelegating version of IUnknown
//

#if defined( OS_MACOS )

// MacOS just had to be different...
// These DECLARE_INTERFACE macros come from AAFMacSDK/MacOLE/Include/compobj.h
// The second version (i.e. with __comobject) is currently used, but
// the entire set are included here for reference.
// INondelegatingUnknown must be declared *identically* to IUnknown to ensure 
// their vtable layouts match.  Hence this crud.

#if defined(applec)
// MPW declaration to force SI vtable construction.
DECLARE_INTERFACE_(INondelegatingUnknown, SingleObject)
#elif   defined(__MWERKS__)
// jjo For testing with CW9 with __comobject compiler path from Andreas Hommel 
DECLARE_INTERFACE_(INondelegatingUnknown, __comobject)
#else
DECLARE_INTERFACE(INondelegatingUnknown)
#endif
{
	BEGIN_INTERFACE
	STDMETHOD(NondelegatingQueryInterface)(const IID& iid, void** ppv) = 0 ;
	STDMETHOD_(ULONG, NondelegatingAddRef)() = 0 ;
	STDMETHOD_(ULONG, NondelegatingRelease)() = 0 ;
} ;

#else

interface INondelegatingUnknown
{
	STDMETHOD(NondelegatingQueryInterface)(const IID& iid, void** ppv) = 0 ;
	STDMETHOD_(ULONG, NondelegatingAddRef)() = 0 ;
	STDMETHOD_(ULONG, NondelegatingRelease)() = 0 ;
} ;

#endif

///////////////////////////////////////////////////////////
//
// Declaration of CAxUnknown 
//   - Base class for implementing IUnknown
//

class CAxUnknown : public INondelegatingUnknown
{
public:

	// Nondelegating IUnknown implementation
	STDMETHOD(NondelegatingQueryInterface)(const IID&, void**);
	STDMETHOD_(ULONG,NondelegatingAddRef)();
	STDMETHOD_(ULONG,NondelegatingRelease)();

	// Constructor
	CAxUnknown(IUnknown* pUnknownOuter);

	// Destructor
	virtual ~CAxUnknown();

	// Initialization (especially for aggregates)
	STDMETHOD(Init)()
		{ return S_OK; }

	// Notification to derived classes that we are releasing
	STDMETHOD_(void, FinalRelease)();

	// Count of currently active components
	static long GetActiveComponents() 
		{ return s_cActiveComponents; }
	
	// Helper function
	HRESULT FinishQI(IUnknown* pI, void** ppv);

protected:

	// Support for delegation
	IUnknown* GetOuterUnknown() const
		{ return m_pUnknownOuter; }

private:
	// Reference count for this object
	long m_cRef ;
	
	// Pointer to (external) outer IUnknown
	IUnknown* m_pUnknownOuter ;

	// Count of all active instances
	static long s_cActiveComponents ; 
};


///////////////////////////////////////////////////////////
//
// Delegating IUnknown
//   - Delegates to the nondelegating IUnknown, or to the
//     outer IUnknown if the component is aggregated.
//
#define CAXUNKNOWN_DECLARE_IUNKNOWN_METHODS		             \
	STDMETHOD(QueryInterface)(const IID& iid, void** ppv)    \
	{	                                                     \
		return GetOuterUnknown()->QueryInterface(iid,ppv) ;  \
	} ;	                                                     \
	STDMETHOD_(ULONG, AddRef)()	                             \
	{	                                                     \
		return GetOuterUnknown()->AddRef() ;                 \
	} ;	                                                     \
	STDMETHOD_(ULONG, Release)() 	                         \
	{	                                                     \
		return GetOuterUnknown()->Release() ;                \
	} ;


#endif
