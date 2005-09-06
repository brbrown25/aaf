#ifndef __ImplAAFPropertyValue_h__
#define __ImplAAFPropertyValue_h__
//=---------------------------------------------------------------------=
//
// $Id: ImplAAFPropertyValue.h,v 1.18 2005/09/06 12:43:24 montrowe Exp $ $Name:  $
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


class ImplAAFTypeDef;


#ifndef __ImplAAFRoot_h__
#include "ImplAAFRoot.h"
#endif

class OMProperty;
class OMDataStreamAccess;

class ImplAAFPropertyValue : public ImplAAFRoot
{
public:
  //
  // Constructor
  //
  //********
  ImplAAFPropertyValue ();

  //****************
  // GetType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetType
        // @parm [out] The type definition associated with this property value
        (ImplAAFTypeDef ** ppTypeDef) const;


  //****************
  // IsDefinedType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    IsDefinedType
        // @parm [out] result
        (aafBool *  pIsDefined);


  virtual AAFRESULT STDMETHODCALLTYPE WriteTo(OMProperty* pOmProp);


protected:
  //
  // Destructor
  //
  //********
  virtual ~ImplAAFPropertyValue ();
  
  // Install the property.
  void SetProperty(OMProperty * pProperty);
  
  // non-published method to initialize this object.
  // Initialize an instance from a type definition. This is the "old-style"
  // "non-direct" access initialization method. 
  AAFRESULT Initialize (const ImplAAFTypeDef *propertyType);

  // non-published method to initialize this object.
  // Initialize the instance from the given type and property. This is the new
  // more "direct" access initialization method. NOTE: The given type must be the
  // same instance as the type in the given property.
  AAFRESULT Initialize (const ImplAAFTypeDef *propertyType,
                        OMProperty *property);

  //****************
  //
  // non-published method to set up one of these.
  //
  AAFRESULT SetType (const ImplAAFTypeDef * pType);

  const ImplAAFTypeDef * pvtGetType (void) const;
  
  // accessor methods for subclasses:
  const ImplAAFTypeDef *type(void) const;
  OMProperty *property(void) const;
  ImplAAFRoot *propertyContainer(void) const;

private:
  // type of this property
  const ImplAAFTypeDef * _pType;
  
  OMProperty *_property; // The property associated with this property value.
  ImplAAFRoot *_propertyContainer; // The object that owns the property.
 };

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFPropertyValue> ImplAAFPropertyValueSP;

#endif // ! __ImplAAFPropertyValue_h__
