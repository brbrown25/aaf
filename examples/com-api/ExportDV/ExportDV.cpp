// @com Executable example program by Stuart Cunningham, BBC R&D
// @com This is based upon ComEssenceDataTest.cpp.

//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "AAFTypes.h"
#include "AAFResult.h"
#include "AAFDefUIDs.h"
#include "AAFDataDefs.h"
#include "AAFOperationDefs.h"
#include "AAFContainerDefs.h"
#include "AAFCodecDefs.h"
#include "AAFEssenceFormats.h"
#include "AAFFileKinds.h"
#include "AAFCompressionDefs.h"

// Include the AAF interface declarations.
#include "AAF.h"

// Include the AAF Stored Object identifiers. These symbols are defined in aaf.lib.
#include "AAFStoredObjectIDs.h"


typedef enum { NONE = 0, RawDV, RawUYVY, RawYUY2 } InputFormat;
InputFormat inpFormat = NONE;

// Use libdv API terminology for consistency with internal use of libdv API
// where "PAL" & "NTSC" mean 625/50 and 525/60 respectively
bool formatPAL = true;

const aafInt32 UNC_PAL_FRAME_SIZE = 720*576*2;
const aafInt32 UNC_NTSC_FRAME_SIZE = 720*480*2;
const aafInt32 DV_PAL_FRAME_SIZE = 144000;
const aafInt32 DV_NTSC_FRAME_SIZE = 120000;

bool useLegacyDV = false;
bool formatMXF = false;

#define aaf_assert(b, msg) \
	if (!(b)) {fprintf(stderr, "ASSERT: %s\n\n", msg); exit(1);}

static void LogError(HRESULT errcode, int line, char *file)
{
	printf("Error '%0x' returned at line %d in %s\n", errcode, line, file);
}

static HRESULT moduleErrorTmp = S_OK; /* note usage in macro */
#define check(a) \
{ moduleErrorTmp = a; \
	if (!SUCCEEDED(moduleErrorTmp)) \
	{ \
		LogError(moduleErrorTmp, __LINE__, __FILE__);\
		exit(1); \
	} \
}

#define checkFatal(a) \
{ moduleErrorTmp = a; \
	if (!SUCCEEDED(moduleErrorTmp)) \
		exit(1);\
}

static void convert(char* cName, size_t length, const wchar_t* name)
{
	aaf_assert((name && *name), "Valid input name");
	aaf_assert(cName != 0, "Valid output buffer");
	aaf_assert(length > 0, "Valid output buffer size");

	size_t status = wcstombs(cName, name, length);
	if (status == (size_t)-1) {
		fprintf(stderr, ": Error : Conversion failed.\n\n");
		exit(1);
	}
}

// Generate a video buffer containing uncompressed UYVY video representing
// the familiar colour bars test signal (or YUY2 video if specified).
static void create_colour_bars(unsigned char *video_buffer, bool convert_to_YUY2)
{
	int		i,j,b;
	int		UYVY_table[][5] = {
				{ 52, 0x80,0xEB,0x80,0xEB },	// white
				{ 140, 0x10,0xD2,0x92,0xD2 },	// yellow
				{ 228, 0xA5,0xA9,0x10,0xA9 },	// cyan
				{ 316, 0x35,0x90,0x22,0x90 },	// green
				{ 404, 0xCA,0x6A,0xDD,0x6A },	// magenta
				{ 492, 0x5A,0x51,0xF0,0x51 },	// red
				{ 580, 0xf0,0x29,0x6d,0x29 },	// blue
				{ 668, 0x80,0x10,0x80,0x10 },	// black
				{ 720, 0x80,0xEB,0x80,0xEB },	// white
			};

	for (j = 0; j < 576; j++)
	{
		for (i = 0; i < 720*2; i+=4)
		{
			for (b = 0; b < 9; b++)
			{
				if (i < UYVY_table[b][0] * 2)
				{
					video_buffer[j*720*2 + i + 0] = UYVY_table[b][1];
					video_buffer[j*720*2 + i + 1] = UYVY_table[b][2];
					video_buffer[j*720*2 + i + 2] = UYVY_table[b][3];
					video_buffer[j*720*2 + i + 3] = UYVY_table[b][4];
					break;
				}
			}
		}
	}

	if (convert_to_YUY2)
	{
		// Convert from UYVY -> YUY2
		for (i = 0; i < 720 * 576 * 2; i+=2)
		{
			unsigned char tmp = video_buffer[i+1];
			video_buffer[i+1] = video_buffer[i];
			video_buffer[i] = tmp;
		}
	}
}

