//=---------------------------------------------------------------------=
//
// $Id: AifVersions.h,v 1.2 2005/01/07 03:17:45 jptrainor Exp $ $Name:  $
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
// Licensor of the AAF Association is Siemens SBS Media
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef __AifVersions_h__
#define __AifVersions_h__

#include <AAFSDKBuild.h>

#if   AAF_MAJOR_VERSION == 1  &&  AAF_MINOR_VERSION == 1  && AAF_MAINT_RELEASE == 0
#define AIF_V110
#elif AAF_MAJOR_VERSION == 1  &&  AAF_MINOR_VERSION == 0  && AAF_MAINT_RELEASE == 2
#define AIF_V102
#else
#error "unsupported AAF SDK version"
#endif

#endif
