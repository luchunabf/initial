#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

 const int  my_strlen(const char* str)
{
	if (nullptr == str)
	{
		assert(0);
		return -1;
	}
	int count = 0;
	while (*str)
	{
		++str;
		++count;
	}
	return count;
}
 const int my_strlen1( const char* str)
 {
	 if (nullptr == str)
	 {
		 assert(0);
		 return -1;
	 }
	 if (*str == '\0')
		 return 0;
	 return 1 + my_strlen1(str + 1);
 }
 const int my_strlen2( char* str)
 {
	 if (nullptr == str)
	 {
		 assert(0);
		 return -1;
	 }
	  char* p = str;
	  while (*str)
	  {
		  str++;
	  }
	  return str - p;
 }
int main()
{
	char* str = "hutfydfygy";
	//int ret = my_strlen(str);
	//int ret = my_strlen1(str);
	int ret = my_strlen2(str);
	cout << ret << endl;
	return 0;
}