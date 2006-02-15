#ifndef __CompressionDefinition_h__
#define __CompressionDefinition_h__

//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: AAFCompressionDefs.h,v 1.5 2006/02/15 23:01:34 jlow Exp $ $Name:  $
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

// AAF well-known CompressionDefinition instances
//

//{edb35383-6d30-11d3-a036-006094eb75cb}
const aafUID_t kAAFCompressionDef_AAF_CMPR_FULL_JPEG =
{0xedb35383, 0x6d30, 0x11d3, {0xa0, 0x36, 0x00, 0x60, 0x94, 0xeb, 0x75, 0xcb}};


//{edb35391-6d30-11d3-a036-006094eb75cb}
const aafUID_t kAAFCompressionDef_AAF_CMPR_AUNC422 =
{0xedb35391, 0x6d30, 0x11d3, {0xa0, 0x36, 0x00, 0x60, 0x94, 0xeb, 0x75, 0xcb}};


//{edb35390-6d30-11d3-a036-006094eb75cb}
const aafUID_t kAAFCompressionDef_LegacyDV =
{0xedb35390, 0x6d30, 0x11d3, {0xa0, 0x36, 0x00, 0x60, 0x94, 0xeb, 0x75, 0xcb}};


//{00004122-0021-0100-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_IEC_DV_525_60 =
{0x00004122, 0x0021, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{00004122-0021-0200-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_IEC_DV_625_50 =
{0x00004122, 0x0021, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{00004122-0022-0100-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_25Mbps_525_60 =
{0x00004122, 0x0022, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{00004122-0022-0200-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_25Mbps_625_50 =
{0x00004122, 0x0022, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{00004122-0022-0300-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_50Mbps_525_60 =
{0x00004122, 0x0022, 0x0300, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{00004122-0022-0400-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_50Mbps_625_50 =
{0x00004122, 0x0022, 0x0400, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


// AAF CompressionDefinition legacy aliases
//

const aafUID_t AAF_CMPR_FULL_JPEG = kAAFCompressionDef_AAF_CMPR_FULL_JPEG;
const aafUID_t AAF_CMPR_AUNC422 = kAAFCompressionDef_AAF_CMPR_AUNC422;

#endif // ! __CompressionDefinition_h__
