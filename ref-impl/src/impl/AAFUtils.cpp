/***********************************************************************
 *
 *              Copyright (c) 1996 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and to distribute
 * and sublicense application software incorporating this software for
 * any purpose is hereby granted, provided that (i) the above
 * copyright notice and this permission notice appear in all copies of
 * the software and related documentation, and (ii) the name Avid
 * Technology, Inc. may not be used in any advertising or publicity
 * relating to the software without the specific, prior written
 * permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT, CONSEQUENTIAL OR OTHER DAMAGES OF
 * ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, INCLUDING, 
 * WITHOUT  LIMITATION, DAMAGES RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, AND WHETHER OR NOT ADVISED OF THE POSSIBILITY OF
 * DAMAGE, REGARDLESS OF THE THEORY OF LIABILITY.
 *
 ************************************************************************/

/*
 * Name: omAcces.c
 *
 * Function: The main API file for media layer operations.
 *
 * Audience: Clients writing or reading AAF media data.
 *
 * Public Functions:
 *		AAFMalloc()
 *			Allocate this many bytes
 *		AAFFree()
 *			Free up this buffer
 *		IsPropertyPresent()
 *			Test if a given property is present in a file.
 *		IsTypeOf()
 *			Test if an object is a member of the given class, or
 *			one of its subclasses.
 *		omfsClassFindSuperClass()
 *			Given a pointer to a classID, returns the superclass ID
 *			and a boolean indicating if a superclass was found.
 *		GetByteOrder()
 *			Return the byte ordering of a particular object in the file. 
 *		omfsPutByteOrder()
 *			Sets the byte ordering of a particular object in the file.
 *		omfsFileGetDefaultByteOrder()
 *			Returns the default byte ordering from the given file.
 *		omfsFileSetDefaultByteOrder()
 *			Sets the default byte ordering from the given file.
 *		GetHeadObject()
 *			Given an opaque file handle, return the head object for
 *			that file.
 *		omfsObjectNew()
 *			Create a new object of a given classID in the given file.
 *		omfsSetProgressCallback()
 *			Sets a callback which will be called at intervals
 *			during long operations, in order to allow your application
 *			to pin a watch cursor, move a thermometer, etc...
 *    GetNextProperty()
 *    GetPropertyName()
 *    omfiGetPropertyTypename()
 *    GetNextObject()
 *
 * Public functions used to extend the toolkit API:
 *	(Used to write wrapper functions for new types and properties)
 *
 *		NewClass()
 *			Add a new class to the class definition table.
 *		omfsRegisterType()
 *			Add a new type to the type definition table.  This function takes an explicit
 *			omType_t, and should be called for required & registered types
 *			which are not registered by a media codec.
 *		omfsRegisterProp()
 *			Register a aafProperty code, supplying a name, class, type, and an enum
 *			value indicating which revisions the field is valid for.  This function takes
 *			an explicit aafProperty_t, and should be called for required & registered
 *			properties which are not registered by a media codec.
 *		omfsRegisterDynamicType()
 *			Register a type with a dynamic type code.  This function should be called when
 *			registering a private type, or when a codec requires a type.  The type code used
 *			to refer to the type is returned from this function, and must be saved in a variable
 *			in the client application, or in the persistant data block of a codec.
 *		omfsRegisterDynamicProp()
 *			Register a type with a dynamic property code.  This function should be called when
 *			registering a private property, or when a codec requires a property.  The type code used
 *			to refer to the property is returned from this function, and must be saved in a variable
 *			in the client application, or in the persistant data block of a codec.
 *		OMReadProp()
 *			Internal function to read the given property from the file, and apply
 *			semantic error checking to the input parameters and the result.
 *		OMWriteProp()
 *			Internal function to write the given property to the file, and apply
 *			semantic error checking to the input parameters.
 *		OMIsPropertyContiguous()
 *			Tell if a property is contigous in the file.   This function
 *			is usually applied to media data, when the application wishes
 *			to read the data directly, without the toolkit.
 *		GetArrayLength()
 *			Get the number of elements in an arrayed AAF object.
 *		OMPutNthPropHdr()
 *			Set an indexed elements value in an arrayed AAF object.
 *		OMGetNthPropHdr()
 *			Get an indexed elements value from an arrayed AAF object.
 *		OMReadBaseProp()
 *			Version of OMReadProp which byte-swaps when needed and always reads
 *			from an offset of 0.
 *		OMWriteBaseProp()
 *			Version of OMWriteProp which always reads from an offset of 0.
 *		OMLengthProp()
 *			Internal function to find the length of the given property.
 *		GetReferencedObject()
 *		GetReferenceData()
 *		OMRemoveNthArrayProp()
 *		omfsFileGetValueAlignment()
 *		omfsFileSetValueAlignment()
 *
 * All functions can return the following error codes if the following
 * argument values are NULL:
 *		OM_ERR_NULL_FHDL -- aafHdl_t was NULL.
 *		OM_ERR_NULLOBJECT -- aafObject_t was NULL.
 *		OM_ERR_BADDATAADDRESS -- Data address was NULL.
 *		OM_ERR_NULL_SESSION -- No session was open.
 *		OM_ERR_SWAB -- Unable to byte swap the given data type.
 * 
 * Any function may also return the following error codes:
 *		OM_ERR_BENTO_PROBLEM -- Bento returned an error, check BentoErrorNumber.
 * 
 * Accessor functions can also return the error codes below:
 *		OM_ERR_BAD_PROP -- aafProperty_t code was out of range.
 *		OM_ERR_OBJECT_SEMANTIC -- Failed a semantic check on an input obj
 *		OM_ERR_DATA_IN_SEMANTIC -- Failed a semantic check on an input data
 *		OM_ERR_DATA_OUT_SEMANTIC -- Failed a semantic check on an output data
 */

