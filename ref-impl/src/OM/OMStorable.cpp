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

// @doc OMINTERNAL
#include "OMStorable.h"
#include "OMStoredObject.h"
#include "OMFile.h"
#include "OMClassFactory.h"
#include "OMObjectDirectory.h"
#include "OMDataTypes.h"
#include "OMProperty.h"

#include "OMAssertions.h"

#include <string.h>

OMStorable::OMStorable(void)
: _persistentProperties(), _containingObject(0), _name(0),
  _pathName(0), _containingProperty(0), _key(0), _store(0),
  _classFactory(0)
{
  TRACE("OMStorable::OMStorable");
  _persistentProperties.setContainer(this);
}

OMStorable::~OMStorable(void)
{
  TRACE("OMStorable::~OMStorable");

  // This assertion will trigger if an attempt is made to delete an
  // object that is still attached. That is, the assertion detects an
  // attempt to create a dangling strong reference.
  //
  PRECONDITION("Object not referenced", _containingProperty == 0);

  delete [] _name;
  _name = 0;
  delete [] _pathName;
  _pathName = 0;
}

  // @mfunc Save this <c OMStorable>.
  //   @this const
void OMStorable::save(void) const
{
  TRACE("OMStorable::save");
  
  //_file->objectDirectory()->insert(pathName(), this);
  store()->save(classId());
  store()->save(_persistentProperties);
}

  // @mfunc Close this <c OMStorable>.
void OMStorable::close(void)
{
  TRACE("OMStorable::close");
  PRECONDITION("Object is persistent", persistent());

  if (_store != 0) {
    size_t context = 0;
    for (size_t i = 0; i < _persistentProperties.count(); i++)
    {
      OMProperty* p = 0;
      _persistentProperties.iterate(context, p);
      ASSERT("Valid property", p != 0);
      p->close();
    }

    _store->close();
    delete _store;
    _store = 0;
  } // else silently ignore unsaved object

  POSTCONDITION("Closed", _store == 0);
}

  // @mfunc Restore the contents of an <c OMStorable> (of unknown
  //        sub-class) from the stored representation <p s>.
  //   @parm The <c OMStoredObject> from which to restore this
  //   <c OMStorable>.
void OMStorable::restoreContentsFrom(OMStoredObject& s)
{
  TRACE("OMStorable::restoreContentsFrom");
  s.restore(_persistentProperties);
}

  // @mfunc Restore an <c OMStorable> (of unknown sub-class) from
  //        the stored representation <p s>.
  //   @parm The <c OMStorable> that will contain (own) the newly
  //   restored <c OMStorable>.
  //   @parm The name to be given the newly restored <c OMStorable>.
  //   @parm The <c OMStoredObject> from which to restore this
  //   <c OMStorable>.
OMStorable* OMStorable::restoreFrom(const OMStorable* containingObject,
                                    const char* name,
                                    OMStoredObject& s)
{
  TRACE("OMStorable::restoreFrom");
  OMClassId cid;
  s.restore(cid);
  OMFile* f = containingObject->file();
  const OMClassFactory* classFactory = f->classFactory();
  OMStorable* object = classFactory->create(cid);
  ASSERT("Registered class id", object != 0);
  ASSERT("Valid class factory", classFactory == object->classFactory());
  // give the object a parent, no orphans allowed
  object->setContainingObject(containingObject);
  // give the object a name, all new objects need a name and so here
  // we baptize them
  object->setName(name);
  object->setStore(&s);
  f->objectDirectory()->insert(object->pathName(), object);
  object->restoreContentsFrom(s);
  return object;
}

  // @mfunc  The <c OMStorable> that contains (owns) this
  //          <c OMStorable>.
  //   @rdesc The containing <c OMStorable>.
  //   @this const
OMStorable* OMStorable::containingObject(void) const
{
  TRACE("OMStorable::containingObject");

  return const_cast<OMStorable*>(_containingObject);
}

  // @mfunc Inform this <c OMStorable> that it is contained
  //        (owned) by the <c OMStorable> <p containingObject>.
  //   @parm The containing <c OMStorable>.
