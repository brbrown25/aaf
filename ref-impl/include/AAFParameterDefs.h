/***********************************************\
*												*
* Advanced Authoring Format						*
*												*
* Copyright (c) 1998-1999 Avid Technology, Inc. *
* Copyright (c) 1998-1999 Microsoft Corporation *
*												*
\***********************************************/

// Following are the UIDs of the well-known parameter definition objects in AAF.
//
// When an API call asks for a DDEF UID, store this into a local UID variable, and then pass
// in the address of the variable, as in:
//		aafUID_t	uid = PARMDEF_Level;
//
// When you need an IAAFDataDef *, (ex: when you want to do DoesDataDefConvertTo()),
// then do the following (where pDictionary is a pointer to the
// dictionary object in the current file.)
//		aafUID_t	uid = PARMDEF_Level;
//		IDataDef	*definition = NULL;
//		hr = pDictionary->LookupParameterDefintion(&uid, &definition);

// Parameter Definition : Level
// Parameter Definition Type : rational
// {E4962320-2267-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefLevel = { 0xe4962320, 0x2267, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : Amplitude multiplier
// Parameter Definition Type : rational
// {E4962321-2267-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefAmplitude = { 0xe4962321, 0x2267, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : Pan Value
// Parameter Definition Type : rational
// {E4962322-2267-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefPan = { 0xe4962322, 0x2267, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Wipe number
// Parameter Definition Type : Int32
const aafUID_t kAAFParameterDefSMPTEWipeNumber = { 0xe4962323, 0x2267, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Reverse
// Parameter Definition Type : Boolean
// {9C894BA0-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEReverse = { 0x9c894ba0, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Soft
// Parameter Definition Type : Boolean
// {9C894BA1-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTESoft = { 0x9c894ba1, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Border
// Parameter Definition Type : Boolean
// {9C894BA2-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEBorder = { 0x9c894ba2, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Position
// Parameter Definition Type : Boolean
// {9C894BA3-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEPosition = { 0x9c894ba3, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Modulator
// Parameter Definition Type : Boolean
// {9C894BA4-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEModulator = { 0x9c894ba4, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Shadow
// Parameter Definition Type : Boolean
// {9C894BA5-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEShadow = { 0x9c894ba5, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Tumble
// Parameter Definition Type : Boolean
// {9C894BA6-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTETumble = { 0x9c894ba6, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Spotlight
// Parameter Definition Type : Boolean
// {9C894BA7-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTESpotlight = { 0x9c894ba7, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE ReplicationH
// Parameter Definition Type : Boolean
// {9C894BA8-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEReplicationH = { 0x9c894ba8, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE ReplicationV
// Parameter Definition Type : Boolean
// {9C894BA9-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTEReplicationV = { 0x9c894ba9, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// Parameter Definition : SMPTE Checkerboard
// Parameter Definition Type : Boolean
// {9C894BAA-2277-11d3-8A4C-0050040EF7D2}
const aafUID_t kAAFParameterDefSMPTECheckerboard = { 0x9c894baa, 0x2277, 0x11d3, { 0x8a, 0x4c, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
