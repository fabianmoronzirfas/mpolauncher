//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchNodeID.h $
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2008/08/19 04:03:07 $
//  
//  $Revision: #1 $
//  
//  $Change: 643572 $
//  
//  Copyright 1997-2008 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//  
//  Each C++ implementation class in the plug-in and its corresponding ImplementationID
//  should be registered in this file.
//  
//========================================================================================

#ifndef __MPOLnchNodeID__
#define __MPOLnchNodeID__

#include "NodeID.h"
#include "IPMStream.h"
#include "MPOLnchID.h"

/** Represents a node in the tree view. It is the list item.
	
	@ingroup wlistboxcomposite
*/
class MPOLnchNodeID : public NodeIDClass
{
	public:
		enum { kNodeType = kMPOLnchListBoxWidgetBoss }; 


		/**	Factory method to create 
		new object of this class
			@return   new instance of this class 
		 */
		static	NodeID_rv Create() { return new MPOLnchNodeID(); }

		/**	Factory method to create new object of this class
			@param path [IN] specifies initial path
			@return  new instance of this class
		 */
		static	NodeID_rv Create(PMString name)  
			{ return new MPOLnchNodeID(name); }

		/**	Destructor
		 */
		virtual ~MPOLnchNodeID() {}
		

		/**	@return type of this node
		 */
		virtual	NodeType GetNodeType() const { return kNodeType; } 

		/**	Comparator function
			@param NodeID [IN] specifies the node that we should compare against
			@return  Comparison results
		 */
		virtual int32 Compare(const NodeIDClass* NodeID) const;

		/**	Create a copy of this
			@return  
		 */
		virtual NodeIDClass* Clone() const;

		/**	Read this from the given stream
			@param stream [IN] specified stream
			@return  
		 */
		virtual void Read(IPMStream* stream);

		/**	Write this to the given stream
			@param [OUT] stream 
			@return  
		 */
		virtual void Write(IPMStream* stream) const;

		/**	Accessor for the value associated with this node
			@return const PMString& 
		 */
		const PMString& GetName() const { return fName; }


	/**	Set the Name Of the Node An Associated Javascript
	 @param PMString
	 */
	//virtual void SetName(const PMString& newName) = 0;


	private:
		// Note we're keeping the destructor private to force use of the factory methods
		MPOLnchNodeID() {}

		MPOLnchNodeID(PMString name):fName(name) {}
	PMString	fName;

};

#endif // __MPOLnchNodeID__


