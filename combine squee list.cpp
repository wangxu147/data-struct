#define _CRT_SECURE_NO_WARNINGS 1
/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。


示例：


输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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

	if (l1 == NULL)//只要
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode* newnode = NULL;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			//取小的下来尾插
			ListNode* next = l1->next;
			if (newnode == NULL)//注意这里一定要有这个判断是否为空的情况.如果为空直接把l1给新节点
			{
				l1->next = NULL;
				newnode = l1;
			}
			else//如果不为空找到尾巴插入
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
			//取另外一个下来尾插.尾插的代码可以重复使用
			ListNode* next = l2->next;
			if (newnode == NULL)//如果为空直接把l1给新节点
			{
				l2->next = NULL;
				newnode = l2;
			}
			else//如果不为空找到尾巴插入
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
			//如果两个相等随便取哪个下来都行
			ListNode* next = l2->next;
			if (newnode == NULL)//如果为空直接把l1给新节点
			{
				l2->next = NULL;
				newnode = l2;
			}
			else//如果不为空找到尾巴插入
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