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

#include "MultiGenCommon.h"

#include <assert.h>

#include <string>
#include <memory>

namespace {

STANDARD_TEST_DECLARATION(RegPlugins);
StandardFactory<RegPlugins> RegPluginsFactory(
  "RegPlugins",
  "Register plugins",
  "full path to plugin library to load",
  "",
  2,2
  );

void RegPlugins::RunTest( CmdState& state, int argc, char **argv )
{
  IAAFSmartPointer<IAAFPluginManager> mgr;

  CHECK_HRESULT( AAFGetPluginManager(&mgr) );

  auto_ptr<wchar_t> wpath( ToWideString(argv[1]) );

  CHECK_HRESULT( mgr->RegisterPluginFile( wpath.get() ) );
}

class LoadLib : public MultiGenTest
{ 
public:
  LoadLib()
    : MultiGenTest()
  {}

  virtual ~LoadLib()
  {}

  virtual void RunTest( CmdState& state, int argc, char** argv );
};

void LoadLib::RunTest( CmdState& state, int argc, char** argv )
{
  string name( argv[0] );

  if ( name == "LoadLib" ) {
    if ( argc != 2 ) {
      throw UsageEx( "LoadLib expects a single argument that is the full path to the COM library." );
    }
    CHECK_HRESULT( AAFLoad( argv[1] ) );
  }
  else {
    assert( name == "UnloadLib" );
    if ( argc != 1 ) {
      throw UsageEx( "UnloadLib expects no arguments." );
    }
	state.ClearPriorToUnload();
    CHECK_HRESULT( AAFUnload() );
  }
}

StandardFactory<LoadLib> loadFactory (
  "LoadLib",
  "Load COM library.",
  "full path to com library",
  "This is the only way that MultiGenTest will load the AAF COM library.",
  2,2
);

StandardFactory<LoadLib> unloadFactory (
  "UnloadLib",
  "Unload COM library.",
  "",
  "",
  1,1
);

} // end of namespace
