#include <stdio.h>
#include <stdlib.h>
/*
*���ݣ�������
*���ߣ������
*ʱ��: 2017/11/16
*/

#define TRUE 1
#define FAlSE 0
typedef int Status;
typedef int ElemType;
typedef struct SingleLinkedList{
    ElemType data; //�ڵ�����
    struct SingleLinkedList* next; //�ڵ�ĺ�̽ڵ��ַ
}SingleLinkedList, * pSingleLinkedList;

Status InitSingleLinkedList(pSingleLinkedList *L);//��ʼ��������
Status SingleLinkedListEmpty(pSingleLinkedList L);//�п�
Status InsertSingleLinkedList(pSingleLinkedList L, int i, ElemType e);//β�巨
void   DispSingleLinkedList(pSingleLinkedList L);//���Ԫ��
int GetLength(pSingleLinkedList L);//������ĳ���
ElemType GetElemSingleLinkedList(pSingleLinkedList L, int i);//��ȡָ��λ�õ�Ԫ��
int LocateSingleLinkedList(pSingleLinkedList L, ElemType e);//��ȡָ��Ԫ�ص�λ��
Status DestroySingleLinkedList(pSingleLinkedList L);//���ٵ�����
Status DelSingleLinkedList(pSingleLinkedList L, int i, ElemType *e);//ɾ��Ԫ��
int main()
{
    SingleLinkedList* L;//������ָ��(��ͷ���)
    ElemType e;
    printf("\n������Ļ�������:\n");
    printf("(1)������ĳ�ʼ��:\n");
    if(InitSingleLinkedList(&L) == TRUE){
        printf("��ʼ��������ɹ�\n");
    }else{
        printf("��ʼ��������ʧ��\n");
    }
    printf("(2)��������п�:\n");
    if(SingleLinkedListEmpty(L) == TRUE){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(3)���������Ԫ�أ�\n");
    InsertSingleLinkedList(L, 1, 1);
    InsertSingleLinkedList(L, 2, 2);
    InsertSingleLinkedList(L, 3, 3);
    printf("(4)��������п�:\n");
    if(SingleLinkedListEmpty(L) == TRUE){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(5)���������:\n");
    DispSingleLinkedList(L);
    printf("(6)������ĳ���\n");
    printf("%d", GetLength(L));
    printf("(7)��ȡָ������2��λ�õ�Ԫ�أ�\n");
    printf("%d\n", GetElemSingleLinkedList(L, 2));
    printf("(8)��ȡָ��(Ԫ��2��Ԫ�ص�λ��:\n");
    printf("%d\n", LocateSingleLinkedList(L, 2));
    printf("(9)ɾ������1��Ԫ�أ�\n");
    DelSingleLinkedList(L, 1, &e);
    printf("%d\n" , e);
    printf("(10)���������:\n");
    DispSingleLinkedList(L);
    printf("(11)���ٵ�����\n");
    DestroySingleLinkedList(L);
    printf("(12)���������:\n");
    //DispSingleLinkedList(L);
    return 0;
}

//��ʼ��������
Status InitSingleLinkedList(pSingleLinkedList *L){
    (*L) = (struct SingleLinkedList*)malloc(sizeof(struct SingleLinkedList));
    (*L)->next = NULL;
     return TRUE;
}

//�п�
Status SingleLinkedListEmpty(pSingleLinkedList L){
    return (L->next == NULL);
}

//β�巨����һ��Ԫ��
Status InsertSingleLinkedList(pSingleLinkedList L, int i, ElemType e){
    int j = 0;
    pSingleLinkedList p = L;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return 0;
    }
    pSingleLinkedList s = ((struct SingleLinkedList*)malloc(sizeof(struct SingleLinkedList)));
    s->data = e;
    s->next = NULL;
    s->next = p->next;
    p->next = s;
    return TRUE;
}

//���Ԫ��
void DispSingleLinkedList(pSingleLinkedList L){
    pSingleLinkedList p = L->next;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//���Ա�ĳ���
int GetLength(pSingleLinkedList L){
    pSingleLinkedList p = L->next;
    int length = 0;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}

//��ȡָ��λ�õ�Ԫ��
ElemType GetElemSingleLinkedList(pSingleLinkedList L, int i){
    int j = 0;
    pSingleLinkedList p = L->next;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return -1;
    }
    return p->data;
}

//��ȡָ��Ԫ�ص�λ��
int LocateSingleLinkedList(pSingleLinkedList L, ElemType e){
    pSingleLinkedList p = L->next;
    int i = 1;
    while(p != NULL){
        if(p->data == e ){
            return i;
        }
        i++;
        p = p->next;
    }
    return 0;
}

//ɾ��Ԫ��
Status DelSingleLinkedList(pSingleLinkedList L, int i, ElemType *e){
    int j = 0;
    pSingleLinkedList p = L, q;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return 0;
    }
     q = p->next;
    if(q == NULL){
        return 0;
    }
    *e=q->data;
     p->next = q->next;//������ɾ
     free(q);
     return 1;
}

//���ٵ�����
Status DestroySingleLinkedList(pSingleLinkedList L){
    pSingleLinkedList p = L , q = L->next;
    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
    return 0;
}


