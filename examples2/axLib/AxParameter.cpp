//=---------------------------------------------------------------------=
//
// $Id: AxParameter.cpp,v 1.2 2004/09/02 12:51:02 jptrainor Exp $
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

#include "AxParameter.h"

//=---------------------------------------------------------------------=

AxParameter::AxParameter( IAAFParameterSP spIaafParameter )
  : AxObject( AxQueryInterface<IAAFParameter, IAAFObject>( spIaafParameter ) ),
    _spIaafParameter( spIaafParameter )
{}

AxParameter::~AxParameter()
{}

IAAFParameterDefSP AxParameter::GetParameterDefinition()
{
  IAAFParameterDefSP spParamDef;
  CHECK_HRESULT( _spIaafParameter->GetParameterDefinition( &spParamDef ) );
  return spParamDef;
}

//=---------------------------------------------------------------------=

AxConstantValue::AxConstantValue( IAAFConstantValueSP spIaafConstantValue )
  : AxParameter( AxQueryInterface<IAAFConstantValue, IAAFParameter>( spIaafConstantValue ) ),
    _spIaafConstantValue( spIaafConstantValue )
{}

AxConstantValue::~AxConstantValue()
{}

void AxConstantValue::Initialize( IAAFParameterDefSP spParameterDef,
				  aafUInt32 valueSize,
				  aafDataBuffer_t pValue )
{
  CHECK_HRESULT( _spIaafConstantValue->Initialize( spParameterDef, valueSize, pValue ) );
}

void AxConstantValue::GetValue( aafUInt32 valueSize,
				aafDataBuffer_t pValue,
				aafUInt32* bytesRead )
{
  CHECK_HRESULT( _spIaafConstantValue->GetValue( valueSize, pValue, bytesRead ) );
}

//=---------------------------------------------------------------------=

AxVaryingValue::AxVaryingValue( IAAFVaryingValueSP spIaafVaryingValue )
  : AxParameter( AxQueryInterface<IAAFVaryingValue, IAAFParameter>( spIaafVaryingValue ) ),
    _spIaafVaryingValue( spIaafVaryingValue )
{}

AxVaryingValue::~AxVaryingValue()
{}

//=---------------------------------------------------------------------=
