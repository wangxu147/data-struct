#define _CRT_SECURE_NO_WARNINGS 1
//输入:[1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]

//额外数组法

void rotate(int* nums, int numsSize, int k){
	int arr[10] = { 0 }; int i = 0; int tem = k;
	while (k>0)//把后面k个数依次存起来
	{
		arr[i] = nums[numsSize - k];
		k--;
		i++;
	}
	while ((numsSize - tem) > 0)//从后往前把size-k个数从后往前移动
	{
		nums[numsSize - 1] = nums[numsSize - tem - 1];
		numsSize--;
	}
	while (i>0)//再把额外开数组依次存入nums中
	{
		nums[i] = arr[i];
		i--;
	}
}



额外数组法

void rotate(int* nums, int numsSize, int k){
    int arr[10] = {0};int i = 0;int tem = k;
    while(k>0)//把后面k个数依次存起来
    {
        arr[i] = nums[numsSize-k];
        k--;
        i++;
    }
    while((numsSize-tem) > 0)//从后往前把size-k个数从后往前移动
    {
        nums[numsSize-1] = nums[numsSize-tem-1];
        numsSize--;
    }
    while(i>0)//再把额外开数组依次存入nums中
    {
        nums[i] = arr[i];
        i--;
    }
}


//
//旋转法
//使用反转，首先把整个元素进行反转，然后再反转签名的k个元素和后面的(n - k)个元素

void rotate(int* nums, int numsSize, int k){
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