void OMStorable::setContainingObject(const OMStorable* containingObject)
{
  TRACE("OMStorable::setContainingObject");
  //PRECONDITION("No valid old containing object", _containingObject == 0);
  PRECONDITION("Valid new containing object", containingObject != 0);
  _containingObject = containingObject;
  delete [] _pathName;
  _pathName = 0;
}

  // @mfunc Inform this <c OMStorable> that it is no longer contained.
void OMStorable::clearContainingObject(void)
{
  TRACE("OMStorable::clearContainingObject");
  _containingObject = 0;
}

  // @mfunc Inform this <c OMStorable> that it is contained
  //        within the <c OMProperty> <p containingProperty>.
  //   @parm The containing <c OMProperty>.
  //   @parm A key used to be used by this <c OMStorable> to identify
  //         itself in future transactions with the given <c OMProperty>.
void OMStorable::setContainingProperty(const OMProperty* containingProperty,
                                       const size_t key)
{
  TRACE("OMStorable::setContainingProperty");
  PRECONDITION("Object not already attached", _containingProperty == 0);
  PRECONDITION("Valid property", containingProperty != 0);

  _containingProperty = const_cast<OMProperty*>(containingProperty);
  _key = key;

  POSTCONDITION("Object properly attached", _containingProperty != 0);
}

  // @mfunc Inform this <c OMStorable> that it is no longer
  //        contained within any <c OMProperty>.
void OMStorable::clearContainingProperty(void)
{
  TRACE("OMStorable::clearContainingProperty");
  _containingProperty = 0;
}

  // @mfunc The name of this <c OMStorable>.
  //   @rdesc The name of this <c OMStorable>.
  //   @this const
const char* OMStorable::name(void) const
{
  TRACE("OMStorable::name");
  return _name;
}

  // @mfunc Give this <c OMStorable> a name.
  //   @parm The name to be given to this <c OMStorable>.
void OMStorable::setName(const char* name)
{
  TRACE("OMStorable::setName");
  PRECONDITION("Valid name", validString(name));
  delete [] _name;
  _name = 0; // for BoundsChecker
  _name = new char[strlen(name) + 1];
  ASSERT("Valid heap pointer", _name != 0);
  strcpy(_name, name);
  delete [] _pathName;
  _pathName = 0;
}

  // @mfunc The <c OMFile> in which this <c OMStorable> has a
  //        persistent representation.
  //   @rdesc The <c OMFile> in which this <c OMStorable> has a
  //          persistent representation.
  //   @this const
OMFile* OMStorable::file(void) const
{
  TRACE("OMStorable::file");
  PRECONDITION("Valid containing object", _containingObject != 0);
  return _containingObject->file();
}

  // @mfunc The path to this <c OMStorable> from the root of
  //        the <c OMFile> in which this <c OMStorable> resides.
  //   @rdesc The path name of this <c OMStorable>.
  //   @this const
const char* OMStorable::pathName(void) const
{
  TRACE("OMStorable::pathName");

  if (_pathName == 0) {
    OMStorable* nonConstThis = const_cast<OMStorable*>(this);
    nonConstThis->_pathName = nonConstThis->makePathName();
  }
  ASSERT("Valid path name", validString(_pathName));
  return _pathName;
}

  // @mfunc Is this <c OMStorable> the root of the object
  //        containment hierarchy.
  //   @rdesc True if this is the root object, false otherwise.
  //   @this const
