//@doc
//@class    AAFDictionary | Implementation class for AAFDictionary
#ifndef __ImplAAFDictionary_h__
#define __ImplAAFDictionary_h__

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
 *  prior written permission of Avid Technology, Inc.
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


class ImplAAFBuiltinClasses;
class ImplAAFBuiltinTypes;
class ImplAAFBuiltinProps;
class ImplAAFClassDef;
class ImplAAFCodecDef;
class ImplAAFContainerDef;
class ImplAAFDataDef;
class ImplAAFInterpolationDef;
class ImplAAFOperationDef;
class ImplAAFPluginDescriptor;
class ImplAAFTypeDef;
class ImplEnumAAFClassDefs;
class ImplEnumAAFCodecDefs;
class ImplEnumAAFContainerDefs;
class ImplEnumAAFDataDefs;
class ImplEnumAAFInterpolationDefs;
class ImplEnumAAFOperationDefs;
class ImplEnumAAFPluggableDefs;
class ImplEnumAAFPluginDescriptors;
class ImplEnumAAFTypeDefs;

#ifndef __ImplAAFObject_h__
#include "ImplAAFObject.h"
#endif

#include "OMClassFactory.h"


#include "ImplAAFClassDef.h"
#include "ImplAAFOperationDef.h"
#include "ImplAAFDefObject.h"
#include "ImplAAFCodecDef.h"
#include "ImplAAFContainerDef.h"
#include "ImplAAFInterpolationDef.h"
#include "ImplAAFTypeDef.h"
#include "ImplAAFDataDef.h"

class ImplAAFDictionary :
  public OMClassFactory, 
  public ImplAAFObject
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFDictionary ();

protected:
  virtual ~ImplAAFDictionary ();

