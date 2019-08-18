#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



//����ȡ�з���Ѱ��left mid right �ģ����飩�м���
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);//left mid right ����mid��left �� right ��ƽ��ֵ
	if (array[left] < array[right - 1])//��ʵ����������֮��ȴ�С��return�м��С���Ǹ���
	{
		if (array[mid] < array[left])//����С��˵��left���м���
			return left;
		else if (array[mid] > array[right - 1])//���Ҵ� ˵��right - 1 ���м��� 
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

int Partion(int* array, int left, int right) //����ֵ��key���±꣨begin��end �غϴ���
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);//����ȡ�з��Ż����м�����������ĩβright-1��

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
			Swap(&array[begin], &array[end]);//���ｻ������begin��end�±��Ӧ������Ԫ�صĽ���������Ӱ��begin��end��λ��
	}
	//�߳�ѭ���Ժ�begin��end�����	��Ҫ����Ϊbegin���ߣ���end����,�ʵ�begin��end�غ�ʱ��Ҳ���ǳ�ѭ��ʱ��begin�ض�����end�ϣ�
	//����ʱend�ڱ�key�������ĵ�һ��Ԫ�ش���Ȼ��Ϳ���ֱ�ӽ��غϵ����λ�ú�key�������Ϳ��Դﵽ�û�׼ֵkey�������Ϊ[�����С][�ұ����]����������
	if (begin != right - 1)//����׼ֵ����begin��end���غϴ�
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

#if 1
//�ǵݹ�ʵ�ֿ���
//#include "stack.h"
void QuickSortNor(int* array, int size)
{
	int left = 0;
	int right = size;
	stack s;
	stackInit(&s);
	stackPush(&s, right);
	stackPush(&s, left);

	while (!stackEmpty(&s))
	{
		left = stackTop(&s);
		stackPop(&s);
		right = stackTop(&s);
		stackPop(&s);

		if (right - left > 1)
		{
			int div = Partion(array, left, right);

			// �����Ұ벿������
			stackPush(&s, right);
			stackPush(&s, div + 1);

			// ������벿������
			stackPush(&s, div);
			stackPush(&s, left);
		}
	}
}
#endif





int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}
