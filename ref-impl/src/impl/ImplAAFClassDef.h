//@doc
//@class    AAFClassDef | Implementation class for AAFClassDef
#ifndef __ImplAAFClassDef_h__
#define __ImplAAFClassDef_h__

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
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
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

class ImplEnumAAFPropertyDefs;
class ImplAAFDefObject;
class ImplAAFPropertyDef;

#ifndef __ImplAAFMetaDefinition_h__
#include "ImplAAFMetaDefinition.h"
#endif

#ifndef __ImplAAFPropertyDef_h__
#include "ImplAAFPropertyDef.h"
#endif

#ifndef __ImplAAFTypeDef_h__
#include "ImplAAFTypeDef.h"
#endif

class ImplAAFClassDef : public ImplAAFMetaDefinition
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFClassDef ();

protected:
  virtual ~ImplAAFClassDef ();

public:

  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
        // @parm [in] auid to be used to identify this type
        (const aafUID_t & classID,

		// Inheritance parent of this class
		ImplAAFClassDef * pParentClass,

		// Human-legible name
		const aafCharacter * pClassName);


  //****************
  // GetPropertyDefs()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetPropertyDefs
        // @parm [out, retval] Property Definition enumeration
        (ImplEnumAAFPropertyDefs ** ppEnum);


  //****************
  // CountPropertyDefs()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CountPropertyDefs
        // @parm [out] number of properties contained in this class definition
        (aafUInt32 *  pCount);


  //****************
  // RegisterNewPropertyDef()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterNewPropertyDef
        (// @parm [in] auid to be used to identify this property
         const aafUID_t & id,

         // @parm [in, string] name of the new property
         const aafCharacter *  pName,

         // @parm [in] type of the new property
         ImplAAFTypeDef * pTypeDef,

         // @parm [in] true if new property is to be optional
         aafBool  isOptional,

         // @parm [in] true if new property is a unique identifier
         aafBool  isUniqueIdentifier,

         // @parm [out] return pointer to newly created property def
         ImplAAFPropertyDef ** ppPropDef);


  //****************
  // RegisterOpionalPropertyDef()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterOptionalPropertyDef
        (// @parm [in] auid to be used to identify this property
         const aafUID_t & id,

         // @parm [in, string] name of the new property
         const aafCharacter *  pName,

         // @parm [in] type of the new property
         ImplAAFTypeDef * pTypeDef,

         // @parm [out] return pointer to newly created property def
         ImplAAFPropertyDef ** ppPropDef);


  //****************
  // LookupPropertyDef()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupPropertyDef
        (// @parm [in] auid reprepresenting property to look up
         const aafUID_t & propID,

         // @parm [out] resulting property definition
         ImplAAFPropertyDef ** ppPropDef) const;


  //****************
  // GetParent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetParent
        // @parm [out, retval] parent class definition
        (ImplAAFClassDef ** ppClassDef);


  //****************
  // CreateInstance()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CreateInstance
        // @parm [out, retval] newly created object
        (ImplAAFObject ** ppobject);

  //****************
  // IsRoot()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    IsRoot
        (aafBool* isRootClass);

  //****************
  // IsUniquelyIdentified
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    IsUniquelyIdentified
        (aafBoolean_t * isUniquelyIdentified);

  //****************
  // GetUniqueIdentifier
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetUniqueIdentifier
        (ImplAAFPropertyDef ** ppUniqueIdentifier);


