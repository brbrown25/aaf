// @doc INTERNAL
// @com This file implements the AAF informational logging utility. 
//=---------------------------------------------------------------------=
//
// $Id: StreamLogger.h,v 1.4 2004/02/27 14:26:16 stuart_hc Exp $ $Name:  $
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

#ifndef STREAMLOGGER_H_DEFINED
#define STREAMLOGGER_H_DEFINED (1)

#include "LoggerBase.h"

/****************************************************************
Name:
	class StreamLogger
Description:
	Logs messages to a given stream.
	
****************************************************************/
class StreamLogger : public LoggerBase
{
protected:
	FILE *iStream; // The file stream to log to. Can be stderr, stdout or a file.
public:
	StreamLogger( FILE *stream, unsigned level = 0, bool isMask = false );
	virtual ~StreamLogger( void );
	virtual unsigned SetLevel( unsigned level );
	virtual FILE* SetStream( FILE *stream );
	virtual void Print( unsigned level, const char *fmt, va_list args  );
};

inline StreamLogger::StreamLogger( FILE *stream, unsigned level, bool isMask )
	: iStream( stream ), LoggerBase( level, isMask ) 
{
}

inline StreamLogger::~StreamLogger( void )
{
}

/****************************************************************
Name:
	StreamLogger::SetStream
Description:
	Set the loggging stream.
Returns:
	The previous stream.
****************************************************************/
inline FILE *StreamLogger::SetStream( FILE *stream ) 
{ 
	FILE *temp = iStream;
	iStream = stream; 
	return temp; 
}

/****************************************************************
Name:
	class FileSteamLogger
Description:
	Logs messages to a file corresponding to a given 
	file name. 
	
****************************************************************/
class FileStreamLogger : public StreamLogger
{
public:
	FileStreamLogger(	const char *fileName, const char *mode = "w", 
						unsigned level = 0, bool isMask = false );
	virtual ~FileStreamLogger(void) ;
	class LogStreamNULL 
	{ 
	public:
		LogStreamNULL( void ) {} 
	};
};

/****************************************************************
Name:
	FileStreamLogger::FileStreamLogger
	FileStreamLogger::~FileStreamLogger
Description:
	Open up a file for logging with the given mode (constructor)
	Close the file when done   (destructor)
Returns:
	N/A
****************************************************************/

inline FileStreamLogger::FileStreamLogger( const char *fileName, const char *mode, unsigned level, bool isMask )
	: StreamLogger( fopen( fileName, mode ), level, isMask )
{
	if( iStream == NULL )
	{
		throw LogStreamNULL();
	}
}


inline FileStreamLogger::~FileStreamLogger(void) 
{ 
	if( iStream != 0 && iStream != stdout && iStream != stderr ) 
	{
		fclose( iStream ); 
	}
}

#endif // LOGGER_H_DEFINED
