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
#include "OMPropertySet.h"
#include "OMProperty.h"

#include "OMAssertions.h"

#define OMPROPERTYSET_CHUNKSIZE (20)

OMPropertySet::OMPropertySet(void)
: _propertySet(0), _capacity(OMPROPERTYSET_CHUNKSIZE), _count(0), _container(0)
{
  TRACE("OMPropertySet::OMPropertySet");
  PRECONDITION("Valid Capacity", _capacity >= 0);

  _propertySet = new OMPropertySetElement[_capacity];
  ASSERT("Valid heap pointer", _propertySet != 0);

  for (size_t i = 0; i < _capacity; i++) {
    _propertySet[i]._valid = false;
  }
  POSTCONDITION("Valid count", ((_count >= 0) && (_count <= _capacity)));
}

OMPropertySet::~OMPropertySet(void)
{
  TRACE("OMPropertySet::~OMPropertySet");

  delete [] _propertySet;
  _propertySet = 0;
}

  // @mfunc Get the <c OMProperty> associated with the property
  //        id <p propertyId>.
  //   @parm Property id.
  //   @rdesc The <c OMProperty> object with property id <p propertyId>.
  //   @this const
OMProperty* OMPropertySet::get(const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::get");
  OMProperty* result;
  PRECONDITION("Valid property id", propertyId >= 0 );
  PRECONDITION("Property is allowed", isAllowed(propertyId));
  PRECONDITION("Property is present", isPresent(propertyId));
  OMPropertySetElement* element = find(propertyId);
  ASSERT("Element found", element != 0);
  ASSERT("Valid element", element->_valid);
  result = element->_property;
  POSTCONDITION("Valid result", result != 0);
  POSTCONDITION("Valid count", ((_count >= 0) && (_count <= _capacity)));
  return result;
}

  // @mfunc Get the <c OMProperty> named <p propertyName>.
  //   @parm Property name.
  //   @rdesc The <c OMProperty> with name <p propertyName>.
  //   @this const
OMProperty* OMPropertySet::get(const char* propertyName) const
{
  TRACE("OMPropertySet::get");

  PRECONDITION("Valid property name", validString(propertyName));
  PRECONDITION("Property is present", isPresent(propertyName));

  OMPropertySetElement* element = find(propertyName);
  ASSERT("Element found", element != 0);
  ASSERT("Valid element", element->_valid);
  OMProperty* result = element->_property;

  POSTCONDITION("Valid result", result != 0);
  return result;
}

  // @mfunc Insert the <c OMProperty> <p property> into
  //        this <c OMPropertySet>.
  //   @parm <c OMProperty> to insert.
void OMPropertySet::put(OMProperty* property)
{
  TRACE("OMPropertySet::put");
  // SAVE(_count);
  PRECONDITION("Valid property", property != 0);
  PRECONDITION("Valid property id", property->propertyId() >= 0);
  PRECONDITION("Property is not present", !isPresent(property->propertyId()));

  OMPropertyId propertyId = property->propertyId();
  OMPropertySetElement* element = find();
  if (element == 0) {
    grow(OMPROPERTYSET_CHUNKSIZE);
    element = find();
  }
  ASSERT("Found space for new element", element != 0);

  element->_propertyId = propertyId;
  element->_property = property;
  element->_valid = true;
  element->_property->setPropertySet(this);
  _count++;

  POSTCONDITION("Property installed", isPresent(property->propertyId()));
  POSTCONDITION("Consistent property set",
                property == find(property->propertyId())->_property);
  // POSTCONDITION("Count increased by one", _count == OLD(_count) + 1);
  POSTCONDITION("Valid count", ((_count >= 0) && (_count <= _capacity)));
}

  // @mfunc Iterate over the <c OMProperty> objects in this
  //        <c OMPropertySet>. Call this function <mf OMPropertySet::count>
  //        times to iterate over all the <c OMProperty> objects in this
  //        <c OMPropertySet>.
  //   @parm Iteration context. Set this to 0 to start with the
  //         "first" <c OMProperty>.
  //   @parm The "current" <c OMProperty>.
  //   @this const
