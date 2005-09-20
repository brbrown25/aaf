//=---------------------------------------------------------------------=
//
// $Id: RequirementLoader.cpp,v 1.1 2005/09/20 17:35:39 ajakowpa Exp $
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

#include "RequirementLoader.h"
#include "RequirementRegistry.h"
#include "RequirementXMLException.h"

#include <fstream>
#include <sstream>

//Expat Files
#include <expat.h>

//Boost files
#include <boost/shared_ptr.hpp>

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

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
    std::ifstream inp;
    inp.open( filename );

    //Parse the file using a buffer of the specified size.
    while ( !inp.eof() )
    {
        
        inp.read(buffer, BUF_SIZE);
        const size_t len = inp.gcount();
               
        done = len < sizeof(buffer);

        if ( !XML_Parse(parser, buffer, len, done) )
        {
            std::wostringstream msg;
            msg << L"expat error: " << XML_ErrorString(XML_GetErrorCode(parser));
            throw RequirementXMLException(msg.str().c_str() );
        }
    }
    
    XML_ParserFree(parser);
    
}

//Called when an open tag is encountered.
void RequirementLoader::StartElement(const AxString& name, const char** attribs)
{

    if ( name == L"requirement" )
    {
        std::wostringstream msg;
        msg << attribs[1];
        AxString type(msg.str().c_str() );
        msg.str(L"");
        msg << attribs[3];
        AxString category(msg.str().c_str() );

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
            std::wostringstream msg;
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
            std::wostringstream msg;
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
        std::wostringstream msg;
        msg << L"Unknown tag: " << name;
        throw RequirementXMLException(msg.str().c_str() );
    }
    
}

//Called when a close tag is encountered.
void RequirementLoader::EndElement(const AxString& name)
{
    if ( name == L"requirement" )
    {
        boost::shared_ptr<const Requirement> req(new Requirement(
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
        std::wostringstream msg;
        msg << L"Unknown tag: /" << name;
        throw RequirementXMLException(msg.str().c_str() );
    }
    
}

//Called after a string of data (between tags) has been loaded.
void RequirementLoader::EndData(const AxString& contents)
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
    std::wostringstream msg;
    msg << name;
    
    //Note: The atts parameter is not changed to a shared pointer because
    //      the memory management is done by the XML parser.    
    me->StartElement( msg.str().c_str(), atts );
}

void RequirementLoader::__EndElement(void *userData, const char *name)
{
    RequirementLoader* me = (RequirementLoader*) userData;
    std::wostringstream msg;
    msg << name;
    me->EndElement( msg.str().c_str() );
}

void RequirementLoader::__EndData(void *userData, const char *s, int len)
{
     if (len != 0)
    {
        RequirementLoader* me = (RequirementLoader*) userData;
        std::wostringstream msg;
        msg << s;
//std::wcerr << msg.str() << std::endl;
//std::wcerr << msg.str().substr(0, len) << std::endl;
        me->EndData( msg.str().substr(0, len).c_str() );
    }
}

} // end of namespace diskstream
