//=---------------------------------------------------------------------=
//
// $Id: ResolveRefVisitor.cpp,v 1.3 2005/08/18 20:38:00 greek_fire Exp $
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

ResolveRefVisitor::ResolveRefVisitor(std::ostream& os, boost::shared_ptr<EdgeMap> spEdgeMap, TestResult& result)
: _os(os),
  _spEdgeMap(spEdgeMap),
  _Result(result)
{
}

ResolveRefVisitor::~ResolveRefVisitor()
{
}

bool ResolveRefVisitor::PostOrderVisit(AAFTypedObjNode<IAAFSourceClip>& node)
{
  AxSourceClip axSrcClp(node.GetAAFObjectOfType());

  try 
  {
    aafSourceRef_t srcRef = axSrcClp.GetSourceReference();
    aafMobID_t mobid = srcRef.sourceID;
    
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
      }
    }
    //keep track of unresolved source clips
    else
    {
      //_OutStream << "SourceClip with id: " << node.GetLID() << " does not reference any mob. << std::endl;
    }

    return true;
  }
  catch (const AxExHResult& ex)
  {
    if (ex.getHResult() == AAFRESULT_NOT_INITIALIZED)
    {
       // FIXME - track this for later reporting
       return true;
    }
  }

  return false;
}

bool ResolveRefVisitor::EdgeVisit(Edge& edge)
{
  return true;
}

}