bool OMStorable::isRoot(void) const
{
  TRACE("OMStorable::isRoot");
  PRECONDITION("Valid containing object", containingObject() != 0);
  bool result;

  // By definition the root object is the one contained directly
  // within the file.
  if (containingObject() == file()) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc The stored representation of this <c OMStorable>.
  //   @rdesc The <c OMStoredObject> representing this <c OMStorable>.
  //   @this const
OMStoredObject* OMStorable::store(void) const
{
  TRACE("OMStorable::store");

  if (_store == 0) {
    OMStorable* container = containingObject();
    ASSERT("Valid container", container != 0);
    OMStorable* nonConstThis = const_cast<OMStorable*>(this);
    nonConstThis->_store = container->store()->create(name());
  }
  POSTCONDITION("Valid store", _store != 0);
  return _store;
}

  // @mfunc Inform this <c OMStorable> where it should store its
  //        persistent representation.
  //   @parm The <c OMStoredObject> on which this <c OMStorable>
  //         should be persisted.
void OMStorable::setStore(OMStoredObject* store)
{
  TRACE("OMStorable::setStore");
  PRECONDITION("Valid store", store != 0);
  PRECONDITION("No previous valid store", _store == 0);
  _store = store;
}

  // @mfunc Is this <c OMStorable> attached to (owned by) another
  //        OMStorable ?
  //   @rdesc True if this <c OMStorable> is attached, false
  //          otherwise.
  //   @this const
bool OMStorable::attached(void) const
{
  TRACE("OMStorable::attached");

  bool result;

  if (_containingProperty != 0) {
    result = true;
  } else {
    result = false;
  }

  return result;
}

  // @mfunc Is this <c OMStorable> associated with an <c OMFile> ?
  //   @rdesc True if this <c OMStorable> is associated with an
  //          <c OMFile> , false otherwise.
  //   @this const
bool OMStorable::inFile(void) const
{
  TRACE("OMStorable::inFile");
  //PRECONDITION("object is attached", attached());

  bool result;
  OMStorable* container = containingObject();
  if (container != 0) {
    result = container->inFile();
  } else {
    result = false;
  }
  return result;
}

  // @mfunc Is this <c OMStorable> a persistent object ?
  //        Persistent objects are associated with a persistent
  //        store (disk file).
  //   @rdesc True if this <c OMStorable> is persistent, false
  //          otherwise.
  //   @this const
bool OMStorable::persistent(void) const
{
  TRACE("OMStorable::persistent");
  //PRECONDITION("object is in file", inFile());

  bool result;
  OMStorable* container = containingObject();
  if (container != 0) {
    result = container->persistent();
  } else {
    result = false;
  }
  return result;
}

  // @mfunc This object's property set.
  //   @rdesc A pointer to this object's <c OMPropertySet>.
OMPropertySet* OMStorable::propertySet(void)
{
  TRACE("OMStorable::propertySet");

  return &_persistentProperties;
}

  // @mfunc The <c OMClassFactory> that created this object.
  //   @rdesc The <c OMClassFactory> that created this object.
  //   @this const
OMClassFactory* OMStorable::classFactory(void) const
{
  TRACE("OMStorable::classFactory");
  PRECONDITION("Valid class factory", _classFactory != 0);

  return const_cast<OMClassFactory*>(_classFactory);
}

  // @mfunc Inform this <c OMStorable> of the <c OMClassFactory>
  //      that was used to create it.
  //   @parm The <c OMClassFactory> that was used to create
  //         this <c OMStorable>.
void OMStorable::setClassFactory(const OMClassFactory* classFactory)
{
  TRACE("OMStorable::setClassFactory");
  PRECONDITION("Valid class factory", classFactory != 0);
  PRECONDITION("No previous valid class factory", _classFactory == 0);

  _classFactory = classFactory;

  POSTCONDITION("Valid class factory", _classFactory != 0);
}

char* OMStorable::makePathName(void)
{
  TRACE("OMStorable::makePathName");

  ASSERT("Object has a name", validString(name()));
  ASSERT("Root object properly named",
                                  IMPLIES(isRoot(), strcmp(name(), "/") == 0));
  ASSERT("Non-root object properly named",
                                  IMPLIES(strcmp(name(), "/") == 0, isRoot()));
  ASSERT("Non-root object has valid container",
                                  IMPLIES(!isRoot(), containingObject() != 0));

  char* result = 0;
  if (isRoot()) {
    // root
    result = new char[strlen(name()) + 1];
    ASSERT("Valid heap pointer", result != 0);
    strcpy(result, name());
  } else {
    OMStorable* cont = containingObject();
    if (cont->isRoot()) {
      // child of root
      result = new char[strlen(cont->pathName()) + strlen(name()) + 1];
      ASSERT("Valid heap pointer", result != 0);
      strcpy(result, cont->pathName());
      strcat(result, name());
    } else {
      // general case
      result = new char[strlen(cont->pathName()) + strlen(name()) + 1 + 1];
      ASSERT("Valid heap pointer", result != 0);
      strcpy(result, cont->pathName());
      strcat(result, "/");
      strcat(result, name());
	}
  }

  POSTCONDITION("Valid result", validString(result));
  return result;

}