public:
  // Create an instance of the appropriate derived class, given the class id.
  //  This method implements the OMClassFactory interface.
  //
  OMStorable* create(const OMClassId& classId) const;


  //****************
  // CreateInstance()
  //
  // Creates a single uninitialized AAF object of the class associated 
  // with a specified stored object id.
  virtual AAFRESULT STDMETHODCALLTYPE 
  CreateInstance (
    // Class identifier (AUID) of the stored object. This is the
    // corresponding SMPTE identifier (as a GUID) for all predefined
    // built-in classes.
    aafUID_t * pAUID,

    // Address of output variable that receives the 
    // object pointer requested in pAUID
    ImplAAFObject ** ppvObject);


  //****************
  // LookupClass()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupClass
        (// @parm [in,ref] Class Unique ID
         const aafUID_t *  pClassID,

         // @parm [out,retval] Class Definition
         ImplAAFClassDef ** ppClassDef);


  //****************
  // RegisterClass()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterClass
        (// @parm [in] Class Definition
         ImplAAFClassDef * pClassDef);


  //****************
  // GetClassDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetClassDefinitions
        // @parm [out,retval] Class Definition Enumeration
        (ImplEnumAAFClassDefs ** ppEnum);


  //****************
  // RegisterType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterType
        (// @parm [in] Type Definition Object
         ImplAAFTypeDef * pTypeDef);

  //****************
  // LookupType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupType
        (// @parm [in,ref] Type Unique ID
         const aafUID_t *  pTypeID,

         // @parm [out,retval] Type Definition Object
         ImplAAFTypeDef ** ppTypeDef);

  //****************
  // GetTypeDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetTypeDefinitions
        // @parm [out,retval] Type Def Enumeration
        (ImplEnumAAFTypeDefs ** ppEnum);


  //****************
  // RegisterDataDefintion()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterDataDefintion
        // @parm [in] Data Definition Object
        (ImplAAFDataDef * pDataDef);

  //****************
  // LookupDataDefintion()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupDataDefintion
        (// @parm [in,ref] Datak Defintion Unique ID
         aafUID_t *  pDataDefintionID,

         // @parm [out,retval] Data Definition Object
         ImplAAFDataDef ** ppDataDef);

  //****************
  // GetDataDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetDataDefinitions
        // @parm [out,retval] Definition Enumeration
        (ImplEnumAAFDataDefs ** ppEnum);


  //****************
  // RegisterOperationDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterOperationDefinition
        // @parm [in] Effect Definition Object
        (ImplAAFOperationDef * pOperationDef);

  //****************
  // LookupOperationDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupOperationDefinition
        (// @parm [in,ref] Effect Unique ID
         aafUID_t *  effectID,

         // @parm [out,retval] Effect definition object
         ImplAAFOperationDef ** ppOperationDef);

  //****************
  // GetOperationDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetOperationDefinitions
        // @parm [out,retval] Definition Enumeration
        (ImplEnumAAFOperationDefs ** ppEnum);

  //****************
  // RegisterParameterDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterParameterDefinition
        // @parm [in] Parameter Definition Object
        (ImplAAFParameterDef * pParameterDef);

  //****************
  // LookupParameterDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupParameterDefinition
        (// @parm [in,ref] Parameter Unique ID
         aafUID_t *  ParameterID,

         // @parm [out,retval] Parameter definition object
         ImplAAFParameterDef ** ppParameterDef);

  //****************
  // GetParameterDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetParameterDefinitions
        // @parm [out,retval] Definition Enumeration
        (ImplEnumAAFParameterDefs ** ppEnum);

  //****************
  // RegisterCodecDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterCodecDefinition
        // @parm [in] Pluggable Definition
        (ImplAAFCodecDef * pPlugDef);

  //****************
  // RegisterCodecDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
   GetCodecDefinitions
      // @parm [out,retval] Definition Enumeration
      (ImplEnumAAFCodecDefs ** ppEnum);

   	AAFRESULT LookupCodecDefinition(aafUID_t *containerID, ImplAAFCodecDef **result);

	//****************
  // RegisterContainerDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterContainerDefinition
        // @parm [in] Pluggable Definition
        (ImplAAFContainerDef * pPlugDef);

  //****************
  // GetContainerDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetContainerDefinitions
        // @parm [out,retval] Definition Enumeration
       (ImplEnumAAFContainerDefs ** ppEnum);

    AAFRESULT LookupContainerDefinition(aafUID_t *containerID, ImplAAFContainerDef **result);

  //****************
  // RegisterInterpolationDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterInterpolationDefinition
        // @parm [in] Interpolation Definition Object
        (ImplAAFInterpolationDef * pInterpolationDef);

  //****************
  // LookupInterpolationDefinition()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupInterpolationDefinition
        (// @parm [in,ref] Interpolation Unique ID
         aafUID_t *  InterpolationID,

         // @parm [out,retval] Interpolation definition object
         ImplAAFInterpolationDef ** ppInterpolationDef);

  //****************
  // GetInterpolationDefinitions()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetInterpolationDefinitions
        // @parm [out,retval] Definition Enumeration
        (ImplEnumAAFInterpolationDefs ** ppEnum);

  //****************
  // RegisterPluginDescriptor()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RegisterPluginDescriptor
        (ImplAAFPluginDescriptor * pPluginDesc);

  //****************
  // LookupPluginDescriptor()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    LookupPluginDescriptor
        (// @parm [in,ref] Interpolation Unique ID
         aafUID_t *  InterpolationID,

         ImplAAFPluginDescriptor ** ppPluginDesc);

  //****************
  // GetPluginDescriptors()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetPluginDescriptors
        (ImplEnumAAFPluginDescriptors ** ppEnum);

