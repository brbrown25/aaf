const aafUID_t DDEF_Video = { 0x6F3C8CE1, 0x6CEF, 0x11D2, { 0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t DDEF_Audio = { 0x78E1EBE1, 0x6CEF, 0x11D2, { 0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t DDEF_Timecode = { 0x7F275E81, 0x77E5, 0x11D2, { 0x80, 0x7F, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t DDEF_Edgecode = { 0xd2bb2af0, 0xd234, 0x11d2, { 0x89, 0xee, 0x0, 0x60, 0x97, 0x11, 0x62, 0x12 } };

const aafUID_t NilMOBID = { 0xF15D2C20, 0x6D22, 0x11d2, { 0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t NoCodec = { 0x568FB761, 9458, 0x11d2, { 0x80, 0x89, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t CodecWave       = { 0x820F09B1, 0xEB9B, 0x11d2, { 0x80, 0x9F, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };

const aafUID_t NoInterpolator		= { 0x5B6C85A3, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t LinearInterpolator   = { 0x5B6C85A4, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };
const aafUID_t StepInterpolator		= { 0x5B6C85A5, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t BSplineInterpolator  = { 0x5B6C85A6, 0x0EDE, 0x11d3, { 0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };

const aafUID_t NilCodecVariety = { 0x1B31F3B1, 0x9450, 0x11d2, { 0x80, 0x89, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t ContainerAAF = { 0x4313B571, 0xD8BA, 0x11d2, { 0x80, 0x9B, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t ContainerFile = { 0x4313B572, 0xD8BA, 0x11d2, { 0x80, 0x9B, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t kAAFFmtEnd = { 0x6AEFC4F1, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t kAAFPlatformIndependant = { 0x3D1DD891, 0xE793, 0x11d2, { 0x80, 0x9E, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t kAAFNoEngine = { 0x9FDEF8C1, 0xE847, 0x11d2, { 0x80, 0x9E, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t kAAFEssencePluginAPI = { 0x69C870A1, 0xE793, 0x11d2, { 0x80, 0x9E, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };

const aafUID_t kAAFPixelFormat = { 0x6AEFC4F2, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expPixelFormat */
const aafUID_t kAAFFrameLayout = { 0x6AEFC4F3, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 		/* operand.expFrameLayout */
const aafUID_t kAAFFieldDominance = { 0x6AEFC4F4, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expFieldDom */
const aafUID_t kAAFStoredRect = { 0x6AEFC4F5, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 		/* operand.expRect */
const aafUID_t kAAFDisplayRect = { 0x6AEFC4F6, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };  		/* operand.expRect */
const aafUID_t kAAFSampledRect = { 0x6AEFC4F7, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };  		/* operand.expRect */
const aafUID_t kAAFPixelSize = { 0x6AEFC4F8, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 			/* operand.expInt16 */
const aafUID_t kAAFAspectRatio = { 0x6AEFC4F9, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expRational */
const aafUID_t kAAFAlphaTransparency = { 0x6AEFC4FA, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };  /* operand.expInt32 */
const aafUID_t kAAFGamma = { 0x6AEFC4FC, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };				/* operand.expRational */
const aafUID_t kAAFImageAlignmentFactor = { 0x6AEFC4FD, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; /* operand.expInt32 */
const aafUID_t kAAFVideoLineMap = { 0x6AEFC4FE, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expLineMap */
const aafUID_t kAAFWillTransferLines = { 0x6AEFC4FF, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };	/* operand.expBoolean */
const aafUID_t kAAFIsCompressed = { 0x6AEFC500, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expBoolean */
const aafUID_t kAAFLineLength = { 0x6AEFC501, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };			/* operand.expInt32 */
		/* the following group is exclusive to RGBA codec */
const aafUID_t kAAFRGBCompLayout = { 0x6AEFC502, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expCompArray */
const aafUID_t kAAFRGBCompSizes = { 0x6AEFC503, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		/* operand.expCompSizeArray */
const aafUID_t kAAFRGBPalette = { 0x6AEFC504, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };			/* operand.expPointer */
const aafUID_t kAAFRGBPaletteLayout = { 0x6AEFC505, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };	/* operand.expCompArray */
const aafUID_t kAAFRGBPaletteSizes = { 0x6AEFC506, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };	/* operand.expCompSizeArray */	
			/* the following group is exclusive to CDCI codec */
const aafUID_t kAAFCDCICompWidth = { 0x6AEFC507, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };	    /* operand.expInt32 */
const aafUID_t kAAFCDCIHorizSubsampling = { 0x6AEFC508, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };/* operand.expUInt32 */
const aafUID_t kAAFCDCIColorSiting = { 0x6AEFC509, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };    /* operand.expColorSiting */
const aafUID_t kAAFCDCIBlackLevel = { 0x6AEFC50A, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };     /* operand.expUInt32 */
const aafUID_t kAAFCDCIWhiteLevel = { 0x6AEFC50B, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };     /* operand.expUInt32 */
const aafUID_t kAAFCDCIColorRange = { 0x6AEFC50C, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };     /* operand.expUInt32 */
const aafUID_t kAAFCDCIPadBits = { 0x6AEFC50D, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };	    /* operand.expInt16 */
			
const aafUID_t kAAFAudioSampleBits = { 0x6AEFC50E, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 
const aafUID_t kAAFMaxSampleBytes = { 0x33F26181, 0xD27F, 0x11d2, { 0x80, 0x99, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 
const aafUID_t kAAFSampleRate = { 0x6AEFC50F, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 
const aafUID_t kAAFSampleFormat = { 0x6AEFC510, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 
const aafUID_t kAAFNumChannels = { 0x6AEFC511, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };
const aafUID_t kAAFExpLong = { 0x6AEFC512, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } };		// TomR:Added to support all options in the union
const aafUID_t kAAFExpRational = { 0x6AEFC513, 0x9041, 0x11d2, { 0x80, 0x88, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F } }; 	// TomR:Added to support all options in the union

/* The followwing group is for effect definitions !! */
// {0C3BEA40-FC05-11d2-8A29-0050040EF7D2}
const aafUID_t kAAFEffectVideoDissolve = { 0xc3bea40, 0xfc05, 0x11d2, { 0x8a, 0x29, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } }; //tlk
// {0C3BEA41-FC05-11d2-8A29-0050040EF7D2}
const aafUID_t kAAFEffectMonoAudioDissolve = { 0xc3bea41, 0xfc05, 0x11d2, { 0x8a, 0x29, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } }; //tlk
// {0C3BEA42-FC05-11d2-8A29-0050040EF7D2}
const aafUID_t kAAFEffectStereoAudioDissolve = { 0xc3bea42, 0xfc05, 0x11d2, { 0x8a, 0x29, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {0C3BEA43-FC05-11d2-8A29-0050040EF7D2}
const aafUID_t kAAFEffectVideoFadeToBlack = { 0xc3bea43, 0xfc05, 0x11d2, { 0x8a, 0x29, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {0C3BEA44-FC05-11d2-8A29-0050040EF7D2}
const aafUID_t kAAFEffectSMPTEVideoWipe = { 0xc3bea44, 0xfc05, 0x11d2, { 0x8a, 0x29, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {0A3C75E0-FD82-11d2-8A2B-0050040EF7D2}
const aafUID_t kAAFEffectPictureWithMate = { 0xa3c75e0, 0xfd82, 0x11d2, { 0x8a, 0x2b, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA890-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectVideoSpeedControl = { 0x9d2ea890, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA891-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectVideoRepeat = { 0x9d2ea891, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA892-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectVideoFrameToMask = { 0x9d2ea892, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA893-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectMonoAudioPan = { 0x9d2ea893, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA894-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectMonoAudioGain = { 0x9d2ea894, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };
// {9D2EA895-0968-11d3-8A38-0050040EF7D2}
const aafUID_t kAAFEffectStereoAudioGain = { 0x9d2ea895, 0x968, 0x11d3, { 0x8a, 0x38, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };

// {1575E350-FCA3-11d2-8A2A-0050040EF7D2}
const aafUID_t kAAFOperationUnknown = { 0x1575e350, 0xfca3, 0x11d2, { 0x8a, 0x2a, 0x0, 0x50, 0x4, 0xe, 0xf7, 0xd2 } };




