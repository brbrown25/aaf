#ifndef __AxMobs_h__
#define __AxMobs_h__

//=---------------------------------------------------------------------=
//
// $Id: AxMob.h,v 1.12 2004/09/10 17:12:11 stuart_hc Exp $ $Name:  $
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
//=---------------------------------------------------------------------=

#include "AxTypes.h"
#include "AxSmartPointer.h"
#include "AxObject.h"

//=---------------------------------------------------------------------=

class AxMob : public AxObject {

public:
	AxMob( IAAFMobSP  spIaafMob );
	AxMob( IAAFMob2SP spIaafMob );
	virtual ~AxMob();

	aafMobID_t GetMobID();
	void SetMobID( const aafMobID_t& mobID );
	
	AxString GetName();
	void SetName( const AxString& name );
	
	aafNumSlots_t CountSlots();

	void AppendSlot( IAAFMobSlotSP spSlot );

	IAAFMobSlotSP LookupSlot( aafSlotID_t slotId );

	IAAFMobSP Copy( const AxString& newMobName );

	IAAFMobSP CloneExternal( aafDepend_t resolveDependencies,
							 aafIncMedia_t includeMedia,
							 IAAFFileSP spDestFile );

	void AppendComment( const AxString& category,
						const AxString& comment );

	void AppendKLVData( const IAAFKLVDataSP& );

	IAAFTimelineMobSlotSP AppendNewTimelineSlot(
		aafRational_t  editRate,
		IAAFSegmentSP spIaafSegment,
		aafSlotID_t  slotID,
		const AxString& slotName,
		aafPosition_t  origin );
	
	IEnumAAFMobSlotsSP GetSlots();

	void SetUsageCode( const aafUID_t& usageCode );
	aafUID_t GetUsageCode();

	inline operator IAAFMobSP ()
	{ return AxQueryInterface<IAAFMob2,IAAFMob>( _spIaafMob ); }

	inline operator IAAFMob2SP ()
	{ return _spIaafMob; }

	AxMob()
	  {}

private:
	AxMob( const AxMob& );
	AxMob& operator=( const AxMob& );

	IAAFMob2SP _spIaafMob;
};

//=---------------------------------------------------------------------=

// No parent class!  See the UML.
class AxSearchSource {

public:
	AxSearchSource( IAAFSearchSourceSP spIaafSearchSource );
	virtual ~AxSearchSource();

	AxSearchSource()
	  {}

	IAAFFindSourceInfoSP SearchSource (aafSlotID_t slotID,
				aafPosition_t  offset,
				aafMobKind_t  mobKind,
				aafMediaCriteria_t *  pMediaCrit,
				aafOperationChoice_t *  pOperationChoice);

private:
	AxSearchSource( const AxSearchSource& );
	AxSearchSource& operator=( const AxSearchSource& );

	IAAFSearchSourceSP _spIaafSearchSource;
};


//=---------------------------------------------------------------------=

class AxMasterMob : public AxMob, public AxSearchSource {

public:
	AxMasterMob( IAAFMasterMobSP spIaafMasterMob );
	
	virtual ~AxMasterMob();

	void Initialize();

	IAAFEssenceAccessSP CreateEssence( 
		aafSlotID_t		slotID,
		IAAFDataDefSP		pMediaKind,		// create essence of this type
		aafUID_constref		codecID,		// using this codec
		aafRational_t		editRate,		// with this edit rate
		aafRational_t		samplerate,		// with this sample rate
		aafCompressEnable_t	Enable,			// optionally compressing it
		IAAFLocatorSP		destination,	// Optionally create the file here.
		aafUID_constref		fileFormat );	// with this format
	
	IAAFEssenceAccessSP OpenEssence( 
		aafSlotID_t			slotId,
		aafMediaCriteria_t*	mediaCrit,		// using this essence criteria
		aafMediaOpenMode_t	openMode,		// ReadOnly or Append
		aafCompressEnable_t	compEnable );	// optionally decompressing
	