void OMPropertySet::iterate(size_t& context, OMProperty*& property) const
{
  TRACE("OMPropertySet::iterate");

  OMPropertySetElement* element = 0;
  size_t start = context;
  size_t found = 0;

  for (size_t i = start; i < _capacity; i++) {
    if (_propertySet[i]._valid) {
      element = &_propertySet[i];
      found = i;
      break;
    }
  }
  if (element != 0) {
    property = element->_property;
    context = ++found;
  } else {
    context = 0;
  }
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

  OMPropertySetElement* element = find(propertyId);
  if (element != 0) {
    return true;
  } else {
    return false;
  }
}

  // @mfunc Is an <c OMProperty> with name <p propertyName>
  //        present in this <c OMPropertySet> ?
  //  @rdesc <e bool.true> if an <c OMProperty> with name
  //         <p propertyName> is present <e bool.false> otherwise.
  //  @parm Property name.
  //  @this const
bool OMPropertySet::isPresent(const char* propertyName) const
{
  TRACE("OMPropertySet::isPresent");

  OMPropertySetElement* element = find(propertyName);
  if (element != 0) {
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
  POSTCONDITION("Valid count", ((_count >= 0) && (_count <= _capacity)));
  return _count;
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
  POSTCONDITION("Valid count", ((_count >= 0) && (_count <= _capacity)));
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

bool OMPropertySet::equal(const OMPropertyId& propertyIda,
                          const OMPropertyId& propertyIdb)
{
  TRACE("OMPropertySet::equal");
  return propertyIda == propertyIdb;
}

OMPropertySet::OMPropertySetElement* OMPropertySet::find(
                                           const OMPropertyId propertyId) const
{
  TRACE("OMPropertySet::find");

  OMPropertySetElement* result = 0;

  for (size_t i = 0; i < _capacity; i++) {
    if (_propertySet[i]._valid) {
      if (equal(_propertySet[i]._propertyId, propertyId)) {
        result = &_propertySet[i];
        break;
      }
    }
  }
  return result;
}

OMPropertySet::OMPropertySetElement* OMPropertySet::find(
                                                const char* propertyName) const
{
  TRACE("OMPropertySet::find");

  OMPropertySetElement* result = 0;

  for (size_t i = 0; i < _capacity; i++) {
    if (_propertySet[i]._valid) {
      if (strcmp(_propertySet[i]._property->name(), propertyName) == 0) {
        result = &_propertySet[i];
        break;
      }
    }
  }
  return result;
}

OMPropertySet::OMPropertySetElement* OMPropertySet::find(void) const
{
  TRACE("OMPropertySet::find");

  OMPropertySetElement* result = 0;

  for (size_t i = 0; i < _capacity; i++) {
    if (!_propertySet[i]._valid) {
      result = &_propertySet[i];
      break;
    }
  }
  return result;

}

void OMPropertySet::grow(const size_t additionalElements)
{
  TRACE("OMPropertySet::grow");

  // Save old size and old property set element array
  //
  size_t oldCapacity = _capacity;
  OMPropertySetElement* oldPropertySet = _propertySet;
  
  // New capacity
  //
  _capacity = _capacity + additionalElements;
  
  // Allocate new property set element array
  //
  _propertySet = new OMPropertySetElement[_capacity];
  ASSERT("Valid heap pointer", _propertySet != 0);

  // Copy over all elements from the old array
  //
  for (size_t i = 0; i < oldCapacity; i++) {
    _propertySet[i] = oldPropertySet[i];
  }

  // Initialize new elements to be invalid
  //
  for (size_t j = oldCapacity; j < _capacity; j++) {
    _propertySet[j]._valid = false;
  }

  // Delete the old array
  //
  delete [] oldPropertySet;

  POSTCONDITION("Size properly increased",
                _capacity == oldCapacity + additionalElements);

}
