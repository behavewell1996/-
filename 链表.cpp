//c风格
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int data;
	struct Node* pnext;
} ListNode,*pListNode;  //ListNode <==> struct Node  pListNode<==>struct Node*

pListNode creat_list(int len)
{
	pListNode pHead = (pListNode)malloc(sizeof(ListNode));
	pHead->pnext = NULL;
	if (NULL == pHead)
	{
		printf("分配失败\n");
		exit(-1);
	}
	pListNode move_p = pHead;
	for (int i = 0; i < 5; i++)
	{
		move_p->pnext = (pListNode)malloc(sizeof(ListNode));
		if (NULL == move_p->pnext)
		{
			printf("分配失败\n");
			exit(-1);
		}
		move_p->pnext->data = i;
		move_p->pnext->pnext = NULL;
		move_p = move_p->pnext;
	}
	return pHead;
}

void traverse_list(pListNode p)
{
	while (p->pnext != NULL)
	{
		printf("%d\n", p->pnext->data);
		p = p->pnext;
	}
	return;
}

bool is_empty(pListNode p)
{
	if (p->pnext == NULL)
		return true;
	else
		return false;
}

int length_list(pListNode p)
{
	int len = 0;
	while (p->pnext != NULL)
	{
		len++;
		p = p->pnext;
	}
	return len;
}

bool insert_list(pListNode p, int pos, int value)
{
	int len = length_list(p);
	pListNode pnew = (pListNode)malloc(sizeof(ListNode));
	pnew->data = value;
	if (len - 1 < pos || pnew == NULL)
		return false;
	else
	{
		pListNode move_p = p;
		for (int i = 0; i < pos; i++)
		{
			move_p = move_p->pnext;
		}
		pnew->pnext = move_p->pnext;
		move_p->pnext = pnew;
		return true;
	}
}

bool delete_list(pListNode p, int pos, int* value)
{
	int len = length_list(p);
	if (pos > len - 1)
	{
		return false;
	}
	else
	{
		pListNode move_p = p;
		for (int i = 0; i < pos; i++)
		{
			move_p = move_p->pnext;
		}
		pListNode tmp = move_p->pnext;
		move_p->pnext = move_p->pnext->pnext;
		*value = tmp->data;
		free(tmp);
	}
}

void sort_list(pListNode p)
{
	int i,j,t;
	pListNode p1, p2;
	p1 = p->pnext;
	//for (i = 0; i < length_list(p) - 1; i++)
	//{		
	//	p2 = p1->pnext;
	//	for (j = i + 1; j < length_list(p); j++)
	//	{	
	//		if (p1->data < p2->data)
	//		{
	//			t = p1->data;
	//			p1->data = p2->data;
	//			p2->data = t;
	//		}
	//		p2 = p2->pnext;
	//	}
	//	p1 = p1->pnext;
	//}

	//等价于上面注释的内容
	for (i = 0, p1 = p->pnext; i < length_list(p) - 1; i++, p1 = p1->pnext)
	{
		for (j = i + 1, p2 = p1->pnext; j < length_list(p); j++, p2 = p2->pnext)
		{
			if (p1->data < p2->data)
			{
				t = p1->data;
				p1->data = p2->data;
				p2->data = t;
			}
		}
	}
}


int main(void)
{
	pListNode pHead = NULL;
	int len = 5;
	pHead = creat_list(len);
	traverse_list(pHead);
	printf("%d\n",is_empty(pHead));
	printf("%d\n", length_list(pHead));
	insert_list(pHead, 3, 300);
	traverse_list(pHead);
	int a;
	delete_list(pHead, 3, &a);
	printf("%d\n", a);
	traverse_list(pHead);
	sort_list(pHead);
	traverse_list(pHead);
	system("pause");
	return 0;
}