//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: CAAFTypeDefWeakObjRef.cpp,v 1.10 2009/06/01 11:47:03 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=



#include "CAAFTypeDefWeakObjRef.h"
#include "ImplAAFTypeDefWeakObjRef.h"
#include "AAFResult.h"
#include "CAAFEnumValidation.h"

#include "OMAssertions.h"
#include "OMExceptions.h"

#include <assert.h>
#include <string.h>


#include "CAAFPropertyValue.h"
#include "ImplAAFPropertyValue.h"

#include "CAAFClassDef.h"
#include "ImplAAFClassDef.h"

// CLSID for AAFTypeDefWeakObjRef 
// {381e1f23-e7bb-11d2-842a-00600832acb8}
EXTERN_C const CLSID CLSID_AAFTypeDefWeakObjRef = { 0x381e1f23, 0xe7bb, 0x11d2, { 0x84, 0x2a, 0x00, 0x60, 0x08, 0x32, 0xac, 0xb8 } };





CAAFTypeDefWeakObjRef::CAAFTypeDefWeakObjRef (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFTypeDefObjectRef (pControllingUnknown, kAAFFalse)
{
  if (doInit)
    {
      ImplAAFTypeDefWeakObjRef * newRep;
      newRep = new ImplAAFTypeDefWeakObjRef;
      assert (newRep);
      InitRep (newRep);
    }
}


CAAFTypeDefWeakObjRef::~CAAFTypeDefWeakObjRef ()
{
}


HRESULT STDMETHODCALLTYPE
    CAAFTypeDefWeakObjRef::Initialize (aafUID_constref  id,
        IAAFClassDef * pObjType,
        aafCharacter_constptr  pTypeName,
        aafUInt32  ids,
        aafUID_constptr  pTargetSet)
{
  HRESULT hr;

  ImplAAFTypeDefWeakObjRef * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplAAFTypeDefWeakObjRef*> (pO);
  assert (ptr);

  //
  // set up for pObjType
  //
  ImplAAFClassDef * internalpObjType = NULL;
  if (pObjType)
    {
      HRESULT hStat;
      IAAFRoot * iObj;
      ImplAAFRoot *arg;
      hStat = pObjType->QueryInterface (IID_IAAFRoot, (void **)&iObj);
      assert (SUCCEEDED (hStat));
      assert (iObj);
      hStat = iObj->GetImplRep((void **)&arg);
      assert (SUCCEEDED (hStat));
      iObj->Release(); // we are through with this interface pointer.
      internalpObjType = static_cast<ImplAAFClassDef*>(arg);
      assert (internalpObjType);
    }

  try
    {
      hr = ptr->Initialize
       (id,
        internalpObjType,
        pTypeName,
        ids,
        pTargetSet);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // no cleanup necessary for pObjType
  //
  return hr;
}

//
// 
// 
inline int EQUAL_UID(const GUID & a, const GUID & b)
{
  return (0 == memcmp((&a), (&b), sizeof (aafUID_t)));
}
HRESULT CAAFTypeDefWeakObjRef::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (EQUAL_UID(riid,IID_IAAFTypeDefWeakObjRef)) 
    { 
        *ppvObj = (IAAFTypeDefWeakObjRef *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFTypeDefObjectRef::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
AAF_DEFINE_FACTORY(AAFTypeDefWeakObjRef)

