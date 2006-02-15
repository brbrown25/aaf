//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id: AAFMetaDictionary.h,v 1.123 2006/02/15 23:01:34 jlow Exp $ $Name:  $
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
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=
//
// Meta definition of the AAF object model.
//
// This file contains invocations of the macros described below.
//
// To use this file - 
//   1) #define those macros required to suit your usage
//   2) #include this file
//
// This file will provide empty definitions for those macros you
// choose not to define.
//
// After invoking the macros, this file will also undefine them.
// All macros will be undefined - those you chose to define
// and those defined by this file.
//
// This is an automatically generated file.
//
// If you edit this file your changes will be lost
// the next time this file is generated.
//
// The following source files were used as input : 
//
// AAFMetaDict.csv 
//
// This file was generated on Wed Feb 15 17:12:55 EST 2006
// by user jlow on system hawk.
//
// Key to macros.
//
//   For formal arguments marked with [*] the actual arguments
//   supplied by the macro invocations in this file are
//   themselves macro invocations.
//
// AAF_TABLE_BEGIN()
//
//   Begin a table of AAF class and property definitions.
//
// AAF_TABLE_END()
//
//   End a table of AAF class and property definitions.
//
// AAF_SYMBOL( symbol, name, alias, description )
//
//   Define a container for the preferred symbol etc of AAF meta entry
//
//     symbol      = the syntactically correct symbol of the entry
//     name        = the name of the entry
//     alias       = the legacy alias name of the entry, if any
//     description = the text description of the entry, if any
//
//   Note: this uses the awkward 2 step approach described by Steve Summit
//
// AAF_CLASS(name, id, parent, concrete)
//
//   Define an AAF class.
//
//     name      = the name of the class
//     id        = the auid used to identify the class [*]
//     parent    = the immediate ancestor class
//     concrete  = true if the class is concrete
//                 false if the class is abstract
//
// AAF_CLASS_END(name, id, parent, concrete)
//
//   End an AAF class definition.
//
//     name      = the name of the class
//     id        = the auid used to identify the class [*]
//     parent    = the immediate ancestor class
//     concrete  = true if the class is concrete
//                 false if the class is abstract
//
// AAF_CLASS_SEPARATOR()
//
//   Separate one AAF class definition from another.
//
// AAF_PROPERTY(name, id, tag, type, mandatory, uid, container)
//
//   Define an AAF property.
//
//     name      = the name of the property
//     id        = the auid used to identify the property [*]
//     tag       = the short form of the id
//     type      = the type of the property [*]
//     mandatory = true if the property is mandatory
//                 false if the property is optional
//     uid       = true if the property is the unique identifier
//                 for this class, false if the property is not
//                 the unique identifier for this class
//     container = the class that defines this property
//
// AAF_TYPE(type)
//
//   Define an AAF type.
//
//     type      = the type
//
// AAF_REFERENCE_TYPE(type, target)
//
//   Define an AAF reference type.
//
//     type      = the reference type
//     target    = the class of the target of the reference
//
// AAF_REFERENCE_TYPE_NAME(type, target)
//
//   Define the name of an AAF reference type.
//
//     type      = the reference type
//     target    = the class of the target of the reference
//
// AAF_TYPE_TABLE_BEGIN()
//
//   Begin a table of AAF type definitions.
//
// AAF_TYPE_TABLE_END()
//
//   End a table of AAF type definitions.
//
// AAF_TYPE_DEFINITION_INTEGER(name, id, size, signed)
//
//   Define an AAF integral type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     size      = the size (in bytes) of the type
//     signed    = true if the type is signed, false otherwise
//
// AAF_TYPE_DEFINITION_ENUMERATION(name, id, type)
//
//   Define an AAF enumerated type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the type of each enumeration element [*]
//
// AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(name, value, container)
//
//   Define a member of an AAF enumerated type.
//
//     name      = the name of the type
//     value     = the value of this enumeration member
//     container = the name of the containing enumerated type
//
// AAF_TYPE_DEFINITION_ENUMERATION_END(name, id, type)
//
//   End an AAF enumerated type definition.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the type of each enumeration element [*]
//
// AAF_TYPE_DEFINITION_RECORD(name, id)
//
//   Define an AAF record type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_RECORD_FIELD(name, type, parent)
//
//   Define a field of an AAF record type.
//
//     name      = the name of the field
//     type      = the type of the field [*]
//     container = the name of the containing record type
//
// AAF_TYPE_DEFINITION_RECORD_END(name, id)
//
//   End an AAF record type definition.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_VARYING_ARRAY(name, id, type)
//
//   Define an AAF varying array type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the element type [*]
//
// AAF_TYPE_DEFINITION_FIXED_ARRAY(name, id, type, count)
//
//   Define an AAF fixed array type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the element type [*]
//     count     = the number of elements
//
// AAF_TYPE_DEFINITION_RENAME(name, id, type)
//
//   Define an AAF renamed type.
//   Define "name" as a new name for "type".
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the type [*]
//
// AAF_TYPE_DEFINITION_STRING(name, id, type)
//
//   Define an AAF string type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the element type [*]
//
// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(name, id)
//
//   Define an AAF extendible enumerated type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(name, auid, container)
//
//   Define a member of an AAF extendible enumerated type.
//
//     name      = the name of the type
//     auid      = the auid of this enumeration member [*]
//     container = the name of the containing extendible enumerated type
//
// AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(name, id)
//
//   End an AAF extendible enumerated type definition.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
//
// AAF_TYPE_DEFINITION_CHARACTER(name, id)
//
//   Define an AAF character type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_INDIRECT(name, id)
//
//   Define an AAF indirect type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_OPAQUE(name, id)
//
//   Define an AAF opque type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_DEFINITION_SET(name, id, type)
//
//   Define an AAF set type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the element type [*]
//
// AAF_TYPE_DEFINITION_STRONG_REFERENCE(name, id, type)
//
//   Define an AAF strong reference type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(name, id, type)
//
//   Define an AAF strong reference set type.
//
//     name      = the name of the type [*]
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(name, id, type)
//
//   Define an AAF strong reference vector type.
//
//     name      = the name of the type [*]
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_WEAK_REFERENCE(name, id, type)
//
//   Define an AAF weak reference type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(name, parent, container)
//
//   Define a member of an AAF extendible enumerated type.
//
//     name      = the name of the type
//     parent    = the parent property for member [*]
//     container = the name of the containing weak reference type
//
// AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(name, id, type)
//
//   End an AAF extendible enumerated type definition.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(name, id, type)
//
//   Define an AAF weak reference set type.
//
//     name      = the name of the type [*]
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(name, id, type)
//
//   Define an AAF weak reference vector type.
//
//     name      = the name of the type [*]
//     id        = the auid used to identify the type [*]
//     type      = the target type [*]
//
// AAF_TYPE_DEFINITION_STREAM(name, id)
//
//   Define an AAF stream type.
//
//     name      = the name of the type
//     id        = the auid used to identify the type [*]
//
// AAF_TYPE_SEPARATOR()
//
//   Separate one AAF type definition from another.
//
// AAF_ALIAS_TABLE_BEGIN()
//
//   Begin a table of AAF alias definitions.
//
// AAF_ALIAS_TABLE_END()
//
//   End a table of AAF alias definitions.
//
// AAF_ALIAS_SEPARATOR()
//
//   Separate one AAF alias from another.
//
// AAF_CLASS_ALIAS(name, alias)
//
//   Define a name used in the source code different from the name of the metadefinition.
//
//     name      = class name
//     alias     = another, usually shorter, name by which the
//                 class is also known
//
// AAF_INSTANCE_TABLE_BEGIN()
//
//   Begin a table of AAF definition instance definitions.
//
// AAF_INSTANCE_TABLE_END()
//
//   End a table of AAF definition instance definitions.
//
// AAF_INSTANCE_GROUP_SEPARATOR()
//
//   Separate one group of AAF definition instances from another.
//
// AAF_INSTANCE_GROUP(name, target)
//
//   Begin a group of AAF definition instances.
//
//     name      = name of container for these instances
//     target    = class name of each instance
//
// AAF_INSTANCE_GROUP_END(name, target)
//
//   End a group of AAF definition instances.
//
//     name      = name of container for these instances
//     target    = class name of each instance
//
// AAF_INSTANCE_SEPARATOR()
//
//   Separate one AAF definition instance from another.
//
// AAF_INSTANCE(class, name, id, desc)
//
//   Define an instance of an AAF definition.
//
//     class     = the class of the instance
//     name      = the name of the instance
//     id        = the auid used to identify the instance [*]
//     desc      = the text description (may be null)
//
// AAF_INSTANCE_END(class, name, id)
//
//   Complete an instance of an AAF definition.
//
//     class     = the class of the instance
//     name      = the name of the instance
//     id        = the auid used to identify the instance [*]
//
// AAF_INSTANCE_PROPERTY(name, type, value)
//
//   Define a property of an instance of an AAF definition.
//
//     name      = the name of the property
//     id        = the type name of the property [*]
//     value     = the value of the property [* - maybe]
//
// AAF_LITERAL_AUID(l, w1, w2,  b1, b2, b3, b4, b5, b6, b7, b8)
//
//   Define an AUID.
//
//     l         = Data1
//     w1        = Data2
//     w2        = Data3
//     b1-b8     = Data4
//

// Default empty definitions so that you only have to define
// those macros you actually want to use.
//
#ifndef AAF_TABLE_BEGIN
#define AAF_TABLE_BEGIN()
#endif

#ifndef AAF_TABLE_END
#define AAF_TABLE_END()
#endif

// default definition of AAF_SYM for backwards compatibility
#ifndef AAF_SYM
#define AAF_SYM( symbol, name, alias, description ) #symbol
#endif

// why 2 step? see Steve Summit (1996) "C Programming FAQs: Frequently Asked Questions" ISBN: 0-201-84519-9
#ifndef AAF_SYMBOL
#define AAF_SYMBOL( a,b,c,d ) AAF_SYM( a,b,c,d )
#endif

#ifndef AAF_CLASS
#define AAF_CLASS(name, id, parent, concrete)
#endif

#ifndef AAF_CLASS_END
#define AAF_CLASS_END(name, id, parent, concrete)
#endif

#ifndef AAF_CLASS_SEPARATOR
#define AAF_CLASS_SEPARATOR()
#endif

#ifndef AAF_PROPERTY
#define AAF_PROPERTY(name, id, tag, type, mandatory, uid, container)
#endif

#ifndef AAF_TYPE
#define AAF_TYPE(type)
#endif

#ifndef AAF_REFERENCE_TYPE
#define AAF_REFERENCE_TYPE(type, target)
#endif

#ifndef AAF_REFERENCE_TYPE_NAME
#define AAF_REFERENCE_TYPE_NAME(type, target)
#endif

#ifndef AAF_TYPE_TABLE_BEGIN
#define AAF_TYPE_TABLE_BEGIN()
#endif

#ifndef AAF_TYPE_TABLE_END
#define AAF_TYPE_TABLE_END()
#endif

#ifndef AAF_TYPE_DEFINITION_INTEGER
#define AAF_TYPE_DEFINITION_INTEGER(name, id, size, signed)
#endif

#ifndef AAF_TYPE_DEFINITION_ENUMERATION
#define AAF_TYPE_DEFINITION_ENUMERATION(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_ENUMERATION_MEMBER
#define AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(name, value, container)
#endif

#ifndef AAF_TYPE_DEFINITION_ENUMERATION_END
#define AAF_TYPE_DEFINITION_ENUMERATION_END(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_RECORD
#define AAF_TYPE_DEFINITION_RECORD(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_RECORD_FIELD
#define AAF_TYPE_DEFINITION_RECORD_FIELD(name, type, parent)
#endif

#ifndef AAF_TYPE_DEFINITION_RECORD_END
#define AAF_TYPE_DEFINITION_RECORD_END(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_VARYING_ARRAY
#define AAF_TYPE_DEFINITION_VARYING_ARRAY(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_FIXED_ARRAY
#define AAF_TYPE_DEFINITION_FIXED_ARRAY(name, id, type, count)
#endif

#ifndef AAF_TYPE_DEFINITION_RENAME
#define AAF_TYPE_DEFINITION_RENAME(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_STRING
#define AAF_TYPE_DEFINITION_STRING(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION
#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER
#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(name, guid, container)
#endif

#ifndef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END
#define AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_CHARACTER
#define AAF_TYPE_DEFINITION_CHARACTER(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_INDIRECT
#define AAF_TYPE_DEFINITION_INDIRECT(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_OPAQUE
#define AAF_TYPE_DEFINITION_OPAQUE(name, id)
#endif

#ifndef AAF_TYPE_DEFINITION_SET
#define AAF_TYPE_DEFINITION_SET(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE
#define AAF_TYPE_DEFINITION_STRONG_REFERENCE(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET
#define AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR
#define AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE
#define AAF_TYPE_DEFINITION_WEAK_REFERENCE(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER
#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(name, parent, container)
#endif

#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_END
#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET
#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR
#define AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(name, id, type)
#endif

#ifndef AAF_TYPE_DEFINITION_STREAM
#define AAF_TYPE_DEFINITION_STREAM(name, id)
#endif

#ifndef AAF_TYPE_SEPARATOR
#define AAF_TYPE_SEPARATOR()
#endif

#ifndef AAF_ALIAS_TABLE_BEGIN
#define AAF_ALIAS_TABLE_BEGIN()
#endif

#ifndef AAF_ALIAS_TABLE_END
#define AAF_ALIAS_TABLE_END()
#endif

#ifndef AAF_ALIAS_SEPARATOR
#define AAF_ALIAS_SEPARATOR()
#endif

#ifndef AAF_CLASS_ALIAS
#define AAF_CLASS_ALIAS(name, alias)
#endif

#ifndef AAF_INSTANCE_TABLE_BEGIN
#define AAF_INSTANCE_TABLE_BEGIN()
#endif

#ifndef AAF_INSTANCE_TABLE_END
#define AAF_INSTANCE_TABLE_END()
#endif

#ifndef AAF_INSTANCE_GROUP_SEPARATOR
#define AAF_INSTANCE_GROUP_SEPARATOR()
#endif

#ifndef AAF_INSTANCE_GROUP
#define AAF_INSTANCE_GROUP(name, target)
#endif

#ifndef AAF_INSTANCE_GROUP_END
#define AAF_INSTANCE_GROUP_END(name, target)
#endif

#ifndef AAF_INSTANCE_SEPARATOR
#define AAF_INSTANCE_SEPARATOR()
#endif

#ifndef AAF_INSTANCE
#define AAF_INSTANCE(class, name, id, desc)
#endif

#ifndef AAF_INSTANCE_END
#define AAF_INSTANCE_END(class, name, id)
#endif

#ifndef AAF_INSTANCE_PROPERTY
#define AAF_INSTANCE_PROPERTY(name, type, value)
#endif

#ifndef AAF_LITERAL_AUID
#define AAF_LITERAL_AUID(l, w1, w2,  b1, b2, b3, b4, b5, b6, b7, b8) \
                        {l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}
#endif

// AAF Object model
//

AAF_TABLE_BEGIN()

