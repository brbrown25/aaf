//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
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

/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */
//=--------------------------------------------------------------------------=
// Definitions for all public IID's needed by an AAF SDK Plugin author
//=--------------------------------------------------------------------------=
//

#ifdef __cplusplus
extern "C"{
#endif


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IAAFRoot = {0x7C3712C2,0x390D,0x11D2,{0x84,0x1B,0x00,0x60,0x08,0x32,0xAC,0xB8}};


const IID IID_IAAFHTMLClip = {0xe684d784,0xb935,0x11d2,{0xbf,0x9d,0x00,0x10,0x4b,0xc9,0x15,0x6d}};


const IID IID_IAAFHTMLDescriptor = {0xe684d770,0xb935,0x11d2,{0xbf,0x9d,0x00,0x10,0x4b,0xc9,0x15,0x6d}};


const IID IID_IAAFMetaDictionary = {0xe1085eeb,0x0cc3,0x11d4,{0x80,0x14,0x00,0x10,0x4b,0xc9,0x15,0x6d}};


const IID IID_IAAFPropValData = {0x106bb6e2,0xf0c1,0x11d2,{0x84,0x2c,0x00,0x60,0x08,0x32,0xac,0xb8}};


const IID IID_IAAFStreamPropertyValue = {0xF06bb6e2,0xf0c1,0x11d2,{0x84,0x2c,0x00,0x60,0x08,0x32,0xac,0xb8}};


const IID IID_IAAFStrongRefArrayValue = {0xf2973a82,0x6895,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xf3}};


const IID IID_IAAFStrongRefSetValue = {0x84537782,0x6897,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xf3}};


const IID IID_IAAFStrongRefValue = {0x4142d582,0x6892,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xf3}};


const IID IID_IAAFTextClip = {0xe684d786,0xb935,0x11d2,{0xbf,0x9d,0x00,0x10,0x4b,0xc9,0x15,0x6d}};


const IID IID_IAAFWeakRefArrayValue = {0x02fbe502,0x6897,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xe3}};


const IID IID_IAAFWeakRefSetValue = {0xb1078f02,0x6897,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xe3}};


const IID IID_IAAFWeakRefValue = {0x32a8ee02,0x6893,0x11d4,{0xa8,0x12,0x8f,0x71,0xe1,0x57,0xe3,0xe3}};


const IID IID_IEnumAAFStorablePropVals = {0x5096c202,0x831b,0x11d4,{0xa8,0x12,0x8a,0x70,0xdf,0x17,0xed,0x53}};


#ifdef __cplusplus
}
#endif

