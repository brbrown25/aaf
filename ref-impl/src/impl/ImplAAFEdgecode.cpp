//=---------------------------------------------------------------------=
//
// $Id: ImplAAFEdgecode.cpp,v 1.16 2004/02/27 14:26:47 stuart_hc Exp $ $Name:  $
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

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#ifndef __ImplAAFEdgecode_h__
#include "ImplAAFEdgecode.h"
#endif

#include "ImplAAFBuiltinDefs.h"
#include "ImplAAFDictionary.h"

#include <assert.h>
#include <string.h>

#include "AAFTypes.h"
#include "AAFResult.h"
#include "aafErr.h"
#include "aafCvt.h"
#include "AAFUtils.h"
#include "AAFDataDefs.h"

ImplAAFEdgecode::ImplAAFEdgecode ():
_start( PID_EdgeCode_Start, L"Start"),
_filmType( PID_EdgeCode_FilmKind, L"FilmKind"),
_edgeType( PID_EdgeCode_CodeFormat, L"CodeFormat"),
_header( PID_EdgeCode_Header, L"Header")
{
	_persistentProperties.put(_start.address());
	_persistentProperties.put(_filmType.address());
	_persistentProperties.put(_edgeType.address());
	_persistentProperties.put(_header.address());
}


ImplAAFEdgecode::~ImplAAFEdgecode ()
{}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFEdgecode::Initialize(aafLength_t		length,
								aafEdgecode_t	edgecode)
{
	HRESULT		rc = AAFRESULT_SUCCESS;
	
	XPROTECT()
	{
		ImplAAFDictionarySP pDict;
		CHECK(GetDictionary(&pDict));
		CHECK(SetNewProps(length,
						  pDict->GetBuiltinDefs()->ddEdgecode()));
		_start = edgecode.startFrame;
		if (edgecode.filmKind < kAAFFtNull || edgecode.filmKind > kAAFFt65MM)
			return AAFRESULT_INVALID_FILMTYPE;
		else
			_filmType = edgecode.filmKind;
		
		if (edgecode.codeFormat == kAAFEtNull || 
			edgecode.codeFormat == kAAFEtKeycode ||
			edgecode.codeFormat == kAAFEtEdgenum4 ||
			edgecode.codeFormat == kAAFEtEdgenum5 ||
			edgecode.codeFormat == kAAFEtHeaderSize)

			_edgeType = edgecode.codeFormat;
		else
			return AAFRESULT_INVALID_EDGETYPE;

		_header.setValue(edgecode.header, sizeof(edgecode.header));

	}
	XEXCEPT
	XEND;

	return rc;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFEdgecode::GetEdgecode (aafEdgecode_t * pEdgecode)
{
	HRESULT		rc = AAFRESULT_SUCCESS;

	if (pEdgecode == NULL)
		rc = AAFRESULT_NULL_PARAM;
	else
	{
		pEdgecode->startFrame = _start;
		pEdgecode->filmKind = _filmType;
		pEdgecode->codeFormat = _edgeType;
		_header.copyToBuffer(pEdgecode->header, sizeof(pEdgecode->header));
	}
	return rc;
}





