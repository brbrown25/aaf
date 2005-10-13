//=---------------------------------------------------------------------=
//
// $Id: GraphBuilder.h,v 1.3 2005/10/13 19:33:58 ajakowpa Exp $
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

#ifndef __GRAPHBUILDER_h__
#define __GRAPHBUILDER_h__

//Boost files
#include <boost/shared_ptr.hpp>

//Ax files
#include <AxTypes.h>

namespace aafanalyzer {

using namespace boost;

class AAFGraphInfo;
class NodeFactory;

class GraphBuilder
{

 public:
  GraphBuilder();
  ~GraphBuilder();

  const shared_ptr<const AAFGraphInfo> CreateGraph(const AxString& fileName, shared_ptr<NodeFactory> spFactory );

 private:  

  // prohibited
  GraphBuilder( const GraphBuilder& );
  GraphBuilder& operator=( const GraphBuilder& );
};

} // end of namespace diskstream

#endif
