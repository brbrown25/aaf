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
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMRootStorable

#include "OMRootStorable.h"

#include "OMStoredObject.h"

OMRootStorable::OMRootStorable(void)
: _clientRoot(0x0002, L"Header"),
  _dictionary(0x0001, L"MetaDictionary"),
  _file(0)
{
  initialize(0, 0);
}

OMRootStorable::OMRootStorable(OMStorable* clientRoot,
                               OMDictionary* dictionary)
: _clientRoot(0x0002, L"Header"),
  _dictionary(0x0001, L"MetaDictionary"),
  _file(0)
{
  initialize(clientRoot, dictionary);
}

OMRootStorable::~OMRootStorable(void)
{
}

// {B3B398A5-1C90-11d4-8053-080036210804}
const OMClassId OMRootStorable::_rootClassId =
{ 0xb3b398a5, 0x1c90, 0x11d4, { 0x80, 0x53, 0x8, 0x0, 0x36, 0x21, 0x8, 0x4 } };

const OMClassId& OMRootStorable::classId(void) const
{
  return _rootClassId;
}

  // @mfunc Save this <c OMRootStorable>.
void OMRootStorable::save(void) const
{
  TRACE("OMRootStorable::save");

  OMRootStorable* nonConstThis = const_cast<OMRootStorable*>(this);
  store()->save(*nonConstThis);
}

  // @mfunc Close this <c OMRootStorable>.
void OMRootStorable::close(void)
{
  TRACE("OMRootStorable::close");

  _clientRoot->close();
  _dictionary->close();
}

  // @mfunc Restore the contents of an <c OMRootStorable>.
void OMRootStorable::restoreContents(void)
{
  TRACE("OMRootStorable::restoreContents");

  store()->restore(_persistentProperties);
}

  // @mfunc The <c OMFile> in which this <c OMRootStorable> has a
  //        persistent representation.
  //   @rdesc The <c OMFile> in which this <c OMRootStorable> has a
  //          persistent representation.
  //   @this const
OMFile* OMRootStorable::file(void) const
{
  TRACE("OMRootStorable::file");
  return _file;
}

  // @mfunc Is this <c OMRootStorable> the root of the object
  //        containment hierarchy.
  //   @rdesc True if this is the root object, false otherwise.
  //   @this const
bool OMRootStorable::isRoot(void) const
{
  TRACE("OMRootStorable::isRoot");
  return true;
}

  // @mfunc Is this <c OMRootStorable> associated with an <c OMFile> ?
  //   @rdesc True if this <c OMRootStorable> is associated with
  //          an <c OMFile> , false otherwise.
  //   @this const
bool OMRootStorable::inFile(void) const
{
  TRACE("OMRootStorable::inFile");
  bool result;
  if (_file != 0) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc Is this <c OMRootStorable> associated with an <c OMFile> ?
  //   @rdesc True if this <c OMRootStorable> is associated with an
  //          <c OMFile> , false otherwise.
  //   @this const
bool OMRootStorable::persistent(void) const
{
  TRACE("OMRootStorable::persistent");

  bool result = inFile(); // All files are persistent for now
  return result;
}

void OMRootStorable::attach(OMFile* file)
{
  TRACE("OMRootStorable::attach");
  _file = file;
}

OMStorable* OMRootStorable::clientRoot(void) const
{
  return _clientRoot;
}

OMDictionary* OMRootStorable::dictionary(void) const
{
  return _dictionary;
}

void OMRootStorable::initialize(OMStorable* clientRoot,
                                OMDictionary* dictionary)
{
  _persistentProperties.put(_clientRoot.address());
  _persistentProperties.put(_dictionary.address());

  _clientRoot = clientRoot;
  _dictionary = dictionary;

  _clientRoot.initialize(OMDictionary::find(0x0002));
  _dictionary.initialize(OMDictionary::find(0x0001));

}
