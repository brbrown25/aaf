//=---------------------------------------------------------------------=
//
// $Id: RefResolver.h,v 1.7 2005/10/13 19:33:58 ajakowpa Exp $ $Name:  $
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

#ifndef __REFRESOLVER_h__
#define __REFRESOLVER_h__

//Test/Result files
#include <Test.h>

//Ax files
#include <AxTypes.h>

namespace aafanalyzer {

using namespace std;
using namespace boost;

class TestLevelTestResult;
class TestGraph;

class RefResolver : public Test
{
 public:
  RefResolver(wostream& os, shared_ptr<const TestGraph> spGraph);
  ~RefResolver();

  shared_ptr<TestLevelTestResult> Execute();
  AxString GetName() const;
  AxString GetDescription() const;
  static const TestInfo GetTestInfo();

 private:

  // prohibited
  RefResolver(const RefResolver&);
  RefResolver& operator=( const RefResolver& );
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
