//@doc
//@class    AAFInterpolationDef | Implementation class for AAFInterpolationDef
#ifndef __ImplAAFInterpolationDef_h__
#define __ImplAAFInterpolationDef_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFInterpolationDef.h,v 1.12 2004/02/27 14:26:47 stuart_hc Exp $ $Name:  $
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



class ImplAAFClassDef;

#ifndef __ImplAAFDefObject_h__
#include "ImplAAFDefObject.h"
#endif


class ImplAAFInterpolationDef : public ImplAAFDefObject
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFInterpolationDef ();


  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
        // @parm [in] Pointer to an AUID reference
        (const aafUID_t & id,
		 const aafCharacter *name,
		 const aafCharacter *description);

protected:
  virtual ~ImplAAFInterpolationDef();
};

#endif // ! __ImplAAFInterpolationDef_h__


