###############################################################################
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
# The Original Code of this file is Copyright 1998-2001, Licensor of the
# AAF Association.
# 
# The Initial Developer of the Original Code of this file and the
# Licensor of the AAF Association is Avid Technology.
# All rights reserved.
#
###############################################################################


AAFBASE ?= .

#
# Common definitions
#
include $(AAFBASE)/build/common.mk


#
#  Default target to build SDK. It assumes that dodo generated
#  files already exist. If they don't or dodo sources have
#  been changed use 'cd dodo && make'.
#  'make everything' must be used to build SDK and applications.
#
.PHONY : all
all : ref-impl


.PHONY : everything
everything : install examples devutils utilities test


.PHONY : ref-impl
ref-impl :
	cd ref-impl && $(MAKE)


.PHONY : install
install : ref-impl
	$(MAKE) -f unixaafsdk.mak CFG=$(AAFTARGET)

.PHONY : examples
examples : install
	cd examples && $(MAKE) 

.PHONY : examples2
examples2 : install
	cd examples2 && $(MAKE) 

.PHONY : devutils
devutils : install
	cd DevUtils && $(MAKE)

.PHONY : utilities
utilities : install examples2
	cd Utilities && $(MAKE)

.PHONY : test
test : install
	cd test && $(MAKE)

.PHONY : check
check : ref-impl
	cd test/com/ComModTestAAF && $(MAKE) check

#
# Binary distributions
#

.PHONY : dist
dist :  release-dist sdk-dist

.PHONY : release-dist
release-dist :
	$(MAKE) CFG=Release ref-impl
	cd dist && $(MAKE) release-dist

.PHONY : sdk-dist
sdk-dist :
	$(MAKE) CFG=Release everything
	$(MAKE) CFG=Debug everything
	cd dist && $(MAKE) sdk-dist

# This target simply prints the compiler version.
.PHONY : ccversion
ccversion :
	@$(CCVERSION)

# This target simply prints the build directory.
.PHONY : 
builddir :
	@echo $(AAFBUILDDIR)

#
# Clean up after 'make'
#
.PHONY : clean
clean :
	cd ref-impl && $(MAKE) $@

#
# Clean up after 'make install'
#
.PHONY : uninstall
uninstall :
	$(MAKE) -f unixaafsdk.mak CFG=$(AAFTARGET) clean

#
# Clean up after 'make everything' and 'make dist'
#
.PHONY : realclean
realclean : uninstall
	cd ref-impl && $(MAKE) $@
	cd DevUtils && $(MAKE) $@
	cd Utilities && $(MAKE) $@
	cd examples && $(MAKE) $@
	cd examples2 && $(MAKE) $@
	cd test && $(MAKE) $@
	cd dist && $(MAKE) $@

