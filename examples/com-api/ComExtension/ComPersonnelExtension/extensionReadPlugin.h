#ifndef __extensionReadPlugin_h__
#define __extensionReadPlugin_h__
//=---------------------------------------------------------------------=
//
// $Id: extensionReadPlugin.h,v 1.3 2004/02/27 14:26:36 stuart_hc Exp $ $Name:  $
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


#include "AAFTypes.h"

//
// This example code is intended to show how AAF may be extended to
// store personnel information relating to the staff which worked on a
// project.
//
// See comments in extensionWrite.cpp for a discussion of what we're
// trying to do and how we're doing it.
//

//
// Reads the aaf file specified by filename.  Assumes it was created
// by the extensionPluginWrite utility; tests its contents to verify that
// they are correct.  Returns true if correct; returns false if there
// was any error found.
//
#ifdef __cplusplus
extern "C" {
#endif

HRESULT extensionReadPlugin (const aafCharacter * filename);

#ifdef __cplusplus
}
#endif

#endif // ! __extensionReadPlugin_h__
