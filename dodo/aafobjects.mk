#
#
# Advanced Authoring Format
#
# Copyright (c) 1998 Avid Technology, Inc.
#
#
# Place the object root name is this list if it is a "persistent"
# aaf object:
AAFPERSISTENTOBJECTS = \
	AAFMIDIFileDescriptor \
	AAFRGBADescriptor


# These are all of the other non-persistent objects:
AAFNONPERSISTENTOBJECTS = \
	EnumAAFPropertyValues


# These are files which specify COM interfaces, but which are
# implemented in other objects.
AAFCOMINTERFACESONLY = \
	AAFEndian \
	AAFSearchSource \
	AAFEssenceMultiAccess \
	AAFEssenceRawAccess

# These are the impl files that are typed by humans.  Be sure to
# remove them from the other list.  As you check each one in, just add
# its name here and remove it from either list above where it occurs.
# Do not add the 'Impl'prefix here.
HUMAN_TYPED_IMPL = \
	AAFAIFCDescriptor \
	AAFClassDef \
	AAFCodecDef \
	AAFCommentMarker \
	AAFComponent \
	AAFCompositionMob \
	AAFConstantValue \
	AAFContainerDef \
	AAFContentStorage \
	AAFControlPoint \
	AAFDataDef \
	AAFDefObject \
	AAFDictionary \
	AAFEdgecode \
	AAFOperationDef \
	AAFEssenceAccess \
	AAFEssenceData \
	AAFEssenceDescriptor \
	AAFEvent \
	AAFEventMobSlot \
	AAFFile \
	AAFFileDescriptor \
	AAFFilmDescriptor \
	AAFDigitalImageDescriptor \
	AAFCDCIDescriptor \
	AAFEssenceFormat \
	AAFEssenceGroup \
	AAFFiller \
	AAFFindSourceInfo \
	AAFOperationGroup \
	AAFGPITrigger \
	AAFHeader \
	AAFHTMLClip \
	AAFHTMLDescriptor \
	AAFIdentification \
	AAFInterpolationDef \
	AAFIntraFrameMarker \
	AAFLocator \
	AAFMasterMob \
	AAFMob  \
	AAFMobSlot \
	AAFNestedScope\
	AAFNetworkLocator \
	AAFObject \
	AAFParameter \
	AAFParameterDef \
	AAFPluggableCode \
	AAFProperty \
	AAFPropertyDef \
	AAFPropertyValue \
	AAFPropValData \
	AAFPluginDescriptor \
	AAFPluginManager \
	AAFPulldown \
	AAFScopeReference \
	AAFSegment \
	AAFSelector \
	AAFSequence \
	AAFSourceClip \
	AAFSourceMob \
	AAFSourceReference \
	AAFStaticMobSlot \
	AAFTapeDescriptor \
	AAFTaggedValue \
	AAFTextClip \
	AAFTextLocator \
	AAFTimecode \
	AAFTimelineMobSlot \
	AAFTransition \
	AAFTIFFDescriptor \
	AAFTimecodeStream \
	AAFTimecodeStream12M \
	AAFTypeDef \
	AAFTypeDefInt \
	AAFTypeDefRename \
	AAFTypeDefEnum \
	AAFTypeDefExtEnum \
	AAFTypeDefFixedArray \
	AAFTypeDefRecord \
	AAFTypeDefSet \
	AAFTypeDefStream \
	AAFTypeDefString \
	AAFTypeDefStrongObjRef \
	AAFTypeDefWeakObjRef \
	AAFTypeDefObjectRef \
	AAFTypeDefVariableArray \
	AAFVaryingValue \
	AAFWAVEDescriptor \
	EnumAAFClassDefs \
	EnumAAFCodecDefs \
	EnumAAFCodecFlavours \
	EnumAAFComponents \
	EnumAAFContainerDefs \
	EnumAAFControlPoints \
	EnumAAFDataDefs \
	EnumAAFIdentifications \
	EnumAAFInterpolationDefs \
	EnumAAFOperationDefs \
	EnumAAFEssenceData \
	EnumAAFLoadedPlugins \
	EnumAAFLocators \
	EnumAAFMobSlots \
	EnumAAFMobs \
	EnumAAFParameterDefs \
	EnumAAFParameters \
	EnumAAFProperties \
	EnumAAFPropertyDefs \
	EnumAAFPluginDescriptors \
	EnumAAFPluginLocators \
	EnumAAFSegments \
	EnumAAFTaggedValues \
	EnumAAFTypeDefs 

# The list of standard dodo targets.
# AAFTypes have to be handled separately since no object is to be created.
DODO_TARGET_NAMES = \
	$(AAFPERSISTENTOBJECTS) \
	$(AAFNONPERSISTENTOBJECTS) \
	$(HUMAN_TYPED_IMPL)


# Build the list of all objects that need to be built into the COM DLL
AAFOBJECTS = \
	$(AAFPERSISTENTOBJECTS) \
	$(AAFNONPERSISTENTOBJECTS) \
	$(HUMAN_TYPED_IMPL)


# Build the list of all objects that have automatically-generated
# implementation classes.
AUTO_GEN_IMPL = \
	$(AAFPERSISTENTOBJECTS) \
	$(AAFNONPERSISTENTOBJECTS)

#---------------------------------------------
# Build the list of all objects which are built into plugin.idl and
# NOT into AAF.idl.

PLUGIN_OBJECTS = \
	AAFPlugin \
	AAFEssenceStream \
	AAFEssenceDataStream \
	AAFEssenceCodec \
	AAFEssenceContainer \
	AAFInterpolator

# objects in PLUGIN_OBJECTS are NOT built into the main interface IDL
#---------------------------------------------
