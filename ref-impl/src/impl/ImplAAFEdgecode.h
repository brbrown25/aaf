//@doc
//@class    AAFEdgecode | Implementation class for AAFEdgecode
#ifndef __ImplAAFEdgecode_h__
#define __ImplAAFEdgecode_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFEdgecode.h,v 1.14 2004/02/27 14:26:47 stuart_hc Exp $ $Name:  $
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


/***********************************************\
*	Stub only.   Implementation not yet added	*
\***********************************************/

#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif
#include "OMVariableSizeProperty.h"

class ImplAAFEdgecode : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFEdgecode ();

protected:
  virtual ~ImplAAFEdgecode ();

public:


  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
        (// @parm [in] Length Property Value
         aafLength_t    length,

         // @parm [in] Edgecode Value
         aafEdgecode_t  edgecode);

  //****************
  // GetEdgecode()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetEdgecode
        // @parm [out] Edgecode
        (aafEdgecode_t *  edgecode);

private:
	OMFixedSizeProperty<aafPosition_t>			_start;
	OMFixedSizeProperty<aafFilmType_t>			_filmType;
	OMFixedSizeProperty<aafEdgeType_t>			_edgeType;
	OMVariableSizeProperty<aafUInt8>			_header;

};

#endif // ! __ImplAAFEdgecode_h__


