// @doc INTERNAL
// @com This file implements the AAF informational logging utility. 
//=---------------------------------------------------------------------=
//
// $Id: StreamLogger.cpp,v 1.3 2004/02/27 14:26:16 stuart_hc Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include "StreamLogger.h"
#include <time.h>

/****************************************************************
Name:
	StreamLogger::SetLevel
Description:
	Set the log level and make note of it in the log.
Returns:
	The previous level.
****************************************************************/
unsigned StreamLogger::SetLevel( unsigned level ) 
{ 
	unsigned temp = LoggerBase::SetLevel( level );
	Log( level, "Log Level changed from %d (0x%x) to %d (0x%x)\n", 
		temp, temp, level, level );
	return temp; 
}

/****************************************************************
Name:
	StreamLogger::Print
Description:
	Print a timestamped log message to the owned stream.
Returns:
	None.
****************************************************************/
void StreamLogger::Print( unsigned level, const char *fmt, va_list args  )
{

	if( iStream != 0 )
	{
		time_t currTime;
		time( &currTime );
		char *timeStr = ctime( &currTime );
		timeStr[24] = 0; // ctime hands back a well defined fixed length string.
		fprintf( iStream, "Level[%d] %s: " , level, timeStr );
		vfprintf( iStream, fmt, args );
	}
   
	return;
}
