//=---------------------------------------------------------------------=
//
// $Id: Aif2XtlObjectRemoveVisitor.h,v 1.2 2005/01/07 03:17:45 jptrainor Exp $ $Name:  $
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
// Licensor of the AAF Association is Siemens SBS Media
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef _Aif2XtlObjectRemove_h_
#define _Aif2XtlObjectRemove_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

class Aif2XtlObjectMarkForRemovalVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlObjectMarkForRemovalVisitor( std::wostream& logStream );
	virtual ~Aif2XtlObjectMarkForRemovalVisitor();

	virtual void PreOrderVisit( Aif2XtlTaggedValue& node );
	virtual void PostOrderVisit( Aif2XtlTaggedValue& node );
};

class Aif2XtlObjectRemoveMarkedVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlObjectRemoveMarkedVisitor( std::wostream& logStream );
	virtual ~Aif2XtlObjectRemoveMarkedVisitor();

	virtual void PreOrderVisit( Aif2XtlParseTreeNode& node );
};


#endif