// InterchangeObject
//
AAF_CLASS(InterchangeObject,
  // {0D010101-0101-0100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.01.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  false)
  AAF_PROPERTY(ObjClass,
    // {06010104-0101-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0101, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0101,
    AAF_REFERENCE_TYPE(WeakReference, ClassDefinition),
    true,
    false,
    InterchangeObject)
  AAF_PROPERTY(Generation,
    // {05200701-0800-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.08.00.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0102,
    AAF_TYPE(AUID),
    false,
    false,
    InterchangeObject)
AAF_CLASS_END(InterchangeObject,
  // {0D010101-0101-0100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.01.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  false)
AAF_CLASS_SEPARATOR()

// Component
//
AAF_CLASS(Component,
  // {0D010101-0101-0200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.02.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(DataDefinition,
    // {04070100-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.07.01.00.00.00.00.00
    AAF_LITERAL_AUID(0x04070100,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0201,
    AAF_REFERENCE_TYPE(WeakReference, DataDefinition),
    true,
    false,
    Component)
  AAF_PROPERTY(Length,
    // {07020201-0103-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.02.01.01.03.00.00
    AAF_LITERAL_AUID(0x07020201,
      0x0103, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0202,
    AAF_TYPE(LengthType),
    false,
    false,
    Component)
  AAF_PROPERTY(KLVData,
    // {03010210-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.10.04.00.00.00
    AAF_LITERAL_AUID(0x03010210,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0203,
    AAF_REFERENCE_TYPE(StrongReferenceVector, KLVData),
    false,
    false,
    Component)
  AAF_PROPERTY(UserComments,
    // {03020102-1600-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.03.02.01.02.16.00.00.00
    AAF_LITERAL_AUID(0x03020102,
      0x1600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x0204,
    AAF_REFERENCE_TYPE(StrongReferenceVector, TaggedValue),
    false,
    false,
    Component)
  AAF_PROPERTY(Attributes,
    // {03010210-0800-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.03.01.02.10.08.00.00.00
    AAF_LITERAL_AUID(0x03010210,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x0205,
    AAF_REFERENCE_TYPE(StrongReferenceVector, TaggedValue),
    false,
    false,
    Component)
AAF_CLASS_END(Component,
  // {0D010101-0101-0200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.02.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// Segment
//
AAF_CLASS(Segment,
  // {0D010101-0101-0300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.03.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Component,
  false)
AAF_CLASS_END(Segment,
  // {0D010101-0101-0300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.03.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Component,
  false)
AAF_CLASS_SEPARATOR()

// EdgeCode
//
AAF_CLASS(EdgeCode,
  // {0D010101-0101-0400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.04.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Start,
    // {01040901-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.04.09.01.00.00.00.00
    AAF_LITERAL_AUID(0x01040901,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0401,
    AAF_TYPE(PositionType),
    true,
    false,
    EdgeCode)
  AAF_PROPERTY(FilmKind,
    // {04100103-0109-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.09.00.00
    AAF_LITERAL_AUID(0x04100103,
      0x0109, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0402,
    AAF_TYPE(FilmType),
    true,
    false,
    EdgeCode)
  AAF_PROPERTY(CodeFormat,
    // {04100103-0102-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.10.01.03.01.02.00.00
    AAF_LITERAL_AUID(0x04100103,
      0x0102, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x0403,
    AAF_TYPE(EdgeType),
    true,
    false,
    EdgeCode)
  AAF_PROPERTY(Header,
    // {01030201-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.03.02.01.02.00.00.00
    AAF_LITERAL_AUID(0x01030201,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0404,
    AAF_TYPE(DataValue),
    false,
    false,
    EdgeCode)
AAF_CLASS_END(EdgeCode,
  // {0D010101-0101-0400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.04.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// EssenceGroup
//
AAF_CLASS(EssenceGroup,
  // {0D010101-0101-0500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.05.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Choices,
    // {06010104-0601-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0601, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0501,
    AAF_REFERENCE_TYPE(StrongReferenceVector, SourceReference),
    true,
    false,
    EssenceGroup)
  AAF_PROPERTY(StillFrame,
    // {06010104-0208-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.08.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0208, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0502,
    AAF_REFERENCE_TYPE(StrongReference, SourceReference),
    false,
    false,
    EssenceGroup)
AAF_CLASS_END(EssenceGroup,
  // {0D010101-0101-0500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.05.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// Event
//
AAF_CLASS(Event,
  // {0D010101-0101-0600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.06.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
  AAF_PROPERTY(Position,
    // {07020103-0303-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.03.03.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x0303, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0601,
    AAF_TYPE(PositionType),
    true,
    false,
    Event)
  AAF_PROPERTY(Comment,
    // {05300404-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.04.04.01.00.00.00
    AAF_LITERAL_AUID(0x05300404,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0602,
    AAF_TYPE(String),
    false,
    false,
    Event)
AAF_CLASS_END(Event,
  // {0D010101-0101-0600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.06.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
AAF_CLASS_SEPARATOR()

// GPITrigger
//
AAF_CLASS(GPITrigger,
  // {0D010101-0101-0700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.07.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Event,
  true)
  AAF_PROPERTY(ActiveState,
    // {05300401-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.04.01.00.00.00.00
    AAF_LITERAL_AUID(0x05300401,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x0801,
    AAF_TYPE(Boolean),
    true,
    false,
    GPITrigger)
AAF_CLASS_END(GPITrigger,
  // {0D010101-0101-0700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.07.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Event,
  true)
AAF_CLASS_SEPARATOR()

// CommentMarker
//
AAF_CLASS(CommentMarker,
  // {0D010101-0101-0800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.08.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Event,
  true)
  AAF_PROPERTY(Annotation,
    // {06010104-020A-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.0A.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x020A, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0901,
    AAF_REFERENCE_TYPE(StrongReference, SourceReference),
    false,
    false,
    CommentMarker)
AAF_CLASS_END(CommentMarker,
  // {0D010101-0101-0800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.08.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Event,
  true)
AAF_CLASS_SEPARATOR()

// Filler
//
AAF_CLASS(Filler,
  // {0D010101-0101-0900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.09.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_END(Filler,
  // {0D010101-0101-0900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.09.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// OperationGroup
//
AAF_CLASS(OperationGroup,
  // {0D010101-0101-0A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Operation,
    // {05300506-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.06.00.00.00.00
    AAF_LITERAL_AUID(0x05300506,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0b01,
    AAF_REFERENCE_TYPE(WeakReference, OperationDefinition),
    true,
    false,
    OperationGroup)
  AAF_PROPERTY(InputSegments,
    // {06010104-0602-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.02.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0602, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0b02,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Segment),
    false,
    false,
    OperationGroup)
  AAF_PROPERTY(Parameters,
    // {06010104-060A-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.0A.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x060A, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0b03,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Parameter),
    false,
    false,
    OperationGroup)
  AAF_PROPERTY(BypassOverride,
    // {0530050C-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.0C.00.00.00.00
    AAF_LITERAL_AUID(0x0530050C,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0b04,
    AAF_TYPE(UInt32),
    false,
    false,
    OperationGroup)
  AAF_PROPERTY(Rendering,
    // {06010104-0206-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.06.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0206, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0b05,
    AAF_REFERENCE_TYPE(StrongReference, SourceReference),
    false,
    false,
    OperationGroup)
AAF_CLASS_END(OperationGroup,
  // {0D010101-0101-0A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// NestedScope
//
AAF_CLASS(NestedScope,
  // {0D010101-0101-0B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Slots,
    // {06010104-0607-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.07.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0607, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0c01,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Segment),
    true,
    false,
    NestedScope)
AAF_CLASS_END(NestedScope,
  // {0D010101-0101-0B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// Pulldown
//
AAF_CLASS(Pulldown,
  // {0D010101-0101-0C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(InputSegment,
    // {06010104-0207-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.07.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0207, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0d01,
    AAF_REFERENCE_TYPE(StrongReference, Segment),
    true,
    false,
    Pulldown)
  AAF_PROPERTY(PulldownKind,
    // {05401001-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.40.10.01.02.00.00.00
    AAF_LITERAL_AUID(0x05401001,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0d02,
    AAF_TYPE(PulldownKindType),
    true,
    false,
    Pulldown)
  AAF_PROPERTY(PulldownDirection,
    // {05401001-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.40.10.01.01.00.00.00
    AAF_LITERAL_AUID(0x05401001,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0d03,
    AAF_TYPE(PulldownDirectionType),
    true,
    false,
    Pulldown)
  AAF_PROPERTY(PhaseFrame,
    // {05401001-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.40.10.01.03.00.00.00
    AAF_LITERAL_AUID(0x05401001,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0d04,
    AAF_TYPE(PhaseFrameType),
    true,
    false,
    Pulldown)
AAF_CLASS_END(Pulldown,
  // {0D010101-0101-0C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// ScopeReference
//
AAF_CLASS(ScopeReference,
  // {0D010101-0101-0D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(RelativeScope,
    // {06010103-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.03.03.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0e01,
    AAF_TYPE(UInt32),
    true,
    false,
    ScopeReference)
  AAF_PROPERTY(RelativeSlot,
    // {06010103-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.03.04.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0e02,
    AAF_TYPE(UInt32),
    true,
    false,
    ScopeReference)
AAF_CLASS_END(ScopeReference,
  // {0D010101-0101-0D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// Selector
//
AAF_CLASS(Selector,
  // {0D010101-0101-0E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Selected,
    // {06010104-0209-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.09.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0209, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0f01,
    AAF_REFERENCE_TYPE(StrongReference, Segment),
    true,
    false,
    Selector)
  AAF_PROPERTY(Alternates,
    // {06010104-0608-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.08.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0608, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0f02,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Segment),
    false,
    false,
    Selector)
AAF_CLASS_END(Selector,
  // {0D010101-0101-0E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// Sequence
//
AAF_CLASS(Sequence,
  // {0D010101-0101-0F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Components,
    // {06010104-0609-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.09.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0609, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1001,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Component),
    true,
    false,
    Sequence)
AAF_CLASS_END(Sequence,
  // {0D010101-0101-0F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.0F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x0F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// SourceReference
//
AAF_CLASS(SourceReference,
  // {0D010101-0101-1000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.10.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
  AAF_PROPERTY(SourceID,
    // {06010103-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.03.01.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1101,
    AAF_TYPE(MobIDType),
    false,
    false,
    SourceReference)
  AAF_PROPERTY(SourceMobSlotID,
    // {06010103-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.03.02.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1102,
    AAF_TYPE(UInt32),
    true,
    false,
    SourceReference)
  AAF_PROPERTY(ChannelIDs,
    // {06010103-0700-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.06.01.01.03.07.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x1103,
    AAF_TYPE(UInt32Array),
    false,
    false,
    SourceReference)
  AAF_PROPERTY(MonoSourceSlotIDs,
    // {06010103-0800-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.06.01.01.03.08.00.00.00
    AAF_LITERAL_AUID(0x06010103,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x1104,
    AAF_TYPE(UInt32Array),
    false,
    false,
    SourceReference)
AAF_CLASS_END(SourceReference,
  // {0D010101-0101-1000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.10.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
AAF_CLASS_SEPARATOR()

// SourceClip
//
AAF_CLASS(SourceClip,
  // {0D010101-0101-1100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.11.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SourceReference,
  true)
  AAF_PROPERTY(StartTime,
    // {07020103-0104-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.01.04.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x0104, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1201,
    AAF_TYPE(PositionType),
    false,
    false,
    SourceClip)
  AAF_PROPERTY(FadeInLength,
    // {07020201-0105-0200-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.02.01.01.05.02.00
    AAF_LITERAL_AUID(0x07020201,
      0x0105, 0x0200,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1202,
    AAF_TYPE(LengthType),
    false,
    false,
    SourceClip)
  AAF_PROPERTY(FadeInType,
    // {05300501-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.05.01.00.00.00.00
    AAF_LITERAL_AUID(0x05300501,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1203,
    AAF_TYPE(FadeType),
    false,
    false,
    SourceClip)
  AAF_PROPERTY(FadeOutLength,
    // {07020201-0105-0300-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.02.01.01.05.03.00
    AAF_LITERAL_AUID(0x07020201,
      0x0105, 0x0300,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1204,
    AAF_TYPE(LengthType),
    false,
    false,
    SourceClip)
  AAF_PROPERTY(FadeOutType,
    // {05300502-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.05.02.00.00.00.00
    AAF_LITERAL_AUID(0x05300502,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1205,
    AAF_TYPE(FadeType),
    false,
    false,
    SourceClip)
AAF_CLASS_END(SourceClip,
  // {0D010101-0101-1100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.11.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SourceReference,
  true)
AAF_CLASS_SEPARATOR()

// TextClip
//
AAF_CLASS(TextClip,
  // {0D010101-0101-1200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.12.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SourceReference,
  false)
AAF_CLASS_END(TextClip,
  // {0D010101-0101-1200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.12.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SourceReference,
  false)
AAF_CLASS_SEPARATOR()

// HTMLClip
//
AAF_CLASS(HTMLClip,
  // {0D010101-0101-1300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.13.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TextClip,
  true)
  AAF_PROPERTY(BeginAnchor,
    // {05300601-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.06.01.01.00.00.00
    AAF_LITERAL_AUID(0x05300601,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1401,
    AAF_TYPE(String),
    false,
    false,
    HTMLClip)
  AAF_PROPERTY(EndAnchor,
    // {05300602-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.06.02.01.00.00.00
    AAF_LITERAL_AUID(0x05300602,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1402,
    AAF_TYPE(String),
    false,
    false,
    HTMLClip)
AAF_CLASS_END(HTMLClip,
  // {0D010101-0101-1300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.13.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TextClip,
  true)
AAF_CLASS_SEPARATOR()

// Timecode
//
AAF_CLASS(Timecode,
  // {0D010101-0101-1400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.14.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
  AAF_PROPERTY(Start,
    // {07020103-0105-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.01.05.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x0105, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1501,
    AAF_TYPE(PositionType),
    true,
    false,
    Timecode)
  AAF_PROPERTY(FPS,
    // {04040101-0206-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.04.01.01.02.06.00.00
    AAF_LITERAL_AUID(0x04040101,
      0x0206, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1502,
    AAF_TYPE(UInt16),
    true,
    false,
    Timecode)
  AAF_PROPERTY(Drop,
    // {04040101-0500-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.04.01.01.05.00.00.00
    AAF_LITERAL_AUID(0x04040101,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1503,
    AAF_TYPE(Boolean),
    true,
    false,
    Timecode)
AAF_CLASS_END(Timecode,
  // {0D010101-0101-1400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.14.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  true)
AAF_CLASS_SEPARATOR()

// TimecodeStream
//
AAF_CLASS(TimecodeStream,
  // {0D010101-0101-1500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.15.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
  AAF_PROPERTY(SampleRate,
    // {04040101-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.04.01.01.02.01.00.00
    AAF_LITERAL_AUID(0x04040101,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1601,
    AAF_TYPE(Rational),
    true,
    false,
    TimecodeStream)
  AAF_PROPERTY(Source,
    // {04070300-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.07.03.00.00.00.00.00
    AAF_LITERAL_AUID(0x04070300,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1602,
    AAF_TYPE(Stream),
    true,
    false,
    TimecodeStream)
  AAF_PROPERTY(SourceType,
    // {04040201-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.04.02.01.00.00.00.00
    AAF_LITERAL_AUID(0x04040201,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1603,
    AAF_TYPE(TCSource),
    true,
    false,
    TimecodeStream)
AAF_CLASS_END(TimecodeStream,
  // {0D010101-0101-1500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.15.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Segment,
  false)
AAF_CLASS_SEPARATOR()

// TimecodeStream12M
//
AAF_CLASS(TimecodeStream12M,
  // {0D010101-0101-1600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.16.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TimecodeStream,
  true)
  AAF_PROPERTY(IncludeSync,
    // {04040101-0400-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.04.01.01.04.00.00.00
    AAF_LITERAL_AUID(0x04040101,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1701,
    AAF_TYPE(Boolean),
    true,
    false,
    TimecodeStream12M)
AAF_CLASS_END(TimecodeStream12M,
  // {0D010101-0101-1600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.16.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TimecodeStream,
  true)
AAF_CLASS_SEPARATOR()

// Transition
//
AAF_CLASS(Transition,
  // {0D010101-0101-1700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.17.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Component,
  true)
  AAF_PROPERTY(OperationGroup,
    // {06010104-0205-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.05.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0205, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1801,
    AAF_REFERENCE_TYPE(StrongReference, OperationGroup),
    true,
    false,
    Transition)
  AAF_PROPERTY(CutPoint,
    // {07020103-0106-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.01.06.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x0106, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1802,
    AAF_TYPE(PositionType),
    true,
    false,
    Transition)
AAF_CLASS_END(Transition,
  // {0D010101-0101-1700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.17.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Component,
  true)
AAF_CLASS_SEPARATOR()

// ContentStorage
//
AAF_CLASS(ContentStorage,
  // {0D010101-0101-1800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.18.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(Mobs,
    // {06010104-0501-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0501, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1901,
    AAF_REFERENCE_TYPE(StrongReferenceSet, Mob),
    true,
    false,
    ContentStorage)
  AAF_PROPERTY(EssenceData,
    // {06010104-0502-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.02.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0502, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1902,
    AAF_REFERENCE_TYPE(StrongReferenceSet, EssenceData),
    false,
    false,
    ContentStorage)
AAF_CLASS_END(ContentStorage,
  // {0D010101-0101-1800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.18.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// ControlPoint
//
AAF_CLASS(ControlPoint,
  // {0D010101-0101-1900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.19.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(Value,
    // {0530050D-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.0D.00.00.00.00
    AAF_LITERAL_AUID(0x0530050D,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1a02,
    AAF_TYPE(Indirect),
    true,
    false,
    ControlPoint)
  AAF_PROPERTY(Time,
    // {07020103-1002-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.10.02.01.00
    AAF_LITERAL_AUID(0x07020103,
      0x1002, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1a03,
    AAF_TYPE(Rational),
    true,
    false,
    ControlPoint)
  AAF_PROPERTY(EditHint,
    // {05300508-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.08.00.00.00.00
    AAF_LITERAL_AUID(0x05300508,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1a04,
    AAF_TYPE(EditHintType),
    false,
    false,
    ControlPoint)
AAF_CLASS_END(ControlPoint,
  // {0D010101-0101-1900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.19.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// DefinitionObject
//
AAF_CLASS(DefinitionObject,
  // {0D010101-0101-1A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(Identification,
    // {01011503-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.01.15.03.00.00.00.00
    AAF_LITERAL_AUID(0x01011503,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1b01,
    AAF_TYPE(AUID),
    true,
    true,
    DefinitionObject)
  AAF_PROPERTY(Name,
    // {01070102-0301-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.07.01.02.03.01.00.00
    AAF_LITERAL_AUID(0x01070102,
      0x0301, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1b02,
    AAF_TYPE(String),
    true,
    false,
    DefinitionObject)
  AAF_PROPERTY(Description,
    // {03020301-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.02.03.01.02.01.00.00
    AAF_LITERAL_AUID(0x03020301,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1b03,
    AAF_TYPE(String),
    false,
    false,
    DefinitionObject)
AAF_CLASS_END(DefinitionObject,
  // {0D010101-0101-1A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// DataDefinition
//
AAF_CLASS(DataDefinition,
  // {0D010101-0101-1B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_END(DataDefinition,
  // {0D010101-0101-1B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// OperationDefinition
//
AAF_CLASS(OperationDefinition,
  // {0D010101-0101-1C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(DataDefinition,
    // {05300509-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.09.00.00.00.00
    AAF_LITERAL_AUID(0x05300509,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1e01,
    AAF_REFERENCE_TYPE(WeakReference, DataDefinition),
    true,
    false,
    OperationDefinition)
  AAF_PROPERTY(IsTimeWarp,
    // {05300503-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.05.03.00.00.00.00
    AAF_LITERAL_AUID(0x05300503,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1e02,
    AAF_TYPE(Boolean),
    false,
    false,
    OperationDefinition)
  AAF_PROPERTY(DegradeTo,
    // {06010104-0401-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.04.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0401, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1e03,
    AAF_REFERENCE_TYPE(WeakReferenceVector, OperationDefinition),
    false,
    false,
    OperationDefinition)
  AAF_PROPERTY(OperationCategory,
    // {0530050A-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.0A.00.00.00.00
    AAF_LITERAL_AUID(0x0530050A,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1e06,
    AAF_TYPE(OperationCategoryType),
    false,
    false,
    OperationDefinition)
  AAF_PROPERTY(NumberInputs,
    // {05300504-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.05.04.00.00.00.00
    AAF_LITERAL_AUID(0x05300504,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1e07,
    AAF_TYPE(Int32),
    true,
    false,
    OperationDefinition)
  AAF_PROPERTY(Bypass,
    // {05300505-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.05.05.00.00.00.00
    AAF_LITERAL_AUID(0x05300505,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x1e08,
    AAF_TYPE(UInt32),
    false,
    false,
    OperationDefinition)
  AAF_PROPERTY(ParametersDefined,
    // {06010104-0302-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.03.02.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0302, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1e09,
    AAF_REFERENCE_TYPE(WeakReferenceSet, ParameterDefinition),
    false,
    false,
    OperationDefinition)
AAF_CLASS_END(OperationDefinition,
  // {0D010101-0101-1C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// ParameterDefinition
//
AAF_CLASS(ParameterDefinition,
  // {0D010101-0101-1D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(Type,
    // {06010104-0106-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.06.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0106, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1f01,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    ParameterDefinition)
  AAF_PROPERTY(DisplayUnits,
    // {0530050B-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.0B.01.00.00.00
    AAF_LITERAL_AUID(0x0530050B,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x1f03,
    AAF_TYPE(String),
    false,
    false,
    ParameterDefinition)
AAF_CLASS_END(ParameterDefinition,
  // {0D010101-0101-1D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// PluginDefinition
//
AAF_CLASS(PluginDefinition,
  // {0D010101-0101-1E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(PluginCategory,
    // {05200901-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.01.00.00.00.00
    AAF_LITERAL_AUID(0x05200901,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2203,
    AAF_TYPE(PluginCategoryType),
    true,
    false,
    PluginDefinition)
  AAF_PROPERTY(VersionNumber,
    // {03030301-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.03.03.01.03.00.00.00
    AAF_LITERAL_AUID(0x03030301,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2204,
    AAF_TYPE(VersionType),
    true,
    false,
    PluginDefinition)
  AAF_PROPERTY(VersionString,
    // {03030301-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.03.03.01.02.01.00.00
    AAF_LITERAL_AUID(0x03030301,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2205,
    AAF_TYPE(String),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Manufacturer,
    // {010A0101-0101-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.0A.01.01.01.01.00.00
    AAF_LITERAL_AUID(0x010A0101,
      0x0101, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2206,
    AAF_TYPE(String),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(ManufacturerInfo,
    // {06010104-020B-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.0B.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x020B, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2207,
    AAF_REFERENCE_TYPE(StrongReference, NetworkLocator),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(ManufacturerID,
    // {010A0101-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.0A.01.01.03.00.00.00
    AAF_LITERAL_AUID(0x010A0101,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2208,
    AAF_TYPE(AUID),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Platform,
    // {05200902-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.02.00.00.00.00
    AAF_LITERAL_AUID(0x05200902,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2209,
    AAF_TYPE(AUID),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MinPlatformVersion,
    // {05200903-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.03.00.00.00.00
    AAF_LITERAL_AUID(0x05200903,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220a,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MaxPlatformVersion,
    // {05200904-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.04.00.00.00.00
    AAF_LITERAL_AUID(0x05200904,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220b,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Engine,
    // {05200905-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.05.00.00.00.00
    AAF_LITERAL_AUID(0x05200905,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220c,
    AAF_TYPE(AUID),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MinEngineVersion,
    // {05200906-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.06.00.00.00.00
    AAF_LITERAL_AUID(0x05200906,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220d,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MaxEngineVersion,
    // {05200907-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.07.00.00.00.00
    AAF_LITERAL_AUID(0x05200907,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220e,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(PluginAPI,
    // {05200908-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.08.00.00.00.00
    AAF_LITERAL_AUID(0x05200908,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x220f,
    AAF_TYPE(AUID),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MinPluginAPI,
    // {05200909-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.09.00.00.00.00
    AAF_LITERAL_AUID(0x05200909,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2210,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(MaxPluginAPI,
    // {0520090A-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0A.00.00.00.00
    AAF_LITERAL_AUID(0x0520090A,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2211,
    AAF_TYPE(VersionType),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(SoftwareOnly,
    // {0520090B-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0B.00.00.00.00
    AAF_LITERAL_AUID(0x0520090B,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2212,
    AAF_TYPE(Boolean),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Accelerator,
    // {0520090C-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0C.00.00.00.00
    AAF_LITERAL_AUID(0x0520090C,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2213,
    AAF_TYPE(Boolean),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Locators,
    // {0520090D-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0D.00.00.00.00
    AAF_LITERAL_AUID(0x0520090D,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2214,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Locator),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(Authentication,
    // {0520090E-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0E.00.00.00.00
    AAF_LITERAL_AUID(0x0520090E,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2215,
    AAF_TYPE(Boolean),
    false,
    false,
    PluginDefinition)
  AAF_PROPERTY(DefinitionObject,
    // {0520090F-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.09.0F.00.00.00.00
    AAF_LITERAL_AUID(0x0520090F,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2216,
    AAF_TYPE(AUID),
    false,
    false,
    PluginDefinition)
AAF_CLASS_END(PluginDefinition,
  // {0D010101-0101-1E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// CodecDefinition
//
AAF_CLASS(CodecDefinition,
  // {0D010101-0101-1F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(FileDescriptorClass,
    // {06010104-0107-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.07.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0107, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2301,
    AAF_REFERENCE_TYPE(WeakReference, ClassDefinition),
    true,
    false,
    CodecDefinition)
  AAF_PROPERTY(DataDefinitions,
    // {06010104-0301-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.03.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0301, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2302,
    AAF_REFERENCE_TYPE(WeakReferenceVector, DataDefinition),
    true,
    false,
    CodecDefinition)
AAF_CLASS_END(CodecDefinition,
  // {0D010101-0101-1F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.1F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x1F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// ContainerDefinition
//
AAF_CLASS(ContainerDefinition,
  // {0D010101-0101-2000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.20.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(EssenceIsIdentified,
    // {03010201-0300-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.03.01.02.01.03.00.00.00
    AAF_LITERAL_AUID(0x03010201,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x2401,
    AAF_TYPE(Boolean),
    false,
    false,
    ContainerDefinition)
AAF_CLASS_END(ContainerDefinition,
  // {0D010101-0101-2000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.20.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// InterpolationDefinition
//
AAF_CLASS(InterpolationDefinition,
  // {0D010101-0101-2100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.21.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_END(InterpolationDefinition,
  // {0D010101-0101-2100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.21.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// Dictionary
//
AAF_CLASS(Dictionary,
  // {0D010101-0101-2200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.22.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(OperationDefinitions,
    // {06010104-0503-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.03.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0503, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2603,
    AAF_REFERENCE_TYPE(StrongReferenceSet, OperationDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(ParameterDefinitions,
    // {06010104-0504-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.04.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0504, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2604,
    AAF_REFERENCE_TYPE(StrongReferenceSet, ParameterDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(DataDefinitions,
    // {06010104-0505-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.05.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0505, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2605,
    AAF_REFERENCE_TYPE(StrongReferenceSet, DataDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(PluginDefinitions,
    // {06010104-0506-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.06.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0506, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2606,
    AAF_REFERENCE_TYPE(StrongReferenceSet, PluginDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(CodecDefinitions,
    // {06010104-0507-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.07.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0507, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2607,
    AAF_REFERENCE_TYPE(StrongReferenceSet, CodecDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(ContainerDefinitions,
    // {06010104-0508-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.08.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0508, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2608,
    AAF_REFERENCE_TYPE(StrongReferenceSet, ContainerDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(InterpolationDefinitions,
    // {06010104-0509-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.05.09.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0509, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2609,
    AAF_REFERENCE_TYPE(StrongReferenceSet, InterpolationDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(KLVDataDefinitions,
    // {06010104-050A-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.06.01.01.04.05.0A.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x050A, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x260a,
    AAF_REFERENCE_TYPE(StrongReferenceSet, KLVDataDefinition),
    false,
    false,
    Dictionary)
  AAF_PROPERTY(TaggedValueDefinitions,
    // {06010104-050B-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.06.01.01.04.05.0B.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x050B, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x260b,
    AAF_REFERENCE_TYPE(StrongReferenceSet, TaggedValueDefinition),
    false,
    false,
    Dictionary)
AAF_CLASS_END(Dictionary,
  // {0D010101-0101-2200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.22.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// EssenceData
//
AAF_CLASS(EssenceData,
  // {0D010101-0101-2300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.23.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(MobID,
    // {06010106-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.06.01.00.00.00
    AAF_LITERAL_AUID(0x06010106,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2701,
    AAF_TYPE(MobIDType),
    true,
    true,
    EssenceData)
  AAF_PROPERTY(Data,
    // {04070200-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.07.02.00.00.00.00.00
    AAF_LITERAL_AUID(0x04070200,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2702,
    AAF_TYPE(Stream),
    true,
    false,
    EssenceData)
  AAF_PROPERTY(SampleIndex,
    // {06010102-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.02.01.00.00.00
    AAF_LITERAL_AUID(0x06010102,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2b01,
    AAF_TYPE(Stream),
    false,
    false,
    EssenceData)
AAF_CLASS_END(EssenceData,
  // {0D010101-0101-2300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.23.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// EssenceDescriptor
//
AAF_CLASS(EssenceDescriptor,
  // {0D010101-0101-2400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.24.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(Locator,
    // {06010104-0603-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.03.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0603, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x2f01,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Locator),
    false,
    false,
    EssenceDescriptor)
AAF_CLASS_END(EssenceDescriptor,
  // {0D010101-0101-2400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.24.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// FileDescriptor
//
AAF_CLASS(FileDescriptor,
  // {0D010101-0101-2500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.25.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  false)
  AAF_PROPERTY(SampleRate,
    // {04060101-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.06.01.01.00.00.00.00
    AAF_LITERAL_AUID(0x04060101,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3001,
    AAF_TYPE(Rational),
    true,
    false,
    FileDescriptor)
  AAF_PROPERTY(Length,
    // {04060102-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.06.01.02.00.00.00.00
    AAF_LITERAL_AUID(0x04060102,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3002,
    AAF_TYPE(LengthType),
    true,
    false,
    FileDescriptor)
  AAF_PROPERTY(ContainerFormat,
    // {06010104-0102-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.02.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0102, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3004,
    AAF_REFERENCE_TYPE(WeakReference, ContainerDefinition),
    false,
    false,
    FileDescriptor)
  AAF_PROPERTY(CodecDefinition,
    // {06010104-0103-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.03.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0103, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3005,
    AAF_REFERENCE_TYPE(WeakReference, CodecDefinition),
    false,
    false,
    FileDescriptor)
AAF_CLASS_END(FileDescriptor,
  // {0D010101-0101-2500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.25.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  false)
AAF_CLASS_SEPARATOR()

// AIFCDescriptor
//
AAF_CLASS(AIFCDescriptor,
  // {0D010101-0101-2600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.26.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
  AAF_PROPERTY(Summary,
    // {03030302-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.03.03.02.02.00.00.00
    AAF_LITERAL_AUID(0x03030302,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3101,
    AAF_TYPE(DataValue),
    true,
    false,
    AIFCDescriptor)
AAF_CLASS_END(AIFCDescriptor,
  // {0D010101-0101-2600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.26.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// DigitalImageDescriptor
//
AAF_CLASS(DigitalImageDescriptor,
  // {0D010101-0101-2700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.27.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  false)
  AAF_PROPERTY(Compression,
    // {04010601-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.06.01.00.00.00.00
    AAF_LITERAL_AUID(0x04010601,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3201,
    AAF_TYPE(AUID),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(StoredHeight,
    // {04010502-0100-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.02.01.00.00.00
    AAF_LITERAL_AUID(0x04010502,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3202,
    AAF_TYPE(UInt32),
    true,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(StoredWidth,
    // {04010502-0200-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.02.02.00.00.00
    AAF_LITERAL_AUID(0x04010502,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3203,
    AAF_TYPE(UInt32),
    true,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(SampledHeight,
    // {04010501-0700-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.07.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3204,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(SampledWidth,
    // {04010501-0800-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.08.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3205,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(SampledXOffset,
    // {04010501-0900-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.09.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0900, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3206,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(SampledYOffset,
    // {04010501-0A00-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.0A.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3207,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(DisplayHeight,
    // {04010501-0B00-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.0B.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0B00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3208,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(DisplayWidth,
    // {04010501-0C00-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.0C.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0C00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3209,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(DisplayXOffset,
    // {04010501-0D00-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.0D.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0D00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x320a,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(DisplayYOffset,
    // {04010501-0E00-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.0E.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0E00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x320b,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(FrameLayout,
    // {04010301-0400-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.03.01.04.00.00.00
    AAF_LITERAL_AUID(0x04010301,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x320c,
    AAF_TYPE(LayoutType),
    true,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(VideoLineMap,
    // {04010302-0500-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.03.02.05.00.00.00
    AAF_LITERAL_AUID(0x04010302,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x320d,
    AAF_TYPE(Int32Array),
    true,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(ImageAspectRatio,
    // {04010101-0100-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.01.01.01.00.00.00
    AAF_LITERAL_AUID(0x04010101,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x320e,
    AAF_TYPE(Rational),
    true,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(AlphaTransparency,
    // {05200102-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.01.02.00.00.00.00
    AAF_LITERAL_AUID(0x05200102,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x320f,
    AAF_TYPE(AlphaTransparencyType),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(TransferCharacteristic,
    // {04010201-0101-0200-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.02.01.01.01.02.00
    AAF_LITERAL_AUID(0x04010201,
      0x0101, 0x0200,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3210,
    AAF_TYPE(TransferCharacteristicType),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(ColorPrimaries,
    // {04010201-016-100-060E-2B340101019}
    // 06.0E.2B.34.01.01.01.9.04.01.02.01.01.6.1.00
    AAF_LITERAL_AUID(0x04010201,
      0x016, 0x100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x9),
    0x3219,
    AAF_TYPE(ColorPrimariesType),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(CodingEquations,
    // {04010201-013-100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.02.01.01.3.1.00
    AAF_LITERAL_AUID(0x04010201,
      0x013, 0x100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x321a,
    AAF_TYPE(CodingEquationsType),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(ImageAlignmentFactor,
    // {04180101-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.18.01.01.00.00.00.00
    AAF_LITERAL_AUID(0x04180101,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3211,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(FieldDominance,
    // {04010301-0600-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.03.01.06.00.00.00
    AAF_LITERAL_AUID(0x04010301,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3212,
    AAF_TYPE(FieldNumber),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(FieldStartOffset,
    // {04180102-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.18.01.02.00.00.00.00
    AAF_LITERAL_AUID(0x04180102,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3213,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(FieldEndOffset,
    // {04180103-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.18.01.03.00.00.00.00
    AAF_LITERAL_AUID(0x04180103,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3214,
    AAF_TYPE(UInt32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(SignalStandard,
    // {045113-0000-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.5.1.13.00.00.00.00
    AAF_LITERAL_AUID(0x045113,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3215,
    AAF_TYPE(SignalStandardType),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(StoredF2Offset,
    // {04132-800-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.3.2.8.00.00.00
    AAF_LITERAL_AUID(0x04132,
      0x800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3216,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(DisplayF2Offset,
    // {04132-700-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.3.2.7.00.00.00
    AAF_LITERAL_AUID(0x04132,
      0x700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3217,
    AAF_TYPE(Int32),
    false,
    false,
    DigitalImageDescriptor)
  AAF_PROPERTY(ActiveFormatDescriptor,
    // {04132-900-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.3.2.9.00.00.00
    AAF_LITERAL_AUID(0x04132,
      0x900, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3218,
    AAF_TYPE(UInt8),
    false,
    false,
    DigitalImageDescriptor)
AAF_CLASS_END(DigitalImageDescriptor,
  // {0D010101-0101-2700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.27.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  false)
AAF_CLASS_SEPARATOR()

// CDCIDescriptor
//
AAF_CLASS(CDCIDescriptor,
  // {0D010101-0101-2800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.28.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DigitalImageDescriptor,
  true)
  AAF_PROPERTY(ComponentWidth,
    // {04010503-0A00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.0A.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3301,
    AAF_TYPE(UInt32),
    true,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(HorizontalSubsampling,
    // {04010501-0500-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.05.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3302,
    AAF_TYPE(UInt32),
    true,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(ColorSiting,
    // {04010501-0600-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.01.06.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3303,
    AAF_TYPE(ColorSitingType),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(BlackReferenceLevel,
    // {04010503-0300-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.03.03.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3304,
    AAF_TYPE(UInt32),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(WhiteReferenceLevel,
    // {04010503-0400-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.05.03.04.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3305,
    AAF_TYPE(UInt32),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(ColorRange,
    // {04010503-0500-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.05.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3306,
    AAF_TYPE(UInt32),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(PaddingBits,
    // {04180104-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.18.01.04.00.00.00.00
    AAF_LITERAL_AUID(0x04180104,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3307,
    AAF_TYPE(Int16),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(VerticalSubsampling,
    // {04010501-1000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.01.10.00.00.00
    AAF_LITERAL_AUID(0x04010501,
      0x1000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3308,
    AAF_TYPE(UInt32),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(AlphaSamplingWidth,
    // {04010503-0700-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.07.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3309,
    AAF_TYPE(UInt32),
    false,
    false,
    CDCIDescriptor)
  AAF_PROPERTY(ReversedByteOrder,
    // {3121-0A00-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.3.1.2.1.0A.00.00.00
    AAF_LITERAL_AUID(0x3121,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x330b,
    AAF_TYPE(Boolean),
    false,
    false,
    CDCIDescriptor)
AAF_CLASS_END(CDCIDescriptor,
  // {0D010101-0101-2800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.28.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DigitalImageDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// RGBADescriptor
//
AAF_CLASS(RGBADescriptor,
  // {0D010101-0101-2900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.29.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DigitalImageDescriptor,
  true)
  AAF_PROPERTY(PixelLayout,
    // {04010503-0600-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.06.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3401,
    AAF_TYPE(RGBALayout),
    true,
    false,
    RGBADescriptor)
  AAF_PROPERTY(Palette,
    // {04010503-0800-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.08.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3403,
    AAF_TYPE(DataValue),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(PaletteLayout,
    // {04010503-0900-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.05.03.09.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0900, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3404,
    AAF_TYPE(RGBALayout),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(ScanningDirection,
    // {040144-100-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.01.4.4.1.00.00.00
    AAF_LITERAL_AUID(0x040144,
      0x100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3405,
    AAF_TYPE(ScanningDirectionType),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(ComponentMaxRef,
    // {04010503-0B00-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.01.05.03.0B.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0B00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3406,
    AAF_TYPE(UInt32),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(ComponentMinRef,
    // {04010503-0C00-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.01.05.03.0C.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0C00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3407,
    AAF_TYPE(UInt32),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(AlphaMaxRef,
    // {04010503-0D00-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.01.05.03.0D.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0D00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3408,
    AAF_TYPE(UInt32),
    false,
    false,
    RGBADescriptor)
  AAF_PROPERTY(AlphaMinRef,
    // {04010503-0E00-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.01.05.03.0E.00.00.00
    AAF_LITERAL_AUID(0x04010503,
      0x0E00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3409,
    AAF_TYPE(UInt32),
    false,
    false,
    RGBADescriptor)
AAF_CLASS_END(RGBADescriptor,
  // {0D010101-0101-2900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.29.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DigitalImageDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// HTMLDescriptor
//
AAF_CLASS(HTMLDescriptor,
  // {0D010101-0101-2A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_END(HTMLDescriptor,
  // {0D010101-0101-2A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// TIFFDescriptor
//
AAF_CLASS(TIFFDescriptor,
  // {0D010101-0101-2B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
  AAF_PROPERTY(IsUniform,
    // {05020103-0101-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.02.01.03.01.01.00.00
    AAF_LITERAL_AUID(0x05020103,
      0x0101, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3701,
    AAF_TYPE(Boolean),
    true,
    false,
    TIFFDescriptor)
  AAF_PROPERTY(IsContiguous,
    // {06080201-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.06.08.02.01.00.00.00.00
    AAF_LITERAL_AUID(0x06080201,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3702,
    AAF_TYPE(Boolean),
    true,
    false,
    TIFFDescriptor)
  AAF_PROPERTY(LeadingLines,
    // {04010302-0300-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.03.02.03.00.00.00
    AAF_LITERAL_AUID(0x04010302,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3703,
    AAF_TYPE(Int32),
    false,
    false,
    TIFFDescriptor)
  AAF_PROPERTY(TrailingLines,
    // {04010302-0400-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.01.03.02.04.00.00.00
    AAF_LITERAL_AUID(0x04010302,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3704,
    AAF_TYPE(Int32),
    false,
    false,
    TIFFDescriptor)
  AAF_PROPERTY(JPEGTableID,
    // {05020103-0102-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.02.01.03.01.02.00.00
    AAF_LITERAL_AUID(0x05020103,
      0x0102, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3705,
    AAF_TYPE(JPEGTableIDType),
    false,
    false,
    TIFFDescriptor)
  AAF_PROPERTY(Summary,
    // {03030302-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.03.03.02.03.00.00.00
    AAF_LITERAL_AUID(0x03030302,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3706,
    AAF_TYPE(DataValue),
    true,
    false,
    TIFFDescriptor)
AAF_CLASS_END(TIFFDescriptor,
  // {0D010101-0101-2B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// WAVEDescriptor
//
AAF_CLASS(WAVEDescriptor,
  // {0D010101-0101-2C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
  AAF_PROPERTY(Summary,
    // {03030302-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.03.03.02.01.00.00.00
    AAF_LITERAL_AUID(0x03030302,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3801,
    AAF_TYPE(DataValue),
    true,
    false,
    WAVEDescriptor)
AAF_CLASS_END(WAVEDescriptor,
  // {0D010101-0101-2C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// FilmDescriptor
//
AAF_CLASS(FilmDescriptor,
  // {0D010101-0101-2D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  true)
  AAF_PROPERTY(FilmFormat,
    // {04100103-0108-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.08.00.00
    AAF_LITERAL_AUID(0x04100103,
      0x0108, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3901,
    AAF_TYPE(FilmType),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(FrameRate,
    // {04010802-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.08.02.03.00.00.00
    AAF_LITERAL_AUID(0x04010802,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3902,
    AAF_TYPE(UInt32),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(PerforationsPerFrame,
    // {04100103-0103-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.03.00.00
    AAF_LITERAL_AUID(0x04100103,
      0x0103, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3903,
    AAF_TYPE(UInt8),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(FilmAspectRatio,
    // {04100103-0203-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.02.03.00.00
    AAF_LITERAL_AUID(0x04100103,
      0x0203, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3904,
    AAF_TYPE(Rational),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(Manufacturer,
    // {04100103-0106-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.06.01.00
    AAF_LITERAL_AUID(0x04100103,
      0x0106, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3905,
    AAF_TYPE(String),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(Model,
    // {04100103-0105-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.05.01.00
    AAF_LITERAL_AUID(0x04100103,
      0x0105, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3906,
    AAF_TYPE(String),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(FilmGaugeFormat,
    // {04100103-0104-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.04.01.00
    AAF_LITERAL_AUID(0x04100103,
      0x0104, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3907,
    AAF_TYPE(String),
    false,
    false,
    FilmDescriptor)
  AAF_PROPERTY(FilmBatchNumber,
    // {04100103-0107-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.03.01.07.01.00
    AAF_LITERAL_AUID(0x04100103,
      0x0107, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3908,
    AAF_TYPE(String),
    false,
    false,
    FilmDescriptor)
AAF_CLASS_END(FilmDescriptor,
  // {0D010101-0101-2D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// TapeDescriptor
//
AAF_CLASS(TapeDescriptor,
  // {0D010101-0101-2E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  true)
  AAF_PROPERTY(FormFactor,
    // {04100101-0101-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.01.01.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0101, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a01,
    AAF_TYPE(TapeCaseType),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(VideoSignal,
    // {04010401-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.01.04.01.01.00.00.00
    AAF_LITERAL_AUID(0x04010401,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a02,
    AAF_TYPE(VideoSignalType),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(TapeFormat,
    // {0D010101-0101-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.0D.01.01.01.01.01.01.00
    AAF_LITERAL_AUID(0x0D010101,
      0x0101, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a03,
    AAF_TYPE(TapeFormatType),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(Length,
    // {04100101-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.03.00.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a04,
    AAF_TYPE(UInt32),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(ManufacturerID,
    // {04100101-0401-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.04.01.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0401, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a05,
    AAF_TYPE(String),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(Model,
    // {04100101-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.02.01.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a06,
    AAF_TYPE(String),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(TapeBatchNumber,
    // {04100101-0601-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.06.01.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0601, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a07,
    AAF_TYPE(String),
    false,
    false,
    TapeDescriptor)
  AAF_PROPERTY(TapeStock,
    // {04100101-0501-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.10.01.01.05.01.00.00
    AAF_LITERAL_AUID(0x04100101,
      0x0501, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3a08,
    AAF_TYPE(String),
    false,
    false,
    TapeDescriptor)
AAF_CLASS_END(TapeDescriptor,
  // {0D010101-0101-2E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// Header
//
AAF_CLASS(Header,
  // {0D010101-0101-2F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(ByteOrder,
    // {03010201-0200-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.03.01.02.01.02.00.00.00
    AAF_LITERAL_AUID(0x03010201,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3b01,
    AAF_TYPE(Int16),
    true,
    false,
    Header)
  AAF_PROPERTY(LastModified,
    // {07020110-0204-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.10.02.04.00.00
    AAF_LITERAL_AUID(0x07020110,
      0x0204, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b02,
    AAF_TYPE(TimeStamp),
    true,
    false,
    Header)
  AAF_PROPERTY(Content,
    // {06010104-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.01.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b03,
    AAF_REFERENCE_TYPE(StrongReference, ContentStorage),
    true,
    false,
    Header)
  AAF_PROPERTY(Dictionary,
    // {06010104-0202-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.02.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0202, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b04,
    AAF_REFERENCE_TYPE(StrongReference, Dictionary),
    true,
    false,
    Header)
  AAF_PROPERTY(Version,
    // {03010201-0500-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.01.05.00.00.00
    AAF_LITERAL_AUID(0x03010201,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b05,
    AAF_TYPE(VersionType),
    true,
    false,
    Header)
  AAF_PROPERTY(IdentificationList,
    // {06010104-0604-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.04.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0604, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b06,
    AAF_REFERENCE_TYPE(StrongReferenceVector, Identification),
    true,
    false,
    Header)
  AAF_PROPERTY(ObjectModelVersion,
    // {03010201-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.01.04.00.00.00
    AAF_LITERAL_AUID(0x03010201,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3b07,
    AAF_TYPE(UInt32),
    false,
    false,
    Header)
  AAF_PROPERTY(OperationalPattern,
    // {01020203-0000-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.01.02.02.03.00.00.00.00
    AAF_LITERAL_AUID(0x01020203,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3b09,
    AAF_TYPE(AUID),
    false,
    false,
    Header)
  AAF_PROPERTY(EssenceContainers,
    // {01020210-0201-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.01.02.02.10.02.01.00.00
    AAF_LITERAL_AUID(0x01020210,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3b0a,
    AAF_TYPE(AUIDSet),
    false,
    false,
    Header)
  AAF_PROPERTY(DescriptiveSchemes,
    // {01020210-0202-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.01.02.02.10.02.02.00.00
    AAF_LITERAL_AUID(0x01020210,
      0x0202, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3b0b,
    AAF_TYPE(AUIDSet),
    false,
    false,
    Header)
AAF_CLASS_END(Header,
  // {0D010101-0101-2F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.2F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x2F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// Identification
//
AAF_CLASS(Identification,
  // {0D010101-0101-3000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.30.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(CompanyName,
    // {05200701-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.02.01.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c01,
    AAF_TYPE(String),
    true,
    false,
    Identification)
  AAF_PROPERTY(ProductName,
    // {05200701-0301-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.03.01.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0301, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c02,
    AAF_TYPE(String),
    true,
    false,
    Identification)
  AAF_PROPERTY(ProductVersion,
    // {05200701-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.04.00.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c03,
    AAF_TYPE(ProductVersion),
    false,
    false,
    Identification)
  AAF_PROPERTY(ProductVersionString,
    // {05200701-0501-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.05.01.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0501, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c04,
    AAF_TYPE(String),
    true,
    false,
    Identification)
  AAF_PROPERTY(ProductID,
    // {05200701-0700-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.07.00.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c05,
    AAF_TYPE(AUID),
    true,
    false,
    Identification)
  AAF_PROPERTY(Date,
    // {07020110-0203-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.10.02.03.00.00
    AAF_LITERAL_AUID(0x07020110,
      0x0203, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c06,
    AAF_TYPE(TimeStamp),
    true,
    false,
    Identification)
  AAF_PROPERTY(ToolkitVersion,
    // {05200701-0A00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.0A.00.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c07,
    AAF_TYPE(ProductVersion),
    false,
    false,
    Identification)
  AAF_PROPERTY(Platform,
    // {05200701-0601-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.06.01.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0601, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c08,
    AAF_TYPE(String),
    false,
    false,
    Identification)
  AAF_PROPERTY(GenerationAUID,
    // {05200701-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.20.07.01.01.00.00.00
    AAF_LITERAL_AUID(0x05200701,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3c09,
    AAF_TYPE(AUID),
    true,
    false,
    Identification)
AAF_CLASS_END(Identification,
  // {0D010101-0101-3000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.30.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// Locator
//
AAF_CLASS(Locator,
  // {0D010101-0101-3100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.31.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_END(Locator,
  // {0D010101-0101-3100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.31.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// NetworkLocator
//
AAF_CLASS(NetworkLocator,
  // {0D010101-0101-3200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.32.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Locator,
  true)
  AAF_PROPERTY(URLString,
    // {01020101-0100-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.01.02.01.01.01.00.00.00
    AAF_LITERAL_AUID(0x01020101,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x4001,
    AAF_TYPE(String),
    true,
    false,
    NetworkLocator)
AAF_CLASS_END(NetworkLocator,
  // {0D010101-0101-3200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.32.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Locator,
  true)
AAF_CLASS_SEPARATOR()

// TextLocator
//
AAF_CLASS(TextLocator,
  // {0D010101-0101-3300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.33.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Locator,
  true)
  AAF_PROPERTY(Name,
    // {01040102-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.04.01.02.01.00.00.00
    AAF_LITERAL_AUID(0x01040102,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4101,
    AAF_TYPE(String),
    true,
    false,
    TextLocator)
AAF_CLASS_END(TextLocator,
  // {0D010101-0101-3300-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.33.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3300,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Locator,
  true)
AAF_CLASS_SEPARATOR()

// Mob
//
AAF_CLASS(Mob,
  // {0D010101-0101-3400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.34.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(MobID,
    // {01011510-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.01.01.15.10.00.00.00.00
    AAF_LITERAL_AUID(0x01011510,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x4401,
    AAF_TYPE(MobIDType),
    true,
    true,
    Mob)
  AAF_PROPERTY(Name,
    // {01030302-0100-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.01.03.03.02.01.00.00.00
    AAF_LITERAL_AUID(0x01030302,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x4402,
    AAF_TYPE(String),
    false,
    false,
    Mob)
  AAF_PROPERTY(Slots,
    // {06010104-0605-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.05.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0605, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4403,
    AAF_REFERENCE_TYPE(StrongReferenceVector, MobSlot),
    true,
    false,
    Mob)
  AAF_PROPERTY(LastModified,
    // {07020110-0205-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.10.02.05.00.00
    AAF_LITERAL_AUID(0x07020110,
      0x0205, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4404,
    AAF_TYPE(TimeStamp),
    true,
    false,
    Mob)
  AAF_PROPERTY(CreationTime,
    // {07020110-0103-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.10.01.03.00.00
    AAF_LITERAL_AUID(0x07020110,
      0x0103, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4405,
    AAF_TYPE(TimeStamp),
    true,
    false,
    Mob)
  AAF_PROPERTY(UserComments,
    // {03020102-0C00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.02.01.02.0C.00.00.00
    AAF_LITERAL_AUID(0x03020102,
      0x0C00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4406,
    AAF_REFERENCE_TYPE(StrongReferenceVector, TaggedValue),
    false,
    false,
    Mob)
  AAF_PROPERTY(KLVData,
    // {03010210-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.10.03.00.00.00
    AAF_LITERAL_AUID(0x03010210,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4407,
    AAF_REFERENCE_TYPE(StrongReferenceVector, KLVData),
    false,
    false,
    Mob)
  AAF_PROPERTY(Attributes,
    // {03010210-0700-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.03.01.02.10.07.00.00.00
    AAF_LITERAL_AUID(0x03010210,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4409,
    AAF_REFERENCE_TYPE(StrongReferenceVector, TaggedValue),
    false,
    false,
    Mob)
  AAF_PROPERTY(UsageCode,
    // {05010108-0000-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.05.01.01.08.00.00.00.00
    AAF_LITERAL_AUID(0x05010108,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4408,
    AAF_TYPE(UsageType),
    false,
    false,
    Mob)
AAF_CLASS_END(Mob,
  // {0D010101-0101-3400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.34.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// CompositionMob
//
AAF_CLASS(CompositionMob,
  // {0D010101-0101-3500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.35.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
  AAF_PROPERTY(DefaultFadeLength,
    // {07020201-0105-0100-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.02.01.01.05.01.00
    AAF_LITERAL_AUID(0x07020201,
      0x0105, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4501,
    AAF_TYPE(LengthType),
    false,
    false,
    CompositionMob)
  AAF_PROPERTY(DefFadeType,
    // {05300201-0000-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.05.30.02.01.00.00.00.00
    AAF_LITERAL_AUID(0x05300201,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x4502,
    AAF_TYPE(FadeType),
    false,
    false,
    CompositionMob)
  AAF_PROPERTY(DefFadeEditUnit,
    // {05300403-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.04.03.00.00.00.00
    AAF_LITERAL_AUID(0x05300403,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4503,
    AAF_TYPE(Rational),
    false,
    false,
    CompositionMob)
  AAF_PROPERTY(Rendering,
    // {06010104-010A-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.06.01.01.04.01.0A.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x010A, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x4504,
    AAF_TYPE(MobIDType),
    false,
    false,
    CompositionMob)
AAF_CLASS_END(CompositionMob,
  // {0D010101-0101-3500-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.35.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3500,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
AAF_CLASS_SEPARATOR()

// MasterMob
//
AAF_CLASS(MasterMob,
  // {0D010101-0101-3600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.36.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
AAF_CLASS_END(MasterMob,
  // {0D010101-0101-3600-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.36.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3600,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
AAF_CLASS_SEPARATOR()

// SourceMob
//
AAF_CLASS(SourceMob,
  // {0D010101-0101-3700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.37.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
  AAF_PROPERTY(EssenceDescription,
    // {06010104-0203-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.03.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0203, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4701,
    AAF_REFERENCE_TYPE(StrongReference, EssenceDescriptor),
    true,
    false,
    SourceMob)
AAF_CLASS_END(SourceMob,
  // {0D010101-0101-3700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.37.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Mob,
  true)
AAF_CLASS_SEPARATOR()

// MobSlot
//
AAF_CLASS(MobSlot,
  // {0D010101-0101-3800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.38.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(SlotID,
    // {01070101-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.07.01.01.00.00.00.00
    AAF_LITERAL_AUID(0x01070101,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4801,
    AAF_TYPE(UInt32),
    true,
    false,
    MobSlot)
  AAF_PROPERTY(SlotName,
    // {01070102-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.07.01.02.01.00.00.00
    AAF_LITERAL_AUID(0x01070102,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4802,
    AAF_TYPE(String),
    false,
    false,
    MobSlot)
  AAF_PROPERTY(Segment,
    // {06010104-0204-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.02.04.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0204, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4803,
    AAF_REFERENCE_TYPE(StrongReference, Segment),
    true,
    false,
    MobSlot)
  AAF_PROPERTY(PhysicalTrackNumber,
    // {01040103-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.01.04.01.03.00.00.00.00
    AAF_LITERAL_AUID(0x01040103,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4804,
    AAF_TYPE(UInt32),
    false,
    false,
    MobSlot)
AAF_CLASS_END(MobSlot,
  // {0D010101-0101-3800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.38.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// EventMobSlot
//
AAF_CLASS(EventMobSlot,
  // {0D010101-0101-3900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.39.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
  AAF_PROPERTY(EditRate,
    // {05300402-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.04.02.00.00.00.00
    AAF_LITERAL_AUID(0x05300402,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4901,
    AAF_TYPE(Rational),
    true,
    false,
    EventMobSlot)
AAF_CLASS_END(EventMobSlot,
  // {0D010101-0101-3900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.39.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
AAF_CLASS_SEPARATOR()

// StaticMobSlot
//
AAF_CLASS(StaticMobSlot,
  // {0D010101-0101-3A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
AAF_CLASS_END(StaticMobSlot,
  // {0D010101-0101-3A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
AAF_CLASS_SEPARATOR()

// TimelineMobSlot
//
AAF_CLASS(TimelineMobSlot,
  // {0D010101-0101-3B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
  AAF_PROPERTY(EditRate,
    // {05300405-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.04.05.00.00.00.00
    AAF_LITERAL_AUID(0x05300405,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4b01,
    AAF_TYPE(Rational),
    true,
    false,
    TimelineMobSlot)
  AAF_PROPERTY(Origin,
    // {07020103-0103-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.07.02.01.03.01.03.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x0103, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4b02,
    AAF_TYPE(PositionType),
    true,
    false,
    TimelineMobSlot)
  AAF_PROPERTY(MarkIn,
    // {07020103-010C-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.07.02.01.03.01.0C.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x010C, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4b03,
    AAF_TYPE(PositionType),
    false,
    false,
    TimelineMobSlot)
  AAF_PROPERTY(MarkOut,
    // {07020103-203-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.07.02.01.03.2.03.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x203, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4b04,
    AAF_TYPE(PositionType),
    false,
    false,
    TimelineMobSlot)
  AAF_PROPERTY(UserPos,
    // {07020103-010D-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.07.02.01.03.01.0D.00.00
    AAF_LITERAL_AUID(0x07020103,
      0x010D, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4b05,
    AAF_TYPE(PositionType),
    false,
    false,
    TimelineMobSlot)
AAF_CLASS_END(TimelineMobSlot,
  // {0D010101-0101-3B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MobSlot,
  true)
AAF_CLASS_SEPARATOR()

// Parameter
//
AAF_CLASS(Parameter,
  // {0D010101-0101-3C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
  AAF_PROPERTY(Definition,
    // {06010104-0104-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.04.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0104, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4c01,
    AAF_TYPE(AUID),
    true,
    false,
    Parameter)
AAF_CLASS_END(Parameter,
  // {0D010101-0101-3C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// ConstantValue
//
AAF_CLASS(ConstantValue,
  // {0D010101-0101-3D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Parameter,
  true)
  AAF_PROPERTY(Value,
    // {05300507-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.05.30.05.07.00.00.00.00
    AAF_LITERAL_AUID(0x05300507,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4d01,
    AAF_TYPE(Indirect),
    true,
    false,
    ConstantValue)
AAF_CLASS_END(ConstantValue,
  // {0D010101-0101-3D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Parameter,
  true)
AAF_CLASS_SEPARATOR()

// VaryingValue
//
AAF_CLASS(VaryingValue,
  // {0D010101-0101-3E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Parameter,
  true)
  AAF_PROPERTY(Interpolation,
    // {06010104-0105-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.01.05.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0105, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4e01,
    AAF_REFERENCE_TYPE(WeakReference, InterpolationDefinition),
    true,
    false,
    VaryingValue)
  AAF_PROPERTY(PointList,
    // {06010104-0606-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.04.06.06.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0606, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x4e02,
    AAF_REFERENCE_TYPE(StrongReferenceVector, ControlPoint),
    true,
    false,
    VaryingValue)
AAF_CLASS_END(VaryingValue,
  // {0D010101-0101-3E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Parameter,
  true)
AAF_CLASS_SEPARATOR()

// TaggedValue
//
AAF_CLASS(TaggedValue,
  // {0D010101-0101-3F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(Name,
    // {03020102-0901-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.02.01.02.09.01.00.00
    AAF_LITERAL_AUID(0x03020102,
      0x0901, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x5001,
    AAF_TYPE(String),
    true,
    false,
    TaggedValue)
  AAF_PROPERTY(Value,
    // {03020102-0A01-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.02.01.02.0A.01.00.00
    AAF_LITERAL_AUID(0x03020102,
      0x0A01, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x5003,
    AAF_TYPE(Indirect),
    true,
    false,
    TaggedValue)
AAF_CLASS_END(TaggedValue,
  // {0D010101-0101-3F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.3F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x3F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// KLVData
//
AAF_CLASS(KLVData,
  // {0D010101-0101-4000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.40.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(Value,
    // {03010210-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.10.02.00.00.00
    AAF_LITERAL_AUID(0x03010210,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x5101,
    AAF_TYPE(Opaque),
    true,
    false,
    KLVData)
AAF_CLASS_END(KLVData,
  // {0D010101-0101-4000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.40.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// DescriptiveMarker
//
AAF_CLASS(DescriptiveMarker,
  // {0D010101-0101-4100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.41.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  CommentMarker,
  true)
  AAF_PROPERTY(DescribedSlots,
    // {01070105-0000-0000-060E-2B3401010104}
    // 06.0E.2B.34.01.01.01.04.01.07.01.05.00.00.00.00
    AAF_LITERAL_AUID(0x01070105,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x04),
    0x6102,
    AAF_TYPE(UInt32Set),
    false,
    false,
    DescriptiveMarker)
  AAF_PROPERTY(Description,
    // {06010104-020C-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.06.01.01.04.02.0C.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x020C, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x6101,
    AAF_REFERENCE_TYPE(StrongReference, DescriptiveFramework),
    false,
    false,
    DescriptiveMarker)
AAF_CLASS_END(DescriptiveMarker,
  // {0D010101-0101-4100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.41.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  CommentMarker,
  true)
AAF_CLASS_SEPARATOR()

// SoundDescriptor
//
AAF_CLASS(SoundDescriptor,
  // {0D010101-0101-4200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.42.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
  AAF_PROPERTY(AudioSamplingRate,
    // {04020301-0101-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.03.01.01.01.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0101, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d03,
    AAF_TYPE(Rational),
    true,
    false,
    SoundDescriptor)
  AAF_PROPERTY(Locked,
    // {04020301-0400-0000-060E-2B3401010104}
    // 06.0E.2B.34.01.01.01.04.04.02.03.01.04.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x04),
    0x3d02,
    AAF_TYPE(Boolean),
    false,
    false,
    SoundDescriptor)
  AAF_PROPERTY(AudioRefLevel,
    // {04020101-0300-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.02.01.01.03.00.00.00
    AAF_LITERAL_AUID(0x04020101,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3d04,
    AAF_TYPE(Int8),
    false,
    false,
    SoundDescriptor)
  AAF_PROPERTY(ElectroSpatial,
    // {04020101-0100-0000-060E-2B3401010101}
    // 06.0E.2B.34.01.01.01.01.04.02.01.01.01.00.00.00
    AAF_LITERAL_AUID(0x04020101,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x01),
    0x3d05,
    AAF_TYPE(ElectroSpatialFormulation),
    false,
    false,
    SoundDescriptor)
  AAF_PROPERTY(Channels,
    // {04020101-0400-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.01.01.04.00.00.00
    AAF_LITERAL_AUID(0x04020101,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d07,
    AAF_TYPE(UInt32),
    true,
    false,
    SoundDescriptor)
  AAF_PROPERTY(QuantizationBits,
    // {04020303-0400-0000-060E-2B3401010104}
    // 06.0E.2B.34.01.01.01.04.04.02.03.03.04.00.00.00
    AAF_LITERAL_AUID(0x04020303,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x04),
    0x3d01,
    AAF_TYPE(UInt32),
    true,
    false,
    SoundDescriptor)
  AAF_PROPERTY(DialNorm,
    // {04020701-0000-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.07.01.00.00.00.00
    AAF_LITERAL_AUID(0x04020701,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d0c,
    AAF_TYPE(Int8),
    false,
    false,
    SoundDescriptor)
  AAF_PROPERTY(Compression,
    // {04020402-0000-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.04.02.04.02.00.00.00.00
    AAF_LITERAL_AUID(0x04020402,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x3d06,
    AAF_TYPE(AUID),
    false,
    false,
    SoundDescriptor)
AAF_CLASS_END(SoundDescriptor,
  // {0D010101-0101-4200-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.42.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4200,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// MultipleDescriptor
//
AAF_CLASS(MultipleDescriptor,
  // {0D010101-0101-4400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.44.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
  AAF_PROPERTY(FileDescriptors,
    // {06010104-060B-0000-060E-2B3401010104}
    // 06.0E.2B.34.01.01.01.04.06.01.01.04.06.0B.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x060B, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x04),
    0x3f01,
    AAF_REFERENCE_TYPE(StrongReferenceVector, FileDescriptor),
    true,
    false,
    MultipleDescriptor)
AAF_CLASS_END(MultipleDescriptor,
  // {0D010101-0101-4400-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.44.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4400,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  FileDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// AES3PCMDescriptor
//
AAF_CLASS(AES3PCMDescriptor,
  // {0D010101-0101-4700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.47.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PCMDescriptor,
  true)
  AAF_PROPERTY(Emphasis,
    // {040251-600-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.6.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d0d,
    AAF_TYPE(EmphasisType),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(BlockStartOffset,
    // {040232-300-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.3.2.3.00.00.00
    AAF_LITERAL_AUID(0x040232,
      0x300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d0f,
    AAF_TYPE(UInt16),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(AuxBitsMode,
    // {040251-100-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.1.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d08,
    AAF_TYPE(AuxBitsModeType),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(ChannelStatusMode,
    // {040251-200-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.2.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d10,
    AAF_TYPE(ChannelStatusModeType),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(FixedChannelStatusData,
    // {040251-300-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.3.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d11,
    AAF_TYPE(UInt8Array),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(UserDataMode,
    // {040251-400-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.4.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d12,
    AAF_TYPE(UserDataModeType),
    false,
    false,
    AES3PCMDescriptor)
  AAF_PROPERTY(FixedUserData,
    // {040251-500-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.5.1.5.00.00.00
    AAF_LITERAL_AUID(0x040251,
      0x500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d13,
    AAF_TYPE(UInt8Array),
    false,
    false,
    AES3PCMDescriptor)
AAF_CLASS_END(AES3PCMDescriptor,
  // {0D010101-0101-4700-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.47.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4700,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PCMDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// PCMDescriptor
//
AAF_CLASS(PCMDescriptor,
  // {0D010101-0101-4800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.48.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SoundDescriptor,
  true)
  AAF_PROPERTY(BlockAlign,
    // {04020302-0100-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.03.02.01.00.00.00
    AAF_LITERAL_AUID(0x04020302,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d0a,
    AAF_TYPE(UInt16),
    true,
    false,
    PCMDescriptor)
  AAF_PROPERTY(SequenceOffset,
    // {04020302-0200-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.03.02.02.00.00.00
    AAF_LITERAL_AUID(0x04020302,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d0b,
    AAF_TYPE(UInt8),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(AverageBPS,
    // {04020303-0500-0000-060E-2B3401010105}
    // 06.0E.2B.34.01.01.01.05.04.02.03.03.05.00.00.00
    AAF_LITERAL_AUID(0x04020303,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x05),
    0x3d09,
    AAF_TYPE(UInt32),
    true,
    false,
    PCMDescriptor)
  AAF_PROPERTY(ChannelAssignment,
    // {04020101-0500-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.04.02.01.01.05.00.00.00
    AAF_LITERAL_AUID(0x04020101,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x3d32,
    AAF_TYPE(AUID),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakEnvelopeVersion,
    // {04020301-0600-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.06.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d29,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakEnvelopeFormat,
    // {04020301-0700-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.07.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2a,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PointsPerPeakValue,
    // {04020301-0800-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.08.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2b,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakEnvelopeBlockSize,
    // {04020301-0900-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.09.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0900, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2c,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakChannels,
    // {04020301-0A00-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.0A.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2d,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakFrames,
    // {04020301-0B00-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.0B.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0B00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2e,
    AAF_TYPE(UInt32),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakOfPeaksPosition,
    // {04020301-0C00-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.0C.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0C00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d2f,
    AAF_TYPE(PositionType),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakEnvelopeTimestamp,
    // {04020301-0D00-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.0D.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0D00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d30,
    AAF_TYPE(TimeStamp),
    false,
    false,
    PCMDescriptor)
  AAF_PROPERTY(PeakEnvelopeData,
    // {04020301-0E00-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.02.03.01.0E.00.00.00
    AAF_LITERAL_AUID(0x04020301,
      0x0E00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x3d31,
    AAF_TYPE(Stream),
    false,
    false,
    PCMDescriptor)
AAF_CLASS_END(PCMDescriptor,
  // {0D010101-0101-4800-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.48.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4800,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  SoundDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// PhysicalDescriptor
//
AAF_CLASS(PhysicalDescriptor,
  // {0D010101-0101-4900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.49.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  false)
AAF_CLASS_END(PhysicalDescriptor,
  // {0D010101-0101-4900-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.49.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4900,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  EssenceDescriptor,
  false)
AAF_CLASS_SEPARATOR()

// ImportDescriptor
//
AAF_CLASS(ImportDescriptor,
  // {0D010101-0101-4A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
AAF_CLASS_END(ImportDescriptor,
  // {0D010101-0101-4A00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4A.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4A00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// RecordingDescriptor
//
AAF_CLASS(RecordingDescriptor,
  // {0D010101-0101-4B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
AAF_CLASS_END(RecordingDescriptor,
  // {0D010101-0101-4B00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4B.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4B00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// TaggedValueDefinition
//
AAF_CLASS(TaggedValueDefinition,
  // {0D010101-0101-4C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_END(TaggedValueDefinition,
  // {0D010101-0101-4C00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4C.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4C00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// KLVDataDefinition
//
AAF_CLASS(KLVDataDefinition,
  // {0D010101-0101-4D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
  AAF_PROPERTY(KLVDataType,
    // {06010104-0109-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.06.01.01.04.01.09.00.00
    AAF_LITERAL_AUID(0x06010104,
      0x0109, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4d12,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    false,
    false,
    KLVDataDefinition)
AAF_CLASS_END(KLVDataDefinition,
  // {0D010101-0101-4D00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4D.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4D00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  DefinitionObject,
  true)
AAF_CLASS_SEPARATOR()

// AuxiliaryDescriptor
//
AAF_CLASS(AuxiliaryDescriptor,
  // {0D010101-0101-4E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
  AAF_PROPERTY(MimeType,
    // {0409021-0000-0000-060E-2B3401010107}
    // 06.0E.2B.34.01.01.01.07.04.09.02.1.00.00.00.00
    AAF_LITERAL_AUID(0x0409021,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x07),
    0x4e11,
    AAF_TYPE(String),
    true,
    false,
    AuxiliaryDescriptor)
  AAF_PROPERTY(CharSet,
    // {0409030-0000-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.09.03.0.00.00.00.00
    AAF_LITERAL_AUID(0x0409030,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x4e12,
    AAF_TYPE(String),
    false,
    false,
    AuxiliaryDescriptor)
AAF_CLASS_END(AuxiliaryDescriptor,
  // {0D010101-0101-4E00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4E.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4E00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  PhysicalDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// RIFFChunk
//
AAF_CLASS(RIFFChunk,
  // {0D010101-0101-4F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
  AAF_PROPERTY(ChunkID,
    // {04060802-0000-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.06.08.02.00.00.00.00
    AAF_LITERAL_AUID(0x04060802,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x4f01,
    AAF_TYPE(UInt32),
    true,
    false,
    RIFFChunk)
  AAF_PROPERTY(ChunkLength,
    // {04060903-0000-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.06.09.03.00.00.00.00
    AAF_LITERAL_AUID(0x04060903,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x4f02,
    AAF_TYPE(UInt32),
    true,
    false,
    RIFFChunk)
  AAF_PROPERTY(ChunkData,
    // {04070400-0000-0000-060E-2B3401010108}
    // 06.0E.2B.34.01.01.01.08.04.07.04.00.00.00.00.00
    AAF_LITERAL_AUID(0x04070400,
      0x0000, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x08),
    0x4f03,
    AAF_TYPE(Stream),
    true,
    false,
    RIFFChunk)
AAF_CLASS_END(RIFFChunk,
  // {0D010101-0101-4F00-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.4F.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x4F00,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  true)
AAF_CLASS_SEPARATOR()

// BWFImportDescriptor
//
AAF_CLASS(BWFImportDescriptor,
  // {0D010101-0101-5000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.50.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x5000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  ImportDescriptor,
  true)
  AAF_PROPERTY(FileSecurityReport,
    // {04232-500-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.2.3.2.5.00.00.00
    AAF_LITERAL_AUID(0x04232,
      0x500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d15,
    AAF_TYPE(UInt32),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(FileSecurityWave,
    // {04232-600-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.2.3.2.6.00.00.00
    AAF_LITERAL_AUID(0x04232,
      0x600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d16,
    AAF_TYPE(UInt32),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(BextCodingHistory,
    // {04252-11-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.2.5.2.1.1.00.00
    AAF_LITERAL_AUID(0x04252,
      0x11, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d21,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyBasicData,
    // {4252-21-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.2.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x21, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d22,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyStartOfModulation,
    // {4252-31-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.3.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x31, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d23,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyQualityEvent,
    // {4252-41-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.4.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x41, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d24,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyEndOfModulation,
    // {4252-51-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.5.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x51, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d25,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyQualityParameter,
    // {4252-61-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.6.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x61, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d26,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyOperatorComment,
    // {4252-71-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.7.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x71, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d27,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(QltyCueSheet,
    // {4252-81-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.4.2.5.2.8.1.00.00
    AAF_LITERAL_AUID(0x4252,
      0x81, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0x3d28,
    AAF_TYPE(String),
    false,
    false,
    BWFImportDescriptor)
  AAF_PROPERTY(UnknownBWFChunks,
    // {6114-60F-0000-060E-2B340101018}
    // 06.0E.2B.34.01.01.01.8.6.1.1.4.6.0F.00.00
    AAF_LITERAL_AUID(0x6114,
      0x60F, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x8),
    0x3d33,
    AAF_REFERENCE_TYPE(StrongReferenceVector, RIFFChunk),
    false,
    false,
    BWFImportDescriptor)
AAF_CLASS_END(BWFImportDescriptor,
  // {0D010101-0101-5000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.50.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x5000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  ImportDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// MPEGVideoDescriptor
//
AAF_CLASS(MPEGVideoDescriptor,
  // {0D010101-0101-5100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.51.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x5100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  CDCIDescriptor,
  true)
  AAF_PROPERTY(SingleSequence,
    // {04162-12-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.2.00.00
    AAF_LITERAL_AUID(0x04162,
      0x12, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff01,
    AAF_TYPE(Boolean),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(ConstantBPictureCount,
    // {04162-13-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.3.00.00
    AAF_LITERAL_AUID(0x04162,
      0x13, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff02,
    AAF_TYPE(Boolean),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(CodedContentScanning,
    // {04162-14-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.4.00.00
    AAF_LITERAL_AUID(0x04162,
      0x14, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff03,
    AAF_TYPE(ContentScanningType),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(LowDelay,
    // {04162-15-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.5.00.00
    AAF_LITERAL_AUID(0x04162,
      0x15, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff04,
    AAF_TYPE(Boolean),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(ClosedGOP,
    // {04162-16-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.6.00.00
    AAF_LITERAL_AUID(0x04162,
      0x16, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff05,
    AAF_TYPE(Boolean),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(IdenticalGOP,
    // {04162-17-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.7.00.00
    AAF_LITERAL_AUID(0x04162,
      0x17, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff06,
    AAF_TYPE(Boolean),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(MaxGOP,
    // {04162-18-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.8.00.00
    AAF_LITERAL_AUID(0x04162,
      0x18, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff07,
    AAF_TYPE(UInt16),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(MaxBPictureCount,
    // {04162-19-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.9.00.00
    AAF_LITERAL_AUID(0x04162,
      0x19, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff08,
    AAF_TYPE(UInt16),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(BitRate,
    // {04162-10B-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.0B.00.00
    AAF_LITERAL_AUID(0x04162,
      0x10B, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff09,
    AAF_TYPE(UInt32),
    false,
    false,
    MPEGVideoDescriptor)
  AAF_PROPERTY(ProfileAndLevel,
    // {04162-10A-0000-060E-2B340101015}
    // 06.0E.2B.34.01.01.01.5.04.1.6.2.1.0A.00.00
    AAF_LITERAL_AUID(0x04162,
      0x10A, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x5),
    0xff10,
    AAF_TYPE(UInt8),
    false,
    false,
    MPEGVideoDescriptor)
AAF_CLASS_END(MPEGVideoDescriptor,
  // {0D010101-0101-5100-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.01.01.51.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0101, 0x5100,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  CDCIDescriptor,
  true)
AAF_CLASS_SEPARATOR()

// ClassDefinition
//
AAF_CLASS(ClassDefinition,
  // {0D010101-0201-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.01.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0201, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  true)
  AAF_PROPERTY(ParentClass,
    // {06010107-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.01.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0008,
    AAF_REFERENCE_TYPE(WeakReference, ClassDefinition),
    true,
    false,
    ClassDefinition)
  AAF_PROPERTY(Properties,
    // {06010107-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.02.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0009,
    AAF_REFERENCE_TYPE(StrongReferenceSet, PropertyDefinition),
    false,
    false,
    ClassDefinition)
  AAF_PROPERTY(IsConcrete,
    // {06010107-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.03.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000a,
    AAF_TYPE(Boolean),
    true,
    false,
    ClassDefinition)
AAF_CLASS_END(ClassDefinition,
  // {0D010101-0201-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.01.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0201, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  true)
AAF_CLASS_SEPARATOR()

// PropertyDefinition
//
AAF_CLASS(PropertyDefinition,
  // {0D010101-0202-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.02.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0202, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  true)
  AAF_PROPERTY(Type,
    // {06010107-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.04.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000b,
    AAF_TYPE(AUID),
    true,
    false,
    PropertyDefinition)
  AAF_PROPERTY(IsOptional,
    // {03010202-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.02.01.00.00.00
    AAF_LITERAL_AUID(0x03010202,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000c,
    AAF_TYPE(Boolean),
    true,
    false,
    PropertyDefinition)
  AAF_PROPERTY(LocalIdentification,
    // {06010107-0500-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.05.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000d,
    AAF_TYPE(UInt16),
    true,
    false,
    PropertyDefinition)
  AAF_PROPERTY(IsUniqueIdentifier,
    // {06010107-0600-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.06.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000e,
    AAF_TYPE(Boolean),
    false,
    false,
    PropertyDefinition)
AAF_CLASS_END(PropertyDefinition,
  // {0D010101-0202-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.02.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0202, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinition
//
AAF_CLASS(TypeDefinition,
  // {0D010101-0203-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.03.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0203, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  false)
AAF_CLASS_END(TypeDefinition,
  // {0D010101-0203-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.03.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0203, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  MetaDefinition,
  false)
AAF_CLASS_SEPARATOR()

// TypeDefinitionInteger
//
AAF_CLASS(TypeDefinitionInteger,
  // {0D010101-0204-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.04.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0204, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(Size,
    // {03010203-0100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.01.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x000f,
    AAF_TYPE(UInt8),
    true,
    false,
    TypeDefinitionInteger)
  AAF_PROPERTY(IsSigned,
    // {03010203-0200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.02.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0010,
    AAF_TYPE(Boolean),
    true,
    false,
    TypeDefinitionInteger)
AAF_CLASS_END(TypeDefinitionInteger,
  // {0D010101-0204-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.04.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0204, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionStrongObjectReference
//
AAF_CLASS(TypeDefinitionStrongObjectReference,
  // {0D010101-0205-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.05.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0205, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ReferencedType,
    // {06010107-0900-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.09.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0900, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0011,
    AAF_REFERENCE_TYPE(WeakReference, ClassDefinition),
    true,
    false,
    TypeDefinitionStrongObjectReference)
AAF_CLASS_END(TypeDefinitionStrongObjectReference,
  // {0D010101-0205-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.05.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0205, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionWeakObjectReference
//
AAF_CLASS(TypeDefinitionWeakObjectReference,
  // {0D010101-0206-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.06.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0206, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ReferencedType,
    // {06010107-0A00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0A.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0A00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0012,
    AAF_REFERENCE_TYPE(WeakReference, ClassDefinition),
    true,
    false,
    TypeDefinitionWeakObjectReference)
  AAF_PROPERTY(TargetSet,
    // {03010203-0B00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.0B.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0B00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0013,
    AAF_TYPE(AUIDArray),
    true,
    false,
    TypeDefinitionWeakObjectReference)
AAF_CLASS_END(TypeDefinitionWeakObjectReference,
  // {0D010101-0206-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.06.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0206, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionEnumeration
//
AAF_CLASS(TypeDefinitionEnumeration,
  // {0D010101-0207-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.07.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0207, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementType,
    // {06010107-0B00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0B.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0B00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0014,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionEnumeration)
  AAF_PROPERTY(ElementNames,
    // {03010203-0400-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.04.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0400, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0015,
    AAF_TYPE(StringArray),
    true,
    false,
    TypeDefinitionEnumeration)
  AAF_PROPERTY(ElementValues,
    // {03010203-0500-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.05.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0500, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0016,
    AAF_TYPE(Int64Array),
    true,
    false,
    TypeDefinitionEnumeration)
AAF_CLASS_END(TypeDefinitionEnumeration,
  // {0D010101-0207-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.07.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0207, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionFixedArray
//
AAF_CLASS(TypeDefinitionFixedArray,
  // {0D010101-0208-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.08.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0208, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementType,
    // {06010107-0C00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0C.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0C00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0017,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionFixedArray)
  AAF_PROPERTY(ElementCount,
    // {03010203-0300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.03.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0018,
    AAF_TYPE(UInt32),
    true,
    false,
    TypeDefinitionFixedArray)
AAF_CLASS_END(TypeDefinitionFixedArray,
  // {0D010101-0208-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.08.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0208, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionVariableArray
//
AAF_CLASS(TypeDefinitionVariableArray,
  // {0D010101-0209-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.09.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0209, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementType,
    // {06010107-0D00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0D.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0D00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0019,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionVariableArray)
AAF_CLASS_END(TypeDefinitionVariableArray,
  // {0D010101-0209-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.09.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0209, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionSet
//
AAF_CLASS(TypeDefinitionSet,
  // {0D010101-020A-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0A.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020A, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementType,
    // {06010107-0E00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0E.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0E00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001a,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionSet)
AAF_CLASS_END(TypeDefinitionSet,
  // {0D010101-020A-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0A.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020A, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionString
//
AAF_CLASS(TypeDefinitionString,
  // {0D010101-020B-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0B.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020B, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementType,
    // {06010107-0F00-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.0F.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0F00, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001b,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionString)
AAF_CLASS_END(TypeDefinitionString,
  // {0D010101-020B-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0B.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020B, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionStream
//
AAF_CLASS(TypeDefinitionStream,
  // {0D010101-020C-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0C.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020C, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_END(TypeDefinitionStream,
  // {0D010101-020C-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0C.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020C, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionRecord
//
AAF_CLASS(TypeDefinitionRecord,
  // {0D010101-020D-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0D.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020D, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(MemberTypes,
    // {06010107-1100-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.11.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x1100, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001c,
    AAF_REFERENCE_TYPE(WeakReferenceVector, TypeDefinition),
    true,
    false,
    TypeDefinitionRecord)
  AAF_PROPERTY(MemberNames,
    // {03010203-0600-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.06.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0600, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001d,
    AAF_TYPE(StringArray),
    true,
    false,
    TypeDefinitionRecord)
AAF_CLASS_END(TypeDefinitionRecord,
  // {0D010101-020D-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0D.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020D, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionRename
//
AAF_CLASS(TypeDefinitionRename,
  // {0D010101-020E-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0E.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020E, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(RenamedType,
    // {06010107-1200-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.12.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x1200, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001e,
    AAF_REFERENCE_TYPE(WeakReference, TypeDefinition),
    true,
    false,
    TypeDefinitionRename)
AAF_CLASS_END(TypeDefinitionRename,
  // {0D010101-020E-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.0E.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x020E, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionExtendibleEnumeration
//
AAF_CLASS(TypeDefinitionExtendibleEnumeration,
  // {0D010101-0220-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.20.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0220, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
  AAF_PROPERTY(ElementNames,
    // {03010203-0700-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.07.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x001f,
    AAF_TYPE(StringArray),
    true,
    false,
    TypeDefinitionExtendibleEnumeration)
  AAF_PROPERTY(ElementValues,
    // {03010203-0800-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.01.02.03.08.00.00.00
    AAF_LITERAL_AUID(0x03010203,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0020,
    AAF_TYPE(AUIDArray),
    true,
    false,
    TypeDefinitionExtendibleEnumeration)
AAF_CLASS_END(TypeDefinitionExtendibleEnumeration,
  // {0D010101-0220-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.20.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0220, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionIndirect
//
AAF_CLASS(TypeDefinitionIndirect,
  // {0D010101-0221-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.21.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0221, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_END(TypeDefinitionIndirect,
  // {0D010101-0221-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.21.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0221, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionOpaque
//
AAF_CLASS(TypeDefinitionOpaque,
  // {0D010101-0222-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.22.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0222, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinitionIndirect,
  true)
AAF_CLASS_END(TypeDefinitionOpaque,
  // {0D010101-0222-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.22.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0222, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinitionIndirect,
  true)
AAF_CLASS_SEPARATOR()

// TypeDefinitionCharacter
//
AAF_CLASS(TypeDefinitionCharacter,
  // {0D010101-0223-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.23.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0223, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_END(TypeDefinitionCharacter,
  // {0D010101-0223-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.23.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0223, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  TypeDefinition,
  true)
AAF_CLASS_SEPARATOR()

// MetaDefinition
//
AAF_CLASS(MetaDefinition,
  // {0D010101-0224-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.24.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0224, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  false)
  AAF_PROPERTY(Identification,
    // {06010107-1300-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.13.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x1300, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0005,
    AAF_TYPE(AUID),
    true,
    true,
    MetaDefinition)
  AAF_PROPERTY(Name,
    // {03020401-0201-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.03.02.04.01.02.01.00.00
    AAF_LITERAL_AUID(0x03020401,
      0x0201, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0006,
    AAF_TYPE(String),
    true,
    false,
    MetaDefinition)
  AAF_PROPERTY(Description,
    // {06010107-1401-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.14.01.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x1401, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0007,
    AAF_TYPE(String),
    false,
    false,
    MetaDefinition)
AAF_CLASS_END(MetaDefinition,
  // {0D010101-0224-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.24.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0224, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  false)
AAF_CLASS_SEPARATOR()

// MetaDictionary
//
AAF_CLASS(MetaDictionary,
  // {0D010101-0225-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.25.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0225, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  true)
  AAF_PROPERTY(ClassDefinitions,
    // {06010107-0700-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.07.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0700, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0003,
    AAF_REFERENCE_TYPE(StrongReferenceSet, ClassDefinition),
    false,
    false,
    MetaDictionary)
  AAF_PROPERTY(TypeDefinitions,
    // {06010107-0800-0000-060E-2B3401010102}
    // 06.0E.2B.34.01.01.01.02.06.01.01.07.08.00.00.00
    AAF_LITERAL_AUID(0x06010107,
      0x0800, 0x0000,
      0x06, 0x0E, 0x2B, 0x34, 0x01, 0x01, 0x01, 0x02),
    0x0004,
    AAF_REFERENCE_TYPE(StrongReferenceSet, TypeDefinition),
    false,
    false,
    MetaDictionary)
AAF_CLASS_END(MetaDictionary,
  // {0D010101-0225-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.01.01.02.25.00.00
  AAF_LITERAL_AUID(0x0D010101,
    0x0225, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  Root,
  true)
AAF_CLASS_SEPARATOR()

// DescriptiveObject
//
AAF_CLASS(DescriptiveObject,
  // {0D01040-0000-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.04.0.00.00.00.00
  AAF_LITERAL_AUID(0x0D01040,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_END(DescriptiveObject,
  // {0D01040-0000-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.04.0.00.00.00.00
  AAF_LITERAL_AUID(0x0D01040,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_SEPARATOR()

// DescriptiveFramework
//
AAF_CLASS(DescriptiveFramework,
  // {0D010401-0000-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.04.01.00.00.00.00
  AAF_LITERAL_AUID(0x0D010401,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)
AAF_CLASS_END(DescriptiveFramework,
  // {0D010401-0000-0000-060E-2B3402060101}
  // 06.0E.2B.34.02.53.01.01.0D.01.04.01.00.00.00.00
  AAF_LITERAL_AUID(0x0D010401,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x02, 0x06, 0x01, 0x01),
  InterchangeObject,
  false)

AAF_TABLE_END()

// Types
//

AAF_TYPE_TABLE_BEGIN()

// UInt8
//
AAF_TYPE_DEFINITION_INTEGER(UInt8, 
  // {01010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 1, False)
AAF_TYPE_SEPARATOR()

// UInt16
//
AAF_TYPE_DEFINITION_INTEGER(UInt16, 
  // {01010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 2, False)
AAF_TYPE_SEPARATOR()

// UInt32
//
AAF_TYPE_DEFINITION_INTEGER(UInt32, 
  // {01010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 4, False)
AAF_TYPE_SEPARATOR()

// UInt64
//
AAF_TYPE_DEFINITION_INTEGER(UInt64, 
  // {01010400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 8, False)
AAF_TYPE_SEPARATOR()

// Int8
//
AAF_TYPE_DEFINITION_INTEGER(Int8, 
  // {01010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 1, True)
AAF_TYPE_SEPARATOR()

// Int16
//
AAF_TYPE_DEFINITION_INTEGER(Int16, 
  // {01010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 2, True)
AAF_TYPE_SEPARATOR()

// Int32
//
AAF_TYPE_DEFINITION_INTEGER(Int32, 
  // {01010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 4, True)
AAF_TYPE_SEPARATOR()

// Int64
//
AAF_TYPE_DEFINITION_INTEGER(Int64, 
  // {01010800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x01010800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), 8, True)
AAF_TYPE_SEPARATOR()

// PositionType
//
AAF_TYPE_DEFINITION_RENAME(PositionType, 
  // {01012001-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.20.01.00.00.00.00
  AAF_LITERAL_AUID(0x01012001,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), Int64)
AAF_TYPE_SEPARATOR()

// LengthType
//
AAF_TYPE_DEFINITION_RENAME(LengthType, 
  // {01012002-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.20.02.00.00.00.00
  AAF_LITERAL_AUID(0x01012002,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), Int64)
AAF_TYPE_SEPARATOR()

// JPEGTableIDType
//
AAF_TYPE_DEFINITION_RENAME(JPEGTableIDType, 
  // {01012003-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.20.03.00.00.00.00
  AAF_LITERAL_AUID(0x01012003,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), Int32)
AAF_TYPE_SEPARATOR()

// PhaseFrameType
//
AAF_TYPE_DEFINITION_RENAME(PhaseFrameType, 
  // {01012300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.01.23.00.00.00.00.00
  AAF_LITERAL_AUID(0x01012300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), Int32)
AAF_TYPE_SEPARATOR()

// AUID
//
AAF_TYPE_DEFINITION_RECORD(AUID, 
  // {0103100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.03.1.00.00.00.00.00
  AAF_LITERAL_AUID(0x0103100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(Data1, AAF_TYPE(UInt32),
    AUID)
  AAF_TYPE_DEFINITION_RECORD_FIELD(Data2, AAF_TYPE(UInt16),
    AUID)
  AAF_TYPE_DEFINITION_RECORD_FIELD(Data3, AAF_TYPE(UInt16),
    AUID)
  AAF_TYPE_DEFINITION_RECORD_FIELD(Data4, AAF_TYPE(UInt8Array8),
    AUID)
AAF_TYPE_DEFINITION_RECORD_END(AUID, 
  // {0103100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.03.1.00.00.00.00.00
  AAF_LITERAL_AUID(0x0103100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// MobIDType
//
AAF_TYPE_DEFINITION_RECORD(MobIDType, 
  // {01030200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.03.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x01030200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(SMPTELabel, AAF_TYPE(UInt8Array12),
    MobIDType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(length, AAF_TYPE(UInt8),
    MobIDType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(instanceHigh, AAF_TYPE(UInt8),
    MobIDType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(instanceMid, AAF_TYPE(UInt8),
    MobIDType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(instanceLow, AAF_TYPE(UInt8),
    MobIDType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(material, AAF_TYPE(AUID),
    MobIDType)
AAF_TYPE_DEFINITION_RECORD_END(MobIDType, 
  // {01030200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.03.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x01030200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// Boolean
//
AAF_TYPE_DEFINITION_ENUMERATION(Boolean, 
  // {01040100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.04.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x01040100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(False,
    0, Boolean)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(True,
    1, Boolean)
AAF_TYPE_DEFINITION_ENUMERATION_END(Boolean, 
  // {01040100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.04.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x01040100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// Character
//
AAF_TYPE_DEFINITION_CHARACTER(Character, 
  // {01100100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.10.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x01100100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// String
//
AAF_TYPE_DEFINITION_STRING(String, 
  // {01100200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.01.10.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x01100200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), Character)
AAF_TYPE_SEPARATOR()

// ProductReleaseType
//
AAF_TYPE_DEFINITION_ENUMERATION(ProductReleaseType, 
  // {02010101-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.01.00.00.00.00
  AAF_LITERAL_AUID(0x02010101,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionUnknown,
    0, ProductReleaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionReleased,
    1, ProductReleaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionDebug,
    2, ProductReleaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionPatched,
    3, ProductReleaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionBeta,
    4, ProductReleaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VersionPrivateBuild,
    5, ProductReleaseType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ProductReleaseType, 
  // {02010101-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.01.00.00.00.00
  AAF_LITERAL_AUID(0x02010101,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// TapeFormatType
//
AAF_TYPE_DEFINITION_ENUMERATION(TapeFormatType, 
  // {02010102-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.02.00.00.00.00
  AAF_LITERAL_AUID(0x02010102,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TapeFormatNull,
    0, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(BetacamFormat,
    1, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(BetacamSPFormat,
    2, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VHSFormat,
    3, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SVHSFormat,
    4, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(8mmFormat,
    5, TapeFormatType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Hi8Format,
    6, TapeFormatType)
AAF_TYPE_DEFINITION_ENUMERATION_END(TapeFormatType, 
  // {02010102-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.02.00.00.00.00
  AAF_LITERAL_AUID(0x02010102,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// VideoSignalType
//
AAF_TYPE_DEFINITION_ENUMERATION(VideoSignalType, 
  // {02010103-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.03.00.00.00.00
  AAF_LITERAL_AUID(0x02010103,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VideoSignalNull,
    0, VideoSignalType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(NTSCSignal,
    1, VideoSignalType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(PALSignal,
    2, VideoSignalType)
AAF_TYPE_DEFINITION_ENUMERATION_END(VideoSignalType, 
  // {02010103-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.03.00.00.00.00
  AAF_LITERAL_AUID(0x02010103,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// TapeCaseType
//
AAF_TYPE_DEFINITION_ENUMERATION(TapeCaseType, 
  // {02010104-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.04.00.00.00.00
  AAF_LITERAL_AUID(0x02010104,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TapeCaseNull,
    0, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ThreeFourthInchVideoTape,
    1, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VHSVideoTape,
    2, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(8mmVideoTape,
    3, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(BetacamVideoTape,
    4, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompactCassette,
    5, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(DATCartridge,
    6, TapeCaseType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(NagraAudioTape,
    7, TapeCaseType)
AAF_TYPE_DEFINITION_ENUMERATION_END(TapeCaseType, 
  // {02010104-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.04.00.00.00.00
  AAF_LITERAL_AUID(0x02010104,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ColorSitingType
//
AAF_TYPE_DEFINITION_ENUMERATION(ColorSitingType, 
  // {02010105-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.05.00.00.00.00
  AAF_LITERAL_AUID(0x02010105,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CoSiting,
    0, ColorSitingType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Averaging,
    1, ColorSitingType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ThreeTap,
    2, ColorSitingType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Quincunx,
    3, ColorSitingType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Rec601,
    4, ColorSitingType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UnknownSiting,
    255, ColorSitingType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ColorSitingType, 
  // {02010105-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.05.00.00.00.00
  AAF_LITERAL_AUID(0x02010105,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// EditHintType
//
AAF_TYPE_DEFINITION_ENUMERATION(EditHintType, 
  // {02010106-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.06.00.00.00.00
  AAF_LITERAL_AUID(0x02010106,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(NoEditHint,
    0, EditHintType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Proportional,
    1, EditHintType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RelativeLeft,
    2, EditHintType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RelativeRight,
    3, EditHintType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RelativeFixed,
    4, EditHintType)
AAF_TYPE_DEFINITION_ENUMERATION_END(EditHintType, 
  // {02010106-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.06.00.00.00.00
  AAF_LITERAL_AUID(0x02010106,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// FadeType
//
AAF_TYPE_DEFINITION_ENUMERATION(FadeType, 
  // {02010107-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.07.00.00.00.00
  AAF_LITERAL_AUID(0x02010107,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FadeNone,
    0, FadeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FadeLinearAmp,
    1, FadeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FadeLinearPower,
    2, FadeType)
AAF_TYPE_DEFINITION_ENUMERATION_END(FadeType, 
  // {02010107-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.07.00.00.00.00
  AAF_LITERAL_AUID(0x02010107,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// LayoutType
//
AAF_TYPE_DEFINITION_ENUMERATION(LayoutType, 
  // {02010108-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.08.00.00.00.00
  AAF_LITERAL_AUID(0x02010108,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FullFrame,
    0, LayoutType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SeparateFields,
    1, LayoutType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(OneField,
    2, LayoutType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(MixedFields,
    3, LayoutType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SegmentedFrame,
    4, LayoutType)
AAF_TYPE_DEFINITION_ENUMERATION_END(LayoutType, 
  // {02010108-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.08.00.00.00.00
  AAF_LITERAL_AUID(0x02010108,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// TCSource
//
AAF_TYPE_DEFINITION_ENUMERATION(TCSource, 
  // {02010109-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.09.00.00.00.00
  AAF_LITERAL_AUID(0x02010109,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TimecodeLTC,
    0, TCSource)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TimecodeVITC,
    1, TCSource)
AAF_TYPE_DEFINITION_ENUMERATION_END(TCSource, 
  // {02010109-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.09.00.00.00.00
  AAF_LITERAL_AUID(0x02010109,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// PulldownDirectionType
//
AAF_TYPE_DEFINITION_ENUMERATION(PulldownDirectionType, 
  // {0201010A-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0A.00.00.00.00
  AAF_LITERAL_AUID(0x0201010A,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TapeToFilmSpeed,
    0, PulldownDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FilmToTapeSpeed,
    1, PulldownDirectionType)
AAF_TYPE_DEFINITION_ENUMERATION_END(PulldownDirectionType, 
  // {0201010A-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0A.00.00.00.00
  AAF_LITERAL_AUID(0x0201010A,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// PulldownKindType
//
AAF_TYPE_DEFINITION_ENUMERATION(PulldownKindType, 
  // {0201010B-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0B.00.00.00.00
  AAF_LITERAL_AUID(0x0201010B,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TwoThreePD,
    0, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(PALPD,
    1, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(OneToOneNTSC,
    2, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(OneToOnePAL,
    3, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(VideoTapNTSC,
    4, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(OneToOneHDSixty,
    5, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TwentyFourToSixtyPD,
    6, PulldownKindType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(TwoToOnePD,
    7, PulldownKindType)
AAF_TYPE_DEFINITION_ENUMERATION_END(PulldownKindType, 
  // {0201010B-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0B.00.00.00.00
  AAF_LITERAL_AUID(0x0201010B,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// EdgeType
//
AAF_TYPE_DEFINITION_ENUMERATION(EdgeType, 
  // {0201010C-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0C.00.00.00.00
  AAF_LITERAL_AUID(0x0201010C,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(EtNull,
    0, EdgeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(EtKeycode,
    1, EdgeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(EtEdgenum4,
    2, EdgeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(EtEdgenum5,
    3, EdgeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(EtHeaderSize,
    8, EdgeType)
AAF_TYPE_DEFINITION_ENUMERATION_END(EdgeType, 
  // {0201010C-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0C.00.00.00.00
  AAF_LITERAL_AUID(0x0201010C,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// FilmType
//
AAF_TYPE_DEFINITION_ENUMERATION(FilmType, 
  // {0201010D-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0D.00.00.00.00
  AAF_LITERAL_AUID(0x0201010D,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FtNull,
    0, FilmType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Ft35MM,
    1, FilmType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Ft16MM,
    2, FilmType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Ft8MM,
    3, FilmType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Ft65MM,
    4, FilmType)
AAF_TYPE_DEFINITION_ENUMERATION_END(FilmType, 
  // {0201010D-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0D.00.00.00.00
  AAF_LITERAL_AUID(0x0201010D,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// RGBAComponentKind
//
AAF_TYPE_DEFINITION_ENUMERATION(RGBAComponentKind, 
  // {0201010E-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0E.00.00.00.00
  AAF_LITERAL_AUID(0x0201010E,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompNone,
    0x30, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompAlpha,
    0x41, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompBlue,
    0x42, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompFill,
    0x46, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompGreen,
    0x47, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompPalette,
    0x50, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompRed,
    0x52, RGBAComponentKind)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(CompNull,
    0x00, RGBAComponentKind)
AAF_TYPE_DEFINITION_ENUMERATION_END(RGBAComponentKind, 
  // {0201010E-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0E.00.00.00.00
  AAF_LITERAL_AUID(0x0201010E,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ReferenceType
//
AAF_TYPE_DEFINITION_ENUMERATION(ReferenceType, 
  // {0201010F-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0F.00.00.00.00
  AAF_LITERAL_AUID(0x0201010F,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RefLimitMinimum,
    0, ReferenceType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RefLimitMaximum,
    1, ReferenceType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RefMinimum,
    2, ReferenceType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RefMaximum,
    3, ReferenceType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(RefEnumvalue,
    4, ReferenceType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ReferenceType, 
  // {0201010F-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.0F.00.00.00.00
  AAF_LITERAL_AUID(0x0201010F,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// AlphaTransparencyType
//
AAF_TYPE_DEFINITION_ENUMERATION(AlphaTransparencyType, 
  // {02010120-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.20.00.00.00.00
  AAF_LITERAL_AUID(0x02010120,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(MinValueTransparent,
    0, AlphaTransparencyType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(MaxValueTransparent,
    1, AlphaTransparencyType)
AAF_TYPE_DEFINITION_ENUMERATION_END(AlphaTransparencyType, 
  // {02010120-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.20.00.00.00.00
  AAF_LITERAL_AUID(0x02010120,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// FieldNumber
//
AAF_TYPE_DEFINITION_ENUMERATION(FieldNumber, 
  // {02010121-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.21.00.00.00.00
  AAF_LITERAL_AUID(0x02010121,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UnspecifiedField,
    0, FieldNumber)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FieldOne,
    1, FieldNumber)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(FieldTwo,
    2, FieldNumber)
AAF_TYPE_DEFINITION_ENUMERATION_END(FieldNumber, 
  // {02010121-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.21.00.00.00.00
  AAF_LITERAL_AUID(0x02010121,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ElectroSpatialFormulation
//
AAF_TYPE_DEFINITION_ENUMERATION(ElectroSpatialFormulation, 
  // {02010122-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.22.00.00.00.00
  AAF_LITERAL_AUID(0x02010122,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_Default,
    0, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_TwoChannelMode,
    1, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_SingleChannelMode,
    2, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_PrimarySecondaryMode,
    3, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_StereophonicMode,
    4, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_SingleChannelDoubleSamplingFrequencyMode,
    7, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_StereoLeftChannelDoubleSamplingFrequencyMode,
    8, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_StereoRightChannelDoubleSamplingFrequencyMode,
    9, ElectroSpatialFormulation)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ElectroSpatialFormulation_MultiChannelMode,
    15, ElectroSpatialFormulation)
AAF_TYPE_DEFINITION_ENUMERATION_END(ElectroSpatialFormulation, 
  // {02010122-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.01.01.22.00.00.00.00
  AAF_LITERAL_AUID(0x02010122,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// EmphasisType
//
AAF_TYPE_DEFINITION_ENUMERATION(EmphasisType, 
  // {02010123-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.23.00.00.00.00
  AAF_LITERAL_AUID(0x02010123,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_Unknown,
    0, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_Reserved0,
    1, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_Reserved1,
    2, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_Reserved2,
    3, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_None,
    4, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_Reserved3,
    5, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_15and50,
    6, EmphasisType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(Emphasis_ITU,
    7, EmphasisType)
AAF_TYPE_DEFINITION_ENUMERATION_END(EmphasisType, 
  // {02010123-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.23.00.00.00.00
  AAF_LITERAL_AUID(0x02010123,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// AuxBitsModeType
//
AAF_TYPE_DEFINITION_ENUMERATION(AuxBitsModeType, 
  // {02010124-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.24.00.00.00.00
  AAF_LITERAL_AUID(0x02010124,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_NotDefined,
    0, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_MainAudioSampleData,
    1, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_SingleCoordinationSignal,
    2, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_UserDefined,
    3, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_Reserved0,
    4, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_Reserved1,
    5, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_Reserved2,
    6, AuxBitsModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(AuxBitsMode_Reserved3,
    7, AuxBitsModeType)
AAF_TYPE_DEFINITION_ENUMERATION_END(AuxBitsModeType, 
  // {02010124-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.24.00.00.00.00
  AAF_LITERAL_AUID(0x02010124,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ChannelStatusModeType
//
AAF_TYPE_DEFINITION_ENUMERATION(ChannelStatusModeType, 
  // {02010125-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.25.00.00.00.00
  AAF_LITERAL_AUID(0x02010125,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_None,
    0, ChannelStatusModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_Minimum,
    1, ChannelStatusModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_Standard,
    2, ChannelStatusModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_Fixed,
    3, ChannelStatusModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_Stream,
    4, ChannelStatusModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ChannelStatusMode_Essence,
    5, ChannelStatusModeType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ChannelStatusModeType, 
  // {02010125-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.25.00.00.00.00
  AAF_LITERAL_AUID(0x02010125,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// UserDataModeType
//
AAF_TYPE_DEFINITION_ENUMERATION(UserDataModeType, 
  // {02010126-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.26.00.00.00.00
  AAF_LITERAL_AUID(0x02010126,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_NotDefined,
    0, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_192BitBlockStructure,
    1, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_AES18,
    2, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_UserDefined,
    3, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_IEC,
    4, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Metadata,
    5, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved0,
    6, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved1,
    7, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved2,
    8, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved3,
    9, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved4,
    10, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved5,
    11, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved6,
    12, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved7,
    13, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved8,
    14, UserDataModeType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(UserDataMode_Reserved9,
    15, UserDataModeType)
AAF_TYPE_DEFINITION_ENUMERATION_END(UserDataModeType, 
  // {02010126-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.26.00.00.00.00
  AAF_LITERAL_AUID(0x02010126,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// SignalStandardType
//
AAF_TYPE_DEFINITION_ENUMERATION(SignalStandardType, 
  // {02010127-0000-0000-60E-2B340104011}
  // 6.0E.2B.34.01.04.01.1.02.01.01.27.00.00.00.00
  AAF_LITERAL_AUID(0x02010127,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x1), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_None,
    0, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_ITU601,
    1, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_ITU1358,
    2, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_SMPTE347M,
    3, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_SMPTE274M,
    4, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_SMPTE296M,
    5, SignalStandardType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(SignalStandard_SMPTE349M,
    6, SignalStandardType)
AAF_TYPE_DEFINITION_ENUMERATION_END(SignalStandardType, 
  // {02010127-0000-0000-60E-2B340104011}
  // 6.0E.2B.34.01.04.01.1.02.01.01.27.00.00.00.00
  AAF_LITERAL_AUID(0x02010127,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x1), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ScanningDirectionType
//
AAF_TYPE_DEFINITION_ENUMERATION(ScanningDirectionType, 
  // {02010128-0000-0000-60E-2B340104011}
  // 6.0E.2B.34.01.04.01.1.02.01.01.28.00.00.00.00
  AAF_LITERAL_AUID(0x02010128,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x1), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_LeftToRightTopToBottom,
    0, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_RightToLeftTopToBottom,
    1, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_LeftToRightBottomToTop,
    2, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_RightToLeftBottomToTop,
    3, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_TopToBottomLeftToRight,
    4, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_TopToBottomRightToLeft,
    5, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_BottomToTopLeftToRight,
    6, ScanningDirectionType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ScanningDirection_BottomToTopRightToLeft,
    7, ScanningDirectionType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ScanningDirectionType, 
  // {02010128-0000-0000-60E-2B340104011}
  // 6.0E.2B.34.01.04.01.1.02.01.01.28.00.00.00.00
  AAF_LITERAL_AUID(0x02010128,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x1), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// ContentScanningType
//
AAF_TYPE_DEFINITION_ENUMERATION(ContentScanningType, 
  // {0201012A-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.2A.00.00.00.00
  AAF_LITERAL_AUID(0x0201012A,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ContentScanning_NotKnown,
    0, ContentScanningType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ContentScanning_Progressive,
    1, ContentScanningType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ContentScanning_Interlace,
    2, ContentScanningType)
  AAF_TYPE_DEFINITION_ENUMERATION_MEMBER(ContentScanning_Mixed,
    3, ContentScanningType)
AAF_TYPE_DEFINITION_ENUMERATION_END(ContentScanningType, 
  // {0201012A-0000-0000-60E-2B3401040101}
  // 6.0E.2B.34.01.04.01.01.02.01.01.2A.00.00.00.00
  AAF_LITERAL_AUID(0x0201012A,
    0x0000, 0x0000,
    0x6, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01), AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// OperationCategoryType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(OperationCategoryType, 
  // {02020101-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.01.00.00.00.00
  AAF_LITERAL_AUID(0x02020101,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(OperationCategory_Effect,
    // {0D010102-0101-0100-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.01.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0100,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    OperationCategoryType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(OperationCategoryType, 
  // {02020101-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.01.00.00.00.00
  AAF_LITERAL_AUID(0x02020101,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// TransferCharacteristicType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(TransferCharacteristicType, 
  // {02020102-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.02.00.00.00.00
  AAF_LITERAL_AUID(0x02020102,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(TransferCharacteristic_ITU470_PAL,
    // {401011-0101-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.01.01.0.00
    AAF_LITERAL_AUID(0x401011,
      0x0101, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    TransferCharacteristicType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(TransferCharacteristic_ITU709,
    // {401011-0102-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.01.02.0.00
    AAF_LITERAL_AUID(0x401011,
      0x0102, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    TransferCharacteristicType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(TransferCharacteristic_SMPTE240M,
    // {401011-0103-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.01.03.0.00
    AAF_LITERAL_AUID(0x401011,
      0x0103, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    TransferCharacteristicType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(TransferCharacteristic_ITU1361,
    // {401011-0105-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.01.05.0.00
    AAF_LITERAL_AUID(0x401011,
      0x0105, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    TransferCharacteristicType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(TransferCharacteristic_linear,
    // {401011-0106-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.01.06.0.00
    AAF_LITERAL_AUID(0x401011,
      0x0106, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    TransferCharacteristicType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(TransferCharacteristicType, 
  // {02020102-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.02.00.00.00.00
  AAF_LITERAL_AUID(0x02020102,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// PluginCategoryType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(PluginCategoryType, 
  // {02020103-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.03.00.00.00.00
  AAF_LITERAL_AUID(0x02020103,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(PluginCategory_Effect,
    // {0D010102-0101-0200-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.02.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0200,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    PluginCategoryType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(PluginCategory_Codec,
    // {0D010102-0101-0300-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.03.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0300,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    PluginCategoryType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(PluginCategory_Interpolation,
    // {0D010102-0101-0400-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.04.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0400,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    PluginCategoryType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(PluginCategoryType, 
  // {02020103-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.03.00.00.00.00
  AAF_LITERAL_AUID(0x02020103,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// UsageType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(UsageType, 
  // {02020104-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.04.00.00.00.00
  AAF_LITERAL_AUID(0x02020104,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(Usage_SubClip,
    // {0D010102-0101-0500-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.05.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0500,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    UsageType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(Usage_AdjustedClip,
    // {0D010102-0101-0600-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.06.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0600,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    UsageType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(Usage_TopLevel,
    // {0D010102-0101-0700-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.07.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0700,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    UsageType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(Usage_LowerLevel,
    // {0D010102-0101-0800-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.08.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0800,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    UsageType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(Usage_Template,
    // {0D010102-0101-0900-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.0D.01.01.02.01.01.09.00
    AAF_LITERAL_AUID(0x0D010102,
      0x0101, 0x0900,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    UsageType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(UsageType, 
  // {02020104-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.04.00.00.00.00
  AAF_LITERAL_AUID(0x02020104,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// ColorPrimariesType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(ColorPrimariesType, 
  // {0202015-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.5.00.00.00.00
  AAF_LITERAL_AUID(0x0202015,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(ColorPrimaries_SMPTE170M,
    // {401011-31-000-060E-2B340401016}
    // 06.0E.2B.34.04.01.01.6.4.01.01.1.3.1.0.00
    AAF_LITERAL_AUID(0x401011,
      0x31, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x6),
    ColorPrimariesType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(ColorPrimaries_ITU470_PAL,
    // {401011-32-000-060E-2B340401016}
    // 06.0E.2B.34.04.01.01.6.4.01.01.1.3.2.0.00
    AAF_LITERAL_AUID(0x401011,
      0x32, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x6),
    ColorPrimariesType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(ColorPrimaries_ITU709,
    // {401011-33-000-060E-2B340401016}
    // 06.0E.2B.34.04.01.01.6.4.01.01.1.3.3.0.00
    AAF_LITERAL_AUID(0x401011,
      0x33, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x6),
    ColorPrimariesType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(ColorPrimariesType, 
  // {0202015-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.5.00.00.00.00
  AAF_LITERAL_AUID(0x0202015,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// CodingEquationsType
//
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION(CodingEquationsType, 
  // {0202016-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.6.00.00.00.00
  AAF_LITERAL_AUID(0x0202016,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(CodingEquations_ITU601,
    // {401011-21-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.2.1.0.00
    AAF_LITERAL_AUID(0x401011,
      0x21, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    CodingEquationsType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(CodingEquations_ITU709,
    // {401011-22-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.2.2.0.00
    AAF_LITERAL_AUID(0x401011,
      0x22, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    CodingEquationsType)
  AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER(CodingEquations_SMPTE240M,
    // {401011-23-000-060E-2B3404010101}
    // 06.0E.2B.34.04.01.01.01.4.01.01.1.2.3.0.00
    AAF_LITERAL_AUID(0x401011,
      0x23, 0x000,
      0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01),
    CodingEquationsType)
AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END(CodingEquationsType, 
  // {0202016-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.02.02.01.6.00.00.00.00
  AAF_LITERAL_AUID(0x0202016,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// Rational
//
AAF_TYPE_DEFINITION_RECORD(Rational, 
  // {03010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(Numerator, AAF_TYPE(Int32),
    Rational)
  AAF_TYPE_DEFINITION_RECORD_FIELD(Denominator, AAF_TYPE(Int32),
    Rational)
AAF_TYPE_DEFINITION_RECORD_END(Rational, 
  // {03010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// ProductVersion
//
AAF_TYPE_DEFINITION_RECORD(ProductVersion, 
  // {03010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(major, AAF_TYPE(UInt16),
    ProductVersion)
  AAF_TYPE_DEFINITION_RECORD_FIELD(minor, AAF_TYPE(UInt16),
    ProductVersion)
  AAF_TYPE_DEFINITION_RECORD_FIELD(tertiary, AAF_TYPE(UInt16),
    ProductVersion)
  AAF_TYPE_DEFINITION_RECORD_FIELD(patchLevel, AAF_TYPE(UInt16),
    ProductVersion)
  AAF_TYPE_DEFINITION_RECORD_FIELD(type, AAF_TYPE(ProductReleaseType),
    ProductVersion)
AAF_TYPE_DEFINITION_RECORD_END(ProductVersion, 
  // {03010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// VersionType
//
AAF_TYPE_DEFINITION_RECORD(VersionType, 
  // {03010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(major, AAF_TYPE(Int8),
    VersionType)
  AAF_TYPE_DEFINITION_RECORD_FIELD(minor, AAF_TYPE(Int8),
    VersionType)
AAF_TYPE_DEFINITION_RECORD_END(VersionType, 
  // {03010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// RGBAComponent
//
AAF_TYPE_DEFINITION_RECORD(RGBAComponent, 
  // {03010400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(Code, AAF_TYPE(RGBAComponentKind),
    RGBAComponent)
  AAF_TYPE_DEFINITION_RECORD_FIELD(Size, AAF_TYPE(UInt8),
    RGBAComponent)
AAF_TYPE_DEFINITION_RECORD_END(RGBAComponent, 
  // {03010400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// DateStruct
//
AAF_TYPE_DEFINITION_RECORD(DateStruct, 
  // {03010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(year, AAF_TYPE(Int16),
    DateStruct)
  AAF_TYPE_DEFINITION_RECORD_FIELD(month, AAF_TYPE(UInt8),
    DateStruct)
  AAF_TYPE_DEFINITION_RECORD_FIELD(day, AAF_TYPE(UInt8),
    DateStruct)
AAF_TYPE_DEFINITION_RECORD_END(DateStruct, 
  // {03010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// TimeStruct
//
AAF_TYPE_DEFINITION_RECORD(TimeStruct, 
  // {03010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(hour, AAF_TYPE(UInt8),
    TimeStruct)
  AAF_TYPE_DEFINITION_RECORD_FIELD(minute, AAF_TYPE(UInt8),
    TimeStruct)
  AAF_TYPE_DEFINITION_RECORD_FIELD(second, AAF_TYPE(UInt8),
    TimeStruct)
  AAF_TYPE_DEFINITION_RECORD_FIELD(fraction, AAF_TYPE(UInt8),
    TimeStruct)
AAF_TYPE_DEFINITION_RECORD_END(TimeStruct, 
  // {03010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// TimeStamp
//
AAF_TYPE_DEFINITION_RECORD(TimeStamp, 
  // {03010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
  AAF_TYPE_DEFINITION_RECORD_FIELD(date, AAF_TYPE(DateStruct),
    TimeStamp)
  AAF_TYPE_DEFINITION_RECORD_FIELD(time, AAF_TYPE(TimeStruct),
    TimeStamp)
AAF_TYPE_DEFINITION_RECORD_END(TimeStamp, 
  // {03010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.03.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x03010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// UInt8Array
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(UInt8Array, 
  // {04010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// UInt8Array12
//
AAF_TYPE_DEFINITION_FIXED_ARRAY(UInt8Array12, 
  // {04010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt8), 12)
AAF_TYPE_SEPARATOR()

// Int32Array
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(Int32Array, 
  // {04010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Int32))
AAF_TYPE_SEPARATOR()

// Int64Array
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(Int64Array, 
  // {04010400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Int64))
AAF_TYPE_SEPARATOR()

// StringArray
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(StringArray, 
  // {04010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Character))
AAF_TYPE_SEPARATOR()

// AUIDArray
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(AUIDArray, 
  // {04010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(AUID))
AAF_TYPE_SEPARATOR()

// PositionArray
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(PositionArray, 
  // {04010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// UInt8Array8
//
AAF_TYPE_DEFINITION_FIXED_ARRAY(UInt8Array8, 
  // {04010800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt8), 8)
AAF_TYPE_SEPARATOR()

// UInt32Array
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(UInt32Array, 
  // {04010900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.01.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x04010900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt32))
AAF_TYPE_SEPARATOR()

// RGBALayout
//
AAF_TYPE_DEFINITION_FIXED_ARRAY(RGBALayout, 
  // {04020100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.02.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x04020100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(RGBAComponent), 8)
AAF_TYPE_SEPARATOR()

// AUIDSet
//
AAF_TYPE_DEFINITION_SET(AUIDSet, 
  // {04030100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.03.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x04030100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(AUID))
AAF_TYPE_SEPARATOR()

// UInt32Set
//
AAF_TYPE_DEFINITION_SET(UInt32Set, 
  // {04030200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.03.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x04030200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt32))
AAF_TYPE_SEPARATOR()

// DataValue
//
AAF_TYPE_DEFINITION_VARYING_ARRAY(DataValue, 
  // {04100100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.10.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x04100100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(UInt8))
AAF_TYPE_SEPARATOR()

// Stream
//
AAF_TYPE_DEFINITION_STREAM(Stream, 
  // {04100200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.10.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x04100200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// Indirect
//
AAF_TYPE_DEFINITION_INDIRECT(Indirect, 
  // {04100300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.10.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x04100300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// Opaque
//
AAF_TYPE_DEFINITION_OPAQUE(Opaque, 
  // {04100400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.04.10.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x04100400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01))
AAF_TYPE_SEPARATOR()

// WeakReference<ClassDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ClassDefinition), 
  // {05010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ClassDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(MetaDictionary, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ClassDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(ClassDefinitions, MetaDictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ClassDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ClassDefinition), 
  // {05010100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ClassDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<ContainerDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ContainerDefinition), 
  // {05010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ContainerDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ContainerDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ContainerDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(ContainerDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ContainerDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ContainerDefinition), 
  // {05010200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ContainerDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<DataDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, DataDefinition), 
  // {05010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, DataDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, DataDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(DataDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, DataDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, DataDefinition), 
  // {05010300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<InterpolationDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, InterpolationDefinition), 
  // {05010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(InterpolationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, InterpolationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, InterpolationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(InterpolationDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, InterpolationDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, InterpolationDefinition), 
  // {05010500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(InterpolationDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<Mob>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, Mob), 
  // {05010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Mob))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, Mob))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Content, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, Mob))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Mobs, ContentStorage,
    AAF_REFERENCE_TYPE_NAME(WeakReference, Mob))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, Mob), 
  // {05010600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Mob))
AAF_TYPE_SEPARATOR()

// WeakReference<OperationDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, OperationDefinition), 
  // {05010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, OperationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, OperationDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(OperationDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, OperationDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, OperationDefinition), 
  // {05010700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<ParameterDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ParameterDefinition), 
  // {05010800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ParameterDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ParameterDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ParameterDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(ParameterDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, ParameterDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, ParameterDefinition), 
  // {05010800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ParameterDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<TypeDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, TypeDefinition), 
  // {05010900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TypeDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(MetaDictionary, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, TypeDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(TypeDefinitions, MetaDictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, TypeDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, TypeDefinition), 
  // {05010900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TypeDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<PluginDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, PluginDefinition), 
  // {05010A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PluginDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PluginDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PluginDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(PluginDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PluginDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, PluginDefinition), 
  // {05010A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PluginDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<CodecDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, CodecDefinition), 
  // {05010B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(CodecDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Header, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, CodecDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Dictionary, Header,
    AAF_REFERENCE_TYPE_NAME(WeakReference, CodecDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(CodecDefinitions, Dictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, CodecDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, CodecDefinition), 
  // {05010B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(CodecDefinition))
AAF_TYPE_SEPARATOR()

// WeakReference<PropertyDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(WeakReference, PropertyDefinition), 
  // {05010C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PropertyDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(MetaDictionary, Root,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PropertyDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(ClassDefinitions, MetaDictionary,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PropertyDefinition))
  AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER(Properties, ClassDefinition,
    AAF_REFERENCE_TYPE_NAME(WeakReference, PropertyDefinition))
AAF_TYPE_DEFINITION_WEAK_REFERENCE_END(
  AAF_REFERENCE_TYPE_NAME(WeakReference, PropertyDefinition), 
  // {05010C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.01.0C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05010C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PropertyDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<ContentStorage>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, ContentStorage), 
  // {05020100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ContentStorage))
AAF_TYPE_SEPARATOR()

// StrongReference<Dictionary>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Dictionary), 
  // {05020200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Dictionary))
AAF_TYPE_SEPARATOR()

// StrongReference<EssenceDescriptor>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, EssenceDescriptor), 
  // {05020300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(EssenceDescriptor))
AAF_TYPE_SEPARATOR()

// StrongReference<NetworkLocator>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, NetworkLocator), 
  // {05020400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(NetworkLocator))
AAF_TYPE_SEPARATOR()

// StrongReference<OperationGroup>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, OperationGroup), 
  // {05020500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationGroup))
AAF_TYPE_SEPARATOR()

// StrongReference<Segment>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Segment), 
  // {05020600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Segment))
AAF_TYPE_SEPARATOR()

// StrongReference<SourceClip>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, SourceClip), 
  // {05020700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(SourceClip))
AAF_TYPE_SEPARATOR()

// StrongReference<SourceReference>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, SourceReference), 
  // {05020800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(SourceReference))
AAF_TYPE_SEPARATOR()

// StrongReference<ClassDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, ClassDefinition), 
  // {05020900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ClassDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<CodecDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, CodecDefinition), 
  // {05020A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(CodecDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<Component>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Component), 
  // {05020B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Component))
AAF_TYPE_SEPARATOR()

// StrongReference<ContainerDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, ContainerDefinition), 
  // {05020C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ContainerDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<ControlPoint>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, ControlPoint), 
  // {05020D00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0D.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020D00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ControlPoint))
AAF_TYPE_SEPARATOR()

// StrongReference<DataDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, DataDefinition), 
  // {05020E00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0E.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020E00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<EssenceData>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, EssenceData), 
  // {05020F00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.0F.00.00.00.00.00
  AAF_LITERAL_AUID(0x05020F00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(EssenceData))
AAF_TYPE_SEPARATOR()

// StrongReference<Identification>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Identification), 
  // {05021000-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.10.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021000,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Identification))
AAF_TYPE_SEPARATOR()

// StrongReference<InterpolationDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, InterpolationDefinition), 
  // {05021100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.11.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(InterpolationDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<Locator>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Locator), 
  // {05021200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.12.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Locator))
AAF_TYPE_SEPARATOR()

// StrongReference<Mob>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Mob), 
  // {05021300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.13.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Mob))
AAF_TYPE_SEPARATOR()

// StrongReference<MobSlot>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, MobSlot), 
  // {05021400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.14.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(MobSlot))
AAF_TYPE_SEPARATOR()

// StrongReference<OperationDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, OperationDefinition), 
  // {05021500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.15.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<Parameter>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, Parameter), 
  // {05021600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.16.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Parameter))
AAF_TYPE_SEPARATOR()

// StrongReference<ParameterDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, ParameterDefinition), 
  // {05021700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.17.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ParameterDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<PluginDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, PluginDefinition), 
  // {05021800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.18.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PluginDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<PropertyDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, PropertyDefinition), 
  // {05021900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.19.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PropertyDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<TaggedValue>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, TaggedValue), 
  // {05021A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TaggedValue))
AAF_TYPE_SEPARATOR()

// StrongReference<TypeDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, TypeDefinition), 
  // {05021B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TypeDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<KLVData>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, KLVData), 
  // {05021C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(KLVData))
AAF_TYPE_SEPARATOR()

// StrongReference<FileDescriptor>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, FileDescriptor), 
  // {05021D00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1D.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021D00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(FileDescriptor))
AAF_TYPE_SEPARATOR()

// StrongReference<RIFFChunk>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, RIFFChunk), 
  // {05021E00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1E.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021E00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(RIFFChunk))
AAF_TYPE_SEPARATOR()

// StrongReference<DescriptiveFramework>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, DescriptiveFramework), 
  // {05021F00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.1F.00.00.00.00.00
  AAF_LITERAL_AUID(0x05021F00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DescriptiveFramework))
AAF_TYPE_SEPARATOR()

// StrongReference<KLVDataDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, KLVDataDefinition), 
  // {05022000-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.20.00.00.00.00.00
  AAF_LITERAL_AUID(0x05022000,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(KLVDataDefinition))
AAF_TYPE_SEPARATOR()

// StrongReference<TaggedValueDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE(
  AAF_REFERENCE_TYPE_NAME(StrongReference, TaggedValueDefinition), 
  // {05022100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.02.21.00.00.00.00.00
  AAF_LITERAL_AUID(0x05022100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TaggedValueDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceSet<DataDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceSet, DataDefinition), 
  // {05030D00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.03.0D.00.00.00.00.00
  AAF_LITERAL_AUID(0x05030D00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceSet<ParameterDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceSet, ParameterDefinition), 
  // {05030E00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.03.0E.00.00.00.00.00
  AAF_LITERAL_AUID(0x05030E00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ParameterDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceSet<PluginDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceSet, PluginDefinition), 
  // {05030F00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.03.0F.00.00.00.00.00
  AAF_LITERAL_AUID(0x05030F00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PluginDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceSet<PropertyDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceSet, PropertyDefinition), 
  // {05031000-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.03.10.00.00.00.00.00
  AAF_LITERAL_AUID(0x05031000,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PropertyDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceVector<OperationDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceVector, OperationDefinition), 
  // {05040100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.04.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05040100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceVector<TypeDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceVector, TypeDefinition), 
  // {05040200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.04.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05040200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TypeDefinition))
AAF_TYPE_SEPARATOR()

// WeakReferenceVector<DataDefinition>
//
AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(WeakReferenceVector, DataDefinition), 
  // {05040300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.04.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05040300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<ClassDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, ClassDefinition), 
  // {05050100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ClassDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<CodecDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, CodecDefinition), 
  // {05050200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(CodecDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<ContainerDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, ContainerDefinition), 
  // {05050300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ContainerDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<DataDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, DataDefinition), 
  // {05050400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(DataDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<EssenceData>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, EssenceData), 
  // {05050500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(EssenceData))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<InterpolationDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, InterpolationDefinition), 
  // {05050600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(InterpolationDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<Mob>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, Mob), 
  // {05050700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Mob))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<OperationDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, OperationDefinition), 
  // {05050800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(OperationDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<ParameterDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, ParameterDefinition), 
  // {05050900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ParameterDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<PluginDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, PluginDefinition), 
  // {05050A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.0A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PluginDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<PropertyDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, PropertyDefinition), 
  // {05050B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.0B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(PropertyDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<TypeDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, TypeDefinition), 
  // {05050C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.0C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TypeDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<KLVDataDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, KLVDataDefinition), 
  // {05050D00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.0D.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050D00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(KLVDataDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceSet<TaggedValueDefinition>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceSet, TaggedValueDefinition), 
  // {05050E00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.05.0E.00.00.00.00.00
  AAF_LITERAL_AUID(0x05050E00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TaggedValueDefinition))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<Component>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, Component), 
  // {05060100-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.01.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060100,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Component))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<ControlPoint>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, ControlPoint), 
  // {05060200-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.02.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060200,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(ControlPoint))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<Identification>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, Identification), 
  // {05060300-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.03.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060300,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Identification))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<Locator>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, Locator), 
  // {05060400-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.04.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060400,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Locator))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<MobSlot>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, MobSlot), 
  // {05060500-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.05.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060500,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(MobSlot))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<Segment>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, Segment), 
  // {05060600-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.06.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060600,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Segment))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<SourceReference>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, SourceReference), 
  // {05060700-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.07.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060700,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(SourceReference))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<TaggedValue>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, TaggedValue), 
  // {05060800-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.08.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060800,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(TaggedValue))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<KLVData>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, KLVData), 
  // {05060900-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.09.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060900,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(KLVData))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<Parameter>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, Parameter), 
  // {05060A00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.0A.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060A00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(Parameter))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<FileDescriptor>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, FileDescriptor), 
  // {05060B00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.0B.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060B00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(FileDescriptor))
AAF_TYPE_SEPARATOR()

// StrongReferenceVector<RIFFChunk>
//
AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR(
  AAF_REFERENCE_TYPE_NAME(StrongReferenceVector, RIFFChunk), 
  // {05060C00-0000-0000-060E-2B3401040101}
  // 06.0E.2B.34.01.04.01.01.05.06.0C.00.00.00.00.00
  AAF_LITERAL_AUID(0x05060C00,
    0x0000, 0x0000,
    0x06, 0x0E, 0x2B, 0x34, 0x01, 0x04, 0x01, 0x01),
  AAF_TYPE(RIFFChunk))

AAF_TYPE_TABLE_END()

// Aliases
//

AAF_ALIAS_TABLE_BEGIN()

AAF_CLASS_ALIAS(ClassDefinition, ClassDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(CodecDefinition, CodecDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(DataDefinition, DataDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(DefinitionObject, DefObject)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(EdgeCode, Edgecode)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(OperationDefinition, OperationDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(InterchangeObject, Object)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(ParameterDefinition, ParameterDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(InterpolationDefinition, InterpolationDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(PropertyDefinition, PropertyDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinition, TypeDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionCharacter, TypeDefCharacter)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionEnumeration, TypeDefEnum)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionExtendibleEnumeration, TypeDefExtEnum)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionFixedArray, TypeDefFixedArray)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionInteger, TypeDefInt)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionRecord, TypeDefRecord)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionRename, TypeDefRename)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionSet, TypeDefSet)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionStream, TypeDefStream)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionString, TypeDefString)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionIndirect, TypeDefIndirect)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionOpaque, TypeDefOpaque)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionStrongObjectReference, TypeDefStrongObjRef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionVariableArray, TypeDefVariableArray)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(TypeDefinitionWeakObjectReference, TypeDefWeakObjRef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(ContainerDefinition, ContainerDef)
AAF_ALIAS_SEPARATOR()
AAF_CLASS_ALIAS(PluginDefinition, PluginDef)

AAF_ALIAS_TABLE_END()

// Instances
//

AAF_INSTANCE_TABLE_BEGIN()

AAF_INSTANCE_GROUP(OperationDefinitionInstances, OperationDefinition)
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoDissolve,OperationDef_VideoDissolve,"kAAFEffectVideoDissolve",""), 
      // {0C3BEA40-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.40.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA40,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoDissolve")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0C3BEA40-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.40.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA40,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoDissolve,OperationDef_VideoDissolve,"kAAFEffectVideoDissolve",""), 
      // {0C3BEA40-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.40.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA40,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_SMPTEVideoWipe,OperationDef_SMPTEVideoWipe,"kAAFEffectSMPTEVideoWipe",""), 
      // {0C3BEA44-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.44.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA44,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_SMPTEVideoWipe")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0C3BEA44-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.44.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA44,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_SMPTEVideoWipe,OperationDef_SMPTEVideoWipe,"kAAFEffectSMPTEVideoWipe",""), 
      // {0C3BEA44-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.44.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA44,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoSpeedControl,OperationDef_VideoSpeedControl,"kAAFEffectVideoSpeedControl",""), 
      // {9D2EA890-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.90.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA890,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoSpeedControl")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA890-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.90.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA890,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoSpeedControl,OperationDef_VideoSpeedControl,"kAAFEffectVideoSpeedControl",""), 
      // {9D2EA890-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.90.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA890,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoRepeat,OperationDef_VideoRepeat,"kAAFEffectVideoRepeat",""), 
      // {9D2EA891-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.91.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA891,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoRepeat")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA891-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.91.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA891,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoRepeat,OperationDef_VideoRepeat,"kAAFEffectVideoRepeat",""), 
      // {9D2EA891-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.91.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA891,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_Flip,OperationDef_Flip,"",""), 
      // {F1DB0F32-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.32.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F32,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_Flip")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {F1DB0F32-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.32.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F32,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_Flip,OperationDef_Flip,"",""), 
      // {F1DB0F32-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.32.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F32,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_Flop,OperationDef_Flop,"",""), 
      // {F1DB0F34-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.34.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F34,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_Flop")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {F1DB0F34-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.34.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F34,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_Flop,OperationDef_Flop,"",""), 
      // {F1DB0F34-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.34.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F34,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_FlipFlop,OperationDef_FlipFlop,"",""), 
      // {F1DB0F33-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.33.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F33,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_FlipFlop")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {F1DB0F33-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.33.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F33,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_FlipFlop,OperationDef_FlipFlop,"",""), 
      // {F1DB0F33-8D64-11D3-80DF-006008143E6F}
      // 80.DF.00.60.08.14.3E.6F.F1.DB.0F.33.8D.64.11.D3
      AAF_LITERAL_AUID(0xF1DB0F33,
        0x8D64, 0x11D3,
        0x80, 0xDF, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoPosition,OperationDef_VideoPosition,"",""), 
      // {86F5711E-EE72-450C-A118-17CF3B175DFF}
      // A1.18.17.CF.3B.17.5D.FF.86.F5.71.1E.EE.72.45.0C
      AAF_LITERAL_AUID(0x86F5711E,
        0xEE72, 0x450C,
        0xA1, 0x18, 0x17, 0xCF, 0x3B, 0x17, 0x5D, 0xFF), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoPosition")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {86F5711E-EE72-450C-A118-17CF3B175DFF}
      // A1.18.17.CF.3B.17.5D.FF.86.F5.71.1E.EE.72.45.0C
      AAF_LITERAL_AUID(0x86F5711E,
        0xEE72, 0x450C,
        0xA1, 0x18, 0x17, 0xCF, 0x3B, 0x17, 0x5D, 0xFF))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoPosition,OperationDef_VideoPosition,"",""), 
      // {86F5711E-EE72-450C-A118-17CF3B175DFF}
      // A1.18.17.CF.3B.17.5D.FF.86.F5.71.1E.EE.72.45.0C
      AAF_LITERAL_AUID(0x86F5711E,
        0xEE72, 0x450C,
        0xA1, 0x18, 0x17, 0xCF, 0x3B, 0x17, 0x5D, 0xFF))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoCrop,OperationDef_VideoCrop,"",""), 
      // {F5826680-26C5-4149-8554-43D3C7A3BC09}
      // 85.54.43.D3.C7.A3.BC.09.F5.82.66.80.26.C5.41.49
      AAF_LITERAL_AUID(0xF5826680,
        0x26C5, 0x4149,
        0x85, 0x54, 0x43, 0xD3, 0xC7, 0xA3, 0xBC, 0x09), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoCrop")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {F5826680-26C5-4149-8554-43D3C7A3BC09}
      // 85.54.43.D3.C7.A3.BC.09.F5.82.66.80.26.C5.41.49
      AAF_LITERAL_AUID(0xF5826680,
        0x26C5, 0x4149,
        0x85, 0x54, 0x43, 0xD3, 0xC7, 0xA3, 0xBC, 0x09))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoCrop,OperationDef_VideoCrop,"",""), 
      // {F5826680-26C5-4149-8554-43D3C7A3BC09}
      // 85.54.43.D3.C7.A3.BC.09.F5.82.66.80.26.C5.41.49
      AAF_LITERAL_AUID(0xF5826680,
        0x26C5, 0x4149,
        0x85, 0x54, 0x43, 0xD3, 0xC7, 0xA3, 0xBC, 0x09))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoScale,OperationDef_VideoScale,"",""), 
      // {2E0A119D-E6F7-4BEE-B5DC-6DD42988687E}
      // B5.DC.6D.D4.29.88.68.7E.2E.0A.11.9D.E6.F7.4B.EE
      AAF_LITERAL_AUID(0x2E0A119D,
        0xE6F7, 0x4BEE,
        0xB5, 0xDC, 0x6D, 0xD4, 0x29, 0x88, 0x68, 0x7E), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoScale")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {2E0A119D-E6F7-4BEE-B5DC-6DD42988687E}
      // B5.DC.6D.D4.29.88.68.7E.2E.0A.11.9D.E6.F7.4B.EE
      AAF_LITERAL_AUID(0x2E0A119D,
        0xE6F7, 0x4BEE,
        0xB5, 0xDC, 0x6D, 0xD4, 0x29, 0x88, 0x68, 0x7E))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoScale,OperationDef_VideoScale,"",""), 
      // {2E0A119D-E6F7-4BEE-B5DC-6DD42988687E}
      // B5.DC.6D.D4.29.88.68.7E.2E.0A.11.9D.E6.F7.4B.EE
      AAF_LITERAL_AUID(0x2E0A119D,
        0xE6F7, 0x4BEE,
        0xB5, 0xDC, 0x6D, 0xD4, 0x29, 0x88, 0x68, 0x7E))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoRotate,OperationDef_VideoRotate,"",""), 
      // {F2CA330D-8D45-4DB4-B1B5-136AB055586F}
      // B1.B5.13.6A.B0.55.58.6F.F2.CA.33.0D.8D.45.4D.B4
      AAF_LITERAL_AUID(0xF2CA330D,
        0x8D45, 0x4DB4,
        0xB1, 0xB5, 0x13, 0x6A, 0xB0, 0x55, 0x58, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoRotate")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {F2CA330D-8D45-4DB4-B1B5-136AB055586F}
      // B1.B5.13.6A.B0.55.58.6F.F2.CA.33.0D.8D.45.4D.B4
      AAF_LITERAL_AUID(0xF2CA330D,
        0x8D45, 0x4DB4,
        0xB1, 0xB5, 0x13, 0x6A, 0xB0, 0x55, 0x58, 0x6F))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoRotate,OperationDef_VideoRotate,"",""), 
      // {F2CA330D-8D45-4DB4-B1B5-136AB055586F}
      // B1.B5.13.6A.B0.55.58.6F.F2.CA.33.0D.8D.45.4D.B4
      AAF_LITERAL_AUID(0xF2CA330D,
        0x8D45, 0x4DB4,
        0xB1, 0xB5, 0x13, 0x6A, 0xB0, 0x55, 0x58, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoCornerPinning,OperationDef_VideoCornerPinning,"",""), 
      // {21D5C51A-8ACB-46D5-9392-5CAE640C8836}
      // 93.92.5C.AE.64.0C.88.36.21.D5.C5.1A.8A.CB.46.D5
      AAF_LITERAL_AUID(0x21D5C51A,
        0x8ACB, 0x46D5,
        0x93, 0x92, 0x5C, 0xAE, 0x64, 0x0C, 0x88, 0x36), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoCornerPinning")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {21D5C51A-8ACB-46D5-9392-5CAE640C8836}
      // 93.92.5C.AE.64.0C.88.36.21.D5.C5.1A.8A.CB.46.D5
      AAF_LITERAL_AUID(0x21D5C51A,
        0x8ACB, 0x46D5,
        0x93, 0x92, 0x5C, 0xAE, 0x64, 0x0C, 0x88, 0x36))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoCornerPinning,OperationDef_VideoCornerPinning,"",""), 
      // {21D5C51A-8ACB-46D5-9392-5CAE640C8836}
      // 93.92.5C.AE.64.0C.88.36.21.D5.C5.1A.8A.CB.46.D5
      AAF_LITERAL_AUID(0x21D5C51A,
        0x8ACB, 0x46D5,
        0x93, 0x92, 0x5C, 0xAE, 0x64, 0x0C, 0x88, 0x36))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoAlphaWithinVideoKey,OperationDef_VideoAlphaWithinVideoKey,"",""), 
      // {14DB900E-D537-49F6-889B-012568FCC234}
      // 88.9B.01.25.68.FC.C2.34.14.DB.90.0E.D5.37.49.F6
      AAF_LITERAL_AUID(0x14DB900E,
        0xD537, 0x49F6,
        0x88, 0x9B, 0x01, 0x25, 0x68, 0xFC, 0xC2, 0x34), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoAlphaWithinVideoKey")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {14DB900E-D537-49F6-889B-012568FCC234}
      // 88.9B.01.25.68.FC.C2.34.14.DB.90.0E.D5.37.49.F6
      AAF_LITERAL_AUID(0x14DB900E,
        0xD537, 0x49F6,
        0x88, 0x9B, 0x01, 0x25, 0x68, 0xFC, 0xC2, 0x34))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoAlphaWithinVideoKey,OperationDef_VideoAlphaWithinVideoKey,"",""), 
      // {14DB900E-D537-49F6-889B-012568FCC234}
      // 88.9B.01.25.68.FC.C2.34.14.DB.90.0E.D5.37.49.F6
      AAF_LITERAL_AUID(0x14DB900E,
        0xD537, 0x49F6,
        0x88, 0x9B, 0x01, 0x25, 0x68, 0xFC, 0xC2, 0x34))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoSeparateAlphaKey,OperationDef_VideoSeparateAlphaKey,"",""), 
      // {E599CB0F-BA5F-4192-9356-51EB19C08589}
      // 93.56.51.EB.19.C0.85.89.E5.99.CB.0F.BA.5F.41.92
      AAF_LITERAL_AUID(0xE599CB0F,
        0xBA5F, 0x4192,
        0x93, 0x56, 0x51, 0xEB, 0x19, 0xC0, 0x85, 0x89), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoSeparateAlphaKey")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {E599CB0F-BA5F-4192-9356-51EB19C08589}
      // 93.56.51.EB.19.C0.85.89.E5.99.CB.0F.BA.5F.41.92
      AAF_LITERAL_AUID(0xE599CB0F,
        0xBA5F, 0x4192,
        0x93, 0x56, 0x51, 0xEB, 0x19, 0xC0, 0x85, 0x89))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoSeparateAlphaKey,OperationDef_VideoSeparateAlphaKey,"",""), 
      // {E599CB0F-BA5F-4192-9356-51EB19C08589}
      // 93.56.51.EB.19.C0.85.89.E5.99.CB.0F.BA.5F.41.92
      AAF_LITERAL_AUID(0xE599CB0F,
        0xBA5F, 0x4192,
        0x93, 0x56, 0x51, 0xEB, 0x19, 0xC0, 0x85, 0x89))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoLuminanceKey,OperationDef_VideoLuminanceKey,"",""), 
      // {38FF7903-69E5-476B-BE5A-EAFC2000F011}
      // BE.5A.EA.FC.20.00.F0.11.38.FF.79.03.69.E5.47.6B
      AAF_LITERAL_AUID(0x38FF7903,
        0x69E5, 0x476B,
        0xBE, 0x5A, 0xEA, 0xFC, 0x20, 0x00, 0xF0, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoLuminanceKey")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {38FF7903-69E5-476B-BE5A-EAFC2000F011}
      // BE.5A.EA.FC.20.00.F0.11.38.FF.79.03.69.E5.47.6B
      AAF_LITERAL_AUID(0x38FF7903,
        0x69E5, 0x476B,
        0xBE, 0x5A, 0xEA, 0xFC, 0x20, 0x00, 0xF0, 0x11))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoLuminanceKey,OperationDef_VideoLuminanceKey,"",""), 
      // {38FF7903-69E5-476B-BE5A-EAFC2000F011}
      // BE.5A.EA.FC.20.00.F0.11.38.FF.79.03.69.E5.47.6B
      AAF_LITERAL_AUID(0x38FF7903,
        0x69E5, 0x476B,
        0xBE, 0x5A, 0xEA, 0xFC, 0x20, 0x00, 0xF0, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoChromaKey,OperationDef_VideoChromaKey,"",""), 
      // {30A315C2-71E5-4E82-A4EF-0513EE056B65}
      // A4.EF.05.13.EE.05.6B.65.30.A3.15.C2.71.E5.4E.82
      AAF_LITERAL_AUID(0x30A315C2,
        0x71E5, 0x4E82,
        0xA4, 0xEF, 0x05, 0x13, 0xEE, 0x05, 0x6B, 0x65), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoChromaKey")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {30A315C2-71E5-4E82-A4EF-0513EE056B65}
      // A4.EF.05.13.EE.05.6B.65.30.A3.15.C2.71.E5.4E.82
      AAF_LITERAL_AUID(0x30A315C2,
        0x71E5, 0x4E82,
        0xA4, 0xEF, 0x05, 0x13, 0xEE, 0x05, 0x6B, 0x65))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoChromaKey,OperationDef_VideoChromaKey,"",""), 
      // {30A315C2-71E5-4E82-A4EF-0513EE056B65}
      // A4.EF.05.13.EE.05.6B.65.30.A3.15.C2.71.E5.4E.82
      AAF_LITERAL_AUID(0x30A315C2,
        0x71E5, 0x4E82,
        0xA4, 0xEF, 0x05, 0x13, 0xEE, 0x05, 0x6B, 0x65))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioGain,OperationDef_MonoAudioGain,"kAAFEffectMonoAudioGain",""), 
      // {9D2EA894-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.94.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA894,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_MonoAudioGain")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA894-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.94.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA894,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioGain,OperationDef_MonoAudioGain,"kAAFEffectMonoAudioGain",""), 
      // {9D2EA894-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.94.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA894,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioPan,OperationDef_MonoAudioPan,"kAAFEffectMonoAudioPan",""), 
      // {9D2EA893-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.93.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA893,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_MonoAudioPan")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA893-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.93.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA893,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioPan,OperationDef_MonoAudioPan,"kAAFEffectMonoAudioPan",""), 
      // {9D2EA893-0968-11D3-8A38-0050040EF7D2}
      // 8A.38.00.50.04.0E.F7.D2.9D.2E.A8.93.09.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA893,
        0x0968, 0x11D3,
        0x8A, 0x38, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioDissolve,OperationDef_MonoAudioDissolve,"kAAFEffectMonoAudioDissolve",""), 
      // {0C3BEA41-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.41.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA41,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_MonoAudioDissolve")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0C3BEA41-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.41.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA41,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioDissolve,OperationDef_MonoAudioDissolve,"kAAFEffectMonoAudioDissolve",""), 
      // {0C3BEA41-FC05-11D2-8A29-0050040EF7D2}
      // 8A.29.00.50.04.0E.F7.D2.0C.3B.EA.41.FC.05.11.D2
      AAF_LITERAL_AUID(0x0C3BEA41,
        0xFC05, 0x11D2,
        0x8A, 0x29, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_TwoParameterMonoAudioDissolve,OperationDef_TwoParameterMonoAudioDissolve,"",""), 
      // {2311BD90-B5DA-4285-AA3A-8552848779B3}
      // AA.3A.85.52.84.87.79.B3.23.11.BD.90.B5.DA.42.85
      AAF_LITERAL_AUID(0x2311BD90,
        0xB5DA, 0x4285,
        0xAA, 0x3A, 0x85, 0x52, 0x84, 0x87, 0x79, 0xB3), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_TwoParameterMonoAudioDissolve")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {2311BD90-B5DA-4285-AA3A-8552848779B3}
      // AA.3A.85.52.84.87.79.B3.23.11.BD.90.B5.DA.42.85
      AAF_LITERAL_AUID(0x2311BD90,
        0xB5DA, 0x4285,
        0xAA, 0x3A, 0x85, 0x52, 0x84, 0x87, 0x79, 0xB3))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_TwoParameterMonoAudioDissolve,OperationDef_TwoParameterMonoAudioDissolve,"",""), 
      // {2311BD90-B5DA-4285-AA3A-8552848779B3}
      // AA.3A.85.52.84.87.79.B3.23.11.BD.90.B5.DA.42.85
      AAF_LITERAL_AUID(0x2311BD90,
        0xB5DA, 0x4285,
        0xAA, 0x3A, 0x85, 0x52, 0x84, 0x87, 0x79, 0xB3))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_Unknown,OperationDef_Unknown,"kAAFOperationUnknown",""), 
      // {1575E350-FCA3-11D2-8A2A-05040EF7D2}
      // 8A.2A.0.50.4.0E.F7.D2.15.75.E3.50.FC.A3.11.D2
      AAF_LITERAL_AUID(0x1575E350,
        0xFCA3, 0x11D2,
        0x8A, 0x2A, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_Unknown")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {1575E350-FCA3-11D2-8A2A-05040EF7D2}
      // 8A.2A.0.50.4.0E.F7.D2.15.75.E3.50.FC.A3.11.D2
      AAF_LITERAL_AUID(0x1575E350,
        0xFCA3, 0x11D2,
        0x8A, 0x2A, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_Unknown,OperationDef_Unknown,"kAAFOperationUnknown",""), 
      // {1575E350-FCA3-11D2-8A2A-05040EF7D2}
      // 8A.2A.0.50.4.0E.F7.D2.15.75.E3.50.FC.A3.11.D2
      AAF_LITERAL_AUID(0x1575E350,
        0xFCA3, 0x11D2,
        0x8A, 0x2A, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoFadeToBlack,OperationDef_VideoFadeToBlack,"kAAFEffectVideoFadeToBlack",""), 
      // {0C3BEA43-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.43.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA43,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoFadeToBlack")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0C3BEA43-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.43.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA43,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoFadeToBlack,OperationDef_VideoFadeToBlack,"kAAFEffectVideoFadeToBlack",""), 
      // {0C3BEA43-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.43.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA43,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_PictureWithMate,OperationDef_PictureWithMate,"kAAFEffectPictureWithMate",""), 
      // {0A3C75E0-FD82-11D2-8A2B-05040EF7D2}
      // 8A.2B.0.50.4.0E.F7.D2.0A.3C.75.E0.FD.82.11.D2
      AAF_LITERAL_AUID(0x0A3C75E0,
        0xFD82, 0x11D2,
        0x8A, 0x2B, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_PictureWithMate")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0A3C75E0-FD82-11D2-8A2B-05040EF7D2}
      // 8A.2B.0.50.4.0E.F7.D2.0A.3C.75.E0.FD.82.11.D2
      AAF_LITERAL_AUID(0x0A3C75E0,
        0xFD82, 0x11D2,
        0x8A, 0x2B, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_PictureWithMate,OperationDef_PictureWithMate,"kAAFEffectPictureWithMate",""), 
      // {0A3C75E0-FD82-11D2-8A2B-05040EF7D2}
      // 8A.2B.0.50.4.0E.F7.D2.0A.3C.75.E0.FD.82.11.D2
      AAF_LITERAL_AUID(0x0A3C75E0,
        0xFD82, 0x11D2,
        0x8A, 0x2B, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_VideoFrameToMask,OperationDef_VideoFrameToMask,"kAAFEffectVideoFrameToMask",""), 
      // {9D2EA892-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.92.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA892,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_VideoFrameToMask")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA892-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.92.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA892,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_VideoFrameToMask,OperationDef_VideoFrameToMask,"kAAFEffectVideoFrameToMask",""), 
      // {9D2EA892-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.92.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA892,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_StereoAudioDissolve,OperationDef_StereoAudioDissolve,"kAAFEffectStereoAudioDissolve",""), 
      // {0C3BEA42-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.42.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA42,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_StereoAudioDissolve")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0C3BEA42-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.42.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA42,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_StereoAudioDissolve,OperationDef_StereoAudioDissolve,"kAAFEffectStereoAudioDissolve",""), 
      // {0C3BEA42-FC5-11D2-8A29-05040EF7D2}
      // 8A.29.0.50.4.0E.F7.D2.0C.3B.EA.42.FC.5.11.D2
      AAF_LITERAL_AUID(0x0C3BEA42,
        0xFC5, 0x11D2,
        0x8A, 0x29, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_StereoAudioGain,OperationDef_StereoAudioGain,"kAAFEffectStereoAudioGain",""), 
      // {9D2EA895-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.95.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA895,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_StereoAudioGain")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9D2EA895-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.95.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA895,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_StereoAudioGain,OperationDef_StereoAudioGain,"kAAFEffectStereoAudioGain",""), 
      // {9D2EA895-968-11D3-8A38-05040EF7D2}
      // 8A.38.0.50.4.0E.F7.D2.9D.2E.A8.95.9.68.11.D3
      AAF_LITERAL_AUID(0x9D2EA895,
        0x968, 0x11D3,
        0x8A, 0x38, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioMixdown,OperationDef_MonoAudioMixdown,"kAAFEffectMonoAudioMixdown",""), 
      // {8D896AD0-2261-11D3-8A4C-05040EF7D2}
      // 8A.4C.0.50.4.0E.F7.D2.8D.89.6A.D0.22.61.11.D3
      AAF_LITERAL_AUID(0x8D896AD0,
        0x2261, 0x11D3,
        0x8A, 0x4C, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "OperationDef_MonoAudioMixdown")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {8D896AD0-2261-11D3-8A4C-05040EF7D2}
      // 8A.4C.0.50.4.0E.F7.D2.8D.89.6A.D0.22.61.11.D3
      AAF_LITERAL_AUID(0x8D896AD0,
        0x2261, 0x11D3,
        0x8A, 0x4C, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(OperationDefinition, AAF_SYMBOL(OperationDef_MonoAudioMixdown,OperationDef_MonoAudioMixdown,"kAAFEffectMonoAudioMixdown",""), 
      // {8D896AD0-2261-11D3-8A4C-05040EF7D2}
      // 8A.4C.0.50.4.0E.F7.D2.8D.89.6A.D0.22.61.11.D3
      AAF_LITERAL_AUID(0x8D896AD0,
        0x2261, 0x11D3,
        0x8A, 0x4C, 0x0, 0x50, 0x4, 0x0E, 0xF7, 0xD2))
AAF_INSTANCE_GROUP_END(OperationDefinitionInstances, OperationDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(ParameterDefinitionInstances, ParameterDefinition)
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_Level,ParameterDef_Level,"kAAFParameterDefLevel",""), 
      // {E4962320-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.20.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962320,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_Level")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {E4962320-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.20.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962320,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_Level,ParameterDef_Level,"kAAFParameterDefLevel",""), 
      // {E4962320-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.20.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962320,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEWipeNumber,ParameterDef_SMPTEWipeNumber,"kAAFParameterDefSMPTEWipeNumber",""), 
      // {E4962323-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.23.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962323,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEWipeNumber")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {E4962323-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.23.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962323,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEWipeNumber,ParameterDef_SMPTEWipeNumber,"kAAFParameterDefSMPTEWipeNumber",""), 
      // {E4962323-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.23.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962323,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReverse,ParameterDef_SMPTEReverse,"kAAFParameterDefSMPTEReverse",""), 
      // {9C894BA0-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A0.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA0,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEReverse")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA0-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A0.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA0,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReverse,ParameterDef_SMPTEReverse,"kAAFParameterDefSMPTEReverse",""), 
      // {9C894BA0-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A0.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA0,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SpeedRatio,ParameterDef_SpeedRatio,"kAAFParameterDefSpeedRatio",""), 
      // {72559A80-24D7-11D3-8A50-0050040EF7D2}
      // 8A.50.00.50.04.0E.F7.D2.72.55.9A.80.24.D7.11.D3
      AAF_LITERAL_AUID(0x72559A80,
        0x24D7, 0x11D3,
        0x8A, 0x50, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SpeedRatio")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {72559A80-24D7-11D3-8A50-0050040EF7D2}
      // 8A.50.00.50.04.0E.F7.D2.72.55.9A.80.24.D7.11.D3
      AAF_LITERAL_AUID(0x72559A80,
        0x24D7, 0x11D3,
        0x8A, 0x50, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SpeedRatio,ParameterDef_SpeedRatio,"kAAFParameterDefSpeedRatio",""), 
      // {72559A80-24D7-11D3-8A50-0050040EF7D2}
      // 8A.50.00.50.04.0E.F7.D2.72.55.9A.80.24.D7.11.D3
      AAF_LITERAL_AUID(0x72559A80,
        0x24D7, 0x11D3,
        0x8A, 0x50, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PositionOffsetX,ParameterDef_PositionOffsetX,"",""), 
      // {C573A510-071A-454F-B617-AD6AE69054C2}
      // B6.17.AD.6A.E6.90.54.C2.C5.73.A5.10.07.1A.45.4F
      AAF_LITERAL_AUID(0xC573A510,
        0x071A, 0x454F,
        0xB6, 0x17, 0xAD, 0x6A, 0xE6, 0x90, 0x54, 0xC2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PositionOffsetX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {C573A510-071A-454F-B617-AD6AE69054C2}
      // B6.17.AD.6A.E6.90.54.C2.C5.73.A5.10.07.1A.45.4F
      AAF_LITERAL_AUID(0xC573A510,
        0x071A, 0x454F,
        0xB6, 0x17, 0xAD, 0x6A, 0xE6, 0x90, 0x54, 0xC2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PositionOffsetX,ParameterDef_PositionOffsetX,"",""), 
      // {C573A510-071A-454F-B617-AD6AE69054C2}
      // B6.17.AD.6A.E6.90.54.C2.C5.73.A5.10.07.1A.45.4F
      AAF_LITERAL_AUID(0xC573A510,
        0x071A, 0x454F,
        0xB6, 0x17, 0xAD, 0x6A, 0xE6, 0x90, 0x54, 0xC2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PositionOffsetY,ParameterDef_PositionOffsetY,"",""), 
      // {82E27478-1336-4EA3-BCB9-6B8F17864C42}
      // BC.B9.6B.8F.17.86.4C.42.82.E2.74.78.13.36.4E.A3
      AAF_LITERAL_AUID(0x82E27478,
        0x1336, 0x4EA3,
        0xBC, 0xB9, 0x6B, 0x8F, 0x17, 0x86, 0x4C, 0x42), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PositionOffsetY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {82E27478-1336-4EA3-BCB9-6B8F17864C42}
      // BC.B9.6B.8F.17.86.4C.42.82.E2.74.78.13.36.4E.A3
      AAF_LITERAL_AUID(0x82E27478,
        0x1336, 0x4EA3,
        0xBC, 0xB9, 0x6B, 0x8F, 0x17, 0x86, 0x4C, 0x42))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PositionOffsetY,ParameterDef_PositionOffsetY,"",""), 
      // {82E27478-1336-4EA3-BCB9-6B8F17864C42}
      // BC.B9.6B.8F.17.86.4C.42.82.E2.74.78.13.36.4E.A3
      AAF_LITERAL_AUID(0x82E27478,
        0x1336, 0x4EA3,
        0xBC, 0xB9, 0x6B, 0x8F, 0x17, 0x86, 0x4C, 0x42))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropLeft,ParameterDef_CropLeft,"",""), 
      // {D47B3377-318C-4657-A9D8-75811B6DC3D1}
      // A9.D8.75.81.1B.6D.C3.D1.D4.7B.33.77.31.8C.46.57
      AAF_LITERAL_AUID(0xD47B3377,
        0x318C, 0x4657,
        0xA9, 0xD8, 0x75, 0x81, 0x1B, 0x6D, 0xC3, 0xD1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_CropLeft")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {D47B3377-318C-4657-A9D8-75811B6DC3D1}
      // A9.D8.75.81.1B.6D.C3.D1.D4.7B.33.77.31.8C.46.57
      AAF_LITERAL_AUID(0xD47B3377,
        0x318C, 0x4657,
        0xA9, 0xD8, 0x75, 0x81, 0x1B, 0x6D, 0xC3, 0xD1))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropLeft,ParameterDef_CropLeft,"",""), 
      // {D47B3377-318C-4657-A9D8-75811B6DC3D1}
      // A9.D8.75.81.1B.6D.C3.D1.D4.7B.33.77.31.8C.46.57
      AAF_LITERAL_AUID(0xD47B3377,
        0x318C, 0x4657,
        0xA9, 0xD8, 0x75, 0x81, 0x1B, 0x6D, 0xC3, 0xD1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropRight,ParameterDef_CropRight,"",""), 
      // {5ECC9DD5-21C1-462B-9FEC-C2BD85F14033}
      // 9F.EC.C2.BD.85.F1.40.33.5E.CC.9D.D5.21.C1.46.2B
      AAF_LITERAL_AUID(0x5ECC9DD5,
        0x21C1, 0x462B,
        0x9F, 0xEC, 0xC2, 0xBD, 0x85, 0xF1, 0x40, 0x33), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_CropRight")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5ECC9DD5-21C1-462B-9FEC-C2BD85F14033}
      // 9F.EC.C2.BD.85.F1.40.33.5E.CC.9D.D5.21.C1.46.2B
      AAF_LITERAL_AUID(0x5ECC9DD5,
        0x21C1, 0x462B,
        0x9F, 0xEC, 0xC2, 0xBD, 0x85, 0xF1, 0x40, 0x33))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropRight,ParameterDef_CropRight,"",""), 
      // {5ECC9DD5-21C1-462B-9FEC-C2BD85F14033}
      // 9F.EC.C2.BD.85.F1.40.33.5E.CC.9D.D5.21.C1.46.2B
      AAF_LITERAL_AUID(0x5ECC9DD5,
        0x21C1, 0x462B,
        0x9F, 0xEC, 0xC2, 0xBD, 0x85, 0xF1, 0x40, 0x33))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropTop,ParameterDef_CropTop,"",""), 
      // {8170A539-9B55-4051-9D4E-46598D01B914}
      // 9D.4E.46.59.8D.01.B9.14.81.70.A5.39.9B.55.40.51
      AAF_LITERAL_AUID(0x8170A539,
        0x9B55, 0x4051,
        0x9D, 0x4E, 0x46, 0x59, 0x8D, 0x01, 0xB9, 0x14), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_CropTop")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {8170A539-9B55-4051-9D4E-46598D01B914}
      // 9D.4E.46.59.8D.01.B9.14.81.70.A5.39.9B.55.40.51
      AAF_LITERAL_AUID(0x8170A539,
        0x9B55, 0x4051,
        0x9D, 0x4E, 0x46, 0x59, 0x8D, 0x01, 0xB9, 0x14))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropTop,ParameterDef_CropTop,"",""), 
      // {8170A539-9B55-4051-9D4E-46598D01B914}
      // 9D.4E.46.59.8D.01.B9.14.81.70.A5.39.9B.55.40.51
      AAF_LITERAL_AUID(0x8170A539,
        0x9B55, 0x4051,
        0x9D, 0x4E, 0x46, 0x59, 0x8D, 0x01, 0xB9, 0x14))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropBottom,ParameterDef_CropBottom,"",""), 
      // {154BA82B-990A-4C80-9101-3037E28839A1}
      // 91.01.30.37.E2.88.39.A1.15.4B.A8.2B.99.0A.4C.80
      AAF_LITERAL_AUID(0x154BA82B,
        0x990A, 0x4C80,
        0x91, 0x01, 0x30, 0x37, 0xE2, 0x88, 0x39, 0xA1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_CropBottom")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {154BA82B-990A-4C80-9101-3037E28839A1}
      // 91.01.30.37.E2.88.39.A1.15.4B.A8.2B.99.0A.4C.80
      AAF_LITERAL_AUID(0x154BA82B,
        0x990A, 0x4C80,
        0x91, 0x01, 0x30, 0x37, 0xE2, 0x88, 0x39, 0xA1))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_CropBottom,ParameterDef_CropBottom,"",""), 
      // {154BA82B-990A-4C80-9101-3037E28839A1}
      // 91.01.30.37.E2.88.39.A1.15.4B.A8.2B.99.0A.4C.80
      AAF_LITERAL_AUID(0x154BA82B,
        0x990A, 0x4C80,
        0x91, 0x01, 0x30, 0x37, 0xE2, 0x88, 0x39, 0xA1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_ScaleX,ParameterDef_ScaleX,"",""), 
      // {8D568129-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.29.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D568129,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_ScaleX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {8D568129-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.29.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D568129,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_ScaleX,ParameterDef_ScaleX,"",""), 
      // {8D568129-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.29.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D568129,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_ScaleY,ParameterDef_ScaleY,"",""), 
      // {8D56812A-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.2A.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D56812A,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_ScaleY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {8D56812A-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.2A.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D56812A,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_ScaleY,ParameterDef_ScaleY,"",""), 
      // {8D56812A-847E-11D5-935A-50F857C10000}
      // 93.5A.50.F8.57.C1.00.00.8D.56.81.2A.84.7E.11.D5
      AAF_LITERAL_AUID(0x8D56812A,
        0x847E, 0x11D5,
        0x93, 0x5A, 0x50, 0xF8, 0x57, 0xC1, 0x00, 0x00))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_Rotation,ParameterDef_Rotation,"",""), 
      // {062CFBD8-F4B1-4A50-B944-F39E2FC73C17}
      // B9.44.F3.9E.2F.C7.3C.17.06.2C.FB.D8.F4.B1.4A.50
      AAF_LITERAL_AUID(0x062CFBD8,
        0xF4B1, 0x4A50,
        0xB9, 0x44, 0xF3, 0x9E, 0x2F, 0xC7, 0x3C, 0x17), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_Rotation")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {062CFBD8-F4B1-4A50-B944-F39E2FC73C17}
      // B9.44.F3.9E.2F.C7.3C.17.06.2C.FB.D8.F4.B1.4A.50
      AAF_LITERAL_AUID(0x062CFBD8,
        0xF4B1, 0x4A50,
        0xB9, 0x44, 0xF3, 0x9E, 0x2F, 0xC7, 0x3C, 0x17))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_Rotation,ParameterDef_Rotation,"",""), 
      // {062CFBD8-F4B1-4A50-B944-F39E2FC73C17}
      // B9.44.F3.9E.2F.C7.3C.17.06.2C.FB.D8.F4.B1.4A.50
      AAF_LITERAL_AUID(0x062CFBD8,
        0xF4B1, 0x4A50,
        0xB9, 0x44, 0xF3, 0x9E, 0x2F, 0xC7, 0x3C, 0x17))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopLeftX,ParameterDef_PinTopLeftX,"",""), 
      // {72A3B4A2-873D-4733-9052-9F83A706CA5B}
      // 90.52.9F.83.A7.06.CA.5B.72.A3.B4.A2.87.3D.47.33
      AAF_LITERAL_AUID(0x72A3B4A2,
        0x873D, 0x4733,
        0x90, 0x52, 0x9F, 0x83, 0xA7, 0x06, 0xCA, 0x5B), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinTopLeftX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {72A3B4A2-873D-4733-9052-9F83A706CA5B}
      // 90.52.9F.83.A7.06.CA.5B.72.A3.B4.A2.87.3D.47.33
      AAF_LITERAL_AUID(0x72A3B4A2,
        0x873D, 0x4733,
        0x90, 0x52, 0x9F, 0x83, 0xA7, 0x06, 0xCA, 0x5B))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopLeftX,ParameterDef_PinTopLeftX,"",""), 
      // {72A3B4A2-873D-4733-9052-9F83A706CA5B}
      // 90.52.9F.83.A7.06.CA.5B.72.A3.B4.A2.87.3D.47.33
      AAF_LITERAL_AUID(0x72A3B4A2,
        0x873D, 0x4733,
        0x90, 0x52, 0x9F, 0x83, 0xA7, 0x06, 0xCA, 0x5B))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopLeftY,ParameterDef_PinTopLeftY,"",""), 
      // {29E4D78F-A502-4EBB-8C07-ED5A0320C1B0}
      // 8C.07.ED.5A.03.20.C1.B0.29.E4.D7.8F.A5.02.4E.BB
      AAF_LITERAL_AUID(0x29E4D78F,
        0xA502, 0x4EBB,
        0x8C, 0x07, 0xED, 0x5A, 0x03, 0x20, 0xC1, 0xB0), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinTopLeftY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {29E4D78F-A502-4EBB-8C07-ED5A0320C1B0}
      // 8C.07.ED.5A.03.20.C1.B0.29.E4.D7.8F.A5.02.4E.BB
      AAF_LITERAL_AUID(0x29E4D78F,
        0xA502, 0x4EBB,
        0x8C, 0x07, 0xED, 0x5A, 0x03, 0x20, 0xC1, 0xB0))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopLeftY,ParameterDef_PinTopLeftY,"",""), 
      // {29E4D78F-A502-4EBB-8C07-ED5A0320C1B0}
      // 8C.07.ED.5A.03.20.C1.B0.29.E4.D7.8F.A5.02.4E.BB
      AAF_LITERAL_AUID(0x29E4D78F,
        0xA502, 0x4EBB,
        0x8C, 0x07, 0xED, 0x5A, 0x03, 0x20, 0xC1, 0xB0))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopRightX,ParameterDef_PinTopRightX,"",""), 
      // {A95296C0-1ED9-4925-8481-2096C72E818D}
      // 84.81.20.96.C7.2E.81.8D.A9.52.96.C0.1E.D9.49.25
      AAF_LITERAL_AUID(0xA95296C0,
        0x1ED9, 0x4925,
        0x84, 0x81, 0x20, 0x96, 0xC7, 0x2E, 0x81, 0x8D), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinTopRightX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {A95296C0-1ED9-4925-8481-2096C72E818D}
      // 84.81.20.96.C7.2E.81.8D.A9.52.96.C0.1E.D9.49.25
      AAF_LITERAL_AUID(0xA95296C0,
        0x1ED9, 0x4925,
        0x84, 0x81, 0x20, 0x96, 0xC7, 0x2E, 0x81, 0x8D))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopRightX,ParameterDef_PinTopRightX,"",""), 
      // {A95296C0-1ED9-4925-8481-2096C72E818D}
      // 84.81.20.96.C7.2E.81.8D.A9.52.96.C0.1E.D9.49.25
      AAF_LITERAL_AUID(0xA95296C0,
        0x1ED9, 0x4925,
        0x84, 0x81, 0x20, 0x96, 0xC7, 0x2E, 0x81, 0x8D))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopRightY,ParameterDef_PinTopRightY,"",""), 
      // {CE1757AE-7A0B-45D9-B3F3-3686ADFF1E2D}
      // B3.F3.36.86.AD.FF.1E.2D.CE.17.57.AE.7A.0B.45.D9
      AAF_LITERAL_AUID(0xCE1757AE,
        0x7A0B, 0x45D9,
        0xB3, 0xF3, 0x36, 0x86, 0xAD, 0xFF, 0x1E, 0x2D), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinTopRightY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {CE1757AE-7A0B-45D9-B3F3-3686ADFF1E2D}
      // B3.F3.36.86.AD.FF.1E.2D.CE.17.57.AE.7A.0B.45.D9
      AAF_LITERAL_AUID(0xCE1757AE,
        0x7A0B, 0x45D9,
        0xB3, 0xF3, 0x36, 0x86, 0xAD, 0xFF, 0x1E, 0x2D))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinTopRightY,ParameterDef_PinTopRightY,"",""), 
      // {CE1757AE-7A0B-45D9-B3F3-3686ADFF1E2D}
      // B3.F3.36.86.AD.FF.1E.2D.CE.17.57.AE.7A.0B.45.D9
      AAF_LITERAL_AUID(0xCE1757AE,
        0x7A0B, 0x45D9,
        0xB3, 0xF3, 0x36, 0x86, 0xAD, 0xFF, 0x1E, 0x2D))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomLeftX,ParameterDef_PinBottomLeftX,"",""), 
      // {08B2BC81-9B1B-4C01-BA73-BBA3554ED029}
      // BA.73.BB.A3.55.4E.D0.29.08.B2.BC.81.9B.1B.4C.01
      AAF_LITERAL_AUID(0x08B2BC81,
        0x9B1B, 0x4C01,
        0xBA, 0x73, 0xBB, 0xA3, 0x55, 0x4E, 0xD0, 0x29), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinBottomLeftX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {08B2BC81-9B1B-4C01-BA73-BBA3554ED029}
      // BA.73.BB.A3.55.4E.D0.29.08.B2.BC.81.9B.1B.4C.01
      AAF_LITERAL_AUID(0x08B2BC81,
        0x9B1B, 0x4C01,
        0xBA, 0x73, 0xBB, 0xA3, 0x55, 0x4E, 0xD0, 0x29))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomLeftX,ParameterDef_PinBottomLeftX,"",""), 
      // {08B2BC81-9B1B-4C01-BA73-BBA3554ED029}
      // BA.73.BB.A3.55.4E.D0.29.08.B2.BC.81.9B.1B.4C.01
      AAF_LITERAL_AUID(0x08B2BC81,
        0x9B1B, 0x4C01,
        0xBA, 0x73, 0xBB, 0xA3, 0x55, 0x4E, 0xD0, 0x29))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomLeftY,ParameterDef_PinBottomLeftY,"",""), 
      // {C163F2FF-CD83-4655-826E-3724AB7FA092}
      // 82.6E.37.24.AB.7F.A0.92.C1.63.F2.FF.CD.83.46.55
      AAF_LITERAL_AUID(0xC163F2FF,
        0xCD83, 0x4655,
        0x82, 0x6E, 0x37, 0x24, 0xAB, 0x7F, 0xA0, 0x92), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinBottomLeftY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {C163F2FF-CD83-4655-826E-3724AB7FA092}
      // 82.6E.37.24.AB.7F.A0.92.C1.63.F2.FF.CD.83.46.55
      AAF_LITERAL_AUID(0xC163F2FF,
        0xCD83, 0x4655,
        0x82, 0x6E, 0x37, 0x24, 0xAB, 0x7F, 0xA0, 0x92))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomLeftY,ParameterDef_PinBottomLeftY,"",""), 
      // {C163F2FF-CD83-4655-826E-3724AB7FA092}
      // 82.6E.37.24.AB.7F.A0.92.C1.63.F2.FF.CD.83.46.55
      AAF_LITERAL_AUID(0xC163F2FF,
        0xCD83, 0x4655,
        0x82, 0x6E, 0x37, 0x24, 0xAB, 0x7F, 0xA0, 0x92))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomRightX,ParameterDef_PinBottomRightX,"",""), 
      // {53BC5884-897F-479E-B833-191F8692100D}
      // B8.33.19.1F.86.92.10.0D.53.BC.58.84.89.7F.47.9E
      AAF_LITERAL_AUID(0x53BC5884,
        0x897F, 0x479E,
        0xB8, 0x33, 0x19, 0x1F, 0x86, 0x92, 0x10, 0x0D), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinBottomRightX")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {53BC5884-897F-479E-B833-191F8692100D}
      // B8.33.19.1F.86.92.10.0D.53.BC.58.84.89.7F.47.9E
      AAF_LITERAL_AUID(0x53BC5884,
        0x897F, 0x479E,
        0xB8, 0x33, 0x19, 0x1F, 0x86, 0x92, 0x10, 0x0D))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomRightX,ParameterDef_PinBottomRightX,"",""), 
      // {53BC5884-897F-479E-B833-191F8692100D}
      // B8.33.19.1F.86.92.10.0D.53.BC.58.84.89.7F.47.9E
      AAF_LITERAL_AUID(0x53BC5884,
        0x897F, 0x479E,
        0xB8, 0x33, 0x19, 0x1F, 0x86, 0x92, 0x10, 0x0D))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomRightY,ParameterDef_PinBottomRightY,"",""), 
      // {812FB15B-0B95-4406-878D-EFAA1CFFC129}
      // 87.8D.EF.AA.1C.FF.C1.29.81.2F.B1.5B.0B.95.44.06
      AAF_LITERAL_AUID(0x812FB15B,
        0x0B95, 0x4406,
        0x87, 0x8D, 0xEF, 0xAA, 0x1C, 0xFF, 0xC1, 0x29), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PinBottomRightY")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {812FB15B-0B95-4406-878D-EFAA1CFFC129}
      // 87.8D.EF.AA.1C.FF.C1.29.81.2F.B1.5B.0B.95.44.06
      AAF_LITERAL_AUID(0x812FB15B,
        0x0B95, 0x4406,
        0x87, 0x8D, 0xEF, 0xAA, 0x1C, 0xFF, 0xC1, 0x29))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PinBottomRightY,ParameterDef_PinBottomRightY,"",""), 
      // {812FB15B-0B95-4406-878D-EFAA1CFFC129}
      // 87.8D.EF.AA.1C.FF.C1.29.81.2F.B1.5B.0B.95.44.06
      AAF_LITERAL_AUID(0x812FB15B,
        0x0B95, 0x4406,
        0x87, 0x8D, 0xEF, 0xAA, 0x1C, 0xFF, 0xC1, 0x29))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_AlphaKeyInvertAlpha,ParameterDef_AlphaKeyInvertAlpha,"",""), 
      // {A2667F65-65D8-4ABF-A179-0B9B93413949}
      // A1.79.0B.9B.93.41.39.49.A2.66.7F.65.65.D8.4A.BF
      AAF_LITERAL_AUID(0xA2667F65,
        0x65D8, 0x4ABF,
        0xA1, 0x79, 0x0B, 0x9B, 0x93, 0x41, 0x39, 0x49), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_AlphaKeyInvertAlpha")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {A2667F65-65D8-4ABF-A179-0B9B93413949}
      // A1.79.0B.9B.93.41.39.49.A2.66.7F.65.65.D8.4A.BF
      AAF_LITERAL_AUID(0xA2667F65,
        0x65D8, 0x4ABF,
        0xA1, 0x79, 0x0B, 0x9B, 0x93, 0x41, 0x39, 0x49))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_AlphaKeyInvertAlpha,ParameterDef_AlphaKeyInvertAlpha,"",""), 
      // {A2667F65-65D8-4ABF-A179-0B9B93413949}
      // A1.79.0B.9B.93.41.39.49.A2.66.7F.65.65.D8.4A.BF
      AAF_LITERAL_AUID(0xA2667F65,
        0x65D8, 0x4ABF,
        0xA1, 0x79, 0x0B, 0x9B, 0x93, 0x41, 0x39, 0x49))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_LumKeyLevel,ParameterDef_LumKeyLevel,"",""), 
      // {21ED5B0F-B7A0-43BC-B779-C47F85BF6C4D}
      // B7.79.C4.7F.85.BF.6C.4D.21.ED.5B.0F.B7.A0.43.BC
      AAF_LITERAL_AUID(0x21ED5B0F,
        0xB7A0, 0x43BC,
        0xB7, 0x79, 0xC4, 0x7F, 0x85, 0xBF, 0x6C, 0x4D), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_LumKeyLevel")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {21ED5B0F-B7A0-43BC-B779-C47F85BF6C4D}
      // B7.79.C4.7F.85.BF.6C.4D.21.ED.5B.0F.B7.A0.43.BC
      AAF_LITERAL_AUID(0x21ED5B0F,
        0xB7A0, 0x43BC,
        0xB7, 0x79, 0xC4, 0x7F, 0x85, 0xBF, 0x6C, 0x4D))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_LumKeyLevel,ParameterDef_LumKeyLevel,"",""), 
      // {21ED5B0F-B7A0-43BC-B779-C47F85BF6C4D}
      // B7.79.C4.7F.85.BF.6C.4D.21.ED.5B.0F.B7.A0.43.BC
      AAF_LITERAL_AUID(0x21ED5B0F,
        0xB7A0, 0x43BC,
        0xB7, 0x79, 0xC4, 0x7F, 0x85, 0xBF, 0x6C, 0x4D))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_LumKeyClip,ParameterDef_LumKeyClip,"",""), 
      // {CBD39B25-3ECE-441E-BA2C-DA473AB5CC7C}
      // BA.2C.DA.47.3A.B5.CC.7C.CB.D3.9B.25.3E.CE.44.1E
      AAF_LITERAL_AUID(0xCBD39B25,
        0x3ECE, 0x441E,
        0xBA, 0x2C, 0xDA, 0x47, 0x3A, 0xB5, 0xCC, 0x7C), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_LumKeyClip")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {CBD39B25-3ECE-441E-BA2C-DA473AB5CC7C}
      // BA.2C.DA.47.3A.B5.CC.7C.CB.D3.9B.25.3E.CE.44.1E
      AAF_LITERAL_AUID(0xCBD39B25,
        0x3ECE, 0x441E,
        0xBA, 0x2C, 0xDA, 0x47, 0x3A, 0xB5, 0xCC, 0x7C))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_LumKeyClip,ParameterDef_LumKeyClip,"",""), 
      // {CBD39B25-3ECE-441E-BA2C-DA473AB5CC7C}
      // BA.2C.DA.47.3A.B5.CC.7C.CB.D3.9B.25.3E.CE.44.1E
      AAF_LITERAL_AUID(0xCBD39B25,
        0x3ECE, 0x441E,
        0xBA, 0x2C, 0xDA, 0x47, 0x3A, 0xB5, 0xCC, 0x7C))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_Amplitude,ParameterDef_Amplitude,"kAAFParameterDefAmplitude",""), 
      // {E4962321-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.21.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962321,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_Amplitude")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {E4962321-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.21.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962321,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_Amplitude,ParameterDef_Amplitude,"kAAFParameterDefAmplitude",""), 
      // {E4962321-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.21.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962321,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_Pan,ParameterDef_Pan,"kAAFParameterDefPan",""), 
      // {E4962322-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.22.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962322,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_Pan")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {E4962322-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.22.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962322,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_Pan,ParameterDef_Pan,"kAAFParameterDefPan",""), 
      // {E4962322-2267-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.E4.96.23.22.22.67.11.D3
      AAF_LITERAL_AUID(0xE4962322,
        0x2267, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_OutgoingLevel,ParameterDef_OutgoingLevel,"",""), 
      // {9E610007-1BE2-41E1-BB11-C95DE9964D03}
      // BB.11.C9.5D.E9.96.4D.03.9E.61.00.07.1B.E2.41.E1
      AAF_LITERAL_AUID(0x9E610007,
        0x1BE2, 0x41E1,
        0xBB, 0x11, 0xC9, 0x5D, 0xE9, 0x96, 0x4D, 0x03), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_OutgoingLevel")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9E610007-1BE2-41E1-BB11-C95DE9964D03}
      // BB.11.C9.5D.E9.96.4D.03.9E.61.00.07.1B.E2.41.E1
      AAF_LITERAL_AUID(0x9E610007,
        0x1BE2, 0x41E1,
        0xBB, 0x11, 0xC9, 0x5D, 0xE9, 0x96, 0x4D, 0x03))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_OutgoingLevel,ParameterDef_OutgoingLevel,"",""), 
      // {9E610007-1BE2-41E1-BB11-C95DE9964D03}
      // BB.11.C9.5D.E9.96.4D.03.9E.61.00.07.1B.E2.41.E1
      AAF_LITERAL_AUID(0x9E610007,
        0x1BE2, 0x41E1,
        0xBB, 0x11, 0xC9, 0x5D, 0xE9, 0x96, 0x4D, 0x03))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_IncomingLevel,ParameterDef_IncomingLevel,"",""), 
      // {48CEA642-A8F9-455B-82B3-86C814B797C7}
      // 82.B3.86.C8.14.B7.97.C7.48.CE.A6.42.A8.F9.45.5B
      AAF_LITERAL_AUID(0x48CEA642,
        0xA8F9, 0x455B,
        0x82, 0xB3, 0x86, 0xC8, 0x14, 0xB7, 0x97, 0xC7), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_IncomingLevel")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {48CEA642-A8F9-455B-82B3-86C814B797C7}
      // 82.B3.86.C8.14.B7.97.C7.48.CE.A6.42.A8.F9.45.5B
      AAF_LITERAL_AUID(0x48CEA642,
        0xA8F9, 0x455B,
        0x82, 0xB3, 0x86, 0xC8, 0x14, 0xB7, 0x97, 0xC7))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_IncomingLevel,ParameterDef_IncomingLevel,"",""), 
      // {48CEA642-A8F9-455B-82B3-86C814B797C7}
      // 82.B3.86.C8.14.B7.97.C7.48.CE.A6.42.A8.F9.45.5B
      AAF_LITERAL_AUID(0x48CEA642,
        0xA8F9, 0x455B,
        0x82, 0xB3, 0x86, 0xC8, 0x14, 0xB7, 0x97, 0xC7))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTESoft,ParameterDef_SMPTESoft,"kAAFParameterDefSMPTESoft",""), 
      // {9C894BA1-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A1.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA1,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTESoft")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA1-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A1.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA1,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTESoft,ParameterDef_SMPTESoft,"kAAFParameterDefSMPTESoft",""), 
      // {9C894BA1-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A1.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA1,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEBorder,ParameterDef_SMPTEBorder,"kAAFParameterDefSMPTEBorder",""), 
      // {9C894BA2-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A2.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA2,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEBorder")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA2-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A2.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA2,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEBorder,ParameterDef_SMPTEBorder,"kAAFParameterDefSMPTEBorder",""), 
      // {9C894BA2-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A2.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA2,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEPosition,ParameterDef_SMPTEPosition,"kAAFParameterDefSMPTEPosition",""), 
      // {9C894BA3-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A3.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA3,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEPosition")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA3-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A3.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA3,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEPosition,ParameterDef_SMPTEPosition,"kAAFParameterDefSMPTEPosition",""), 
      // {9C894BA3-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A3.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA3,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEModulator,ParameterDef_SMPTEModulator,"kAAFParameterDefSMPTEModulator",""), 
      // {9C894BA4-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A4.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA4,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEModulator")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA4-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A4.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA4,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEModulator,ParameterDef_SMPTEModulator,"kAAFParameterDefSMPTEModulator",""), 
      // {9C894BA4-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A4.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA4,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEShadow,ParameterDef_SMPTEShadow,"kAAFParameterDefSMPTEShadow",""), 
      // {9C894BA5-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A5.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA5,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEShadow")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA5-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A5.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA5,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEShadow,ParameterDef_SMPTEShadow,"kAAFParameterDefSMPTEShadow",""), 
      // {9C894BA5-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A5.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA5,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTETumble,ParameterDef_SMPTETumble,"kAAFParameterDefSMPTETumble",""), 
      // {9C894BA6-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A6.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA6,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTETumble")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA6-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A6.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA6,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTETumble,ParameterDef_SMPTETumble,"kAAFParameterDefSMPTETumble",""), 
      // {9C894BA6-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A6.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA6,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTESpotlight,ParameterDef_SMPTESpotlight,"kAAFParameterDefSMPTESpotlight",""), 
      // {9C894BA7-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A7.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA7,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTESpotlight")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA7-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A7.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA7,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTESpotlight,ParameterDef_SMPTESpotlight,"kAAFParameterDefSMPTESpotlight",""), 
      // {9C894BA7-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A7.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA7,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReplicationH,ParameterDef_SMPTEReplicationH,"kAAFParameterDefSMPTEReplicationH",""), 
      // {9C894BA8-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A8.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA8,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEReplicationH")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA8-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A8.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA8,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReplicationH,ParameterDef_SMPTEReplicationH,"kAAFParameterDefSMPTEReplicationH",""), 
      // {9C894BA8-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A8.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA8,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReplicationV,ParameterDef_SMPTEReplicationV,"kAAFParameterDefSMPTEReplicationV",""), 
      // {9C894BA9-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A9.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA9,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTEReplicationV")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BA9-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A9.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA9,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTEReplicationV,ParameterDef_SMPTEReplicationV,"kAAFParameterDefSMPTEReplicationV",""), 
      // {9C894BA9-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.A9.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BA9,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTECheckerboard,ParameterDef_SMPTECheckerboard,"kAAFParameterDefSMPTECheckerboard",""), 
      // {9C894BAA-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.AA.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BAA,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_SMPTECheckerboard")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9C894BAA-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.AA.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BAA,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_SMPTECheckerboard,ParameterDef_SMPTECheckerboard,"kAAFParameterDefSMPTECheckerboard",""), 
      // {9C894BAA-2277-11D3-8A4C-0050040EF7D2}
      // 8A.4C.00.50.04.0E.F7.D2.9C.89.4B.AA.22.77.11.D3
      AAF_LITERAL_AUID(0x9C894BAA,
        0x2277, 0x11D3,
        0x8A, 0x4C, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ParameterDefinition, AAF_SYMBOL(ParameterDef_PhaseOffset,ParameterDef_PhaseOffset,"kAAFParameterDefPhaseOffset",""), 
      // {5F1C2560-2415-11D3-8A4F-0050040EF7D2}
      // 8A.4F.00.50.04.0E.F7.D2.5F.1C.25.60.24.15.11.D3
      AAF_LITERAL_AUID(0x5F1C2560,
        0x2415, 0x11D3,
        0x8A, 0x4F, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ParameterDef_PhaseOffset")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5F1C2560-2415-11D3-8A4F-0050040EF7D2}
      // 8A.4F.00.50.04.0E.F7.D2.5F.1C.25.60.24.15.11.D3
      AAF_LITERAL_AUID(0x5F1C2560,
        0x2415, 0x11D3,
        0x8A, 0x4F, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(ParameterDefinition, AAF_SYMBOL(ParameterDef_PhaseOffset,ParameterDef_PhaseOffset,"kAAFParameterDefPhaseOffset",""), 
      // {5F1C2560-2415-11D3-8A4F-0050040EF7D2}
      // 8A.4F.00.50.04.0E.F7.D2.5F.1C.25.60.24.15.11.D3
      AAF_LITERAL_AUID(0x5F1C2560,
        0x2415, 0x11D3,
        0x8A, 0x4F, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
AAF_INSTANCE_GROUP_END(ParameterDefinitionInstances, ParameterDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(DataDefinitionInstances, DataDefinition)
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Picture,DataDef_Picture,"","Picture data"), 
      // {01030202-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.01.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01), "Picture data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Picture")
    AAF_INSTANCE_PROPERTY(Description, String, "Picture data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {01030202-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.01.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Picture,DataDef_Picture,"","Picture data"), 
      // {01030202-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.01.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_LegacyPicture,DataDef_LegacyPicture,"DDEF_Picture","Picture data (legacy)"), 
      // {6F3C8CE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.6F.3C.8C.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x6F3C8CE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "Picture data (legacy)")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_LegacyPicture")
    AAF_INSTANCE_PROPERTY(Description, String, "Picture data (legacy)")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {6F3C8CE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.6F.3C.8C.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x6F3C8CE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_LegacyPicture,DataDef_LegacyPicture,"DDEF_Picture","Picture data (legacy)"), 
      // {6F3C8CE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.6F.3C.8C.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x6F3C8CE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Matte,DataDef_Matte,"DDEF_Matte","Matte data"), 
      // {05CBA731-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.31.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA731,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "Matte data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Matte")
    AAF_INSTANCE_PROPERTY(Description, String, "Matte data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {05CBA731-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.31.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA731,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Matte,DataDef_Matte,"DDEF_Matte","Matte data"), 
      // {05CBA731-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.31.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA731,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_PictureWithMatte,DataDef_PictureWithMatte,"DDEF_PictureWithMatte","Picture and Matte data"), 
      // {05CBA732-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.32.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA732,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "Picture and Matte data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_PictureWithMatte")
    AAF_INSTANCE_PROPERTY(Description, String, "Picture and Matte data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {05CBA732-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.32.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA732,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_PictureWithMatte,DataDef_PictureWithMatte,"DDEF_PictureWithMatte","Picture and Matte data"), 
      // {05CBA732-1DAA-11D3-80AD-006008143E6F}
      // 80.AD.00.60.08.14.3E.6F.05.CB.A7.32.1D.AA.11.D3
      AAF_LITERAL_AUID(0x05CBA732,
        0x1DAA, 0x11D3,
        0x80, 0xAD, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Sound,DataDef_Sound,"","Sound data"), 
      // {01030202-0200-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.02.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0200, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01), "Sound data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Sound")
    AAF_INSTANCE_PROPERTY(Description, String, "Sound data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {01030202-0200-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.02.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0200, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Sound,DataDef_Sound,"","Sound data"), 
      // {01030202-0200-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.02.02.00.00.00
      AAF_LITERAL_AUID(0x01030202,
        0x0200, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_LegacySound,DataDef_LegacySound,"DDEF_Sound","Sound data (legacy)"), 
      // {78E1EBE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.78.E1.EB.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x78E1EBE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "Sound data (legacy)")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_LegacySound")
    AAF_INSTANCE_PROPERTY(Description, String, "Sound data (legacy)")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {78E1EBE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.78.E1.EB.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x78E1EBE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_LegacySound,DataDef_LegacySound,"DDEF_Sound","Sound data (legacy)"), 
      // {78E1EBE1-6CEF-11D2-807D-006008143E6F}
      // 80.7D.00.60.08.14.3E.6F.78.E1.EB.E1.6C.EF.11.D2
      AAF_LITERAL_AUID(0x78E1EBE1,
        0x6CEF, 0x11D2,
        0x80, 0x7D, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Timecode,DataDef_Timecode,"","Timecode data"), 
      // {01030201-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.01.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01), "Timecode data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Timecode")
    AAF_INSTANCE_PROPERTY(Description, String, "Timecode data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {01030201-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.01.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Timecode,DataDef_Timecode,"","Timecode data"), 
      // {01030201-0100-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.01.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_LegacyTimecode,DataDef_LegacyTimecode,"DDEF_Timecode","Timecode data (legacy)"), 
      // {7F275E81-77E5-11D2-807F-006008143E6F}
      // 80.7F.00.60.08.14.3E.6F.7F.27.5E.81.77.E5.11.D2
      AAF_LITERAL_AUID(0x7F275E81,
        0x77E5, 0x11D2,
        0x80, 0x7F, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "Timecode data (legacy)")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_LegacyTimecode")
    AAF_INSTANCE_PROPERTY(Description, String, "Timecode data (legacy)")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {7F275E81-77E5-11D2-807F-006008143E6F}
      // 80.7F.00.60.08.14.3E.6F.7F.27.5E.81.77.E5.11.D2
      AAF_LITERAL_AUID(0x7F275E81,
        0x77E5, 0x11D2,
        0x80, 0x7F, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_LegacyTimecode,DataDef_LegacyTimecode,"DDEF_Timecode","Timecode data (legacy)"), 
      // {7F275E81-77E5-11D2-807F-006008143E6F}
      // 80.7F.00.60.08.14.3E.6F.7F.27.5E.81.77.E5.11.D2
      AAF_LITERAL_AUID(0x7F275E81,
        0x77E5, 0x11D2,
        0x80, 0x7F, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Edgecode,DataDef_Edgecode,"DDEF_Edgecode","Edgecode data"), 
      // {D2BB2AF0-D234-11D2-89EE-006097116212}
      // 89.EE.00.60.97.11.62.12.D2.BB.2A.F0.D2.34.11.D2
      AAF_LITERAL_AUID(0xD2BB2AF0,
        0xD234, 0x11D2,
        0x89, 0xEE, 0x00, 0x60, 0x97, 0x11, 0x62, 0x12), "Edgecode data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Edgecode")
    AAF_INSTANCE_PROPERTY(Description, String, "Edgecode data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {D2BB2AF0-D234-11D2-89EE-006097116212}
      // 89.EE.00.60.97.11.62.12.D2.BB.2A.F0.D2.34.11.D2
      AAF_LITERAL_AUID(0xD2BB2AF0,
        0xD234, 0x11D2,
        0x89, 0xEE, 0x00, 0x60, 0x97, 0x11, 0x62, 0x12))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Edgecode,DataDef_Edgecode,"DDEF_Edgecode","Edgecode data"), 
      // {D2BB2AF0-D234-11D2-89EE-006097116212}
      // 89.EE.00.60.97.11.62.12.D2.BB.2A.F0.D2.34.11.D2
      AAF_LITERAL_AUID(0xD2BB2AF0,
        0xD234, 0x11D2,
        0x89, 0xEE, 0x00, 0x60, 0x97, 0x11, 0x62, 0x12))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_DescriptiveMetadata,DataDef_DescriptiveMetadata,"","Descriptive metadata"), 
      // {01030201-1000-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.10.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x1000, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01), "Descriptive metadata")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_DescriptiveMetadata")
    AAF_INSTANCE_PROPERTY(Description, String, "Descriptive metadata")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {01030201-1000-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.10.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x1000, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_DescriptiveMetadata,DataDef_DescriptiveMetadata,"","Descriptive metadata"), 
      // {01030201-1000-0000-060E-2B3404010101}
      // 06.0E.2B.34.04.01.01.01.01.03.02.01.10.00.00.00
      AAF_LITERAL_AUID(0x01030201,
        0x1000, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x01))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Auxiliary,DataDef_Auxiliary,"","Auxiliary data"), 
      // {01030203-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.01.03.02.03.01.00.00.00
      AAF_LITERAL_AUID(0x01030203,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05), "Auxiliary data")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Auxiliary")
    AAF_INSTANCE_PROPERTY(Description, String, "Auxiliary data")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {01030203-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.01.03.02.03.01.00.00.00
      AAF_LITERAL_AUID(0x01030203,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Auxiliary,DataDef_Auxiliary,"","Auxiliary data"), 
      // {01030203-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.01.03.02.03.01.00.00.00
      AAF_LITERAL_AUID(0x01030203,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(DataDefinition, AAF_SYMBOL(DataDef_Unknown,DataDef_Unknown,"DDEF_Unknown","Data kind not known"), 
      // {851419D0-2E4F-11D3-8A5B-0050040EF7D2}
      // 8A.5B.00.50.04.0E.F7.D2.85.14.19.D0.2E.4F.11.D3
      AAF_LITERAL_AUID(0x851419D0,
        0x2E4F, 0x11D3,
        0x8A, 0x5B, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2), "Data kind not known")
    AAF_INSTANCE_PROPERTY(Name, String, "DataDef_Unknown")
    AAF_INSTANCE_PROPERTY(Description, String, "Data kind not known")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {851419D0-2E4F-11D3-8A5B-0050040EF7D2}
      // 8A.5B.00.50.04.0E.F7.D2.85.14.19.D0.2E.4F.11.D3
      AAF_LITERAL_AUID(0x851419D0,
        0x2E4F, 0x11D3,
        0x8A, 0x5B, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
  AAF_INSTANCE_END(DataDefinition, AAF_SYMBOL(DataDef_Unknown,DataDef_Unknown,"DDEF_Unknown","Data kind not known"), 
      // {851419D0-2E4F-11D3-8A5B-0050040EF7D2}
      // 8A.5B.00.50.04.0E.F7.D2.85.14.19.D0.2E.4F.11.D3
      AAF_LITERAL_AUID(0x851419D0,
        0x2E4F, 0x11D3,
        0x8A, 0x5B, 0x00, 0x50, 0x04, 0x0E, 0xF7, 0xD2))
AAF_INSTANCE_GROUP_END(DataDefinitionInstances, DataDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(ContainerDefinitionInstances, ContainerDefinition)
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_External,ContainerDef_External,"ContainerFile",""), 
      // {4313B572-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.72.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B572,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_External")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4313B572-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.72.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B572,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_External,ContainerDef_External,"ContainerFile",""), 
      // {4313B572-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.72.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B572,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_OMF,ContainerDef_OMF,"ContainerOMF",""), 
      // {4B1C1A46-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.46.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A46,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_OMF")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4B1C1A46-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.46.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A46,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_OMF,ContainerDef_OMF,"ContainerOMF",""), 
      // {4B1C1A46-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.46.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A46,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAF,ContainerDef_AAF,"ContainerAAF",""), 
      // {4313B571-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.71.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B571,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_AAF")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4313B571-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.71.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B571,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAF,ContainerDef_AAF,"ContainerAAF",""), 
      // {4313B571-D8BA-11D2-809B-0608143E6F}
      // 80.9B.0.60.8.14.3E.6F.43.13.B5.71.D8.BA.11.D2
      AAF_LITERAL_AUID(0x4313B571,
        0xD8BA, 0x11D2,
        0x80, 0x9B, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFMSS,ContainerDef_AAFMSS,"ContainerAAFMSS",""), 
      // {42464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.42.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x42464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_AAFMSS")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {42464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.42.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x42464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFMSS,ContainerDef_AAFMSS,"ContainerAAFMSS",""), 
      // {42464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.42.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x42464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFKLV,ContainerDef_AAFKLV,"ContainerAAFKLV",""), 
      // {4B464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.4B.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x4B464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_AAFKLV")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4B464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.4B.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x4B464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFKLV,ContainerDef_AAFKLV,"ContainerAAFKLV",""), 
      // {4B464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.4B.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x4B464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFXML,ContainerDef_AAFXML,"ContainerAAFXML",""), 
      // {58464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.58.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x58464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_AAFXML")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {58464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.58.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x58464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_AAFXML,ContainerDef_AAFXML,"ContainerAAFXML",""), 
      // {58464141-00D-4D4F-060E-2B3410101FF}
      // 06.0E.2B.34.1.01.01.FF.58.46.41.41.0.0D.4D.4F
      AAF_LITERAL_AUID(0x58464141,
        0x00D, 0x4D4F,
        0x06, 0x0E, 0x2B, 0x34, 0x1, 0x01, 0x01, 0xFF))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_RIFFWAVE,ContainerDef_RIFFWAVE,"",""), 
      // {0D011301-011-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.1.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x011, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_RIFFWAVE")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0D011301-011-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.1.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x011, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_RIFFWAVE,ContainerDef_RIFFWAVE,"",""), 
      // {0D011301-011-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.1.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x011, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_JFIF,ContainerDef_JFIF,"",""), 
      // {0D011301-012-200-060E-2B340401017}
      // 06.0E.2B.34.04.01.01.7.0D.01.13.01.01.2.2.00
      AAF_LITERAL_AUID(0x0D011301,
        0x012, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x7), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_JFIF")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0D011301-012-200-060E-2B340401017}
      // 06.0E.2B.34.04.01.01.7.0D.01.13.01.01.2.2.00
      AAF_LITERAL_AUID(0x0D011301,
        0x012, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x7))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_JFIF,ContainerDef_JFIF,"",""), 
      // {0D011301-012-200-060E-2B340401017}
      // 06.0E.2B.34.04.01.01.7.0D.01.13.01.01.2.2.00
      AAF_LITERAL_AUID(0x0D011301,
        0x012, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x7))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(ContainerDefinition, AAF_SYMBOL(ContainerDef_AIFFAIFC,ContainerDef_AIFFAIFC,"",""), 
      // {0D011301-014-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.4.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x014, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06), "")
    AAF_INSTANCE_PROPERTY(Name, String, "ContainerDef_AIFFAIFC")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0D011301-014-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.4.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x014, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06))
  AAF_INSTANCE_END(ContainerDefinition, AAF_SYMBOL(ContainerDef_AIFFAIFC,ContainerDef_AIFFAIFC,"",""), 
      // {0D011301-014-0100-060E-2B3404010106}
      // 06.0E.2B.34.04.01.01.06.0D.01.13.01.01.4.01.00
      AAF_LITERAL_AUID(0x0D011301,
        0x014, 0x0100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x06))
AAF_INSTANCE_GROUP_END(ContainerDefinitionInstances, ContainerDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(InterpolationDefinitionInstances, InterpolatorDefinition)
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_None,InterpolationDef_None,"NoInterpolator",""), 
      // {5B6C85A3-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A3.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A3,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_None")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5B6C85A3-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A3.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A3,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_None,InterpolationDef_None,"NoInterpolator",""), 
      // {5B6C85A3-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A3.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A3,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Linear,InterpolationDef_Linear,"LinearInterpolator",""), 
      // {5B6C85A4-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A4.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A4,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_Linear")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5B6C85A4-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A4.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A4,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Linear,InterpolationDef_Linear,"LinearInterpolator",""), 
      // {5B6C85A4-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A4.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A4,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Constant,InterpolationDef_Constant,"ConstantInterpolator",""), 
      // {5B6C85A5-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A5.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A5,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_Constant")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5B6C85A5-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A5.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A5,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Constant,InterpolationDef_Constant,"ConstantInterpolator",""), 
      // {5B6C85A5-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A5.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A5,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_BSpline,InterpolationDef_BSpline,"BSplineInterpolator",""), 
      // {5B6C85A6-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A6.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A6,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_BSpline")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {5B6C85A6-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A6.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A6,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_BSpline,InterpolationDef_BSpline,"BSplineInterpolator",""), 
      // {5B6C85A6-0EDE-11D3-80A9-006008143E6F}
      // 80.A9.00.60.08.14.3E.6F.5B.6C.85.A6.0E.DE.11.D3
      AAF_LITERAL_AUID(0x5B6C85A6,
        0x0EDE, 0x11D3,
        0x80, 0xA9, 0x00, 0x60, 0x08, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Log,InterpolationDef_Log,"LogInterpolator",""), 
      // {15829EC3-1F24-458A-960D-C65BB23C2AA1}
      // 96.0D.C6.5B.B2.3C.2A.A1.15.82.9E.C3.1F.24.45.8A
      AAF_LITERAL_AUID(0x15829EC3,
        0x1F24, 0x458A,
        0x96, 0x0D, 0xC6, 0x5B, 0xB2, 0x3C, 0x2A, 0xA1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_Log")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {15829EC3-1F24-458A-960D-C65BB23C2AA1}
      // 96.0D.C6.5B.B2.3C.2A.A1.15.82.9E.C3.1F.24.45.8A
      AAF_LITERAL_AUID(0x15829EC3,
        0x1F24, 0x458A,
        0x96, 0x0D, 0xC6, 0x5B, 0xB2, 0x3C, 0x2A, 0xA1))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Log,InterpolationDef_Log,"LogInterpolator",""), 
      // {15829EC3-1F24-458A-960D-C65BB23C2AA1}
      // 96.0D.C6.5B.B2.3C.2A.A1.15.82.9E.C3.1F.24.45.8A
      AAF_LITERAL_AUID(0x15829EC3,
        0x1F24, 0x458A,
        0x96, 0x0D, 0xC6, 0x5B, 0xB2, 0x3C, 0x2A, 0xA1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Power,InterpolationDef_Power,"PowerInterpolator",""), 
      // {C09153F7-BD18-4E5A-AD09-CBDD654FA001}
      // AD.09.CB.DD.65.4F.A0.01.C0.91.53.F7.BD.18.4E.5A
      AAF_LITERAL_AUID(0xC09153F7,
        0xBD18, 0x4E5A,
        0xAD, 0x09, 0xCB, 0xDD, 0x65, 0x4F, 0xA0, 0x01), "")
    AAF_INSTANCE_PROPERTY(Name, String, "InterpolationDef_Power")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {C09153F7-BD18-4E5A-AD09-CBDD654FA001}
      // AD.09.CB.DD.65.4F.A0.01.C0.91.53.F7.BD.18.4E.5A
      AAF_LITERAL_AUID(0xC09153F7,
        0xBD18, 0x4E5A,
        0xAD, 0x09, 0xCB, 0xDD, 0x65, 0x4F, 0xA0, 0x01))
  AAF_INSTANCE_END(InterpolationDefinition, AAF_SYMBOL(InterpolationDef_Power,InterpolationDef_Power,"PowerInterpolator",""), 
      // {C09153F7-BD18-4E5A-AD09-CBDD654FA001}
      // AD.09.CB.DD.65.4F.A0.01.C0.91.53.F7.BD.18.4E.5A
      AAF_LITERAL_AUID(0xC09153F7,
        0xBD18, 0x4E5A,
        0xAD, 0x09, 0xCB, 0xDD, 0x65, 0x4F, 0xA0, 0x01))
AAF_INSTANCE_GROUP_END(InterpolationDefinitionInstances, InterpolatorDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(OPDefinitionInstances, OPDefinition)
  AAF_INSTANCE(OPDefinition, AAF_SYMBOL(OPDef_EditProtocol,OPDef_EditProtocol,"","Operational Pattern for the AAF Edit Protocol"), 
      // {0D011201-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.0D.01.12.01.01.00.00.00
      AAF_LITERAL_AUID(0x0D011201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05), "Operational Pattern for the AAF Edit Protocol")
    AAF_INSTANCE_PROPERTY(Name, String, "OPDef_EditProtocol")
    AAF_INSTANCE_PROPERTY(Description, String, "Operational Pattern for the AAF Edit Protocol")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {0D011201-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.0D.01.12.01.01.00.00.00
      AAF_LITERAL_AUID(0x0D011201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05))
  AAF_INSTANCE_END(OPDefinition, AAF_SYMBOL(OPDef_EditProtocol,OPDef_EditProtocol,"","Operational Pattern for the AAF Edit Protocol"), 
      // {0D011201-0100-0000-060E-2B3404010105}
      // 06.0E.2B.34.04.01.01.05.0D.01.12.01.01.00.00.00
      AAF_LITERAL_AUID(0x0D011201,
        0x0100, 0x0000,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x05))
AAF_INSTANCE_GROUP_END(OPDefinitionInstances, OPDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(KLVDataDefinitionInstances, KLVDataDefinition)
AAF_INSTANCE_GROUP_END(KLVDataDefinitionInstances, KLVDataDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(TaggedValueDefinitionInstances, TaggedValueDefinition)
AAF_INSTANCE_GROUP_END(TaggedValueDefinitionInstances, TaggedValueDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(PluginDefinitionInstances, PluginDefinition)
  AAF_INSTANCE(PluginDefinition, AAF_SYMBOL(Platform_Independent,Platform_Independent,"kAAFPlatformIndependant",""), 
      // {3D1DD891-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.3D.1D.D8.91.E7.93.11.D2
      AAF_LITERAL_AUID(0x3D1DD891,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "Platform_Independent")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {3D1DD891-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.3D.1D.D8.91.E7.93.11.D2
      AAF_LITERAL_AUID(0x3D1DD891,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(PluginDefinition, AAF_SYMBOL(Platform_Independent,Platform_Independent,"kAAFPlatformIndependant",""), 
      // {3D1DD891-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.3D.1D.D8.91.E7.93.11.D2
      AAF_LITERAL_AUID(0x3D1DD891,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(PluginDefinition, AAF_SYMBOL(Engine_None,Engine_None,"kAAFNoEngine",""), 
      // {9FDEF8C1-E847-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.9F.DE.F8.C1.E8.47.11.D2
      AAF_LITERAL_AUID(0x9FDEF8C1,
        0xE847, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "Engine_None")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {9FDEF8C1-E847-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.9F.DE.F8.C1.E8.47.11.D2
      AAF_LITERAL_AUID(0x9FDEF8C1,
        0xE847, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(PluginDefinition, AAF_SYMBOL(Engine_None,Engine_None,"kAAFNoEngine",""), 
      // {9FDEF8C1-E847-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.9F.DE.F8.C1.E8.47.11.D2
      AAF_LITERAL_AUID(0x9FDEF8C1,
        0xE847, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(PluginDefinition, AAF_SYMBOL(PluginAPI_EssenceAccess,PluginAPI_EssenceAccess,"kAAFEssencePluginAPI",""), 
      // {69C870A1-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.69.C8.70.A1.E7.93.11.D2
      AAF_LITERAL_AUID(0x69C870A1,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "PluginAPI_EssenceAccess")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {69C870A1-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.69.C8.70.A1.E7.93.11.D2
      AAF_LITERAL_AUID(0x69C870A1,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(PluginDefinition, AAF_SYMBOL(PluginAPI_EssenceAccess,PluginAPI_EssenceAccess,"kAAFEssencePluginAPI",""), 
      // {69C870A1-E793-11D2-809E-0608143E6F}
      // 80.9E.0.60.8.14.3E.6F.69.C8.70.A1.E7.93.11.D2
      AAF_LITERAL_AUID(0x69C870A1,
        0xE793, 0x11D2,
        0x80, 0x9E, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(PluginDefinition, AAF_SYMBOL(PluginCategory_Codec,PluginCategory_Codec,"kAAFPluginNoCategory",""), 
      // {56905E0B-537D-11D4-A36C-09027DFCA6A}
      // A3.6C.0.90.27.DF.CA.6A.56.90.5E.0B.53.7D.11.D4
      AAF_LITERAL_AUID(0x56905E0B,
        0x537D, 0x11D4,
        0xA3, 0x6C, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A), "")
    AAF_INSTANCE_PROPERTY(Name, String, "PluginCategory_Codec")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {56905E0B-537D-11D4-A36C-09027DFCA6A}
      // A3.6C.0.90.27.DF.CA.6A.56.90.5E.0B.53.7D.11.D4
      AAF_LITERAL_AUID(0x56905E0B,
        0x537D, 0x11D4,
        0xA3, 0x6C, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
  AAF_INSTANCE_END(PluginDefinition, AAF_SYMBOL(PluginCategory_Codec,PluginCategory_Codec,"kAAFPluginNoCategory",""), 
      // {56905E0B-537D-11D4-A36C-09027DFCA6A}
      // A3.6C.0.90.27.DF.CA.6A.56.90.5E.0B.53.7D.11.D4
      AAF_LITERAL_AUID(0x56905E0B,
        0x537D, 0x11D4,
        0xA3, 0x6C, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
AAF_INSTANCE_GROUP_END(PluginDefinitionInstances, PluginDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(CodecDefinitionInstances, CodecDefinition)
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_None,CodecDef_None,"kAAFNoCodec",""), 
      // {568FB761-9458-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.56.8F.B7.61.94.58.11.D2
      AAF_LITERAL_AUID(0x568FB761,
        0x9458, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_None")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {568FB761-9458-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.56.8F.B7.61.94.58.11.D2
      AAF_LITERAL_AUID(0x568FB761,
        0x9458, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_None,CodecDef_None,"kAAFNoCodec",""), 
      // {568FB761-9458-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.56.8F.B7.61.94.58.11.D2
      AAF_LITERAL_AUID(0x568FB761,
        0x9458, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_PCM,CodecDef_PCM,"kAAFCodecPCM",""), 
      // {90AC17C8-E3E2-4596-9E9E-A6DD1C70C892}
      // 9E.9E.A6.DD.1C.70.C8.92.90.AC.17.C8.E3.E2.45.96
      AAF_LITERAL_AUID(0x90AC17C8,
        0xE3E2, 0x4596,
        0x9E, 0x9E, 0xA6, 0xDD, 0x1C, 0x70, 0xC8, 0x92), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_PCM")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {90AC17C8-E3E2-4596-9E9E-A6DD1C70C892}
      // 9E.9E.A6.DD.1C.70.C8.92.90.AC.17.C8.E3.E2.45.96
      AAF_LITERAL_AUID(0x90AC17C8,
        0xE3E2, 0x4596,
        0x9E, 0x9E, 0xA6, 0xDD, 0x1C, 0x70, 0xC8, 0x92))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_PCM,CodecDef_PCM,"kAAFCodecPCM",""), 
      // {90AC17C8-E3E2-4596-9E9E-A6DD1C70C892}
      // 9E.9E.A6.DD.1C.70.C8.92.90.AC.17.C8.E3.E2.45.96
      AAF_LITERAL_AUID(0x90AC17C8,
        0xE3E2, 0x4596,
        0x9E, 0x9E, 0xA6, 0xDD, 0x1C, 0x70, 0xC8, 0x92))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_WAVE,CodecDef_WAVE,"kAAFCodecWAVE",""), 
      // {820F9B1-EB9B-11D2-809F-0608143E6F}
      // 80.9F.0.60.8.14.3E.6F.82.0F.9.B1.EB.9B.11.D2
      AAF_LITERAL_AUID(0x820F9B1,
        0xEB9B, 0x11D2,
        0x80, 0x9F, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_WAVE")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {820F9B1-EB9B-11D2-809F-0608143E6F}
      // 80.9F.0.60.8.14.3E.6F.82.0F.9.B1.EB.9B.11.D2
      AAF_LITERAL_AUID(0x820F9B1,
        0xEB9B, 0x11D2,
        0x80, 0x9F, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_WAVE,CodecDef_WAVE,"kAAFCodecWAVE",""), 
      // {820F9B1-EB9B-11D2-809F-0608143E6F}
      // 80.9F.0.60.8.14.3E.6F.82.0F.9.B1.EB.9B.11.D2
      AAF_LITERAL_AUID(0x820F9B1,
        0xEB9B, 0x11D2,
        0x80, 0x9F, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_AIFC,CodecDef_AIFC,"kAAFCODEC_AIFC",""), 
      // {4B1C1A45-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.45.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A45,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_AIFC")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4B1C1A45-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.45.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A45,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_AIFC,CodecDef_AIFC,"kAAFCODEC_AIFC",""), 
      // {4B1C1A45-3F2-11D4-80FB-0608143E6F}
      // 80.FB.0.60.8.14.3E.6F.4B.1C.1A.45.3.F2.11.D4
      AAF_LITERAL_AUID(0x4B1C1A45,
        0x3F2, 0x11D4,
        0x80, 0xFB, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_JPEG,CodecDef_JPEG,"kAAFCodecJPEG",""), 
      // {18634F8C-3BAB-11D3-BFD6-0104BC9156D}
      // BF.D6.0.10.4B.C9.15.6D.18.63.4F.8C.3B.AB.11.D3
      AAF_LITERAL_AUID(0x18634F8C,
        0x3BAB, 0x11D3,
        0xBF, 0xD6, 0x0, 0x10, 0x4B, 0xC9, 0x15, 0x6D), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_JPEG")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {18634F8C-3BAB-11D3-BFD6-0104BC9156D}
      // BF.D6.0.10.4B.C9.15.6D.18.63.4F.8C.3B.AB.11.D3
      AAF_LITERAL_AUID(0x18634F8C,
        0x3BAB, 0x11D3,
        0xBF, 0xD6, 0x0, 0x10, 0x4B, 0xC9, 0x15, 0x6D))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_JPEG,CodecDef_JPEG,"kAAFCodecJPEG",""), 
      // {18634F8C-3BAB-11D3-BFD6-0104BC9156D}
      // BF.D6.0.10.4B.C9.15.6D.18.63.4F.8C.3B.AB.11.D3
      AAF_LITERAL_AUID(0x18634F8C,
        0x3BAB, 0x11D3,
        0xBF, 0xD6, 0x0, 0x10, 0x4B, 0xC9, 0x15, 0x6D))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_CDCI,CodecDef_CDCI,"kAAFCodecCDCI",""), 
      // {4E8445E-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5E.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445E,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_CDCI")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4E8445E-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5E.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445E,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_CDCI,CodecDef_CDCI,"kAAFCodecCDCI",""), 
      // {4E8445E-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5E.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445E,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecDef_RGBA,CodecDef_RGBA,"kAAFCodecRGBA",""), 
      // {4E8445F-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5F.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445F,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecDef_RGBA")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4E8445F-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5F.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445F,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecDef_RGBA,CodecDef_RGBA,"kAAFCodecRGBA",""), 
      // {4E8445F-0F29-11D4-A359-09027DFCA6A}
      // A3.59.0.90.27.DF.CA.6A.4E.84.4.5F.0F.29.11.D4
      AAF_LITERAL_AUID(0x4E8445F,
        0x0F29, 0x11D4,
        0xA3, 0x59, 0x0, 0x90, 0x27, 0xDF, 0xCA, 0x6A))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_None,CodecFlavour_None,"kAAFNilCodecFlavour",""), 
      // {1B31F3B1-9450-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.1B.31.F3.B1.94.50.11.D2
      AAF_LITERAL_AUID(0x1B31F3B1,
        0x9450, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_None")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {1B31F3B1-9450-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.1B.31.F3.B1.94.50.11.D2
      AAF_LITERAL_AUID(0x1B31F3B1,
        0x9450, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_None,CodecFlavour_None,"kAAFNilCodecFlavour",""), 
      // {1B31F3B1-9450-11D2-8089-0608143E6F}
      // 80.89.0.60.8.14.3E.6F.1B.31.F3.B1.94.50.11.D2
      AAF_LITERAL_AUID(0x1B31F3B1,
        0x9450, 0x11D2,
        0x80, 0x89, 0x0, 0x60, 0x8, 0x14, 0x3E, 0x6F))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_LegacyDV_625_50,CodecFlavour_LegacyDV_625_50,"",""), 
      // {AF4DE587-23D7-4C7C-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7C
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7C,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_LegacyDV_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C7C-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7C
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7C,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_LegacyDV_625_50,CodecFlavour_LegacyDV_625_50,"",""), 
      // {AF4DE587-23D7-4C7C-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7C
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7C,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_LegacyDV_525_60,CodecFlavour_LegacyDV_525_60,"",""), 
      // {AF4DE587-23D7-4C7D-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7D
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7D,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_LegacyDV_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C7D-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7D
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7D,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_LegacyDV_525_60,CodecFlavour_LegacyDV_525_60,"",""), 
      // {AF4DE587-23D7-4C7D-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7D
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7D,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_IEC_DV_625_50,CodecFlavour_IEC_DV_625_50,"",""), 
      // {AF4DE587-23D7-4C7E-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7E
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7E,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_IEC_DV_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C7E-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7E
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7E,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_IEC_DV_625_50,CodecFlavour_IEC_DV_625_50,"",""), 
      // {AF4DE587-23D7-4C7E-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7E
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7E,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_IEC_DV_525_60,CodecFlavour_IEC_DV_525_60,"",""), 
      // {AF4DE587-23D7-4C7F-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7F
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7F,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_IEC_DV_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C7F-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7F
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7F,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_IEC_DV_525_60,CodecFlavour_IEC_DV_525_60,"",""), 
      // {AF4DE587-23D7-4C7F-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.7F
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C7F,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_25Mbps_525_60,CodecFlavour_DV_Based_25Mbps_525_60,"",""), 
      // {AF4DE587-23D7-4C80-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.80
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C80,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_DV_Based_25Mbps_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C80-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.80
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C80,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_25Mbps_525_60,CodecFlavour_DV_Based_25Mbps_525_60,"",""), 
      // {AF4DE587-23D7-4C80-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.80
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C80,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_25Mbps_625_50,CodecFlavour_DV_Based_25Mbps_625_50,"",""), 
      // {AF4DE587-23D7-4C81-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.81
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C81,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_DV_Based_25Mbps_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C81-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.81
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C81,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_25Mbps_625_50,CodecFlavour_DV_Based_25Mbps_625_50,"",""), 
      // {AF4DE587-23D7-4C81-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.81
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C81,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_50Mbps_525_60,CodecFlavour_DV_Based_50Mbps_525_60,"",""), 
      // {AF4DE587-23D7-4C82-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.82
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C82,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_DV_Based_50Mbps_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C82-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.82
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C82,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_50Mbps_525_60,CodecFlavour_DV_Based_50Mbps_525_60,"",""), 
      // {AF4DE587-23D7-4C82-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.82
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C82,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_50Mbps_625_50,CodecFlavour_DV_Based_50Mbps_625_50,"",""), 
      // {AF4DE587-23D7-4C83-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.83
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C83,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CodecFlavour_DV_Based_50Mbps_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {AF4DE587-23D7-4C83-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.83
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C83,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
  AAF_INSTANCE_END(CodecDefinition, AAF_SYMBOL(CodecFlavour_DV_Based_50Mbps_625_50,CodecFlavour_DV_Based_50Mbps_625_50,"",""), 
      // {AF4DE587-23D7-4C83-B37B-C1C13870E711}
      // B3.7B.C1.C1.38.70.E7.11.AF.4D.E5.87.23.D7.4C.83
      AAF_LITERAL_AUID(0xAF4DE587,
        0x23D7, 0x4C83,
        0xB3, 0x7B, 0xC1, 0xC1, 0x38, 0x70, 0xE7, 0x11))
AAF_INSTANCE_GROUP_END(CodecDefinitionInstances, CodecDefinition)
AAF_INSTANCE_GROUP_SEPARATOR()
AAF_INSTANCE_GROUP(CompressionDefinitionInstances, CompressionDefinition)
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_AAF_CMPR_FULL_JPEG,CompressionDef_AAF_CMPR_FULL_JPEG,"AAF_CMPR_FULL_JPEG",""), 
      // {EDB35383-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.83.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35383,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_AAF_CMPR_FULL_JPEG")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {EDB35383-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.83.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35383,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_AAF_CMPR_FULL_JPEG,CompressionDef_AAF_CMPR_FULL_JPEG,"AAF_CMPR_FULL_JPEG",""), 
      // {EDB35383-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.83.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35383,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_AAF_CMPR_AUNC422,CompressionDef_AAF_CMPR_AUNC422,"AAF_CMPR_AUNC422",""), 
      // {EDB35391-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.91.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35391,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_AAF_CMPR_AUNC422")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {EDB35391-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.91.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35391,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_AAF_CMPR_AUNC422,CompressionDef_AAF_CMPR_AUNC422,"AAF_CMPR_AUNC422",""), 
      // {EDB35391-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.91.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35391,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_LegacyDV,CompressionDef_LegacyDV,"",""), 
      // {EDB35390-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.90.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35390,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_LegacyDV")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {EDB35390-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.90.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35390,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_LegacyDV,CompressionDef_LegacyDV,"",""), 
      // {EDB35390-6D30-11D3-A036-06094EB75CB}
      // A0.36.0.60.94.EB.75.CB.ED.B3.53.90.6D.30.11.D3
      AAF_LITERAL_AUID(0xEDB35390,
        0x6D30, 0x11D3,
        0xA0, 0x36, 0x0, 0x60, 0x94, 0xEB, 0x75, 0xCB))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_IEC_DV_525_60,CompressionDef_IEC_DV_525_60,"",""), 
      // {4122-21-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.1.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_IEC_DV_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-21-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.1.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_IEC_DV_525_60,CompressionDef_IEC_DV_525_60,"",""), 
      // {4122-21-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.1.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_IEC_DV_625_50,CompressionDef_IEC_DV_625_50,"",""), 
      // {4122-21-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.2.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_IEC_DV_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-21-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.2.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_IEC_DV_625_50,CompressionDef_IEC_DV_625_50,"",""), 
      // {4122-21-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.1.2.00
      AAF_LITERAL_AUID(0x4122,
        0x21, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_25Mbps_525_60,CompressionDef_DV_Based_25Mbps_525_60,"",""), 
      // {4122-22-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.1.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_DV_Based_25Mbps_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-22-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.1.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_25Mbps_525_60,CompressionDef_DV_Based_25Mbps_525_60,"",""), 
      // {4122-22-100-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.1.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x100,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_25Mbps_625_50,CompressionDef_DV_Based_25Mbps_625_50,"",""), 
      // {4122-22-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.2.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_DV_Based_25Mbps_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-22-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.2.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_25Mbps_625_50,CompressionDef_DV_Based_25Mbps_625_50,"",""), 
      // {4122-22-200-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.2.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x200,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_50Mbps_525_60,CompressionDef_DV_Based_50Mbps_525_60,"",""), 
      // {4122-22-300-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.3.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x300,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_DV_Based_50Mbps_525_60")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-22-300-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.3.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x300,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_50Mbps_525_60,CompressionDef_DV_Based_50Mbps_525_60,"",""), 
      // {4122-22-300-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.3.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x300,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_SEPARATOR()
  AAF_INSTANCE(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_50Mbps_625_50,CompressionDef_DV_Based_50Mbps_625_50,"",""), 
      // {4122-22-400-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.4.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x400,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1), "")
    AAF_INSTANCE_PROPERTY(Name, String, "CompressionDef_DV_Based_50Mbps_625_50")
    AAF_INSTANCE_PROPERTY(Identification, AUID, 
      // {4122-22-400-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.4.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x400,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
  AAF_INSTANCE_END(CompressionDefinition, AAF_SYMBOL(CompressionDef_DV_Based_50Mbps_625_50,CompressionDef_DV_Based_50Mbps_625_50,"",""), 
      // {4122-22-400-060E-2B340401011}
      // 06.0E.2B.34.04.01.01.1.4.1.2.2.2.2.4.00
      AAF_LITERAL_AUID(0x4122,
        0x22, 0x400,
        0x06, 0x0E, 0x2B, 0x34, 0x04, 0x01, 0x01, 0x1))
AAF_INSTANCE_GROUP_END(CompressionDefinitionInstances, CompressionDefinition)

AAF_INSTANCE_TABLE_END()

// Undefine all macros
//
#undef AAF_TABLE_BEGIN

#undef AAF_TABLE_END

#undef AAF_SYM

#undef AAF_SYMBOL

#undef AAF_CLASS

#undef AAF_CLASS_END

#undef AAF_CLASS_SEPARATOR

#undef AAF_PROPERTY

#undef AAF_TYPE

#undef AAF_REFERENCE_TYPE

#undef AAF_REFERENCE_TYPE_NAME

#undef AAF_LITERAL_AUID

#undef AAF_TYPE_TABLE_BEGIN

#undef AAF_TYPE_TABLE_END

#undef AAF_TYPE_DEFINITION_INTEGER

#undef AAF_TYPE_DEFINITION_ENUMERATION

#undef AAF_TYPE_DEFINITION_ENUMERATION_MEMBER

#undef AAF_TYPE_DEFINITION_ENUMERATION_END

#undef AAF_TYPE_DEFINITION_RECORD

#undef AAF_TYPE_DEFINITION_RECORD_FIELD

#undef AAF_TYPE_DEFINITION_RECORD_END

#undef AAF_TYPE_DEFINITION_VARYING_ARRAY

#undef AAF_TYPE_DEFINITION_FIXED_ARRAY

#undef AAF_TYPE_DEFINITION_RENAME

#undef AAF_TYPE_DEFINITION_STRING

#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION

#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_MEMBER

#undef AAF_TYPE_DEFINITION_EXTENDIBLE_ENUMERATION_END

#undef AAF_TYPE_DEFINITION_CHARACTER

#undef AAF_TYPE_DEFINITION_INDIRECT

#undef AAF_TYPE_DEFINITION_OPAQUE

#undef AAF_TYPE_DEFINITION_SET

#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE

#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE_SET

#undef AAF_TYPE_DEFINITION_STRONG_REFERENCE_VECTOR

#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE

#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_MEMBER

#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_END

#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_SET

#undef AAF_TYPE_DEFINITION_WEAK_REFERENCE_VECTOR

#undef AAF_TYPE_DEFINITION_STREAM

#undef AAF_TYPE_SEPARATOR

#undef AAF_ALIAS_TABLE_BEGIN

#undef AAF_ALIAS_TABLE_END

#undef AAF_ALIAS_SEPARATOR

#undef AAF_CLASS_ALIAS

#undef AAF_INSTANCE_TABLE_BEGIN

#undef AAF_INSTANCE_TABLE_END

#undef AAF_INSTANCE_GROUP_SEPARATOR

#undef AAF_INSTANCE_GROUP

#undef AAF_INSTANCE_GROUP_END

#undef AAF_INSTANCE_SEPARATOR

#undef AAF_INSTANCE

#undef AAF_INSTANCE_END

#undef AAF_INSTANCE_PROPERTY

#undef AAF_LITERAL_AUID

//
// End of automatically generated file.
