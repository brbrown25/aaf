/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/


//
// Use include guard so that the file can be included in every 
// platform build without causing any errors in the build.
//
#if defined(macintosh) || defined(_MAC)

// Declare the public interface that must be implemented.

#include "aafrdli.h"



#include "AAFResult.h"

#include <Files.h>
#include <Folders.h>
#include <Resources.h>
#include <CodeFragments.h>
#include <MacMemory.h>
#include <Errors.h>

#include <stdio.h>
#include <stdlib.h>


// Try current archtecture (ppc?)
#define AAF_FRAGARCHITECTURE kCompiledCFragArch
// Try to load an existing one and update the reference count
#define AAF_FRAGLOADOPTIONS kPrivateCFragCopy //kReferenceCFrag




AAFRDLIRESULT AAFLoadLibrary(const char* name, AAFLibraryHandle* pLibHandle)
{
  AAFRDLIRESULT result = AAFRESULT_SUCCESS;
  char * dirSeparator = NULL;
 
  if (NULL == name || NULL == pLibHandle)
    return AAFRESULT_NULL_PARAM;
  
  dirSeparator = strchr(name, ':');
  if (NULL == dirSeparator)
    return AAFLoadSharedLibrary(name, pLibHandle);
  else
    return AAFLoadLibraryFile(name, pLibHandle);
}

AAFRDLIRESULT AAFUnloadLibrary(AAFLibraryHandle libHandle)
{
  AAFRDLIRESULT result = AAFRESULT_SUCCESS;
  CFragConnectionID connectionID = (CFragConnectionID)libHandle;
  
  if (0 == connectionID)
    return AAFRESULT_NULL_PARAM;
    
  result = CloseConnection(&connectionID);  

  return result;
}

AAFRDLIRESULT AAFFindSymbol(AAFLibraryHandle libHandle, const char* symbolName, AAFSymbolAddr* pSymbol)
{
  AAFRDLIRESULT result = AAFRESULT_SUCCESS;
  Str63 PSymbolName;
  Ptr theSymbol = NULL;
  CFragSymbolClass  symClass;

  
  if (NULL == libHandle || NULL == symbolName || NULL == pSymbol || (NULL != symbolName && 63 < strlen(symbolName)) )
    return AAFRESULT_NULL_PARAM;

  // Copy and convert the c null terminated string to a Str63.
  strncpy((char *)PSymbolName, symbolName, sizeof(Str63));
  PSymbolName[sizeof(Str63) - 1] = 0; // force null termination
  c2pstr((char *)PSymbolName);

  result = FindSymbol((CFragConnectionID)libHandle, PSymbolName, &theSymbol, &symClass);
  if (noErr == result)
    *pSymbol = (AAFSymbolAddr)theSymbol;

  
  return result;
}

// Handy routine so that we only have to do this one a once.
inline bool AAFCInfoIsDirectory(CInfoPBRec& cInfo)
{
  return 0 != ((1 << ioDirFlg) & cInfo.dirInfo.ioFlAttrib);
}

