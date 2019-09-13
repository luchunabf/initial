#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <iostream>
#include <assert.h>
#include <memory.h>
using namespace std;

//void* my_memcpy(void* dst, const void* src, int count)
//{
//	assert(dst != nullptr && src != nullptr);
//	void* ret = dst;
//	while (count--)
//	{
//		*((char*)dst++) = *((char*)src++);
//
//		//*(char*)dst = *(char*)src;
//		//dst = (char*)dst + 1;
//		//src = (char*)src + 1;
//	}
//	return ret;
//}

#if 0
void* my_memmove(void* dest, void* src, int count)
{
	assert(dest);
	assert(src);
	void* ret = dest;

	if (dest < src)
	{
		while (count--)
		{
			//*(char*)dest = *(char*)src;//将地址强转为char*（1个字节），然后解引用赋值
			//((char*)dest)++;//地址先强转为char*（1个字节），然后以1个字节往后加一个
			//((char*)src)++;//同上
			//*((char*)dest)++ = *((char*)src)++;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
#endif


void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;

	while(count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}

	return ret;
}

#if 0
void* my_memmove(void* dest, const void* src, int count)
{
	assert(dest);
	assert(src);
	void* ret = dest;

	if (dest <= src || (char*)dest >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
#endif




int main()
{
	char str1[] = "abcdefghijk";
	char str2[] = "abcg";
	//cout << memcmp(str1, str2, 4) << endl;
	//my_memcpy(str1, str2, 5);
	//my_memmove(str1 + 1, str1 + 4, 7);
	memcpy(str1 + 1, str1 + 4, 7);
	cout << str1;
	return 0;
}