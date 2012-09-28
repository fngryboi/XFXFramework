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

#include <System/Double.h>
#include <System/String.h>
#include <stdlib.h>
#include <string.h>

unsigned long long rawNaND = 0x7ff8000000000000ULL;
unsigned long long rawPosInfD = 0x7ff0000000000000ULL;
unsigned long long rawNegInfD = 0xfff0000000000000ULL;

namespace System
{
	const double Double::Epsilon =  4.94066e-324;
	const double Double::MaxValue = 1.79769e+308;
	const double Double::MinValue = -1.79769e+308;
	const double Double::NaN = *(double*)&rawNaND;
	const double Double::PositiveInfinity = *(double*)&rawPosInfD;
	const double Double::NegativeInfinity = *(double*)&rawNegInfD;

	Double::Double(const Double &obj)
		: value(obj.value)
	{
	}

	Double::Double(const double &obj)
		: value(obj)
	{
	}

	int Double::CompareTo(const Double other) const
	{
		if (value > other.value)
			return 1;
		if (value < other.value)
			return -1;
		return 0;
	}

	bool Double::Equals(const Double other) const
	{
		return (*this == other);
	}

	int Double::GetHashCode() const
	{
		return (int)value;
	}

	int Double::GetType() const
	{
		return 14;
	}

	double Double::Parse(char *str)
	{
		double retval;
		char sign = 0;
		char *sp = str;

		if (*sp == '+' || *sp == '-')
        sign = *sp++;

		if (stricmp(sp, "inf") == 0)
		{
			if (!sign || sign == '+')
				retval = PositiveInfinity;
			else
				retval = NegativeInfinity;
		}
		else if (stricmp(sp, "nan") == 0)
			retval = NaN;
		else /* valid number */
			retval = atof(sp);

		return retval;
	}

	const char* Double::ToString() const
	{
		return String::Format("%d", value);
	}

	const char* Double::ToString(const double value)
	{
		return String::Format("%d", value);
	}

	bool Double::operator !=(const Double right) const
	{
		return (value != right.value);
	}

	bool Double::operator ==(const Double right) const
	{
		return (value == right.value);
	}
}
