//=---------------------------------------------------------------------=
//
// $Id: AAFTypedObjNode.h,v 1.6 2005/11/14 19:46:50 ajakowpa Exp $
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

#ifndef __AAFTYPEDOBJNODE_h__
#define __AAFTYPEDOBJNODE_h__

//AAF Analyzer Base files
#include "AAFObjNode.h"
#include "TypedNodeFactoryRegistry.h"
#include "TypedNodeFactory.h"

//Ax files
#include <AxSmartPointer.h>
#include <AxDictionary.h>
#include <AxMetaDef.h>

namespace aafanalyzer {

using namespace std;
using namespace boost;

template<typename AAFObjType>
class AAFTypedObjNode : public AAFObjNode
{
 public:
  ~AAFTypedObjNode();
  
  virtual IAAFSmartPointer<AAFObjType> GetAAFObjectOfType() const =0;
  
  //This function will return a new node and all type information about the
  //actual type of the templated parameter will be lost.  Therefore, this node
  //should not be stored anywhere unless it is acceptable to use the node
  //without complete type information.
  template<typename To>
  shared_ptr<AAFTypedObjNode<To> > DownCast()
  {

    //Get the dictionary.
    AxObject axObj( this->GetAAFObject() );
    AxDictionary axDictionary( axObj.GetDictionary() );

    //Find the class definition of the class to cast to.
    To* pTo = NULL;
    AxClassDef clsDef( axDictionary.LookupClassDef( AxAUID(pTo) ) );

    //Find the TypedNodeFactory for the class to cast to.
    shared_ptr<TypedNodeFactory> spNodeFactory;
    spNodeFactory = TypedNodeFactoryRegistry::GetInstance().LookUp(clsDef);
    
    //Get a shared pointer to this node.
    shared_ptr<AAFObjNode> spThis = 
        dynamic_pointer_cast<AAFObjNode>( this->GetSharedPointerToNode() );

    //Return the casted node.  If the cast is not legal, the node factory will
    //throw an exception.
    return dynamic_pointer_cast<AAFTypedObjNode<To> > ( spNodeFactory->CreateNodeFrom( spThis ) );

  }

 protected:
  AAFTypedObjNode(IAAFSmartPointer<AAFObjType> ObjectType,
          const basic_string<wchar_t>& name );
  AAFTypedObjNode( IAAFSmartPointer<AAFObjType> ObjectType,
          shared_ptr<Node> spExistingNode );

 private:

  //prohibited
  AAFTypedObjNode();
  AAFTypedObjNode( const AAFTypedObjNode& );
  AAFTypedObjNode& operator=( const AAFTypedObjNode& );

};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
