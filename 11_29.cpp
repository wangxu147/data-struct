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

	for (int j = 0; j <= MAX; j++)//��쳲��������д���������
	{
		arr[j] = Fib(j);
	}
	printf("������Ҫ�жϵ���:\n");
	scanf("%d", &num);
	while (1)
	{
		if ((arr[i - 1] <= num) && (num <= arr[i]))//�ҵ�num��쳲���������Ǹ�����
		{
			tem = i;
			break;
		}
		i++;
	}
	while ((num - arr[tem - 1]) && (arr[tem] - num))//�ô�����С��ȥ��,˭���������ͽ�����.count��¼���������������Ĵ���
	{
		arr[tem - 1]++;
		arr[tem]++;
		count++;
	}
	printf("%d", count);
	system("pause");
	return 0;
}