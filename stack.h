#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//静态栈
//typedef int stackdata;
//#define N 10
//typedef struct stack{
//	//静态的不用指针,是数组和下标
//	stackdata a[N];
//	int top;
//}stack;

//动态(整个思想是用数组来实现栈)
typedef int stackdata;
typedef struct stack{
	//链表里的指针是指向结构体的,所以指针是结构体类型,而栈不是,是存储类型
	stackdata* a;
	int top;//栈顶指针
	int capacity;//容量
}stack;

//初始化
void StackInit(stack* ps)
{
	
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(stack* ps,stackdata x)
{
	//先判断满不满,满了开空间
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (stackdata* )realloc(ps->a, newcapacity*sizeof(stackdata));//开存储类型的大小
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(stack*ps)
{
	assert(ps && ps->top > 0);
	ps->top--;
}
//获取栈顶元素返回的是存储数据类型
stackdata StackTop(stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];//top是栈顶元素的下一个位置
}

int StackSize(stack* ps)
{
	assert(ps);
	return ps->top;
}

int StackEmpty(stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;//如果为空返回1,表示确实为空
}

void StackDestory(stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;//free完了记得把指针置空

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
	while (!StackEmpty(&st))//这句话stackempty本来就是判断为空,如果空返回1,所以加!表示非空的时候继续循环
	{
		printf("%d", StackTop(&st));
		StackPop(&st);

	}
	StackDestory(&st);