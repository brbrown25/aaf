//=---------------------------------------------------------------------=
//
// $Id: AcyclicAnalysis.cpp,v 1.2 2005/08/26 14:02:52 jptrainor Exp $
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

#include "AcyclicAnalysis.h"

#include <DepthFirstTraversal.h>
#include <AcyclicVisitor.h>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

AcyclicAnalysis::AcyclicAnalysis(std::ostream& os, boost::shared_ptr<TestGraph> spTestGraph)
: Test(os)
{
  SetTestGraph(spTestGraph);
}

AcyclicAnalysis::~AcyclicAnalysis()
{
}

TestResult AcyclicAnalysis::Execute()
{
  TestResult result;
  boost::shared_ptr<AcyclicVisitor> spVisitor(new AcyclicVisitor(GetOutStream()));
  DepthFirstTraversal dfs(GetTestGraph()->GetEdgeMap(), GetTestGraph()->GetRootNode());

  //output to screen
  //GetOutStream() << GetName() << std::endl << GetDescription() << std::endl << std::endl;

  //set result properties
  result.SetName(GetName());
  result.SetDescription(GetDescription());

  dfs.TraverseDown(spVisitor, GetTestGraph()->GetRootNode()); 

  TestResult visitorResult = spVisitor->GetTestResult();

  // FIXME - At this point we should store sub results.
  
  result.SetResult( visitorResult.GetResult() );

  return result;
}

std::string AcyclicAnalysis::GetName() const
{
  std::string name = "--- Acyclic Analysis Test ---";
  return name;
}

std::string AcyclicAnalysis::GetDescription() const
{
  std::string description = "Test Description: Traverse the directed graph and ensure it is acyclic.";
  return description;
}

} // end of namespace aafanalyzer
