//@doc
//@class    AAFFiller | Implementation class for AAFFiller
#ifndef __ImplAAFFiller_h__
#define __ImplAAFFiller_h__


//=---------------------------------------------------------------------=
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


#ifndef __AAFTypes_h__
#include "AAFTypes.h"
#endif

class ImplAAFDataDef;





#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif


class ImplAAFFiller : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFFiller ();
  virtual ~ImplAAFFiller ();



  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
	    (// @parm [in] Data Definition Object
         ImplAAFDataDef * pDataDef,

		 // @parm [in] Length Property Value
		 aafLength_t  length);



public:

	virtual AAFRESULT TraverseToClip( aafLength_t length,
									  ImplAAFSegment **sclp,
									  ImplAAFPulldown **pulldownObj,
									  aafInt32 *pulldownPhase,
									  aafLength_t *sclpLen,
									  aafBool *isMask);
};

#endif // ! __ImplAAFFiller_h__

