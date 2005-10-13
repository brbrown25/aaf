//=---------------------------------------------------------------------=
//
// $Id: FileLoad.h,v 1.6 2005/10/13 19:33:58 ajakowpa Exp $ $Name:  $
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

#ifndef __FILELOAD_h__
#define __FILELOAD_h__

//Test/Result files
#include <Test.h>

//Ax files
#include <AxTypes.h>

namespace aafanalyzer {
    
using namespace std;
using namespace boost;

class TestLevelTestResult;
class AAFGraphInfo;

class FileLoad : public Test
{
 public:
  FileLoad(wostream& os, const basic_string<wchar_t> AAFFile);
  ~FileLoad();

  shared_ptr<TestLevelTestResult> Execute();
  AxString GetName() const;
  AxString GetDescription() const;
  shared_ptr<const AAFGraphInfo> GetTestGraphInfo();
  static const TestInfo GetTestInfo();

 private:
  const basic_string<wchar_t> _File;
  shared_ptr<const AAFGraphInfo> _spGraphInfo;

  // prohibited
  FileLoad(const FileLoad&);
  FileLoad& operator=( const FileLoad& );
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
