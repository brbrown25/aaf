//@doc
//@class    AAFFindSourceInfo | Implementation class for AAFFindSourceInfo
#ifndef __ImplAAFFindSourceInfo_h__
#define __ImplAAFFindSourceInfo_h__

/***********************************************\
*												*
* Advanced Authoring Format						*
*												*
* Copyright (c) 1998-1999 Avid Technology, Inc. *
* Copyright (c) 1998-1999 Microsoft Corporation *
*												*
\***********************************************/

#ifndef __AAFTypes_h__
#include "AAFTypes.h"
#endif

#ifndef __ImplAAFRoot_h__
#include "ImplAAFRoot.h"
#endif

class ImplAAFMob;
class ImplAAFComponent;
class ImplAAFOperationGroup;
class ImplAAFPulldown;

class ImplAAFFindSourceInfo : public ImplAAFRoot
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFFindSourceInfo ();

protected:
  virtual ~ImplAAFFindSourceInfo ();

  	ImplAAFMob		*_mob;
	aafSlotID_t		_slotID;
	aafPosition_t	_position;
	aafRational_t	_editRate;
	aafLength_t		_length;
	ImplAAFComponent *_cpnt;
	ImplAAFOperationGroup *_operationGroup;

public:

	virtual AAFRESULT STDMETHODCALLTYPE
		Init(ImplAAFMob *mob, aafSlotID_t slotID, aafPosition_t position,
							aafRational_t editRate, aafLength_t length,
							ImplAAFComponent *cpnt);
	virtual AAFRESULT STDMETHODCALLTYPE
		AddPulldown(ImplAAFPulldown *pdwn);
	virtual AAFRESULT STDMETHODCALLTYPE
		SetOperationGroup(ImplAAFOperationGroup *OperationGroup);
	virtual AAFRESULT STDMETHODCALLTYPE
		SetComponent(ImplAAFComponent *cpnt);

	virtual AAFRESULT STDMETHODCALLTYPE
		Duplicate(ImplAAFFindSourceInfo *info);
	virtual AAFRESULT STDMETHODCALLTYPE
		Clear(void);
	virtual AAFRESULT STDMETHODCALLTYPE
		GetMob(ImplAAFMob **ppMob);
	virtual AAFRESULT STDMETHODCALLTYPE
		GetReference(aafSourceRef_t *pSourceRef);
};

#endif // ! __ImplAAFFindSourceInfo_h__

