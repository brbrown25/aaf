//=---------------------------------------------------------------------=
//
// $Id: ResolveRefVisitor.cpp,v 1.6 2005/09/05 00:50:45 jptrainor Exp $
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

#include "ResolveRefVisitor.h"

#include "AAFMobReference.h"
#include "AAFSlotReference.h"
#include "EdgeMap.h"
#include "MobNodeMap.h"
#include "TempAllNodeMap.h"

//Ax files
#include <AxMobSlot.h>
#include <AxComponent.h>
#include <AAFResult.h>
#include <AxUtil.h>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================
namespace aafanalyzer {

ResolveRefVisitor::ResolveRefVisitor(std::ostream& os, boost::shared_ptr<EdgeMap> spEdgeMap )
: _os(os),
  _spEdgeMap(spEdgeMap),
  _spResult( new TestResult( L"ResolveRefVisitor",
			     L"Visit source clip objects and resolve references..",
			     L"-",
			     L"-",
			     TestResult::PASS ) )
{}

ResolveRefVisitor::~ResolveRefVisitor()
{
}

bool ResolveRefVisitor::PostOrderVisit(AAFTypedObjNode<IAAFSourceClip>& node)
{
  AxSourceClip axSrcClp(node.GetAAFObjectOfType());

  aafSourceRef_t srcRef = axSrcClp.GetSourceReference();
  aafMobID_t mobid = srcRef.sourceID;

  if ( AxConstants::NULL_MOBID == mobid )
  {
    return true;
  }
    
  boost::shared_ptr<Node> spNode;
  spNode = MobNodeMap::GetInstance().GetMobNode(mobid);
	
  //Assert it really is a mob. (i.e. to verify the MobNodeMap is delivering good data.)
  //Then resolve the reference.
  if(spNode)
  {
    //verify mob
    IAAFMobSP spVerify;
    boost::shared_ptr<AAFObjNode> spObjNode;
    spObjNode = boost::dynamic_pointer_cast<AAFObjNode>(spNode);
    AxObject axObj(spObjNode->GetAAFObject());
    assert(AxIsA(axObj, spVerify));
    
    //mob has been verified, proceed to the sourceclip
    boost::shared_ptr<AAFTypedObjNode<IAAFSourceClip> > spSrcClp;
    spSrcClp = boost::dynamic_pointer_cast<AAFTypedObjNode<IAAFSourceClip> >(TempAllNodeMap::GetInstance().GetNode(node.GetLID()));
    
    //ensure we have the two proper nodes (spNode, spSrcClp), create a Mob Edge and add to Edgemap
    if(spSrcClp)
    {
      boost::shared_ptr<AAFMobReference> spMobRefEdge(new AAFMobReference(spSrcClp, spNode)); 
      _spEdgeMap->AddEdge(spMobRefEdge);
      
      //now create a Slot Edge from the source clip to the mobslot and add to Edgemap
      boost::shared_ptr<AAFTypedObjNode<IAAFTimelineMobSlot> > spMobSlotNode;
      EdgeMap::EdgeVectorSP mobChildren = _spEdgeMap->GetChildren(spNode);
      
      for(unsigned int i = 0; i < mobChildren->size(); i++)
      {
	spMobSlotNode = boost::dynamic_pointer_cast<AAFTypedObjNode<IAAFTimelineMobSlot> >(mobChildren->at(i)->GetChildNode());
	
	if(spMobSlotNode)
	{
	  AxTimelineMobSlot axMobSlot(spMobSlotNode->GetAAFObjectOfType());
	  aafSlotID_t slotid = srcRef.sourceSlotID;
	  
	  if(axMobSlot.GetSlotID() == slotid)
	  {
	    boost::shared_ptr<AAFSlotReference> spSlotEdge(new AAFSlotReference(spSrcClp, spMobSlotNode));
	    _spEdgeMap->AddEdge(spSlotEdge);
	  }
	}
      }
      
      // TODO - The next level of reference detail is to create the
      // edges from the source clip to components ultimately
      // references. The may be multiple referenced components in
      // the event that the source clips points to a sequence.
      
    }
  }
  //keep track of unresolved source clips
  else
  {
    AxString explain( L"Out-file mob referenced. ID = " );
    explain += AxStringUtil::mobid2Str( mobid );
    boost::shared_ptr<TestResult> spWarning( new TestResult( _spResult->GetName(),
							     L"-", // desc
							     explain,
							     L"-", // docref
							     TestResult::WARN ) );
    _spResult->AppendSubtestResult( spWarning );
  }

  return true;
}

bool ResolveRefVisitor::EdgeVisit(Edge& edge)
{
  return true;
}

boost::shared_ptr<const TestResult> ResolveRefVisitor::GetTestResult() const
{
  return _spResult;
}

}
