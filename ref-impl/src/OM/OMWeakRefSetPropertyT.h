//=---------------------------------------------------------------------=
//
// $Id: OMWeakRefSetPropertyT.h,v 1.67 2006/06/15 19:53:21 tbingham Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2006, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. |
//         OMWeakReferenceSetProperty
#ifndef OMWEAKREFSETPROPERTYT_H
#define OMWEAKREFSETPROPERTYT_H

#include "OMAssertions.h"
#include "OMWeakReferenceSetIter.h"
#include "OMPropertyTable.h"
#include "OMUtilities.h"
#include "OMStoredObject.h"
#include "OMStrongReferenceSet.h"

  // @mfunc Constructor.
  //   @parm The property id.
  //   @parm The name of this <c OMWeakReferenceSetProperty>.
  //   @parm The name (as a string) of the the <c OMProperty> instance
  //         (a set property) in which the objects referenced by the
  //         elements of this <c OMWeakReferenceSetProperty> reside.
  //   @parm The id of the property by which the <p ReferencedObject>s
  //         are uniquely identified (the key).
template <typename ReferencedObject>
OMWeakReferenceSetProperty<ReferencedObject>::
                   OMWeakReferenceSetProperty(const OMPropertyId propertyId,
                                              const wchar_t* name,
                                              const wchar_t* targetName,
                                              const OMPropertyId keyPropertyId)
: OMWeakReferenceSet(propertyId, name),
  _targetTag(nullOMPropertyTag),
  _targetName(targetName),
  _targetPropertyPath(0),
  _keyPropertyId(keyPropertyId),
  _targetSet(0)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::"
                                                 "OMWeakReferenceSetProperty");
}

  // @mfunc Constructor.
  //   @parm The property id.
  //   @parm The name of this <c OMWeakReferenceSetProperty>.
  //   @parm The id of the property by which the <p ReferencedObject>s
  //         are uniquely identified (the key).
  //   @parm The name (as a list of pids) of the the <c OMProperty> instance
  //         (a set property) in which the objects referenced by the
  //         elements of this <c OMWeakReferenceSetProperty> reside.
template <typename ReferencedObject>
OMWeakReferenceSetProperty<ReferencedObject>::OMWeakReferenceSetProperty(
                                        const OMPropertyId propertyId,
                                        const wchar_t* name,
                                        const OMPropertyId keyPropertyId,
                                        const OMPropertyId* targetPropertyPath)
: OMWeakReferenceSet(propertyId, name),
  _targetTag(nullOMPropertyTag),
  _targetName(0),
  _targetPropertyPath(0),
  _keyPropertyId(keyPropertyId),
  _targetSet(0)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::"
                                                 "OMWeakReferenceSetProperty");

  _targetPropertyPath = savePropertyPath(targetPropertyPath);
}

  // @mfunc Destructor.
template <typename ReferencedObject>
OMWeakReferenceSetProperty<ReferencedObject>::~OMWeakReferenceSetProperty(void)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::"
                                                "~OMWeakReferenceSetProperty");

  delete [] _targetPropertyPath;
}

  // @mfunc Save this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @this const
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::save(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::save");

  PRECONDITION("Optional property is present",
                                           IMPLIES(isOptional(), isPresent()));

  store()->save(*this);
}

  // @mfunc Close this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::close(void)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::close");

  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    element.close();
  }
}

  // @mfunc Detach this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::detach(void)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::detach");

  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    element.detach();
  }
}

  // @mfunc Restore this <c OMWeakReferenceSetProperty>, the external
  //        (persisted) size of the <c OMWeakReferenceSetProperty> is
  //        <p externalSize>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The external (persisted) size of the
  //         <c OMWeakReferenceSetProperty>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::restore(
                                                   OMPropertySize externalSize)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::restore");

  store()->restore(*this, externalSize);
  setPresent();
}

  // @mfunc The number of objects contained within this
  //        <c OMWeakReferenceSetProperty> if any.
  //   @rdesc The number of objects.
template <typename ReferencedObject>
OMUInt64
OMWeakReferenceSetProperty<ReferencedObject>::objectCount(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::objectCount");
  // OMWeakReferenceProperty doesn't contain objects.
  return 0;
}

  // @mfunc The number of <p ReferencedObject>s in this
  //        <c OMWeakReferenceSetProperty>.
  //   @this const
