//=---------------------------------------------------------------------=
//
// $Id: OMDataVector.cpp,v 1.3 2006/06/15 03:23:24 tbingham Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2006, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMEXTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMDataVector

#include "OMDataVector.h"

#include "OMProperty.h"
#include "OMStoredObject.h"

#include "OMAssertions.h"

OMDataVector::OMDataVector(const OMPropertyId propertyId,
                           const OMStoredForm storedForm,
                           const wchar_t* name)
: OMProperty(propertyId, storedForm, name)
{
  TRACE("OMDataVector::OMDataVector");
}

OMDataVector::~OMDataVector(void)
{
  TRACE("OMDataVector::~OMDataVector");
}

void OMDataVector::save(void) const
{
  TRACE("OMDataVector::save");
  store()->save(*this);
}

void OMDataVector::restore(OMPropertySize externalSize)
{
  TRACE("OMDataVector::restore");

  // tjb -- resize ?
  store()->restore(*this, externalSize);
  setPresent();
}
