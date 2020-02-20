//c风格 动态栈   注意指针指向头结点 压栈类似于头插
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//是在链表的基础上，先写一个链表节点
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*pNODE;

//写栈
typedef struct Stack
{
	pNODE pTop;
	pNODE pBottom;
}STACK,*pSTACK;

//有头结点
void initStack(pSTACK ps)
{
	ps->pBottom = (pNODE)malloc(sizeof(NODE));
	ps->pTop = ps->pBottom;
	ps->pTop->pNext = NULL;
}
void pushStack(pSTACK ps, int val)
{
	pNODE p_new = (pNODE)malloc(sizeof(NODE));
	p_new->data = val;
	p_new->pNext = ps->pTop;
	ps->pTop = p_new;



}

bool popStact(pSTACK ps, int* val)
{
	if (ps->pTop == ps->pBottom)
		return false;
	else
	{
		*val = ps->pTop->data;
		pNODE tmp = ps->pTop;
		ps->pTop = ps->pTop->pNext;
		free(tmp);
		tmp = NULL;
		return true;
	}
}
void traverseStack(pSTACK ps)
{
	pNODE pMove = ps->pTop;
	while (pMove != ps->pBottom)
	{
		printf("%d\n", pMove->data);
		pMove = pMove->pNext;
	}
}
void clear(pSTACK ps)
{
	while (ps->pTop != ps->pBottom)
	{
		pNODE tmp = ps->pTop;
		ps->pTop = ps->pTop->pNext;
		free(tmp);
		tmp = NULL;
	}
}

int main(void)
{
	STACK s;
	initStack(&s);
	pushStack(&s,1);
	pushStack(&s,2);
    traverseStack(&s);
	int x;
	popStact(&s, &x);
	printf("%d\n", x);
	traverseStack(&s);
	clear(&s);
	printf("清空\n");
	traverseStack(&s);
	pushStack(&s, 3);
	pushStack(&s, 4);
	pushStack(&s, 5);
	pushStack(&s, 2);
	traverseStack(&s);
	system("pause");
	return 0;
}