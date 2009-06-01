//=---------------------------------------------------------------------=
//
// $Id: Aif2XtlMobSelectVisitor.h,v 1.3 2009/06/01 11:46:48 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Siemens SBS Media
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef _Aif2XtlMobSelectVisitor_h_
#define _Aif2XtlMobSelectVisitor_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

#include <AifParseTreeVisitor.h>

class Aif2XtlMobSelectFunc {
public:
	virtual bool operator()( Aif2XtlSourceMob& ) = 0;
};

class Aif2XtlSelectFirstFileMob : public Aif2XtlMobSelectFunc {
public:
	Aif2XtlSelectFirstFileMob();
	virtual ~Aif2XtlSelectFirstFileMob();
	virtual bool operator()( Aif2XtlSourceMob& srcMobNode );
};

class Aif2XtlMobSelectVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlMobSelectVisitor( Aif2XtlMobSelectFunc& func,
							 std::wostream& logStream );

	virtual ~Aif2XtlMobSelectVisitor();

	virtual void PreOrderVisit( Aif2XtlMasterMob& node );
	virtual void PostOrderVisit( Aif2XtlMasterMob& node );

	virtual void PreOrderVisit( Aif2XtlSourceClipNode& node );
	virtual void PostOrderVisit( Aif2XtlSourceClipNode& node );

private:
	// Prohibited
	Aif2XtlMobSelectVisitor();

	bool _master;
	int  _srcClipCount;
	Aif2XtlMobSelectFunc& _selectFunc;
};

#endif

