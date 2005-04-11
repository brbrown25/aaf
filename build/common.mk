###############################################################################
#
# $Id: common.mk,v 1.12.4.1 2005/04/11 14:57:39 philipn Exp $ $Name:  $
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


#----------------------------------------------------------
# Determine the platform we're building on and include
# platfrom specific definitions.
# N.B. Requires GNU Make for the $(shell ...) command -
# see http://www.gnu.org/software/make/make.html
#----------------------------------------------------------
ifndef AAFPLATFORM
    AAFPLATFORM = $(shell $(AAFBASE)/build/aafplatform.sh)
endif

include $(AAFBASE)/build/pdefs-$(AAFPLATFORM).mk

#--------------------------------------------------------------------------
# Optional DV functionality requires libdv and can be turned on using e.g.
# make LIBDV_PATH=/usr/lib
#
# libdv is used to provide DV functionality in the CDCI codec.
#--------------------------------------------------------------------------
ifdef LIBDV_PATH
    ifneq "$(LIBDV_PATH)" "/usr/lib"
        ADD_CFLAGS += -I$(LIBDV_PATH)/include
        OPT_CODEC_LIBS += -L$(LIBDV_PATH)
    endif
    ADD_CFLAGS += -DUSE_LIBDV
    OPT_CODEC_LIBS += -ldv
endif

#--------------------------------------------------------------------------
# Optional libgsf support is enabled by the LIBGSF_PATH variable which must
# contain the path to the installed libgsf includes and library e.g.
# make LIBGSF_PATH=/usr/local
#
# libgsf itself requires glib (for gobject and glib calls) and zlib
#--------------------------------------------------------------------------
ifdef LIBGSF_PATH
    PLATFORMLIBS += -L$(LIBGSF_PATH)/lib -lgsf-1 -lgobject-2.0 -lglib-2.0 -lz
    ADD_CFLAGS += -I$(LIBGSF_PATH)/include -I$(LIBGSF_PATH)/include/glib-2.0 -I$(LIBGSF_PATH)/lib/glib-2.0/include -I$(LIBGSF_PATH)/include/libgsf-1 -DUSE_LIBGSF
endif


#--------------------------------------------------------------------------
# Prototype AAF-XML stored format support can be turned on using e.g.
# make LIBEXPAT_PATH=/usr/local
#--------------------------------------------------------------------------
ifdef LIBEXPAT_PATH
    PLATFORMLIBS += -L$(LIBEXPAT_PATH)/lib -lexpat
    ADD_CFLAGS += -I$(LIBEXPAT_PATH)/include -DHAVE_EXPAT
endif


#----------------------------------------------------------
# AAFBUILDDIR is the directory where all the binaries will 
# be placed. It's located in AAF toolkit directory and has
# two components: platform name generated above and 
# compiler name defined in the platfrom specific 
# definitions file.
#----------------------------------------------------------
AAFBUILDDIR = $(AAFBASE)/AAF$(AAFPLATFORM)SDK/$(COMPILER)


#----------------------------------------------------------
# Define AAFTARGET and related variables.
# There are three supported build types: Debug (default) 
# Debug-static (as statically linked Debug build) and
# Release. To change default setting a user can specify 
# AAFTARGET as a parameter to the make command:
#
#	make AAFTARGET=Release
#	make AAFTARGET=Debug-static
#
#----------------------------------------------------------
# Define default target build
ifndef AAFTARGET
    AAFTARGET = Debug
endif

# Define target build subdirectory.
ifeq ($(AAFTARGET), Debug)
    AAFTARGETDIR = debug
else
    ifeq ($(AAFTARGET), Debug-static)
        AAFTARGETDIR = debug
    else
        AAFTARGETDIR = .
    endif
endif

# Update DBG_FLAGS depending on build target.
ifeq ($(findstring Debug, $(AAFTARGET)), Debug)
    # Add debug flags if -D_DEBUG is not already present
    ifneq ($(findstring -D_DEBUG, $(DBG_FLAGS)), -D_DEBUG)
        DBG_FLAGS += -D_DEBUG -DOM_DEBUG -DOM_STACK_TRACE_ON_ASSERT
    endif
else
ifeq ($(AAFTARGET), Release)
    ifneq ($(findstring -DNDEBUG, $(DBG_FLAGS)), -DNDEBUG)
        DBG_FLAGS = -DNDEBUG $(REL_FLAGS)
    endif
endif
endif

ifeq ($(AAFTARGET), Debug-static)
    DBG_FLAGS += -DDISABLE_DYNAMIC_LOADING
endif

