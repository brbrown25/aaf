#ifndef __ImplAAFDigitalImageDescriptor_h__
#define __ImplAAFDigitalImageDescriptor_h__

//=---------------------------------------------------------------------=
//
// $Id: ImplAAFDigitalImageDescriptor.h,v 1.16.2.1 2004/08/09 22:13:50 akharkev Exp $ $Name:  $
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

#ifndef __ImplAAFFileDescriptor_h__
#include "ImplAAFFileDescriptor.h"
#endif

#include "OMArrayProperty.h"

class ImplAAFDigitalImageDescriptor : public ImplAAFFileDescriptor
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFDigitalImageDescriptor ();

protected:
  virtual ~ImplAAFDigitalImageDescriptor ();

public:
  //****************
  // SetCompression()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetCompression
		// @parm [in] Identifies the compression and format of compression information
        (const aafUID_t & compression);

  //****************
  // SetStoredView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetStoredView
	    (// @parm [in] Number of pixels in vertical dimension of stored view.
         aafUInt32  StoredHeight,

		 // @parm [in] Number of pixels in horizontal dimension of stored view.
		 aafUInt32  StoredWidth);

  //****************
  // SetSampledView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetSampledView
        (// @parm [in] Number of pixels in vertical dimension of sampled view.
		 aafUInt32  SampledHeight,

		 // @parm [in] Number of pixels in horizontal dimension of sampled view.
		 aafUInt32  SampledWidth,

		 // @parm [in] Number of pixels from top left corner of sampled view. Optional.
         aafInt32  SampledXOffset,

		 // @parm [in] Number of pixels from top left corner of sampled view. Optional.
		 aafInt32  SampledYOffset);

  //****************
  // SetDisplayView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetDisplayView
        (// @parm [in] Number of pixels in vertical dimension of display view. Optional.
		 aafUInt32  DisplayHeight,

		 // @parm [in] Number of pixels in horizontal dimension of display view. Optional.
		 aafUInt32  DisplayWidth,

		 // @parm [in] Number of pixels from the top-left corner of the display view. Optional.
         aafInt32  DisplayXOffset,

		 // @parm [in] Number pixels from the top-left corner of the display view. Optional.
		 aafInt32  DisplayYOffset);

  //****************
  // SetFrameLayout()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetFrameLayout
		// @parm [in] layout of the frame
        (aafFrameLayout_t  FrameLayout);

  //****************
  // SetVideoLineMap()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetVideoLineMap
	    (// @parm [in] The number of elements in the array
         aafUInt32  numberElements,

		 // @parm [in, size_is(size)] Array to hold the Video Line Map information
		 aafInt32 *  pVideoLineMap);

  //****************
  // SetImageAspectRatio()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetImageAspectRatio
		// @parm [in] Ratio between horizontal and vertical size
        (aafRational_t  ImageAspectRatio);

  //****************
  // SetAlphaTransparency()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetAlphaTransparency
		// @parm [in] Optional.
        (aafAlphaTransparency_t  AlphaTransparency);

  //****************
  // SetGamma()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetGamma
		// @parm [in] Optional
        (aafUID_t  Gamma);

  //****************
  // SetImageAlignmentFactor()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetImageAlignmentFactor
		// @parm [in] Optional.
        (aafInt32  ImageAlignmentFactor);

  //****************
  // GetCompression()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetCompression
		// @parm [out] Identifies the compression and format of compression information
        (aafUID_t *  pCompression);

  //****************
  // GetStoredView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetStoredView
	    (// @parm [out] Number of pixels in vertical dimension of stored view.
         aafUInt32 *  pStoredHeight,

		 // @parm [out] Number of pixels in horizontal dimension of stored view.
		 aafUInt32 *  pStoredWidth);

  //****************
  // GetSampledView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetSampledView
        (// @parm [out] Number of pixels in vertical dimension of sampled view.
		 aafUInt32 *  pSampledHeight,

		 // @parm [out] Number of pixels in horizontal dimension of sampled view.
		 aafUInt32 *  pSampledWidth,

		 // @parm [out] Number of pixels from top left corner of sampled view. Optional.
         aafInt32 *  pSampledXOffset,

		 // @parm [out] Number of pixels from top left corner of sampled view. Optional.
		 aafInt32 *  pSampledYOffset);

  //****************
  // GetDisplayView()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetDisplayView
        (// @parm [out] Number of pixels in vertical dimension of display view. Optional.
		 aafUInt32 *  pDisplayHeight,

		 // @parm [out] Number of pixels in horizontal dimension of display view. Optional.
		 aafUInt32 *  pDisplayWidth,

		 // @parm [out] Number of pixels from the top-left corner of the display view. Optional.
         aafInt32 *  pDisplayXOffset,

		 // @parm [out] Number pixels from the top-left corner of the display view. Optional.
		 aafInt32 *  pDisplayYOffset);

  //****************
  // GetFrameLayout()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetFrameLayout
		// @parm [out] layout of the frame
        (aafFrameLayout_t *  pFrameLayout);

  //****************
  // GetVideoLineMap()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetVideoLineMapSize
	    (// @parm [out] The number of elements in the array
         aafUInt32 *  pNumberElements);

  //****************
  // GetVideoLineMap()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetVideoLineMap
	    (// @parm [in] The number of elements in the array
         aafUInt32  numberElements,

		 // @parm [out, size_is(numberElements)] Array to hold the Video Line Map information
		 aafInt32 *  pVideoLineMap);

  //****************
  // GetImageAspectRatio()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetImageAspectRatio
		// @parm [out] Ratio between horizontal and vertical size
        (aafRational_t *  pImageAspectRatio);

  //****************
  // GetAlphaTransparency()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetAlphaTransparency
		// @parm [out] Optional.
        (aafAlphaTransparency_t *  pAlphaTransparency);

  //****************
  // GetGamma()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetGamma
		// @parm [out] Optional.
        (aafUID_t *  pGamma);

  //****************
  // GetImageAlignmentFactor()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetImageAlignmentFactor
		// @parm [out] Optional.
        (aafUInt32 *  pImageAlignmentFactor);

protected:
	OMFixedSizeProperty<aafUID_t>				_compression;
	OMFixedSizeProperty<aafUInt32>				_storedHeight;
	OMFixedSizeProperty<aafUInt32>				_storedWidth;
	OMFixedSizeProperty<aafUInt32>				_sampledHeight;
	OMFixedSizeProperty<aafUInt32>				_sampledWidth;
	OMFixedSizeProperty<aafInt32>				_sampledXOffset;
	OMFixedSizeProperty<aafInt32>				_sampledYOffset;
	OMFixedSizeProperty<aafUInt32>				_displayHeight;
	OMFixedSizeProperty<aafUInt32>				_displayWidth;
	OMFixedSizeProperty<aafInt32>				_displayXOffset;
	OMFixedSizeProperty<aafInt32>				_displayYOffset;
	OMFixedSizeProperty<aafFrameLayout_t>		_frameLayout;
	OMArrayProperty<aafInt32>			_videoLineMap;
	OMFixedSizeProperty<aafRational_t>			_imageAspectRatio;
	OMFixedSizeProperty<aafAlphaTransparency_t>	_alphaTransparency;
	OMFixedSizeProperty<aafUID_t>				_gamma;
	OMFixedSizeProperty<aafUInt32>				_imageAlignmentFactor;
};

#endif // ! __ImplAAFDigitalImageDescriptor_h__

