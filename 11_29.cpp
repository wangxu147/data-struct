#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX 10


int Fib(int num)
{
	if (num == 0 || num == 1)
		return 1;
	else
		return Fib(num - 1) + Fib(num - 2);

}
int main()
{
	int arr[MAX] = { 0 };
	int left = 0, right = 0;
	int num = 0; int tem = 0;
	int i = 0; int count = 0;

	for (int j = 0; j <= MAX; j++)//把斐波那契数列存数数组中
	{
		arr[j] = Fib(j);
	}
	printf("输入你要判断的数:\n");
	scanf("%d", &num);
	while (1)
	{
		if ((arr[i - 1] <= num) && (num <= arr[i]))//找到num在斐波那契额的那个区间
		{
			tem = i;
			break;
		}
		i++;
	}
	while ((num - arr[tem - 1]) && (arr[tem] - num))//用大数和小数去减,谁先跳出来就结束了.count记录的是最早跳出来的次数
	{
		arr[tem - 1]++;//小数每次加1
		arr[tem]--;//大数每次减1
		count++;
	}
	printf("%d", count);
	system("pause");
	return 0;
}
