//@doc
//@class    AAFVaryingValue | Implementation class for AAFVaryingValue
#ifndef __ImplAAFVaryingValue_h__
#define __ImplAAFVaryingValue_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFVaryingValue.h,v 1.16 2004/09/10 17:13:09 stuart_hc Exp $ $Name:  $
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

class ImplAAFDataDef;
class ImplAAFControlPoint;

template <class T> 
class ImplAAFEnumerator;
typedef ImplAAFEnumerator<ImplAAFControlPoint> ImplEnumAAFControlPoints;

#ifndef __ImplAAFParameter_h__
#include "ImplAAFParameter.h"
#endif

#ifndef __ImplAAFInterpolationDef_h__
#include "ImplAAFInterpolationDef.h"
#endif

#include "OMWeakRefProperty.h"
#include "OMStrongRefVectorProperty.h"

#include "ImplEnumAAFControlPoints.h"

class ImplAAFVaryingValue : public ImplAAFParameter
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFVaryingValue ();


  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
        (// @parm [in] // Parameter definition for this object (this determines the type of the constant value)
         ImplAAFParameterDef * pParameterDef,
         
         // @parm [in] Interpolation definition for this object
         ImplAAFInterpolationDef * pInterpolationDef);



protected:
  virtual ~ImplAAFVaryingValue ();

public:


  //****************
  // SetInterpolationDef()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetInterpolationDefinition
        (ImplAAFInterpolationDef * pPoint);


  //****************
  // GetInterpolationDef()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetInterpolationDefinition
        (ImplAAFInterpolationDef ** ppDef);

  //****************
  // AddControlPoint()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    AddControlPoint
        // @parm [in] pointer to IAAFControlPoint object
        (ImplAAFControlPoint * pPoint);


  //****************
  // GetControlPoints()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetControlPoints
        // @parm [out,retval] Parameter definition enumeration
        (ImplEnumAAFControlPoints ** ppEnum);

  //****************
  // CountControlPoints()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CountControlPoints
        // @parm [out,retval] Parameter definition enumeration
        (aafUInt32 * pResult);


  //****************
  // GetControlPointAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetControlPointAt
        // @parm [in] index of control point to retrieve
        (aafUInt32 index,
		 // @parm [out,retval] retrieved control point
		 ImplAAFControlPoint ** ppControlPoint);


  //****************
  // RemoveControlPointAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RemoveControlPointAt
        // @parm [in] index of control point to remove
        (aafUInt32 index);


  //****************
  // GetValueBufLen()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetValueBufLen
        // @parm [out] Mob Name
        (aafInt32 *  pLen);

  //****************
  // GetInterpolatedValue()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetInterpolatedValue
        (// @parm [in] Position along the effect
         aafRational_t  inputValue,

         // @parm [in] Size of preallocated buffer
         aafInt32  valueSize,

         // @parm [out, size_is(valueSize),length_is(*bytesRead)] Preallocated buffer to hold value
         aafDataBuffer_t  pValue,

         // @parm [out] Number of actual bytes read
         aafInt32*  bytesRead);

public:
	// SDK-private methods

private:
	OMWeakReferenceProperty<ImplAAFInterpolationDef>		_interpolation;
  OMStrongReferenceVectorProperty<ImplAAFControlPoint> _controlPoints;

  ImplAAFTypeDef * _cachedTypeDef; // NOT REFERENCE COUNTED!
};	

#endif // ! __ImplAAFVaryingValue_h__



