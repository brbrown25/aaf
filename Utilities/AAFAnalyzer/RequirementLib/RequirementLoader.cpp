//=---------------------------------------------------------------------=
//
// $Id: RequirementLoader.cpp,v 1.2 2005/10/13 19:33:58 ajakowpa Exp $
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

//Requirement files
#include "RequirementLoader.h"
#include "RequirementRegistry.h"
#include "RequirementXMLException.h"

//Expat files
#include <expat.h>

//Boost files
#include <boost/shared_ptr.hpp>

//STL files
#include <fstream>
#include <sstream>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{
    
using namespace std;
using namespace boost;

RequirementLoader::RequirementLoader()
{}

RequirementLoader::~RequirementLoader()
{}

void RequirementLoader::ParseXML( const char* filename ) const
{
    
    //Variables needed to run the expat XML parser.
    const int BUF_SIZE = 256;
    int done;
    char buffer[BUF_SIZE] = "";
    
    //Create the XML parser
    XML_Parser parser = XML_ParserCreate(NULL);
 
    //Setup event handlers for the XML parser.
    try
    {
        XML_SetElementHandler( parser, RequirementLoader::__StartElement, RequirementLoader::__EndElement);
        XML_SetCharacterDataHandler(parser, RequirementLoader::__EndData);
    }
    catch (...)
    {
        XML_ParserFree(parser);
        throw RequirementXMLException( L"Could not set parser's handler functions." );
    }

    //Use this object as the data used by all handlers.
    XML_SetUserData( parser, (void*)this );

    //Open the XML file for input.
    ifstream inp;
    inp.open( filename );

    //Parse the file using a buffer of the specified size.
    while ( !inp.eof() )
    {
        
        inp.read(buffer, BUF_SIZE);
        const size_t len = inp.gcount();
               
        done = len < sizeof(buffer);

        if ( !XML_Parse(parser, buffer, len, done) )
        {
            wostringstream msg;
            msg << L"expat error: " << XML_ErrorString(XML_GetErrorCode(parser));
            throw RequirementXMLException(msg.str().c_str() );
        }
    }
    
    XML_ParserFree(parser);
    
}

//Called when an open tag is encountered.
void RequirementLoader::StartElement(const wstring& name, const char** attribs)
{

    if ( name == L"requirement" )
    {
        wostringstream msg;
        msg << attribs[1];
        wstring type(msg.str().c_str() );
        msg.str(L"");
        msg << attribs[3];
        wstring category(msg.str().c_str() );

        if ( type == L"app" )
        {
            _currentType = Requirement::APP;
        }
        else if ( type == L"file" )
        {
            _currentType = Requirement::FILE;
        }
        else
        {
            wostringstream msg;
            msg << L"Unknown requirement type: " << type;
            throw RequirementXMLException(msg.str().c_str() );
        }
        
        if ( category == L"compositional" )
        {
            _currentCategory = Requirement::COMPOSITIONAL;
        }
        else if ( type == L"annotations" )
        {
            _currentCategory = Requirement::ANNOTATIONS;
        }
        else if ( type == L"ad-hoc" )
        {
            _currentCategory = Requirement::ADHOC;
        }
        else
        {
            wostringstream msg;
            msg << L"Unknown category: " << category;
            throw RequirementXMLException(msg.str().c_str() );
        }
        
    }
    else if ( name == L"id" )
    {
        _currentData = L"";
    }
    else if ( name == L"name" )
    {
        _currentData = L"";
    }
    else if ( name == L"desc" )
    {
        _currentData = L"";
    }
    else if ( name == L"doc" )
    {
        _currentData = L"";
    }
    else if ( name == L"version" )
    {
        _currentData = L"";
    }
    else if ( name == L"section" )
    {
        _currentData = L"";
    }
    else if ( name == L"ref" )
    {
        _currentData = L"";
    }
    else if ( name == L"requirement-set" )
    {
        _currentData = L"";
    }
    else if ( name == L"requirement-set-name" )
    {
        _currentData = L"";
    }
    else if ( name == L"requirement-set-version" )
    {
        _currentData = L"";
    }
    else
    {
        wostringstream msg;
        msg << L"Unknown tag: " << name;
        throw RequirementXMLException(msg.str().c_str() );
    }
    
}

//Called when a close tag is encountered.
void RequirementLoader::EndElement(const wstring& name)
{
    if ( name == L"requirement" )
    {
        shared_ptr<const Requirement> req(new Requirement(
            _currentId, _currentType, _currentCategory, _currentName,
            _currentDesc, _currentDocument, _currentVersion, _currentSection ));
        RequirementRegistry::GetInstance().Register( req );
    }
    else if ( name == L"id" )
    {
        _currentId = _currentData;
    }
    else if ( name == L"name" )
    {
        _currentName = _currentData;
    }
    else if ( name == L"desc" )
    {
        _currentDesc = _currentData;
    }
    else if ( name == L"doc" )
    {
        _currentDocument = _currentData;
    }
    else if ( name == L"version" )
    {
        _currentVersion = _currentData;
    }
    else if ( name == L"section" )
    {
        _currentSection = _currentData;
    }
    else if ( name == L"ref" )
    {
        //No defined behaviour
    }
    else if ( name == L"requirement-set" )
    {
        //No defined behaviour
    }
    else if ( name == L"requirement-set-name" )
    {
        //No defined behaviour
    }
    else if ( name == L"requirement-set-version" )
    {
        //No defined behaviour
    }
    else
    {
        wostringstream msg;
        msg << L"Unknown tag: /" << name;
        throw RequirementXMLException(msg.str().c_str() );
    }
    
}

//Called after a string of data (between tags) has been loaded.
void RequirementLoader::EndData(const wstring& contents)
{
    _currentData += contents;
}

//These three static functions are the callback functions called by the expat
//XML parser.  In all cases, the userData parameter refers to the object that'
//owns the XML parser.  The functions simply convert the necessary parameters
//to simpler data types and forward them to the necessary member function.
void RequirementLoader::__StartElement(void *userData, const char *name, const char **atts)
{
    RequirementLoader* me = (RequirementLoader*) userData;
    wostringstream msg;
    msg << name;
    
    //Note: The atts parameter is not changed to a shared pointer because
    //      the memory management is done by the XML parser.    
    me->StartElement( msg.str().c_str(), atts );
}

void RequirementLoader::__EndElement(void *userData, const char *name)
{
    RequirementLoader* me = (RequirementLoader*) userData;
    wostringstream msg;
    msg << name;
    me->EndElement( msg.str().c_str() );
}

void RequirementLoader::__EndData(void *userData, const char *s, int len)
{
     if (len != 0)
    {
        RequirementLoader* me = (RequirementLoader*) userData;
        wostringstream msg;
        msg << s;
        me->EndData( msg.str().substr(0, len).c_str() );
    }
}

} // end of namespace diskstream