template <typename ReferencedObject>
OMUInt32 OMWeakReferenceSetProperty<ReferencedObject>::count(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::count");

  return _set.count();
}

  // @mfunc Insert <p object> into this
  //        <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The object to insert.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::insert(
                                                const ReferencedObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::insert");

  PRECONDITION("Valid object", object != 0);
  PRECONDITION("Object is not present", !containsValue(object));
#if defined(OM_VALIDATE_WEAK_REFERENCES)
  PRECONDITION("Source container object attached to file",
                                                        container()->inFile());
  PRECONDITION("Target object attached to file", object->inFile());
  PRECONDITION("Source container object and target object in same file",
                                        container()->file() == object->file());
  PRECONDITION("Valid target object", targetSet()->containsObject(object));
#endif
  // Set the set to contain the new object
  //
  OMUniqueObjectIdentification key = object->identification();
  SetElement newElement(this, key, _targetTag);
#if defined(OM_VALIDATE_WEAK_REFERENCES)
  newElement.reference().setTargetTag(targetTag());
#endif
  newElement.setValue(key, object);
  _set.insert(key, newElement);
  setPresent();

  POSTCONDITION("Object is present", containsValue(object));
  //POSTCONDITION("Optional property is present", isPresent());
}

  // @mfunc If it is not already present, insert <p object> into this
  //        <c OMWeakReferenceSetProperty> and return true,
  //        otherwise return false.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The object to insert.
  //   @rdesc True if the object was inserted, false if it was already present.
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::ensurePresent(
                                                const ReferencedObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::ensurePresent");

  PRECONDITION("Valid object", object != 0);

  // tjb - Current cost is 2 * O(lg N) this should be halved to
  //       O(lg N) by implementing an ensurePresent() on OMSet.
  bool present = containsValue(object);
  if (!present) {
    insert(object);
  }
  POSTCONDITION("Object is present", containsValue(object));
  return !present;
}

  // @mfunc Append the given <p ReferencedObject> <p object> to
  //        this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm A pointer to a <p ReferencedObject>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::appendValue(
                                                const ReferencedObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::appendValue");
  PRECONDITION("Valid object", object != 0);

  OBSOLETE("OMWeakReferenceSetProperty<ReferencedObject>::insert");
  insert(object);
  POSTCONDITION("Object is present", containsValue(object));
}

  // @mfunc Remove the <p ReferencedObject> identified by
  //        <p identification> from this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The unique identification of the object to be removed, the
  //         search key.
  //   @rdesc A pointer to the removed <p ReferencedObject>. If lazy
  //          loading is enabled and the referenced object was never
  //          loaded the value returned is 0.
template <typename ReferencedObject>
ReferencedObject*
OMWeakReferenceSetProperty<ReferencedObject>::remove(
                            const OMUniqueObjectIdentification& identification)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::remove");

  PRECONDITION("Object is present", contains(identification));

  SetElement* element = 0;
#if defined(OM_DEBUG)
  bool found =
