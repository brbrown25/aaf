#include "OMAssertions.h"

#if defined (OM_ENABLE_DEBUG)

#include <string.h>

#include <iostream.h>
#include <stdlib.h>

#include "OMUtilities.h"

#if defined(OM_ENABLE_STACK_TRACE)
#include "OMStackTrace.h"
#endif


void reportAssertionFailure(char* kind,
                            char* name,
                            char* expressionString,
                            char* routine,
                            char* fileName,
                            size_t lineNumber)
{
  cerr << kind << " \"" << name << "\" failed in routine \""
       << routine  << "\"." << endl;
  cerr << "The failure occurred at line " << lineNumber
       << " in file \"" << fileName << "\"." << endl;
  cerr << "The condition \"" << expressionString << "\" was violated." << endl;

#if defined(OM_ENABLE_STACK_TRACE)
  printStackTrace(cerr);
#endif

#if defined(OM_ENABLE_ABORT)
  abort();
#else
  exit(FAILURE);
#endif
}

bool validString(const char* string)
{
  return ((string != 0) && (strlen(string) > 0));
}

bool validWideString(const wchar_t* string)
{
  return (string != 0) /* && (lengthOfWideString(string) > 0) */;
}

bool validOMWideString(const OMWideCharacter* string)
{
  return (string != 0) /* && (lengthOfOMWideString(string) > 0) */;
}

#if defined (OM_ENABLE_TRACE)

void trace(const char* routine)
{
  cerr << "Enter \"" << routine << "\"." << endl;
}

#endif

#endif
