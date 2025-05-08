#include <stdio.h>
	int num, n, temp;//定义变量
	int a[100];   //初始化数组
	int i = 0;
int main()
{

	
	for (int j = 0; j < n - 1; j++)  //比较n-1轮
	{
		for (int k = 0; k < n - 1 - j; k++)  //每轮比较n-1-j次,
		{
			/*
			if (a[k] < a[k+1]) //从大到小
			{
				temp = a[k];
				a[k] = a[k+1];
				a[k+1] = temp;
			}
			*/
			if (a[k] > a[k + 1]) //从小到大
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}

}