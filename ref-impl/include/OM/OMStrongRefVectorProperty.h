/***********************************************************************
*
*              Copyright (c) 1998-1999 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted,
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
* prior written permission of Avid Technology, Inc.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
* LIABILITY.
*
************************************************************************/

// @doc OMEXTERNAL
#ifndef OMSTRONGREFVECTORPROPERTY_H
#define OMSTRONGREFVECTORPROPERTY_H

#include "OMVector.h"
#include "OMContainerElement.h"

template <typename ReferencedObject>
class OMStrongReferenceVectorIterator;

  // @class Persistent elastic sequential collections of strongly
  //        referenced (contained) objects supported by the Object Manager.
  //        Objects are accessible by index. The order of objects is
  //        determined externally. Duplicate objects are allowed.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @base public | <c OMContainerProperty>
template <typename ReferencedObject>
class OMStrongReferenceVectorProperty : public OMContainerProperty {
public:
  // @access Public members.

    // @cmember Constructor.
  OMStrongReferenceVectorProperty(const OMPropertyId propertyId,
                                  const char* name);

    // @cmember Destructor.
  virtual ~OMStrongReferenceVectorProperty(void);

    // @cmember Save this <c OMStrongReferenceVectorProperty>.
  virtual void save(void* clientContext) const;

    // @cmember Close this <c OMProperty>.
  virtual void close(void);

    // @cmember Restore this <c OMStrongReferenceVectorProperty>, the
    //          external (persisted) size of the
    //          <c OMStrongReferenceVectorProperty> is <p externalSize>.
  virtual void restore(size_t externalSize);

    // @cmember The number of <p ReferencedObject>s in this
    //          <c OMStrongReferenceVectorProperty>.
  size_t count(void) const;

    // @cmember Get the size of this <c OMStrongReferenceVectorProperty>.
  void getSize(size_t& size) const;

    // @cmember Get the size of this <c OMStrongReferenceVectorProperty>.
  size_t getSize(void) const;

    // @cmember Set the value of the <p ReferencedObject> at
    //          position <p index> in this
    //          <c OMStrongReferenceVectorProperty>.
  ReferencedObject* setValueAt(const ReferencedObject* value,
                               const size_t index);

    // @cmember Get the value of the <p ReferencedObject> at
    //          position <p index> in this
    //          <c OMStrongReferenceVectorProperty>.
  void getValueAt(ReferencedObject*& value, const size_t index) const;

    // @cmember Append the given <p ReferencedObject> <p value> to
    //          this <c OMStrongReferenceVectorProperty>.
  void appendValue(const ReferencedObject*& value);

    // @cmember Increase the capacity of this
    //          <c OMStrongReferemceVectorProperty> so that it
    //          can contain at least <p capacity> <p ReferencedObject>s
    //          without having to be resized.
  void grow(const size_t capacity);

  // Optional property interface

    // @cmember Remove this optional <c OMStrongReferenceVectorProperty>.
  virtual void remove(void);

  // Direct property access interface

    // @cmember The size of the raw bits of this
    //          <c OMStrongReferenceVectorProperty>. The size is given
    //          in bytes.
  virtual size_t bitsSize(void) const;

    // @cmember Get the raw bits of this
    //          <c OMStrongReferenceVectorProperty>. The raw bits are
    //          copied to the buffer at address <p bits> which is
    //          <p size> bytes in size.
  virtual void getBits(OMByte* bits, size_t size) const;

    // @cmember Set the raw bits of this
    //          <c OMStrongReferenceVectorProperty>. The raw bits are
    //          copied from the buffer at address <p bits> which is
    //          <p size> bytes in size.
  virtual void setBits(const OMByte* bits, size_t size);

private:

    // The vector of references.
  OMVector<OMVectorElement<OMStrongObjectReference<ReferencedObject>,
                           ReferencedObject> > _vector;

  friend class OMStrongReferenceVectorIterator<ReferencedObject>;

};

#include "OMStrongRefVectorPropertyT.h"

#endif
