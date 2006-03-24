//@doc
//@class    AAFSubDescriptor | Implementation class for AAFSubDescriptor
#ifndef __ImplAAFSubDescriptor_h__
#define __ImplAAFSubDescriptor_h__

//=---------------------------------------------------------------------=
//
//
// $Id: ImplAAFSubDescriptor.h,v 1.1 2006/03/24 18:23:37 jlow Exp $ $Name:  $
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











#ifndef __ImplAAFObject_h__
#include "ImplAAFObject.h"
#endif


class ImplAAFSubDescriptor : public ImplAAFObject
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFSubDescriptor ();

protected:
  virtual ~ImplAAFSubDescriptor ();



};

#endif // ! __ImplAAFSubDescriptor_h__


