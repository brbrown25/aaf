//=---------------------------------------------------------------------=
//
// $Id: Aif2XtlMobSelectVisitor.cpp,v 1.2 2005/01/07 03:17:45 jptrainor Exp $ $Name:  $
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

#include <Aif2XtlMobSelectVisitor.h>

#include <AxMob.h>
#include <AxEssence.h>

#include <assert.h>


Aif2XtlSelectFirstFileMob::Aif2XtlSelectFirstFileMob()
{}

Aif2XtlSelectFirstFileMob::~Aif2XtlSelectFirstFileMob()
{}

bool Aif2XtlSelectFirstFileMob::operator()( Aif2XtlSourceMob& srcMobNode )
{
	AxSourceMob axSrcMob( srcMobNode.GetAif2XtlAAFObject() );

	AxEssenceDescriptor axEssDesc( axSrcMob.GetEssenceDescriptor() );
	
	IAAFFileDescriptorSP spFileDesc;

	if ( AxIsA( axEssDesc, spFileDesc ) ) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

Aif2XtlMobSelectVisitor::Aif2XtlMobSelectVisitor( Aif2XtlMobSelectFunc& func,
												  std::wostream& logStream )
: Aif2XtlParseTreeVisitor( logStream ),
  _master(false),
  _srcClipCount(0),
  _selectFunc( func )
{}

Aif2XtlMobSelectVisitor::~Aif2XtlMobSelectVisitor()
{}

void Aif2XtlMobSelectVisitor::PreOrderVisit( Aif2XtlMasterMob& node )
{
	_srcClipCount = 0;
	assert( !_master );
	_master = true;
}

void Aif2XtlMobSelectVisitor::PostOrderVisit( Aif2XtlMasterMob& node )
{
	_master = false;
}

void Aif2XtlMobSelectVisitor::PreOrderVisit( Aif2XtlSourceClipNode& node )
{
	if ( _master ) {
		_srcClipCount++;
	}

	// If we are processing a master mob sub tree, and this is the first
	// source mob then this src clip points to the head of a mob chain.
	// Each mob in the chain is represented as a child of this node in
	// the AifParseTree.  (The processing to accomplish that is performed
	// by the Aif2XtlSourceClipVisitor - which must preceed execution of
	// this visitor.) 
	//
	// This visitor queries the children and selects one of them.  Subsequent
	// traversals will only follow the "selected" child.

	if ( _master && 1 == _srcClipCount ) {
	
		int numChildren = node.GetNumChildren();
		int i;

		for (i = 0; i < numChildren; ++i ) {

			Aif2XtlSourceMob& srcMobNode = dynamic_cast<Aif2XtlSourceMob&>( node.GetChild(i) );

			if ( _selectFunc( srcMobNode ) ) {
				node.SetSelectedChild( i );
				break;
			}
		}

		// fail if none selected
		assert( i != numChildren );

	}
}

void Aif2XtlMobSelectVisitor::PostOrderVisit( Aif2XtlSourceClipNode& node )
{
	if ( _master ) {
		_srcClipCount--;
	}
}
