//
// An example program that calls the test AAF COM interfaces.
//

//
#include <iostream.h>
#include <stdlib.h>
#include <time.h>


#ifdef WIN32
#include <unknwn.h>
#include <objbase.h>
#endif

#ifdef __powerc

#define _MAC

#if !defined(CDECL) && defined(_MSC_VER)
#define CDECL	_cdecl
#endif // CDECL

#if !defined(FAR)
#define FAR
#endif

#include <ole2.h>
#include "dispatch.h"
#include "wintypes.h"
#include <olectl.h>
#endif


#ifndef __AAFTypes_h__
#include "AAFTypes.h"
#endif


#include "CAAFModuleTest.h"

#ifdef __powerc
#include <console.h> /* Mac command line window */
#endif

#ifdef WIN32
#include <winbase.h>
#include <tchar.h>
#endif

typedef AAFRESULT (*AAFModuleTestProc)();



#define SUCCESS (0)
#define FAILURE (-1)


// helper class
struct CComInitialize
{
	CComInitialize() { CoInitialize(NULL); }
	~CComInitialize() { CoUninitialize(); }
};




// forward declarations.

#ifdef WIN32
// routine copied from Tim Bingham's test program...
void formatError(DWORD errorCode)
{
  TCHAR buffer[256];

  int status = FormatMessage(
    FORMAT_MESSAGE_FROM_SYSTEM,
    NULL,
    errorCode,
    LANG_SYSTEM_DEFAULT,
    buffer, sizeof(buffer)/sizeof(buffer[0]),
    NULL);

  if (status != 0) {
    int length = _tcslen(buffer);
    if (length >= 2) {
      buffer[length - 2] = '\0';
    }
    cerr << buffer << endl;
  } else {
    cerr << hex << errorCode << dec << endl;
  }
}
#endif



//
// If there are no arguments then perform the module test for all modules.
// Otherwise the arguments are assumed to be valid AAF object names such as
// AAFObject or AAFComponent.
//


int main(int argc, char* argv[])
{
	int result = SUCCESS;

	// Initialize com library for this process.
	CComInitialize comInit;

	// Create the module test object.
	CAAFModuleTest AAFModuleTest;
	try
	{
		HRESULT hr = S_OK;

		/* console window for mac */

		#ifdef __powerc
		argc = ccommand(&argv);
		#endif


		/* Check arguments to see if help was requested */

		if ( argc > 1 &&
			(0 == strncmp(argv[1],"-h",2) ||
			 0 == strncmp(argv[1],"-H",2) )	)
		{
			cout<< "\nCOMMODAAF***********************\n"; 
			cout<< "No arguments --> To run all tests\n";
			cout<< "Otherwise any AAF object class name can be typed\n";
			cout<< "and that objects test method will be executed.\n";
			cout<< "ex AAFSegment AAFTransition etc\n"<< endl;

			return(0);
		}

		/* Print Header */
		cout<< "\n\n"<< endl;
		cout<< "***************************\n";
		cout<< "*       COMMODAAF         *\n";
		cout<< "*   AAF COM Module Test   *\n";
		cout<< "***************************\n"<< endl;	


		/* Get and print start time */
		time_t s_time;
		time(&s_time);
		cout<< ctime(&s_time)<< endl<< endl;

		if (1 >= argc)
			// Call all Module tests...
			hr = AAFModuleTest.Test(NULL);
		else
		{
			// Call only the modules that are named in the command line.
			int module;

			for (module = 1; module < argc; module++)
				hr = AAFModuleTest.Test(reinterpret_cast<unsigned char *>(argv[module]));
		}
		
		/* Get and Print finish time	*/
		time_t e_time;
		time(&e_time);
		cout<< endl<< ctime(&e_time)<< endl;

		/* Determine and print elapsed time */
		double elapsed_time = difftime( e_time, s_time );
		cout<< "COMMODAAF completed in ";
		cout<< ((long)elapsed_time/3600) <<":"; /* hours */
		cout<< (((long)elapsed_time%3600)/60) <<":"; /* minutes */
		cout<< (((long)elapsed_time%3600)%60) <<"\n" <<endl; /* seconds */


		result = (int)hr;
	}
	catch (...)
	{
		result = FAILURE;
	}
	

	return result;
}


