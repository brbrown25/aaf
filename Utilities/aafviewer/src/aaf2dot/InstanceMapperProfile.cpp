/*
 * $Id: InstanceMapperProfile.cpp,v 1.2 2004/02/27 16:41:24 stuart_hc Exp $ $Name:  $
 *
 *      Copyright (c) 2003, Philip de Nier (philipn@users.sourceforge.net)
 *
 *
 *      This file is part of aaf2dot.
 *
 *  aaf2dot is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  aaf2dot is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with aaf2dot; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#pragma warning (disable:4786)

#include <iostream>
using namespace std;

#include <InstanceMapperProfile.h>
#include <Logging.h>


//-----------------------------------------------------------------------------
InstanceMapperProfile::InstanceMapperProfile() 
   : _dataDefRefs( true ), _onlyFirstDataDefRefs( false ), _dictionary( true ), 
     _taggedValues( true ), _maxAttributeLength( 128 ), _maxAttributeWidth( 40 ),
     _concentrate( false ), _cluster( false ), _debug( false ) 
{
}


//-----------------------------------------------------------------------------
InstanceMapperProfile::~InstanceMapperProfile()
{
}

