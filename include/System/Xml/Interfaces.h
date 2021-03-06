/*****************************************************************************
 *	Enums.h 																 *
 *																			 *
 *	System::Xml Interfaces definition file. 								 *
 *	Copyright (c) XFX Team. All rights reserved.							 *
 *****************************************************************************/
#ifndef _SYSTEM_XML_INTERFACES_
#define _SYSTEM_XML_INTERFACES_

#include <System/Collections/Generic/Interfaces.h>
#include <System/String.h>
#include <System/Xml/Enums.h>

using namespace System::Collections::Generic;

namespace System
{
	namespace Xml
	{
		class XmlNode;

		/**
		 * Enables a class to return an System::Xml::XmlNode from the current context or position.
		 */
		interface IHasXmlNode
		{
		public:
			virtual XmlNode* GetNode()=0;

			virtual ~IHasXmlNode() { }
		};

		/**
		 * Provides an interface to enable a class to return line and position information.
		 */
		interface IXmlLineInfo
		{
		public:
			virtual bool HasLineInfo()=0;

			virtual int LineNumber();
			virtual int LinePosition();

			virtual ~IXmlLineInfo() { }
		};

		/**
		 * Provides read-only access to a set of prefix and namespace mappings.
		 */
		interface IXmlNamespaceResolver
		{
		public:
			virtual IDictionary<String, String>* GetNamespacesInScope(const XmlNamespaceScope_t scope) const=0;
			virtual String LookupNamespace(const String& prefix) const=0;
			virtual String LookupPrefix(const String& namespaceName) const=0;

			virtual ~IXmlNamespaceResolver() { }
		};
	}
}

#endif //_SYSTEM_XML_INTERFACES_
