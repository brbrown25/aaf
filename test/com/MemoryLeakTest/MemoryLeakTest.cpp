//=---------------------------------------------------------------------=
//
// $Id: MemoryLeakTest.cpp,v 1.1 2008/06/13 08:06:19 stuart_hc Exp $ $Name:  $
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
#include <stdlib.h>

#include "AAF.h"
#include "AAFResult.h"


void printUsage(const char *progname)
{
	printf("Usage: %s aaffile\n\n", progname);
}

extern int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printUsage(argv[0]);
		return 1;
	}

	aafWChar Filename[FILENAME_MAX];
	size_t status = mbstowcs(Filename, argv[1], sizeof(Filename));
	if (status == (size_t)-1) {
		fprintf(stderr, "mbstowcs failed for \"%s\"\n", argv[1]);
		return 1;
	}

	IAAFFile *pFile = NULL;
	int mode = 0;
	HRESULT res_open;

	// Perform the simplest possible use of the AAF SDK to open an
	// existing AAF file. This is enough to cause a memory leak in
	// AAF SDK v1.1.2 and up to at least CVS snapshot 2008-05-12.

	res_open = AAFFileOpenExistingRead(Filename, mode, &pFile);
	if (AAFRESULT_FAILED(res_open))
	{
		aafCharacter buf[100] = L"";
		AAFResultToText(res_open, buf, sizeof(buf));
		fprintf(stderr, "AAFFileOpenExistingRead() failed, result=0x%08x %ls\n", res_open, buf);
		return 1;
	}

	pFile->Close();
	pFile->Release();

	return 0;
}
