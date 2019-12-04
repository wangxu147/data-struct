#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListInit(SeqList* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void checkcapacity(SeqList*ps)
{
	if (ps->size == ps->capacity)//ÂúÁËÀ©ÈÝ
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLSeqList*)realloc(ps->a, newcapacity*sizeof(SLSeqList));
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, SLSeqList x)
{
	checkcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
	
}
void SeqListPrint(SeqList*ps)
{
	for (size_t i=0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
		
	}
	printf("\n");
}

void SeqListPushFront(SeqList* ps, SLSeqList x)
{
	checkcapacity(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)
{
	ps->size--;
}

void SeqListPopFront(SeqList*ps)
{
	for (size_t i=0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}