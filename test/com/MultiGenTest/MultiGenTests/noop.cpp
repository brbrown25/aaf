//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
//=---------------------------------------------------------------------=

#include <MultiGenTest.h>

namespace {

STANDARD_TEST_DECLARATION(Noop);
StandardFactory<Noop> NoopFactory(
  "Noop",
  "No Description",
  "No Usage",
  "No Description",
  1, // Minimum number of args (Noop itself counts as one)
  5  // Maximum number of args (-1 if unlimited)
  );

void Noop::RunTest( CmdState& state, int argc, char** argv)
{
  // Avoid "not used" compiler errors...
  (void)state;
  (void)argc;
  (void)argv;
}

} // end of namespace
