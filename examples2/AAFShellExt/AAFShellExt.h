//=---------------------------------------------------------------------=
//
// $Id: AAFShellExt.h,v 1.2 2004/02/27 14:26:37 stuart_hc Exp $ $Name:  $
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

// AAFShellExt.h : main header file for the AAFShellExt DLL
//

#if !defined(AAFSHELLEXT_H)
#define AAFSHELLEXT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "AAFShellExt_i.h"

/////////////////////////////////////////////////////////////////////////////
// CAAFShellExtApp
// See AAFShellExt.cpp for the implementation of this class
//

class CAAFShellExtApp : public CWinApp
{
public:
	CAAFShellExtApp();
	~CAAFShellExtApp();

    // Holds pointers to the open and closed icons.
    // If we don't do this, we can never 
    // reliably get our icon if we develop more
    // than one namespace extension on our own.
    UINT OpenIcon(){ return m_iconOpen; }
    UINT ClosedIcon(){ return m_iconClosed; }
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAAFShellExtApp)
	public:
		virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CAAFShellExtApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL InitATL();
    UINT m_iconOpen;
    UINT m_iconClosed;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AAFSHELLEXT_H)
