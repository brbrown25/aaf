#ifndef __CompressionDefinition_h__
#define __CompressionDefinition_h__

//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: AAFCompressionDefs.h,v 1.12 2008/12/08 06:50:10 stuart_hc Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2006, Licensor of the
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


//{04010202-0201-0100-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_IEC_DV_525_60 =
{0x04010202, 0x0201, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-0201-0200-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_IEC_DV_625_50 =
{0x04010202, 0x0201, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-0202-0100-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_25Mbps_525_60 =
{0x04010202, 0x0202, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-0202-0200-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_25Mbps_625_50 =
{0x04010202, 0x0202, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-0202-0300-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_50Mbps_525_60 =
{0x04010202, 0x0202, 0x0300, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-0202-0400-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_DV_Based_50Mbps_625_50 =
{0x04010202, 0x0202, 0x0400, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


//{04010202-7100-0000-060e-2b340401010a}
const aafUID_t kAAFCompressionDef_VC3_1 =
{0x04010202, 0x7100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x0a}};


//{0e040201-0204-0100-060e-2b3404010101}
const aafUID_t kAAFCompressionDef_Avid_DNxHD_Legacy =
{0x0e040201, 0x0204, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};


const aafUID_t kAAFCompressionDef_SMPTE_D10_625x50I_50Mbps = {0x04010202, 0x0102, 0x0101, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};
const aafUID_t kAAFCompressionDef_SMPTE_D10_525x5994I_50Mbps = {0x04010202, 0x0102, 0x0102, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};
const aafUID_t kAAFCompressionDef_SMPTE_D10_625x50I_40Mbps = {0x04010202, 0x0102, 0x0103, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};
const aafUID_t kAAFCompressionDef_SMPTE_D10_525x5994I_40Mbps = {0x04010202, 0x0102, 0x0104, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};
const aafUID_t kAAFCompressionDef_SMPTE_D10_625x50I_30Mbps = {0x04010202, 0x0102, 0x0105, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};
const aafUID_t kAAFCompressionDef_SMPTE_D10_525x5994I_30Mbps = {0x04010202, 0x0102, 0x0106, {0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};

const aafUID_t kAAFCompressionDef_DVbased_1080x5994I_100Mbps = { 0x04010202, 0x0202, 0x0500, { 0x6, 0xe, 0x2b, 0x34, 0x4, 0x1, 0x1, 0x1 } };
const aafUID_t kAAFCompressionDef_DVbased_1080x50I_100Mbps = { 0x04010202, 0x0202, 0x0600, { 0x6, 0xe, 0x2b, 0x34, 0x4, 0x1, 0x1, 0x1 } };
const aafUID_t kAAFCompressionDef_DVbased_720x5994P_100Mbps = { 0x04010202, 0x0202, 0x0700, { 0x6, 0xe, 0x2b, 0x34, 0x4, 0x1, 0x1, 0x1 } };
const aafUID_t kAAFCompressionDef_DVbased_720x50P_100Mbps = { 0x04010202, 0x0202, 0x0800, { 0x6, 0xe, 0x2b, 0x34, 0x4, 0x1, 0x1, 0x1 } };

// AAF CompressionDefinition legacy aliases
//

const aafUID_t AAF_CMPR_FULL_JPEG = kAAFCompressionDef_AAF_CMPR_FULL_JPEG;
const aafUID_t AAF_CMPR_AUNC422 = kAAFCompressionDef_AAF_CMPR_AUNC422;

#endif // ! __CompressionDefinition_h__
