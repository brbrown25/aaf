#ifndef __ImplAAFFile_h__
#define __ImplAAFFile_h__
/***********************************************************************
 *
 *              Copyright (c) 1998-2001 Avid Technology, Inc.
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

#include "ImplAAFRoot.h"


//
// Forward declaration
//
class OMFile;
class OMRawStorage;
class ImplAAFDictionary;
class ImplAAFMetaDictionary;
class ImplAAFFile;
class ImplAAFRawStorage;
class ImplAAFHeader;
class ImplAAFDataDef;
class ImplAAFOMRawStorage;

struct IAAFRawStorage;
struct IAAFRandomRawStorage;

class ImplAAFFile : public ImplAAFRoot
{
public:

  //
  // methods to support API
  //

  virtual AAFRESULT STDMETHODCALLTYPE
	Initialize ();

  virtual AAFRESULT STDMETHODCALLTYPE
	Open ();

  virtual AAFRESULT STDMETHODCALLTYPE
	OpenExistingRead (const aafCharacter * pFileName,
					  aafUInt32 modeFlags);

  virtual AAFRESULT STDMETHODCALLTYPE
	OpenExistingModify (const aafCharacter * pFileName,
						aafUInt32 modeFlags,
						aafProductIdentification_t * pIdent);

  virtual AAFRESULT STDMETHODCALLTYPE
	OpenNewModify (const aafCharacter * pFileName,
				   aafUInt32 modeFlags,
				   aafProductIdentification_t * pIdent);

  virtual AAFRESULT STDMETHODCALLTYPE
	OpenTransient (aafProductIdentification_t * pIdent);

  virtual AAFRESULT STDMETHODCALLTYPE
    CreateAAFFileOnRawStorage (IAAFRawStorage * pRawStorage,
							   aafFileExistence_t existence,
							   aafFileAccess_t access,
							   aafUID_constptr pFileKind,
							   aafUInt32 modeFlags,
							   aafProductIdentification_constptr pIdent);

  virtual AAFRESULT STDMETHODCALLTYPE
	Close ();

  virtual AAFRESULT STDMETHODCALLTYPE
	Save ();

  virtual AAFRESULT STDMETHODCALLTYPE
	SaveAs (const aafCharacter * pFileName,
			aafUInt32 modeFlags);

  virtual AAFRESULT STDMETHODCALLTYPE
	SaveCopyAs (ImplAAFFile * pDestFile);

  virtual AAFRESULT STDMETHODCALLTYPE
	Revert ();

  virtual AAFRESULT STDMETHODCALLTYPE
	GetHeader (ImplAAFHeader ** header);

  virtual AAFRESULT STDMETHODCALLTYPE
	GetRevision (aafFileRev_t *  rev);
  
  virtual AAFRESULT STDMETHODCALLTYPE
    GetDictionary
        (ImplAAFDictionary ** ppDictionary) const;  //@parm [out,retval] The AAF Dictionary

  //
  // Constructor/destructor
  //
  //********
  ImplAAFFile ();
  virtual ~ImplAAFFile ();

protected:

  // Returns the OMFile associated with this AAFFile.  Requires
  // IsOpen().
  OMFile * omFile (void);

  bool IsReadable () const;
  bool IsWriteable () const;
  bool IsOpen () const;
  bool IsClosed () const;
  OMRawStorage * RawStorage ();

private:

  void InternalReleaseObjects();

  AAFRESULT pvtCreateExistingRead
    ();
  AAFRESULT pvtCreateExistingModify
    (aafProductIdentification_constptr pIdent);
  AAFRESULT pvtCreateNewModify
    (aafUID_constptr pFileKind,
	 aafProductIdentification_constptr pIdent);


  aafInt32			_cookie;
  OMFile			*_file;
  ImplAAFDictionary *_factory;
  ImplAAFMetaDictionary *_metafactory;
  aafInt16			_byteOrder;
  ImplAAFHeader *   _head;		// Needed by Head object
  aafBool   _semanticCheckEnable;	//!!!  /* Used to stop recursion in checks */
  aafFileRev_t   _setrev;
  aafBool _initialized;
  aafUInt32 _modeFlags;

  aafFileExistence_t _existence;
  aafFileAccess_t    _access;

  aafProductIdentification_t _preOpenIdent;
};

//
// smart pointer
//

#ifndef __ImplAAFSmartPointer_h__
// caution! includes assert.h
#include "ImplAAFSmartPointer.h"
#endif

typedef ImplAAFSmartPointer<ImplAAFFile> ImplAAFFileSP;

#endif // ! __ImplAAFFile_h__
