#ifndef __AxBasics_h__
#define __AxBasics_h__

//=---------------------------------------------------------------------=
//
// $Id: AxInit.h,v 1.4 2004/04/10 14:21:15 jptrainor Exp $ $Name:  $
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


class AxInit {
public:
	AxInit();
	AxInit( const char* dllname );
	virtual ~AxInit();
private:
	void Init( const char* dllname );
	static bool once;
};

#endif

