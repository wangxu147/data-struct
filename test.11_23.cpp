#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//����AB�����ַ���
void Swap(int* A, int* B)
{
	//��ʱ������
	int temp = *A;
	*A = *B;
	*B = temp;
}

//��ʹ����ʱ����
void Swap(int* A, int* B)
{
	*A = *A + *B;
	*B = *A - *B;
	*A = *A - *B;
}

//���ķ���
void Swap(int*A, int*B)
{
	*A = *A^*B;
	*B = *A^*B;
	*A = *A^*B;
}
int main()
{
	int A = 10, B = 20;
	printf("��ӡǰA=%d,B=%d\n", A, B);
	Swap(&A, &B);
	printf("��ӡ��A=%d,B=%d\n", A, B);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1