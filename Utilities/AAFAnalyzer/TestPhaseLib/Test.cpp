//=---------------------------------------------------------------------=
//
// $Id: Test.cpp,v 1.9 2009/06/01 11:46:48 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
//=---------------------------------------------------------------------=

//Test/Result files
#include "Test.h"
#include "TestRegistry.h"

//Analyzer Base files
#include <TestGraph.h>

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

Test::Test(wostream& os, const TestInfo& info)
  : _os(os),
    _spCoveredRequirements(InitializeRequirements(info.GetName()))
{}

const Test::ConstRequirementMapSP Test::InitializeRequirements(const wstring& name)
{
  TestRegistry& reg = TestRegistry::GetInstance();
  return reg.GetConstRequirementsForTest(name);
}

Test::~Test()
{}

wstring Test::GetName() const
{
  wstring null;
  return null;
}

wstring Test::GetDescription() const
{
  wstring null;
  return null;
}

wostream& Test::GetOutStream() const
{
  return _os;
}

shared_ptr<const TestGraph> Test::GetTestGraph()
{
  return _spGraph;
}

void Test::SetTestGraph(shared_ptr<const TestGraph> spGraph)
{
  _spGraph = spGraph;
}

shared_ptr<TestLevelTestResult> Test::CreateTestResult() const
{
  shared_ptr<TestLevelTestResult>
    spTestResult( new TestLevelTestResult( GetName(),
                                           GetDescription(),
                                           this->shared_from_this() ) );
  return spTestResult;
}

shared_ptr<TestLevelTestResult> Test::CreateTestResult( const wstring& explain,
                                                        TestResult::Result result ) const
{
  shared_ptr<TestLevelTestResult>
    spTestResult( new TestLevelTestResult( GetName(),
                                           GetDescription(),
                                           explain,
                                           result,
                                           this->shared_from_this() ) );
  return spTestResult;
}

shared_ptr<TestLevelTestResult> Test::CreatePassTestResult() const
{
  return CreateTestResult( L"", TestResult::PASS );
}

const Requirement::RequirementMap& Test::GetCoveredRequirements() const
{
  return *_spCoveredRequirements;
}

// Get a single requirement that is registered against this test.
// Throws xxx if reqId is not registered.
shared_ptr<const Requirement> Test::GetRequirement( const wstring& reqId ) const
{
  Requirement::RequirementMap::const_iterator iter = _spCoveredRequirements->find(reqId);
  assert( iter != _spCoveredRequirements->end() );
  return iter->second;
}

bool Test::IsRequirementRegistered( const wstring& reqId ) const
{
  return _spCoveredRequirements->find(reqId) != _spCoveredRequirements->end();
}

} // end of namespace diskstream
