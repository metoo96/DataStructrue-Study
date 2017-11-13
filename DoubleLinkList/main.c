#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
//�����������ͣ�����������Ĵ洢�ṹ����������
typedef int ElemType;
typedef struct DoubleLinkList//����˫����������
{
	ElemType data;
	struct DNode * prior;	//ָ��ǰ�����
	struct DNode * next;	//ָ���̽��
} DoubleLinkList, * pDoubleLinkList;

void DoubleLink_InitList(pDoubleLinkList L);	//��ʼ��
void DoubleLink_DestroyList(pDoubleLinkList L);	//�������Ա�
status DoubleLink_ListEmpty(pDoubleLinkList L);	//�����Ա��Ƿ�Ϊ�ձ�
int  DoubleLink_ListLength(pDoubleLinkList L);	//�����Ա�ĳ���
void DoubleLink_DispList(pDoubleLinkList L);	//������Ա�
status DoubleLink_GetElem(pDoubleLinkList L, int i, ElemType *e);	//�����Ա���ĳ������Ԫ��ֵ
int  DoubleLink_LocateElem(pDoubleLinkList L, ElemType e);	//��Ԫ��ֵ����
status DoubleLink_ListInsert(pDoubleLinkList L, int i, ElemType e);	//��������Ԫ��
status DoubleLink_ListDelete(pDoubleLinkList L, int i, ElemType *e);	//ɾ������Ԫ��

//��������
int main()
{
	DoubleLinkList H;
	ElemType e;
	printf("˫����Ļ�����������:\n");
	printf("(1)��ʼ��˫����\n");
	DoubleLink_InitList(&H);
	printf("(2)���β���β�巨����1,2,3,4,5Ԫ��\n");
	DoubleLink_ListInsert(&H, 1, 1);
	DoubleLink_ListInsert(&H, 2, 2);
	DoubleLink_ListInsert(&H, 3, 3);
	DoubleLink_ListInsert(&H, 4, 4);
	DoubleLink_ListInsert(&H, 5, 5);
	printf("(3)���˫����:");
	DoubleLink_DispList(&H);
	printf("(4)˫������=%d\n", DoubleLink_ListLength(&H));
    printf("(5)˫����Ϊ%s\n", (DoubleLink_ListEmpty(&H)?"��":"�ǿ�"));
	DoubleLink_GetElem(&H, 3, &e);
	printf("(6)˫����ĵ�3��Ԫ��=%d\n", e);
	printf("(7)Ԫ��2��λ��=%d\n",DoubleLink_LocateElem(&H, 2));
	printf("(8)�ڵ�4��Ԫ��λ���ϲ���Ԫ��8\n");
	DoubleLink_ListInsert(&H, 4, 8);
	printf("(9)���˫����:");
	DoubleLink_DispList(&H);
	printf("(10)ɾ��h�ĵ�3��Ԫ��\n");
	DoubleLink_ListDelete(&H, 3, &e);
	printf("(11)���˫����H:");
	DoubleLink_DispList(&H);
	printf("(12)�ͷ�˫����\n");
	DoubleLink_DestroyList(&H);
	printf("(13)�ͷ�˫����...OK!\n");
	return 0;
}

void DoubleLink_InitList(pDoubleLinkList L)	//��ʼ��
{
	L=(struct DoubleLinkList*)malloc(sizeof(DoubleLinkList));  	//����ͷ���
	L->prior=L->next=NULL;
}

void DoubleLink_DestroyList(pDoubleLinkList L)	//�������Ա�
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

status DoubleLink_ListEmpty(pDoubleLinkList L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return (L->next==NULL);
}

int DoubleLink_ListLength(pDoubleLinkList L)	//�����Ա�ĳ���
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

void DoubleLink_DispList(pDoubleLinkList L)	//������Ա�
{
	pDoubleLinkList p = L->next;
	while (p != NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}

status DoubleLink_GetElem(pDoubleLinkList L, int i, ElemType* e)	//�����Ա���ĳ������Ԫ��ֵ
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

int DoubleLink_LocateElem(pDoubleLinkList L, ElemType e)//��Ԫ��ֵ����
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

status DoubleLink_ListInsert(pDoubleLinkList L, int i, ElemType e)	//��������Ԫ��
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

status DoubleLink_ListDelete(pDoubleLinkList L, int i, ElemType *e)	//ɾ������Ԫ��
{
	int j = 0;
	pDoubleLinkList p = L, q;
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//δ�ҵ���i-1�����
		return 0;
	else						//�ҵ���i-1�����*p
	{
		q = p->next;				//qָ��Ҫɾ���Ľ��
		if (q == NULL)
        return 0;	//�����ڵ�i�����
		e = q->data;
		p->next = q->next;		//�ӵ�������ɾ��*q���
		if (p->next != NULL)
        q->prior = p;
		free(q);				//�ͷ�*q���
		return 1;
	}
}
