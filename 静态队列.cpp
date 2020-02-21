//c风格 队列 ---->静态队列（数组实现）通常是循环队列
//为什么是循环队列：因为无论插入删除都是往一个方向移动
//求动态数组长度 int* a = new int[20];   size = *(a-4)/sizeof(int)

#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

typedef struct myqueue
{
	int* pBase;
	int front;
	int rear;
}QUEUE,*pQUEUE;

void init(pQUEUE p,int i)
{
	p->pBase = (int*)malloc(sizeof(int)*i);
	p->front = 0;
	p->rear = 0;
}
int length_queue(pQUEUE p)
{
	return *(p->pBase - 4) / sizeof(int);
}
bool full_queue(pQUEUE p)
{
	if ((p->rear + 1) % length_queue(p) == p->front)
		return true;
	else
		return false;
}
bool empty_quene(pQUEUE p)
{
	if (p->front == p->rear)
		return true;
	else
		return false;
}
bool en_queue(pQUEUE p, int i)
{
	if (full_queue(p))
		return false;
	p->pBase[p->rear] = i;
	p->rear = (p->rear + 1) % length_queue(p);
	return true;
}
bool exit_queue(pQUEUE p)
{
	if (empty_quene(p))
	{
		return false;
	}
	p->front = (p->front + 1) % length_queue(p);
}

void travese(pQUEUE p)
{
	int tmp = p->front;
	while (tmp != p->rear)
	{
		printf("%d\n", p->pBase[tmp]);
		tmp = (tmp + 1) % length_queue(p);
	}
}
int main(void)
{
	QUEUE Q;
	init(&Q,6);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 4);
	en_queue(&Q, 8);
	en_queue(&Q, 16);
	en_queue(&Q, 32);
	travese(&Q);
	cout << endl;
	exit_queue(&Q);
	exit_queue(&Q);
	exit_queue(&Q);
	travese(&Q);
	cout << endl;

	exit_queue(&Q);
	exit_queue(&Q);
	exit_queue(&Q);
	travese(&Q);
	cout << endl;
	//int a[32];
	//cout << sizeof(a) << endl; //128
	//int *b = (int*)malloc(sizeof(int)* 33);  
	//cout << sizeof(b) << endl;//4
	//cout << (b[-4])/sizeof(int) << endl;
	system("pause");
}