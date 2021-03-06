// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//* Redistributions of source code must retain the above copyright 
//notice, this list of conditions and the following disclaimer.
//* Redistributions in binary form must reproduce the above copyright 
//notice, this list of conditions and the following disclaimer in the 
//documentation and/or other materials provided with the distribution.
//* Neither the name of the copyright holder nor the names of any 
//contributors may be used to endorse or promote products derived from 
//this software without specific prior written permission.
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

#include <System/Windows/Point.h>
#include <System/String.h>
#include <System/Type.h>

namespace System
{
	namespace Windows
	{
		const Type PointTypeInfo("Point", "System::Windows::Point", TypeCode::Object);

		Point::Point()
			: X(0), Y(0)
		{
		}

		Point::Point(const int x, const int y)
			: X(x), Y(y)
		{
		}

		Point::Point(const Point &obj)
			: X(obj.X), Y(obj.Y)
		{
		}

		bool Point::Equals(Object const * const obj) const
		{
			return is(obj, this) ? *this == *(Point *)obj : false;
		}

		bool Point::Equals(const Point other) const
		{
			return (*this == other);
		}

		int Point::GetHashCode() const
		{
			return X + Y;
		}

		const Type& Point::GetType()
		{
			return PointTypeInfo;
		}

		const String Point::ToString() const
		{
			return String::Format("{X:%i Y:%i}", X, Y);
		}

		bool Point::operator ==(const Point& right) const
		{
			return ((X == right.X) && (Y == right.Y));
		}

		bool Point::operator !=(const Point& right) const
		{
			return ((X != right.X) || (Y != right.Y));
		}
	}
}
