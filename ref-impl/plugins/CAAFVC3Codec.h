//@doc
//@class    CAAFVC3Codec | Implementation class for AAFEssenceCodec
#ifndef __CAAFVC3Codec_h__
#define __CAAFVC3Codec_h__

//=---------------------------------------------------------------------=
//
// $Id: CAAFVC3Codec.h,v 1.1 2008/07/14 17:06:12 terabrit Exp $ $Name:  $
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


// Include the interfaces that our plugin needs to support.
#include "AAFPlugin.h"

// Include our base class for support of IUnknown methods.
#include "CAAFUnknown.h"

#include "AAFUtils.h" // AAFByteOrder

#ifndef __CAAFCDCIDescriptorHelper_h__
#include "CAAFCDCIDescriptorHelper.h"
#endif

// ID for this Plugin's CoClass.
EXTERN_C const CLSID CLSID_AAFVC3Codec;


#define VC3HEADERSIZE 640

#define MAX_VC3_UNCOMPRESSED_FRAME (1080*(1920/2)*8)
#define MAX_VC3_COMPRESSED_FRAME (917504)

class CAAFVC3Codec
  : public IAAFEssenceCodec2,
	public IAAFEssenceCodec,
	public IAAFPlugin,
	public CAAFUnknown
{
protected:

  //********
  //
  // Constructor/destructor
  //
  CAAFVC3Codec (IUnknown * pControllingUnknown);
  virtual ~CAAFVC3Codec ();

public:

  //
  // IAAFPlugin interface methods
	//

  STDMETHOD (CountDefinitions)
	  (/*[out]*/ aafUInt32 *pDefCount);

  STDMETHOD (GetIndexedDefinitionID)
	  (/*[in] */ aafUInt32 index, 
		 /*[out]*/ aafUID_t *result);

  STDMETHOD (GetPluginDescriptorID)
	  (/*[out]*/ aafUID_t *result);

  STDMETHOD (GetIndexedDefinitionObject)
	  (/*[in] */ aafUInt32 index, 
		 /*[in] */ IAAFDictionary *dict, 
		 /*[out]*/ IAAFDefObject **def);

  STDMETHOD (CreateDescriptor)
	  (/*[in] */ IAAFDictionary *dict,
		 /*[out]*/ IAAFPluginDef **desc);


  //
  // IAAFEssenceCodec interface methods
	//
	
	// Set the AAFEssenceAccess used as a factory for AAFEssenceFormat 
  STDMETHOD (SetEssenceAccess)
    (/*[in] */ IAAFEssenceAccess *access);

  STDMETHOD (CountFlavours)
    (/*[in] */ aafUInt32  *pCount);

	// Some codecs have variants handled by a single codec.
	// (For example, the Avid AVR codec handles multiple AVRs.)
	// The number of variants is returned by GetIndexedFlavourID, and cached
	// by the AAFPluginManager.
	//
  STDMETHOD (GetIndexedFlavourID)
    (/*[in] */ aafUInt32  index, // Which flavour to get the ID for
     /*[out]*/ aafUID_t *  pFlavour); // The returned flavour ID 

  STDMETHOD (CountDataDefinitions)
    (/*[out] */ aafUInt32 *pCount);

	// All codecs handle at least one kind of media (picture, sound, control)
	    // but some handle more than one.  The kind of media is specified by an
	    // AAFDataDefinition.  The numnber of data definitions is returned by
	    // GetIndexedDataDefinition, and cached by the AAFPluginManager.
  STDMETHOD (GetIndexedDataDefinition)
    (/*[in] */ aafUInt32  index, // Which data definition to get the ID for
     /*[out]*/ aafUID_t * pFlavour); // The returned dataDefinition 

  STDMETHOD (GetMaxCodecDisplayNameLength)
    (/*[out]*/ aafUInt32  *bufSize);

	// Given a flavour ID, return the human readable name
  STDMETHOD (GetCodecDisplayName)
    (/*[in] */ aafUID_constref  flavour, // which flavour of the codec to use
     /*[in,string]*/ aafCharacter *  pName, // Human-readable name of the flavour
     /*[in] */ aafUInt32  bufSize); // length of the buffer to hold flavour Name 

	// Switches the codec into the specified flavour.
  STDMETHOD (SetFlavour)
    (/*[in]*/ aafUID_constref flavour);

  // Returns the number of channels which this codec can handle
			// of the given essence kind
  STDMETHOD (CountChannels)
    (/*[in] */ IAAFSourceMob *fileMob, // Get the number of processable channels on this file mob
     /*[in] */ aafUID_constref essenceKind, // This is the type of essence to open
     /*[in] */ IAAFEssenceStream *stream,
     /*[out]*/ aafUInt16 *  pNumChannels); // The number of channels present 

  STDMETHOD (GetSelectInfo)
	  (/*[in] */ IAAFSourceMob *fileMob, 
		 /*[in] */ IAAFEssenceStream *stream, 
		 /*[out]*/ aafSelectInfo_t *  pSelectInfo);
	 
  // Returns a (possibly zero-length) string listing any problems
			//found with the essence, or the relationship between variables
			// in the essence descriptor, and any such values contained within
			// the essence data
  STDMETHOD (ValidateEssence)
    (/*[in] */ IAAFSourceMob *fileMob, // Run a check on this file mob
     /*[in] */ IAAFEssenceStream *stream,
     /*[in] */ aafCheckVerbose_t  verbose, // This is the verbosity level of the output
     /*[out]*/ aafCheckWarnings_t warning, // This determines whether the output contains warnings
     /*[in] */ aafUInt32  bufSize,
		 /*[in, string] */ wchar_t *  pName,
     /*[out]*/ aafUInt32  *bytesWritten);
		
  // Create a media data object, and attach the correct type of
			//EssenceDescriptor to the fileMob
  STDMETHOD (Create)
    (/*[in]*/ IAAFSourceMob *fileMob, // Create the essence attached to this file mob
     /*[in]*/ aafUID_constref flavour, // which flavour of the codec to use
     /*[in]*/ aafUID_constref essenceKind, // This is the type of essence to create
     /*[in]*/ aafRational_constref sampleRate,
     /*[in]*/ IAAFEssenceStream * stream, // stream to write the data
     /*[in]*/ aafCompressEnable_t compEnable); // whether or not samples should be written compressed

  // Open a media data object.
  STDMETHOD (Open)
    (/*[in]*/ IAAFSourceMob *fileMob, // Open the essence attached to this file mob
     /*[in]*/ aafMediaOpenMode_t  openMode, // In this mode
     /*[in]*/ IAAFEssenceStream * stream, // Here is an essence stream with the raw data 
     /*[in]*/ aafCompressEnable_t compEnable); // whether or not samples should be read compressed

  // Returns the number of samples which this codec can find on the
			// given slot.
  STDMETHOD (CountSamples)
    (/*[in] */ aafUID_constref essenceKind, // This is the type of essence to check
	   /*[out]*/ aafLength_t *  pNumSamples); // The number of samples present of that type

  STDMETHOD (WriteSamples) (
    /*[in]*/ aafUInt32  nSamples, // write this many samples
    /*[in]*/ aafUInt32  buflen,  // size of buffer
    /*[in,size_is(buflen)]*/ aafDataBuffer_t  buffer, // from a buffer
    /*[out]*/ aafUInt32 *samplesWritten, // write this many samples
    /*[out]*/ aafUInt32 *bytesWritten);  // size of buffer

  STDMETHOD (ReadSamples) (  
    /*[in]*/ aafUInt32  nSamples, // Read this many samples
    /*[in]*/ aafUInt32  buflen, // into a buffer of this size
    /*[out]*/ aafDataBuffer_t  buffer, // The transfer buffer
    /*[out, ref]*/ aafUInt32 *  samplesRead, // The number of samples actually read
    /*[out, ref]*/ aafUInt32 *  bytesRead); // The number of bytes actually read

  // Seek to a particular sample frame on the media.  The
			// sample frame is one frame for picture, and one sample
			// times the number of interleaved channels for audio.
  STDMETHOD (Seek)
    (/*[in]*/ aafPosition_t  sampleFrame); // The sample frame to seek to. 

  // Close the media stream, ready to open another or Finish.
  STDMETHOD (CompleteWrite)
     (IAAFSourceMob *desc);


  // Given some raw essence (like a VC3 file), create
			// an AAFEssenceDescriptor to match, with all fields filled in.
  STDMETHOD (CreateDescriptorFromStream)
    (/*[in] */ IAAFEssenceStream * pStream, // A raw file stream
     /*[in] */ IAAFSourceMob *fileMob); // Put the finished descriptor on this source mob 

  // Return the current essence stream.
  STDMETHOD (GetCurrentEssenceStream)
    (/*[out]*/ IAAFEssenceStream ** ppStream); // The current essence stream 
		
  // Set the format of the data.
  STDMETHOD (PutEssenceFormat)
    (/*[in] */ IAAFEssenceFormat * pFormat); // An essence format object 

  // Supply an essence format object specifying what data is
			// required, and it is filled in with the data values.
  STDMETHOD (GetEssenceFormat)
    (/*[in] */ IAAFEssenceFormat *pTemplate, // An essence format template object 
     /*[out]*/ IAAFEssenceFormat **pResult); // An essence format result object 

  STDMETHOD (GetDefaultEssenceFormat)
    (/*[out]*/ IAAFEssenceFormat **pFormat); // An essence format result object 

  STDMETHOD (GetEssenceDescriptorID)
	  (/*[out]*/ aafUID_t *result);

  STDMETHOD (GetEssenceDataID)
	  (/*[out]*/ aafUID_t *result);

  STDMETHOD (GetIndexedSampleSize)
    (/*[in] */ aafUID_constref dataDefID,
		 /*[in] */aafPosition_t pos, 
		 /*[out]*/aafLength_t *pResult);

  STDMETHOD (GetLargestSampleSize)
    (/*[in] */aafUID_constref dataDefID,
		 /*[out]*/aafLength_t *pResult);

protected:
  // 
  // Declare the QI that implements for the interfaces
  // for this module. This will be called by CAAFUnknown::QueryInterface().
  // 
  STDMETHOD(InternalQueryInterface)(REFIID riid, void **ppvObjOut);


public:
  //
  // This class as concrete. All AAF objects can be constructed from
  // a CLSID. This will allow subclassing all "base-classes" by
  // aggreggation.
  // 
  AAF_DECLARE_CONCRETE();
  //
  //********


private:
	void SetEssenceStream(IAAFEssenceStream *stream);
	void SetCompressionEnabled(aafCompressEnable_t compEnable);

  	void SetNumberOfSamples(const aafLength_t& numberOfSamples);


	// Helper utility to make sure the current information in the codec is 
	// synchronized with the given descriptor information . 
	// Called in Open and Create methods.
	STDMETHOD( ReadDescriptor )(CAAFCDCIDescriptorHelper& descriptorHelper);

	// Helper utility to make sure the given descriptor information is synchronized
	// with the current information in the codec. Called in 
	// CompleteWrite and Create methods.
	void UpdateDescriptor (CAAFCDCIDescriptorHelper& descriptorHelper);

	// Prepares codec internals for writing samples
	void SetCodecState(void);

	// Routine to keep calculated member data up-to-date.
	void UpdateCalculatedData(void);

	STDMETHOD( CreateLegacyPropDefs )(IAAFDictionary *p_dict);
	
	bool IsInterlaced()
	{
		if(_ComprID==1241 || _ComprID==1242 || _ComprID==1243 )
			return true;
		return false;
	}

	virtual aafUInt32 GetBytesPerSample()
	{
		switch(_ComprID)
		{
		case 1235:
		case 1238:
		case 1241:
		case 1243:
			return 917504;
			break;
		case 1237:
		case 1242:
			return 606208;
			break;
		case 1250:
		case 1251:
			return 458752;
			break;
		case 1252:
			return 303104;
			break;
		case 1253:
			return 188416;
			break;
		case 1254:
			return 131072;	// FIXME: is this correct?
			break;
		default:
			return 0;
			break;
		}
	}

	aafUInt32 GetUncomprFrameSize()
	{
		if(GetLinesPerField()==720)
		{
			return 720*1280*4;
		}
		return MAX_VC3_UNCOMPRESSED_FRAME;
	}

	bool Is10Bit()
	{
		if( _ComprID==1235 || _ComprID==1241 || _ComprID==1250)
			return true;
		return false;
	}

	int GetLinesPerField()
	{
		switch(_ComprID)
		{
		case 1235:
		case 1237:
		case 1238:
			return 1080;
			break;
		case 1241:
		case 1243:
		case 1242:
			return 540;
			break;
		case 1250:
		case 1251:
		case 1252:
			return 720;
			break;
		case 1253:
		case 1254:
			return 1080;
			break;
		default:
			return 0;
			break;
		}

	}

	int GetPixelsPerLine()
	{
		switch(_ComprID)
		{
		case 1235:
		case 1237:
		case 1238:
		case 1241:
		case 1243:
		case 1242:
			return 1920;
			break;
		case 1250:
		case 1251:
		case 1252:
			return 1280;
			break;
		case 1253:
		case 1254:
			return 1920;
			break;
		default:
			return 0;
			break;
		}
	}




private:
	AAFByteOrder		_nativeByteOrder;

	IAAFEssenceAccess	*_access;
	IAAFEssenceStream	*_stream; // stream for VC3 sample data.


	aafMediaOpenMode_t _openMode; // Either read-only or for append.

	// Data from/to FileDescriptor
	aafLength_t _length; // total size of file (informational?)
	aafRational_t _sampleRate; // same for all samples.
	aafUID_t _containerFormat;	// set by refimpl

	// Data from/to DigitalImageDescriptor
	aafUID_t _compression;

	aafUInt32 _storedHeight;
	aafUInt32 _storedWidth;

	aafUInt32 _sampledHeight; // SampledView
	aafUInt32 _sampledWidth;
	aafInt32 _sampledXOffset;
	aafInt32 _sampledYOffset;

	aafUInt32 _displayHeight; // DisplayView
	aafUInt32 _displayWidth;
	aafInt32 _displayXOffset;
	aafInt32 _displayYOffset;

	aafFrameLayout_t _frameLayout;

	CAAFCDCIDescriptorHelper _descriptorHelper;

	aafUInt32 _videoLineMapSize; // s/b 2, VideoLineMap
	aafVideoLineMap_t  _videoLineMap;

	aafRational_t _imageAspectRatio;
	aafAlphaTransparency_t _alphaTransparency;
	aafUID_t _gamma;
	aafUInt32 _imageAlignmentFactor; // padding for "sector size" on disk for possibly faster access.

	// Data from/to VC3Descriptor
	aafUInt32 _componentWidth; // should always be 8 (no support for 12 bit data).
	aafUInt32 _horizontalSubsampling;
	aafUInt32 _verticalSubsampling; // not currently a property (default to 1 in codec).
	aafColorSiting_t _colorSiting;
	aafUInt32 _blackReferenceLevel;
	aafUInt32 _whiteReferenceLevel;
	aafUInt32 _colorRange;
	aafInt16 _paddingBits;

	// Misc. data copied from omf codec
	aafUInt32 _imageHeight; 
	aafUInt32 _imageWidth;
	aafUInt32 _fileBytesPerSample;
	aafBoolean_t _descriptorFlushed;

	aafColorSpace_t _pixelFormat;
	aafCompArray_t _compArray;

	aafFieldDom_t	_fieldDominance;
	aafUInt32	_fieldStartOffset;
	aafUInt32	_fieldEndOffset;

	aafUInt16 _bitsPerPixelAvg;

	// Copied from WaveCodec...(may be renamed...)
	aafLength_t	_numberOfSamples; /* was _sampleFrames in WaveCodec) */

	aafUInt16 _padBytesPerRow;

#ifdef USE_VC3_CODEC

	// for access to the VC3 Codec SDK
	// please visit http://www.avid.com/DNxHD
	// or contact DNxHDSupport@avid.com

	aafDataBuffer_t	_vc3_buffer;		// enough for PAL or NTSC frame

#endif

	aafCompressEnable_t _compressEnable;

	aafUInt8 _Header[VC3HEADERSIZE];
	aafUInt32 _HeaderFilled;

	aafUInt64 _TotalBytesWritten;


	aafUInt32 _ComprID;
	bool	  _UseLegacyAvidUIDs; //true if the original Avid UIDs are to be used

	aafUInt32 _phys;		// physical slot number - small integer, default = 1
							// will be expanded by the codec for MXF GC

	aafUID_t  _eek;			// MXF GC Essence Element Key
							// codec will set default, taking _UseLegacyAvidUIDs nto account
							// application may override

	//variables from decoding header on read
	int _ALPF;
	int _SPL;
	int _SBD;

};

#endif // ! __CAAFVC3Codec_h__
