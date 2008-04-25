//=---------------------------------------------------------------------=
//
// $Id: OMDataStreamAccess.h,v 1.6 2008/04/25 18:58:40 vladimirg2 Exp $ $Name:  $
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
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMINTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMDataStreamAccess
#ifndef OMDATASTREAMACCESS_H
#define OMDATASTREAMACCESS_H

class OMDataStream;

  // @class Provide deferred access to <c OMDataStream> properties.
  //        This permits clients to construct objects "bottom up",
  //        and to supply the data for <c OMDataStream> properties only
  //        after the objects are complete.
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMDataStreamAccess {
public:
  // @access Public members.

    // @cmember Constructor.
  OMDataStreamAccess(void* context);
  /*
  If the OMDataStreamAccess destructor is NOT virtual,
  then classes which inherit from OMDataStreamAccess 
  can leak memory when freed from a OMDataStreamAccess pointer.
  If an object from a derived class is referenced 
  by a OMDataStreamAccess pointer and is freed from that pointer,
  then the NON virtual destructor of OMDataStreamAccess executes
  but the destructor of the derived object does NOT execute,
  the derived object is "sheered" and leaks memory. 
  If no destructor for OMDataStreamAccess is written then the C++
  compiler will auto-generate a NON virtual destructor and there 
  will be memory leaks.*/
  virtual ~OMDataStreamAccess() {}

    // @cmember Save data to the given <c OMDataStream> object.
    //          This is a call back function supplied by the client.
    //          The client is passed the opaque context
    //          used to construct this <c OMDataStreamAccess> object.
  virtual void save(OMDataStream& stream, void* context) = 0;

    // @cmember Save data to the given <c OMDataStream> object.
  void save(OMDataStream& stream);

private:
  void* _context;

};

#endif
