//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: CAAFCachePageAllocator.cpp,v 1.1 2005/09/07 17:51:48 montrowe Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=



#include "CAAFCachePageAllocator.h"
#include "ImplAAFCachePageAllocator.h"
#include "AAFResult.h"
#include "CAAFEnumValidation.h"

#include "OMAssertions.h"
#include "OMExceptions.h"

#include <assert.h>
#include <string.h>


// CLSID for AAFCachePageAllocator 
// {EA131C6C-C57C-4F64-A81B-2362A2EC44CA}
EXTERN_C const CLSID CLSID_AAFCachePageAllocator = { 0xEA131C6C, 0xC57C, 0x4F64, { 0xA8, 0x1B, 0x23, 0x62, 0xA2, 0xEC, 0x44, 0xCA } };





CAAFCachePageAllocator::CAAFCachePageAllocator (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFRoot (pControllingUnknown, kAAFFalse)
{
  if (doInit)
    {
      ImplAAFCachePageAllocator * newRep;
      newRep = new ImplAAFCachePageAllocator;
      assert (newRep);
      InitRep (newRep);
    }
}


CAAFCachePageAllocator::~CAAFCachePageAllocator ()
{
}


HRESULT STDMETHODCALLTYPE
    CAAFCachePageAllocator::Initialize (aafUInt32  pageCount,
        aafUInt32  pageSize)
{
  HRESULT hr;

  ImplAAFCachePageAllocator * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplAAFCachePageAllocator*> (pO);
  assert (ptr);


  try
    {
      hr = ptr->Initialize
       (pageCount,
        pageSize);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UNEXPECTED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNEXPECTED_EXCEPTION);
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

  return hr;
}


HRESULT STDMETHODCALLTYPE
    CAAFCachePageAllocator::Allocate (aafMemPtr_t *  pPage)
{
  HRESULT hr;

  ImplAAFCachePageAllocator * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplAAFCachePageAllocator*> (pO);
  assert (ptr);


  try
    {
      hr = ptr->Allocate
       (pPage);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UNEXPECTED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNEXPECTED_EXCEPTION);
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

  return hr;
}


HRESULT STDMETHODCALLTYPE
    CAAFCachePageAllocator::Deallocate (aafMemPtr_t  page)
{
  HRESULT hr;

  ImplAAFCachePageAllocator * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplAAFCachePageAllocator*> (pO);
  assert (ptr);


  try
    {
      hr = ptr->Deallocate
       (page);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UNEXPECTED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNEXPECTED_EXCEPTION);
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

  return hr;
}


//
// 
// 
inline int EQUAL_UID(const GUID & a, const GUID & b)
{
  return (0 == memcmp((&a), (&b), sizeof (aafUID_t)));
}
HRESULT CAAFCachePageAllocator::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (EQUAL_UID(riid,IID_IAAFCachePageAllocator)) 
    { 
        *ppvObj = (IAAFCachePageAllocator *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFRoot::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
AAF_DEFINE_FACTORY(AAFCachePageAllocator)
