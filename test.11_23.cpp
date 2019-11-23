#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//交换AB的三种方法
void Swap(int* A, int* B)
{
	//临时变量法
	int temp = *A;
	*A = *B;
	*B = temp;
}

//不使用临时变量
void Swap(int* A, int* B)
{
	*A = *A + *B;
	*B = *A - *B;
	*A = *A - *B;
}

//异或的方法
void Swap(int*A, int*B)
{
	*A = *A^*B;
	*B = *A^*B;
	*A = *A^*B;
}
int main()
{
	int A = 10, B = 20;
	printf("打印前A=%d,B=%d\n", A, B);
	Swap(&A, &B);
	printf("打印后A=%d,B=%d\n", A, B);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1