//=---------------------------------------------------------------------=
//
// $Id: LowLevelTestResult.cpp,v 1.1 2005/09/20 17:47:26 ajakowpa Exp $
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

#include "LowLevelTestResult.h"
#include <TestRegistry.h>
#include <RequirementMismatchException.h>
#include <sstream>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

using namespace std;

LowLevelTestResult::LowLevelTestResult( const Requirement::RequirementMapSP& requirements ) 
    : TestResult (requirements)
{}

LowLevelTestResult::LowLevelTestResult( const AxString& name, const AxString& desc,
                                        const AxString& explain, const AxString& docRef,
                                        Result defaultResult,
                                        const Requirement::RequirementMapSP& requirements )
    : TestResult (name, desc, explain, docRef, defaultResult, requirements)
{}

LowLevelTestResult::~LowLevelTestResult()
{}

void LowLevelTestResult::SetRequirementStatus( TestResult::Result level, const boost::shared_ptr<const Requirement>& req)
{
    //If the requirement was already in a map store it in the map with
    //the worst possible status.  Otherwise, the requirement should not be
    //set because it is not part of this test result.
    Result oldReqLevel;
    if ( this->ContainsRequirment( req->GetId(), oldReqLevel ) ) {
        this->RemoveRequirement(req->GetId());
        this->AddRequirement(level, req);
    } else if ( TestRegistry::GetInstance().IsUnsafeRequirements() ) {
        //If unsafe requirements are being used, then go ahead and add it to the
        //list of requirements stored by this test.  Do not register the 
        //requirement - it should not be reported as being covered by the 
        //associated test (although it is possible that it has been loaded).
        this->AddRequirement(level, req);
    } else {
            std::wostringstream msg;
            msg << L"Attempting to set status of " << req->GetId() << L" which does not exist in " << this->GetName();
            throw RequirementMismatchException ( msg.str().c_str() );

    }
}

} // end of namespace diskstream
