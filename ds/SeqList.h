#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLSeqList;

typedef struct SeqList{
	int* a;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListPushBack(SeqList* ps,SLSeqList x);
void SeqListPushFront(SeqList* ps, SLSeqList x);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);
void SeqListPrint(SeqList*ps);

void SeqListDestory(SeqList* ps);