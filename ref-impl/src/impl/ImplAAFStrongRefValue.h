//@doc
//@class    AAFStrongRefValue | Implementation class for AAFStrongRefValue
#ifndef __ImplAAFStrongRefValue_h__
#define __ImplAAFStrongRefValue_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFStrongRefValue.h,v 1.4 2004/02/27 14:26:48 stuart_hc Exp $ $Name:  $
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



#ifndef __ImplAAFRefValue_h__
#include "ImplAAFRefValue.h"
#endif

class ImplAAFTypeDefStrongObjRef;

class ImplAAFStrongRefValue : public ImplAAFRefValue
{
public:

  //
  // Constructor/destructor
  //
  //********
  ImplAAFStrongRefValue ();
  
protected:
  virtual ~ImplAAFStrongRefValue ();
  
public:
  // non-published method to initialize this object.
  // Initialize an instance from a type definition. This is the "old-style"
  // "non-direct" access initialization method. 
  AAFRESULT Initialize (const ImplAAFTypeDefStrongObjRef *referenceType);

  // non-published method to initialize this object.
  // NOTE: The given property's type must be a reference type.
  AAFRESULT Initialize (const ImplAAFTypeDefStrongObjRef *referenceType,
                        OMProperty *property);

  virtual AAFRESULT STDMETHODCALLTYPE GetObject(ImplAAFStorable **ppObject) const;
  virtual AAFRESULT STDMETHODCALLTYPE SetObject(ImplAAFStorable *pObject);

  virtual AAFRESULT STDMETHODCALLTYPE WriteTo(OMProperty* pOmProp);
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFStrongRefValue> ImplAAFStrongRefValueSP;

#endif // ! __ImplAAFStrongRefValue_h__