	void AddMasterSlot(
		IAAFDataDefSP		spDataDef,		// Data kind of new slot. (Probably DDEF_Picture or DDEF_Sound)
		aafSlotID_t			sourceSlotID,	// Slot ID of the Source Mob slot to be added to the Master Mob
		IAAFSourceMobSP		spSourceMob,	// Source Mob containing the slot to be added to the Master Mob
		aafSlotID_t			masterSlotID,	// SlotID assigned to the new Master Mob slot
		const AxString&		slotName );		// Name to assign to new slot in Master Mob

	inline operator IAAFMasterMobSP ()
	{ return _spIaafMasterMob; }

	AxMasterMob()
	  {}

#if 0
	AxMasterMob( const AxMasterMob& other )
	{
		
	}
	  : _spIaafMasterMob( other._spIaafMasterMob )
	  

	AxMasterMob& operator=( const AxMasterMob& rhs )
	{
	  if ( &rhs != this ) {
	    _spIaafMasterMob = rhs._spIaafMasterMob;
	  }
	  return *this;
	}
#endif

private:

	AxMasterMob( const AxMasterMob& other );
	AxMasterMob& operator=( const AxMasterMob& rhs );

	// As soon as you attempt to implement a copy constructor,
	// and/or operator=,  you have to deal with a const AxMasterMob&.
	// That leads to the need to declare the smart pointer mutable.
	mutable IAAFMasterMobSP _spIaafMasterMob;
};

//=---------------------------------------------------------------------=

class AxMasterMobEx : public AxMasterMob {

public:
	AxMasterMobEx( IAAFMasterMobExSP spIaafMasterMobEx );

	virtual ~AxMasterMobEx();

	IAAFEssenceAccessSP ExtendEssence( 
		aafSlotID_t			slotID,
		IAAFDataDefSP		pMediaKind,		// create essence of this type
		aafUID_constref		codecID,		// using this codec
		aafRational_t		editRate,		// with this edit rate
		aafRational_t		samplerate,		// with this sample rate
		aafCompressEnable_t	Enable,			// optionally compressing it
		IAAFLocatorSP		destination,	// Optionally create the file here.
		aafUID_constref		fileFormat );	// with this format

	inline operator IAAFMasterMobExSP ()
		{ return _spIaafMasterMobEx; }

private:
	AxMasterMobEx();
	AxMasterMobEx( const AxMasterMobEx& );
	AxMasterMobEx& operator=( const AxMasterMobEx& );

	// As soon as you attempt to implement a copy constructor,
	// and/or operator=,  you have to deal with a const AxMasterMob&.
	// That leads to the need to declare the smart pointer mutable.
	mutable IAAFMasterMobExSP _spIaafMasterMobEx;
};

//=---------------------------------------------------------------------=

class AxCompositionMob : public AxMob {

public:
	AxCompositionMob( IAAFCompositionMobSP spIaafCompositionMob );
	virtual ~AxCompositionMob();
	
	void Initialize( const AxString& name );

	inline operator IAAFCompositionMobSP ()
	{ return _spIaafCompositionMob; }

private:
	AxCompositionMob();
	AxCompositionMob( const AxCompositionMob& );
	AxCompositionMob& operator=( const AxCompositionMob& );

	IAAFCompositionMobSP _spIaafCompositionMob;
};

//=---------------------------------------------------------------------=

class AxSourceMob : public AxMob, public AxSearchSource {

public:
	AxSourceMob( IAAFSourceMobSP spIaafSourceMob );
	virtual ~AxSourceMob();

	void Initialize();

	void SetEssenceDescriptor( IAAFEssenceDescriptorSP sp );

	IAAFEssenceDescriptorSP GetEssenceDescriptor();

	void AddNilReference( aafSlotID_t slotID,
						  aafLength_t len,
						  IAAFDataDefSP spDataDef,
						  const aafRational_t& editRate );
	inline operator IAAFSourceMobSP ()
	{ return _spIaafSourceMob; }

private:
	AxSourceMob();
	AxSourceMob( const AxSourceMob& );
	AxSourceMob& operator=( const AxSourceMob& );

	IAAFSourceMobSP _spIaafSourceMob;
};


//=---------------------------------------------------------------------=

#endif
