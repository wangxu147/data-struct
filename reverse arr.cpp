#define _CRT_SECURE_NO_WARNINGS 1
//����:[1, 2, 3, 4, 5, 6, 7] �� k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
// ���� :
//	������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//	������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//	������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]

//�������鷨

void rotate(int* nums, int numsSize, int k){
	int arr[10] = { 0 }; int i = 0; int tem = k;
	while (k>0)//�Ѻ���k�������δ�����
	{
		arr[i] = nums[numsSize - k];
		k--;
		i++;
	}
	while ((numsSize - tem) > 0)//�Ӻ���ǰ��size-k�����Ӻ���ǰ�ƶ�
	{
		nums[numsSize - 1] = nums[numsSize - tem - 1];
		numsSize--;
	}
	while (i>0)//�ٰѶ��⿪�������δ���nums��
	{
		nums[i] = arr[i];
		i--;
	}
}



�������鷨

void rotate(int* nums, int numsSize, int k){
    int arr[10] = {0};int i = 0;int tem = k;
    while(k>0)//�Ѻ���k�������δ�����
    {
        arr[i] = nums[numsSize-k];
        k--;
        i++;
    }
    while((numsSize-tem) > 0)//�Ӻ���ǰ��size-k�����Ӻ���ǰ�ƶ�
    {
        nums[numsSize-1] = nums[numsSize-tem-1];
        numsSize--;
    }
    while(i>0)//�ٰѶ��⿪�������δ���nums��
    {
        nums[i] = arr[i];
        i--;
    }
}


//
//��ת��
//ʹ�÷�ת�����Ȱ�����Ԫ�ؽ��з�ת��Ȼ���ٷ�תǩ����k��Ԫ�غͺ����(n - k)��Ԫ��

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

