#ifndef __ImplAAFOMCachePageAllocator_h__
#define __ImplAAFOMCachePageAllocator_h__

//=---------------------------------------------------------------------=
//
// $Id: ImplAAFOMCachePageAllocator.h,v 1.1 2005/09/07 17:51:48 montrowe Exp $ $Name:  $
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

#include "OMCachePageAllocator.h"

#include "ImplAAFRoot.h"

struct IAAFCachePageAllocator;

class ImplAAFOMCachePageAllocator : public OMCachePageAllocator {
public:

  ImplAAFOMCachePageAllocator(IAAFCachePageAllocator* pAllocator,
                              aafUInt32 pageSize,
                              aafUInt32 pageCount);

  virtual ~ImplAAFOMCachePageAllocator();

  // Overrides from OMCachePageAllocator

  virtual OMByte* allocate(void);

  virtual void deallocate(OMByte* page);

private:
  IAAFCachePageAllocator* _pAllocator;
};

#endif // ! __ImplAAFOMCachePageAllocator_h__