#endif
  _set.find(identification, &element);
  ASSERT("Object found", found);
  OMStorable* p = element->setValue(nullOMUniqueObjectIdentification, 0);
  ReferencedObject* result = 0;
  if (p != 0) {
    result = dynamic_cast<ReferencedObject*>(p);
    ASSERT("Object is correct type", result != 0);
  }
  _set.remove(identification);

  POSTCONDITION("Object is not present", !contains(identification));

  return result;
}

  // @mfunc If it is present, remove the <p ReferencedObject> identified by
  //        <p identification> from this <c OMWeakReferenceSetProperty>
  //        and return true, otherwise return false.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The object to remove.
  //   @rdesc True if the object was removed, false if it was already absent.
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::ensureAbsent(
                            const OMUniqueObjectIdentification& identification)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::ensureAbsent");

  SetElement* element = 0;
  bool result = _set.find(identification, &element);
  if (result) {
    element->setValue(nullOMUniqueObjectIdentification, 0);
    _set.remove(identification);
  }

  POSTCONDITION("Object is not present", !contains(identification));
  return result;
}

  // @mfunc Remove <p object> from this
  //        <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm A pointer to a <p ReferencedObject>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::removeValue(
                                                const ReferencedObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::removeValue");

  PRECONDITION("Valid object", object != 0);
  PRECONDITION("Object is present", containsValue(object));

  OMUniqueObjectIdentification identification = object->identification();
  remove(identification);

  POSTCONDITION("Object is not present", !containsValue(object));
}

  // @mfunc If it is present, remove <p object> from this
  //        <c OMWeakReferenceSetProperty> and return true,
  //        otherwise return false.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The object to remove.
  //   @rdesc True if the object was removed, false if it was already absent.
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::ensureAbsent(
                                                const ReferencedObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::ensureAbsent");

  PRECONDITION("Valid object", object != 0);

  OMUniqueObjectIdentification identification = object->identification();
  bool result = ensureAbsent(identification);

  POSTCONDITION("Object is not present", !containsValue(object));
  return result;
}

  // @mfunc Does this <c OMWeakReferenceSetProperty> contain
  //        <p object> ?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm A pointer to a <p ReferencedObject>.
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::containsValue(
                                          const ReferencedObject* object) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::containsValue");
  PRECONDITION("Valid object", object != 0);

  bool result = _set.contains(object->identification());
  return result;
}

  // @mfunc Does this <c OMWeakReferenceSetProperty> contain a
  //        <p ReferencedObject> identified by <p identification>?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The unique identification of the desired object, the search key.
  //   @rdesc True if the object is found, false otherwise.
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::contains(
                      const OMUniqueObjectIdentification& identification) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::contains");

  return _set.contains(identification);
}

  // @mfunc The <p ReferencedObject> in this
  //        <c OMWeakReferenceSetProperty> identified by
  //        <p identification>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The unique identification of the desired object, the search key.
  //   @rdesc A pointer to the <p ReferencedObject>.
  //   @this const
template <typename ReferencedObject>
ReferencedObject* OMWeakReferenceSetProperty<ReferencedObject>::value(
                     const OMUniqueObjectIdentification& identification) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::value");

  PRECONDITION("Object is present", contains(identification));

  SetElement* element = 0;

  _set.find(identification, &element);
  OMStorable* p = element->getValue();
  ReferencedObject* result = 0;
  if (p != 0) {
    result = dynamic_cast<ReferencedObject*>(p);
    ASSERT("Object is correct type", result != 0);
  }

  POSTCONDITION("Valid result", result != 0);
  return result;
}

  // @mfunc Find the <p ReferencedObject> in this
  //        <c OMWeakReferenceSetProperty> identified by
  //        <p identification>.  If the object is found it is returned
  //        in <p object> and the result is true. If the element is
  //        not found the result is false.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @parm The unique identification of the desired object, the search key.
  //   @parm A pointer to a <p ReferencedObject> by reference.
  //   @rdesc True if the object is found, false otherwise.
  //   @this const
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::find(
                            const OMUniqueObjectIdentification& identification,
                            ReferencedObject*& object) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::find");

  SetElement* element = 0;

  bool result = _set.find(identification, &element);
  if (result) {
    OMStorable* p = element->getValue();
    if (p != 0) {
      object = dynamic_cast<ReferencedObject*>(p);
      ASSERT("Object is correct type", object != 0);
    } else {
      object = 0;
    }
  }

  return result;
}

  // @mfunc Is this <c OMWeakReferenceSetProperty> void ?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @rdesc True if this <c OMWeakReferenceSetProperty> is void,
  //          false otherwise.
  //   @this const
template <typename ReferencedObject>
bool OMWeakReferenceSetProperty<ReferencedObject>::isVoid(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::isVoid");

  bool result = true;

  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    OMStorable* object = element.getValue();
    if (object != 0) {
      result = false;
      break;
    }
  }
  return result;
}

  // @mfunc Remove this optional <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::removeProperty(void)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::removeProperty");

  PRECONDITION("Property is optional", isOptional());
  PRECONDITION("Optional property is present", isPresent());
  PRECONDITION("Property is void", isVoid());
  clearPresent();
  POSTCONDITION("Optional property no longer present", !isPresent());
}
  // @mfunc The size of the raw bits of this
  //        <c OMWeakReferenceSetProperty>. The size is given in bytes.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @rdesc The size of the raw bits of this
  //          <c OMWeakReferenceSetProperty> in bytes.
  //   @this const
