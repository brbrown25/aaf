#ifndef __extensionReadPlugin_h__
#define __extensionReadPlugin_h__
//=---------------------------------------------------------------------=
//
// $Id: extensionReadPlugin.h,v 1.4 2009/06/01 11:46:51 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
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
