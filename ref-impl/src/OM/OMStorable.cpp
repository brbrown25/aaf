#include "OMStorable.h"
#include "OMStoredObject.h"
#include "OMFile.h"
#include "OMClassFactory.h"
#include "OMObjectDirectory.h"
#include "OMTypes.h"

#include "OMAssertions.h"

#include <string.h>

OMStorable::OMStorable(void)
: _persistentProperties(), _containingObject(0), _name(0), _pathName(0)
{
  TRACE("OMStorable::OMStorable");
  _persistentProperties.setContainer(this);
}

OMStorable::~OMStorable(void)
{
  delete [] _name;
  _name = 0;
  delete [] _pathName;
  _pathName = 0;
}

void OMStorable::saveTo(OMStoredObject& s) const
{
  TRACE("OMStorable::saveTo");
  
  size_t context = 0;
  //_file->objectDirectory()->insert(pathName(), this);
  s.save(classId());
  for (size_t i = 0; i < _persistentProperties.count(); i++)
  {
    OMProperty* p = 0;
    _persistentProperties.iterate(context, p);
    ASSERT("Valid property", p != 0);
    s.save(p);
  }
}

void OMStorable::save(OMStoredObject& s, const OMStorable* p)
{
  TRACE("OMStorable::save");
  if (p != 0) {
    p->saveTo(s);
  } else {
    // Treat null as a reference to non-existent object 0.
  }
}

void OMStorable::restoreContentsFrom(OMStoredObject& s)
{
  TRACE("OMStorable::restoreContentsFrom");
  s.restore(_persistentProperties);
}

OMStorable* OMStorable::restoreFrom(const OMStorable* containingObject,
                                    const char* name,
                                    OMStoredObject& s)
{
  TRACE("OMStorable::restoreFrom");
  OMClassId cid;
  s.restore(cid);
  OMFile* f = containingObject->file();
  OMStorable* object = f->classFactory()->create(cid);
  ASSERT("Registered class id", object != 0);
  // give the object a parent, no orphans allowed
  object->setContainingObject(containingObject);
  // give the object a name, all new objects need a name and so here
  // we baptize them
  object->setName(name);
  f->objectDirectory()->insert(object->pathName(), object);
  object->restoreContentsFrom(s);
  return object;
}

OMStorable* OMStorable::containingObject(void) const
{
  return const_cast<OMStorable*>(_containingObject);
}

void OMStorable::setContainingObject(const OMStorable* containingObject)
{
  _containingObject = containingObject;
  delete [] _pathName;
  _pathName = 0;
}

const char* OMStorable::name(void) const
{
  return _name;
}

void OMStorable::setName(const char* name)
{
  PRECONDITION("Valid name", validString(name));
  delete [] _name;
  _name = 0; // for BoundsChecker
  _name = new char[strlen(name) + 1];
  strcpy(_name, name);
  delete [] _pathName;
  _pathName = 0;
}

OMFile* OMStorable::file(void) const
{
  PRECONDITION("Valid containing object", _containingObject != 0);
  return _containingObject->file();
}

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

char* OMStorable::makePathName(void)
{
  TRACE("OMStorable::makePathName");
  // Don't need to compute path name each time, should save once computed.

  // All objects must have a name.
  //
  ASSERT("Object has a name", validString(name()));

  // By definition the root object is the one with no container.
  // Check that the root object is called "/".
  //
  ASSERT("Root object properly named",
                   IMPLIES(containingObject() == 0, strcmp(name(), "/") == 0));

  // Only the root object is called "/".
  // Check that if the object is called "/" it is the root object (has
  // no container).
  //
  ASSERT("Non-root object properly named",
                   IMPLIES(strcmp(name(), "/") == 0, containingObject() == 0));
  
  char* result = 0;
  OMStorable* cont = containingObject();
  if (cont != 0) {
    if (cont->containingObject() != 0) {
      // general case
      result = new char[strlen(cont->pathName()) + strlen(name()) + 1 + 1];
      strcpy(result, cont->pathName());
      strcat(result, "/");
      strcat(result, name());
    } else {
      // child of root
      result = new char[strlen(cont->pathName()) + strlen(name()) + 1];
      strcpy(result, cont->pathName());
      strcat(result, name());
    }
  } else {
    // root
    result = new char[strlen(name()) + 1];
    strcpy(result, name());
  }

  POSTCONDITION("Valid result", validString(result));
  return result;

}
