//@doc
//@class    AAFTypeDefObjectRef | Implementation class for AAFTypeDefObjectRef
#ifndef __ImplAAFTypeDefObjectRef_h__
#define __ImplAAFTypeDefObjectRef_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFTypeDefObjectRef.h,v 1.22 2006/06/15 19:53:15 tbingham Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2006, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=


class ImplAAFPropertyValue;
class ImplAAFRoot;
class ImplAAFClassDef;





#ifndef __ImplAAFTypeDef_h__
#include "ImplAAFTypeDef.h"
#endif


class ImplAAFTypeDefObjectRef : public ImplAAFTypeDef
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFTypeDefObjectRef ();

protected:
  virtual ~ImplAAFTypeDefObjectRef ();

public:

  //****************
  // CreateValue()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CreateValue
        (// @parm [in] object with which to initialize this object reference
         ImplAAFRoot * pObj,

         // @parm [out] newly created property value
         ImplAAFPropertyValue ** ppPropVal);


  //****************
  // GetObjectType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetObjectType
        // @parm [out] class def of objects permitted to be referenced
        (ImplAAFClassDef ** ppObjType);


  //****************
  // GetObject()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetObject
        (// @parm [in] property value from which value is to be read
         ImplAAFPropertyValue * pPropVal,

         // @parm [out] pointer to object value
         ImplAAFRoot ** ppObject);


  //****************
  // SetObject()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetObject
        (// @parm [in] property value from which value is to be read
         ImplAAFPropertyValue * pPropVal,

         // @parm [in] pointer to object value
         ImplAAFRoot * ppObject);



  //*************************************************************
  //
  // Overrides from OMType, via inheritace through ImplAAFTypeDef
  //
  //*************************************************************

  virtual void reorder(OMByte* externalBytes,
                       OMUInt32 externalBytesSize) const;

  virtual OMUInt32 externalSize(const OMByte* internalBytes,
							  OMUInt32 internalBytesSize) const;

  virtual void externalize(const OMByte* internalBytes,
                           OMUInt32 internalBytesSize,
                           OMByte* externalBytes,
                           OMUInt32 externalBytesSize,
                           OMByteOrder byteOrder) const;

  virtual OMUInt32 internalSize(const OMByte* externalBytes,
							  OMUInt32 externalBytesSize) const;

  virtual void internalize(const OMByte* externalBytes,
                           OMUInt32 externalBytesSize,
                           OMByte* internalBytes,
                           OMUInt32 internalBytesSize,
                           OMByteOrder byteOrder) const;



public:
  // Overrides from ImplAAFTypeDef
  virtual bool IsAggregatable () const;
  virtual bool IsStreamable () const;
  virtual bool IsFixedArrayable () const;
  virtual bool IsVariableArrayable () const;
  virtual bool IsStringable () const;

  // Override callbacks from OMStorable
  virtual void onSave(void* clientContext) const;
  virtual void onRestore(void* clientContext) const;
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFTypeDefObjectRef> ImplAAFTypeDefObjectRefSP;

#endif // ! __ImplAAFTypeDefObjectRef_h__
