//=---------------------------------------------------------------------=
//
// $Id: TestGraph.h,v 1.2 2005/08/18 20:38:00 greek_fire Exp $
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

#ifndef __TESTGRAPH_h__
#define __TESTGRAPH_h__

//boost files
#include <boost/shared_ptr.hpp>

namespace aafanalyzer {

class Node;
class EdgeMap;

class TestGraph
{
 public:
   
  // The default copy constructor is okay.
  TestGraph(boost::shared_ptr<EdgeMap> spEdgeMap, boost::shared_ptr<Node> spRootNode);
  ~TestGraph();

  boost::shared_ptr<EdgeMap> GetEdgeMap() const;
  boost::shared_ptr<Node> GetRootNode() const;

 private:
  boost::shared_ptr<EdgeMap> _spEdgeMap;
  boost::shared_ptr<Node> _spRootNode;

  // prohibited
  TestGraph();
  TestGraph& operator=(const TestGraph& graph);
};

} // end of namespace diskstream

#endif
