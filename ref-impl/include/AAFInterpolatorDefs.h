//=---------------------------------------------------------------------=
//
// $Id: AAFInterpolatorDefs.h,v 1.7 2004/09/10 17:12:39 stuart_hc Exp $ $Name:  $
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

// Following are the UIDs of the well-known Interpolator definition objects in AAF.
//
//

const aafUID_t NoInterpolator		= { 0x5B6C85A3, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t LinearInterpolator   = { 0x5B6C85A4, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };
const aafUID_t ConstantInterpolator		= { 0x5B6C85A5, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t BSplineInterpolator  = { 0x5B6C85A6, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };
const aafUID_t LogInterpolator   = { 0x15829ec3, 0x1f24, 0x458a, { 0x96, 0xd, 0xc6, 0x5b, 0xb2, 0x3c, 0x2a, 0xa1 } };
const aafUID_t PowerInterpolator   = { 0xc09153f7, 0xbd18, 0x4e5a, { 0xad, 0x9, 0xcb, 0xdd, 0x65, 0x4f, 0xa0, 0x1 } };
