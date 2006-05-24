//=---------------------------------------------------------------------=
//
// $Id: ImplAAFStorable.cpp,v 1.6 2006/05/24 18:01:53 tbingham Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

/*************************************************************************
 * 
 * @module ImplAAFStorable | ImplAAFStorable is an abstract class
 *		  that defines a base class of all persistant objects in
 *      an AAF file. All of its methods are inherited and then implemented
 *      by a subclass.
 *
 * @base public | ImplAAFRoot | OMStorable
 *
 *************************************************************************/



#include "ImplAAFStorable.h"
#include "ImplAAFClassDef.h"
#include "ImplAAFContext.h"
#include "ImplAAFModule.h"
#include "OMAssertions.h"

ImplAAFStorable::ImplAAFStorable ()
{
}


ImplAAFStorable::~ImplAAFStorable ()
{
}


// Associate OMClassDefinition and OMPropertyDefinitions with this object.
void ImplAAFStorable::InitializeOMStorable(ImplAAFClassDef * pClassDef)
{
  ASSERTU (NULL != pClassDef);
  
  // Install the class definition for this storable.
  setDefinition(pClassDef);
  
  // Make sure all of the properties exist and have property definitions.
  InitOMProperties(pClassDef);
}

  
AAFRESULT ImplAAFStorable::GetDefinition(ImplAAFClassDef ** ppClassDef)
{
  if (NULL == ppClassDef)
    return AAFRESULT_NULL_PARAM;
  *ppClassDef = NULL;
  
  OMClassDefinition * classDefinition = const_cast<OMClassDefinition *>(definition());
  ImplAAFClassDef * pClassDef = dynamic_cast<ImplAAFClassDef *>(classDefinition);
  ASSERTU (NULL != pClassDef);
  if (!pClassDef)
    return AAFRESULT_NOT_INITIALIZED;
  
  *ppClassDef = pClassDef;
  pClassDef->AcquireReference();
  return AAFRESULT_SUCCESS;
}

// Call during long operations in order to give time to the calling application
void ImplAAFStorable::Progress(void) const
{
  ImplAAFContext* context = ImplAAFContext::GetInstance();
  ASSERTU(context);
  IAAFProgress* progress = NULL;
  context->GetProgressCallback(&progress);
  if(progress != NULL)
  {
	  try
	  {
		(*progress).ProgressCallback();
	  }
	  catch(...)
	  {
	  }
  }
}