//#include "masterhd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if PORT_SYS_MAC
#include <memory.h>		/* For AAFMalloc() and AAFFree() */
#include <OSUtils.h>
#endif
#ifdef _WIN32
#include <time.h>
#endif

//#include "omPublic.h"
//#include "omPvt.h" 
#include "Container.h"
#include "AAFTypes.h"
#include "AAFUtils.h"
#include "aafCvt.h"

/* Moved math.h down here to make NEXT's compiler happy */
#include <math.h>


#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

static aafBool  InitCalled = AAFFalse;

const aafProductVersion_t AAFToolkitVersion = {2, 1, 0, 1, kVersionBeta};


aafBool	EqualAUID(aafUID_t *uid1, aafUID_t *uid2)
{
	return(memcmp((char *)uid1, (char *)uid2, sizeof(aafUID_t)) == 0 ? AAFTrue : AAFFalse);
}

static aafInt32 powi(
			aafInt32	base,
			aafInt32	exponent);

double FloatFromRational(
			aafRational_t	e);		/* IN - Convert this into a double */
aafRational_t RationalFromFloat(
			double	f);		/* IN - Convert this number into a rational */

	/************************************************************
	 *
	 * Public Functions (Part of the toolkit API)
	 *
	 *************************************************************/

/*************************************************************************
 * Private Function: isObjFunc() and set1xEditrate()
 *
 *      These are callback functions used by omfiMobAppendNewSlot()
 *      to recursively attach the CPNT:Editrate property to 1.x
 *      components.  The callback functions are input to the
 *      omfiMobMatchAndExecute() function which traverses a
 *      tree of objects depth first and executes the callbacks.
 *      They will only be called on 1.x files.
 *
 * Argument Notes:
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 *************************************************************************/
aafBool isObjFunc(AAFFile * file,       /* IN - File Handle */
				  AAFObject * obj,     /* IN - Object to match */
				  void *data)          /* IN/OUT - Match Data */
{
  /* Match all objects in the subtree */
  return(AAFTrue);
}


