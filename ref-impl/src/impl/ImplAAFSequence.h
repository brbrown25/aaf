//@doc
//@class    AAFSequence | Implementation class for AAFSequence
#ifndef __ImplAAFSequence_h__
#define __ImplAAFSequence_h__


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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

class ImplAAFTimecode;

class ImplAAFComponent;

class ImplAAFSegment;

class ImplAAFDataDef;

template <class T> 
class ImplAAFEnumerator;
typedef ImplAAFEnumerator<ImplAAFComponent> ImplEnumAAFComponents;

#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif

#include "OMStrongRefVectorProperty.h"

class ImplAAFSequence : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFSequence ();
  virtual ~ImplAAFSequence ();


  //****************
  // Initialize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    Initialize
		// @parm [in] Data Definition object
        (ImplAAFDataDef * pDataDef);


  //****************
  // AppendComponent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    AppendComponent
		// @parm [in] Component to append to the sequence
        (ImplAAFComponent * pComponent);


  //****************
  // PrependComponent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    PrependComponent
		// @parm [in] Component to prepend to the sequence
        (ImplAAFComponent * pComponent);


  //****************
  // InsertComponentAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    InsertComponentAt
		// @parm [in] index to insert component
        (aafUInt32 index,

		 // @parm [in] Component to insert into the sequence
		 ImplAAFComponent * pComponent);


  //****************
  // GetComponentAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetComponentAt
		// @parm [in] index of component to retrieve
        (aafUInt32 index,

		 // @parm [out, retval] retrieved component
		 ImplAAFComponent ** ppComponent);


  //****************
  // RemoveComponentAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RemoveComponentAt
		// @parm [in] index of component to remove
        (aafUInt32 index);


  //****************
  // RemoveComponent()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RemoveComponent
		// @parm [in] Component to remove from the sequence
        (ImplAAFComponent * pComponent);


  //****************
  // CountComponents()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CountComponents
		// @parm [out, retval] Component Enumeration
        (aafUInt32 * pResult);


  //****************
  // GetComponents()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetComponents
		// @parm [out, retval] Component Enumeration
        (ImplEnumAAFComponents ** ppEnum);


  // Override from AAFSegment
  virtual AAFRESULT STDMETHODCALLTYPE
    SegmentOffsetToTC (/*[in]*/ aafPosition_t *  pOffset,
	  /*[out]*/ aafTimecode_t *  pTimecode);

  // Override from AAFSegment
  virtual AAFRESULT STDMETHODCALLTYPE
    SegmentTCToOffset (/*[in]*/ aafTimecode_t *  pTimecode,
	  /*[in]*/ aafRational_t *  pEditRate,
	  /*[out]*/ aafFrameOffset_t *  pOffset);



public:

  // Interfaces visible inside the toolkit, but not exposed through the API
  AAFRESULT GetNthComponent(aafUInt32 index, ImplAAFComponent **ppComponent);
	virtual AAFRESULT ChangeContainedReferences(aafMobID_constref from,
												aafMobID_constref to);
  AAFRESULT
    SetNthComponent (aafUInt32 index, ImplAAFComponent* pComponent);

private:
	OMStrongReferenceVectorProperty<ImplAAFComponent> _components;

};

#endif // ! __ImplAAFSequence_h__

