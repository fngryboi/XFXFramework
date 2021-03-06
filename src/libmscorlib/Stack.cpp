#include <System/Array.h>
#include <System/Collections/Stack.h>

namespace System
{
	namespace Collections
	{
		const int Stack::_defaultCapacity = 10;

		int Stack::Count()
		{
			return _size;
		}

		bool Stack::IsSynchronized()
		{
			return false;
		}

		Stack::Stack()
		{
			_bottom = new Object*[_defaultCapacity];
			_size = 0;
			_version = 0;
		}

		Stack::Stack(ICollection* col)
		{
			Stack((!col) ? 0x20 : col->Count());

			if (!col)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "col");
#endif
				return;
			}

			for (int i = 0; i < col->Count(); i++)
			{
				
				// TODO: Push all values in the ICollection into this Stack.
			}
		}

		Stack::Stack(int initialCapacity)
		{
			if (initialCapacity < 0)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\": %s\n", __FUNCTION__, __LINE__, __FILE__, "initialCapacity", "Non-negative number required");
#endif
				return;
			}

			if (initialCapacity < _defaultCapacity)
				initialCapacity = _defaultCapacity;

			_bottom = new Object*[initialCapacity];
			_size = 0;
			_version = 0;
		}

		Stack::~Stack()
		{
			delete[] _bottom;
		}

		void Stack::Clear()
		{
			Array::Clear(_bottom, 0, _size);
			_size = 0;
			_version++;
		}

		Object* Stack::Peek()
		{
			return *_top;
		}

		Object* Stack::Pop()
		{
			_top--;
			_version++;
			return *_top;
		}

		void Stack::Push(Object* obj)
		{
			*_top = obj; 
			_top++;
			_version++;
		}

		Object** Stack::ToArray()
		{
			//TODO: Copy the contents of _bottom into a fresh array and return it
		}
	}
}