/************************
 * Function: AAFGetDateTime			(INTERNAL)
 *
 * 	Returns the number of seconds since the standard root date
 *		for the current machine.  The date returned here will be converted
 *		to the canonical date format in the date write routine.
 *
 * Argument Notes:
 *		Time - is NATIVE format.  That is relative to 1/1/1904 for the
 *			Mac and 1/1/70? for everyone else.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
void AAFGetDateTime(aafTimeStamp_t *time)
{
#if defined(_MAC) || defined(macintosh)
	GetDateTime(&(time->TimeVal));
	time->IsGMT = FALSE;
#elif  defined(_WIN32)
	time->TimeVal = (long) clock();
	time->IsGMT = FALSE;
#else
	{
		struct timeval  tv;
		struct timezone tz;

		gettimeofday(&tv, &tz);
		time->TimeVal = tv.tv_sec;
		time->IsGMT = false;
	}
#endif
}

aafErr_t AAFConvertEditRate(
	aafRational_t srcRate,        /* IN - Source Edit Rate */
	aafPosition_t srcPosition,    /* IN - Source Position */
	aafRational_t destRate,       /* IN - Destination Edit Rate */
	aafRounding_t howRound,	      /* IN - Rounding method (floor or ceiling) */
	aafPosition_t *destPosition)  /* OUT - Destination Position */
{
	aafInt64		intPos, destPos;
	aafInt32		remainder;
		
	XPROTECT()
	{
		CvtInt32toInt64(0, destPosition);
		if ((howRound != kRoundCeiling) && (howRound != kRoundFloor))
		{
			RAISE(OM_ERR_INVALID_ROUNDING);
		}

		if(FloatFromRational(srcRate) != FloatFromRational(destRate))
		{
			CHECK(MultInt32byInt64((srcRate.denominator * destRate.numerator), srcPosition, &intPos));
			CHECK(DivideInt64byInt32(intPos, (srcRate.numerator * destRate.denominator), &destPos, &remainder));
		}
		else
		{
	  		/* JeffB: (1 / 29.97) * 29.97 often doesn't == 1
	  		 * (it seems to be .99999... on the 68K FPU)
	  		 * The debugger says it's 1.0, but if(foo >= 1.0) fails.
	  		 */
	  		destPos = srcPosition;
	  		remainder = 0;
		}

		/* Usually used for lower edit rate to higher edit rate conversion - 
		 * to return the first sample of the higher edit rate that contains a
		 * sample of the lower edit rate. (i.e., video -> audio)
		 */
		if (howRound == kRoundFloor)
		{
			*destPosition = destPos;
		}
		/* Usually used for higher edit rate to lower edit rate conversion -
		 * to return the sample of the lower edit rate that fully contains
		 * the sample of the higher edit rate. (i.e., audio -> video)
		 */
		else if (howRound == kRoundCeiling)
		{
			*destPosition = destPos;
			if(remainder != 0)
				AddInt32toInt64(1, destPosition);
		}
	} /* XPROTECT */

	XEXCEPT
	{
		return(XCODE());
	}
	XEND;

	return(OM_ERR_NONE);
}

/************************
 * Function: FloatFromRational (INTERNAL)
 *
 * 	Convert a rational number into a floating point double
 *
 * Argument Notes:
 *		See argument comments and assertions.
 *
 * ReturnValue:
 *		The result, or zero if the denominator was zero.
 *
 * Possible Errors:
 *		Returns zero if the denominator was zero.
 */
double FloatFromRational(
			aafRational_t	e)		/* IN - Convert this into a double */
{
	double          num = (double) e.numerator;
	double          den = (double) e.denominator;

	if(den == 0)
		return(0);
	else
		return (num / den);
}


/************************
 * Function: RationalFromFloat (INTERNAL)
 *
 * 	Translate a floating point number into the nearest rational
 *		number.  Used when rates must be stored as floats.
 *
 * Argument Notes:
 *		See argument comments and assertions.
 *
 * ReturnValue:
 *		A rational number
 *
 * Possible Errors:
 */
aafRational_t RationalFromFloat(
			double	f)		/* IN - Convert this number into a rational */
{
	/* chintzy conversion of old code  */
	aafRational_t   rate;
	double          rem;
	aafInt32           i;

	/* special check for NTSC video */
	if (fabs(f - 29.97) < .01)
	{
		rate.numerator = 2997;
		rate.denominator = 100;
		return (rate);
	}
	/* need to normalize to make compare work */
	rem = f - floor(f);
	for (i = 0; (i < 4) && (rem > .001); i++)
	{
		f = f * 10;
		rem = f - floor(f);
	}
	rate.numerator = (aafInt32) f;
	rate.denominator = powi(10L, i);
	return (rate);
}

