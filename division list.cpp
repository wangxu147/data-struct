#define _CRT_SECURE_NO_WARNINGS 1
//思路:定义两个头节点,把所有值和x进行比较,小的放到一起,大的放到一起.最后把大链表附到小的后面,在返回
typedef struct ListNode ListNode;
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		//先申请两个头节点
		ListNode* LessHead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* GreaterHead = (ListNode*)malloc(sizeof(ListNode));
		LessHead->next = NULL; GreaterHead->next = NULL;
		ListNode* Lesstail, *Greatertail;
		Lesstail = LessHead; Greatertail = GreaterHead;

		ListNode* cur = pHead;
		while (cur)
		{
			//小于放到小的里面
			if (cur->val < x)
			{
				Lesstail->next = cur;
				Lesstail = cur;//cur此时没有动所以还是指向的正常的cur后面
			}
			else
			{
				Greatertail->next = cur;
				Greatertail = cur;
			}
			cur = cur->next;
		}
		//把大的衔接到小的后面
		Lesstail->next = GreaterHead->next;
		Greatertail->next = NULL;//注意这里,一定要把大的尾设为空,否则当出现最后两个数为8,2.8是大链表的最后一个.不把他设成空,则8就指向
		  	                 //了2,形成了环形链表!有问题.
		//释放两个头节点
		ListNode* list = LessHead->next;
		free(LessHead);
		free(GreaterHead);
		return list;
