//@doc
//@class    AAFEssenceStream | Implementation class for AAFEssenceStream
#ifndef __CAAFEssenceDataStream_h__
#define __CAAFEssenceDataStream_h__

//=---------------------------------------------------------------------=
//
// $Id: CAAFEssenceDataStream.h,v 1.14 2007/03/16 18:00:13 akharkev Exp $ $Name:  $
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

#ifndef __AAFPlugin_h__
#include "AAFPlugin.h"
#endif


#ifndef __CAAFUnknown_h__
#include "CAAFUnknown.h"
#endif

// forward declaration
interface IAAFEssenceData;


EXTERN_C const CLSID CLSID_AAFEssenceDataStream;

class CAAFEssenceDataStream
  : public IAAFEssenceDataStream,
    public IAAFEssenceStream,
    public CAAFUnknown
{
protected:

  //********
  //
  // Constructor/destructor
  //
  CAAFEssenceDataStream (IUnknown * pControllingUnknown);
  virtual ~CAAFEssenceDataStream ();

public:
  //
  // IAAFEssenceDataStream methods.
  //

  // Initialize this instance with an IAAFEssenceData interface pointer
  // ba calling QueryInterface on the given IUnknown pointer.
  STDMETHOD (Init)
            (/* [in] */ IUnknown *essenceData);

  
  //
  // IAAFEssenceStream methods.
  //

  // Write some number of bytes to the stream exactly and with no formatting or compression.
  STDMETHOD(Write)
    (/*[in]*/ aafUInt32  bytes, // write this many bytes
     /*[out, size_is(bytes), length_is(*bytesWritten)]*/ aafDataBuffer_t  buffer, // here is the buffer
     /*[out,ref]*/ aafUInt32 *  bytesWritten); // return bytes actually written.

  // Read some number of bytes from the stream exactly and with no formatting or compression.
  STDMETHOD (Read)
    (/*[in]*/ aafUInt32  buflen, // to a buffer of this size
     /*[out, size_is(buflen), length_is(*bytesRead)]*/ aafDataBuffer_t  buffer, // here is the buffer
     /*[out,ref]*/ aafUInt32 *  bytesRead); // Return bytes actually read 

  // Seek to the absolute byte offset into the stream.
  STDMETHOD (Seek)
    (/*[in]*/ aafPosition_t  byteOffset); // The absolute byte offset into the stream. 

  // Seek forward or backward the given byte count.
  STDMETHOD (SeekRelative)
    (/*[in]*/ aafInt32  byteOffset); // The relative byte offset into the stream. 

  // Returns kAAFTrue if the byte offset is within the stream.
  STDMETHOD (IsPosValid)
    (/*[in]*/ aafPosition_t  byteOffset, // The absolute byte offset into the stream.
     /*[out]*/ aafBoolean_t *  isValid); // The result. 

  // Returns the position within the stream.
  STDMETHOD (GetPosition)
    (/*[out]*/ aafPosition_t *  position); // The position within the stream. 

  // Returns the length of the stream.
  STDMETHOD (GetLength)
    (/*[out]*/ aafLength_t *  position); // The length of the stream. 

  // Ensure that all bits are written.
  STDMETHOD (FlushCache)
     ();


  // Sets the size of the cache buffer used for further operations.
			// Destroys the current contents of the cache.
  STDMETHOD (SetCacheSize)
    (/*[in]*/ aafUInt32  itsSize); // The size of the cache buffer. 


  
  //
  // IUnknown methods. (Macro defined in CAAFUnknown.h)
  //

  AAF_DECLARE_STANDARD_UNKNOWN()

protected:
  // 
  // Declare the QI that implements for the interfaces
  // for this module. This will be called by CAAFUnknown::QueryInterface().
  // 
  STDMETHOD(InternalQueryInterface)(REFIID riid, void **ppvObjOut);


public:
  //
  // This class as concrete. All objects can be constructed from
  // a CLSID. This will allow subclassing all "base-classes" by
  // aggreggation.
  // 
  AAF_DECLARE_FACTORY();
  //


private:
	IAAFPlainEssenceData		*_data;
};

#endif // ! __CAAFEssenceDataStream_h__


