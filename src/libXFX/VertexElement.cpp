// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include <Graphics/VertexElement.h>
#include <System/String.h>
#include <System/Type.h>

namespace XFX
{
	namespace Graphics
	{
		const Type VertexElementTypeInfo("VertexElement", "XFX::Graphics::VertexElement", TypeCode::Object);

		VertexElement::VertexElement(const int offset, const VertexElementFormat_t elementFormat, const VertexElementUsage_t elementUsage, const int usageIndex)
			: Offset(offset), UsageIndex(usageIndex),
			  VertexElementFormat(elementFormat), VertexElementUsage(elementUsage)
		{
		}

		VertexElement::VertexElement(const VertexElement &obj)
			: Offset(obj.Offset), UsageIndex(obj.UsageIndex),
			  VertexElementFormat(obj.VertexElementFormat), VertexElementUsage(obj.VertexElementUsage)
		{
		}

		bool VertexElement::Equals(Object const * const obj) const
		{
			return is(obj, this) ? (*this == *(VertexElement *)obj) : false;
		}
		
		int VertexElement::GetHashCode() const
		{
			return (Offset ^ UsageIndex);
		}

		const Type& VertexElement::GetType()
		{
			return VertexElementTypeInfo;
		}

		const String VertexElement::ToString() const
		{
			// TODO: implement
		}
		
		bool VertexElement::operator!=(const VertexElement& other) const
		{
			return ((Offset != other.Offset) ||
				(this->VertexElementFormat != other.VertexElementFormat) ||
				(this->VertexElementUsage != other.VertexElementUsage) ||
				(this->UsageIndex != other.UsageIndex));
		}
		
		bool VertexElement::operator==(const VertexElement& other) const
		{
			return ((Offset == other.Offset) &&
				(this->VertexElementFormat == other.VertexElementFormat) &&
				(this->VertexElementUsage == other.VertexElementUsage) &&
				(this->UsageIndex == other.UsageIndex));
		}
	}
}
