###############################################################################
#
# $Id: GenAafPrivate_i.sh,v 1.8 2009/06/01 11:46:51 stuart_hc Exp $ $Name:  $
#
# The contents of this file are subject to the AAF SDK Public Source
# License Agreement Version 2.0 (the "License"); You may not use this
# file except in compliance with the License.  The License is available
# in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
# Advanced Media Workflow Association, Inc., or its successor.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
# the License for the specific language governing rights and limitations
# under the License.  Refer to Section 3.3 of the License for proper use
# of this Exhibit.
#
# WARNING:  Please contact the Advanced Media Workflow Association,
# Inc., for more information about any additional licenses to
# intellectual property covering the AAF Standard that may be required
# to create and distribute AAF compliant products.
# (http://www.amwa.tv/policies).
#
# Copyright Notices:
# The Original Code of this file is Copyright 1998-2009, licensor of the
# Advanced Media Workflow Association.  All rights reserved.
#
# The Initial Developer of the Original Code of this file and the
# licensor of the Advanced Media Workflow Association is
# Avid Technology.
# All rights reserved.
#
###############################################################################

echo "/* this file contains the actual definitions of */"
echo "/* the IIDs and CLSIDs */"
echo ""
echo "/* link this file in with the server and any clients */"
echo "//=--------------------------------------------------------------------------="
echo "// Definitions for all public IID's needed by an AAF SDK Plugin author"
echo "//=--------------------------------------------------------------------------="
echo "//"
echo ""
echo \#ifdef __cplusplus
echo "extern \"C\"{"
echo \#endif
echo ""
echo ""
for class in AAFRoot ${PRIVATE_AAFOBJECTS} ; do \
	awk -f dod2iid.awk C=$class $class.dod
done
echo \#ifdef __cplusplus
echo "}"
echo \#endif
echo ""
