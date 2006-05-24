//=---------------------------------------------------------------------=
//
//
// $Id: ImplAAFMPEGVideoDescriptor.cpp,v 1.2 2006/05/24 18:01:51 tbingham Exp $ $Name:  $
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
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=










#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#ifndef __ImplAAFMPEGVideoDescriptor_h__
#include "ImplAAFMPEGVideoDescriptor.h"
#endif

#include <string.h>


ImplAAFMPEGVideoDescriptor::ImplAAFMPEGVideoDescriptor ():

	_singleSequence(PID_MPEGVideoDescriptor_SingleSequence,					L"SingleSequence"),
	_constantBPictureCount(PID_MPEGVideoDescriptor_ConstantBPictureCount,	L"ConstantBPictureCount"),
	_codedContentScanning(PID_MPEGVideoDescriptor_CodedContentScanning,		L"CodedContentScanning"),
	_lowDelay(PID_MPEGVideoDescriptor_LowDelay,								L"LowDelay"),
	_closedGOP(PID_MPEGVideoDescriptor_ClosedGOP,							L"ClosedGOP"),
	_identicalGOP(PID_MPEGVideoDescriptor_IdenticalGOP,						L"IdenticalGOP"),
	_maxGOP(PID_MPEGVideoDescriptor_MaxGOP,									L"MaxGOP"),
	_maxBPictureCount(PID_MPEGVideoDescriptor_MaxBPictureCount,				L"MaxBPictureCount"),
	_bitRate(PID_MPEGVideoDescriptor_BitRate,								L"BitRate"),
	_profileAndLevel(PID_MPEGVideoDescriptor_ProfileAndLevel,				L"ProfileAndLevel")
	
{

	_persistentProperties.put(_singleSequence.address());
	_persistentProperties.put(_constantBPictureCount.address());
	_persistentProperties.put(_codedContentScanning.address());
	_persistentProperties.put(_lowDelay.address());
	_persistentProperties.put(_closedGOP.address());
	_persistentProperties.put(_identicalGOP.address());
	_persistentProperties.put(_maxGOP.address());
	_persistentProperties.put(_maxBPictureCount.address());
	_persistentProperties.put(_bitRate.address());
	_persistentProperties.put(_profileAndLevel.address());
  
  
}


ImplAAFMPEGVideoDescriptor::~ImplAAFMPEGVideoDescriptor ()
{}

AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::Initialize ()
{
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetSingleSequence (
      aafBoolean_t  singleSequence)
{
	_singleSequence = singleSequence;
	return AAFRESULT_SUCCESS;
	
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetSingleSequence (
      aafBoolean_t *  pSingleSequence)
{
  
  if( pSingleSequence == NULL )
    {
        return AAFRESULT_NULL_PARAM;
    }
	if( !_singleSequence.isPresent() )
    {
		return AAFRESULT_PROP_NOT_PRESENT;
    }


    *pSingleSequence = _singleSequence;


    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetConstantBPictureCount (
      aafBoolean_t  constantBPictureCount)
{
  	_constantBPictureCount = constantBPictureCount;
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetConstantBPictureCount (
      aafBoolean_t *  pConstantBPictureCount)
{
  	if( pConstantBPictureCount == NULL )
    	{
        	return AAFRESULT_NULL_PARAM;
	    }
	if( !_constantBPictureCount.isPresent() )
	    {
			return AAFRESULT_PROP_NOT_PRESENT;
	    }
	
	
	*pConstantBPictureCount = _constantBPictureCount;
	
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetCodedContentScanning (
      aafContentScanningType_t  codedContentScanning)
{
	
	_codedContentScanning = codedContentScanning;

	return AAFRESULT_SUCCESS;  

}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetCodedContentScanning (
      aafContentScanningType_t *  pContentScanning)
{
  	if (pContentScanning == NULL)
	  	return AAFRESULT_NULL_PARAM;

	if (!_codedContentScanning.isPresent())
	  	return AAFRESULT_PROP_NOT_PRESENT;

	*pContentScanning = _codedContentScanning;

	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetLowDelay (
      aafBoolean_t  lowDelay)
{
  	_lowDelay = lowDelay;
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetLowDelay (
      aafBoolean_t *  pLowDelay)
{
	if( pLowDelay == NULL )
    	{
        	return AAFRESULT_NULL_PARAM;
	    }
	
	if( !_lowDelay.isPresent() )
	    {
			return AAFRESULT_PROP_NOT_PRESENT;
	    }
	
	
	*pLowDelay = _lowDelay;
	
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetClosedGOP (
      aafBoolean_t  closedGOP)
{
	_closedGOP = closedGOP;
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetClosedGOP (
      aafBoolean_t *  pClosedGOP)
{
	if( pClosedGOP == NULL )
    	{
        	return AAFRESULT_NULL_PARAM;
	    }
	
	if( !_closedGOP.isPresent() )
	    {
			return AAFRESULT_PROP_NOT_PRESENT;
	    }
	
	
	*pClosedGOP = _closedGOP;
	
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetIdenticalGOP (
      aafBoolean_t  identicalGOP)
{
	_identicalGOP = identicalGOP;
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetIdenticalGOP (
      aafBoolean_t *  pIdenticalGOP)
{
	if( pIdenticalGOP == NULL )
    	{
        	return AAFRESULT_NULL_PARAM;
	    }
	
	if( !_identicalGOP.isPresent() )
	    {
			return AAFRESULT_PROP_NOT_PRESENT;
	    }
	
	
	*pIdenticalGOP = _identicalGOP;
	
	
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetMaxGOP (
      aafUInt16  maxGOP)
{
	_maxGOP = maxGOP;
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetMaxGOP (
      aafUInt16 *  pMaxGOP)
{
	if( pMaxGOP == NULL )
    {
        return AAFRESULT_NULL_PARAM;
    }
    
	if( !_maxGOP.isPresent() )
    {
		return AAFRESULT_PROP_NOT_PRESENT;
    }


    *pMaxGOP = _maxGOP;


    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetMaxBPictureCount (
      aafUInt16  maxBPictureCount)
{
	_maxBPictureCount = maxBPictureCount;
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetMaxBPictureCount (
      aafUInt16 *  pMaxBPictureCount)
{
	if( pMaxBPictureCount == NULL )
    {
        return AAFRESULT_NULL_PARAM;
    }
    
	if( !_maxBPictureCount.isPresent() )
    {
		return AAFRESULT_PROP_NOT_PRESENT;
    }


    *pMaxBPictureCount = _maxBPictureCount;


    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetBitRate (
      aafUInt32  bitRate)
{
	_bitRate = bitRate;
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetBitRate (
      aafUInt32 *  pBitRate)
{
	if( pBitRate == NULL )
    {
        return AAFRESULT_NULL_PARAM;
    }
    
	if( !_bitRate.isPresent() )
    {
		return AAFRESULT_PROP_NOT_PRESENT;
    }


    *pBitRate = _bitRate;


    return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::SetProfileAndLevel (
      aafUInt8  profileAndLevel)
{
	_profileAndLevel = profileAndLevel;
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFMPEGVideoDescriptor::GetProfileAndLevel (
      aafUInt8 *  pProfileAndLevel)
{
	if( pProfileAndLevel == NULL )
    {
        return AAFRESULT_NULL_PARAM;
    }
    
	if( !_profileAndLevel.isPresent() )
    {
		return AAFRESULT_PROP_NOT_PRESENT;
    }


    *pProfileAndLevel = _profileAndLevel;


    return AAFRESULT_SUCCESS;
}




