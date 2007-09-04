//=---------------------------------------------------------------------=
//
// $Id: ResolveRefVisitor.h,v 1.7 2007/09/04 17:28:23 jptrainor Exp $
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

//TestPhaseLib files
#include <TestLevelTestResult.h>

//AAF Analyzer Base files
#include <TypedVisitor.h>

//AAF files
#include <AAFSmartPointer2.h>

//STL files
#include <vector>

class AxSourceClip;
class AxSegment;
class AxComponent;
class AxTimelineMobSlot;
class AxEventMobSlot;
class AxMobSlot;

namespace aafanalyzer {

using namespace std;
using namespace boost;

class Edge;
class EdgeMap;
class DetailLevelTestResult;

class ResolveRefVisitor : public TypedVisitor
{
 public:
  ResolveRefVisitor(wostream& os,
		    shared_ptr<EdgeMap> spEdgeMap,
		    shared_ptr<TestLevelTestResult> spTestLevelResult );
  virtual ~ResolveRefVisitor();

  virtual bool PostOrderVisit(AAFTypedObjNode<IAAFSourceClip>& node);

 private:

  shared_ptr<Node> ResolveChildSlotNode( shared_ptr<EdgeMap> spEdgeMap,
					 shared_ptr<Node> spParentMobNode,
					 IAAFMobSP spParentIaafMob,
					 const aafSlotID_t slotId );

  shared_ptr<vector<shared_ptr<Node> > > GetContainedChildComponents( shared_ptr<Node> spMobSlotNode );

  wostream& _os;
  shared_ptr<EdgeMap> _spEdgeMap;
  shared_ptr<DetailLevelTestResult> _spResult;

  // prohibited
  ResolveRefVisitor();
  ResolveRefVisitor( const ResolveRefVisitor& );
  ResolveRefVisitor& operator=( const ResolveRefVisitor& );

  shared_ptr<TestLevelTestResult> _spTestLevelResult;
};

} // end of namespace diskstream

#endif
