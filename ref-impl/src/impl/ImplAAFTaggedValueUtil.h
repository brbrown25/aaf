//=---------------------------------------------------------------------=
//
// $Id: ImplAAFTaggedValueUtil.h,v 1.1.2.1 2004/03/24 17:44:29 jptrainor Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
//
//=---------------------------------------------------------------------=

#ifndef __ImplAAFTaggedValueUtil_h__
#define __ImplAAFTaggedValueUtil_h__

#include "AAFTypes.h"

#include "OMStrongRefVectorProperty.h"

class ImplAAFObject;
class ImplAAFTaggedValue;
template <class T> class ImplAAFEnumerator;
typedef ImplAAFEnumerator<ImplAAFTaggedValue> ImplEnumAAFTaggedValues;

// Vectors of tagged values are common.  These functoins implement
// support for the most common operations on this property type:
// appending a new string value, fetching the size of the vector,
// creating an enumerator for the vector, and removing an entry in the
// vector.

class ImplAAFTaggedValueUtil
{
 public:
  static AAFRESULT AppendNameValuePair( ImplAAFObject* pContainingObject,  
					OMStrongReferenceVectorProperty<ImplAAFTaggedValue>& taggedValues,
					aafCharacter_constptr  pName,
					aafCharacter_constptr  pValue );

  static AAFRESULT CountEntries( OMStrongReferenceVectorProperty<ImplAAFTaggedValue>& taggedValues,
				 aafUInt32* pNumEntries );
  
  static AAFRESULT GetEnumerator( ImplAAFObject* pContainingObject,  
				  OMStrongReferenceVectorProperty<ImplAAFTaggedValue>& taggedValues,
				  ImplEnumAAFTaggedValues ** ppEnum);
  
  static AAFRESULT RemoveEntry( OMStrongReferenceVectorProperty<ImplAAFTaggedValue>& taggedValues,
				ImplAAFTaggedValue* pEntry );
};

#endif
