//=---------------------------------------------------------------------=
//
// $Id: OMSSSStorageRWInputSource.h,v 1.3 2005/10/13 16:45:14 rodrigc Exp $ $Name:  $
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
// Licensor of the AAF Association is Schema Software Inc.
// All rights reserved.
//
//=---------------------------------------------------------------------=


/************************************************************************
* StructuredStorage.h
* Public Header file for Structured Storage library
*
* (c) Schema Software Inc., 2001-2004
* Authors: Bob Sabiston, Yuri Khramov, Mark Ambachtsheer
************************************************************************

$Revision: 1.3 $
$Date: 2005/10/13 16:45:14 $
*/
#ifndef OMSSSSTORAGERWINPUTSOURCE_H
#define OMSSSSTORAGERWINPUTSOURCE_H

#ifndef OM_NO_STRUCTURED_STORAGE

#include "OMRawStorage.h"
#include "StructuredStorage.h"
extern "C" int openStructuredStorageInOMRawStorage (
    const OMRawStorage* in_pRaw,
    StgMode in_accessMode,
    RootStorage** out_ppRoot);

extern "C" int createStructuredStorageInOMRawStorageEx (
    const OMRawStorage* in_pRaw,
    StgMode in_accessMode,
    RootStorage** out_ppRoot,
    unsigned long in_sectorSize);

#endif // !OM_NO_STRUCTURED_STORAGE

#endif //OMSSSSTORAGERWINPUTSOURCE_H
