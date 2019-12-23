#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//用单链表实现队列
typedef int queuedata;
typedef struct QueueNode{
	queuedata data;
	struct QueueNode* next;//因为这里是链表,所以指针的类型是结构体类型
}QueueNode;

typedef struct Queue{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;//把头尾指针都设置成空
}

//队尾入队
void QueuePush(Queue* q,queuedata x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (q->tail == NULL)//队列的tail就是指向最后一个元素,所以判断条件不能是q->tail->next == NULL
	{
		//q->tail = newnode;//队列有对头和队尾,一定要两个都兼顾到
		q->head = q->tail = newnode;
	}
	else
	{
		//因为不确定tail是否为空,如果为空tail->next就会崩,所以要判断
		q->tail->next = newnode;
		q->tail = newnode;
	}

}

//队头出队
void QueuePop(Queue* q)
{
	assert(q);
	//同理出队的时候也一样如果只有一个节点Q->next就会出问题
	if (q->head->next = NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QueueNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}

//获取头部元素
queuedata QueueFront(Queue* q)
{
	//队列取头取尾的使用时默认不为空的
	assert(q);
	return q->head->data;
}
//获取尾部元素
queuedata QueueBack(Queue* q)
{
	//队列取头取尾的使用时默认不为空的
	assert(q);
	return q->tail->data;
}

int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	
	}
	return n;
}
//检测队列为空
int QueueEmpty(Queue*q)
{
	return q->head == NULL ? 1 : 0;
}

//销毁队列
void QueueDestory(Queue* q)
{
	QueueNode* cur = q->head;
	while (cur)
	{
		//销毁之前要保存下一个节点
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
}