/* Limited set of platform independent directory searching functions.*/
AAFRDLIRESULT AAFFindLibrary(const char* name, LPFNAAFTESTFILEPROC testProc, void *userData)
{
  AAFRDLIRESULT rc = AAFRESULT_SUCCESS;
 
  if (NULL == name || NULL == testProc)
    return AAFRESULT_NULL_PARAM;

  int nameLength = strlen(name);

  if (0 == nameLength)
  {
    // Default implementation will just continue to use a hard-coded list of shared libaries.
    const char *pluginFileNames[] = 
    {
      "AAFPGAPI.DLL (PPC)",
      "AAFINTP.DLL (PPC)",
      NULL
    };

    if (NULL == name || NULL == testProc)
      return AAFRESULT_NULL_PARAM;

    for (int i = 0; AAFRESULT_SUCCESS == rc && pluginFileNames[i]; ++i)
      rc = testProc(pluginFileNames[i], false /* not a directory */, userData);
  }
  else
  {
    FSSpec fileSpec;
  
    rc = AAFPathToFSSpec(name, &fileSpec);
    if (noErr != rc)
      return rc;

    // Check to see if the given fileSpec points to a file or directory.
    CInfoPBRec cInfo;
    
    memset(&cInfo, 0, sizeof(cInfo));
    cInfo.dirInfo.ioVRefNum = fileSpec.vRefNum;
    cInfo.dirInfo.ioDrDirID = fileSpec.parID;
    cInfo.dirInfo.ioNamePtr = fileSpec.name;
      
    rc = PBGetCatInfoSync(&cInfo);
    if (noErr != rc)
      return rc;
        
    // If it is a file then fail.
    bool isDirectory = AAFCInfoIsDirectory(cInfo);
    if (!isDirectory)
      return AAFRESULT_INVALID_PARAM;
      
    // Allocate the smallest buffer possible.
    int nameLen = strlen(name);
    char *path = new char[nameLen + 1 + sizeof(StrFileName)];
    if (NULL == path)
      return AAFRESULT_NOMEMORY;
    strcpy(path, name);
    if (':' != path[nameLen - 1])
    {
      path[nameLen++] = ':';
      path[nameLen] = 0;
    }
    
    // Save our directory id.
    long dirID = cInfo.dirInfo.ioDrDirID;

    // Walk through the files and folders in the given folder.
    memset(&cInfo, 0, sizeof(cInfo));
    StrFileName fileName;
    int index = 1;
    cInfo.dirInfo.ioNamePtr = fileName;
    cInfo.dirInfo.ioFDirIndex = index; 
    cInfo.dirInfo.ioDrDirID = dirID; // restore directory id found above.
    cInfo.dirInfo.ioACUser = 0;
    rc = PBGetCatInfoSync(&cInfo);
    
    while (noErr == rc)
    {
      // Build the full path name.
      memcpy(&path[nameLen], &fileName[1], (int)fileName[0]);
      path[nameLen + (int)fileName[0]] = 0;
    
      isDirectory = AAFCInfoIsDirectory(cInfo);
      
      if (isDirectory)
      {
        rc = testProc(path, isDirectory, userData);
      }
      else if (kCFragLibraryFileType == cInfo.hFileInfo.ioFlFndrInfo.fdType)
      {
        rc = testProc(path, isDirectory, userData);
      }
      
      if (noErr != rc)
        break;
      
      ++index;
      
      cInfo.dirInfo.ioDrDirID = dirID; // restore directory id found above.
      cInfo.hFileInfo.ioFDirIndex = index; 
      cInfo.hFileInfo.ioACUser = 0;
      rc = PBGetCatInfoSync(&cInfo);
    }
    
    delete [] path;
    path = NULL;
    
    if (fnfErr == rc)
      rc = noErr;    
  }
  

  return rc;
}


// Given just a file name this routine will use GetSharedLibrary() to load the code fragment.
AAFRDLIRESULT AAFLoadSharedLibrary(const char* name, AAFLibraryHandle* pLibHandle)
{
  AAFRDLIRESULT result = AAFRESULT_SUCCESS;
  HRESULT hr = CO_E_DLLNOTFOUND; // the default error code
  OSErr             err = noErr;
  CFragArchitecture archType = AAF_FRAGARCHITECTURE;
  CFragLoadOptions  loadFlags = AAF_FRAGLOADOPTIONS;
  Ptr               mainAddr = NULL;
  char              errMessage[256];
  StringPtr         psymName = NULL;
  Ptr               symAddr = NULL;
  Str63             libName;
  CFragConnectionID connectionID = 0;

 
  if (NULL == name || NULL == pLibHandle)
    return AAFRESULT_NULL_PARAM;
  
  
  // Copy and convert the c null terminated string to a Str63.
  if (63 < strlen(name))
    return AAFRESULT_INVALID_PARAM;
    
  strncpy((char *)libName, name, sizeof(Str63));
  libName[sizeof(Str63) - 1] = 0; // force null termination
  c2pstr((char *)libName);
  
  // Attempt to load the library.
  err = GetSharedLibrary(libName, archType, loadFlags, &connectionID, &mainAddr, (unsigned char *)errMessage);
  if (noErr != err)
  {
    result = err;
#ifdef _DEBUG
    p2cstr((unsigned char *)errMessage);
    fprintf(stderr, "\nGetSharedLibrary(\"%s\"...); \n\tfailed with an error code = %d and errMessage:\"%s\"\n", name, hr, errMessage);
    fflush(stderr);
#endif
  }
  else
  { // Library successfully loaded:
    *pLibHandle = (AAFLibraryHandle *)connectionID;
  }
 
  return result;
}


