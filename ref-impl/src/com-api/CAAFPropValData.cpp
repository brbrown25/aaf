//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
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
// The Initial Developer of the Original Code of this file and the 
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=



#include "CAAFPropValData.h"
#include "ImplAAFPropValData.h"
#include "AAFResult.h"
#include "CAAFEnumValidation.h"

class OMAssertionViolation;

#include <assert.h>
#include <string.h>


// CLSID for AAFPropValData 
// {106bb6e1-f0c1-11d2-842c-00600832acb8}
EXTERN_C const CLSID CLSID_AAFPropValData = { 0x106bb6e1, 0xf0c1, 0x11d2, { 0x84, 0x2c, 0x00, 0x60, 0x08, 0x32, 0xac, 0xb8 } };





CAAFPropValData::CAAFPropValData (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFPropertyValue (pControllingUnknown, kAAFFalse)
{
  if (doInit)
    {
      ImplAAFPropValData * newRep;
      newRep = new ImplAAFPropValData;
      assert (newRep);
      InitRep (newRep);
    }
}


CAAFPropValData::~CAAFPropValData ()
{
}


//
// 
// 
inline int EQUAL_UID(const GUID & a, const GUID & b)
{
  return (0 == memcmp((&a), (&b), sizeof (aafUID_t)));
}
HRESULT CAAFPropValData::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    HRESULT hr = S_OK;

    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (EQUAL_UID(riid,IID_IAAFPropValData)) 
    { 
        *ppvObj = (IAAFPropValData *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFPropertyValue::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
AAF_DEFINE_FACTORY(AAFPropValData)

