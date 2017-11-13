#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//����ElemType����Ԫ������
//���嵥������洢�ṹ����������
typedef int ElemType;
typedef int status;
typedef struct SingleLinkList{
    ElemType data;
    struct SingleLinkList* next;
}SingleLinkList, * pSingleLinkList;

void InitList(pSingleLinkList L);//��ʼ�����Ա�����ͷ���
void DestroyList(pSingleLinkList L);//�������Ա�
status ListEmpty(pSingleLinkList L);//�ж����Ա��Ƿ�Ϊ��
int  ListLength(pSingleLinkList L);//�����Ա�ĳ���
void DispList(pSingleLinkList L);//������Ա�
void GetElem(pSingleLinkList L, int i, ElemType *e);//�����Ա��е�i������Ԫ��ֵ,��ֵ����e��
int  LocateElem(pSingleLinkList L, ElemType e);//��Ԫ��ֵe����λ��
void ListInsert(pSingleLinkList L, int i, ElemType e);//�ڵ�i��λ�ò�������Ԫ��e
status ListDelete(pSingleLinkList L, int i, ElemType *e);//ɾ����i������Ԫ�أ���ֵ�ŵ�e��

int main()
{
    SingleLinkList linkList;
    ElemType e;
    printf("������Ļ�����������:\n");
    printf("(1)��ʼ��������\n");
    InitList(&linkList);
    printf("(2)���β���β�巨����1��2��3��4��5Ԫ��\n");
    ListInsert(&linkList, 1, 1);
    ListInsert(&linkList, 2, 2);
    ListInsert(&linkList, 3, 3);
    ListInsert(&linkList, 4, 4);
    ListInsert(&linkList, 5, 5);
    printf("(3)�������������Ԫ��\n");
    DispList(&linkList);
    /*printf("(4)������ĳ���:%d\n", ListLength(&linkList));
    printf("(5)�жϵ������Ƿ�Ϊ��\n");
    if(ListEmpty(&linkList) == 1){
        printf("��\n");
    }else{
        printf("��Ϊ��\n");
    }
    GetElem(&linkList, 1, &e);
    e = 1;
    printf("(6)��Ԫ��ֵe����λ��\n");
    printf("%d", LocateElem(&linkList, e));
    printf("(7)ɾ����i������Ԫ�أ���ֵ����e��\n");
    if(ListDelete(&linkList, 1, &e) == 1){
        printf("ɾ���ɹ�\n");
    }else{
        printf("ɾ��ʧ��\n");
    }
    DestroyList(&linkList);
    printf("%d", e);
    */return 0;
}

//��ʼ��������
void InitList(pSingleLinkList L){
    L = (struct SingleLinkList*)malloc(sizeof(SingleLinkList));
    L->next = NULL;
}

//��������Ԫ��
void ListInsert(pSingleLinkList L, int i, ElemType e){
    int j=0;
    pSingleLinkList p=L, s;
	while (j<i-1 && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return ;
	else
	{
	    s=(struct SingleLinkList *)malloc(sizeof(SingleLinkList));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return ;
	}
}

//���������Ԫ��
void DispList(pSingleLinkList L){
    pSingleLinkList p = L->next;
    while(p != NULL){
        printf("%d", p->data);
        p = p->next;
    }
    return ;
}

//�����Ա�ĳ���
int  ListLength(pSingleLinkList L){
    int length = 0;
    pSingleLinkList p = L->next;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}

//�ж����Ա��Ƿ�Ϊ��
status ListEmpty(pSingleLinkList L){
    if(L->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

//�����Ա��е�i������Ԫ��ֵ,��ֵ����e��
void GetElem(pSingleLinkList L, int i, ElemType *e){
    int j = 0;
    pSingleLinkList p = L->next;
    while(j < i-1 && p != NULL){
        j++;
        p = p->next;
    }
    if(p == NULL)
    {
        return ;
    }
    *e = p->data;
}

//��Ԫ��ֵe����λ��
int  LocateElem(pSingleLinkList L, ElemType e){
    int i = 0;
    pSingleLinkList p = L->next;
    while(p != NULL){
        if(p->data == e){
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}

//ɾ���� i��Ԫ�أ�������ֵ����e��
status ListDelete(pSingleLinkList L, int i, ElemType *e){
    int j=0;
	pSingleLinkList p=L, q;
	while (j<i-1 && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;
	else
	{
	    q=p->next;
		if (q==NULL)
			return 0;
		*e=q->data;
		p->next=q->next;
		free(q);
		    return 1;
	}
}

//���ٵ�����
void DestroyList(pSingleLinkList L){
    pSingleLinkList p = L->next, q;
    while(p != NULL){
        q = p;
        free(q);
        p = p->next;
    }
}







