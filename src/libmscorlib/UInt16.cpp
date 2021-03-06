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

#include <System/UInt16.h>
#include <System/String.h>
#include <System/Type.h>

#include <stdlib.h>

namespace System
{
	const ushort UInt16::MaxValue = 0xFFFF;
	const ushort UInt16::MinValue = 0;
	const Type UInt16TypeInfo("UInt16", "System::UInt16", TypeCode::UInt16);

	UInt16::UInt16()
		: value(0)
	{
	}

	UInt16::UInt16(const UInt16 &obj)
		: value(obj.value)
	{
	}

	UInt16::UInt16(const ushort &obj)
		: value(obj)
	{
	}

	int UInt16::CompareTo(const UInt16 other) const
	{
		if (value < other.value)
		{
			return -1;
		}

		if (value > other.value)
		{
			return 1;
		}

		return 0;
	}

	bool UInt16::Equals(Object const * const obj) const
	{
		return (obj != null && is(obj, this)) ? *this == *(UInt16 *)obj : false;
	}

	bool UInt16::Equals(const UInt16 other) const
	{
		return (*this == other);
	}

	int UInt16::GetHashCode() const
	{
		return value;
	}

	const Type& UInt16::GetType()
	{
		return UInt16TypeInfo;
	}

	const String UInt16::ToString() const
	{
		return String::Format("%i", value);
	}

	const String UInt16::ToString(const ushort value)
	{
		return String::Format("%i", value);
	}

	bool UInt16::TryParse(const String& str, out ushort* result)
	{
		*result = 0;
		char* end = NULL;

		if (String::IsNullOrEmpty(str))
		{
			return false;
		}

		ushort retval = (ushort)strtoul(str, &end, 10);

		if (end)
		{
			return false;
		}

		*result = retval;
		return true;
	}

	UInt16::operator ushort() const
	{
		return value;
	}

	bool UInt16::operator ==(const UInt16& right) const
	{
		return (value == right.value);
	}

	/*bool UInt16::operator ==(const ushort& right) const
	{
		return (value == right);
	}*/

	bool UInt16::operator !=(const UInt16& right) const
	{
		return (value != right.value);
	}

	/*bool UInt16::operator !=(const ushort& right) const
	{
		return (value != right);
	}*/
}
