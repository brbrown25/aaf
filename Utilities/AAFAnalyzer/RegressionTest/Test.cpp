//=---------------------------------------------------------------------=
//
// $Id: Test.cpp,v 1.1 2005/08/11 20:04:16 greek_fire Exp $
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

#include "Test.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

Test::Test(std::ostream& os)
: _os(os)
{
}

Test::~Test()
{
}

std::string Test::GetName()
{
  std::string null;
  return null;
}

std::string Test::GetDescription()
{
  std::string null;
  return null;
}

std::ostream& Test::GetOutStream()
{
  return _os;
}

boost::shared_ptr<TestGraph> Test::GetTestGraph()
{
  return _spTestGraph;
}

void Test::SetTestGraph(boost::shared_ptr<TestGraph> spTestGraph)
{
  _spTestGraph = spTestGraph;
}

} // end of namespace diskstream
