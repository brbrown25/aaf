//=---------------------------------------------------------------------=
//
// $Id: OMDataSet.cpp,v 1.1.2.2 2004/07/23 18:56:13 tbingham Exp $ $Name:  $
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
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMDataSet

#include "OMDataSet.h"

#include "OMAssertions.h"
#include "OMStoredObject.h"

OMDataSet::OMDataSet(const OMPropertyId propertyId,
                     const OMStoredForm storedForm,
                     const wchar_t* name)
: OMProperty(propertyId, storedForm, name)
{
  TRACE("OMDataSet::OMDataSet");
}

OMDataSet::~OMDataSet(void)
{
  TRACE("OMDataSet::~OMDataSet");
}

void OMDataSet::save(void) const
{
  TRACE("OMDataSet::save");
  store()->save(*this);
}

void OMDataSet::restore(size_t externalSize)
{
  TRACE("OMDataSet::restore");
  // tjb -- resize ?
  store()->restore(*this, externalSize);
  setPresent();
}
