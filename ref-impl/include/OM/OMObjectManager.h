//=---------------------------------------------------------------------=
//
// $Id: OMObjectManager.h,v 1.6 2004/02/27 14:26:40 stuart_hc Exp $ $Name:  $
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
#ifndef OMOBJECTMANAGER_H
#define OMOBJECTMANAGER_H

// @class OMObjectManager| Object Manager global functions.
//   @cauthor Tim Bingham | tjb | Avid Technology, Inc.

class OMObjectManager {
public:

    // @cmember Initialize the Object Manager.
  static void initialize(void);

    // @cmember Finalize the Object Manager.
  static void finalize(void);

};

#endif
