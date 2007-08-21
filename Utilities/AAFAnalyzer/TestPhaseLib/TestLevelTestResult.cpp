//=---------------------------------------------------------------------=
//
// $Id: TestLevelTestResult.cpp,v 1.3 2007/08/21 14:08:34 jptrainor Exp $
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

//Test/Result files
#include "TestLevelTestResult.h"
#include "DetailLevelTestResult.h"
#include "Test.h"
#include "TestRegistry.h"

//Requirement files
#include <Requirement.h>
#include <RequirementMismatchException.h>

#include <iostream>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

using namespace std;
using namespace boost;

TestLevelTestResult::TestLevelTestResult( const shared_ptr<const Test> associatedTest )
  : LowLevelTestResult( associatedTest )
{}

TestLevelTestResult::TestLevelTestResult( const wstring& name,
                                          const wstring& desc,
                                          const wstring& explain,
                                          Result result,
                                          const shared_ptr<const Test> associatedTest )
  : LowLevelTestResult( associatedTest, name, desc, explain )
{
  this->ProtectedSetResult(result);
}

TestLevelTestResult::TestLevelTestResult( const wstring& name,
                                          const wstring& desc,
                                          const shared_ptr<const Test> associatedTest )
  : LowLevelTestResult( associatedTest, name, desc, L"" )
{}

TestLevelTestResult::~TestLevelTestResult()
{}

const enum TestResult::ResultLevel TestLevelTestResult::GetResultType() const
{
  return TestResult::TEST;
}

shared_ptr<DetailLevelTestResult> TestLevelTestResult::AddSingleResult( const wstring& reqId,
                                                                        Result result,
                                                                        const wstring& resultName,
                                                                        const wstring& resultDesc,
                                                                        const wstring& resultExplain )
{
  shared_ptr<DetailLevelTestResult>
    spResult( new DetailLevelTestResult( this->GetAssociatedTest(),
                                         resultName,
                                         resultDesc,
                                         resultExplain,
                                         reqId,
                                         result ) );

  this->AddSubtestResult( spResult );

  return spResult;
}

shared_ptr<DetailLevelTestResult> TestLevelTestResult::AddSingleResult( const wstring& reqId,
                                                                        const wstring& explain,
                                                                        Result result )
{
  shared_ptr<DetailLevelTestResult>
    spResult( new DetailLevelTestResult( this->GetAssociatedTest(),
                                         explain,
                                         reqId,
                                         result ) );

  this->AddSubtestResult( spResult );

  return spResult;
}

void TestLevelTestResult::InitConsolidateResults()
{
  const Requirement::RequirementMap& coveredReqs = GetAssociatedTest()->GetCoveredRequirements();

  for( Requirement::RequirementMap::const_iterator iter = coveredReqs.begin();
       iter != coveredReqs.end();
       ++iter )
  {
    this->AddRequirement( PASS, iter->second );
  }
}

} // end of namespace diskstream
