// Copyright 2003 BBC Technology

// $Id: Aif2XtlParseTreeNodes.cpp,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#include <Aif2XtlParseTreeNodes.h>

#include <Aif2XtlParseTreeNodeFactory.h>
#include <Aif2XtlParseTreeVisitor.h>

#include <assert.h>

// This is called by Aif2XtlInit() simply to force a reference to this
// code.  Without it, the linker decides that this code is not used,
// doesn't link it into the executable, and the global contstructors
// that register the factories do not get executed.  Alternatively,
// the init routine itself could register the factories.  I don't
// think this problem would exist if the library was a dll (??).
void Aif2XtlParseTreeNodesInit()
{}

//------------------------------------------------------------------------------

Aif2XtlParseTreeNode::Aif2XtlParseTreeNode()
: AifParseTreeNode()
{}

Aif2XtlParseTreeNode::Aif2XtlParseTreeNode(IAAFObjectSP sp)
: AifParseTreeNode( sp )
{}

Aif2XtlParseTreeNode::~Aif2XtlParseTreeNode()
{}

void Aif2XtlParseTreeNode::Visit( AifParseTreeVisitor* pVisitor )
{
	Aif2XtlParseTreeVisitor* pXtlVisitor = dynamic_cast<Aif2XtlParseTreeVisitor*>(pVisitor);
	if (!pXtlVisitor) {
		AifParseTreeNode::Visit( pVisitor );
		return;
	}

	pXtlVisitor->PreOrderVisit( *this );
	VisitChildren( pVisitor );
	pXtlVisitor->PostOrderVisit( *this );
}

//------------------------------------------------------------------------------

template <class Type>
Aif2XtlStandardTypedNode<Type>::Aif2XtlStandardTypedNode()
: Aif2XtlParseTreeNode()
{}

template <class Type>
Aif2XtlStandardTypedNode<Type>::~Aif2XtlStandardTypedNode()
{}

template <class Type>
void Aif2XtlStandardTypedNode<Type>::Visit( AifParseTreeVisitor* pVisitor )
{
	Aif2XtlParseTreeVisitor* pXtlVisitor = dynamic_cast<Aif2XtlParseTreeVisitor*>(pVisitor);
	if (!pXtlVisitor) {
		AifParseTreeNode::Visit( pVisitor );
		return;
	}

	pXtlVisitor->PreOrderVisit( *this );
	VisitChildren( pVisitor );
	pXtlVisitor->PostOrderVisit( *this );
}


// Explicit template instances of type Aif2XtlStandardTypedNode
template class Aif2XtlStandardTypedNode<Aif2XtlGroup>;

//------------------------------------------------------------------------------

template <class IAAFType>
Aif2XtlStandardNode<IAAFType>::Aif2XtlStandardNode( IAAFSmartPointer<IAAFType> sp )
: Aif2XtlParseTreeNode( AxQueryInterface<IAAFType,IAAFObject>(sp) ),
  _sp( sp )
{}

template <class IAAFType>
Aif2XtlStandardNode<IAAFType>::~Aif2XtlStandardNode()
{}

template <class IAAFType>
IAAFSmartPointer<IAAFType> Aif2XtlStandardNode<IAAFType>::GetAif2XtlAAFObject()
{
	return _sp;
}

template <class IAAFType>
void Aif2XtlStandardNode<IAAFType>::Visit( AifParseTreeVisitor* pVisitor )
{
	Aif2XtlParseTreeVisitor* pXtlVisitor = dynamic_cast<Aif2XtlParseTreeVisitor*>(pVisitor);
	if (!pXtlVisitor) {
		AifParseTreeNode::Visit( pVisitor );
		return;
	}

	pXtlVisitor->PreOrderVisit( *this );
	VisitChildren( pVisitor );
	pXtlVisitor->PostOrderVisit( *this );
}


