//=---------------------------------------------------------------------=
//
// $Id: Test.h,v 1.1 2005/08/18 14:07:23 greek_fire Exp $ $Name:  $
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

#ifndef __TEST_h__
#define __TEST_h__

//project files
#include "TestResult.h"
#include <TestGraph.h>

//stl files
#include <iostream>
#include <string>

//boost files
#include <boost/shared_ptr.hpp>

namespace aafanalyzer {

class Test
{
 public:
  Test(std::ostream& os);
  virtual ~Test();

  virtual TestResult Execute() = 0;
  virtual std::string GetName();
  virtual std::string GetDescription();
  std::ostream& GetOutStream();
  boost::shared_ptr<TestGraph> GetTestGraph();

protected:
  void SetTestGraph(boost::shared_ptr<TestGraph> spTestGraph);

 private:
  std::ostream& _os;
  boost::shared_ptr<TestGraph> _spTestGraph;

  // prohibited
  Test(const Test&);
  Test& operator=( const Test& );
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
