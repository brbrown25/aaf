#ifndef __AxEx_h__
#define __AxEx_h__

//=---------------------------------------------------------------------=
//
// $Id: AxEx.h,v 1.6 2004/11/26 17:20:28 stuart_hc Exp $ $Name:  $
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
//=---------------------------------------------------------------------=

// Similar to standard C++ "exception" base class, but uses wide characters.
// Not derived from "exception" so that "what()" method can return wide 
// character.  Could be derived from "exception" if desired... with effort.
// The wide string is  returned by widewhat();
// The 8 bit string is returned by what() (override exception::what).

#include "AxTypes.h"

#include <AAF.h>

#include <exception>

#include <wchar.h>

#define CHECK_HRESULT( expr )				       \
{							       \
	HRESULT _hr = (expr);				       \
	if ( !SUCCEEDED( _hr ) ) {			       \
		throw AxExHResult( _hr, __FILE__, __LINE__ );  \
	}						       \
}

class AxEx : public std::exception {

public:

	AxEx();
	AxEx( const wchar_t* what );
	AxEx( const AxString& what );
	virtual ~AxEx() throw();
	virtual const wchar_t* widewhat() const throw();
	virtual const char* what() const throw();

private:
	AxString _widewhat;
	std::string _what;
};

class AxExHResult : public AxEx {

public:

	AxExHResult();
	AxExHResult( HRESULT hr );
	AxExHResult( HRESULT hr, const wchar_t* what );
	AxExHResult( HRESULT hr, const char* file, int line );
	virtual ~AxExHResult() throw();
	virtual const wchar_t* widewhat() const throw();
	virtual const char* what() const throw();

	HRESULT getHResult() const;
	int getLine() const;
	const char* getFile() const;

private:
	const char* _file;
	int _line;
	AxString _widewhat;
	std::string _what;
	HRESULT _hresult;
};

class AxExSmartPointer : public AxEx {

public:

	AxExSmartPointer();
	virtual ~AxExSmartPointer() throw();
};

class AxExBadImp : public AxEx {

public:

	AxExBadImp( const wchar_t* what );
	virtual ~AxExBadImp() throw();
};

#endif
