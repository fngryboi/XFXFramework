/********************************************************
 *	Array.h												*
 *														*
 *	XFX Array class definition file						*
 *	Contains array helper methods						*
 *	Copyright � XFX Team. All Rights Reserved			*
 ********************************************************/
#ifndef _SYSTEM_ARRAY_
#define _SYSTEM_ARRAY_

namespace System
{
	class Array
	{
	public:
		template <class T>
		static void Clear(T array[], int index, int length);
		template <class T>
		static void Copy(T sourceArray[], int sourceIndex, T destinationArray[], int destinationIndex, int length);
		template <class T>
		static int IndexOf(T array[], T value, int startIndex, int count);
		template <class T>
		static int Length(T array[]);
	};
}

#endif //_SYSTEM_ARRAY_
