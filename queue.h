#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�õ�����ʵ�ֶ���
typedef int queuedata;
typedef struct QueueNode{
	queuedata data;
	struct QueueNode* next;//��Ϊ����������,����ָ��������ǽṹ������
}QueueNode;

typedef struct Queue{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;//��ͷβָ�붼���óɿ�
}

//��β���
void QueuePush(Queue* q,queuedata x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (q->tail == NULL)//���е�tail����ָ�����һ��Ԫ��,�����ж�����������q->tail->next == NULL
	{
		//q->tail = newnode;//�����ж�ͷ�Ͷ�β,һ��Ҫ��������˵�
		q->head = q->tail = newnode;
	}
	else
	{
		//��Ϊ��ȷ��tail�Ƿ�Ϊ��,���Ϊ��tail->next�ͻ��,����Ҫ�ж�
		q->tail->next = newnode;
		q->tail = newnode;
	}

}

//��ͷ����
void QueuePop(Queue* q)
{
	assert(q);
	//ͬ����ӵ�ʱ��Ҳһ�����ֻ��һ���ڵ�Q->next�ͻ������
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

//��ȡͷ��Ԫ��
queuedata QueueFront(Queue* q)
{
	//����ȡͷȡβ��ʹ��ʱĬ�ϲ�Ϊ�յ�
	assert(q);
	return q->head->data;
}
//��ȡβ��Ԫ��
queuedata QueueBack(Queue* q)
{
	//����ȡͷȡβ��ʹ��ʱĬ�ϲ�Ϊ�յ�
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
//������Ϊ��
int QueueEmpty(Queue*q)
{
	return q->head == NULL ? 1 : 0;
}

//���ٶ���
void QueueDestory(Queue* q)
{
	QueueNode* cur = q->head;
	while (cur)
	{
		//����֮ǰҪ������һ���ڵ�
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
}