#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <assert.h>

namespace myString
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		String& operator= (const String& s)
		{
			if (this != &s)
			{
				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}//end of namespace


int main()
{
	myString::String s1("hello world");
	myString::String s2(s1);
	myString::String s3;
	s3 = s1;
	return 0;
}