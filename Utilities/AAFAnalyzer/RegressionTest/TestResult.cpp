//=---------------------------------------------------------------------=
//
// $Id: TestResult.cpp,v 1.1 2005/08/11 20:04:16 greek_fire Exp $
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

#include "TestResult.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

TestResult::TestResult()
{
}

TestResult::~TestResult()
{
}

TestResult::TestResult(const TestResult& test)
{
}

TestResult& TestResult::operator=(const TestResult& test)
{
  if(this != &test)
  {
  }

  return *this;
}

} // end of namespace diskstream
