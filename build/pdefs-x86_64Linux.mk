###############################################################################
#
# $Id: pdefs-x86_64Linux.mk,v 1.5 2007/04/13 17:09:14 stuart_hc Exp $ $Name:  $
#
# The contents of this file are subject to the AAF SDK Public
# Source License Agreement (the "License"); You may not use this file
# except in compliance with the License.  The License is available in
# AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
# Association or its successor.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code of this file is Copyright 1998-2004, Licensor of the
# AAF Association.
#
# The Initial Developer of the Original Code of this file and the
# Licensor of the AAF Association is Avid Technology.
# All rights reserved.
#
###############################################################################

#------------------------------------------------------------------------------
#
# pdefs-x86_64Linux.mk
#
#	This file contains makefile definitions for the Linux platform.
#
#
# Uses:
#	COMPILER, XL, RPATH, CC
#	
# Requires:
#	XL, RPATH, CC
#
# Sets:
#	MIPS_ABI, COMPILER, PLATFORM_CFLAGS, RPATH_OPT, 
#	LD, LD_STAT_LIB, LD_DYN_LIB, U_OPTS, OBJ, EXE, LIBEXT, DLL,
#
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# Include common linux-x86 definitions.
#------------------------------------------------------------------------------
include $(AAFBASE)/build/pdefs-i586Linux.mk

# -fPIC is necessary when building object code to be used in a shared library
PLATFORM_CFLAGS += -fPIC

# turn on k8 specific optimisations for Release builds
REL_FLAGS += -march=k8