// Given a full path to a file this routine will use the file's cfrg resource to load
// the code fragment.
AAFRDLIRESULT AAFLoadLibraryFile(const char* name, AAFLibraryHandle* pLibHandle)
{
  AAFRDLIRESULT     result = CO_E_DLLNOTFOUND;
  FSSpec            libSpec;

 
  if (NULL == name || NULL == pLibHandle)
    return AAFRESULT_NULL_PARAM;
  
  // First resolve the given path name into an appropriate file spec.
  result = AAFPathToFSSpec(name, &libSpec);
  if (noErr == result)
  {
    result = AAFFSpLoadLibraryFile(&libSpec, pLibHandle);
  }


  

  return result;
}

// Same as above except that it attempts to load the library from a mac file spec.
AAFRDLIRESULT AAFFSpLoadLibraryFile(FSSpec *pSpec, AAFLibraryHandle* pLibHandle)
{
  AAFRDLIRESULT result = noErr;
  OSErr             err = noErr;
  CFragArchitecture archType = AAF_FRAGARCHITECTURE;
  CFragLoadOptions  loadFlags = AAF_FRAGLOADOPTIONS;
  Ptr               mainAddr = NULL;
  char              errMessage[256];
  CFragConnectionID connectionID = 0;

 
  if (NULL == pSpec || NULL == pLibHandle)
    return AAFRESULT_NULL_PARAM;

  short currentResFile = CurResFile();
  short resRefNum = -1;

  resRefNum = FSpOpenResFile(pSpec, fsRdPerm);
  if (-1 != resRefNum)
  {
    // Attempt to load the 'cfrg' resource so that we can properly load
    // our fragment.
    Handle cfrgHandle = Get1Resource(kCFragResourceType, kCFragResourceID);
    if (NULL != cfrgHandle)
    {
      HLock(cfrgHandle);
      if (noErr == (result = MemError()))
      {
        UInt16 index;
        CFragResourcePtr cfrgPtr = (CFragResourcePtr)(*cfrgHandle);
        UInt16 memberCount = cfrgPtr->memberCount;
        CFragResourceMemberPtr cfrgMemberPtr = &cfrgPtr->firstMember;
        
        // Default result if no fragment is found
        result = cfragNoSectionErr;

        for (index = 0; (index < memberCount) && (0 == connectionID); ++index)
        {
          if (archType == cfrgMemberPtr->architecture)
          {
            switch (cfrgMemberPtr->where)
            {
              case kDataForkCFragLocator:      /* Container is in a file's data fork.*/
              {
                result = GetDiskFragment(pSpec, 
                                         cfrgMemberPtr->offset, 
                                         cfrgMemberPtr->length, 
                                         cfrgMemberPtr->name, 
                                         loadFlags, 
                                         &connectionID, 
                                         &mainAddr, 
                                         (unsigned char *)errMessage);
                if (noErr != result)
                {
  #ifdef _DEBUG
                  StrFileName errName;
                  memcpy(errName, &pSpec->name[1], pSpec->name[0]);
                  errName[pSpec->name[0]] = 0;
                  p2cstr((unsigned char *)errMessage);
                  fprintf(stderr, "\nGetDiskFragment(\"%s\"...); \n\tfailed with an error code = %d and errMessage:\"%s\"\n", errName, result, errMessage);
                  fflush(stderr);
  #endif
                }
                break;
              }
              
              case kMemoryCFragLocator:        /* Container is already addressable.*/
              case kResourceCFragLocator:      /* Container is in a file's resource fork.*/
              case kByteStreamCFragLocator:    /* ! Reserved for possible future use!*/
              case kNamedFragmentCFragLocator: /* ! Reserved for possible future use!*/
                break;
            }
          }
          
          // Get the pointer to the next member (skip over any extensions)
          cfrgMemberPtr = NextCFragResourceMemberPtr(cfrgMemberPtr);
        } 
        
        HUnlock(cfrgHandle);
      }
      
      ReleaseResource(cfrgHandle);
      cfrgHandle = NULL;  
    }
    else
    {
      result = ResError(); // no cfrg resource
      if (noErr == result) // very old "bug" in resource manager.
        result = resNotFound;
    }
    
    CloseResFile(resRefNum);
  }
  else
  {
    result = ResError(); // OpenResFile failed!
    if (noErr == result) // very old "bug" in resource manager.
      result = resFNotFound;
  }

  // Restore the current Res file.
  UseResFile(currentResFile);


  if (noErr == result)
  { // Library successfully loaded:
    *pLibHandle = (AAFLibraryHandle *)connectionID;
  }

  return result;
}

