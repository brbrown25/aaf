//=---------------------------------------------------------------------=
//
// $Id: OMDataSet.h,v 1.1.2.1 2004/07/06 18:58:43 tbingham Exp $ $Name:  $
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
#ifndef OMDATASET_H
#define OMDATASET_H

#include "OMProperty.h"
#include "OMDataContainer.h"

#include "OMDataTypes.h"

#include <stddef.h>

  // @class Abstract base class for persistent properties representing
  //        sets of data items supported by the Object Manager.
  //   @base public | <c OMProperty>
  //   @base public | <c OMDataContainer>
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMDataSet : public OMProperty,
                  public OMDataContainer {
public:
  // @access Public members.

     // @cmember Constructor.
  OMDataSet(const OMPropertyId propertyId,
            const OMStoredForm storedForm,
            const wchar_t* name);

   // @cmember Destructor.
  virtual ~OMDataSet(void);

    // @cmember Save this <c OMDataSet>.
  virtual void save(void) const;

    // @cmember Restore this <c OMDataSet>, the external (persisted)
    //          size of the <c OMDataSet> is <p externalSize>.
  virtual void restore(size_t externalSize);

    // @cmember The number of items in this this <c OMDataSet>.
  virtual size_t count(void) const = 0;

  virtual void insert(void* value) = 0;

  virtual size_t elementSize(void) const = 0;

private:

    // OMDataSet can't be assigned - declare but don't define
  OMDataSet& operator = (const OMDataSet& rhs);

    // OMDataSet can't be copied - declare but don't define
  OMDataSet(const OMDataSet& rhs);

};

#endif