template <typename ReferencedObject>
OMUInt32 OMWeakReferenceSetProperty<ReferencedObject>::bitsSize(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::bitsSize");
  OBSOLETE("methods on class OMReferenceSetProperty");

  return sizeof(ReferencedObject*) * count();
}

  // @mfunc Get the raw bits of this <c OMWeakReferenceSetProperty>.
  //        The raw bits are copied to the buffer at address <p bits> which
  //        is <p size> bytes in size.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The address of the buffer into which the raw bits are copied.
  //   @parm The size of the buffer.
  //   @this const
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::getBits(
                                                    OMByte* bits,
                                                    OMUInt32 ANAME(size)) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::getBits");
  OBSOLETE("methods on class OMReferenceSetProperty");

  PRECONDITION("Optional property is present",
                                           IMPLIES(isOptional(), isPresent()));
  PRECONDITION("Valid bits", bits != 0);
  PRECONDITION("Valid size", size >= bitsSize());

  const OMStorable** p = (const OMStorable**)bits;

  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    *p++ = element.getValue();
  }
}

  // @mfunc Set the raw bits of this
  //        <c OMWeakReferenceSetProperty>. The raw bits are
  //        copied from the buffer at address <p bits> which is
  //        <p size> bytes in size.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The address of the buffer from which the raw bits are copied.
  //   @parm The size of the buffer.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::setBits(const OMByte* bits,
                                                           OMUInt32 size)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::setBits");
  OBSOLETE("methods on class OMReferenceSetProperty");

  PRECONDITION("Valid bits", bits != 0);
  PRECONDITION("Valid size", size >= bitsSize());

  size_t count = size / sizeof(ReferencedObject*);
  ReferencedObject** p = (ReferencedObject**)bits;

  for (size_t i = 0; i < count; i++) {
    ReferencedObject* object = p[i];
    insert(object);
  }

}

  // @mfunc Insert <p object> into this
  //        <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The <c OMObject> to insert.
template <typename ReferencedObject>
void
OMWeakReferenceSetProperty<ReferencedObject>::insertObject(
                                                        const OMObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::insertObject");

  PRECONDITION("Valid object", object != 0);

  const ReferencedObject* p = dynamic_cast<const ReferencedObject*>(object);
  ASSERT("Object is correct type", p != 0);

  insert(p);
}

  // @mfunc Does this <c OMWeakReferenceSetProperty> contain
  //        <p object> ?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The <c OMObject> for which to search.
  //   @rdesc True if <p object> is present, false otherwise.
  //   @this const
template <typename ReferencedObject>
bool
OMWeakReferenceSetProperty<ReferencedObject>::containsObject(
                                                  const OMObject* object) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::containsObject");

  PRECONDITION("Valid object", object != 0);

  const ReferencedObject* p = dynamic_cast<const ReferencedObject*>(object);
  ASSERT("Object is correct type", p != 0);

  return containsValue(p);
}

  // @mfunc Remove <p object> from this
  //        <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The <c OMObject> to remove.
template <typename ReferencedObject>
void
OMWeakReferenceSetProperty<ReferencedObject>::removeObject(
                                                        const OMObject* object)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::removeObject");

  PRECONDITION("Valid object", object != 0);

  const ReferencedObject* p = dynamic_cast<const ReferencedObject*>(object);
  ASSERT("Object is correct type", p != 0);

  removeValue(p);
}

  // @mfunc Remove all objects from this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::removeAllObjects(void)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::removeAllObjects");

  _set.clear();
  POSTCONDITION("All objects removed", count() == 0);
}

  // @mfunc Create an <c OMReferenceContainerIterator> over this
  //        <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @rdesc An <c OMReferenceContainerIterator> over this
  //          <c OMWeakReferenceSetProperty>.
  //   @this const
template <typename ReferencedObject>
OMReferenceContainerIterator*
OMWeakReferenceSetProperty<ReferencedObject>::createIterator(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::createIterator");

  OMWeakReferenceSetIterator<ReferencedObject>* result =
             new OMWeakReferenceSetIterator<ReferencedObject>(*this, OMBefore);
  ASSERT("Valid heap pointer", result != 0);

  return result;
}

  // @mfunc Remove the <c OMObject> identified by <p identification>
  //        from this <c OMWeakReferenceSetProperty>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The unique identification of the object to remove.
  //   @rdesc The object that was removed.
