//=---------------------------------------------------------------------=
//
// $Id: TestPhaseLevelTestResult.h,v 1.1 2005/09/20 17:47:26 ajakowpa Exp $ $Name:  $
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

#ifndef __TESTPHASELEVELTESTRESULT_h__
#define __TESTPHASELEVELTESTRESULT_h__

//Project files
#include "HighLevelTestResult.h"
#include "TestLevelTestResult.h"

namespace aafanalyzer {

using namespace std;

class TestPhaseLevelTestResult : public HighLevelTestResult
{
 public:

  TestPhaseLevelTestResult();
  TestPhaseLevelTestResult( const AxString& name, const AxString& desc,
                            const AxString& explain, const AxString& docRef,
                            Result defaultResult );
  ~TestPhaseLevelTestResult();

  void AppendSubtestResult( const boost::shared_ptr<const TestLevelTestResult>& subtestResult );
  const enum ResultLevel GetResultType() const;

  // prohibited
  
};

} // end of namespace diskstream

#endif/*__TESTPHASELEVELTESTRESULT_h__*/
