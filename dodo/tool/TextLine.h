#ifndef _TextLine_h_
#define _TextLine_h_
/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/

#ifndef _SourceInfo_h_
#include "SourceInfo.h"
#endif


struct TextLine
{
  TextLine ();
  ~TextLine ();
  TextLine (const TextLine & src);
  TextLine operator= (const TextLine & src);
  //
  // Default ctor, dtor, copy ctor, op=
  //
  //********

  int Init
	(const char * text);			// [in] input text
  //
  // Fills this TextLine with the given text, discarding any
  // previously contained text.  Reads text until either the end of
  // the text, or until (and including) the first non-eescaped
  // newline.  Returns the number of characters consumed.
  //
  // Returns:
  //  Number of characters taken from text.
  //
  //********


  int GetLength () const;
  //
  // Returns:
  //  number of characters in this line, including any trailing
  //  newline but not any trailing null.
  //
  //********


  bool Append
	(char c);
  //
  // Attempts to append c to the end of this line.  Will succeed if
  // this line does not yet end in a non-escaped newline.
  //
  // Returns:
  //  true if succeeded
  //  false if failed.
  //
  //********


  bool Consume
	(char & c);		// [out] destination for char to be retrieved
  //
  // Consumes one character from beginning of this text line.
  //
  // Returns:
  //  true if successful, false if stream is empty.
  //
  //********


  SourceInfo GetSourceInfo () const;
  //
  // Returns:
  //  current source info with reference to the original source file.
  //
  //********


  void SetSourceInfo
	(const SourceInfo & si);
  //
  // Sets the cached filename and line number information for this
  // TextLine.
  //
  //********


  static void Test ();
  //
  // Unit test.  assert()s if an error is found.
  //
  //********

private:

  void allocate
	(const char * text);
  //
  // helper function for copy ctor and op=
  //
  //********


  SourceInfo	_sourceInfo;	// file/line information about where
								// this came from
  char * 		_pStorage;		// head of allocated storage for text
  unsigned int	_numAllocated;	// number of bytes allocated
  char * 		_pData;			// head of non-consumed data within _pStorage
};

#endif // ! _TextLine_h_
