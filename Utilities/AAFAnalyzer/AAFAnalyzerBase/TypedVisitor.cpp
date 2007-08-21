//=---------------------------------------------------------------------=
//
// $Id: TypedVisitor.cpp,v 1.6 2007/08/21 14:08:10 jptrainor Exp $
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
#include "TypedVisitor.h"
#include "AAFContainment.h"
#include "AAFComponentReference.h"
#include "AAFMobReference.h"
#include "AAFSlotReference.h"

namespace {

using namespace aafanalyzer;

} // end of namespace

//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer
{

TypedVisitor::TypedVisitor()
  : Visitor()
{}

TypedVisitor::TypedVisitor( Visitor::Follow_e follow )
  : Visitor( follow )
{}

TypedVisitor::~TypedVisitor()
{}

bool TypedVisitor::EdgeVisit(AAFContainment& edge)
{
  return Visitor::EdgeVisit(edge);
}

bool TypedVisitor::EdgeVisit(AAFComponentReference& edge)
{
  return Visitor::EdgeVisit(edge);
}

bool TypedVisitor::EdgeVisit(AAFMobReference& edge)
{
  return Visitor::EdgeVisit(edge);
}

bool TypedVisitor::EdgeVisit(AAFSlotReference& edge)
{
  return Visitor::EdgeVisit(edge);
}

} // end of namespace diskstream

