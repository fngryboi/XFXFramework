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

#include <Vector2.h>
#include <Vector3.h>
#include <Graphics/VertexPositionNormalTexture.h>
#include <System/String.h>
#include <System/Type.h>

namespace XFX
{
	namespace Graphics
	{
		const Type VertexPositionNormalTextureTypeInfo("VertexPositionNormalTexture", "XFX::Graphics::VertexPositionNormalTexture", TypeCode::Object);

		const VertexElement VertexPositionNormalTexture::vertexArray[] =
		{
			VertexElement(0, VertexElementFormat::Vector3, VertexElementUsage::Position, 0),
			VertexElement(12, VertexElementFormat::Vector3, VertexElementUsage::Normal, 0),
			VertexElement(24, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate, 0)
		};

		VertexDeclaration VertexPositionNormalTexture::getVertexDeclaration() const
		{
			return VertexDeclaration(vertexArray, 3);
		}

		VertexPositionNormalTexture::VertexPositionNormalTexture()
		{
		}

		VertexPositionNormalTexture::VertexPositionNormalTexture(const Vector3 position, const Vector3 normal, const Vector2 textureCoordinate)
			: Position(position), Normal(normal), TextureCoordinate(textureCoordinate)
		{
		}

		bool VertexPositionNormalTexture::Equals(Object const * const obj) const
		{
			return is(obj, this) ? (*this == *(VertexPositionNormalTexture *)obj) : false;
		}
		
		int VertexPositionNormalTexture::GetHashCode() const
		{
			return Normal.GetHashCode() ^ Position.GetHashCode() ^ TextureCoordinate.GetHashCode();
		}

		const Type& VertexPositionNormalTexture::GetType()
		{
			return VertexPositionNormalTextureTypeInfo;
		}

		const String VertexPositionNormalTexture::ToString() const
		{
			return String::Format("{Position:%s Normal:%s TextureCoordinate:%s}", (const char *)Position.ToString(), (const char *)Normal.ToString(), (const char *)TextureCoordinate.ToString());
		}
		
		bool VertexPositionNormalTexture::operator!=(const VertexPositionNormalTexture& other) const
		{
			return ((Normal != other.Normal) || (Position != other.Position) || (TextureCoordinate != other.TextureCoordinate));
		}
		
		bool VertexPositionNormalTexture::operator==(const VertexPositionNormalTexture& other) const
		{
			return ((Normal == other.Normal) && (Position == other.Position) && (TextureCoordinate == other.TextureCoordinate));
		}
	}
}
