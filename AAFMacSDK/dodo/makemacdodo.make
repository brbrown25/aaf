############################################
# File: makemacdodo.make                   #
#                                          #
# Copyright (c) 1998 Avid Technology, Inc. #
#                                          #
############################################
dod = {aaf}dodo:
AAFMacSDK = {aaf}AAFMacSDK:
DODO = {AAFMacSDK}dodo:tool:dodo
convertmk = {AAFMacSDK}dodo:tool:ConvertMake


all � macdodo.make


MAKEFILE     = makemacdodo.make


macaafobjects.mk � "{dod}aafobjects.mk"
	make -f macaafobjects.make > macaafobjects.make.out
	macaafobjects.make.out
	

makemacdodo.mk � macaafobjects.mk makemacdodo.mak1
	catenate macaafobjects.mk > makemacdodo.t01
	echo "" >> makemacdodo.t01
	echo "" >> makemacdodo.t01
	catenate makemacdodo.mak1 >> makemacdodo.t01
	copy_if_diff makemacdodo.t01 makemacdodo.mk
	rm -f makemacdodo.t01
	

macdodo.mak1  � makemacdodo.mk
	make -f makemacdodo.mk -d aaf="{aaf}" > makemacdodo.output
	makemacdodo.output


macdodo.make  � macdodo.mak1 makemacdodo.mak2
	echo 'making macdodo.make...'
	catenate macdodo.mak1 > macdodo.t02
	echo "" >> macdodo.t02
	echo "" >> macdodo.t02
	echo "" >> macdodo.t02
	catenate makemacdodo.mak2 >> macdodo.t02
	copy_if_diff -p macdodo.t02 macdodo.make
	rm -f macdodo.t02


clean_makemacdodo �
	if "" � "`exists -f makemacdodo.mk`"
		make clean -f makemacdodo.mk -d aaf="{aaf}" > makemacdodo.output
		makemacdodo.output
	end

realclean_makemacdodo �
	if "" � "`exists -f makemacdodo.mk`"
		make realclean -f makemacdodo.mk -d aaf="{aaf}" > makemacdodo.output
		makemacdodo.output
	end


cleantmp �
	rm -f makemacdodo.mk
	rm -f macaafobjects.mk
	rm -f macdodo.mak1


clean � clean_makemacdodo cleantmp

realclean � realclean_makemacdodo cleantmp
	rm -f macdodo.make
