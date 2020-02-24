//c风格  链式二叉树
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

struct BTNode
{
	char data;
	struct BTNode* pLchild;    //左孩子
	struct BTNode* pRchild;    //右孩子
};
//创建一个静态树
struct BTNode* CreatBTree()
{
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = NULL;
	pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = NULL;
	pE->pRchild = NULL;
	return pA;
}
void PreTraverse(struct BTNode* p)
{
	/*if (p != NULL)
	{
		cout << p->data<<" ";
	}
	if (p->pLchild != NULL)
	{
		PreTraverse(p->pLchild);
	}
	if (p->pRchild != NULL)
	{
		PreTraverse(p->pRchild);
	}*/
	//不需要像上面这样写 只需要判断p为不为空 但是上面的写法可以少调用 节省时间
	if (p != NULL)
	{
		cout << p->data << " ";
		PreTraverse(p->pLchild);
		PreTraverse(p->pRchild);
	}

	
}
void InTraverse(struct BTNode* p)
{
	//if (p->pLchild != NULL)
	//{
	//	InTraverse(p->pLchild);
	//}
	//cout << p->data << " ";
	//if (p->pRchild != NULL)
	//{
	//	InTraverse(p->pRchild);
	//}

	if (p != NULL)
	{
		InTraverse(p->pLchild);
		cout << p->data << " ";
		InTraverse(p->pRchild);
	}
}
void PosTraverse(struct BTNode* p)
{
	//if (p->pLchild != NULL)
	//{
	//	PosTraverse(p->pLchild);
	//}
	//if (p->pRchild != NULL)
	//{
	//	PosTraverse(p->pRchild);
	//}
	//cout << p->data << " ";

	if (p != NULL)
	{
		PosTraverse(p->pLchild);
		PosTraverse(p->pRchild);
		cout << p->data << " ";
	}
}
int main(void)
{
	struct BTNode* pT = CreatBTree();
	PreTraverse(pT);  //先序
	cout << endl;
	InTraverse(pT);  //中序
	cout << endl;
	PosTraverse(pT);  //后序
	system("pause");
	return 0;
}