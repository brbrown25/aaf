//=---------------------------------------------------------------------=
//
// $Id: LowLevelTestResult.h,v 1.3 2005/10/18 17:02:42 ajakowpa Exp $ $Name:  $
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

#ifndef __LOWLEVELTESTRESULT_h__
#define __LOWLEVELTESTRESULT_h__

//Test/Result files
#include "TestResult.h"

namespace aafanalyzer {

using namespace std;
using namespace boost;

class LowLevelTestResult : public TestResult
{
 public:

  virtual ~LowLevelTestResult();

  //This must be called to change the status of a requirement.  The status of
  //requirements are not updated when another LowLevelTestResult is appended
  //as a subtest result.
  void SetRequirementStatus( TestResult::Result level, const shared_ptr<const Requirement>& req);

  virtual const enum ResultLevel GetResultType() const =0;

 protected:

  LowLevelTestResult( const Requirement::RequirementMapSP& requirements ) ;
  LowLevelTestResult( const wstring& name, const wstring& desc,
                      const wstring& explain, const wstring& docRef,
                      Result defaultResult,
                      const Requirement::RequirementMapSP& requirements );
 
   // prohibited
   LowLevelTestResult( const LowLevelTestResult& );
   LowLevelTestResult& operator=( const LowLevelTestResult& );
  
};

} // end of namespace diskstream

#endif/*__LOWLEVELTESTRESULT_h__*/
