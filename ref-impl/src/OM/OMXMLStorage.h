//=---------------------------------------------------------------------=
//
// $Id: OMXMLStorage.h,v 1.1.2.2 2005/04/11 15:04:44 philipn Exp $ $Name:  $
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
// Licensor of the AAF Association is British Broadcasting Corporation.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef __OMXMLSTORAGE_H__
#define __OMXMLSTORAGE_H__

#include "OMRawStorage.h"
#include "OMXMLWriter.h"
#include "OMXMLReader.h"
#include "OMSymbolspace.h"
#include "OMWString.h"
#include "OMSet.h"
#include "OMDataStreamProperty.h"



class OMXMLStorage
{
public:
    OMXMLStorage(OMRawStorage* storage, bool isRead);
    ~OMXMLStorage();
    
    bool isRead();
    OMXMLWriter* getWriter();
    OMXMLReader* getReader();
    
    OMSymbolspace* getBaselineSymbolspace() const;
    OMSymbolspace* getDefaultExtSymbolspace() const;
    OMSymbolspace* createDefaultExtSymbolspace(OMClassId id);
    
    bool getSymbol(OMClassId id, const wchar_t** symbolspaceURI, const wchar_t** symbol) const;
    const wchar_t* getDefinitionSymbol(OMClassId id);
    OMClassId getId(const wchar_t* symbolspaceURI, const wchar_t* symbol) const;
    OMPropertyId getPropertyId(const wchar_t* symbolspaceURI, const wchar_t* symbol) const;
    OMClassId getId(const wchar_t* definitionSymbol) const;
    
    const wchar_t* getDataStreamNotationName(OMClassId typeId);
    const wchar_t* getDataStreamEntityName(void* ref);
    const wchar_t* getDataStreamEntityValue(void* ref);
    
    void forwardObjectSetId(const wchar_t* id);
    bool haveForwardedObjectSetId();
    wchar_t* getForwardedObjectSetId();
    
private:
    void loadStringIds();

    bool            _isRead;
    OMXMLWriter*    _xmlWriter;
    OMXMLReader*    _xmlReader;
    
    wchar_t*        _objectSetId;
    
    OMSymbolspace*  _baselineSymbolspace;
    OMSymbolspace*  _defaultExtSymbolspace;
    
    OMSet<OMWString, OMSymbolspace*> _symbolspaces;
    OMSet<OMClassId, OMWString> _idToDefSymbol;
    OMSet<OMWString, OMClassId> _defSymbolToId;

    int             _dataStreamNotationNameIndex;
    int             _dataStreamEntityNameIndex;
    int             _dataStreamEntityValueIndex;
    OMSet<OMClassId, OMWString> _dataStreamNotationNames;
    OMSet<void*, OMWString> _dataStreamEntityNames;
    OMSet<void*, OMWString> _dataStreamEntityValues;
};


#endif