/************************
 * Function: powi		(INTERNAL)
 *
 * 	Return base ^ exponent.
 *
 * Argument Notes:
 * 	<none>
 *
 * ReturnValue:
 *		The result.
 *
 * Possible Errors:
 *		<none>.
 */
static aafInt32 powi(
			aafInt32	base,
			aafInt32	exponent)
{
	aafInt32           result = 1;
	aafInt32           i = exponent;

	if (exponent == 0)
		return (1);
	else if (exponent > 0)
	{
		while (i--)
			result *= base;
		return (result);
	}
	else
	{
		/* negative exponent not good for integer
		 * exponentiation
		 */
		return (0);
	}
}

#if defined(_MAC) || defined(macintosh)
#include <OSUtils.h>
#include <events.h>
#elif defined(_WIN32)
#include <time.h>
#define HZ CLK_TCK
#endif

/*
 * Doug Cooper - 04-04-96
 * Added proper includes for NeXTStep to define HZ:
 */
//#ifdef NEXT
//#include <architecture/ARCH_INCLUDE.h>
//#import ARCH_INCLUDE(bsd/, param.h)
//#endif

//#if defined(PORTKEY_OS_UNIX) || defined(PORTKEY_OS_ULTRIX)
//#if PORT_INC_NEEDS_SYSTIME
//#include <sys/time.h>
//#include <sys/times.h>
//#endif
//#include <sys/param.h>
//#endif
//
//#ifdef sun
//#include <sys/resource.h>
//#endif

/*************************************************************************
 * Function: omfiMobIDNew()
 *
 *      This function can be used to create a new mob ID.  The mob ID
 *      consists of the company specific prefix specified when 
 *      omfsBeginSession() is called.  The major number is the time of day,
 *      and the minor number is the accumulated cpu cycles of the
 *      application.
 *
 *      This function supports both 1.x and 2.x files.
 *
 * Argument Notes:
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 *************************************************************************/

struct SMPTELabel
{
	aafUInt32	MobIDMajor;
	aafUInt32	MobIDMinor;
	aafUInt8	oid;
	aafUInt8	size;
	aafUInt8	ulcode;
	aafUInt8	SMPTE;
	aafUInt8	Registry;
	aafUInt8	unused;
	aafUInt16	MobIDPrefix;
};

union label
{
	aafUID_t			guid;
	struct SMPTELabel	smpte;
};

AAFRESULT aafMobIDNew(
        aafUID_t *mobID)     /* OUT - Newly created Mob ID */
{
	union label		aLabel;
	static aafUInt32 last_part2 = 0;		// Get rid of this!!!
//#ifdef sun
//	struct rusage rusage_struct;
//	int status;
//#endif
	aafTimeStamp_t	timestamp;
	
	aLabel.smpte.oid = 0x06;
	aLabel.smpte.size = 0x0E;
	aLabel.smpte.ulcode = 0x2B;
	aLabel.smpte.SMPTE = 0x34;
	aLabel.smpte.Registry = 0x02;
	aLabel.smpte.unused = 0;
	aLabel.smpte.MobIDPrefix = 42;		// Means its an OMF Uid

	AAFGetDateTime(&timestamp);
	aLabel.smpte.MobIDMajor = timestamp.TimeVal;
#if defined(_MAC) || defined(macintosh)
	aLabel.smpte.MobIDMinor = TickCount();
#else
#ifdef _WIN32
	aLabel.smpte.MobIDMinor = ((unsigned long)(time(NULL)*60/CLK_TCK));
#else 
//#if defined(sun)
//	status = getrusage(RUSAGE_SELF, &rusage_struct);
//
//	/* On the Sun, add system and user time */
//	label.smpte.MobIDMminor = rusage_struct.ru_utime.tv_sec*60 + 
//	      rusage_struct.ru_utime.tv_usec*60/1000000 +
//		  rusage_struct.ru_stime.tv_sec*60 +
//		  rusage_struct.ru_stime.tv_usec*60/1000000;
//#else
	{
	  static struct tms timebuf;
	  aLabel.smpte.MobIDMminor = ((unsigned long)(times(&timebuf)*60/HZ));
	}	
//#endif
#endif
#endif

	if (last_part2 >= aLabel.smpte.MobIDMinor)
	  aLabel.smpte.MobIDMinor = last_part2 + 1;
		
	last_part2 = aLabel.smpte.MobIDMinor;

	*mobID = aLabel.guid;
	return(OM_ERR_NONE);
}

