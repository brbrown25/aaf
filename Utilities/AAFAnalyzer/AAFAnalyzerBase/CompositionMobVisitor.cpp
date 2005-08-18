//=---------------------------------------------------------------------=
//
// $Id: CompositionMobVisitor.cpp,v 1.1 2005/08/18 20:38:43 greek_fire Exp $
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

#include "CompositionMobVisitor.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================
namespace aafanalyzer {

CompositionMobVisitor::CompositionMobVisitor(std::ostream& os, TestResult& result)
: _os(os),
  _Result(result)
{
}

CompositionMobVisitor::~CompositionMobVisitor()
{
}

bool CompositionMobVisitor::IsPresent(unsigned int lid)
{
  Map::const_iterator iter = _Map.find(lid);  
  return iter != _Map.end();
}

bool CompositionMobVisitor::PreOrderVisit(AAFTypedObjNode<IAAFCompositionMob>& node)
{
  Node::LID lid = node.GetLID();

  if(IsPresent(lid))
  {
    _Map[lid] = _Map[lid]++;
  }
  else
  {
    _Map[lid] = 0;
  }

  return true;
}

std::vector<unsigned int> CompositionMobVisitor::GetCompMobsWithCount(int count)
{
  Vector mobs;
  
  return mobs;
}

}
