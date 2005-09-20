//=---------------------------------------------------------------------=
//
// $Id: TestResult.cpp,v 1.6 2005/09/20 17:47:26 ajakowpa Exp $
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

#include "TestResult.h"
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

// Default result is FAIL.
// Test implementations must explicity indicate success.
// Default result of subtests is PASS, it is updated whenever a new subtest is
// attached to the worst result.  It does not affect the result unless it is
// done explicitly outside of this file.
TestResult::TestResult()
  : _result( FAIL ),
    _spSubtestResults(new SubtestResultVector()),
    _aggregateEnumResult( PASS ),
    _spPassedRequirements( new Requirement::RequirementMap() ),
    _spWarnedRequirements( new Requirement::RequirementMap() ),
    _spFailedRequirements( new Requirement::RequirementMap() )
{}

TestResult::TestResult( const AxString& name,
			const AxString& desc,
			const AxString& explain,
			const AxString& docRef,
			Result defaultResult )
  : _name( name ),
    _desc( desc ),
    _expl( explain ),
    _docRef( docRef ),
    _result( defaultResult ),
    _spSubtestResults(new SubtestResultVector()),
    _aggregateEnumResult( PASS ),
    _spPassedRequirements( new Requirement::RequirementMap() ),
    _spWarnedRequirements( new Requirement::RequirementMap() ),
    _spFailedRequirements( new Requirement::RequirementMap() )
{}

TestResult::TestResult ( const Requirement::RequirementMapSP& requirements )
  : _result( FAIL ), 
    _spSubtestResults(new SubtestResultVector()),
    _aggregateEnumResult( PASS ),
    _spPassedRequirements( requirements ),
    _spWarnedRequirements( new Requirement::RequirementMap() ),
    _spFailedRequirements( new Requirement::RequirementMap() )
{}
    
TestResult::TestResult (const AxString& name, const AxString& desc,
                        const AxString& explain, const AxString& docRef,
                        Result defaultResult,
                        const Requirement::RequirementMapSP& requirements)
  : _name( name ),
    _desc( desc ),
    _expl( explain ),
    _docRef( docRef ),
    _result( defaultResult ),
    _spSubtestResults(new SubtestResultVector()),
    _aggregateEnumResult( PASS ),
    _spPassedRequirements( requirements ),
    _spWarnedRequirements( new Requirement::RequirementMap() ),
    _spFailedRequirements( new Requirement::RequirementMap() )
{}

TestResult::~TestResult()
{}

const AxString& TestResult::GetExplanation() const
{
  return _expl;
}

const AxString& TestResult::GetDocumentRef() const
{
  return _docRef;
}

const AxString& TestResult::GetName() const
{
  return _name;
}

const AxString& TestResult::GetDescription() const
{
  return _desc;
}

enum TestResult::Result TestResult::GetResult() const
{
  return _result;
}

void TestResult::SetExplanation(const AxString& exp)
{
  _expl = exp;
}

void TestResult::SetName(const AxString& name)
{
  _name = name;
}

void TestResult::SetDescription(const AxString& desc)
{
  _desc = desc;
}

void TestResult::SetResult(Result result)
{
  //can only be set to success, warning, or failure
  _result = result;
}

const TestResult::SubtestResultVector& TestResult::GetSubtestResults() const {
    return *_spSubtestResults;
}

enum TestResult::Result TestResult::GetAggregateResult() const 
{
    return _aggregateEnumResult;
}

bool TestResult::ContainsSubtests() const {
    return !_spSubtestResults->empty();
}

const Requirement::RequirementMap& TestResult::GetRequirements( Result type ) const
{
    switch (type)
    {
        case PASS:
            return *_spPassedRequirements;
            break;
        case WARN:
            return *_spWarnedRequirements;
            break;
        default:
            return *_spFailedRequirements;
    }
    
}

void TestResult::AddDetail( const AxString& detail )
{
  _details.push_back( detail );
}

const vector<AxString>& TestResult::GetDetails() const
{
  return _details;
}

void TestResult::AddSubtestResult( boost::shared_ptr<const TestResult> subtestResult )
{
  _spSubtestResults->push_back( subtestResult );
}

void TestResult::SetEnumResult( Result enumResult )
{
  _aggregateEnumResult = enumResult;
}

bool TestResult::ContainsRequirment( const AxString& id, Result& outContainedIn )
{
    if ( _spPassedRequirements->find(id) != _spPassedRequirements->end() ) {
        outContainedIn = PASS;
        return true;
    } else if ( _spWarnedRequirements->find(id) != _spWarnedRequirements->end() ) {
        outContainedIn = WARN;
        return true;
    } else if ( _spFailedRequirements->find(id) != _spFailedRequirements->end() ) {
        outContainedIn = FAIL;
        return true;
    } else {
        return false;
    }
}

void TestResult::ClearRequirements()
{
    _spPassedRequirements->clear();
    _spWarnedRequirements->clear();
    _spFailedRequirements->clear();
}

void TestResult::AddRequirement( Result type, const boost::shared_ptr<const Requirement>& req )
{
    Requirement::RequirementMapSP spMap = this->GetMyRequirements( type );
    (*spMap)[req->GetId()] = req;
}

void TestResult::RemoveRequirement( const AxString& id )
{
    _spPassedRequirements->erase(id);
    _spWarnedRequirements->erase(id);
    _spFailedRequirements->erase(id);
}

const Requirement::RequirementMapSP& TestResult::GetMyRequirements( Result type )
{
    switch (type)
    {
        case PASS:
            return _spPassedRequirements;
            break;
        case WARN:
            return _spWarnedRequirements;
            break;
        default:
            return _spFailedRequirements;
    }
    
}

} // end of namespace diskstream