public:

	bool
    PvtIsPropertyDefRegistered (
      aafUID_constref propId);

  //****************
  // SetParent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetParent
        (ImplAAFClassDef *pClassDef);

  //****************
  // SetBootstrapParent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetBootstrapParent
        (ImplAAFClassDef *pClassDef);

  //****************
  // pvtInitialize()
  //
  // Same as Initialize(), but takes guid for parent class instead of
  // object pointer.
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    pvtInitialize
        // @parm [in] auid to be used to identify this type
        (const aafUID_t & classID,

		// Inheritance parent of this class
		const ImplAAFClassDef * pParentClassId,

		// Human-legible name
		const aafCharacter * pClassName);


  // Private method to unconditionally register a property def (ignoring
  // whether or not property is optional or not, or if this class has
  // already been registered).
  AAFRESULT STDMETHODCALLTYPE
    pvtRegisterPropertyDef
        (const aafUID_t & id,
         const aafCharacter *  pName,
         const aafUID_t & typeId,
         aafBool  isOptional,
         aafBool  isUniqueIdentifier,
         ImplAAFPropertyDef ** ppPropDef);


  // Appends an existing property def object.
  AAFRESULT STDMETHODCALLTYPE
    pvtRegisterExistingPropertyDef
        (// PropertyDef to append
		 ImplAAFPropertyDef * pPropDef);


  //****************
  // LookupPropertyDefbyOMPid()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupPropertyDefbyOMPid
        (// @parm [in] pid reprepresenting property to look up
         OMPropertyId omPid,

         // @parm [out] resulting property definition
         ImplAAFPropertyDef ** ppPropDef) const;

  // Make sure that the type definition of each property definition
  // has been loaded into memory.
  void AssurePropertyTypesLoaded ();

  // Find the unique identifier property defintion for this class or any parent class
  // (RECURSIVE)
  ImplAAFPropertyDef * pvtGetUniqueIdentifier(void); // result is NOT reference counted.

private:

  //
  // Private implementation classes to share lookup code between
  // methods which lookup by auid, and ones which look up by OMPid.
  //
  // Abstract base class which allows comparison of a property
  // identifier to a property definition.
  class pvtPropertyIdentifier
  {
  public:
	// Returns kAAFTrue if this property identifier matches the given
	// property definition.
	virtual aafBool DoesMatch
    (const ImplAAFPropertyDef * pTestPropDef) const = 0;
  };

  //
  // Concrete class implementing property identifier as OM PID
  //
  class pvtPropertyIdentifierOMPid : public pvtPropertyIdentifier
  {
  public:
	pvtPropertyIdentifierOMPid (const OMPropertyId & id)
	  : _id (id) {}

	aafBool DoesMatch (const ImplAAFPropertyDef * pTestPropDef) const;
	
  private:
	OMPropertyId _id;
  };

  //
  // Concrete class implementing property identifier as a Property ID
  // AUID.
  //
  class pvtPropertyIdentifierAUID : public pvtPropertyIdentifier
  {
  public:
	pvtPropertyIdentifierAUID (const aafUID_t & id)
	  : _id (id) {}

	aafBool DoesMatch (const ImplAAFPropertyDef * pTestPropDef) const;

  private:
	aafUID_t _id;
  };


  // Provide two level property search routines that are overloaded.

  // Low-level recursive methods the OM find method instead of a linear search
  // that will necessarily load all of the property definitions for the class
  // definition instance.
  AAFRESULT
    generalLookupPropertyDef (
      aafUID_constref propId,
      ImplAAFPropertyDef ** ppPropDef);

  //
  // The generalized lookup method which uses a pvtPropertyIdentifier
  // as the property ID.
  //
  AAFRESULT 
    generalLookupPropertyDef (
      const pvtPropertyIdentifier & propId,
      ImplAAFPropertyDef ** ppPropDef);

  // OMWeakReferenceProperty<ImplAAFClassDef> _ParentClass;
  OMWeakReferenceProperty<ImplAAFClassDef>         _ParentClass;

  OMStrongReferenceSetProperty<OMUniqueObjectIdentification, ImplAAFPropertyDef> _Properties;

  ImplAAFClassDef	*_BootstrapParent;

  bool _propTypesLoaded;
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFClassDef> ImplAAFClassDefSP;

#endif // ! __ImplAAFClassDef_h__
