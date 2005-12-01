//=---------------------------------------------------------------------=
//
// $Id: Requirement.h,v 1.4 2005/12/01 19:18:18 ajakowpa Exp $ $Name:  $
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

#ifndef __REQUIREMENT_H_
#define __REQUIREMENT_H_

//Boost files
#include <boost/shared_ptr.hpp>

//STL files
#include <string>
#include <map>

namespace aafanalyzer {

using namespace std;
using namespace boost;

class Requirement
{
public:
    enum RequirementType {FILE, APP, DEFINITION};
    enum Category        {COMPOSITIONAL, ANNOTATIONS, ADHOC};

    Requirement(const wstring& id,
                const RequirementType requirementType,
                const Category category,
                const wstring& name,
                const wstring& desc,
                const wstring& document,
                const wstring& version,
                const wstring& section);
    ~Requirement();
    
    const wstring& GetId() const;
    const enum RequirementType GetRequirementType() const;
    const enum Category GetCategory() const;
    const wstring& GetName() const;
    const wstring& GetDescription() const;
    const wstring& GetDocument() const;
    const wstring& GetVersion() const;
    const wstring& GetSection() const;
    
    typedef map< const wstring, shared_ptr<const Requirement> > RequirementMap;
    typedef shared_ptr<RequirementMap> RequirementMapSP;

 private:
    const wstring _id;
    const enum RequirementType _requirementType;
    const enum Category _category;
    const wstring _name;
    const wstring _description;
    const wstring _document;
    const wstring _version;
    const wstring _section;

  // prohibited
  Requirement();
  Requirement(const Requirement&);
  Requirement& operator=( const Requirement& );
};

} // end of namespace diskstream

#endif /*__REQUIREMENT_H_*/
