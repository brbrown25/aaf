#include <iostream.h>
#include <assert.h>
#include <stdlib.h>

#include "headerGenUtils.h"

#define AAF_CLASS(name, id, parent, concrete) \
cout << endl; \
cout << "const aafUID_t kAAFClassID_"; \
cout << #name; \
cout << " =" << endl; \
id

#include "literalAuidDef.h"

static void doFile (const char * moduleName)
{
  assert (moduleName);
  cout << "#ifndef __" << moduleName << "_h__" << endl;
  cout << "#define __" << moduleName << "_h__" << endl;
  printCopyright (cout);
  cout << endl;
#include "AAFMetaDictionary.h"
  cout << endl;
  cout << "#endif // ! __" << moduleName << "_h__" << endl;
}


void main (int argc, char ** argv)
{
  char * moduleName = 0;
  validateArgs (argc, argv, moduleName);
  // If validateArgs() returned (without exit()ing) then moduleName
  // must be properly filled in.
  assert (moduleName);
  doFile (moduleName);
  exit (0);
}