#if 0	//!!! Add functions from the end of the file as needed 


/************************
 * Function: omfsSetProgressCallback
 *
 * 	Sets a callback which will be called at intervals
 *		during long operations, in order to allow your application
 *		to pin a watch cursor, move a thermometer, etc...
 *
 * Argument Notes:
 *
 *		The progress callback supplied by you should have the following
 *		prototype:
 *
 *			void ProgressProc(aafHdl_t file, aafInt32 curVal, aafInt32 endVal);
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
aafErr_t omfsSetProgressCallback(
			aafHdl_t				file,		/* IN - For this file */
			aafProgressProc_t aProc)	/* IN - Set this progress callback */
{
	aafAssertValidFHdl(file);
	file->progressProc = aProc;
	return(OM_ERR_NONE);
}

	/************************************************************
	 *
	 * Public functions used to extend the toolkit API
	 *
	 *************************************************************/





	/************************************************************
	 *
	 * Toolkit private functions
	 *
	 *************************************************************/



aafInt32 GetBentoID(
			aafHdl_t file,		/* IN -- For this aaf file */
			aafObject_t obj)	/* IN -- return objectID for this object */
{
	aafAssertValidFHdl(file);
	aafAssertIsAAF(file);
	aafAssert((obj != NULL), file, OM_ERR_NULLOBJECT);
}


/************************
 * Function: omfsInit	(INTERNAL)
 *
 * 		Called from BeginSession() to initialize static information
 *
 *		This function initializes read-only variables, and therefore contains a
 *		reference to the only write/read global.  Do not call this function or
 *		BeginSession() from a thread.
 *
 * Argument Notes:
 *		<none>
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard assertions.  See top of the file.
 */
aafErr_t omfsInit(
			void)
{
	if (!InitCalled)
	{
		omfsErrorInit();
	}
	InitCalled = TRUE;

	return (OM_ERR_NONE);
}

/************************
 * Function: clearBentoErrors	(INTERNAL)
 *
 * 		Internal function to reset error information at the start of a toolkit
 *		call to avoid passing back stale information.  Toolkit functions should
 *		immediately return on error without calling other functions to avoid clearing
 *		state.
 *
 * Argument Notes:
 *		See argument comments and assertions.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard assertions.  See top of the file.
 */
aafErr_t clearBentoErrors(
			aafHdl_t file)	/* IN -- For this aaf file */
{
	if (file != NULL)
	{
		if(file->cookie != FILE_COOKIE)
			return(OM_ERR_BAD_FHDL);
		
		file->BentoErrorNumber = 0;
		file->BentoErrorRaised = FALSE;
		if(file->session != NULL)
		{
			file->session->BentoErrorNumber = 0;
			file->session->BentoErrorRaised = FALSE;
		}
	}

	return (OM_ERR_NONE);
}



#ifdef VIRTUAL_BENTO_OBJECTS
/*------------------------------------------------------------------------------*
 | omfsPurgeObject - Flush the property & value data if it has not been touched |
 *------------------------------------------------------------------------------*
 
 If an object has not been touched, flush the property & value data.  If the object
 is accessed again, then this information will be reloaded from the file.  This
 function should be called when a program is REASONABLY sure that it will not need
 to access an object again.
*/

aafErr_t Purge(
			aafHdl_t				file,				/* IN -- For this aaf file */
			aafObject_t			anObject)		/* IN -- see if this object */
{
	OMLPurgeObjectVM((OMLObject)anObject);
	return(OM_ERR_NONE);
}
#endif
#endif