// Given a pathname return the corresponding file spec.
AAFRDLIRESULT AAFPathToFSSpec(const char* name, FSSpec *pSpec)
{
  OSErr err = noErr;
  
  if (NULL == name || NULL == pSpec)
    return AAFRESULT_NULL_PARAM;

  AliasHandle alias = NULL;
  int nameLen = strlen(name);
  err = NewAliasMinimalFromFullPath(nameLen, name, NULL, NULL, &alias);
  if (noErr == err)
  {
    FSSpec foundSpec[1];
    short specCount = sizeof(foundSpec) / sizeof(FSSpec);
    short aliasCount = specCount;
    unsigned long rulesMask = kARMNoUI | kARMMultVols | kARMSearch;
    Boolean needsUpdate = false;
   
    memset(foundSpec, 0, sizeof(foundSpec));
    err = MatchAlias(NULL, rulesMask, alias, &aliasCount, foundSpec, &needsUpdate, NULL, NULL);
    if (noErr == err)
    {
      *pSpec = foundSpec[0];
    }
    
    DisposeHandle((Handle)alias);
    alias = NULL;  
  }

  
  return err;
}

// Copy the given data reversed. Warning: src and dst must NOT overlap!
static void copy_rev(char *dst, const char *src, size_t count)
{
  size_t i;
  
  for (i = 0; i < count; ++i)
    dst[i] = src[count - 1 - i];
}

static void rev_mem(char *buffer, size_t count)
{
  size_t i, j;
  char tmp;
  
  for (i = 0, j = count - 1; i < j; ++i, --j)
  {
    tmp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = tmp;
  }
}


// Given a pathname return the corresponding file spec.
AAFRDLIRESULT AAFFSSpecToPath(const FSSpec *pSpec, char *pathBuffer, int pathBufferSize)
{
  OSErr err = noErr;
  CInfoPBRec cInfo;
  StrFileName folderName;
  int currentLen = 0;
  
  if (NULL == pSpec || NULL == pathBuffer)
    return AAFRESULT_NULL_PARAM;
  else if (0 >= pathBufferSize)
    return AAFRESULT_INVALID_PARAM;
    
  // Copy the spec name into the buffer.
  if (pathBufferSize < pSpec->name[0])
    return AAFRESULT_SMALLBUF;

  // First check to see if it is a file or a directory.
  // If it is a directory then we need to add the ":".
  memset(&cInfo, 0, sizeof(cInfo));
  cInfo.dirInfo.ioVRefNum = pSpec->vRefNum;
  cInfo.dirInfo.ioDrDirID = pSpec->parID;
  cInfo.dirInfo.ioNamePtr = const_cast<unsigned char*>(pSpec->name);
  
  err = PBGetCatInfoSync(&cInfo);
  if (noErr != err)
    return err;
  if (AAFCInfoIsDirectory(cInfo))
    pathBuffer[currentLen++] = ':';
  
  // Copy the file/folder name into the buffer.  
  copy_rev(&pathBuffer[currentLen], (const char *)&pSpec->name[1], (size_t)pSpec->name[0]);
  currentLen += pSpec->name[0];
  pathBuffer[currentLen] = 0;
  
  memset(&cInfo, 0, sizeof(cInfo));
  cInfo.dirInfo.ioVRefNum = pSpec->vRefNum;
  cInfo.dirInfo.ioDrParID = pSpec->parID;
  cInfo.dirInfo.ioNamePtr = folderName;
  cInfo.dirInfo.ioFDirIndex = -1; // get info about directory

  do
  {
    cInfo.dirInfo.ioDrDirID = cInfo.dirInfo.ioDrParID;
    cInfo.dirInfo.ioACUser = 0;
      err = PBGetCatInfoSync(&cInfo);
    if (noErr != err)
      break;
    
    // Copy the directory separator and name: check for enough space
    // before the copy (name length + sizeof(':') + sizeof('\0'))
    if (pathBufferSize < currentLen + (int)folderName[0] + 2)
    {
      err = AAFRESULT_SMALLBUF;
      break;
    }
     
    // Copy the name
    pathBuffer[currentLen++] = ':';
    copy_rev(&pathBuffer[currentLen], (const char *)&folderName[1], (int)folderName[0]);
    currentLen += (int)folderName[0];
    pathBuffer[currentLen] = 0; // terminate the string
    
  } while (cInfo.dirInfo.ioDrDirID != fsRtDirID);
  
  // Reverse the whole string.
  rev_mem(pathBuffer, currentLen);
  

  return err;
}

#endif /* #if defined(macintosh) || defined(_MAC) */