template <typename ReferencedObject>
OMObject*
OMWeakReferenceSetProperty<ReferencedObject>::remove(void* identification)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::remove");

  PRECONDITION("Valid identification", identification != 0);

  OMUniqueObjectIdentification* id =
               reinterpret_cast<OMUniqueObjectIdentification*>(identification);
  return remove(*id);
}

  // @mfunc Does this <c OMWeakReferenceSetProperty> contain an
  //        <c OMObject> identified by <p identification> ?
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The unique identification of the object for which to search.
  //   @rdesc True if the object was found, false otherwise.
  //   @this const
template <typename ReferencedObject>
bool
OMWeakReferenceSetProperty<ReferencedObject>::contains(
                                                    void* identification) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::containsObject");


  PRECONDITION("Valid identification", identification != 0);

  OMUniqueObjectIdentification* id =
               reinterpret_cast<OMUniqueObjectIdentification*>(identification);
  return contains(*id);
}

  // @mfunc Find the <c OMObject> in this <c OMWeakReferenceSetProperty>
  //        identified by <p identification>.  If the object is found
  //        it is returned in <p object> and the result is < e bool.true>.
  //        If the object is not found the result is <e bool.false>.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable> and <c OMUnique>.
  //   @parm The unique identification of the object for which to search.
  //   @parm The object.
  //   @rdesc True if the object was found, false otherwise.
  //   @this const
template <typename ReferencedObject>
bool
OMWeakReferenceSetProperty<ReferencedObject>::findObject(
                                                      void* identification,
                                                       OMObject*& object) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::findObject");

  PRECONDITION("Valid identification", identification != 0);

  OMUniqueObjectIdentification* id =
               reinterpret_cast<OMUniqueObjectIdentification*>(identification);

  ReferencedObject* obj = 0;

  bool result = find(*id, obj);

  object = obj;
  return result;
}

template <typename ReferencedObject>
OMContainerIterator<OMWeakReferenceSetElement>*
OMWeakReferenceSetProperty<ReferencedObject>::iterator(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::iterator");

  OMSetIterator<OMUniqueObjectIdentification, SetElement>* result =
   new OMSetIterator<OMUniqueObjectIdentification, SetElement>(_set, OMBefore);
  ASSERT("Valid heap pointer", result != 0);
  return result;
}

template <typename ReferencedObject>
void
OMWeakReferenceSetProperty<ReferencedObject>::insert(
                                      void* key,
                                      const OMWeakReferenceSetElement& element)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::insert");

  OMUniqueObjectIdentification* k =
                          reinterpret_cast<OMUniqueObjectIdentification*>(key);
  _set.insert(*k, element);
}

template <typename ReferencedObject>
OMPropertyTag
OMWeakReferenceSetProperty<ReferencedObject>::targetTag(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::targetTag");

  PRECONDITION("Property is attached to file", container()->inFile());

  OMWeakReferenceSetProperty<ReferencedObject>* nonConstThis =
               const_cast<OMWeakReferenceSetProperty<ReferencedObject>*>(this);
  if (_targetTag == nullOMPropertyTag) {
    nonConstThis->_targetTag =
                  file()->referencedProperties()->insert(targetPropertyPath());
  }
  POSTCONDITION("Valid target property tag", _targetTag != nullOMPropertyTag);
  return _targetTag;
}

template <typename ReferencedObject>
void
OMWeakReferenceSetProperty<ReferencedObject>::setTargetTag(
                                                       OMPropertyTag targetTag)
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::setTargetTag");

  _targetTag = targetTag;
}

template <typename ReferencedObject>
OMStrongReferenceSet*
OMWeakReferenceSetProperty<ReferencedObject>::targetSet(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::targetSet");
  OMWeakReferenceSetProperty<ReferencedObject>* nonConstThis =
               const_cast<OMWeakReferenceSetProperty<ReferencedObject>*>(this);
  if (_targetSet == 0) {
    nonConstThis->_targetSet = OMWeakObjectReference<
                                 OMUniqueObjectIdentification>::targetSet(
                                                                  this,
                                                                  targetTag());
  }
  POSTCONDITION("Valid result", _targetSet != 0);
  return _targetSet;
}

template <typename ReferencedObject>
OMPropertyId
OMWeakReferenceSetProperty<ReferencedObject>::keyPropertyId(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::keyPropertyId");

  return _keyPropertyId;
}

