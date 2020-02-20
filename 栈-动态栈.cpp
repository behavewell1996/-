//c��� ��̬ջ   ע��ָ��ָ��ͷ��� ѹջ������ͷ��
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//��������Ļ����ϣ���дһ������ڵ�
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*pNODE;

//дջ
typedef struct Stack
{
	pNODE pTop;
	pNODE pBottom;
}STACK,*pSTACK;

//��ͷ���
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
	printf("���\n");
	traverseStack(&s);
	pushStack(&s, 3);
	pushStack(&s, 4);
	pushStack(&s, 5);
	pushStack(&s, 2);
	traverseStack(&s);
	system("pause");
	return 0;
}