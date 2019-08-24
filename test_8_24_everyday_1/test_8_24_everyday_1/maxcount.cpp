#define _CRT_SECURE_NO_WARNINGS 1


class MaxGap {
public:
	int Fibs(int a, int b)
	{
		if (a > b)
			return a - b;
		else
			return b - a;
	}
	int findMaxGap(vector<int> A, int n) {
		int k = 0;
		int maxcount1 = A[0];
		int maxcount = 0;
		for (; k < n - 1; ++k)
		{
			if (A[k] > maxcount1)
				maxcount1 = A[k];
			int maxcount2 = A[n - 1];
			for (int j = k + 1; j < n; ++j)
			{
				if (A[j] > maxcount2)
					maxcount2 = A[j];
			}
			int ret = Fibs(maxcount1, maxcount2);
			if (ret > maxcount)
				maxcount = ret;
		}
		return maxcount;
	}
};