#if 0
AAFObject *AAFNewClassFromContainerObj(AAFFile *file, OMLObject obj)
{
	OMLProperty      cprop;
	OMLType          ctype;
	OMLValue			val;
	aafPosition_t	zero;
	aafLength_t		idSize;
	aafProperty_t 	idProp;
	aafType_t 		idType;
	aafClassID_t	objClass;
	OMContainer	*container;
	AAFHeader		*head;
		
	file->GetHeadObject(&head);
	CvtInt32toPosition(0, zero);
	CvtInt32toLength(4, idSize);
	{
		idProp = OMOOBJObjClass;
		idType = OMClassID;
	}

	cprop = head->CvtPropertyToBento(idProp);
	ctype = head->CvtTypeToBento(idType, NULL);
	container = file->GetContainer();
	
	val = container->OMLUseValue(obj, cprop, ctype);
//!!!	if (file->ContainerErrorRaised())
//!!!		RAISE(OM_ERR_BENTO_PROBLEM);

	(void)container->OMLReadValueData(val, (OMLPtr)objClass, zero, idSize);
	return(AAFNewClassFromClassID(file, objClass, obj));
}

AAFObject *AAFNewClassFromClassID(AAFFile *file, char *classID, OMLObject obj)
{
	AAFObject	*result;
	
/*	if(strncmp(classID, "AIFC",4) == 0)
		result = new AAFAIFCData(file, obj);
	else if(strncmp(classID, "AIFD",4) == 0)
		result = new AAFAIFCDescriptor(file, obj);
	else if(strncmp(classID, "CLSD",4) == 0)
		result = new AAFClassDictionary(file, obj);
	else if(strncmp(classID, "CDCI",4) == 0)
		result = new AAFCDCIDescriptor(file, obj);
	else */
	/* Skip abstract class CPNT */
#if FULL_TOOLKIT
	if(strncmp(classID, "CMOB",4) == 0)
		result = new AAFCompMob(file, obj);
	else if(strncmp(classID, "CVAL",4) == 0)
		result = new AAFConstValue(file, obj);
	else if(strncmp(classID, "CTLP",4) == 0)
		result = new AAFControlPoint(file, obj);
	else if(strncmp(classID, "DDEF",4) == 0)
		result = new AAFDataKind(file, obj);
	else
	/*if(strncmp(classID, "DIDD",4) == 0)
		result = new AAF(file, obj);
	else */
	if(strncmp(classID, "DOSL",4) == 0)
		result = new AAFDOSLocator(file, obj);
	else if(strncmp(classID, "ECCP",4) == 0)
		result = new AAFEdgecode(file, obj);
	/* Skip ERAT */
	else if(strncmp(classID, "EDEF",4) == 0)
		result = new AAFEffectDef(file, obj);
	else if(strncmp(classID, "EFFE",4) == 0)
		result = new AAFEffect(file, obj);
	else if(strncmp(classID, "ESLT",4) == 0)
		result = new AAFEffectSlot(file, obj);
	else if(strncmp(classID, "FILL",4) == 0)
		result = new AAFFiller(file, obj);
	/* Skip HEAD, IDAT, JPEG for the moment */
	/* Skip LOCR, as it's an abstract class */
	else if(strncmp(classID, "JPED",4) == 0)
		result = new AAFMediaFileDescriptor(file, obj);	//!!! Fix this!
	else if(strncmp(classID, "MACL",4) == 0)
		result = new AAFMacLocator(file, obj);
	else if(strncmp(classID, "MMOB",4) == 0)
		result = new AAFMasterMob(file, obj);
	/* Skip MDAT for the moment */
	/* Skip MDES, as it's an abstract class */
	else if(strncmp(classID, "MDFL",4) == 0)
		result = new AAFMediaFileDescriptor(file, obj);
	else if(strncmp(classID, "MDFM",4) == 0)
		result = new AAFMediaFilmDescriptor(file, obj);	//!!! Fix this!
	else if(strncmp(classID, "MGRP",4) == 0)
		result = new AAFMediaGroup(file, obj);
	else if(strncmp(classID, "MDTP",4) == 0)
		result = new AAFTapeDescriptor(file, obj);
	/* Skip MOBJ, as it's an abstract class */
	else if(strncmp(classID, "MSLT",4) == 0)
		result = new AAFMobSlot(file, obj);
	else if(strncmp(classID, "NEST",4) == 0)
		result = new AAFNestedScope(file, obj);
	/* Skip OOBJ, as it's an abstract class */
	/* Skip RGBA for the moment */
	else if(strncmp(classID, "PDWN",4) == 0)
		result = new AAFPulldown(file, obj);
	else if(strncmp(classID, "SREF",4) == 0)
		result = new AAFScopeRef(file, obj);
	else if(strncmp(classID, "SEGM",4) == 0)
		result = new AAFSegment(file, obj);
	else if(strncmp(classID, "SLCT",4) == 0)
		result = new AAFSelector(file, obj);
	else if(strncmp(classID, "SEQU",4) == 0)
		result = new AAFSequence(file, obj);
	else if(strncmp(classID, "SCLP",4) == 0)
		result = new AAFSourceClip(file, obj);
	else if(strncmp(classID, "SMOB",4) == 0)
	{
		AAFSourceMob		*tmp;
		AAFMediaDescriptor	*mdes;
		aafErr_t			aafError;
		aafClassID_t		objClass;
		
		tmp = new AAFSourceMob(file, obj);
		tmp->Load(file);
		tmp->GetMediaDescription(&mdes);
		mdes->Load(file);
		(void)mdes->ReadClassID(OMOOBJObjClass, objClass);
		if(mdes->IsTypeOf("MDFL", &aafError))
			result = new AAFFileMob(file, obj, objClass);
		else if(mdes->IsTypeOf("MDFM", &aafError))
			result = new AAFFilmMob(file, obj);
		else if(mdes->IsTypeOf("MDTP", &aafError))
			result = new AAFTapeMob(file, obj);
		else
			result = new AAFSourceMob(file, NULL, objClass, PT_NULL);
		delete tmp;
	}
	else if(strncmp(classID, "TXTL",4) == 0)
		result = new AAFTextLocator(file, obj);
	/* Skip TIFF, TIFD for the moment */
	else if(strncmp(classID, "TCCP",4) == 0)
		result = new AAFTimecode(file, obj);
	else if(strncmp(classID, "TRKD",4) == 0)
		result = new AAFTrackDescriptor(file, obj);
	else if(strncmp(classID, "TRAN",4) == 0)
		result = new AAFTransition(file, obj);
	else if(strncmp(classID, "UNXL",4) == 0)
		result = new AAFUnixLocator(file, obj);
	else if(strncmp(classID, "VVAL",4) == 0)
		result = new AAFVaryValue(file, obj);
	/* Skip WAVE, WAVD for the moment */
	else
#endif
		result = new AAFObject(file, obj);
		
	if(obj == NULL)
		result->CreatePersistant(file, classID);
		
	return(result);
}
#endif

