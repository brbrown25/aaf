/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/




#ifndef __ImplAAFObject_h__
#include "ImplAAFObject.h"
#endif

#include <assert.h>


ImplAAFObject::ImplAAFObject ()
{}


ImplAAFObject::~ImplAAFObject ()
{}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::SetGeneration (aafUID_t *  /*pGeneration*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetGeneration (aafUID_t *  /*pGeneration*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetStoredByteOrder (aafByteOrder_t *  /*pOrder*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFObject::GetNativeByteOrder (aafByteOrder_t *  /*pOrder*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}


extern "C" const aafClassID_t CLSID_AAFObject;

OMDEFINE_STORABLE(AAFObject, CLSID_AAFObject);
