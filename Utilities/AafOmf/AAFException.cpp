// @doc INTERNAL
// @com This file implements the AAF exception handling utility. 
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

#include "AAFException.h"

/*******************************************************************
Name:
	AAFException
Description:
	Test the given error code for a failure condition. If a failure
	occurred, print the given printf() style message to the log (if 
	applicable) and throw an exception.
Returns:
	None.
********************************************************************/

void AAFException::Check( AAFRESULT errCode, const char *fmt, ... ) 
{
	if( FAILED( errCode ) )
	{
		if( fmt != 0 && iLogger != 0 )
		{
			va_list args;
			va_start( args, fmt );
			VaList valist( args );
			iLogger->Log( 0, fmt, valist );
			va_end( args );
		}
		throw AAFException( errCode );
	}
	return;
}