typedef struct
	{
	aafUInt32	fpMinute;
	aafUInt32   fpHour;
	aafUInt32	dropFpMin;
	aafUInt32	dropFpMin10;
	aafUInt32	dropFpHour;
} frameTbl_t;

/*************************************************************************
 * Private Function: GetFrameInfo()
 *
 *      This function is used by omfsTimecodeToString().  It pulls
 *      apart a frame rate into elements in different units, and
 *      returns a structure containing these units.
 *
 * Argument Notes:
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 *************************************************************************/
static frameTbl_t GetFrameInfo(
							   aafInt32 fps) /* IN - Frame Rate */
{
	frameTbl_t	result;
	
	result.dropFpMin = (60 * fps) - 2;
	result.dropFpMin10 = (10*result.dropFpMin+2);
	result.dropFpHour = 6 * result.dropFpMin10;

	result.fpMinute = 60 * fps;
	result.fpHour = 60 * result.fpMinute;

	return(result);
}

/*************************************************************************
 * Private Function: PvtOffsetToTimecode()
 *
 *      Given an offset into a track and a frame rate, this function
 *      calculates a timecode value.
 *
 * Argument Notes:
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 *************************************************************************/
aafErr_t PvtOffsetToTimecode(
	aafFrameOffset_t offset, /* IN - Offset into a track */
	aafInt16 frameRate,      /* IN - Frame rate */
	aafDropType_t drop,     /* OUT - Drop or non-drop Timecode */
	aafInt16 *hours,         /* OUT - Hours value of timecode */
	aafInt16 *minutes,       /* OUT - Minutes value of timecode */
	aafInt16 *seconds,       /* OUT - Seconds value of timecode */
	aafInt16 *frames)        /* OUT - Frames value of timecode */
{
  frameTbl_t info;
  aafUInt32		frames_day;
  aafInt32 min10, min1;
  aafBool frame_dropped;

  info = GetFrameInfo(frameRate);
  frames_day = (drop ? info.dropFpHour: info.fpHour) *24;

  if (offset < 0L)
	 offset += frames_day;
  if (offset >= frames_day)
	 offset -= frames_day;
  if (drop)
	 {
		*hours = (aafInt16)(offset / info.dropFpHour);
		offset = offset % info.dropFpHour;
		min10 = offset / info.dropFpMin10;
		offset = offset % info.dropFpMin10;
		if (offset < info.fpMinute)
		  {
			 frame_dropped = AAFFalse;
			 min1 = 0;
		  }
		else
		  {
			 frame_dropped = AAFTrue;
			 offset -= info.fpMinute;
			 min1 = (offset / info.dropFpMin) + 1;
			 offset = offset % info.dropFpMin;
		  }
		
		*minutes = (aafInt16)((min10 * 10) + min1);
		*seconds = (aafInt16)(offset / frameRate);
		*frames = (aafInt16)(offset % frameRate);
		if (frame_dropped)
		  {
			 (*frames) +=2;
			 if (*frames >= frameRate)
				{
				  (*frames) -= frameRate;
				  (*seconds)++;
				  if (*seconds > 60)
					 {
						(*seconds) -= 60;
						(*minutes)++;
						if (*minutes > 60)
						  {
							 (*minutes) -= 60;
							 (*hours)++;
						  }
					 }
				}
		  }
	 }
  else
	 {
		*hours = (aafInt16)(offset / info.fpHour);
		offset = offset % info.fpHour;
		*minutes = (aafInt16)(offset / info.fpMinute);
		offset = offset % info.fpMinute;
		*seconds = (aafInt16)(offset / frameRate);
		*frames = (aafInt16)(offset % frameRate);
	 }

  return(OM_ERR_NONE);
}


