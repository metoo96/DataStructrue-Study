#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
//定义数据类型，定义链表结点的存储结构与数据类型
typedef int ElemType;
typedef struct DoubleLinkList//定义双链表结点类型
{
	ElemType data;
	struct DNode * prior;	//指向前驱结点
	struct DNode * next;	//指向后继结点
} DoubleLinkList, * pDoubleLinkList;

void DoubleLink_InitList(pDoubleLinkList L);	//初始化
void DoubleLink_DestroyList(pDoubleLinkList L);	//销毁线性表
status DoubleLink_ListEmpty(pDoubleLinkList L);	//判线性表是否为空表
int  DoubleLink_ListLength(pDoubleLinkList L);	//求线性表的长度
void DoubleLink_DispList(pDoubleLinkList L);	//输出线性表
status DoubleLink_GetElem(pDoubleLinkList L, int i, ElemType *e);	//求线性表中某个数据元素值
int  DoubleLink_LocateElem(pDoubleLinkList L, ElemType e);	//按元素值查找
status DoubleLink_ListInsert(pDoubleLinkList L, int i, ElemType e);	//插入数据元素
status DoubleLink_ListDelete(pDoubleLinkList L, int i, ElemType *e);	//删除数据元素

//主调函数
int main()
{
	DoubleLinkList H;
	ElemType e;
	printf("双链表的基本运算如下:\n");
	printf("(1)初始化双链表\n");
	DoubleLink_InitList(&H);
	printf("(2)依次采用尾插法插入1,2,3,4,5元素\n");
	DoubleLink_ListInsert(&H, 1, 1);
	DoubleLink_ListInsert(&H, 2, 2);
	DoubleLink_ListInsert(&H, 3, 3);
	DoubleLink_ListInsert(&H, 4, 4);
	DoubleLink_ListInsert(&H, 5, 5);
	printf("(3)输出双链表:");
	DoubleLink_DispList(&H);
	printf("(4)双链表长度=%d\n", DoubleLink_ListLength(&H));
    printf("(5)双链表为%s\n", (DoubleLink_ListEmpty(&H)?"空":"非空"));
	DoubleLink_GetElem(&H, 3, &e);
	printf("(6)双链表的第3个元素=%d\n", e);
	printf("(7)元素2的位置=%d\n",DoubleLink_LocateElem(&H, 2));
	printf("(8)在第4个元素位置上插入元素8\n");
	DoubleLink_ListInsert(&H, 4, 8);
	printf("(9)输出双链表:");
	DoubleLink_DispList(&H);
	printf("(10)删除h的第3个元素\n");
	DoubleLink_ListDelete(&H, 3, &e);
	printf("(11)输出双链表H:");
	DoubleLink_DispList(&H);
	printf("(12)释放双链表\n");
	DoubleLink_DestroyList(&H);
	printf("(13)释放双链表...OK!\n");
	return 0;
}

void DoubleLink_InitList(pDoubleLinkList L)	//初始化
{
	L=(struct DoubleLinkList*)malloc(sizeof(DoubleLinkList));  	//创建头结点
	L->prior=L->next=NULL;
}

void DoubleLink_DestroyList(pDoubleLinkList L)	//销毁线性表
{
	pDoubleLinkList p = L;
	pDoubleLinkList q = p;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

status DoubleLink_ListEmpty(pDoubleLinkList L)	//判线性表是否为空表
{
	return (L->next==NULL);
}

int DoubleLink_ListLength(pDoubleLinkList L)	//求线性表的长度
{
	pDoubleLinkList p = L;
	int i = 0;
	while (p->next != NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}

void DoubleLink_DispList(pDoubleLinkList L)	//输出线性表
{
	pDoubleLinkList p = L->next;
	while (p != NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}

status DoubleLink_GetElem(pDoubleLinkList L, int i, ElemType* e)	//求线性表中某个数据元素值
{
	int j = 0;
	pDoubleLinkList p = L;
	while (j<i && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
	{
		*e = p->data;
		return 1;
	}
}

int DoubleLink_LocateElem(pDoubleLinkList L, ElemType e)//按元素值查找
{
	int n=1;
	pDoubleLinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		n++;
		p = p->next;
	}
	if (p == NULL)
		return(0);
	else
		return(n);
}

status DoubleLink_ListInsert(pDoubleLinkList L, int i, ElemType e)	//插入数据元素
{
	int j=0;
	pDoubleLinkList p = L, s;
	while (j< i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s=(struct DoubleLinkList *)malloc(sizeof(DoubleLinkList));
		s->data = e;
		s->next = p->next;
		s->next = NULL;
		if (p->next != NULL)
        p->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}

status DoubleLink_ListDelete(pDoubleLinkList L, int i, ElemType *e)	//删除数据元素
{
	int j = 0;
	pDoubleLinkList p = L, q;
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//未找到第i-1个结点
		return 0;
	else						//找到第i-1个结点*p
	{
		q = p->next;				//q指向要删除的结点
		if (q == NULL)
        return 0;	//不存在第i个结点
		e = q->data;
		p->next = q->next;		//从单链表中删除*q结点
		if (p->next != NULL)
        q->prior = p;
		free(q);				//释放*q结点
		return 1;
	}
}
