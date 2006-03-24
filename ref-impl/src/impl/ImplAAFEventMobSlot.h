//@doc
//@class    AAFEventMobSlot | Implementation class for AAFEventMobSlot
#ifndef __ImplAAFEventMobSlot_h__
#define __ImplAAFEventMobSlot_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplAAFEventMobSlot.h,v 1.10 2006/03/24 18:23:37 jlow Exp $ $Name:  $
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
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=


#ifndef __ImplAAFMobSlot_h__
#include "ImplAAFMobSlot.h"
#endif


class ImplAAFEventMobSlot : public ImplAAFMobSlot
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFEventMobSlot ();

protected:
  virtual ~ImplAAFEventMobSlot ();

public:


  //****************
  // GetEditRate()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetEditRate
        // @parm [out,retval] Edit rate property value
        (aafRational_t *  pEditRate);

  //****************
  // SetEditRate()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetEditRate
        // @parm [in] Edit rate property value
        (aafRational_t *  pEditRate);


  //****************
  // GetEventSlotOrigin()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetEventSlotOrigin
        // @parm [out,retval] EventSlotOrigin property value
        (aafPosition_t *  result);

  //****************
  // SetEventSlotOrigin()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetEventSlotOrigin
        // @parm [in] EventSlotOrigin property value
        (aafPosition_t  value);




  // Override from AAFMobSlot
  virtual AAFRESULT STDMETHODCALLTYPE
    SetSegment (/*[in]*/ ImplAAFSegment * pSegment);

protected:
  OMFixedSizeProperty<aafRational_t>	_editRate;
  OMFixedSizeProperty<aafPosition_t>	_eventSlotOrigin;
};

#endif // ! __ImplAAFEventMobSlot_h__