/*************************************************************************
 * Function: PvtTimecodeToOffset()
 *
 *      Given a timecode and a frame rate, this function returns a
 *      position relative to the beginning of a track.
 *
 * Argument Notes:
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 *************************************************************************/
aafErr_t PvtTimecodeToOffset(
	aafInt16 frameRate,  /* IN - Frame Rate */
	aafInt16 hours,      /* IN - Hours value of Timecode */
	aafInt16 minutes,    /* IN - Minutes value of Timecode */
	aafInt16 seconds,    /* IN - Seconds value of Timecode */
	aafInt16 frames,     /* IN - Frames value of Timecode */
	aafDropType_t drop,  /* IN - Drop of non-drop Timecode */
	aafFrameOffset_t	*result) /* OUT - resulting position */

{
   aafUInt32		val;
	frameTbl_t	info;
	
	info = GetFrameInfo(frameRate);
	if(drop)
		{
		val = (hours * info.dropFpHour);
		val += ((minutes / 10) * info.dropFpMin10);
		val += (minutes % 10) * info.dropFpMin;
		}
	else
		{
		val = hours * info.fpHour;
		val += minutes * info.fpMinute;
		}

	val += seconds * frameRate;
	val += frames;
	
	*result = val;

	return(OM_ERR_NONE);
}
/*
;;; Local Variables: ***
;;; tab-width:3 ***
;;; End: ***
*/
