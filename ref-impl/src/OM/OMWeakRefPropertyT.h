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
#ifndef OMWEAKREFPROPERTYT_H
#define OMWEAKREFPROPERTYT_H

#include "OMAssertions.h"
#include "OMPropertyTable.h"

template<typename ReferencedObject>
OMWeakReferenceProperty<ReferencedObject>::OMWeakReferenceProperty(
                                              const OMPropertyId propertyId,
                                              const char* name,
                                              const char* targetName,
                                              const OMPropertyId keyPropertyId)
: OMReferenceProperty<ReferencedObject>(propertyId,
                                        SF_WEAK_OBJECT_REFERENCE,
                                        name), _reference(this),
  _targetTag(nullOMPropertyTag),
  _targetName(saveString(targetName)),
  _keyPropertyId(keyPropertyId)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::OMWeakReferenceProperty");
}

template<typename ReferencedObject>
OMWeakReferenceProperty<ReferencedObject>::~OMWeakReferenceProperty(void)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::~OMWeakReferenceProperty");
  delete [] _targetName;
}

  // @mfunc Get the value of this <c OMWeakReferenceProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (pointed to) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm A pointer to a <p ReferencedObject> by reference.
  //   @this const
template<typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::getValue(
                                               ReferencedObject*& object) const
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::getValue");
  PRECONDITION("Optional property is present",
                                           IMPLIES(isOptional(), isPresent()));

  ReferencedObject* result = _reference.getValue();

  object = result;

}

  // @mfunc Set the value of this <c OMWeakReferenceProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm A pointer to the new <p ReferencedObject>.
  //   @rdesc A pointer to the old <p ReferencedObject>. If lazy
  //          loading is enabled and the referenced object was never
  //          loaded the value returned is 0.
template <typename ReferencedObject>
ReferencedObject* OMWeakReferenceProperty<ReferencedObject>::setValue(
                                               const ReferencedObject* object)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::setValue");

  ReferencedObject* result = _reference.setValue(object);
  setPresent();
  return result;
}

  // @mfunc Assignment operator.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (pointed to) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @rdesc The result of the assignment.
  //   @parm A pointer to a <p ReferencedObject> by value.
template<typename ReferencedObject>
OMWeakReferenceProperty<ReferencedObject>&
OMWeakReferenceProperty<ReferencedObject>::operator = (
                                                 const ReferencedObject* value)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::operator =");

  setValue(value);
  return *this;
}

  // @mfunc Dereference operator.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>
  //   @rdesc A pointer to a <p ReferencedObject> by value.
template<typename ReferencedObject>
ReferencedObject*
OMWeakReferenceProperty<ReferencedObject>::operator -> (void)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::operator ->");

  return _reference.getValue();
}

template<typename ReferencedObject>
const ReferencedObject*
OMWeakReferenceProperty<ReferencedObject>::operator -> (void) const
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::operator ->");

  return _reference.getValue();
}

  // @mfunc Type conversion. Convert an
  //        <c OMWeakReferenceProperty> into a pointer to the
  //        referenced (pointed to) <p ReferencedObject>.
  //   @rdesc The result of the conversion as a value of type
  //          pointer to <p ReferencedObject>.
  //   @this const
template<typename ReferencedObject>
OMWeakReferenceProperty<ReferencedObject>::operator ReferencedObject* () const
{
  TRACE(
      "OMWeakReferenceProperty<ReferencedObject>::operator ReferencedObject*");

  ReferencedObject* result;
  getValue(result);
  return result;
}

  // @mfunc Save this <c OMWeakReferenceProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (pointed to) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @this const
template<typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::save(void) const
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::save");

  PRECONDITION("Non-void weak reference", !_reference.isVoid());

  ASSERT("Valid property set", _propertySet != 0);
  OMStorable* container = _propertySet->container();
  ASSERT("Valid container", container != 0);
  ASSERT("Container is persistent", container->persistent());
  OMStoredObject* store = container->store();

  OMFile* file = container->file();
  OMPropertyTag tag = file->referencedProperties()->insert(_targetName);

  const OMUniqueObjectIdentification& id = _reference.identification();
  store->save(_propertyId, _storedForm, id, tag, _keyPropertyId);

  _reference.save();
}

  // @mfunc Close this <c OMWeakReferenceProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
template <typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::close(void)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::close");
  // tjb
}

  // @mfunc Restore this <c OMWeakReferenceProperty>, the external
  //        (persisted) size of the <c OMWeakReferenceProperty> is
  //        <p externalSize>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (pointed to) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The external (persisted) size of the <c OMWeakReferenceProperty>.
template<typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::restore(size_t externalSize)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::restore");

  ASSERT("Valid property set", _propertySet != 0);
  OMStorable* container = _propertySet->container();
  ASSERT("Valid container", container != 0);
  ASSERT("Container is persistent", container->persistent());
  OMStoredObject* store = container->store();
  ASSERT("Valid store", store != 0);

  OMUniqueObjectIdentification id;
  OMPropertyTag tag;
  ASSERT("Sizes match", (sizeof(tag) + sizeof(OMPropertyId) +
                         sizeof(OMKeySize) + sizeof(id)) == externalSize);
  OMPropertyId keyPropertyId;
  store->restore(_propertyId, _storedForm, id, tag, keyPropertyId);
  ASSERT("Consistent key property ids", keyPropertyId == _keyPropertyId);
  _targetTag = tag;
  _reference = OMWeakObjectReference<ReferencedObject>(this, id, _targetTag);
  _reference.restore();
  setPresent();
}

  // @mfunc  Is this <c OMWeakReferenceProperty> void ?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @rdesc True if this <c OMWeakReferenceProperty> is void, false
  //          otherwise
  //   @this const
template<typename ReferencedObject>
bool OMWeakReferenceProperty<ReferencedObject>::isVoid(void) const
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::isVoid");

  bool result;
  const OMUniqueObjectIdentification& key = _reference.identification();
  if (key == nullOMUniqueObjectIdentification) {
    result = true;
  } else {
    result = false;
  }

  return result;
}

  // @mfunc Get the raw bits of this <c OMWeakReferenceProperty>. The raw bits
  //        are copied to the buffer at address <p bits> which is
  //        <p size> bytes in size.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          object. This type must be a descendant of <c OMStorable>.
  //   @parm The address of the buffer into which the raw bits are copied.
  //   @parm The size of the buffer.
  //   @this const
template<typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::getBits(OMByte* bits,
                                                    size_t size) const
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::getBits");
  PRECONDITION("Optional property is present",
                                           IMPLIES(isOptional(), isPresent()));
  PRECONDITION("Valid bits", bits != 0);
  PRECONDITION("Valid size", size >= bitsSize());

  ReferencedObject* pointer;
  getValue(pointer);

  memcpy(bits, &pointer, bitsSize());
}

  // @mfunc Set the raw bits of this <c OMWeakReferenceProperty>. The raw
  //        bits are copied from the buffer at address <p bits> which
  //        is <p size> bytes in size.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          object. This type must be a descendant of <c OMStorable>.
  //   @parm The address of the buffer into which the raw bits are copied.
  //   @parm The size of the buffer.
template<typename ReferencedObject>
void OMWeakReferenceProperty<ReferencedObject>::setBits(const OMByte* bits,
                                                    size_t size)
{
  TRACE("OMWeakReferenceProperty<ReferencedObject>::getBits");
  PRECONDITION("Valid bits", bits != 0);
  PRECONDITION("Valid size", size >= bitsSize());

  const ReferencedObject* p = *(const ReferencedObject**)bits;
  setValue(p);
}

#endif
