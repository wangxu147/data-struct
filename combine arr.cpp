
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//2.�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
//
//˵�� :
//
//��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
//����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
//ʾ�� :
//
//���� :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//��� : [1, 2, 2, 3, 5, 6]
//
// ˼· : �Ӻ���ǰ.(��Ϊ��ǰ�������Ļ��漰��������ƶ����鷳)
//	  ��ȷ������ܵĿռ���Ҫsum = m + n.Ȼ���num1[m - 1]��num2[n - 1]��ʼ�Ӻ���ǰ���бȽ�, 
//�Ѵ�ķ�num1[sum - 1], Ȼ���±�--, �ظ����бȽ�.
oid merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int sum = m + n;
	while (m > 0 && n > 0)
	{
		if (nums1[m - 1] < nums2[n - 1])
		{
			nums1[sum - 1] = nums2[n - 1];
			n--;
			sum--;


		}
		else if (nums1[m - 1] > nums2[n - 1])
		{
			nums1[sum - 1] = nums1[m - 1];
			m--;
			sum--;
		}
		else
		{
			nums1[sum - 1] = nums2[n - 1];
			n--;
			sum--;
		}
	}
}