public:

  //
  // Internal to the SDK
  //

  //****************
  // GetNumEssenceData()
  //
  virtual AAFRESULT
    GetNumCodecDefs
        (aafUInt32 *  pNumCodecDefs);  //@parm [out,retval] Total number of pluggable defs

  virtual AAFRESULT
    GetNthCodecDef (aafInt32 index, ImplAAFCodecDef **ppEnum);

  virtual AAFRESULT
    GetNumContainerDefs
        (aafUInt32 *  pNumContainerDefs);  //@parm [out,retval] Total number of pluggable defs

  virtual AAFRESULT
    GetNthContainerDef (aafInt32 index, ImplAAFContainerDef **ppEnum);

  AAFRESULT LookupPropTypeByOMPid (OMPropertyId opid,
								   ImplAAFTypeDef ** ppTypeDef) const;

  AAFRESULT LookupPropDefByOMPid (OMPropertyId opid,
								  ImplAAFPropertyDef ** ppd) const;

  // make sure built-in types are initialized.
  void InitBuiltins();

  // Factory method for creating a Dictionary.
  static ImplAAFDictionary *CreateDictionary(void);

  // internal utility factory method to create an ImplAAFObject given an auid.
  // This method was created to make it simpler to replace calls to "Deprecated"
  // call to CreateImpl which should only be used for instanciating transient
  // non-ImplAAFObject classes such as an enumerator.
  ImplAAFObject *CreateImplObject(const aafUID_t& auid); 

  // Generates an OM PID corresponding to the given property def auid.
  AAFRESULT GenerateOmPid (const aafUID_t & rAuid,
						   OMPropertyId & rOutPid);


  // Like LookupClass(), except will only look at classes currently
  // registered in this dictionary; will not attempt to look at
  // builtins which may not have already been entered into the dict.
  AAFRESULT dictLookupClass
    (// @parm [in,ref] Class Unique ID
	 const aafUID_t *  pClassID,

	 // @parm [out,retval] Class Definition
	 ImplAAFClassDef ** ppClassDef);


  // Like LookupType(), except will only look at types currently
  // registered in this dictionary; will not attempt to look at
  // builtins which may not have already been entered into the dict.
  AAFRESULT dictLookupType
    (// @parm [in,ref] Type Unique ID
	 const aafUID_t *  pTypeID,

	 // @parm [out,retval] Type Definition Object
	 ImplAAFTypeDef ** ppTypeDef);


  static ImplAAFObject* pvtCreateBaseClassInstance(const aafUID_t* pAUID);


  // Initializes the built-in types critical to building the dictionary.
  void pvtInitCriticalBuiltins (void);

  // Register the given object to be initialized "at the right time".
  // If that time is now, will init immediately.  If not ready yet,
  // will put obj on queue to be initialized when everything's ready.
  void pvtInitObjectProperties (ImplAAFObject * pObj) const;

private:

  // Like the non-private LookupPropTypeByOMPid(), except will
  // only look at types currently registered in this dictionary; will
  // not attempt to look at builtins which may have not already been
  // entered into the dict.
  AAFRESULT pvtLookupPropTypeByOMPid (OMPropertyId opid,
									  ImplAAFTypeDef ** ppTypeDef) const;


  // Like the non-private LookupPropDefByOMPid(), except will only
  // look at classes currently registered in this dictionary; will not
  // attempt to look at builtins which may have not already been
  // entered into the dict.
  AAFRESULT pvtLookupPropDefByOMPid (OMPropertyId opid,
									 ImplAAFPropertyDef ** ppd) const;



  ImplAAFBuiltinClasses * _pBuiltinClasses;
  ImplAAFBuiltinProps   * _pBuiltinProps;
  ImplAAFBuiltinTypes   * _pBuiltinTypes;

  // Flag to show if initialization of critical builtins has been
  // started yet.
  aafBool                 _initStarted;

  // Flag to show if it's OK to initialize properties of newly created
  // objects.
  aafBool                 _OKToInitProps;



  //
  // Private class to keep a FIFO of objects
  //
  struct pvtObjFifo
  {
	pvtObjFifo ();

	ImplAAFObjectSP GetNext (void);

	void Append (ImplAAFObject * obj);

  private:
	enum {
	  kPvtMaxInitObjs = 200
	};
	ImplAAFObjectSP _objs[kPvtMaxInitObjs];
	aafUInt32 _putIdx;
	aafUInt32 _getIdx;
  };

  //
  // Fifo of objects which will require initialization
  //
  pvtObjFifo _objsToInit;


  OMStrongReferenceVectorProperty<ImplAAFCodecDef>         _codecDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFContainerDef>     _containerDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFOperationDef>     _operationDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFParameterDef>     _parameterDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFTypeDef>          _typeDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFClassDef>         _classDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFInterpolationDef> _interpolationDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFDataDef>          _dataDefinitions;
  OMStrongReferenceVectorProperty<ImplAAFPluginDescriptor> _pluginDefinitions;

  aafInt32 _lastGeneratedPid;	// must be signed!
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFDictionary> ImplAAFDictionarySP;

#endif // ! __ImplAAFDictionary_h__
