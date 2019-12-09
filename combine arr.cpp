
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//2.给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]
//
// 思路 : 从后往前.(因为从前往后插入的话涉及到数组的移动很麻烦)
//	  先确定最后总的空间需要sum = m + n.然后从num1[m - 1]和num2[n - 1]开始从后往前进行比较, 
//把大的放num1[sum - 1], 然后下标--, 重复进行比较.
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