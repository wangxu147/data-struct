#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//
//ʾ�� 1:
//
//���� : [1, 2, 3, 4, 5, 6, 7] �� k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
// ���� :
//	������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//	������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//	������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]

void rotate(int* nums, int numsSize, int k){
//ʹ�÷�ת�����Ȱ�����Ԫ�ؽ��з�ת��Ȼ���ٷ�תǩ����k��Ԫ�غͺ���� (n-k)��Ԫ��
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);


}
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tem = nums[right];
		nums[right] = nums[left];
		nums[left] = tem;
		left++;
		right--;
	}
}