#----------------------------------------------------------
# AAFSDK controls the directories where SDK libraries and 
# includes will be copied and applications (tests,examples,
# utils) will be built.
# The default setting is the AAF tollkit build directory.
# Common alternatives include:
#	AAFSDK=/usr/local
#	AAFSDK=/opt/AAF
#----------------------------------------------------------
ifndef AAFSDK
    AAFSDK = $(AAFBUILDDIR)
endif
AAFSDKINCLUDEDIR  = $(AAFSDK)/include
AAFSDKBINDIR      = $(AAFSDK)/bin/$(AAFTARGETDIR)
AAFSDKLIBDIR      = $(AAFSDK)/lib/$(AAFTARGETDIR)


#----------------------------------------------------------
# Put compiler specific flags in CFLAGS
# CFLAGS components are defined in platform-specific 
# definitions file pdefs-$(AAFPLATFORM).mk
#----------------------------------------------------------
CFLAGS = $(DBG_FLAGS) $(ADD_CFLAGS) $(PLATFORM_CFLAGS) $(BYTE_ORDER)

# U_OPTS should be defined as whether use_unicode or 
# no_unicode in platform-specific .def file
ifeq ($(U_OPTS), use_unicode)
    CFLAGS += -D_UNICODE=1
endif


#----------------------------------------------------------
# Dynamic library search path. Optional.
# It allows the libraries to be found quickly.
# By default it depends on AAFBASE value. But user can 
# set this variable to point to the directory where AAF 
# libraries are installed. For example:
#
#	make RPATH=/usr/local/lib/aaf
#
#----------------------------------------------------------
#RPATH ?= $(LIBDIR)  <-- this doesnt work
ifeq ($(origin RPATH), undefined)
    RPATH = $(LIBDIR)
endif


#----------------------------------------------------------
# Dependencies generation flag.
# If it's not 0 make will generate dependency files.
# By default dependencies generation is turned on. To
# change this behaviour use:
#
#       make GENDEPS=0
#
#----------------------------------------------------------
ifndef GENDEPS
    GENDEPS = 1
endif


PACKDIR := $(AAFBUILDDIR)/$(PACKAGE)
OBJDIR := $(PACKDIR)/$(AAFTARGETDIR)
LIBDIR := $(OBJDIR)

CPP_EXTENSION ?= cpp

HEADERS = $(wildcard, *.{hxx,h})
CXXFILES = $(wildcard *.$(CPP_EXTENSION))
CFILES = $(wildcard *.c)
CXXFILES2 = 


SOURCES = $(CXXFILES) $(CFILES)
CXXOBJS1 = $(SOURCES:%.$(CPP_EXTENSION)=$(OBJDIR)/%$(OBJ))
CXXOBJS = $(CXXOBJS1:%.c=$(OBJDIR)/%$(OBJ))
CXXOBJS2A = $(CXXFILES2:%.$(CPP_EXTENSION)=$(OBJDIR)/%$(OBJ))
CXXOBJS2 = $(CXXOBJS2A:%.c=$(OBJDIR)/%$(OBJ))

DEPS_TMP = $(SOURCES:%.$(CPP_EXTENSION)=$(OBJDIR)/%.d)
DEPS = $(DEPS_TMP:%.c=$(OBJDIR)/%.d)


#----------------------------------------------------------
# STORAGE_LIBS - Structured Storage Libraries.
# Using wildcards, find all available structured storage
# libraries and add them to STORAGE_LIBS.
#----------------------------------------------------------

STORAGE_LIBS=
LINK_STG=
# check for SchemaSoft implementation libSSRW2C.a
ifeq ($(wildcard $(AAFBUILDDIR)/sss-impl/libSSRW2C$(LIB)),$(AAFBUILDDIR)/sss-impl/libSSRW2C$(LIB))
STORAGE_LIBS += $(AAFBUILDDIR)/sss-impl/libSSRW2C$(LIB)
LINK_STG += -L$(AAFBUILDDIR)/sss-impl -lSSRW2C
else
endif

#----------------------------------------------------------
# STATIC_LINK_LINE - Link line used for static builds
# Pulls in all required static libraries to achieve a
# statically linked executable.
#----------------------------------------------------------
STATIC_LINK_LINE = -L$(AAFBUILDDIR)/ref-impl/$(AAFTARGETDIR) -L$(AAFBUILDDIR)/aaflib/$(AAFTARGETDIR) -L$(AAFBUILDDIR)/aafiid/$(AAFTARGETDIR) -L$(AAFBUILDDIR)/OM/$(AAFTARGETDIR) -lcom-api -limpl -laaflib -laafiid -lom $(PLATFORMLIBS) $(LIBCIO) $(LINK_STG) $(UUIDLIB)
