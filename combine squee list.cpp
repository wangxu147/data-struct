#define _CRT_SECURE_NO_WARNINGS 1
/*��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�


ʾ����


���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	if (l1 == NULL)//ֻҪ
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode* newnode = NULL;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			//ȡС������β��
			ListNode* next = l1->next;
			if (newnode == NULL)//ע������һ��Ҫ������ж��Ƿ�Ϊ�յ����.���Ϊ��ֱ�Ӱ�l1���½ڵ�
			{
				l1->next = NULL;
				newnode = l1;
			}
			else//�����Ϊ���ҵ�β�Ͳ���
			{
				ListNode* tail = newnode;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				l1->next = NULL;
				tail->next = l1;
			}
			l1 = next;
		}
		else if (l1->val > l2->val)
		{
			//ȡ����һ������β��.β��Ĵ�������ظ�ʹ��
			ListNode* next = l2->next;
			if (newnode == NULL)//���Ϊ��ֱ�Ӱ�l1���½ڵ�
			{
				l2->next = NULL;
				newnode = l2;
			}
			else//�����Ϊ���ҵ�β�Ͳ���
			{
				ListNode* tail = newnode;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				l2->next = NULL;
				tail->next = l2;
			}
			l2 = next;
		}
		else
		{
			//�������������ȡ�ĸ���������
			ListNode* next = l2->next;
			if (newnode == NULL)//���Ϊ��ֱ�Ӱ�l1���½ڵ�
			{
				l2->next = NULL;
				newnode = l2;
			}
			else//�����Ϊ���ҵ�β�Ͳ���
			{
				ListNode* tail = newnode;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				l2->next = NULL;
				tail->next = l2;
			}
			l2 = next;
		}
	}
	if (l1 == NULL)
	{
		ListNode* tail = newnode;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = l2;
	}
	if (l2 == NULL)
	{
		ListNode* tail = newnode;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = l1;
	}
	return newnode;


}