// Explicit template instances of type Aif2XtlStandardNode
template class Aif2XtlStandardNode<IAAFCompositionMob>;
template class Aif2XtlStandardNode<IAAFMasterMob>;
template class Aif2XtlStandardNode<IAAFTimelineMobSlot>;
template class Aif2XtlStandardNode<IAAFSequence>;
template class Aif2XtlStandardNode<IAAFSourceMob>;
template class Aif2XtlStandardNode<IAAFCDCIDescriptor>;
template class Aif2XtlStandardNode<IAAFWAVEDescriptor>;
template class Aif2XtlStandardNode<IAAFNetworkLocator>;
template class Aif2XtlStandardNode<IAAFTransition>;
template class Aif2XtlStandardNode<IAAFTaggedValue>;
template class Aif2XtlStandardNode<IAAFConstantValue>;

//------------------------------------------------------------------------------

// Each explicit instance of the Aif2XtlStandardNode above should have a factory object.
namespace {

Aif2XtlStandardNodeFactory<IAAFCompositionMob,	Aif2XtlCompMobNode>     aCompMobNodeFactory;
Aif2XtlStandardNodeFactory<IAAFSourceClip,	Aif2XtlSourceClipNode>	aSourceClipNodeFactory;
Aif2XtlStandardNodeFactory<IAAFTimelineMobSlot, Aif2XtlTimelineMobSlot>	aTimelineMobSlotFactory;
Aif2XtlStandardNodeFactory<IAAFSequence,	Aif2XtlSequence>        aSequenceFactory;
Aif2XtlStandardNodeFactory<IAAFMasterMob,	Aif2XtlMasterMob>       aMasterMobFactory;
Aif2XtlStandardNodeFactory<IAAFSourceMob,	Aif2XtlSourceMob>       aSourceMobFactory;
Aif2XtlStandardNodeFactory<IAAFCDCIDescriptor,	Aif2XtlCDCIDescriptor>  aCDCIDescriptorFactory;
Aif2XtlStandardNodeFactory<IAAFWAVEDescriptor,	Aif2XtlWaveDescriptor>  aWaveDescriptorFactory;
Aif2XtlStandardNodeFactory<IAAFNetworkLocator,  Aif2XtlNetworkLocator>  aNetworkLocatorFactory;
Aif2XtlStandardNodeFactory<IAAFTransition,      Aif2XtlTransition>      aTransitionFactory;
Aif2XtlStandardNodeFactory<IAAFTaggedValue,	Aif2XtlTaggedValue>	aTaggedValueFactory;
Aif2XtlStandardNodeFactory<IAAFConstantValue,	Aif2XtlConstantValue>	aConstantValueFactory;

} // end of namespace

//------------------------------------------------------------------------------

Aif2XtlSourceClipNode::Aif2XtlSourceClipNode( IAAFSourceClipSP sp )
:	AifParseTreeNode( AxQueryInterface<IAAFSourceClip,IAAFObject>(sp) ),
	_sp( sp ),
	_isChildSelected( false ),
	_selectedChild( -1 )
{}

Aif2XtlSourceClipNode::~Aif2XtlSourceClipNode()
{}

bool Aif2XtlSourceClipNode::IsChildSelected()
{
	return _isChildSelected;
}

void Aif2XtlSourceClipNode::SetSelectedChild( int selectedChild )
{
	assert( selectedChild < GetNumChildren() );
	_isChildSelected = true;
	_selectedChild = selectedChild;
}

int Aif2XtlSourceClipNode::GetSelectedChild()
{
	return _selectedChild;
}

void Aif2XtlSourceClipNode::Visit( AifParseTreeVisitor* pVisitor )
{
	Aif2XtlParseTreeVisitor* pXtlVisitor = dynamic_cast<Aif2XtlParseTreeVisitor*>(pVisitor);
	if (!pXtlVisitor) {
		AifParseTreeNode::Visit( pVisitor );
		return;
	}

	pXtlVisitor->PreOrderVisit( *this );

	if ( _isChildSelected ) {
		VisitChild( pVisitor, _selectedChild );
	}
	else {
		VisitChildren( pVisitor );
	}
	

	pXtlVisitor->PostOrderVisit( *this );
}

IAAFSourceClipSP Aif2XtlSourceClipNode::GetAif2XtlAAFObject()
{
	return _sp;
}


//------------------------------------------------------------------------------
