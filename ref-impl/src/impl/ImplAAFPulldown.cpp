/***********************************************\
*												*
* Advanced Authoring Format						*
*												*
* Copyright (c) 1998-1999 Avid Technology, Inc. *
* Copyright (c) 1998-1999 Microsoft Corporation *
*												*
\***********************************************/

#include "AAFStoredObjectIDs.h"

#ifndef __ImplAAFPulldown_h__
#include "ImplAAFPulldown.h"
#endif

#include <assert.h>
#include <string.h>
#include "aafErr.h"
#include "aafCvt.h"
#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"
#include "ImplAAFTimecode.h"

ImplAAFPulldown::ImplAAFPulldown ()
: _inputSegment(        PID_Pulldown_InputSegment,          "InputSegment"),
  _pulldownKind(        PID_Pulldown_PulldownKind,          "PulldownKind"),
  _pulldownDirection(   PID_Pulldown_PulldownDirection,     "PulldownDirection"),
  _phaseFrame(			PID_Pulldown_PhaseFrame,	        "PhaseFrame")
{
	_persistentProperties.put(_inputSegment.address());
	_persistentProperties.put(_pulldownKind.address());
	_persistentProperties.put(_pulldownDirection.address());
	_persistentProperties.put(_phaseFrame.address());
}


