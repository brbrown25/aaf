//@doc
//@class    AAFPropertyValue | Implementation class for AAFPropertyValue
#ifndef __ImplAAFPropertyValue_h__
#define __ImplAAFPropertyValue_h__


/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/


class ImplAAFTypeDef;


#ifndef __ImplAAFRoot_h__
#include "ImplAAFRoot.h"
#endif


class ImplAAFPropertyValue : public ImplAAFRoot
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFPropertyValue ();


  //****************
  // GetType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetType
        // @parm [out] The type definition associated with this property value
        (ImplAAFTypeDef ** ppTypeDef);


  //****************
  // IsDefinedType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    IsDefinedType
        // @parm [out] result
        (aafBool *  pIsDefined);


protected:
  virtual ~ImplAAFPropertyValue ();

  //****************
  //
  // non-published method to set up one of these.
  //
  AAFRESULT SetType (ImplAAFTypeDef * pType);

  const ImplAAFTypeDef * pvtGetType (void) const;

private:
  // type of this property
  ImplAAFTypeDef * _pType;
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
