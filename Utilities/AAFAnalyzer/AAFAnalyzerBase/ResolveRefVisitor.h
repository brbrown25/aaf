//=---------------------------------------------------------------------=
//
// $Id: ResolveRefVisitor.h,v 1.1 2005/08/05 20:15:46 greek_fire Exp $
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

#ifndef __RESOLVEREFVISITOR_h__
#define __RESOLVEREFVISITOR_h__

#include "TypedVisitor.h"

//boost files
#include <boost/shared_ptr.hpp>

namespace aafanalyzer {

class Edge;
class EdgeMap;

class ResolveRefVisitor : public TypedVisitor
{
 public:
  ResolveRefVisitor(boost::shared_ptr<EdgeMap> spEdgeMap);
  virtual ~ResolveRefVisitor();

  virtual bool PostOrderVisit(AAFTypedObjNode<IAAFSourceClip>& node);
  virtual bool EdgeVisit(Edge& edge);

 private:

  boost::shared_ptr<EdgeMap> _spEdgeMap;

  // prohibited
  ResolveRefVisitor( const ResolveRefVisitor& );
  ResolveRefVisitor& operator=( const ResolveRefVisitor& );
};

} // end of namespace diskstream

#endif
