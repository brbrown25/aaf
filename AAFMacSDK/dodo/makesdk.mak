########################################################################
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
########################################################################

dod = {aaf}dodo:
AAFMacSDK = "{aaf}AAFMacSDK:"
incl = "{AAFMacSDK}include:"
refi = "{aaf}ref-impl:include:"
refh = "{refi}ref-api:"
comh = "{refi}com-api:"
bin  = "{AAFMacSDK}bin:"
bind = "{AAFMacSDK}bin:debug:"
lib  = "{AAFMacSDK}lib:"
libd = "{AAFMacSDK}lib:debug:"


all �  makesdk




make_makesdk � $OutOfDate makesdk.mak
	(
		perl "{dod}sync_copyright.pl" --copyright "{dod}CopyrightMessage.txt" --shell_style
		echo ""
		echo 'AAFMacSDK = {aaf}AAFMacSDK:'
		echo 'incl = {AAFMacSDK}include:'
		echo 'refi = {aaf}ref-impl:include:'
		echo 'refh = {refi}ref-api:'
		echo 'comh = {refi}com-api:'
		echo 'bin  = {AAFMacSDK}bin:'
		echo 'bind = {AAFMacSDK}bin:debug:'
		echo 'lib  = {AAFMacSDK}lib:'
		echo 'libd = {AAFMacSDK}lib:debug:'
		echo ""
		echo ""
		echo 'targetIncludes = �'
		set refimpl "`files -s "{refi}" | StreamEdit -e '/Private/ Delete'`"
		for item in {refimpl}
			echo '	"{incl}'{item}'" �'
		end
		set refapi "`files -s "{refh}" | StreamEdit -e '/Private/ Delete'`"
		for item in {refapi}
			echo '	"{incl}'{item}'" �'
		end
		echo ""
		echo ""
		echo 'all � checkDirectories {targetIncludes}'
		echo ""
		echo ""
		echo "# Directory dependencies"
		echo '"{incl}" � "{refi}"'
		echo '"{incl}" � "{refh}"'
		echo '"{incl}" � "{comh}"'
		echo ""
		echo ""
		echo 'checkDirectories �'
		echo '	if "" == "`exists -d "{bin}"`"'
		echo '		NewFolder "{bin}"'
		echo '	end'
		echo '	if "" == "`exists -d "{bind}"`"'
		echo '		NewFolder "{bind}"'
		echo '	end'
		echo '	if "" == "`exists -d "{incl}"`"'
		echo '		NewFolder "{incl}"'
		echo '	end'
		echo '	if "" == "`exists -d "{lib}"`"'
		echo '		NewFolder "{lib}"'
		echo '	end'
		echo '	if "" == "`exists -d "{libd}"`"'
		echo '		NewFolder "{libd}"'
		echo '	end'
		echo ""
		echo ""
		echo ""
		echo ""
		for item in {refimpl}
			echo '"{incl}'{item}'" � "{refi}'{item}'"'
			echo '	copy_if_diff -p "{refi}'{item}'" ''"{incl}'{item}'"'
			echo ""
			echo ""
		end
		for item in {refapi}
			echo '"{incl}'{item}'" � "{refh}'{item}'"'
			echo '	copy_if_diff -p "{refh}'{item}'" ''"{incl}'{item}'"'
			echo ""
			echo ""
		end
		echo ""
		echo ""
		echo "clean �"
		echo '	echo "No files removed" > dev:null'
		echo ""
		echo "realclean �"
		echo '	for item in {targetIncludes}'
		echo '		rm -v -f "{item}"'
		echo '	end'
		echo ""
		echo ""
	) > makesdk.tmp
	copy_if_diff makesdk.tmp makesdk.make
	rm -f makesdk.tmp


makesdk.make � "{dod}CopyrightMessage.txt" "{dod}sync_copyright.pl" make_makesdk


makesdk � makesdk.make
	make -f makesdk.make -d aaf="{aaf}" > makesdk.make.all.out
	makesdk.make.all.out
	

cleantmp �	
	rm -f makesdk.tmp
	rm -f makesdk.make.all.out
	rm -f makesdk.make.clean.out
	rm -f makesdk.make.realclean.out


clean_makesdk �
	if "" � "`exists makesdk.make`"
		make clean -f makesdk.make > makesdk.make.clean.out
		makesdk.make.clean.out
	end


realclean_makesdk �
	if "" � "`exists makesdk.make`"
		make realclean -f makesdk.make > makesdk.make.realclean.out
		makesdk.make.realclean.out
		rm -f -v makesdk.make
	end
	
	
clean � clean_makesdk cleantmp

	
realclean � realclean_makesdk cleantmp
