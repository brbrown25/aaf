//=---------------------------------------------------------------------=
//
// $Id: TestPhase.cpp,v 1.1 2005/08/18 14:07:23 greek_fire Exp $
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

#include "TestPhase.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

TestPhase::TestPhase(std::ostream& os)
: _os(os)
{
}

TestPhase::~TestPhase()
{
}

std::string TestPhase::GetDescription()
{
  std::string null;
  return null;
}

std::string TestPhase::GetName()
{
  std::string null;
  return null;
}

std::ostream& TestPhase::GetOutStream()
{
  return _os;
}

} // end of namespace diskstream
