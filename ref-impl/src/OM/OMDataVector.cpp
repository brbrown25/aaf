//=---------------------------------------------------------------------=
//
// $Id: OMDataVector.cpp,v 1.1.2.1 2004/07/06 20:19:19 tbingham Exp $ $Name:  $
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
#if 0 // tjb - Not yet
  store()->save(*this);
#endif
}

void OMDataVector::restore(size_t externalSize)
{
  TRACE("OMDataVector::restore");
#if 0 // tjb - Not yet
  // tjb -- resize ?
  store()->restore(*this, externalSize);
  setPresent();
#endif
}
