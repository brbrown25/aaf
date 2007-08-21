//=---------------------------------------------------------------------=
//
// $Id: TypedVisitor.h,v 1.9 2007/08/21 14:08:10 jptrainor Exp $ $Name:  $
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

#ifndef __TYPEDVISITOR_h__
#define __TYPEDVISITOR_h__

//Analyzer Base files
#include <Visitor.h>

//AAF Analyzer Base files
#include "AAFTypedObjNode.h"

//AAF files
#include <AAF.h>

namespace aafanalyzer {

class AAFContainment;
class AAFComponentReference;
class AAFMobReference;
class AAFSlotReference;

class TypedVisitor : public Visitor
{
  public:

    // Default constructor uses the default Visitor construct
    // (i.e. uses Visitor::FOLLOW_CONTAINED)
    TypedVisitor();


    // Specialize the traversal by using this constructor.
    TypedVisitor( Visitor::Follow_e follow );

    virtual ~TypedVisitor();

    virtual bool EdgeVisit(AAFContainment& edge);
    virtual bool EdgeVisit(AAFComponentReference& edge);
    virtual bool EdgeVisit(AAFMobReference& edge);
    virtual bool EdgeVisit(AAFSlotReference& edge);

#include "TypedVisitor.h.gen"

  private:

    virtual bool DefaultPreOrderBehaviour() { return true; }
    virtual bool DefaultPostOrderBehaviour() { return true; }

    // prohibited
    TypedVisitor( const TypedVisitor& );
    TypedVisitor& operator=( const TypedVisitor& );

};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
