#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);

	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	

}
int main()
{
	test();
	system("pause");
	return 0;
}