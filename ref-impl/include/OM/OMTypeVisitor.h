//=---------------------------------------------------------------------=
//
// $Id: OMTypeVisitor.h,v 1.1 2007/02/06 15:46:11 wschilp Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
#ifndef OMTYPEVISITOR_H
#define OMTYPEVISITOR_H

#include "OMType.h"

#include "OMSet.h"

class OMIntegerType;
class OMCharacterType;
class OMStrongObjectReferenceType;
class OMWeakObjectReferenceType;
class OMRenamedType;
class OMEnumeratedType;
class OMFixedArrayType;
class OMVaryingArrayType;
class OMSetType;
class OMRecordType;
class OMStreamType;
class OMStringType;
class OMExtendibleEnumeratedType;
class OMIndirectType;
class OMOpaqueType;

template <typename Key, typename Element>
class OMSet;

// @author Tim Bingham | tjb | Avid Technology, Inc. | OMTypeVisitor
class OMTypeVisitor {
public:

  virtual ~OMTypeVisitor(void) {};

  virtual void visitIntegerType(const OMIntegerType* type) = 0;

  virtual void visitCharacterType(const OMCharacterType* type) = 0;

  virtual void visitStrongObjectReferenceType(
                                  const OMStrongObjectReferenceType* type) = 0;

  virtual void visitWeakObjectReferenceType(
                                    const OMWeakObjectReferenceType* type) = 0;

  virtual void visitRenamedType(const OMRenamedType* type) = 0;

  virtual void visitEnumeratedType(const OMEnumeratedType* type) = 0;

  virtual void visitFixedArrayType(const OMFixedArrayType* type) = 0;

  virtual void visitVaryingArrayType(const OMVaryingArrayType* type) = 0;

  virtual void visitSetType(const OMSetType* type) = 0;

  virtual void visitRecordType(const OMRecordType* type) = 0;

  virtual void visitStreamType(const OMStreamType* type) = 0;

  virtual void visitStringType(const OMStringType* type) = 0;

  virtual void visitExtendibleEnumeratedType(
                                   const OMExtendibleEnumeratedType* type) = 0;

  virtual void visitIndirectType(const OMIndirectType* type) = 0;

  virtual void visitOpaqueType(const OMOpaqueType* type) = 0;

};

// @author Tim Bingham | tjb | Avid Technology, Inc. | OMTypeCollector
class TypeCollector : public OMTypeVisitor {
public:
  TypeCollector(OMSet<OMUniqueObjectIdentification,
                const OMType*>& types);

  virtual void visitIntegerType(const OMIntegerType* type);

  virtual void visitCharacterType(const OMCharacterType* type);

  virtual void visitStrongObjectReferenceType(
                                      const OMStrongObjectReferenceType* type);

  virtual void visitWeakObjectReferenceType(
                                        const OMWeakObjectReferenceType* type);

  virtual void visitRenamedType(const OMRenamedType* type);

  virtual void visitEnumeratedType(const OMEnumeratedType* type);

  virtual void visitFixedArrayType(const OMFixedArrayType* type);

  virtual void visitVaryingArrayType(const OMVaryingArrayType* type);

  virtual void visitSetType(const OMSetType* type);

  virtual void visitRecordType(const OMRecordType* type);

  virtual void visitStreamType(const OMStreamType* type);

  virtual void visitStringType(const OMStringType* type);

  virtual void visitExtendibleEnumeratedType(
                                       const OMExtendibleEnumeratedType* type);

  virtual void visitIndirectType(const OMIndirectType* type);

  virtual void visitOpaqueType(const OMOpaqueType* type);

protected:

  virtual void add(const OMType* type);

private:
  OMSet<OMUniqueObjectIdentification,
        const OMType*>& _types;
};

#endif
