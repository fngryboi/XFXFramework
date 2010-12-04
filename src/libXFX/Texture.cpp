// Copyright (C) 2010-2012, XFX Team
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

#include <Graphics/Texture.h>
#include <Graphics/Texture2D.h>
#include <Graphics/TextureCreationParameters.h>
#include <Graphics/TextureInformation.h>
#include <Rectangle.h>
#include <System/Exception.h>
#include <System/IO/File.h>
#include <System/IO/FileStream.h>

using namespace XFX;

namespace XFX
{
	namespace Graphics
	{
		Texture Texture::FromFile(GraphicsDevice graphicsDevice, char* filename, TextureCreationParameters creationParameters)
		{
			TextureInformation texinfo = GetTextureInformation(filename); 
             if (creationParameters.Width == 0) creationParameters.Width = texinfo.Width; 
             if (creationParameters.Height == 0) creationParameters.Height = texinfo.Height; 
             if (creationParameters.Depth == 0) creationParameters.Depth = texinfo.Depth; 
             /*if (texinfo.ResourceType == ResourceType::Texture2D) 
             { 
                 int ImgID; 
                 Il::ilGenImages(1, out ImgID); 
                 Il::ilBindImage(ImgID); 
                 Il::ilLoadImage(filename); 
                 int width = Il::ilGetInteger(Il::IL_IMAGE_WIDTH); 
                 int height = Il::ilGetInteger(Il::IL_IMAGE_HEIGHT); 
                 int depth = Il::ilGetInteger(Il::IL_IMAGE_DEPTH); 
                 int size = Il::ilGetInteger(Il::IL_IMAGE_SIZE_OF_DATA); 
                 Texture2D tex = Texture2D(graphicsDevice, creationParameters.Width, creationParameters.Height, creationParameters.Depth, TextureUsage::None, SurfaceFormat::Rgb32); 
                 int[] texture = int[1]; 
                 Gl::glGenTextures(1,texture); 
                 tex.textureId = texture[0]; 
                 Gl::glBindTexture(Gl::GL_TEXTURE_2D, tex.textureId); 
                 Gl::glTexImage2D(Gl::GL_TEXTURE_2D, 0, Il::ilGetInteger(Il::IL_IMAGE_BYTES_PER_PIXEL), creationParameters.Width, creationParameters.Height, 0, Gl::GL_RGBA, Gl::GL_UNSIGNED_BYTE, Il::ilGetData()); 
                 Gl::glTexParameteri(Gl::GL_TEXTURE_2D, Gl::GL_TEXTURE_MIN_FILTER, Gl::GL_LINEAR); 
                 Gl::glTexParameteri(Gl::GL_TEXTURE_2D, Gl::GL_TEXTURE_MAG_FILTER, Gl::GL_LINEAR); 
                 Il::ilBindImage(0); 
                 //Il::ilDeleteImage(0);
                 return tex;
             } */
             else if (texinfo.ResourceType_ == ResourceType::Texture3D) { } 
             else if (texinfo.ResourceType_ == ResourceType::Texture3DVolume) { } //FIXME: Should we handle this here too? 
             else if (texinfo.ResourceType_ == ResourceType::TextureCube) { } 
		}
		
		TextureInformation Texture::GetTextureInformation(char* filename)
		{ 
            FileStream FS; 
            try 
            { 
                FS = File::OpenRead(filename); 
            }
			catch(Exception)
			{
			}
			FS.Close(); 

            TextureInformation TexInfo; 
            //TexInfo.Depth = Il::ilGetInteger(Il::IL_IMAGE_DEPTH); 
            TexInfo.Format = SurfaceFormat::Color; //TODO: Find out how to detect and set properly. 
            //TexInfo.Height = Il::ilGetInteger(Il::IL_IMAGE_HEIGHT); 
            //TexInfo.imageFormat = ILimageformat2XNAimageformat(Il::ilGetInteger(Il::IL_IMAGE_FORMAT)); 
            TexInfo.ResourceType_ = ResourceType::Texture2D; //TODO: Find out how to detect and set properly. 
            //TexInfo.Width = Il::ilGetInteger(Il::IL_IMAGE_WIDTH);
            return TexInfo; 
         }
	}
}
