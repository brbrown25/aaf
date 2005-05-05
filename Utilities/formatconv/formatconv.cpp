//=---------------------------------------------------------------------=
//
// $Id: formatconv.cpp,v 1.1.2.1 2005/05/05 09:04:43 philipn Exp $ $Name:  $
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
// Licensor of the AAF Association is British Broadcasting Corporation.
// All rights reserved.
//
//=---------------------------------------------------------------------=


#include <AAF.h>
#include <AAFTypes.h>
#include <AAFResult.h>
#include <AAFFileKinds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void FatalErrorCode(HRESULT errcode, int line, char *file)
{
    fprintf(stderr, "\nError '%0x' returned at line %d in %s\n", errcode, line, file);
    exit(1);
}

static HRESULT check_hr = S_OK;
#define check(a)  \
{ \
    check_hr = a; \
    if (!SUCCEEDED(check_hr)) \
    { \
        FatalErrorCode(check_hr, __LINE__, __FILE__); \
    } \
}

struct CAAFInitialize
{
    CAAFInitialize(const char *dllname = NULL)
    {
        HRESULT hr = AAFLoad(dllname);
        if (!AAFRESULT_SUCCEEDED(hr))
        {
            fprintf(stderr, "Error : Failed to load the AAF library, ");
            fprintf(stderr, "check environment variables -\n");
            fprintf(stderr, "  Windows    - $PATH\n");
            fprintf(stderr, "  Unix/Linux - $LD_LIBRARY_PATH\n");
            exit(hr);
        }
    }

    ~CAAFInitialize()
    {
        AAFUnload();
    }
};


static void Usage(int argc, char *argv[])
{
    fprintf(stderr, "%s [-xml | -ss] <in filename> <out filename>\n", argv[0]);
}

int main(int argc, char *argv[])
{
    if (argc != 4 ||
            (strcmp(argv[1], "-xml") != 0 && strcmp(argv[1], "-ss") != 0))
    {
        Usage(argc, argv);
        exit(1);
    }


    aafCharacter *inFileName = new aafCharacter[strlen(argv[2]) + 1];
    aafCharacter *outFileName = new aafCharacter[strlen(argv[3]) + 1];

    size_t status = mbstowcs(inFileName, argv[2], strlen(argv[2]));
    if (status == (size_t)-1)
    {
        fprintf(stderr, "\nError: Failed to convert filename '%s' to a wide string.", argv[2]);
        exit(1);
    }
    status = mbstowcs(outFileName, argv[3], strlen(argv[3]));
    if (status == (size_t)-1)
    {
        fprintf(stderr, "\nError: Failed to convert filename '%s' to a wide string.", argv[3]);
        exit(1);
    }
    inFileName[strlen(argv[2])] = 0;
    outFileName[strlen(argv[3])] = 0;

    // remove the output file if it already exists
    remove(argv[3]);

    
    CAAFInitialize aafInit;
    IAAFFile* inFile = 0;
    IAAFFile* outFile = 0;

    check(AAFFileOpenExistingRead(inFileName, 0, &inFile));

    aafProductVersion_t v;
    v.major = 0;
    v.minor = 1;
    v.tertiary = 0;
    v.patchLevel = 0;
    v.type = kAAFVersionUnknown;

    const aafUID_t productUID = 
        {0x97e04c67, 0xdbe6, 0x4d11, {0xbc, 0xd7, 0x3a, 0x90, 0x42, 0x53, 0xa2, 0xef}};
    aafProductIdentification_t  productInfo;
    productInfo.companyName = L"AAF Association";
    productInfo.productName = L"AAF Format Converter";
    productInfo.productVersion = &v;
    productInfo.productVersionString = 0;
    productInfo.productID = productUID;
    productInfo.platform = 0;

    // create output file based on choice of stored format
    if (strcmp(argv[1], "-xml") == 0)
    {
        check(AAFFileOpenNewModifyEx(outFileName, &kAAFFileKind_AafXmlTextPrototype, 0, &productInfo, &outFile));
    }
    else
    {
        check(AAFFileOpenNewModify(outFileName, 0, &productInfo, &outFile));
    }

    // save copy using the selected stored format
    check(inFile->SaveCopyAs(outFile));
    
    check(outFile->Close());
    check(inFile->Close());

    outFile->Release();
    outFile = 0;
    inFile->Release();
    inFile = 0;

    delete [] inFileName;
    delete [] outFileName;

    return 0;
}

