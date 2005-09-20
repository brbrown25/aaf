//=---------------------------------------------------------------------=
//
// $Id: Test2Stub.cpp,v 1.1 2005/09/20 17:48:53 ajakowpa Exp $
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

#include "Test2Stub.h"

#include <vector>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

Test2Stub::Test2Stub(std::wostream& os)
: Test(os, GetTestInfo())
{
}

Test2Stub::~Test2Stub()
{
}

boost::shared_ptr<TestLevelTestResult> Test2Stub::Execute()
{
  const boost::shared_ptr<const Test> me = this->shared_from_this();
  Requirement::RequirementMapSP spMyReqs(new Requirement::RequirementMap(this->GetCoveredRequirements()));
  boost::shared_ptr<TestLevelTestResult> spResult(new TestLevelTestResult(me, spMyReqs ));
  spResult->SetName(GetName());
  spResult->SetDescription(GetDescription());

  return spResult;
}

AxString Test2Stub::GetName() const
{
  AxString name = L"Test 2";
  return name;
}

AxString Test2Stub::GetDescription() const
{
  AxString description = L"For Regression Testing.";
  return description;
}

const TestInfo Test2Stub::GetTestInfo()
{
    boost::shared_ptr<std::vector<AxString> > spReqIds(new std::vector<AxString>);
    spReqIds->push_back(L"TEST01");
    spReqIds->push_back(L"TEST02");
    spReqIds->push_back(L"TEST03");
    spReqIds->push_back(L"TEST04");
    return TestInfo(L"Test2Stub", spReqIds);
}

} // end of namespace aafanalyzer
