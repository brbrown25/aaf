//=---------------------------------------------------------------------=
//
// $Id: TypedVisitor.h,v 1.4 2005/07/26 16:30:16 greek_fire Exp $ $Name:  $
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

//project files
#include "Visitor.h"
#include "AAFTypedObjNode.h"

//AAF files
#include <AAF.h>

//boost files
#include <boost/shared_ptr.hpp>

namespace aafanalyzer {

class AAFContainment;
class AAFComponentReference;
class AAFMobReference;
class AAFSlotReference;


class TypedVisitor : public Visitor
{
  public:
    TypedVisitor();
    virtual ~TypedVisitor();

    virtual bool EdgeVisit(AAFContainment& edge) { return true; }
    virtual bool EdgeVisit(AAFComponentReference& edge) { return true; }
    virtual bool EdgeVisit(AAFMobReference& edge) { return true; }
    virtual bool EdgeVisit(AAFSlotReference& edge) { return true; }

#include "TypedVisitor.h.gen"
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
