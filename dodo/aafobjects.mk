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
	AAFAIFCData \
	AAFDataDef \
	AAFJPEGData \
	AAFHTMLData \
	AAFImageData \
	AAFLocator \
	AAFMediaFilmDescriptor \
	AAFMediaGroup \
	AAFMIDIData \
	AAFMIDIFileDescriptor \
	AAFPluggableCode \
	AAFReferenceValue \
	AAFRGBADescriptor \
	AAFTaggedValue \
	AAFTextLocator \
	AAFTIFFData \
	AAFTimecodeStream \
	AAFTimecodeStream12M \
	AAFTypeDefSet \
	AAFWAVEData


# These are all of the other non-persistent objects:
AAFNONPERSISTENTOBJECTS = \
	AAFRoot \
	EnumAAFClassDefs \
	EnumAAFCodecFlavours \
	EnumAAFDataDefs \
	EnumAAFDefs \
	EnumAAFIdentifications \
	EnumAAFMobComments \
	EnumAAFObjects \
	EnumAAFPropertyDefs \
	EnumAAFPropertyValues \
	EnumAAFReferenceValues \
	EnumAAFTaggedValues 


# These are files which specify COM interfaces, but which are
# implemented in other objects.
AAFCOMINTERFACESONLY = \
	AAFEndian \
	AAFEssenceSampleStream \
	AAFInterpolator \
	AAFSearchSource

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
	AAFConstValue \
	AAFContainerDef \
	AAFContentStorage \
	AAFControlPoint \
	AAFDefObject \
	AAFDictionary \
	AAFEdgecode \
	AAFOperationDef \
	AAFEssenceAccess \
	AAFEssenceData \
	AAFEssenceDescriptor \
	AAFEssencePlugin \
	AAFEvent \
	AAFEventMobSlot \
	AAFFile \
	AAFFileDescriptor \
	AAFDigitalImageDescriptor \
	AAFCDCIDescriptor \
	AAFEssenceFormat \
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
	AAFMasterMob \
	AAFMob  \
	AAFMobSlot \
	AAFNestedScope\
	AAFNetworkLocator \
	AAFObject \
	AAFParameter \
	AAFParameterDef \
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
	AAFTimecode \
	AAFTimelineMobSlot \
	AAFTapeDescriptor \
	AAFTextClip \
	AAFTransition \
	AAFTIFFDescriptor \
	AAFTypeDef \
	AAFTypeDefInt \
	AAFTypeDefRename \
	AAFTypeDefEnum \
	AAFTypeDefFixedArray \
	AAFTypeDefRecord \
	AAFTypeDefStream \
	AAFTypeDefString \
	AAFTypeDefStrongObjRef \
	AAFTypeDefWeakObjRef \
	AAFTypeDefObjectRef \
	AAFTypeDefVariableArray \
	AAFVaryingValue \
	AAFWAVEDescriptor \
	EnumAAFCodecDefs \
	EnumAAFComponents \
	EnumAAFContainerDefs \
	EnumAAFControlPoints \
	EnumAAFInterpolationDefs \
	EnumAAFOperationDefs \
	EnumAAFEssenceData \
	EnumAAFLoadedPlugins \
	EnumAAFLocators \
	EnumAAFMobSlots \
	EnumAAFMobs \
	EnumAAFParameterDefs \
	EnumAAFProperties \
	EnumAAFPluginDescriptors \
	EnumAAFPluginLocators \
	EnumAAFSegments \
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
