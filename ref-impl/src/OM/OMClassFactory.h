//=---------------------------------------------------------------------=
//
// $Id: OMClassFactory.h,v 1.18 2004/02/27 14:26:42 stuart_hc Exp $ $Name:  $
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

// @doc OMEXTERNAL
#ifndef OMCLASSFACTORY_H
#define OMCLASSFACTORY_H

#include "OMDataTypes.h"

class OMStorable;

  // @class Abstract base class decribing the class factory used by
  //        the Object Manager and provided by Object Manager clients.
  //
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMClassFactory {
public:
  // @access Public members.

    //@cmember Destructor.
  virtual ~OMClassFactory(void) {}

    // @cmember Is the given class id registered ?
  virtual bool isRegistered(const OMClassId& classId) const = 0;

  // @cmember Copy the class identified by id to the destination class
  //          factory.  A Subsequent call to dstFactory->create(id) should
  //          succeed.  Return value is true if the copy succeed.  In normal
  //          operation there is no reason for the copy to fail.
  virtual void cloneClassDef(const OMClassId& id, OMClassFactory* dstFactory) = 0;

    // @cmember Create an instance of the appropriate derived class,
    //          given the class id.
  virtual OMStorable* create(const OMClassId& classId) const = 0;

};

#endif
