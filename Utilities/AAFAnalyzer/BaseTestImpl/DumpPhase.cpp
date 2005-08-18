//=---------------------------------------------------------------------=
//
// $Id: DumpPhase.cpp,v 1.1 2005/08/18 16:04:20 greek_fire Exp $
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

#include "DumpPhase.h"

#include "FileDumper.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 	
{

DumpPhase::DumpPhase(std::ostream& os, boost::shared_ptr<TestGraph> spTestGraph) 
: TestPhase(os),
  _spTestGraph(spTestGraph)
{
}

DumpPhase::~DumpPhase()
{
}

boost::shared_ptr<TestGraph> DumpPhase::GetTestGraph()
{
  return _spTestGraph;
}

std::vector<TestResult> DumpPhase::Execute() 
{
  std::vector<TestResult> LoadTest;

  //dump the aaf file graph to screen
  FileDumper dumper(GetOutStream(), GetTestGraph());
  LoadTest.push_back(dumper.Execute());

  return LoadTest;
}


} // end of namespace diskstream