const aafUID_t NIL_UID = { 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };

static char *input_video = NULL;
static FILE *input;

static HRESULT CreateAAFFile(aafWChar * pFileName, bool comp_enable)
{
	IAAFFile*					pFile = NULL;
	IAAFHeader*					pHeader = NULL;
	IAAFDictionary*				pDictionary = NULL;
	IAAFMob*					pMob = NULL;
	IAAFMasterMob*				pMasterMob = NULL;
	IAAFEssenceAccess*			pEssenceAccess = NULL;
	aafMobID_t					masterMobID;
	aafProductIdentification_t	ProductInfo;
	aafRational_t				editRate = {25, 1};
	aafRational_t				sampleRate = {25, 1};
	aafRational_t				ntsc_rate = {30000, 1001};
	IAAFClassDef				*pCDMasterMob = NULL;
	IAAFDataDef					*pPictureDef = NULL;
	aafUInt32					samplesWritten, bytesWritten;
	aafInt32					frameSize;

	// Delete any previous test file before continuing...
	char cFileName[FILENAME_MAX];
	convert(cFileName, sizeof(cFileName), pFileName);
	remove(cFileName);

	cout << "Creating file " << cFileName << " using WriteSamples with " <<
		(comp_enable ? "CompressionEnable" : "CompressionDisable") << endl;

	aafProductVersion_t ver = {1, 0, 0, 0, kAAFVersionBeta};
	ProductInfo.companyName = L"none";
	ProductInfo.productName = L"AAF SDK";
	ProductInfo.productVersion = &ver;
	ProductInfo.productVersionString = L"1.0.0.0 Beta";
	ProductInfo.productID = NIL_UID;
	ProductInfo.platform = NULL;		// Set by SDK when saving

	// Large sectors for new files, small sectors for legacy files
	const aafUID_t *fileKind = useLegacyDV ? &kAAFFileKind_Aaf512Binary : &kAAFFileKind_Aaf4KBinary;

	if (formatMXF)
	  fileKind = &aafFileKindMxfKlvBinary;

	// Create a new AAF file
	check(AAFFileOpenNewModifyEx(pFileName, fileKind, 0, &ProductInfo, &pFile));
	check(pFile->GetHeader(&pHeader));

	if (formatMXF)
	{
	  aafUID_t kAAFOpDef_Atom = { 0x0d010201, 0x1000, 0x0000, { 0x06, 0x0e, 0x2b, 0x34, 0x04, 0x01, 0x01, 0x01}};

	  IAAFHeader2* pHeader2 = 0;
	  check(pHeader->QueryInterface(IID_IAAFHeader2, (void **)&pHeader2));
	  check(pHeader2->SetOperationalPattern(kAAFOpDef_Atom));
	  pHeader2->Release();
	}

	// Get the AAF Dictionary from the file
	check(pHeader->GetDictionary(&pDictionary));

	/* Lookup class definitions for the objects we want to create. */
	check(pDictionary->LookupClassDef(AUID_AAFMasterMob, &pCDMasterMob));

	/* Lookup any necessary data definitions. */
	check(pDictionary->LookupDataDef(kAAFDataDef_Picture, &pPictureDef));

	/* Create a Mastermob */

	// Get a Master MOB Interface
	check(pCDMasterMob->CreateInstance(IID_IAAFMasterMob, (IUnknown **)&pMasterMob));

	// Get a Mob interface and set its variables.
	check(pMasterMob->QueryInterface(IID_IAAFMob, (void **)&pMob));
	check(pMob->GetMobID(&masterMobID));
	if (input_video == NULL)
	{
		check(pMob->SetName(L"colour_bars"));
	}
	else
	{
		check(pMob->SetName(pFileName));
	}

	// Add Mobs to the Header
	check(pHeader->AddMob(pMob));

	// Create a frame of colour bars
	// experiment shows 4 bytes per pixel needed to avoid SMALLBUF using WriteSamples
	// with kAAFMixedFields and 720x576
	// 2 bytes per pixel work fine with kAAFSeparateFields and 720x288
	unsigned char video_buf[UNC_PAL_FRAME_SIZE];
	if (input_video == NULL)
	{
		create_colour_bars(video_buf, true);
	}

	// Get a pointer to video data for WriteSamples
	unsigned char *dataPtr;
	dataPtr = video_buf;

	if (! formatPAL)	// set NTSC rates if using NTSC video
	{
		editRate = ntsc_rate;
		sampleRate = ntsc_rate;
	}


	/* Create the Essence Data specifying the codec, container, edit rate and sample rate */
	check(pMasterMob->CreateEssence(1,			// Slot ID within MasterMob
						pPictureDef,			// MediaKind
						kAAFCodecCDCI,			// codecID
						editRate,				// edit rate
						sampleRate,				// sample rate
						comp_enable ? kAAFCompressionEnable : kAAFCompressionDisable,
						NULL,					// No Locator used
						ContainerAAF,			// Essence embedded in AAF file
						&pEssenceAccess));		//

	// Set the codec flavour for desired video format
	if (formatPAL)
	{
		if (useLegacyDV)
			pEssenceAccess->SetEssenceCodecFlavour( kAAFCodecFlavour_LegacyDV_625_50 );
		else
			pEssenceAccess->SetEssenceCodecFlavour( kAAFCodecFlavour_IEC_DV_625_50 );

		frameSize = (comp_enable ? UNC_PAL_FRAME_SIZE : DV_PAL_FRAME_SIZE);
	}
	else	// format is NTSC
	{
		if (useLegacyDV)
			pEssenceAccess->SetEssenceCodecFlavour( kAAFCodecFlavour_LegacyDV_525_60 );
		else
			pEssenceAccess->SetEssenceCodecFlavour( kAAFCodecFlavour_IEC_DV_525_60 );

		frameSize = (comp_enable ? UNC_NTSC_FRAME_SIZE : DV_NTSC_FRAME_SIZE);
	}

	// For fun, print the name of the selected codec flavour
	aafWChar codec_name[128] = L"";
	check(pEssenceAccess->GetCodecName(sizeof(codec_name), codec_name));
	printf("  using codec flavour \"%ls\"\n", codec_name);


	// Write the video samples
	int total_samples = 0;
	if (input_video == NULL)		// using generated uncompressed video?
	{
		for (int i = 0; i < 10; i++)	// 10 frames will do
		{
			check(pEssenceAccess->WriteSamples(	1,					//
												sizeof(video_buf),	// buffer size
												dataPtr,			// pointer to video frame
												&samplesWritten,
												&bytesWritten));
			total_samples += samplesWritten;
		}
	}
	else
	{
		while (1)
		{
			if ( fread(video_buf, frameSize, 1, input) != 1 )
			{
				if (feof(input))
					break;
				perror(input_video);
				fprintf(stderr, "Probably incomplete last frame in input file\n");
				break;
			}

			if (inpFormat == RawUYVY)
			{
				// Convert from UYVY -> YUY2
				for (int i = 0; i < frameSize; i+=2)
				{
					unsigned char tmp = video_buf[i+1];
					video_buf[i+1] = video_buf[i];
					video_buf[i] = tmp;
				}
			}

			check(pEssenceAccess->WriteSamples(
									1,					// number of samples
									frameSize,			// buffer size
									dataPtr,			// samples buffer
									&samplesWritten,
									&bytesWritten));
			total_samples += samplesWritten;
		}
	}
	printf("Wrote %d samples\n", total_samples);

	/* Set the essence to indicate that you have finished writing the samples */
	check(pEssenceAccess->CompleteWrite());

	pEssenceAccess->Release();

	pMob->Release();
	pMasterMob->Release();

	pPictureDef->Release();
	pCDMasterMob->Release();

	pDictionary->Release();
	pHeader->Release();

	/* Save the AAF file */
	pFile->Save();

	/* Close the AAF file */
	pFile->Close();
	pFile->Release();

	return moduleErrorTmp;
}

