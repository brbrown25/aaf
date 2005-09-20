//=---------------------------------------------------------------------=
//
// $Id: TopLevelTestResult.cpp,v 1.1 2005/09/20 17:47:26 ajakowpa Exp $
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

#include "TopLevelTestResult.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

using namespace std;

TopLevelTestResult::TopLevelTestResult()
  : HighLevelTestResult()
{}

TopLevelTestResult:: TopLevelTestResult( const AxString& name, 
                                         const AxString& desc,
                                         const AxString& explain,
                                         const AxString& docRef,
                                         Result defaultResult )
  : HighLevelTestResult( name, desc, explain, docRef, defaultResult )
{}

TopLevelTestResult::~TopLevelTestResult()
{}

void TopLevelTestResult::AppendSubtestResult( const boost::shared_ptr<const TestPhaseLevelTestResult>& subtestResult )
{
    this->AddSubtestResult( subtestResult );

    //Properly set the status of requirements based on the status of the new
    //child requirements.
    for (int curReqLevel = PASS; curReqLevel <= FAIL; curReqLevel++)
    {
      //Find all the requirements and loop through them.
      Requirement::RequirementMap requirements = subtestResult->GetRequirements((Result)curReqLevel);           
      Requirement::RequirementMap::iterator iter;
      for ( iter = requirements.begin(); iter != requirements.end(); iter++ )
      {
          //If the requirement was already in a map store it in the map with
          //the worst possible status.  Otherwise, add the requirement to the
          //map that it is in, in the child subtest.
          Result oldReqLevel;
          if ( this->ContainsRequirment( iter->first, oldReqLevel ) ) {
              if (oldReqLevel < curReqLevel)
              {
                  this->RemoveRequirement(iter->first);
                  this->AddRequirement((Result)curReqLevel, iter->second);
              }
          } else {
              this->AddRequirement((Result)curReqLevel, iter->second);
          }
      }
    }
    //If the result of the appended test is worse than any other subtest then
    //update the aggregate result.
    if ( subtestResult->GetResult() > this->GetAggregateResult() ) {
        this->SetEnumResult(subtestResult->GetResult());
    }
}

const enum TestResult::ResultLevel TopLevelTestResult::GetResultType() const
{
  return TestResult::TOP;
}

} // end of namespace diskstream
