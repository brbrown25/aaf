//=---------------------------------------------------------------------=
//
// $Id: Extensions.h,v 1.7 2004/02/27 14:26:15 stuart_hc Exp $ $Name:  $
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

#include "AafOmf.h"
#include "Aaf2Omf.h"
#include "Omf2Aaf.h"

class ExtendedAaf2Omf : public Aaf2Omf
{
public:
	ExtendedAaf2Omf(AAFDomainUtils *aafDomainUtils, OMFDomainUtils *omfDomainUtils, EffectTranslate *effectTranslate );
	virtual ~ExtendedAaf2Omf();

public:
private:
};

class ExtendedOmf2Aaf : public Omf2Aaf
{
public:
	ExtendedOmf2Aaf( AAFDomainUtils *aafDomainUtils, OMFDomainUtils *omfDomainUtils, EffectTranslate *effectTranslate );
	virtual ~ExtendedOmf2Aaf();

public:
	virtual void FinishUpMob(omfMobObj_t  /*pOMFMob*/, IAAFMob*  /*pMob*/) { };
private:
};

