#ifndef __ParameterDefinition_h__
#define __ParameterDefinition_h__

//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: AAFParameterDefs.h,v 1.9 2005/06/14 20:27:52 montrowe Exp $ $Name:  $
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
// Licensor of the AAF Association is Metaglue Corporation.
// All rights reserved.
//
//=---------------------------------------------------------------------=


#include "AAFTypes.h"

// AAF well-known ParameterDefinition instances
//

//{e4962320-2267-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_Level =
{0xe4962320, 0x2267, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{e4962323-2267-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEWipeNumber =
{0xe4962323, 0x2267, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba0-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEReverse =
{0x9c894ba0, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{72559a80-24d7-11d3-8a50-0050040ef7d2}
const aafUID_t kAAFParameterDef_SpeedRatio =
{0x72559a80, 0x24d7, 0x11d3, {0x8a, 0x50, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{c573a510-071a-454f-b617-ad6ae69054c2}
const aafUID_t kAAFParameterDef_PositionOffsetX =
{0xc573a510, 0x071a, 0x454f, {0xb6, 0x17, 0xad, 0x6a, 0xe6, 0x90, 0x54, 0xc2}};


//{82e27478-1336-4ea3-bcb9-6b8f17864c42}
const aafUID_t kAAFParameterDef_PositionOffsetY =
{0x82e27478, 0x1336, 0x4ea3, {0xbc, 0xb9, 0x6b, 0x8f, 0x17, 0x86, 0x4c, 0x42}};


//{d47b3377-318c-4657-a9d8-75811b6dc3d1}
const aafUID_t kAAFParameterDef_CropLeft =
{0xd47b3377, 0x318c, 0x4657, {0xa9, 0xd8, 0x75, 0x81, 0x1b, 0x6d, 0xc3, 0xd1}};


//{5ecc9dd5-21c1-462b-9fec-c2bd85f14033}
const aafUID_t kAAFParameterDef_CropRight =
{0x5ecc9dd5, 0x21c1, 0x462b, {0x9f, 0xec, 0xc2, 0xbd, 0x85, 0xf1, 0x40, 0x33}};


//{8170a539-9b55-4051-9d4e-46598d01b914}
const aafUID_t kAAFParameterDef_CropTop =
{0x8170a539, 0x9b55, 0x4051, {0x9d, 0x4e, 0x46, 0x59, 0x8d, 0x01, 0xb9, 0x14}};


//{154ba82b-990a-4c80-9101-3037e28839a1}
const aafUID_t kAAFParameterDef_CropBottom =
{0x154ba82b, 0x990a, 0x4c80, {0x91, 0x01, 0x30, 0x37, 0xe2, 0x88, 0x39, 0xa1}};


//{8d568129-847e-11d5-935a-50f857c10000}
const aafUID_t kAAFParameterDef_ScaleX =
{0x8d568129, 0x847e, 0x11d5, {0x93, 0x5a, 0x50, 0xf8, 0x57, 0xc1, 0x00, 0x00}};


//{8d56812a-847e-11d5-935a-50f857c10000}
const aafUID_t kAAFParameterDef_ScaleY =
{0x8d56812a, 0x847e, 0x11d5, {0x93, 0x5a, 0x50, 0xf8, 0x57, 0xc1, 0x00, 0x00}};


//{062cfbd8-f4b1-4a50-b944-f39e2fc73c17}
const aafUID_t kAAFParameterDef_Rotation =
{0x062cfbd8, 0xf4b1, 0x4a50, {0xb9, 0x44, 0xf3, 0x9e, 0x2f, 0xc7, 0x3c, 0x17}};


//{72a3b4a2-873d-4733-9052-9f83a706ca5b}
const aafUID_t kAAFParameterDef_PinTopLeftX =
{0x72a3b4a2, 0x873d, 0x4733, {0x90, 0x52, 0x9f, 0x83, 0xa7, 0x06, 0xca, 0x5b}};


//{29e4d78f-a502-4ebb-8c07-ed5a0320c1b0}
const aafUID_t kAAFParameterDef_PinTopLeftY =
{0x29e4d78f, 0xa502, 0x4ebb, {0x8c, 0x07, 0xed, 0x5a, 0x03, 0x20, 0xc1, 0xb0}};


//{a95296c0-1ed9-4925-8481-2096c72e818d}
const aafUID_t kAAFParameterDef_PinTopRightX =
{0xa95296c0, 0x1ed9, 0x4925, {0x84, 0x81, 0x20, 0x96, 0xc7, 0x2e, 0x81, 0x8d}};


//{ce1757ae-7a0b-45d9-b3f3-3686adff1e2d}
const aafUID_t kAAFParameterDef_PinTopRightY =
{0xce1757ae, 0x7a0b, 0x45d9, {0xb3, 0xf3, 0x36, 0x86, 0xad, 0xff, 0x1e, 0x2d}};


//{08b2bc81-9b1b-4c01-ba73-bba3554ed029}
const aafUID_t kAAFParameterDef_PinBottomLeftX =
{0x08b2bc81, 0x9b1b, 0x4c01, {0xba, 0x73, 0xbb, 0xa3, 0x55, 0x4e, 0xd0, 0x29}};


//{c163f2ff-cd83-4655-826e-3724ab7fa092}
const aafUID_t kAAFParameterDef_PinBottomLeftY =
{0xc163f2ff, 0xcd83, 0x4655, {0x82, 0x6e, 0x37, 0x24, 0xab, 0x7f, 0xa0, 0x92}};


//{53bc5884-897f-479e-b833-191f8692100d}
const aafUID_t kAAFParameterDef_PinBottomRightX =
{0x53bc5884, 0x897f, 0x479e, {0xb8, 0x33, 0x19, 0x1f, 0x86, 0x92, 0x10, 0x0d}};


//{812fb15b-0b95-4406-878d-efaa1cffc129}
const aafUID_t kAAFParameterDef_PinBottomRightY =
{0x812fb15b, 0x0b95, 0x4406, {0x87, 0x8d, 0xef, 0xaa, 0x1c, 0xff, 0xc1, 0x29}};


//{a2667f65-65d8-4abf-a179-0b9b93413949}
const aafUID_t kAAFParameterDef_AlphaKeyInvertAlpha =
{0xa2667f65, 0x65d8, 0x4abf, {0xa1, 0x79, 0x0b, 0x9b, 0x93, 0x41, 0x39, 0x49}};


//{21ed5b0f-b7a0-43bc-b779-c47f85bf6c4d}
const aafUID_t kAAFParameterDef_LumKeyLevel =
{0x21ed5b0f, 0xb7a0, 0x43bc, {0xb7, 0x79, 0xc4, 0x7f, 0x85, 0xbf, 0x6c, 0x4d}};


//{cbd39b25-3ece-441e-ba2c-da473ab5cc7c}
const aafUID_t kAAFParameterDef_LumKeyClip =
{0xcbd39b25, 0x3ece, 0x441e, {0xba, 0x2c, 0xda, 0x47, 0x3a, 0xb5, 0xcc, 0x7c}};


//{e4962321-2267-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_Amplitude =
{0xe4962321, 0x2267, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{e4962322-2267-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_Pan =
{0xe4962322, 0x2267, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9e610007-1be2-41e1-bb11-c95de9964d03}
const aafUID_t kAAFParameterDef_OutgoingLevel =
{0x9e610007, 0x1be2, 0x41e1, {0xbb, 0x11, 0xc9, 0x5d, 0xe9, 0x96, 0x4d, 0x03}};


//{48cea642-a8f9-455b-82b3-86c814b797c7}
const aafUID_t kAAFParameterDef_IncomingLevel =
{0x48cea642, 0xa8f9, 0x455b, {0x82, 0xb3, 0x86, 0xc8, 0x14, 0xb7, 0x97, 0xc7}};


//{9c894ba1-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTESoft =
{0x9c894ba1, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba2-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEBorder =
{0x9c894ba2, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba3-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEPosition =
{0x9c894ba3, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba4-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEModulator =
{0x9c894ba4, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba5-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEShadow =
{0x9c894ba5, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba6-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTETumble =
{0x9c894ba6, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba7-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTESpotlight =
{0x9c894ba7, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba8-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEReplicationH =
{0x9c894ba8, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894ba9-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTEReplicationV =
{0x9c894ba9, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9c894baa-2277-11d3-8a4c-0050040ef7d2}
const aafUID_t kAAFParameterDef_SMPTECheckerboard =
{0x9c894baa, 0x2277, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{5f1c2560-2415-11d3-8a4f-0050040ef7d2}
const aafUID_t kAAFParameterDef_PhaseOffset =
{0x5f1c2560, 0x2415, 0x11d3, {0x8a, 0x4f, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


// AAF ParameterDefinition legacy aliases
//

const aafUID_t kAAFParameterDefLevel = kAAFParameterDef_Level;
const aafUID_t kAAFParameterDefSMPTEWipeNumber = kAAFParameterDef_SMPTEWipeNumber;
const aafUID_t kAAFParameterDefSMPTEReverse = kAAFParameterDef_SMPTEReverse;
const aafUID_t kAAFParameterDefSpeedRatio = kAAFParameterDef_SpeedRatio;
const aafUID_t kAAFParameterDefAmplitude = kAAFParameterDef_Amplitude;
const aafUID_t kAAFParameterDefPan = kAAFParameterDef_Pan;
const aafUID_t kAAFParameterDefSMPTESoft = kAAFParameterDef_SMPTESoft;
const aafUID_t kAAFParameterDefSMPTEBorder = kAAFParameterDef_SMPTEBorder;
const aafUID_t kAAFParameterDefSMPTEPosition = kAAFParameterDef_SMPTEPosition;
const aafUID_t kAAFParameterDefSMPTEModulator = kAAFParameterDef_SMPTEModulator;
const aafUID_t kAAFParameterDefSMPTEShadow = kAAFParameterDef_SMPTEShadow;
const aafUID_t kAAFParameterDefSMPTETumble = kAAFParameterDef_SMPTETumble;
const aafUID_t kAAFParameterDefSMPTESpotlight = kAAFParameterDef_SMPTESpotlight;
const aafUID_t kAAFParameterDefSMPTEReplicationH = kAAFParameterDef_SMPTEReplicationH;
const aafUID_t kAAFParameterDefSMPTEReplicationV = kAAFParameterDef_SMPTEReplicationV;
const aafUID_t kAAFParameterDefSMPTECheckerboard = kAAFParameterDef_SMPTECheckerboard;
const aafUID_t kAAFParameterDefPhaseOffset = kAAFParameterDef_PhaseOffset;

#endif // ! __ParameterDefinition_h__
