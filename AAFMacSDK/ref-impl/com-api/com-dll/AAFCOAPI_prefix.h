// >>> � 1998 Avid Technology, Inc.  All rights reserved. <<<

// Include the pre-compiled header that includes AAF.h
#include "AAFHeaders.h"


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

// Conditional debugging and ansi assertions disabled
#ifndef NDEBUG
#define NDEBUG
#endif


// Enable PRECONDITION, POSTCONDITION, ASSERT, INVARIANT and IMPLIES macros.
//#define OM_ENABLE_DEBUG

// Uncomment the following line if you want to see an exhausted list
// of the calling sequence within the Object Manager.
//#define OM_ENABLE_TRACE