#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void  InsertSort(int* arr, int size)
//{
//	for (int i = 1; i < size; ++i)
//	{
//		int key = arr[i];
//		int end = i - 1;
//		while (end >= 0 && arr[end] > key)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = key;
//	}
//}


void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void InsertSort(int* array, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		// ������Ԫ��
		int key = array[i];

		// ��key�Ĳ���λ�ã���ǰ���Ѿ�����õ�Ԫ�شӺ���ǰ�Ƚ�
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end -= 1;
		}

		// ����Ԫ��
		array[end + 1] = key;
	}
}

int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

// [left, right)
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// ���������ұȻ�׼ֵ���Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[begin] <= key)
			begin++;

		// ���������ұȻ�׼ֵС��Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[end] >= key)
			end--;

		if (begin != end)
			Swap(&array[begin], &array[end]);
	}

	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// ��ǰ�����ұȻ�׼ֵ���Ԫ�أ��ҵ������endλ�õĿ�
		while (begin < end && array[begin] <= key)
			begin++;

		// ���endλ�õĿ�
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		// �Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ��ҵ������beginλ�õĿ�
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	array[begin] = key;
	return begin;
}

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];


	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		++cur;
	}

	if (++prev != right)
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{

	if ((right - left) < 16)
		//InsertSort(array, right - left);
		InsertSort(array, left, right);//��ʱҪ�õ��ݹ飬������ڶ����QuickSort(array, div + 1, right);����ʱ����������left��right
									   //����Ҫ��ֱ�Ӵ������������ڶ�����������(right - left)����ʱ
									   //����������Ĭ�ϰ����±�ȫ��0��ʼ��right - left
									   //��ʱ������Ļ�����������Ų���ȥ���������ֱ�ӳ��ݹ�
									   //���ԣ������ڲ�������(InsertSort)��ָ��Ҫ��������left��right.
	else
	{
		// ���ջ�׼ֵ������ָ������������
		// ���С�ڻ�׼ֵ ��׼ֵ �Ҳ���ڻ�׼ֵ
		int div = Partion1(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}

	//if (right - left > 1)
	//{
	//	int div = Partion1(array, left, right);
	//	QuickSort(array, left, div);
	//	QuickSort(array, div + 1, right);
	//}


	//int div;
	//if (right - left > 16)
	//{
	//	div = Partion1(array, left, right);
	//	QuickSort(array, left, div);
	//	QuickSort(array, div + 1, right);
	//}
	//else
	//	InsertSort(array, right - left);
}
#include <string.h>
int main()
{
	int arr[] = { 5, 6, 7, 3, 9, 1, 2, 0, 4, 8, 22, 99, 66, 88, 55, 77, 33, 44, 11, 12, 56, 98, 74, 29, 31 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len);
	//for (auto e : arr)
	//	cout << e << " ";
	PrintArray(arr,len);
	cout << endl;
	return 0;
}