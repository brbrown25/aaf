//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2003, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMPropertySet

#include "OMPropertySet.h"
#include "OMProperty.h"
#include "OMUtilities.h"
#include "OMRedBlackTreeIterator.h"

#include "OMAssertions.h"


OMPropertySet::OMPropertySet(void)
: _set(),
  _container(0)
{
  TRACE("OMPropertySet::OMPropertySet");
}

OMPropertySet::~OMPropertySet(void)
{
  TRACE("OMPropertySet::~OMPropertySet");
  _container = 0;
}

  // @mfunc Get the <c OMProperty> associated with the property
  //        id <p propertyId>.
  //   @parm Property id.
  //   @rdesc The <c OMProperty> object with property id <p propertyId>.
  //   @this const
OMProperty* OMPropertySet::get(const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::get");
  OMProperty* result = 0;
  PRECONDITION("Valid property id", propertyId != 0 );
  PRECONDITION("Property is allowed", isAllowed(propertyId));
  PRECONDITION("Property is present", isPresent(propertyId));

  bool status = _set.find(propertyId, result);
  ASSERT("Property found", status);
  POSTCONDITION("Valid result", result != 0);
  return result;
}

  // @mfunc Get the <c OMProperty> named <p propertyName>.
  //   @parm Property name.
  //   @rdesc The <c OMProperty> with name <p propertyName>.
  //   @this const
OMProperty* OMPropertySet::get(const wchar_t* propertyName) const
{
  TRACE("OMPropertySet::get");

  PRECONDITION("Valid property name", validWideString(propertyName));
  PRECONDITION("Property is present", isPresent(propertyName));

  OMProperty* result = find(propertyName);

  POSTCONDITION("Valid result", result != 0);
  return result;
}

  // @mfunc Insert the <c OMProperty> <p property> into
  //        this <c OMPropertySet>.
  //   @parm <c OMProperty> to insert.
void OMPropertySet::put(OMProperty* property)
{
  TRACE("OMPropertySet::put");

  PRECONDITION("Valid property", property != 0);
  PRECONDITION("Valid property id", property->propertyId() != 0);
  PRECONDITION("Property is not present", !isPresent(property->propertyId()));

  OMPropertyId propertyId = property->propertyId();

  property->setPropertySet(this);
  _set.insert(propertyId, property);

  POSTCONDITION("Property installed", isPresent(property->propertyId()));
  POSTCONDITION("Consistent property set",
                                      property == get(property->propertyId()));
}

  // @mfunc Is an <c OMProperty> with property id <p propertyId>
  //        present in this <c OMPropertySet> ?
  //  @rdesc <e bool.true> if an <c OMProperty> with property id
  //         <p propertyId> is present <e bool.false> otherwise.
  //  @parm Property id.
  //  @this const
bool OMPropertySet::isPresent(const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::isPresent");

  OMProperty* p;
  bool result = _set.find(propertyId, p);
  return result;
}

  // @mfunc Is an <c OMProperty> with name <p propertyName>
  //        present in this <c OMPropertySet> ?
  //  @rdesc <e bool.true> if an <c OMProperty> with name
  //         <p propertyName> is present <e bool.false> otherwise.
  //  @parm Property name.
  //  @this const
bool OMPropertySet::isPresent(const wchar_t* propertyName) const
{
  TRACE("OMPropertySet::isPresent");

  OMProperty* p = find(propertyName);
  if (p != 0) {
    return true;
  } else {
    return false;
  }
}

  // @mfunc Is an <c OMProperty> with property id <p propertyId>
  //        allowed in this <c OMPropertySet> ?
  //  @rdesc <e bool.true> if an <c OMProperty> with property id
  //         <p propertyId> is allowed <e bool.false> otherwise.
  //  @parm Property id.
  //  @this const
bool OMPropertySet::isAllowed(const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::isAllowed");

  return isPresent(propertyId); // tjb -- no optional properties yet
}

  // @mfunc Is an <c OMProperty> with property id <p propertyId>
  //        a required member of this <c OMPropertySet> ?
  //  @rdesc <e bool.true> if an <c OMProperty> with property id
  //         <p propertyId> is required <e bool.false> otherwise.
  //  @parm Property id.
  //  @this const
bool OMPropertySet::isRequired(const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::isRequired");

  return isPresent(propertyId); // tjb -- no optional properties yet
}

  // @mfunc The number of <c OMProperty> objects in this
  //        <c OMPropertySet>.
  //   @rdesc The number of <c OMProperty> objects in this
  //          <c OMPropertySet>.
  //   @this const
size_t OMPropertySet::count(void) const
{
  TRACE("OMPropertySet::count");

  return _set.count();
}

size_t OMPropertySet::countPresent(void) const
{
  TRACE("OMPropertySet::countPresent");

  size_t result = 0;
  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    OMProperty* p = iterator.value();
    if (!p->isOptional() || p->isPresent()) {
      result = result + 1;
    }
  }
  return result;
}

  // @mfunc This <c OMPropertySet> is contained by the given <c
  //        OMStorable> object <p container>. The <c OMProperty> objects
  //        in this <c OMPropertySet> are the properties of the given
  //        <c OMStorable> object <p container>.
  //   @parm The <c OMStorable> object that contains this <c OMPropertySet>.
void OMPropertySet::setContainer(const OMStorable* container)
{
  TRACE("OMPropertySet::setContainer");
  // The following assertion may need to be changed once we allow
  // OMStorable::copy and OMStorable::move
  //
  PRECONDITION("No valid old container", _container == 0);
  PRECONDITION("Valid new container", container != 0);
  _container = container;
}

  // @mfunc The <c OMStorable> object that contains this
  //        <c OMPropertySet>.
  //   @rdesc The <c OMStorable> object that contains this
  //          <c OMPropertySet>.
  //   @this const
OMStorable* OMPropertySet::container(void) const
{
  TRACE("OMPropertySet::container");
  return const_cast<OMStorable*>(_container);
}

OMProperty* OMPropertySet::find(const wchar_t* propertyName) const
{
  TRACE("OMPropertySet::find");

  OMProperty* result = 0;
  SetIterator iterator(_set, OMBefore);
  while (++iterator) {
    OMProperty* p = iterator.value();
    if (compareWideString(p->name(), propertyName) == 0) {
      result = p;
      break;
    }
  }
  return result;
}
