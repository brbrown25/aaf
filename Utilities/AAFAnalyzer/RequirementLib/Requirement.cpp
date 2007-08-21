//=---------------------------------------------------------------------=
//
// $Id: Requirement.cpp,v 1.4 2007/08/21 14:08:33 jptrainor Exp $
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

//Requirement files
#include "Requirement.h"

#include <assert.h>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

Requirement::Requirement(const wstring& id,
                         const RequirementType requirementType,
			 const wstring& requirementTypeAsString,
                         const Category category,
			 const wstring& categoryAsString,
			 const wstring& name,
                         const wstring& desc,
			 const wstring& document,
                         const wstring& version,
			 const wstring& section):
    _id( id ),
    _requirementType( requirementType ),
    _requirementTypeAsString( requirementTypeAsString ),
    _category( category ),
    _categoryAsString( categoryAsString ),
    _name( name ),
    _description( desc ),
    _document( document ),
    _version( version ),
    _section( section )
{}
    
Requirement::~Requirement()
{}

const wstring& Requirement::GetId() const
{
    return _id;
}

const enum Requirement::RequirementType Requirement::GetRequirementType() const
{
    return _requirementType;
}

const enum Requirement::Category Requirement::GetCategory() const
{
    return _category;
}

const wstring& Requirement::GetName() const
{
    return _name;
}

const wstring& Requirement::GetDescription() const
{
    return _description;
}

const wstring& Requirement::GetDocument() const
{
    return _document;
}

const wstring& Requirement::GetVersion() const
{
    return _version;
}

const wstring& Requirement::GetSection() const
{
    return _section;
}

const wstring& Requirement::GetRequirementTypeAsString() const
{
  return _requirementTypeAsString;
}

const wstring& Requirement::GetCategoryAsString() const
{
  return _categoryAsString;
}

} // end of namespace diskstream
