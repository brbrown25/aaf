//@doc
//@class    ImplAAFPhysicalDescriptor | Implementation class for AAFPhysicalDescriptor
#ifndef __ImplAAFPhysicalDescriptor_h__
#define __ImplAAFTapeDescriptor_h__

//=---------------------------------------------------------------------=
//
// $Id: ImplAAFPhysicalDescriptor.h,v 1.2 2004/09/10 17:13:08 stuart_hc Exp $ $Name:  $
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


#ifndef __AAFTypes_h__
#include "AAFTypes.h"
#endif

#ifndef __ImplAAFEssenceDescriptor_h__
#include "ImplAAFEssenceDescriptor.h"
#endif

#include "OMWideStringProperty.h"



class ImplAAFPhysicalDescriptor : public ImplAAFEssenceDescriptor
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFPhysicalDescriptor ();
  virtual ~ImplAAFPhysicalDescriptor ();

public:

//  virtual AAFRESULT	STDMETHODCALLTYPE
//		GetOwningMobKind (aafMobKind_t *pMobKind);

	// Persistent properties
private:
};

#endif // ! __ImplAAFPhysicalDescriptor_h__

