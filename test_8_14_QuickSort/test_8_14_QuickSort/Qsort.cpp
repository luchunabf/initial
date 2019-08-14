#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
void InsertSort(int* array, int left,int right)
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

//��������
// a  b  c


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

// [left, right)�������С��[0-(size-1)],��ʱ�򴫵���left:0   right: size  ��[left, right)��ʾ������������ ��������� end = right - 1;
//����ֻ��ȡ�� left �� right - 1

//1.hoare����������ĩ��Ԫ����Ϊ��׼ֵkey
int Partion1(int* array, int left, int right) //����ֵ��key���±꣨begin��end �غϴ���
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

//2.�ڿӷ�������beginȥ�ҵ�һ����key���Ԫ��
//	Ȼ���ø�Ԫ��ȥ����key��������Ӧ�����Ϊ����key��Ϊ��׼ֵ������ĩβ��������ȡ�з������Ժ��������ĩβ��Ҳ���ܲ��ǡ���ֵ���棬Ҳ���൱��������һ��������䣨�ڸǣ��Ŀӣ�
//  ��begin��ǰ������ȥѰ�ұ�key���Ԫ�أ�Ȼ����end����
//	��end�Ӻ���ǰ��ȥѰ�ұ�keyС��Ԫ�أ�Ȼ����begin����
//  ÿ�����һ�ο��Ժ���begin++����end--�ƶ�һ��ȥѭ��
//	����ѭ����hoare��һ����begin����һ������begin��end�غϣ�����ʱend���ǿӣ���Ϊ��һ��end�Ѿ���ֵ��begin����ӣ�����key����ÿ�
int Partion2(int* array, int left, int right) //����ֵ��key���±꣨begin��end �غϴ���
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];//Ҳ��������ĩβԪ�أ�����ȡ�з��Ż����м�ֵ��������ĩβ���ɣ���Ϊ��׼ֵ

	while (begin < end)
	{
		// ��ǰ�����ұȻ�׼ֵ���Ԫ�أ��ҵ������endλ�õĿ�
		while (begin < end && array[begin] <= key)
			begin++;

		// ���endλ�õĿӣ���Ϊendλ�ô���key�Ѿ���ǣ����Ը������Ժ󻹿�����key�ҵ���
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
	//��ѭ����hoare��һ����begin����һ������begin��end�غϣ�����ʱend���ǿӣ���Ϊ��һ��end�Ѿ���ֵ��begin����ӣ�������ֱ����key�����
	array[begin] = key;
	return begin;
}

//3.ǰ��ָ�뷨��	cur����ǰָ�룬�����������ߣ���cur����ֵС�ڻ�׼ֵkey����ô��prev������һ����
//					prev:��ǿ�ʼʱcur��ǰһ��λ�ô�  ��1����cur����ֵС�ڻ�׼ֵkeyʱ��prev������һ��	
//													  ��2����cur�������飬ѭ��������prev������һ��
//					��cur�������飬ѭ��������prev������һ���Ժ󣬽���prev��key����ֵ��OK��
int Partion3(int* array, int left, int right) //����ֵ��key���±꣨begin��end �غϴ���
{
	int cur = left;// cur��ǵ�ǰָ���λ��
	int prev = cur - 1;//prev��ǿ�ʼʱcur��ǰһ��λ�ô�
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];//Ҳ��������ĩβԪ�أ�����ȡ�з��Ż����м�ֵ��������ĩβ���ɣ���Ϊ��׼ֵ


	while (cur < right)//cur�����Ǵ����鿪ʼ�ߵ���β����ѭ��������ÿ��ѭ��������һ����
	{
		if (array[cur] < key && ++prev != cur)//��arr[cur]��ֵС��keyʱ��prev��������һ��
			//ע�⣺��&&ǰ�����������Ļ��Ż�ִ�к����++prev
			Swap(&array[cur], &array[prev]);//��prev+1������curʱ����pre��cur�м���[ >=key ]Ԫ�أ�����prev��ǰһ��ָ�����[ >=key ]Ԫ�أ�Ȼ�󽻻�cur����Ԫ�غ�prev����Ԫ��

		++cur; //ÿ��ѭ��pcur������������һ��
	}
	///�ص����///if�����������++prev����prev������һ�������ж��ύ�޹أ���if (array[cur] < key && ++prev != cur)���������ǰ���array[cur] < key�����������Ժ�Ż�ִ��++prev
	if (++prev != right)//��ѭ����cur�ߵ�����ĩβ����һ��λ�ô���
		//���prevû���ߵ�������һ��[��ʱcur�ߵ���β��һ��]����prev��������һ��������key�������ĵ�һ��Ԫ�ش�������keyֵ����prev��
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)//�Ż�1������ȡ�з� �Ż�2�����ݹ鵽δ�������������С��ĳ��ֵ��һ����16��ʱ�����ò�������
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
		int div = Partion1(array, left, right);//Partion���������䶼������ҿ���[left, right)�������С��[0-(size-1)],������left:0   right: size  ��[left, right)��ʾ������������ ��Ϊ�������е� end = right - 1;
		QuickSort(array, left, div);//ͬ�����ϣ�divȡ������
		QuickSort(array, div + 1, right);//ͬ�����ϣ�rightȡ������
	}
}


#if 0
//�ǵݹ�ʵ�ֿ���
#include "Stack.h"
void QuickSortNor(int* array, int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion3(array, left, right);

			// �����Ұ벿������
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// ������벿������
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}
#endif





int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5, 15, 95, 67, 28, 34, 18, 66, 24 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}


