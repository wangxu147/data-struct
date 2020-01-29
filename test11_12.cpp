#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//
//示例 1:
//
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]

void rotate(int* nums, int numsSize, int k){
        if(!nums || numsSize == 0)//num为空或者长度为0，直接返回
         return;
        k = k%numsSize;//非常重要！因为k可能大于数组的长度，要以要把循环一遍以后的个数算出来
//使用反转，首先把整个元素进行反转，然后再反转签名的k个元素和后面的 (n-k)个元素
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

