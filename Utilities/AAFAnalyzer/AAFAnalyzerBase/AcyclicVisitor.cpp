//=---------------------------------------------------------------------=
//
// $Id: AcyclicVisitor.cpp,v 1.4 2005/08/26 15:25:28 jptrainor Exp $
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

#include "AcyclicVisitor.h"

#include "Node.h"

#include <iostream>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================
namespace aafanalyzer {

AcyclicVisitor::  AcyclicVisitor(std::ostream& os)
  : _os(os),
    _Result( "Acyclic analysis",
	     "Detects cycles in an AAF object graph.",
	     "No cycles found.",
	     "", // DOCREF REQUIRED
	     TestResult::PASS )
{}

AcyclicVisitor::~AcyclicVisitor()
{
}

bool AcyclicVisitor::IsPresent(unsigned int lid)
{
  for(unsigned int i = 0; i < _Vector.size(); i++)
  {
    if(_Vector.at(i) == lid)
    {
      return true;
    }
  }
  
  return false;
}

bool AcyclicVisitor::PreOrderVisit(Node& node)
{
  Node::LID lid = node.GetLID();

  if(!IsPresent(lid))
  {
    //add node into the vector since it was visited on this sub-branch's traversal
    _Vector.push_back(lid);
    return true;
  }
 
  //a cycle was detected
  _Result.SetExplanation("Error: Cycle detected!");
  _Result.SetResult(TestResult::FAIL);

  std::cout << "Nodes of the cycle:" << std::endl;
  for(unsigned int i = 0; i < _Vector.size(); i++)
  {
    std::cout << _Vector.at(i) << std::endl;
  }
  std::cout << lid << std::endl;

  return false;
}

bool AcyclicVisitor::PostOrderVisit(Node& node)
{
  Node::LID lid = node.GetLID();

  if(IsPresent(lid))
  {
    //remove the node from vector since we have finished travelling down branch
    Erase(lid);
    return true;
  }

  //an unkown error occured
  _Result.SetExplanation("Error: Unknown error occured during postorder visit!");
  _Result.SetResult(TestResult::FAIL);

  return false;
}

void AcyclicVisitor::Erase(unsigned int lid)
{
  for(unsigned int i = 0; i < _Vector.size(); i++)
  {
    if(_Vector.at(i) == lid)
    {
      _Vector.erase(_Vector.begin() + i);
      break;
    }
  }  
}

const TestResult& AcyclicVisitor::GetTestResult() const
{
  return _Result;
}

} // end of namespace aafanalyzer
