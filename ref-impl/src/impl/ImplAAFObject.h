//@doc
//@class    AAFObject | Implementation class for AAFObject
#ifndef __ImplAAFObject_h__
#define __ImplAAFObject_h__

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


//
// Forward declarations
//
class ImplEnumAAFProperties;
class ImplAAFClassDef;
class ImplAAFProperty;
class ImplAAFPropertyDef;
class ImplAAFPropertyValue;
class ImplPropertyCollection;
class ImplAAFDictionary;

#include "AAFTypes.h"
#include "OMStorable.h"
#include "OMProperty.h"
#include "ImplAAFRoot.h"

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

class ImplAAFObject : public OMStorable, public ImplAAFRoot
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFObject ();
  virtual ~ImplAAFObject ();


  //****************
  // SetGeneration()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetGeneration
		// @parm [in] Generation ID to which this object is to be set
        (const aafUID_t & generation);


  //****************
  // GetGeneration()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetGeneration
		// @parm [out] Generation ID into which this object's generation is to be written
        (aafUID_t *  pGeneration);


  //****************
  // GetDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetDefinition
		// @parm [out] class definition of which this object is an instance.
        (ImplAAFClassDef ** ppClassDef);


  //****************
  // GetObjectClass()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	GetObjectClass
		(aafUID_t * pClass);


  //****************
  // GetProperties()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	GetProperties
		(ImplEnumAAFProperties ** ppEnum);


  //****************
  // CountProperties()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	CountProperties
		(aafUInt32 * pCount);


  //****************
  // GetPropertyValue()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	GetPropertyValue
		(ImplAAFPropertyDef * pPropDef,
		 ImplAAFPropertyValue ** ppPropVal);


  //****************
  // SetPropertyValue()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	SetPropertyValue
		(ImplAAFPropertyDef * pPropDef,
		 ImplAAFPropertyValue * pPropVal);


  //****************
  // IsPropertyPresent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
	IsPropertyPresent
		(ImplAAFPropertyDef * pPropDef,
		 aafBool * pResult);


  //***********************************************************
  // METHOD NAME: GetStoredByteOrder()
  //
  // DESCRIPTION:
  // @mfunc AAFRESULT | AAFEndian | GetStoredByteOrder |
  // Returns the "Endian-ness" in which the current object was or will
  // be stored.  If this is a transient object (i.e., one which has
  // not been persisted) then it will return the native byte order of
  // the platform on which this is running.
  //
  // @end
  // 
  virtual AAFRESULT STDMETHODCALLTYPE
  GetStoredByteOrder (
    // @parm [out] eAAFByteOrder_t * | pOrder | Pointer to place where byte order is to be put
    eAAFByteOrder_t *  pOrder
  );



  //***********************************************************
  // METHOD NAME: GetNativeByteOrder()
  //
  // DESCRIPTION:
  // @mfunc AAFRESULT | AAFEndian | GetNativeByteOrder |
  // Returns the native "Endian-ness" of the platform on which this is
  // running.
  //
  // @end
  // 
  virtual AAFRESULT STDMETHODCALLTYPE
  GetNativeByteOrder (
    // @parm [out] eAAFByteOrder_t * | pOrder | Pointer to place where byte order is to be put
    eAAFByteOrder_t *  pOrder
  );


public:
  // Interfaces ivisible inside the toolkit, but not exposed through the API

  // Gets the head object of the file containing this object.
  // This function is used to maintain MOB and Definition tables in the
  // head object.
  virtual AAFRESULT MyHeadObject
    (class ImplAAFHeader **header) const;

  // Gets the dictionary used to create this instance.
  virtual AAFRESULT STDMETHODCALLTYPE 
    GetDictionary(ImplAAFDictionary **ppDictionary) const;


  void pvtSetSoid (const aafUID_t & id);

  virtual const OMClassId& classId(void) const;

  // Create and intialize associated external extensions.
  AAFRESULT InitializeExtensions(void);

  // Remembers the given property so it will be deleted with this
  // object.
  void RememberAddedProp (OMProperty * pProp);

private:

  // private method
  AAFRESULT InitProperties ();

  ImplPropertyCollection * _pProperties;

  ImplAAFClassDef *        _cachedDefinition;

  // stored object ID
  aafUID_t                 _soid;
	OMFixedSizeProperty<aafMobID_t>	_generation;

  // 
  // The following section is intended only to delete added properties
  // when this object goes away.
  // 
  // Private class to manage saved properties
  class SavedProp
  {
  public:
	SavedProp (OMProperty * p);
	~SavedProp ();

  private:
	// Disallow copy and assignment, so declare them private and don't
	// implement!
	SavedProp (const SavedProp&);
	SavedProp& operator= (const SavedProp&);

	OMProperty * _p;
  };
  //
  // pointer to array of pointers to saved properties.
  SavedProp ** _apSavedProps;
  //
  // size of _pSavedProps array.
  aafUInt32 _savedPropsSize;
  //
  // number of those props that are actually used
  aafUInt32 _savedPropsCount;
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFObject> ImplAAFObjectSP;


#endif // ! __ImplAAFObject_h__
