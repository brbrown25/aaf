//=---------------------------------------------------------------------=
//
// $Id: TestResult.h,v 1.1 2005/08/18 14:07:23 greek_fire Exp $ $Name:  $
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

#ifndef __TESTRESULT_h__
#define __TESTRESULT_h__

//stl files
#include <string>

namespace aafanalyzer {

class TestResult
{
 public:
  TestResult();
  TestResult& operator=(const TestResult& test);
  ~TestResult();

  enum Result {success = 0, warning, error};

  std::string GetExplanation();
  std::string GetDocumentRef();
  std::string GetName();
  std::string GetDescription();

  void SetExplanation(std::string exp);
  void SetName(std::string name);
  void SetDescription(std::string desc);

  void SetResult(Result result);
  enum Result GetResult();

 private:
  std::string _Expl;
  std::string _Name;
  std::string _Desc;
  enum Result _enum_result;

  // prohibited
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
