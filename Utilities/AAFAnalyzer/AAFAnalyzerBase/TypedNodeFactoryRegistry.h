//=---------------------------------------------------------------------=
//
// $Id: TypedNodeFactoryRegistry.h,v 1.1 2005/07/13 16:47:56 greek_fire Exp $
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

#ifndef __TYPEDNODEFACTORYREGISTRY_h__
#define __TYPEDNODEFACTORYREGISTRY_h__

//project files

//AAF files
#include <AAFTypes.h>

//boost files
#include <boost/shared_ptr.hpp>

//STL files
#include <map>

namespace aafanalyzer {

class TypedNodeFactory;

class TypedNodeFactoryRegistry
{
 public:
  // dtor must be public so that shared_ptr class can access it
  ~TypedNodeFactoryRegistry();

  bool IsPresent(aafUID_t AUID);
  bool Deregister(aafUID_t AUID);
  TypedNodeFactoryRegistry& GetInstance();
  boost::shared_ptr<TypedNodeFactory> LookUp(aafUID_t AUID);
  void Register(aafUID_t AUID, boost::shared_ptr<TypedNodeFactory> spFactory);  

 private:
  //using Singleton pattern to allow only one object
  TypedNodeFactoryRegistry();

  static TypedNodeFactoryRegistry* _pFactory;
  std::map<aafUID_t, boost::shared_ptr<TypedNodeFactory> > _pMap;  

  // prohibited
  //TypedNodeFactoryRegistry( const TypedNodeFactoryRegistry& );
  //TypedNodeFactoryRegistry& operator=( const TypedNodeFactoryRegistry& );
};

} // end of namespace diskstream

#endif/*__TYPEDNODEFACTORYREGISTRY_h__*/
