#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <iostream>
#include <assert.h>
using namespace std;

void* my_memcpy(void* dst, const void* src, int num)
{
	assert(dst != nullptr && src != nullptr);
	void* ret = dst;
	while (num--)
	{
		(*(char*)dst)++ = (*(char*)src)++;
	}
	return ret;
}



int main()
{
	char str1[] = "abcd";
	char str2[] = "abcg";
	//cout << memcmp(str1, str2, 4) << endl;

	return 0;
}