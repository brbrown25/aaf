//=---------------------------------------------------------------------=
//
// $Id: AAFComponentReference.cpp,v 1.5 2007/08/21 14:08:08 jptrainor Exp $
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

//AAF Analyzer Base files
#include "AAFComponentReference.h"
#include "TypedVisitor.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{
    
using namespace boost;

AAFComponentReference::AAFComponentReference(shared_ptr<Node> spParent, shared_ptr<Node> spChild, Node::LID tag, bool isLast)
  : Edge(spParent, spChild, (isLast ? Edge::EDGE_KIND_LAST_REFERENCE : Edge::EDGE_KIND_REFERENCE), tag)
{}

AAFComponentReference::~AAFComponentReference()
{}

bool AAFComponentReference::Visit(shared_ptr<Visitor> spVisitor)
{
  shared_ptr<TypedVisitor> spTypedVis = dynamic_pointer_cast<TypedVisitor>(spVisitor);
  if(spTypedVis)
  {
    return spTypedVis->EdgeVisit(*this);
  }

  return spVisitor->EdgeVisit(*this);
}

shared_ptr<Edge> AAFComponentReference::CreateNewEdge( shared_ptr<Node> spParent, shared_ptr<Node> spChild ) const
{
	bool isLast = GetKind() == EDGE_KIND_LAST_REFERENCE ? true : false;
	shared_ptr<Edge> spNewEdge( new AAFComponentReference( spParent, spChild, GetTag(), isLast) );
    return spNewEdge;
}

const std::wstring& AAFComponentReference::GetTypeName() const
{
  return typeName;
}

const std::wstring AAFComponentReference::typeName = L"component reference";

} // end of namespace diskstream
