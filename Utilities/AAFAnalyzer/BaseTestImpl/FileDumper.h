//=---------------------------------------------------------------------=
//
// $Id: FileDumper.h,v 1.2 2005/08/18 20:39:07 greek_fire Exp $ $Name:  $
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

#ifndef __FILEDUMPER_h__
#define __FILEDUMPER_h__

//project files
#include <Test.h>

namespace aafanalyzer {

class FileDumper : public Test
{
 public:
  FileDumper(std::ostream& os, boost::shared_ptr<TestGraph> spTestGraph);
  ~FileDumper();

  TestResult Execute();
  std::string GetName();
  std::string GetDescription();

 private:

  // prohibited
  FileDumper(const FileDumper&);
  FileDumper& operator=( const FileDumper& );
};

} // end of namespace diskstream

#endif/*__TEMPLATE_h__*/
