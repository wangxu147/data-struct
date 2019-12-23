#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//��̬ջ
//typedef int stackdata;
//#define N 10
//typedef struct stack{
//	//��̬�Ĳ���ָ��,��������±�
//	stackdata a[N];
//	int top;
//}stack;

//��̬(����˼������������ʵ��ջ)
typedef int stackdata;
typedef struct stack{
	//�������ָ����ָ��ṹ���,����ָ���ǽṹ������,��ջ����,�Ǵ洢����
	stackdata* a;
	int top;//ջ��ָ��
	int capacity;//����
}stack;

//��ʼ��
void StackInit(stack* ps)
{
	
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(stack* ps,stackdata x)
{
	//���ж�������,���˿��ռ�
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (stackdata* )realloc(ps->a, newcapacity*sizeof(stackdata));//���洢���͵Ĵ�С
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(stack*ps)
{
	assert(ps && ps->top > 0);
	ps->top--;
}
//��ȡջ��Ԫ�ط��ص��Ǵ洢��������
stackdata StackTop(stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];//top��ջ��Ԫ�ص���һ��λ��
}

int StackSize(stack* ps)
{
	assert(ps);
	return ps->top;
}

int StackEmpty(stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;//���Ϊ�շ���1,��ʾȷʵΪ��
}

void StackDestory(stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;//free���˼ǵð�ָ���ÿ�

	ps->capacity = 0;
	ps->top = 0;
}

void TestStack()
{
	stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))//��仰stackempty���������ж�Ϊ��,����շ���1,���Լ�!��ʾ�ǿյ�ʱ�����ѭ��
	{
		printf("%d", StackTop(&st));
		StackPop(&st);

	}
	StackDestory(&st);