#define _CRT_SECURE_NO_WARNINGS 1
//˼·:��������ͷ�ڵ�,������ֵ��x���бȽ�,С�ķŵ�һ��,��ķŵ�һ��.���Ѵ�������С�ĺ���,�ڷ���
typedef struct ListNode ListNode;
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		//����������ͷ�ڵ�
		ListNode* LessHead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* GreaterHead = (ListNode*)malloc(sizeof(ListNode));
		LessHead->next = NULL; GreaterHead->next = NULL;
		ListNode* Lesstail, *Greatertail;
		Lesstail = LessHead; Greatertail = GreaterHead;

		ListNode* cur = pHead;
		while (cur)
		{
			//С�ڷŵ�С������
			if (cur->val < x)
			{
				Lesstail->next = cur;
				Lesstail = cur;//cur��ʱû�ж����Ի���ָ���������cur����
			}
			else
			{
				Greatertail->next = cur;
				Greatertail = cur;
			}
			cur = cur->next;
		}
		//�Ѵ���νӵ�С�ĺ���
		Lesstail->next = GreaterHead->next;
		Greatertail->next = NULL;
		//�ͷ�����ͷ�ڵ�
		ListNode* list = LessHead->next;
		free(LessHead);
		free(GreaterHead);
		return list;
