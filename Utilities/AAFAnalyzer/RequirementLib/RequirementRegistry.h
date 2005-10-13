//=---------------------------------------------------------------------=
//
// $Id: RequirementRegistry.h,v 1.2 2005/10/13 19:33:58 ajakowpa Exp $
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

#ifndef __REQUIREMENTREGISTRY_H_
#define __REQUIREMENTREGISTRY_H_

//Requirement files
#include "Requirement.h"

//Boost files
#include <boost/shared_ptr.hpp>

//STL files
#include <string>

namespace aafanalyzer {

using namespace std;
using namespace boost;

class RequirementRegistry
{
 public:

  // dtor must be public so that shared_ptr class can access it
  ~RequirementRegistry();

  static RequirementRegistry& GetInstance();
  void Register( const shared_ptr<const Requirement>& req );
  const shared_ptr<const Requirement> GetRequirement( const wstring& id ) const;
  const Requirement::RequirementMap& GetAllRequirements() const;

 private:

  RequirementRegistry();//using Singleton pattern to allow only one object

  static RequirementRegistry* _pRequirementRegistry;
  Requirement::RequirementMap _requirementSet;

  // prohibited

};

} // end of namespace diskstream

#endif /*__REQUIREMENTREGISTRY_H_*/
