//@doc
//@class    AAFSourceReference | Implementation class for AAFSourceReference
#ifndef __ImplAAFSourceReference_h__
#define __ImplAAFSourceReference_h__

#include "OMStorable.h"

//=---------------------------------------------------------------------=
//
// $Id: ImplAAFSourceReference.h,v 1.23.2.1 2004/05/01 02:10:44 jptrainor Exp $ $Name:  $
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


#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif

#include "ImplAAFObject.h"


class ImplAAFSourceReference : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFSourceReference ();
  virtual ~ImplAAFSourceReference ();



  //****************
  // GetSourceID()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetSourceID
		// @parm [retval][out] Place to put source ID
        (aafMobID_t *  pSourceID);

  //****************
  // SetSourceID()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetSourceID
		// @parm [in] Source ID to set
        (aafMobID_constref   sourceID);

  //****************
  // GetSourceMobSlotID()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetSourceMobSlotID
		// @parm [retval][out] Place to put source mob slot ID
        (aafSlotID_t *  pMobSlotID);

  //****************
  // SetSourceMobSlotID()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetSourceMobSlotID
		// @parm [in] Source Mob ID to set
        (aafSlotID_t   mobSlotID);


  //****************
  // SetChannelIDs()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetChannelIDs
        (// @parm [in] Number of elements in the pChannelIDs array
         aafUInt32  numberElements,

         // @parm [in] Array of channel IDs
         aafUInt32*  pChannelIDs);


  //****************
  // GetChannelIDs()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetChannelIDs
        (// @parm [in] Number of elements in the pChannelIDs array
         aafUInt32  numberElements,

         // @parm [in] Array of channel IDs
         aafUInt32*  pChannelIDs);

  //****************
  // GetChannelIDsSize()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetChannelIDsSize
        // @parm [out] Number of elements in the pChannelIDs array
        (aafUInt32 *  numberElements);


public:
	//SDK-private

	virtual AAFRESULT ChangeContainedReferences(aafMobID_constref from,
												aafMobID_constref to);
	// OM deep copy notification
	virtual void onCopy(void* clientContext) const;

private:
	OMFixedSizeProperty<aafMobID_t>	_sourceID;
	OMFixedSizeProperty<aafInt32>	_sourceMobSlotId;

};

#endif // ! __ImplAAFSourceReference_h__

