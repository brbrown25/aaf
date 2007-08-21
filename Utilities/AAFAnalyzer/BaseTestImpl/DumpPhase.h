//=---------------------------------------------------------------------=
//
// $Id: DumpPhase.h,v 1.7 2007/08/21 14:08:15 jptrainor Exp $ $Name:  $
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

#ifndef __DUMPPHASE_h__
#define __DUMPPHASE_h__

//Base Test files (included so the application only needs to include the Test
//Phase and not individual tests in order to register tests).
#include "FileDumper.h"

//Test/Result files
#include <TestPhase.h>

//Ax files
#include <AxTypes.h>

namespace aafanalyzer {
    
using namespace std;
using namespace boost;

class TestGraph;
class Node;

class DumpPhase : public TestPhase
{
 public:

  // Use the root node contained by the TestGraph. Only follow edges
  // that model contaiment. (i.e. for AAF file this dumps the header
  // and all contained objects)
  DumpPhase(wostream& os, shared_ptr<const TestGraph> spGraph);

  // Use alternate root node.
  // This is used to dump the top level composition in an aaf file. It
  // will configure the visitor to follow references such that the
  // entire composition graph, including resolved mob references, is
  // dumped.
  DumpPhase(wostream& os, shared_ptr<const TestGraph> spGraph, shared_ptr<Node> spRoot);

  ~DumpPhase();

  shared_ptr<const TestGraph> GetTestGraph();
  shared_ptr<TestPhaseLevelTestResult> Execute();

 private:
  // prohibited
  DumpPhase();
  DumpPhase( const DumpPhase& );
  DumpPhase& operator=( const DumpPhase& );

  shared_ptr<const TestGraph> _spGraph;
  shared_ptr<Node> _spRoot;

  bool _followReferences;
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