template <typename ReferencedObject>
OMPropertyId*
OMWeakReferenceSetProperty<ReferencedObject>::targetPropertyPath(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::targetPropertyPath");

  if (_targetPropertyPath == 0) {
    ASSERT("Valid target name", validWideString(_targetName));
    OMWeakReferenceSetProperty<ReferencedObject>* nonConstThis =
               const_cast<OMWeakReferenceSetProperty<ReferencedObject>*>(this);
    nonConstThis->_targetPropertyPath = file()->path(_targetName);
  }
  POSTCONDITION("Valid result", _targetPropertyPath != 0);
  return _targetPropertyPath;
}

template <typename ReferencedObject>
void
OMWeakReferenceSetProperty<ReferencedObject>::clearTargetTag(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::clearTargetTag");

  OMWeakReferenceSetProperty<ReferencedObject>* nonConstThis =
               const_cast<OMWeakReferenceSetProperty<ReferencedObject>*>(this);

  nonConstThis->_targetTag = nullOMPropertyTag;
  delete [] nonConstThis->_targetPropertyPath;
  nonConstThis->_targetPropertyPath = 0;
}

template <typename ReferencedObject>
const wchar_t*
OMWeakReferenceSetProperty<ReferencedObject>::targetName(void) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::targetName");

  return _targetName;
}

template <typename ReferencedObject>
bool
OMWeakReferenceSetProperty<ReferencedObject>::isResolved(
                const OMUniqueObjectIdentification& /* identification */) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::isResolved");

  ASSERT("Unimplemented code not reached", false);
  bool result = false;
  return result;
}

template <typename ReferencedObject>
bool
OMWeakReferenceSetProperty<ReferencedObject>::isResolvable(
                const OMUniqueObjectIdentification& /* identification */) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::isResolvable");

  ASSERT("Unimplemented code not reached", false);
  bool result = false;
  return result;
}

template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::shallowCopyTo(
                                                 OMProperty* destination) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::shallowCopyTo");
  PRECONDITION("Valid destination", destination != 0);

  typedef OMWeakReferenceSetProperty Property;
  Property* dest = dynamic_cast<Property*>(destination);
  ASSERT("Destination is correct type", dest != 0);
  ASSERT("Valid destination", dest != this);

  ASSERT("Destination set is void", dest->isVoid());
  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    SetElement destElement( dest, element.identification(), nullOMPropertyTag);
    dest->_set.insert(destElement.identification(), destElement);
  }

  dest->_targetTag = nullOMPropertyTag;
  dest->_targetName = _targetName;
  delete [] dest->_targetPropertyPath;
  dest->_targetPropertyPath = 0;
  dest->_keyPropertyId = _keyPropertyId;
  dest->setPresent();
}

template <typename ReferencedObject>
void OMWeakReferenceSetProperty<ReferencedObject>::deepCopyTo(
                                                     OMProperty* destination,
                                                     void* clientContext) const
{
  TRACE("OMWeakReferenceSetProperty<ReferencedObject>::deepCopyTo");
  PRECONDITION( "Valid destination", destination != 0 );

  typedef OMWeakReferenceSetProperty<ReferencedObject> Property;
  Property* wp = dynamic_cast<Property*>(destination);
  ASSERT("Correct property type", wp != 0);

  // Update the target tags on elements
  SetIterator destIterator(wp->_set, OMBefore);
  while (++destIterator) {
    SetElement& element = destIterator.value();
    element.reference().setTargetTag(wp->targetTag());
  }

  OMStrongReferenceSet* dest = wp->targetSet();
  ASSERT("Destination is correct type", dest != 0);

  OMStorable* container = dest->container();
  ASSERT("Valid container", container != 0);
  OMClassFactory* factory = container->classFactory();
  ASSERT("Valid class factory", factory != 0);

  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    SetElement& element = iterator.value();
    OMStorable* source = element.getValue();
    if (source != 0) {
      OMUniqueObjectIdentification id = element.identification();
      if (!dest->contains(&id)) {
        OMStorable* d = source->shallowCopy(factory);
        dest->insertObject(d);
        d->onCopy(clientContext);
        source->deepCopyTo(d, clientContext);
      }
    }
  }
}

#endif

