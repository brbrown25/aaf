//=---------------------------------------------------------------------=
//
// $Id: FileOp.cpp,v 1.7.2.2 2004/06/09 17:21:26 asuraparaju Exp $ $Name:  $
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

#include <MultiGenTest.h>

#include "MultiGenCommon.h"

#include <AAFDefUIDs.h>
#include <AAFFileKinds.h>

#include "../../../../ref-impl/include/AAFSDKBuild.h"

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>

#include <stdlib.h>
#include <assert.h>

namespace {

class KindMap {
public:
  KindMap()
  {
    #define ADD_KIND( X ) \
    _kindMap[ string( #X ) ] = aafFileKindAaf##X;

    ADD_KIND( M512Binary );
    ADD_KIND( S512Binary );
    ADD_KIND( M4KBinary );
    ADD_KIND( S4KBinary );
  }

  ~KindMap()
  {}


  aafUID_t GetKind( const char* kindName )
  {
    std::map<std::string, aafUID_t >::const_iterator iter;
    iter = _kindMap.find( kindName );

    if ( iter == _kindMap.end() ) {
      std::stringstream what;
      what << "File kind unknown: " << kindName;
      throw UsageEx( what.str().c_str() );
    }

    return iter->second;
  }

private:
  std::map< std::string, aafUID_t > _kindMap;
};


class FileOp : public MultiGenTest
{ 
public:
  FileOp()
    : MultiGenTest()
  {}

  virtual ~FileOp()
  {}

  virtual void RunTest( CmdState& state, int argc, char** argv );
};

IAAFSmartPointer<IAAFFile> CreateFileOfKind( const std::string& fileName,
					     aafFileExistence_e existance,
					     aafFileAccess_e access,
					     const aafUID_t& fileKind,
					     const aafProductIdentification_t& prodId )
{
  std::auto_ptr<wchar_t> wfileName( ToWideString( fileName.c_str() ) );

  IAAFSmartPointer<IAAFRawStorage> spRawStorage;
  CHECK_HRESULT( AAFCreateRawStorageDisk( wfileName.get(),
					  existance,
					  access,
					  &spRawStorage) );
  
  IAAFSmartPointer<IAAFFile> spFile;
  CHECK_HRESULT( AAFCreateAAFFileOnRawStorage( spRawStorage,
					       existance,
					       access,
					       &fileKind,
					       0,
					       &prodId,
					       &spFile));

  return spFile;
}

void FileOp::RunTest( CmdState& state, int argc, char** argv )
{
  using namespace std;
	
  IAAFSmartPointer<IAAFFile> iaafFile;

  aafProductVersion_t v;
  aafProductIdentification_t	productInfo;
  v.major = 1;
  v.minor = 0;
  v.tertiary = 0;
  v.patchLevel = 0;
  v.type = kAAFVersionUnknown;
  productInfo.companyName = L"AAF Developers Desk";
  productInfo.productName = L"AAF MultiGenTest";
  productInfo.productVersion = &v;
  productInfo.productVersionString = NULL;
  productInfo.productID = UnitTestProductID;
  productInfo.platform = NULL;

  if ( argc < 2 ) {
    throw UsageEx("FileOp requires least one argument.");
  }

  string which(argv[1]);

  if ( which == "write" || which == "read" || which == "modify" ) {

    if ( argc != 4 ) {
      throw UsageEx("FileOp write|read|modify expects 3 arguments.");
    }

    std::string fileName( argv[3] );
    IAAFSmartPointer<IAAFFile> spFile;
    
    std::string kind( argv[2] );
    
    KindMap kmap;
    aafUID_t fileKind = kmap.GetKind( argv[2] );
    
    aafFileExistence_e existance;
    aafFileAccess_e access;
    
    if ( which == "write" ) {
      existance = kAAFFileExistence_new;
      access = kAAFFileAccess_modify;
    }
    else if ( which == "read" ) {
      existance = kAAFFileExistence_existing;
      access = kAAFFileAccess_read;
    }
    else if ( which == "modify" ) {
      existance = kAAFFileExistence_existing;
      access = kAAFFileAccess_modify;
    }
    else {
      assert(0);
    }
    
    spFile =
      CreateFileOfKind( fileName,
			existance,
			access,
			fileKind,
			productInfo );
    
    CHECK_HRESULT( spFile->Open() );

    state.SetFile( spFile );
  }
  else if ( which == "save" ) {
    CHECK_HRESULT( state.GetFile()->Save() );
  }
  else if ( which == "close" ) {
    CHECK_HRESULT( state.GetFile()->Close() );
  }
  else if ( which == "save_and_close" ) {
    CHECK_HRESULT( state.GetFile()->Save() );
    CHECK_HRESULT( state.GetFile()->Close() );
  }
  else {
    string msg("FileOp option unrecognized: " + which);
    throw UsageEx( msg );
  }
}

StandardFactory<FileOp> factory(
  "FileOp",
  "File Operations",
  "{ (write|read|modify M512Binary|S512Binary|M4KBinary|S4KBinary filename} | save | close | save_and_close }",
  "",
  2, 4
  );

} // end of namespace
