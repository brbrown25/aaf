//=---------------------------------------------------------------------=
//
// $Id: DerivationChainParser.h,v 1.1 2007/09/23 14:13:44 jptrainor Exp $
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

#ifndef __DERIVATIONCHAINPARSER_H_
#define __DERIVATIONCHAINPARSER_H_

//Requirement files
#include <Requirement.h>

//Ax files
#include <AxTypes.h>

//Boost files
#include <boost/shared_ptr.hpp>

//STL files
#include <map>
#include <stack>
#include <vector>

namespace aafanalyzer {

using namespace std;
using namespace boost;

class TestLevelTestResult;

class DerivationChainParser
{
 public:
  
  typedef aafUID_t EventID;

  // The following two event ids are used to identify end-of-chain
  // source clips and out-of-file source clips.  The other events use
  // existing AAF class, and usages codes, as event ids. These are
  // necessary because no AAF usage codes map to these meanings of
  // source clip.

  static const EventID EOC_EVENT_ID;
  static const EventID OOF_EVENT_ID;

  DerivationChainParser( wostream& log,
			 shared_ptr<TestLevelTestResult> spTestResult );
  ~DerivationChainParser();
  
  static bool IsKnownEvent( const aafUID_t event );

  // "Send" event to cause transition. "objName" is the name of object
  // associated with the event. "detail" and "requirements" return
  // results. True is returned if the the transition is successfull,
  // false if not.
  // Test results are added to spTestResult.
  bool Transition( const EventID& event,
                   const AxString& nextName );

  // Retrns true if the parser has reached a valid end state (no
  // further events can be parsed).
  bool IsInEndState() const;

  // Call to verify the end state is value after processing all available tokens.
  void CheckEndState();
  
  // Add a detail message the is formated (i.e. indented) the same way
  // the the messages generated internally by this class are formated.
  // Detail prefix is "OK" if ok is true, else "FAIL".
  void AddDetail( bool ok, const wstring& detail );

 private:
 
  // prohibited
  DerivationChainParser();
  DerivationChainParser( const DerivationChainParser& );
  DerivationChainParser& operator=( const DerivationChainParser& );

  enum State { INITIAL, TOP_LEVEL, LOWER_LEVEL, SUB_CLIP, ADJUSTED_CLIP,
               TEMPLATE_CLIP, CLIP, FILE_SOURCE, RECORDING_SOURCE, IMPORT_SOURCE,
               TAPE_SOURCE, FILM_SOURCE,
               EOC, // End Of Chain (zero valued source clip mob id)
               OOF  // Out Of File  (out of file reference)
             };
 
  AxString Indent();

public:
  typedef map<pair<const State, const EventID>, State> TransitionMap;
  typedef map<EventID, AxString> EventMap;
  typedef wstring ReqIdType;
  typedef map<State, ReqIdType> StateToReqMap;
  typedef map<State, AxString> StateNameMap;

private:

  // Static maps that initialized the first time the
  // the class is used
  static bool _staticInitFlag;
  static TransitionMap _transitionMap;
  static EventMap _eventMap;
  static StateToReqMap _stateToReqMap;
  static StateNameMap _stateNameMap;

  friend class DerivationChainParserGlobalInit;

  static void StaticInit();
  static void InitTransitions();
  static void InitEvents();
  static void InitStateToReq();
  static void InitStateNames();

  void AddNotationalResult( const wstring& nextName,
			    State currentState );

  void AddFinalNotationalResult();

  void AddParseErrorResults( const wstring& curName,
			     const wstring& nextName,
			     const EventID& event,
			     State currentState );

  // state variables
  stack<State> _currentState;
  stack<wstring> _objNameStack;
  wostream& _log;
  shared_ptr<TestLevelTestResult> _spTestResult;
};

} // end of namespace aafanalyzer

#endif /*__DERIVATIONCHAINSTATEMACHINE_H_*/
