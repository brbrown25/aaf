/***********************************************************************
 *
 *              Copyright (c) 1998-2000 Avid Technology, Inc.
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


#ifndef __ImplAAFBuiltinClasses_h__
#include "ImplAAFBuiltinClasses.h"
#endif

#ifndef __ImplAAFClassDef_h__
#include "ImplAAFClassDef.h"
#endif

#ifndef __AAFClassDefUIDs_h__
#include "AAFClassDefUIDs.h"
#endif

#ifndef __AAFTypeDefUIDs_h__
#include "AAFTypeDefUIDs.h"
#endif
#ifndef __AAFPropertyIDs_h__
#include "AAFPropertyIDs.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "AAFUtils.h"
#include "ImplAAFDictionary.h"
#include "ImplAAFMetaDictionary.h"
#include "ImplAAFBuiltinDefs.h"
#include "AAFObjectModel.h"

#include <assert.h>








ImplAAFBuiltinClasses::ImplAAFBuiltinClasses (ImplAAFDictionary* dictionary)
  : _dictionary (dictionary)
{
  dictionary->SetBuiltinClasses(this);
}


ImplAAFBuiltinClasses::~ImplAAFBuiltinClasses ()
{
}


AAFRESULT
ImplAAFBuiltinClasses::NewBuiltinClassDef (const aafUID_t & rClassID,
										   ImplAAFClassDef ** ppResult)
{
  AAFRESULT status = AAFRESULT_NO_MORE_OBJECTS;

  ImplAAFUID popped;
	
	

  assert (! _createStack.isPresent (rClassID));

  _createStack.push (rClassID);
  
  // Find the builtin class definition template.
	const AAFObjectModel * objectModel = AAFObjectModel::singleton();
	const ClassDefinition * classDefinition = objectModel->findClassDefinition(&rClassID);
	if (classDefinition && !classDefinition->isNil())
	{
		assert(!classDefinition->axiomatic()); // axiomatic classes should have already been created.
		
	  // We've found the desired class in our table.
	  ImplAAFClassDef * pcd = (ImplAAFClassDef*)(_dictionary->metaDictionary())->pvtCreateMetaDefinition(AUID_AAFClassDef);
	  assert (pcd);
    pcd->InitializeOMStorable(_dictionary->GetBuiltinDefs()->cdClassDef());

	  status = InitBuiltinClassDef (rClassID, classDefinition, pcd);
	  if (AAFRESULT_SUCCEEDED (status))
		{
		  assert (ppResult);
		  *ppResult = pcd;
		}
	}

  popped = _createStack.pop ();
  assert (popped == rClassID);
  return status;
}



AAFRESULT
ImplAAFBuiltinClasses::InitBuiltinClassDef (const aafUID_t & rClassID,
											const ClassDefinition * classDefinition, 
											ImplAAFClassDef * pClass)
{
  assert (classDefinition && !classDefinition->isNil());
	assert(!classDefinition->axiomatic()); // axiomatic classes should have already been created.
	assert (pClass);
	AAFRESULT status = AAFRESULT_NO_MORE_OBJECTS;
	ImplAAFUID popped;
	ImplAAFClassDefSP parent;
	
	assert (! _initStack.isPresent (rClassID));
	
	_initStack.push (rClassID);
	
  
	if (!classDefinition->isRoot())
	{
		// JeffB: The LookupClassDef() call on the parent may make a recursive
		// call to InitBuiltinClassDef for the parent class.  Since we have a moderately
		// shallow tree with no loops, this shouldn't be a problem.
		status = _dictionary->LookupClassDef(*classDefinition->parentId(), &parent);
		assert (AAFRESULT_SUCCEEDED (status));
	}
	else
	{
		parent = pClass;	// Hit an object whose parent is NULL, end the recursion.
	}
		
	status = pClass->Initialize (*classDefinition->id(),
								parent,
								classDefinition->name(),
								classDefinition->concrete() ? kAAFTrue : kAAFFalse);
	if (AAFRESULT_SUCCEEDED (status))
	{
		status = pClass->SetBootstrapParent(parent);
	}
		
		
  RegisterBuiltinProperties (classDefinition, pClass);

	popped = _initStack.pop ();
	assert (popped == rClassID);
	return status;
}


AAFRESULT ImplAAFBuiltinClasses::LookupOmPid
  (const aafUID_t & rAuid,
   OMPropertyId & outPid) const
{
  // Find the builtin class definition template.
	const AAFObjectModel * objectModel = AAFObjectModel::singleton();
	const PropertyDefinition * propertyDefinition = objectModel->findPropertyDefinition(&rAuid);

  if (propertyDefinition && !propertyDefinition->isNil())
		{
		  // Yup, matches.  Return the pid.
		  outPid = propertyDefinition->pid();
		  return AAFRESULT_SUCCESS;
		}

  // Not found.
  return E_FAIL;
}


ImplAAFClassDef * ImplAAFBuiltinClasses::LookupAxiomaticClass
(const aafUID_t & classId)
{
  assert (_dictionary);

  ImplAAFClassDef * result = 0;

	result = _dictionary->metaDictionary()->findAxiomaticClassDefinition(classId); // return value NOT reference counted!
  if (result)
  {
    result->AcquireReference(); // We will be returning this references!
  }

  return result;
}

bool ImplAAFBuiltinClasses::IsAxiomaticClass
(const aafUID_t & classId) const
{
  assert (_dictionary);

  bool result = false;


	ImplAAFClassDef *pAxiomaticClass = _dictionary->metaDictionary()->findAxiomaticClassDefinition(classId); // return value NOT reference counted!
  if (pAxiomaticClass)
  {
    result = true;
  }

  return result;
}


void ImplAAFBuiltinClasses::RegisterBuiltinProperties
(
 const ClassDefinition * classDefinition, 
 ImplAAFClassDef * pClassDef
) const
{
  assert (classDefinition && !classDefinition->isNil());
  assert (pClassDef);
  assert(!classDefinition->axiomatic()); // axiomatic classes should have already been created.

  // Get auid for given class def.
  aafUID_t classAuid;
  AAFRESULT hr;
  hr = pClassDef->GetAUID (&classAuid);
  assert (AAFRESULT_SUCCEEDED (hr));

  // Look through all known builtin properties.  Identify which ones
  // belong to this class.  For each one, instantiate it and add it to
  // the class.
  aafUInt32 i;
	
	const PropertyDefinition * propertyDefinition = NULL;
	for (i = 0; i < classDefinition->propertyCount(); i++)
	{
		propertyDefinition = classDefinition->propertyDefinitionAt(i);
		ImplAAFPropertyDefSP pd;
		hr = pClassDef->pvtRegisterPropertyDef
						(*propertyDefinition->id(),
						propertyDefinition->name(),
						*propertyDefinition->typeId(),
						propertyDefinition->required() ? kAAFFalse : kAAFTrue,
						propertyDefinition->uid() ? kAAFTrue : kAAFFalse,
						&pd);
		assert (AAFRESULT_SUCCEEDED (hr));

		// Don't need these anymore
		assert (pd);
	}
}
