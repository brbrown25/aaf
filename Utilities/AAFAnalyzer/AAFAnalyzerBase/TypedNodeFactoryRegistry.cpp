//=---------------------------------------------------------------------=
//
// $Id: TypedNodeFactoryRegistry.cpp,v 1.7 2005/10/13 19:33:58 ajakowpa Exp $
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

//AAF Analyzer Base files
#include "TypedNodeFactoryRegistry.h"
#include "TypedNodeFactoryImpl.h"

//Ax files
#include <AxSmartPointer.h>

//AAF files
#include <AAF.h>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer {

using namespace boost;

//static variable
TypedNodeFactoryRegistry* TypedNodeFactoryRegistry::_pFactory = NULL;

TypedNodeFactoryRegistry::TypedNodeFactoryRegistry()
{
  RegisterAAFObjects();
}

TypedNodeFactoryRegistry::~TypedNodeFactoryRegistry()
{
  if(_pFactory != NULL)
  {
    delete _pFactory;
    _pFactory = NULL;
  }
}

bool TypedNodeFactoryRegistry::IsPresent(aafUID_t AUID)
{
  Map::const_iterator iter = _Map.find(AUID);
  return iter != _Map.end();
}

bool TypedNodeFactoryRegistry::Deregister(aafUID_t AUID)
{
  // TO BE COMPLETED
  return false;
}

TypedNodeFactoryRegistry& TypedNodeFactoryRegistry::GetInstance()
{
  //using Singleton pattern, create object iff it does not exist
  if(_pFactory == NULL)
  {
    _pFactory = new TypedNodeFactoryRegistry();
  }

  return *_pFactory;
}

shared_ptr<TypedNodeFactory> TypedNodeFactoryRegistry::LookUp(AxClassDef& clsDef)
{
  //Find the Auid for the IAAFObject in question, if none exists look to its parent and continue
  //upwards until an Auid is found.  An exception will be thrown if no Auid is found at the
  //topmost level (i.e. no parent exists for IAAFObject).  This is not handled because it should 
  //not happen in a correct file.
  aafUID_t Auid = clsDef.GetAUID();

  //Base Case:
  if(IsPresent(Auid))
  {
    return _Map[Auid];
  }  
  //Recursive Case:
  AxClassDef clsParent(clsDef.GetParent());

  return LookUp(clsParent);//Use Tail Recursion to avoid potential problem of stack overflow
}

void TypedNodeFactoryRegistry::Register(aafUID_t AUID, shared_ptr<TypedNodeFactory> spFactory)
{
  //only add a factory into Map if it is not already present
  if(!IsPresent(AUID))
  {
    _Map[AUID] = spFactory;
  }
}

void TypedNodeFactoryRegistry::RegisterAAFObjects()
{
#include "RegistrationCode.cpp.gen"
}

} // end of namespace diskstream