ImplAAFPulldown::~ImplAAFPulldown ()
{
	ImplAAFSegment *seg = _inputSegment.setValue(0);
	if (seg)
	{
		seg->ReleaseReference();
	}
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::GetInputSegment (
      ImplAAFSegment **ppInputSegment)
{
	if (ppInputSegment == NULL)
		return AAFRESULT_NULL_PARAM;

	*ppInputSegment = _inputSegment;
	// !!!Handle case where inputseg may not
	// exist, return  AAFRESULT_NO_ESSENCE_DESC.

  if (*ppInputSegment)
    (*ppInputSegment)->AcquireReference();

	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SetInputSegment (
      ImplAAFSegment *pInputSegment)
{
	if (pInputSegment == NULL)
		return AAFRESULT_NULL_PARAM;

	ImplAAFSegment *pOldSeg = _inputSegment;
	if (pOldSeg)
		pOldSeg->ReleaseReference();

	_inputSegment = pInputSegment;
	
	if (pInputSegment)
		pInputSegment->AcquireReference();

	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::GetPulldownKind (
      aafPulldownKind_t *pPulldownKind)
{
	if (pPulldownKind == NULL)
		return AAFRESULT_NULL_PARAM;

	*pPulldownKind = _pulldownKind;

	return AAFRESULT_SUCCESS;
}




AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SetPulldownKind (
      aafPulldownKind_t  pulldownKind)
{
	_pulldownKind = pulldownKind;
	
	return AAFRESULT_SUCCESS;
}




AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::GetPulldownDirection (
      aafPulldownDir_t *pPulldownDirection)
{
	if (pPulldownDirection == NULL)
		return AAFRESULT_NULL_PARAM;

	*pPulldownDirection = _pulldownDirection;

	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SetPulldownDirection (
      aafPulldownDir_t  pulldownDirection)
{
	_pulldownDirection = pulldownDirection;
	
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::GetPhaseFrame (
      aafPhaseFrame_t *pPhaseFrame)
{
	if (pPhaseFrame == NULL)
		return AAFRESULT_NULL_PARAM;

	*pPhaseFrame = _phaseFrame;

	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SetPhaseFrame (
      aafPhaseFrame_t  phaseFrame)
{
	_phaseFrame = phaseFrame;
	
	return AAFRESULT_SUCCESS;
}


  // Override from AAFSegment
  AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SegmentOffsetToTC (/*[in]*/ aafPosition_t *  /*pOffset*/,
      /*[out]*/ aafTimecode_t *  /*pTimecode*/)
  {
    return AAFRESULT_NOT_IMPLEMENTED;
  }

  // Override from AAFSegment
  AAFRESULT STDMETHODCALLTYPE
    ImplAAFPulldown::SegmentTCToOffset (/*[in]*/ aafTimecode_t *  /*pTimecode*/,
      /*[in]*/ aafRational_t *  /*pEditRate*/,
      /*[out]*/ aafFrameOffset_t *  /*pOffset*/)
  {
    return AAFRESULT_NOT_IMPLEMENTED;
  }

AAFRESULT ImplAAFPulldown::MapOffset(aafPosition_t offset,
			   aafBool reverse,
			   aafLength_t *numFrames,
			   aafInt32 *srcPhase)
{
  ImplAAFSegment*	pulldownCVAL = NULL;
  aafUInt32     maskBits;
  aafBool       drop;
  aafUInt32     phaseOffset = 0;
  aafInt32	        sign, revolutions, ones = 0L, tmpOnes = 0L;
  char          	masksize, maskones, remainder;
  aafPosition_t 	zeroPos;
  aafInt32     		offset32, full = 0L, maskLen;
	aafBool				oneToOne;
	
  XPROTECT()
    {
      /* Get properties off of the pulldown */
		{
			phaseOffset = (aafUInt32)_phaseFrame;
			
			drop = (_pulldownDirection == kAAFTapeToFilmSpeed ? AAFTrue : AAFFalse);
			CHECK(aafPvtGetPulldownMask(_pulldownKind, &maskBits, &maskLen, &oneToOne));
		}

	  if(oneToOne)
	  {
	  	if(numFrames)
	  		*numFrames = offset;
	  }
	  else
	  {		
		  if (reverse)
			  drop = (drop ? AAFFalse : AAFTrue);

		  CvtInt32toPosition(0, zeroPos);
		  if (Int64Less(offset, zeroPos))
			sign = -1;
		  else 
			sign = 1;
		  TruncInt64toInt32(offset, &offset32);	/* OK FRAMEOFFSET */

		  MaskGetBits(maskBits, &maskones);
		  masksize = (char)maskLen;
		  /* If dropping frames */
		  if (drop)
			{
			  if (maskBits)
				{
				  revolutions = abs(offset32) / masksize;
				  remainder = offset32 % masksize;
				  if(srcPhase != NULL)
				  	*srcPhase = remainder;
				  
				  ones = revolutions * maskones;
				  GetRemFramesDrop(maskBits, remainder, phaseOffset, masksize, &tmpOnes);
				  ones += tmpOnes;
				  ones *= sign;

				  if (numFrames)
					CvtInt32toInt64(ones, numFrames);
				}
			} 

		  else /* Doubling frames */
			{
			  if (maskBits)
				{
				  revolutions = abs(offset32) / maskones;
				  remainder = offset32 % maskones;
				  if(srcPhase != NULL)
				  	*srcPhase = remainder;

				  full = revolutions * masksize;
				  GetRemFramesDouble(maskBits, remainder, phaseOffset, masksize, &tmpOnes);
				  full += tmpOnes;
				  full *= sign;

				  if (numFrames)
					CvtInt32toInt64(full, numFrames);
				}
			}
		}
    }

  XEXCEPT
    {
    }
  XEND;

  return(AAFRESULT_SUCCESS);
}

AAFRESULT ImplAAFPulldown::GetRemFramesDrop(aafUInt32 maskBits, 
							char ones, 
							aafUInt32 phase,
							aafUInt32 masksize,
							aafInt32 *result)
{
  long remMask, maskBitsLeft;
  aafInt32 ret;
  unsigned char phasePtr;

  remMask = maskBits;
  
  /* Shift mask to start at phase we want */
  for (phasePtr=0; phasePtr<phase; remMask<<=1,phasePtr++)
	;

  for (ret=0, maskBitsLeft = masksize; ones--; remMask<<=1, maskBitsLeft--)
	{
	  if (maskBitsLeft == 0)
	  {
	  	remMask = maskBits;
	  	maskBitsLeft = masksize;
	  }
	  if (remMask<0L)  /* Is high bit a 1 */
		ret++;
	}

  if (result)
	*result = ret;

  return(AAFRESULT_SUCCESS);
 }

AAFRESULT ImplAAFPulldown::GetRemFramesDouble(aafUInt32 maskBits, 
							char ones,
							aafUInt32 phase,
							aafUInt32 masksize,
							aafInt32 *result)
{
  long remMask, maskBitsLeft;
  aafInt32 ret;
  aafUInt32 phasePtr;

  remMask = maskBits;

  /* Shift mask to start at phase we want */
  for (phasePtr=0; phasePtr<phase; remMask<<=1,phasePtr++)
	;
  for (ret=0,phasePtr=phase, maskBitsLeft = masksize; ones; remMask<<=1,
  										phasePtr++, maskBitsLeft--)
	{
	  if (maskBitsLeft == 0)
		{
		  remMask = maskBits;
		  phasePtr = 0;
	  	maskBitsLeft = masksize;
		}
	  ret++;
	  if (remMask<0L)
		ones--;
	}

  if (result)
	*result = ret;
  return(AAFRESULT_SUCCESS);
}

AAFRESULT ImplAAFPulldown::MaskGetBits(aafUInt32 maskBits, char *maskones)
{
  aafInt32 tmpMask;
  char		ones;

  /* Iterate over the mask counting all bits and 1-bits */
  for (tmpMask=maskBits,ones=0; tmpMask; tmpMask<<=1)
	{
	  /* If high bit is 1 */
	  if (tmpMask<0) 
		ones++;
	}

  if (maskones)
	*maskones = ones;
  return(AAFRESULT_SUCCESS);
 }

AAFRESULT ImplAAFPulldown::aafPvtGetPulldownMask(
			   aafPulldownKind_t	pulldown,
			   aafUInt32 			*outMask,
			   aafInt32				*maskLen,
			   aafBool	 			*isOneToOne)
{
	switch(pulldown)
	{
		/* !! How do we handle "average of fields" mode (it's still even or odd dominant */
		/* NTSC pullown pattern is:
		 *		AA BB BC CD DD
		 *			Looking at the odd field, we see:
		 *				A B B C D
		 */
		case kAAFTwoThreePD:
			*outMask = 0xD8000000;	/* 3623878656 decimal */
			*maskLen = 5;
			*isOneToOne = AAFFalse;
			break;
		/* PAL pullown pattern is:
		 *		AA BB CC DD EE FF GG HH II JJ KK LL MM MN NO OP PQ QR RS ST TU UV VW WX XY YY
		 *			Looking at the odd field, we see:
		 *				A B C D E F G H I J K L M M N O P Q R S T U V W X Y
		 */
		case kAAFPALPD:
			*outMask = 0xFFF7FF80;
			*maskLen = 25;
			*isOneToOne = AAFFalse;
			break;
			
		case kAAFOneToOneNTSC:
		case kAAFOneToOnePAL:
			*isOneToOne = AAFTrue;
			
		default:
			return(AAFRESULT_PULLDOWN_KIND);
	}
	
	return(AAFRESULT_SUCCESS);
}

AAFRESULT ImplAAFPulldown::intSegmentOffsetToTC(aafPosition_t offset, aafTimecode_t *tc, aafBool *found)
{
	ImplAAFSegment	*pdwnInput;
	aafLength_t	newStart;
	aafInt32	start32;
	
  XPROTECT()
    {
		pdwnInput = _inputSegment;
		CHECK(((ImplAAFTimecode *)pdwnInput)->GetTimecode(tc));
		*found = AAFTrue;
		  CHECK(MapOffset(offset, AAFFalse, &newStart, NULL));
		  CHECK(TruncInt64toInt32(newStart, &start32));
		  tc->startFrame += start32;
    }

  XEXCEPT
    {
    }
  XEND;

  return(AAFRESULT_SUCCESS);
}

AAFRESULT ImplAAFPulldown::TraverseToClip(aafLength_t length,
					ImplAAFSegment **sclp,
					 ImplAAFPulldown **pulldownObj,
					 aafInt32 *pulldownPhase,
					 aafLength_t *sclpLen,
					 aafBool *isMask)
{
  aafLength_t	tmpLen;
  aafInt32		phase;
  
  XPROTECT()
    {
	  *isMask = AAFTrue;
	  /* Get the (assumed) source clip out of the mask */
	  *sclp = _inputSegment;
//!!!	  if (!(*sclp)->IsTypeOf("SCLP", &aafError));
////		{
//		  RAISE(OM_ERR_NO_MORE_MOBS);
//		}
	  tmpLen = length;
	  CHECK((*sclp)->GetLength(sclpLen));
	  CHECK(MapOffset(tmpLen, AAFFalse, &length, &phase));
	  if(pulldownObj != NULL)
	  	*pulldownObj = (ImplAAFPulldown *)this;
	  if(pulldownPhase != NULL)
	  	*pulldownPhase = phase;
 	  if (Int64Less(length, *sclpLen))
		{
		  *sclpLen = length;
		}
    }

  XEXCEPT
    {
    }
  XEND;

  return(AAFRESULT_SUCCESS);
}

OMDEFINE_STORABLE(ImplAAFPulldown, AUID_AAFPulldown);