// simple helper class to initialize and cleanup AAF library.
struct CAAFInitialize
{
	CAAFInitialize(const char *dllname = NULL)
	{
		HRESULT hr = AAFLoad(dllname);
		if (!AAFRESULT_SUCCEEDED(hr)) {
			fprintf(stderr, "Error : Failed to load the AAF library, ");
			fprintf(stderr, "check environment variables -\n");
			fprintf(stderr, "	Windows		- $PATH\n");
			fprintf(stderr, "	Unix/Linux	- $LD_LIBRARY_PATH\n");
			exit(hr);
		}
	}

	~CAAFInitialize()
	{
		AAFUnload();
	}
};


// Make sure all of our required plugins have been registered.
static HRESULT RegisterRequiredPlugins(void)
{
	IAAFPluginManager	*mgr = NULL;

	// Load the plugin manager
	check(AAFGetPluginManager(&mgr));

	// Attempt load and register all of the plugins
	// in the shared plugin directory.
	check(mgr->RegisterSharedPlugins());

	if (mgr)
		mgr->Release();

	return moduleErrorTmp;
}

void printUsage(const char *progname)
{
	cout << "Usage : " << progname << " [-legacyDV] [-ntsc] [-rawDV|-rawYUY2|-rawUYVY input_filename]" << endl;
	cout << endl;
	cout << "\tWith no arguments creates ExportDV.aaf containing 10 DV frames" << endl;
	cout << endl;
	cout << "\t-legacyDV use the legacy Compression ID and 6 extended properties found in legacy software" << endl;
	cout << "\t-ntsc     treat input as 525 lines 60Hz video instead of default 626 lines 50Hz" << endl;
	cout << "\t-rawDV    input video is compressed DV frames (raw DV)" << endl;
	cout << "\t-rawYUY2  input video is uncompressed YUY2" << endl;
	cout << "\t-rawUYVY  input video is uncompressed UYVY" << endl;
}

