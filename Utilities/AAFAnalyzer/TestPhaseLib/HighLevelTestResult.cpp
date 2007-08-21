//=---------------------------------------------------------------------=
//
// $Id: HighLevelTestResult.cpp,v 1.3 2007/08/21 14:08:34 jptrainor Exp $
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

//Test/Result files
#include "HighLevelTestResult.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

using namespace std;

HighLevelTestResult::HighLevelTestResult()
  : TestResult()
{}

HighLevelTestResult:: HighLevelTestResult( const wstring& name, 
                                           const wstring& desc,
                                           const wstring& explain )
  : TestResult( name, desc, explain )
{}

HighLevelTestResult::~HighLevelTestResult()
{}

} // end of namespace diskstream
