//=---------------------------------------------------------------------=
//
// $Id: DetailLevelTestResult.h,v 1.1 2005/09/20 17:47:26 ajakowpa Exp $ $Name:  $
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

#ifndef __DETAILLEVELTESTRESULT_h__
#define __DETAILLEVELTESTRESULT_h__

//Project files
#include "LowLevelTestResult.h"

namespace aafanalyzer {

using namespace std;

class DetailLevelTestResult : public LowLevelTestResult
{
 public:

  DetailLevelTestResult( const Requirement::RequirementMapSP& requirements );
  DetailLevelTestResult( const AxString& name, const AxString& desc,
                         const AxString& explain, const AxString& docRef,
                         Result defaultResult,
                         const Requirement::RequirementMapSP& requirements );
  ~DetailLevelTestResult();

  void AppendSubtestResult( const boost::shared_ptr<const DetailLevelTestResult>& subtestResult );
  const enum ResultLevel GetResultType() const;
 private:
 
  // prohibited
  
};

} // end of namespace diskstream

#endif/*__DETAILLEVELTESTRESULT_h__*/