extern int main(int argc, char *argv[])
{
	CAAFInitialize aafInit;

	aafWChar *		pwFileName	= L"ExportDV.aaf";
	bool			compressionEnable = true;		// convert from uncomp to DV by default

	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
			{
				printUsage(argv[0]);
				return 0;
			}
			else if (!strcmp(argv[i], "-ntsc"))
			{
				formatPAL = false;
				i++;
			}
			else if (!strcmp(argv[i], "-legacyDV"))
			{
				useLegacyDV = true;
				i++;
			}
			else if (!strcmp(argv[i], "-rawDV"))
			{
				if (inpFormat)
				{
					printUsage(argv[0]);
					return 1;
				}
				compressionEnable = false;
				inpFormat = RawYUY2;
				i++;
			}
			else if (!strcmp(argv[i], "-rawYUY2"))
			{
				if (inpFormat)
				{
					printUsage(argv[0]);
					return 1;
				}
				inpFormat = RawYUY2;
				i++;
			}
			else if (!strcmp(argv[i], "-rawUYVY"))
			{
				if (inpFormat)
				{
					printUsage(argv[0]);
					return 1;
				}
				inpFormat = RawUYVY;
				i++;
			}
			else if (!strcmp(argv[i], "-mxf"))
			{
			  formatMXF = true;
			  i++;
			}
			else
			{
				break;
			}
		}
	}

	if (i < argc)
	{
		input_video = argv[i];		// source of uncompressed video

		if (inpFormat == NONE)
		{
			cout << "Input format not specified" << endl;
			printUsage(argv[0]);
			return 1;
		}
		if ( (input = fopen(input_video, "rb")) == NULL)
		{
			perror(input_video);
			return 1;
		}
	}
	else
	{
		if (inpFormat != NONE)		// provided format but no filename
		{
			cout << "Input file not specified" << endl;
			printUsage(argv[0]);
			return 1;
		}
	}

	// Make sure all of our required plugins have been registered.
	checkFatal(RegisterRequiredPlugins());

	checkFatal(CreateAAFFile(pwFileName, compressionEnable));

	printf("DONE\n");

	return(0);
}
