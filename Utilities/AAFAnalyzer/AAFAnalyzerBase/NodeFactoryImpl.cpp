//=---------------------------------------------------------------------=
//
// $Id: NodeFactoryImpl.cpp,v 1.1 2005/07/13 16:47:56 greek_fire Exp $
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


#include "NodeFactoryImpl.h"

#include "TypedNodeFactoryImpl.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer {

NodeFactoryImpl::NodeFactoryImpl()
{
}

NodeFactoryImpl::~NodeFactoryImpl()
{
}

boost::shared_ptr<Node> NodeFactoryImpl::CreateNode(IAAFObjectSP spObj)
{
  // First, check the registry for a node factory support the specific
  // AAF object type.
  
  // To Be Completed

  // If no factory object exists for the AAF object in question,
  // therefore, we simply instantiate TypeNodeFactoryImpl on
  // IAAFObject.
  boost::shared_ptr<TypedNodeFactory> spNodeFactory(new TypedNodeFactoryImpl<IAAFObject>());

  return spNodeFactory->CreateNode(spObj);
}

} // end of namespace diskstream
