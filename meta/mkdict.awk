#/***********************************************************************
#*
#*              Copyright (c) 1998-1999 Avid Technology, Inc.
#*
#* Permission to use, copy and modify this software and accompanying
#* documentation, and to distribute and sublicense application software
#* incorporating this software for any purpose is hereby granted,
#* provided that (i) the above copyright notice and this permission
#* notice appear in all copies of the software and related documentation,
#* and (ii) the name Avid Technology, Inc. may not be used in any
#* advertising or publicity relating to the software without the specific,
#* prior written permission of Avid Technology, Inc.
#*
#* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
#* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
#* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
#* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
#* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
#* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
#* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
#* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
#* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
#* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
#* LIABILITY.
#*
#************************************************************************/
#
# Generate an AAF meta dictionary from a .csv spreadsheet.
#
# Command line:
#
#   awk -f mkdict.awk ../smpte/DictP18-277-1847BMaster.csv | flip -u > AAFMetaDictionary.h
#
# Author
#
#   Tim Bingham tim_bingham@avid.com
#
# This program uses the following spreadsheet columns for the
# purposes indicated ...
#
# $1 - $9 = column(A - I) => AUID (with appropriate reordering).
# $10     = column(J)     => class/property name.
# $22     = column(V)     => if this field == "class" then the entity is a
#                            class, otherwise it is a property and this field
#                            denotes the type of the property. When this
#                            field == "class" this row is taken to be the
#                            start of a class definition. All the following
#                            rows (until the start of the next class) are
#                            taken to be properties of this class.
# $23     = column(W)     => For enumeration members the value of the member
#                            For record members the name of the member
# $24     = column(X)     => For enumerations the type of every member
#                            For arrays indicates whether the array is fixed
#                            or varying
#                            For references indicates whether the reference
#                            is strong or weak.
# $25     = column(Y)     => For arrays the element type.
#                            For references (singleton, array and set) the
#                            type of the target.
# $26     = column(Z)     => if this field == "M" then this is a required
#                            property. If this field is "O" then this is an
#                            optional property.
# $29     = column(AC)    => if this entity is a class then this field is
#                            the immediate ancestor (otherwise the field
#                            is checked to see that it is the same as the
#                            current class).
# $30     = column(AD)    => this field is not an input field to this program,
#                            however it is checked. If this entity is a class
#                            then this field should be the same as the class
#                            name (J), otherwise the field should be the same
#                            as the parent/owning class (AC).
# $33     = column(AG)    => property id. This field is ignored if
#                            field $29 == "class"
# $34     = column(AH)    => if this is a property and the property type (V)
#                            is a reference then this field is the type (class)
#                            of the referenced object, otherwise this field
#                            should be empty.
# $35     = column(AI)    => if this entity is a class and the class is
#                            abstract, this field contains "abstract" otherwise
#                            this field should be empty.
# $36     = column(AJ)    => if this entity is a property and the property is
#                            unique identifier, this field contains "uid"
#                            otherwise this field should be empty.
#
BEGIN {
  #
  # define symbolic names for columns
  #
  # SLO<n> SMPTE Label Octet n
  #
  SLO07C=1
  SLO08C=2
  SLO09C=3
  SLO10C=4
  SLO11C=5
  SLO12C=6
  SLO13C=7
  SLO14C=8
  SLO15C=9
  #
  elementNameC=10
  typeNameC=22
  kindC=23
  qualifC=24
  elementTypeC=25
  isMandatoryC=26
  parentC=29
  className1C=30
  pidC=33
  referenceTypeC=34
  isAbstractC=35
  isUidC=36
  #
  errors = 0;
  FS=","
  #
  # Write a header to the generated file.
  #
  printf("/***********************************************************************\n");
  printf("*\n");
  printf("*              Copyright (c) 1998-1999 Avid Technology, Inc.\n");
  printf("*\n");
  printf("* Permission to use, copy and modify this software and accompanying\n");
  printf("* documentation, and to distribute and sublicense application software\n");
  printf("* incorporating this software for any purpose is hereby granted,\n");
  printf("* provided that (i) the above copyright notice and this permission\n");
  printf("* notice appear in all copies of the software and related documentation,\n");
  printf("* and (ii) the name Avid Technology, Inc. may not be used in any\n");
  printf("* advertising or publicity relating to the software without the specific,\n");
  printf("* prior written permission of Avid Technology, Inc.\n");
  printf("*\n");
  printf("* THE SOFTWARE IS PROVIDED \"AS-IS\" AND WITHOUT WARRANTY OF ANY KIND,\n");
  printf("* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY\n");
  printf("* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.\n");
  printf("* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,\n");
  printf("* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR\n");
  printf("* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF\n");
  printf("* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND\n");
  printf("* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES\n");
  printf("* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT\n");
  printf("* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF\n");
  printf("* LIABILITY.\n");
  printf("*\n");
  printf("************************************************************************/\n");
  printf("//\n");
  printf("// Meta definition of the AAF object model.\n");
  printf("//\n");
  printf("// This file contains invocations of the macros described below.\n");
  printf("//\n");
  printf("// To use this file - \n");
  printf("//   1) #define those macros required to suit your usage\n");
  printf("//   2) #include this file\n");
  printf("//\n");
  printf("// This file will provide empty definitions for those macros you\n");
  printf("// choose not to define.\n");
  printf("//\n");
  printf("// After invoking the macros, this file will also undefine them.\n");
  printf("// All macros will be undefined - those you chose to define\n");
  printf("// and those defined by this file.\n");
  printf("//\n");
  printf("// This is an automatically generated file.\n");
  printf("//\n");
  printf("// If you edit this file your changes will be lost\n");
  printf("// the next time this file is generated.\n");
  printf("//\n");
  printf("// The following source files were used as input : \n");
  printf("//\n");
  printf("// ");
  for (i = 1; i < ARGC; i++) {
    printf("%s ", ARGV[i]);
  }
  printf("\n");
  printf("//\n");
  "date" | getline date
  "print $USERNAME" | getline user
  "print $COMPUTERNAME" | getline computer
  printf("// This file was generated on %s\n", date);
  printf("// by user %s on system %s.\n", user, computer);
  printf("//\n");
  printf("// Key to macros.\n");
  printf("//\n");
  printf("//   For formal arguments marked with [*] the actual arguments\n");
  printf("//   supplied by the macro invocations in this file are\n");
  printf("//   themselves macro invocations.\n");
  printf("//\n");
  printf("// AAF_TABLE_BEGIN()\n");
  printf("//\n");
  printf("//   Begin a table of AAF class and property definitions.\n");
  printf("//\n");
  printf("// AAF_TABLE_END()\n");
  printf("//\n");
  printf("//   End a table of AAF class and property definitions.\n");
  printf("//\n");
  printf("// AAF_CLASS(name, id, parent, concrete)\n");
  printf("//\n");
  printf("//   Define an AAF class.\n");
  printf("//\n");
  printf("//     name      = the name of the class\n");
  printf("//     id        = the auid used to identify the class [*]\n");
  printf("//     parent    = the immediate ancestor class\n");
  printf("//     concrete  = true if the class is concrete\n");
  printf("//                 false if the class is abstract\n");
  printf("//\n");
  printf("// AAF_CLASS_END(name)\n");
  printf("//\n");
  printf("//   End an AAF class definition.\n");
  printf("//\n");
  printf("//     name      = the name of the class\n");
  printf("//\n");
  printf("// AAF_CLASS_SEPARATOR()\n");
  printf("//\n");
  printf("//   Separate one AAF class definition from another.\n");
  printf("//\n");
  printf("// AAF_PROPERTY(name, id, tag, type, mandatory, uid, container)\n");
  printf("//\n");
  printf("//   Define an AAF property.\n");
  printf("//\n");
  printf("//     name      = the name of the property\n");
  printf("//     id        = the auid used to identify the property [*]\n");
  printf("//     tag       = the short form of the id\n");
  printf("//     type      = the type of the property [*]\n");
  printf("//     mandatory = true if the property is mandatory\n");
  printf("//                 false if the property is optional\n");
  printf("//     uid       = true if the property is the unique identifier\n");
  printf("//                 for this class, false if the property is not\n");
  printf("//                 the unique identifier for this class\n");
  printf("//     container = the class that defines this property\n");
  printf("//\n");
  printf("// AAF_TYPE(type)\n");
  printf("//\n");
  printf("//   Define an AAF type.\n");
  printf("//\n");
  printf("//     type      = the type\n");
  printf("//\n");
  printf("// AAF_REFERENCE_TYPE(type, target)\n");
  printf("//\n");
  printf("//   Define an AAF reference type.\n");
  printf("//\n");
  printf("//     type      = the reference type\n");
  printf("//     target    = the class of the target of the reference\n");
  printf("//\n");
  printf("// AAF_REFERENCE_TYPE_NAME(type, target)\n");
  printf("//\n");
  printf("//   Define the name of an AAF reference type.\n");
  printf("//\n");
  printf("//     type      = the reference type\n");
  printf("//     target    = the class of the target of the reference\n");
  printf("//\n");
  printf("// AAF_TYPE_TABLE_BEGIN()\n");
  printf("//\n");
  printf("//   Begin a table of AAF type definitions.\n");
  printf("//\n");
  printf("// AAF_TYPE_TABLE_END()\n");
  printf("//\n");
  printf("//   End a table of AAF type definitions.\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_INTEGER(name, id, size, signed)\n");
  printf("//\n");
  printf("//   Define an AAF integral type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     size      = the size (in bytes) of the type\n");
  printf("//     signed    = true if the type is signed, false otherwise\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_ENUMERATION(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF enumerated type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the type of each enumeration element [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(name, value, container)\n");
  printf("//\n");
  printf("//   Define a member of an AAF enumerated type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     value     = the value of this enumeration member\n");
  printf("//     container = the name of the containing enumerated type\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_ENUMERATION_END(name)\n");
  printf("//\n");
  printf("//   End an AAF enumerated type definition.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_RECORD(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF record type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_RECORD_FIELD(name, type, parent)\n");
  printf("//\n");
  printf("//   Define a field of an AAF record type.\n");
  printf("//\n");
  printf("//     name      = the name of the field\n");
  printf("//     type      = the type of the field [*]\n");
  printf("//     container = the name of the containing record type\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_RECORD_END(name)\n");
  printf("//\n");
  printf("//   End an AAF record type definition.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_VARYING_ARRAY(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF varying array type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the element type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_FIXED_ARRAY(name, id, type, count)\n");
  printf("//\n");
  printf("//   Define an AAF fixed array type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the element type [*]\n");
  printf("//     count     = the number of elements\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_RENAME(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF renamed type.\n");
  printf("//   Define \"name\" as a new name for \"type\".\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_STRING(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF string type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the element type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF extendible enumerated type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(name, auid, container)\n");
  printf("//\n");
  printf("//   Define a member of an AAF extendible enumerated type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     auid      = the auid of this enumeration member [*]\n");
  printf("//     container = the name of the containing extendible enumerated type\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(name)\n");
  printf("//\n");
  printf("//   End an AAF extendible enumerated type definition.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_CHARACTER(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF character type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_INDIRECT(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF indirect type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_OPAQUE(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF opque type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_SET(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF set type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the element type [*]\n");
  printf("//\n");
  printf("//AAF_TYPE_DEFINITION_STRONG_REFERENCE(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF strong reference type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF strong reference set type.\n");
  printf("//\n");
  printf("//     name      = the name of the type [*]\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF strong reference vector type.\n");
  printf("//\n");
  printf("//     name      = the name of the type [*]\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("//AAF_TYPE_DEFINITION_WEAK_REFERENCE(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF weak reference type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF weak reference set type.\n");
  printf("//\n");
  printf("//     name      = the name of the type [*]\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(name, id, type)\n");
  printf("//\n");
  printf("//   Define an AAF weak reference vector type.\n");
  printf("//\n");
  printf("//     name      = the name of the type [*]\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//     type      = the target type [*]\n");
  printf("//\n");
  printf("//AAF_TYPE_DEFINITION_STREAM(name, id)\n");
  printf("//\n");
  printf("//   Define an AAF stream type.\n");
  printf("//\n");
  printf("//     name      = the name of the type\n");
  printf("//     id        = the auid used to identify the type [*]\n");
  printf("//\n");
  printf("// AAF_TYPE_SEPARATOR()\n");
  printf("//\n");
  printf("//   Separate one AAF type definition from another.\n");
  printf("//\n");
  printf("//\n");
  printf("\n");
  printf("// Default empty definitions so that you only have to define\n");
  printf("// those macros you actually want to use.\n");
  printf("//\n");
  printf("#ifndef AAF_TABLE_BEGIN\n");
  printf("#define AAF_TABLE_BEGIN()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TABLE_END\n");
  printf("#define AAF_TABLE_END()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_CLASS\n");
  printf("#define AAF_CLASS(name, id, parent, concrete)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_CLASS_END\n");
  printf("#define AAF_CLASS_END(name)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_CLASS_SEPARATOR\n");
  printf("#define AAF_CLASS_SEPARATOR()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_PROPERTY\n");
  printf("#define AAF_PROPERTY(name, id, tag, type, mandatory, uid, container)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE\n");
  printf("#define AAF_TYPE(type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_REFERENCE_TYPE\n");
  printf("#define AAF_REFERENCE_TYPE(type, target)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_REFERENCE_TYPE_NAME\n");
  printf("#define AAF_REFERENCE_TYPE_NAME(type, target)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_TABLE_BEGIN\n");
  printf("#define AAF_TYPE_TABLE_BEGIN()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_TABLE_END\n");
  printf("#define AAF_TYPE_TABLE_END()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_INTEGER\n");
  printf("#define AAF_TYPE_DEFINITION_INTEGER(name, id, size, signed)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_ENUMERATION\n");
  printf("#define AAF_TYPE_DEFINITION_ENUMERATION(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_ENUMERATION_MEMBER\n");
  printf("#define AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(name, value, container)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_ENUMERATION_END\n");
  printf("#define AAF_TYPE_DEFINITION_ENUMERATION_END(name)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_RECORD\n");
  printf("#define AAF_TYPE_DEFINITION_RECORD(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_RECORD_FIELD\n");
  printf("#define AAF_TYPE_DEFINITION_RECORD_FIELD(name, type, parent)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_RECORD_END\n");
  printf("#define AAF_TYPE_DEFINITION_RECORD_END(name)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_VARYING_ARRAY\n");
  printf("#define AAF_TYPE_DEFINITION_VARYING_ARRAY(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_FIXED_ARRAY\n");
  printf("#define AAF_TYPE_DEFINITION_FIXED_ARRAY(name, id, type, count)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_RENAME\n");
  printf("#define AAF_TYPE_DEFINITION_RENAME(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_STRING\n");
  printf("#define AAF_TYPE_DEFINITION_STRING(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION\n");
  printf("#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER\n");
  printf("#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(name, guid, container)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END\n");
  printf("#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(name)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_CHARACTER\n");
  printf("#define AAF_TYPE_DEFINITION_CHARACTER(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_INDIRECT\n");
  printf("#define AAF_TYPE_DEFINITION_INDIRECT(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_OPAQUE\n");
  printf("#define AAF_TYPE_DEFINITION_OPAQUE(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_SET\n");
  printf("#define AAF_TYPE_DEFINITION_SET(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE\n");
  printf("#define AAF_TYPE_DEFINITION_STRONG_REFERENCE(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET\n");
  printf("#define AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR\n");
  printf("#define AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE\n");
  printf("#define AAF_TYPE_DEFINITION_WEAK_REFERENCE(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET\n");
  printf("#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR\n");
  printf("#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(name, id, type)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_DEFINITION_STREAM\n");
  printf("#define AAF_TYPE_DEFINITION_STREAM(name, id)\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_TYPE_SEPARATOR\n");
  printf("#define AAF_TYPE_SEPARATOR()\n");
  printf("#endif\n");
  printf("\n");
  printf("#ifndef AAF_LITERAL_AUID\n");
  printf("#define AAF_LITERAL_AUID(l, w1, w2,  b1, b2, b3, b4, b5, b6, b7, b8) \\\n");
  printf("                        {l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}\n");
  printf("#endif\n");
  printf("\n");
  printf("// AAF Object model\n");
  printf("//\n");
  printf("\n");
  printf("AAF_TABLE_BEGIN()\n");
  #
  # Initialize global variables.
  #
  firstType = 1;
}

/SMPTE Label Key/ {
  next # Discard the key line
}

{
  if ($elementNameC != "") { # This item has a name
    # printf("// <%s> \n", $parentC);
    if ($typeNameC == "Class") { # This item is a class
      if ($elementNameC != class) { # This is a new class
        if (class != "" ) {
          # end the old one
          printf("AAF_CLASS_END(%s)\n", class);
          printf("AAF_CLASS_SEPARATOR()\n");
          parent = $parentC;
        } else {
          parent = "Root"
        }
        class = $elementNameC;
        printf("\n");
        printf("// %s\n", class);
        printf("//\n");
      }
      if ($isMandatoryC != "") {
        classError(class, isMandatoryC);
        errors++;
      }
      if ($className1C != $elementNameC) {
        classError(class, className1C);
        errors++;
      }
      if ($referenceTypeC != "") {
        classError(class, referenceTypeC);
        errors++;
      }
      concrete = "true";
      if ($isAbstractC == "abstract") {
        concrete = "false";
      } else if ($isAbstractC != "") {
        classError(class, isAbstractC);
        errors++;
      }
      # AAF_CLASS(name, id, parent)
      printf("AAF_CLASS(%s,\n  AAF_LITERAL_AUID(0x%s%s%s%s,\n    0x%s%s, 0x%s%s,\n    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x%s),\n  %s,\n  %s)\n",
             $elementNameC, $SLO08C, $SLO09C, $SLO10C, $SLO11C, $SLO12C, $SLO13C, $SLO14C, $SLO15C, $SLO07C, parent, concrete);
    } else if ($typeNameC == "type" ) {
      # a type
      if (firstType) {
        printf("AAF_CLASS_END(%s)\n", class);
        printf("\n");
        printf("AAF_TABLE_END()\n");
        printf("\n");
        printf("// Types\n");
        printf("//\n");
        printf("\n");
        printf("AAF_TYPE_TABLE_BEGIN()\n");
        firstType = 0;
      } else {
        # end the previous type
        if (kind == "enumeration" ) {
          printf("AAF_TYPE_DEFINITION_ENUMERATION_END(%s)\n", typeName);
        } else if (kind == "record") {
          printf("AAF_TYPE_DEFINITION_RECORD_END(%s)\n", typeName);
        } else if (kind == "extendible") {
          printf("AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(%s)\n", typeName);
        }
        printf("AAF_TYPE_SEPARATOR()\n");
      }
#
      guid = sprintf("\n  AAF_LITERAL_AUID(0x%s%s%s%s,\n    0x%s%s, 0x%s%s,\n    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x%s)",
             $SLO08C, $SLO09C, $SLO10C, $SLO11C, $SLO12C, $SLO13C, $SLO14C, $SLO15C, $SLO07C);
#
      typeName = $elementNameC;
      parentTypeName = typeName;
      printf("\n");
      printf("// %s", typeName);
      if (($qualifC == "weak") || ($qualifC == "strong")) {
        printf("<%s>\n", $elementTypeC);
      } else {
        printf("\n");
      }
      printf("//\n");
      kind = $kindC;
      if        (kind == "integer") {
        printf("AAF_TYPE_DEFINITION_INTEGER(%s, %s, %s, %s)\n", typeName, guid, $qualifC, $elementTypeC);
      } else if (kind == "enumeration" ) {
        printf("AAF_TYPE_DEFINITION_ENUMERATION(%s, %s, AAF_TYPE(%s))\n", typeName, guid, $qualifC);
      } else if (kind == "array") {
        elementType = $elementTypeC;
        if ($qualifC == "varying") {
          printf("AAF_TYPE_DEFINITION_VARYING_ARRAY(%s, %s,\n  AAF_TYPE(%s))\n", typeName, guid, elementType);
        } else if ($qualifC == "fixed") {
          printf("AAF_TYPE_DEFINITION_FIXED_ARRAY(%s, %s,\n  AAF_TYPE(%s), %s)\n", typeName, guid, elementType, $isMandatoryC);
        } else if ($qualifC == "strong") {
          # Special cases for strong reference vectors.
            printf("AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, elementType, guid, elementType);
        } else if ($qualifC == "weak") {
          # Special cases for weak reference vectors.
            printf("AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, elementType, guid, elementType);
        } else {
          typeError(typeName, qualifC);
          errors++;
        }
      } else if (kind == "record") {
        printf("AAF_TYPE_DEFINITION_RECORD(%s, %s)\n", typeName, guid);
      } else if (kind == "rename") {
        printf("AAF_TYPE_DEFINITION_RENAME(%s, %s, %s)\n", typeName, guid, $elementTypeC);
      } else if (kind == "string") {
        printf("AAF_TYPE_DEFINITION_STRING(%s, %s, %s)\n", typeName, guid, $elementTypeC);
      } else if (kind == "extendible") {
        printf("AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(%s, %s)\n", typeName, guid);
      } else if (kind == "character") {
        printf("AAF_TYPE_DEFINITION_CHARACTER(%s, %s)\n", typeName, guid);
      } else if (kind == "indirect") {
        printf("AAF_TYPE_DEFINITION_INDIRECT(%s, %s)\n", typeName, guid);
      } else if (kind == "opaque") {
        printf("AAF_TYPE_DEFINITION_OPAQUE(%s, %s)\n", typeName, guid);
      } else if (kind == "set") {
        elementType = $elementTypeC;
        # Special cases for strong/weak reference sets.
        if ($qualifC == "strong") {
          printf("AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, elementType, guid, elementType);
        } else if ($qualifC == "weak") {
          printf("AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, elementType, guid, elementType);
        } else { 
          printf("AAF_TYPE_DEFINITION_SET(%s, %s,\n  AAF_TYPE(%s))\n", typeName, guid, elementType);
        }
      } else if (kind == "reference") {
        targetType = $elementTypeC;
        if ($qualifC == "strong") {
          printf("AAF_TYPE_DEFINITION_STRONG_REFERENCE(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, targetType, guid, targetType);
        } else if ($qualifC == "weak" ) {
          printf("AAF_TYPE_DEFINITION_WEAK_REFERENCE(\n  AAF_REFERENCE_TYPE_NAME(%s, %s), %s,\n  AAF_TYPE(%s))\n", typeName, targetType, guid, targetType);
        } else {
          typeError(typeName, qualifC);
          errors++;
        }
      } else if (kind == "stream") {
          printf("AAF_TYPE_DEFINITION_STREAM(%s, %s)\n", typeName, guid);
      } else {
        # better be another type
      }
    } else if ($typeNameC == "member") {
      # a "member" of a type
      memberName = $elementNameC;
      if (kind == "enumeration" ) {
        printf("  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(%s,\n    %s, %s)\n", memberName, $kindC, parentTypeName);
      } else if (kind == "record") {
        printf("  AAF_TYPE_DEFINITION_RECORD_FIELD(%s, AAF_TYPE(%s),\n    %s)\n", memberName, $kindC, parentTypeName);
      } else if (kind == "extendible") {
#
      eguid = sprintf("AAF_LITERAL_AUID(0x%s%s%s%s,\n      0x%s%s, 0x%s%s,\n      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x%s)",
             $SLO08C, $SLO09C, $SLO10C, $SLO11C, $SLO12C, $SLO13C, $SLO14C, $SLO15C, $SLO07C);
#
        printf("  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(%s,\n    %s,\n    %s)\n", memberName, eguid, parentTypeName);
      } else {
        # error, what is this a member of ?
      }     
    } else { # this item is a property
      type = $typeNameC;
      if (type == "Array of Int32") {
        type = "Int32Array"
      } else if (type == "Array of Int64") {
        type = "Int64Array"
      }
      #
      if        (type == "WeakReference") {
        reftype = "WEAK_REFERENCE";
      } else if (type == "WeakReferenceVector") {
        reftype = "WEAK_REFERENCE_VECTOR";
      } else if (type == "WeakReferenceSet") {
        reftype = "WEAK_REFERENCE_SET";
      } else if (type == "StrongReference") {
        reftype = "STRONG_REFERENCE";
      } else if (type == "StrongReferenceVector") {
        reftype = "STRONG_REFERENCE_VECTOR";
      } else if (type == "StrongReferenceSet") {
        reftype = "STRONG_REFERENCE_SET";
      } else {
        reftype="";
      }
      if (reftype != "") {
        if ($referenceTypeC != "") {
          # type = sprintf("AAF_%s(%s, %s)", reftype, type, $referenceTypeC);
          type = sprintf("AAF_REFERENCE_TYPE(%s, %s)", type, $referenceTypeC);
        } else {
          propertyError($elementNameC, class, referenceTypeC)
          errors++;
        }
      } else {
        if ($referenceTypeC == "") {
          type = sprintf("AAF_TYPE(%s)", type);
        } else {
          propertyError($elementNameC, class, referenceTypeC);
          errors++;
        }
      }
      #
      if ($isMandatoryC == "M") {
        mandatory = "true";
      } else if ($isMandatoryC == "O") {
        mandatory = "false";
      } else {
        propertyError($elementNameC, class, isMandatoryC);
        errors++;
      }
      if ($parentC != class) {
        propertyError($elementNameC, class, parentC);
        errors++;
      }
      if ($className1C != $parentC) {
        propertyError($elementNameC, class, className1C);
        errors++;
      }
      if ($isAbstractC != "") {
        propertyError($elementNameC, class, isAbstractC);
        errors++;
      }
      if ($isUidC == "uid") {
        uid = "true";
        if ($isMandatoryC == "O") {
          propertyError($elementNameC, class, isUidC);
          printError("A unique identifier must be mandatory.\n");
          errors++;
        }
      } else {
        uid = "false";
      }
      # AAF_PROPERTY(name, id, tag, type, mandatory, container)
      printf("  AAF_PROPERTY(%s,\n    AAF_LITERAL_AUID(0x%s%s%s%s,\n      0x%s%s, 0x%s%s,\n      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x%s),\n    0x%s,\n    %s,\n    %s,\n    %s,\n    %s)\n", $elementNameC, $SLO08C, $SLO09C, $SLO10C, $SLO11C, $SLO12C, $SLO13C, $SLO14C, $SLO15C, $SLO07C, $pidC, type, mandatory, uid, class);
    }
  }
}

END {
  if (errors == 0 ){
    if (kind == "enumeration" ) {
      printf("AAF_TYPE_DEFINITION_ENUMERATION_END(%s)\n", typeName);
    } else if (kind == "record") {
      printf("AAF_TYPE_DEFINITION_RECORD_END(%s)\n", typeName);
    } else if (kind == "extendible") {
      printf("AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(%s)\n", typeName);
    }
    printf("\n");
    printf("AAF_TYPE_TABLE_END()\n");
    printf("\n");
    printf("// Undefine all macros\n");
    printf("//\n");
    printf("#undef AAF_TABLE_BEGIN\n");
    printf("\n");
    printf("#undef AAF_TABLE_END\n");
    printf("\n");
    printf("#undef AAF_CLASS\n");
    printf("\n");
    printf("#undef AAF_CLASS_END\n");
    printf("\n");
    printf("#undef AAF_CLASS_SEPARATOR\n");
    printf("\n");
    printf("#undef AAF_PROPERTY\n");
    printf("\n");
    printf("#undef AAF_TYPE\n");
    printf("\n");
    printf("#undef AAF_REFERENCE_TYPE\n");
    printf("\n");
    printf("#undef AAF_REFERENCE_TYPE_NAME\n");
    printf("\n");
    printf("#undef AAF_LITERAL_AUID\n");
    printf("\n");
    printf("#undef AAF_TYPE_TABLE_BEGIN\n");
    printf("\n");
    printf("#undef AAF_TYPE_TABLE_END\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_INTEGER\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_ENUMERATION\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_ENUMERATION_MEMBER\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_ENUMERATION_END\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_RECORD\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_RECORD_FIELD\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_RECORD_END\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_VARYING_ARRAY\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_FIXED_ARRAY\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_RENAME\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_STRING\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_CHARACTER\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_INDIRECT\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_OPAQUE\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_SET\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR\n");
    printf("\n");
    printf("#undef AAF_TYPE_DEFINITION_STREAM\n");
    printf("\n");
    printf("#undef AAF_TYPE_SEPARATOR\n");
    printf("\n");
    printf("//\n");
    printf("// End of automatically generated file.\n");
  } else {
    printError(sprintf("File generation failed with %d errors.\n", errors));
    exit 1
  }
}

function printError(message)
{
  printf("#error %s", message);
  printf("Error : %s", message) | "cat 1>&2";
}

function elementError(column, elementName)
{
  printError(sprintf("Illegal entry \"%s\" in column \"%s\", for %s.\n", $column, column, elementName));
}

function classError(class, column)
{
  elementError(column , sprintf("class \"%s\"", class));
}

function typeError(type, column)
{
  elementError(column , sprintf("type \"%s\"", type));
}

function propertyError(property, class, column)
{
  elementError(column, sprintf("property \"%s\" of class \"%s\"", property, class));
}
