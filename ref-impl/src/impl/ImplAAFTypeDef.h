//@doc
//@class    AAFTypeDef | Implementation class for AAFTypeDef
#ifndef __ImplAAFTypeDef_h__
#define __ImplAAFTypeDef_h__

/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 * prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/


#ifndef __ImplAAFMetaDefinition_h__
#include "ImplAAFMetaDefinition.h"
#endif

#ifndef OMTYPE_H
#include "OMType.h"
#endif

class ImplAAFTypeDef : public ImplAAFMetaDefinition, public OMType
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFTypeDef ();

protected:
  virtual ~ImplAAFTypeDef ();

public:

  //****************
  // GetTypeCategory()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetTypeCategory
        // @parm [out] Returned type category
        (eAAFTypeCategory_t *  pTid);


  //****************
  // RawAccessType()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RawAccessType
        // @parm [out] the raw access type definition
        (ImplAAFTypeDef ** ppRawTypeDef);


  //
  // non-published methods
  //

  // Returns true if property values of this type are of a fixed size.
  virtual aafBool IsFixedSize (void) const;

  // If this->IsFixedSize(), then will return the size of property
  // values of this type.  If not fixed size, will assert().
  virtual size_t PropValSize (void) const;

  // Returns true if offsets have been registered for this type def.
  virtual aafBool IsRegistered (void) const;

  // Will attempt to identify this as a built-in type; if it is, will
  // register the offsets.
  virtual void AttemptBuiltinRegistration (void);

  // If this->IsRegistered(), then will return the native in-memory
  // size of this type.  If not registered, will assert().
  virtual size_t NativeSize (void) const;

  //*************************************************************
  //
  // Overrides from OMType, via inheritace through ImplAAFTypeDef
  //
  //*************************************************************

  virtual void reorder(OMByte* bytes,
                       size_t bytesSize) const;

  virtual size_t externalSize(OMByte* internalBytes,
                              size_t internalBytesSize) const;

  virtual void externalize(OMByte* internalBytes,
                           size_t internalBytesSize,
                           OMByte* externalBytes,
                           size_t externalBytesSize,
                           OMByteOrder byteOrder) const;

  virtual size_t internalSize(OMByte* externalBytes,
                              size_t externalSize) const;

  virtual void internalize(OMByte* externalBytes,
                           size_t externalBytesSize,
                           OMByte* internalBytes,
                           size_t internalBytesSize,
                           OMByteOrder byteOrder) const;

  // Allocate an OMProperty that can represent this type.  Implemented
  // by derived classes.
  virtual OMProperty *
    pvtCreateOMProperty (OMPropertyId pid,
							const wchar_t * name) const;


  //
  // Pure virtual methods to assist in the composition of types.  Each
  // type must implement these, to assist other types in determining
  // if particular aggregations are legal.
  //

  // Returns true if aggregates (that is, Record types) may be made
  // using this type as an element.
  virtual bool IsAggregatable () const;

  // Returns true if this type may be used as an element of a stream.
  virtual bool IsStreamable () const;

  // Returns true if this type may be used as an element of a
  // fixed-size array.
  virtual bool IsFixedArrayable () const;

  // Returns true if this type may be used as an element of a
  // variably-size array.
  virtual bool IsVariableArrayable () const;

  // Returns true if this type may be used as an element of a string.
  virtual bool IsStringable () const;


  // override from OMStorable.
  virtual const OMClassId& classId(void) const;

  // Override callbacks from OMStorable
  virtual void onSave(void* clientContext) const;
  virtual void onRestore(void* clientContext) const;

protected:
  // Helper function to return the raw type of UInt8Array (if
  // applicable for the derived type)
  virtual AAFRESULT STDMETHODCALLTYPE
    pvtGetUInt8Array8Type
        (ImplAAFTypeDef ** ppRawTypeDef);
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFTypeDef> ImplAAFTypeDefSP;

#endif // ! __ImplAAFTypeDef_h__
