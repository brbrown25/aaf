// @doc OMEXTERNAL
#include "OMProperty.h"

#include "OMStorable.h"

#include <memory.h>

// class OMProperty

OMProperty::OMProperty(const OMPropertyId propertyId,
                       const int type,
                       const char* name)
: _propertyId(propertyId), _type(type), _name(name)
{
}

OMProperty::~OMProperty(void)
{
}

  // @mfunc The name of this <c OMProperty>.
  //   @rdesc The property name.
  //   @this const
const char* OMProperty::name(void) const
{
  return _name;
}

  // @mfunc The property id of this <c OMProperty>.
  //   @rdesc The property id.
  //   @this const
const OMPropertyId OMProperty::propertyId(void) const
{
  return _propertyId;
}

  // @mfunc Inform this <c OMProperty> that it is a member of
  //        the <c OMPropertySet> <p propertySet>.
  //   @parm The <c OMPropertySet> of which this <c OMProperty> is
  //   a member.
void OMProperty::setPropertySet(const OMPropertySet* propertySet)
{
  _propertySet = propertySet;
}

  // @mfunc The address of this <c OMProperty> object. This function
  //        is defined so that descendants may override "operator &" to
  //        obtain the address of the contained property value. This
  //        function can then be used to obtain the address of this
  //        <c OMProperty>.
  //   @rdesc The address of this <c OMProperty>.
OMProperty* OMProperty::address(void)
{
  return this;
}

void OMProperty::detach(const OMStorable* object, const size_t key)
{
  TRACE("OMProperty::detach");
  PRECONDITION("Valid object", object != 0);
  // nothing to do for most descendants of OMProperty
}

// @doc OMINTERNAL

// class OMSimpleProperty

OMSimpleProperty::OMSimpleProperty(const OMPropertyId propertyId,
                                   const char* name)
: OMProperty(propertyId, TID_DATA, name), _size(0), _bits(0)
{
}

OMSimpleProperty::OMSimpleProperty(const OMPropertyId propertyId,
                                   const char* name,
                                   size_t valueSize)
: OMProperty(propertyId, TID_DATA, name),
  _size(valueSize),
  _bits(new unsigned char[valueSize])
{
  PRECONDITION("Valid size", (valueSize > 0));

  for (size_t i = 0; i < valueSize; i++) {
    _bits[i] = 0;
  }

  POSTCONDITION("Valid bits", _bits != 0 );
}

OMSimpleProperty::~OMSimpleProperty(void)
{
  delete [] _bits;
}

size_t OMSimpleProperty::size(void) const
{
  return _size;
}

void OMSimpleProperty::get(void* value, size_t valueSize) const
{
  PRECONDITION("Valid size", valueSize >= _size);
  memcpy(value, _bits, _size);
}

void OMSimpleProperty::set(const void* value, size_t valueSize) 
{
  if (valueSize != _size) {
    delete [] _bits;
    _bits = 0; // for BoundsChecker
    _bits = new unsigned char[valueSize];
    _size = valueSize;
  }
  memcpy(_bits, value, _size);
}

void OMSimpleProperty::saveTo(OMStoredObject& s) const
{
  s.write(_propertyId, _type, _bits, _size);
}


// class OMCollectionProperty

OMCollectionProperty::OMCollectionProperty(const OMPropertyId propertyId,
                                           const int type,
                                           const char* name)
: OMProperty(propertyId, type, name)
{
}

OMCollectionProperty::~OMCollectionProperty(void)
{
}

// class OMStringProperty

OMStringProperty::OMStringProperty(const OMPropertyId propertyId,
                                   const char* name)
: OMCharacterStringProperty<char>(propertyId, name)
{
}

OMStringProperty::~OMStringProperty(void)
{
}

OMStringProperty& OMStringProperty::operator = (const char* value)
{
  assign(value);
  return *this;
}

// class OMWideStringProperty

OMWideStringProperty::OMWideStringProperty(const OMPropertyId propertyId,
                                           const char* name)
: OMCharacterStringProperty<wchar_t>(propertyId, name)
{
}

OMWideStringProperty::~OMWideStringProperty(void)
{
}

OMWideStringProperty& OMWideStringProperty::operator = (const wchar_t* value)
{
  assign(value);
  return *this;
}

