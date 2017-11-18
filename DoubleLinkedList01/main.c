#include <stdio.h>
#include <stdlib.h>
/**
*����:˫����
*����:�����
*ʱ��:2017/11/16
*/
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct DoubleLinkedList{
    ElemType data;//������
    struct DoubleLinkedList *prior;//ǰ���ڵ�
    struct DoubleLinkedList *next;//��̽ڵ�
}DoubleLinkedList, *pDoubleLinkedList;

void InitDoubleLinkedList(pDoubleLinkedList *L);//��ʼ��˫����
Status DoubleLinkedListEmpty(pDoubleLinkedList L);//�п�
Status InsertDoubleLinkedList(pDoubleLinkedList L, int i, ElemType e);//��ָ��λ�ò�������
void DispDoubleLinkedList(pDoubleLinkedList L);//���˫����
void GetElemDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e);//��ָ��λ�û�ȡԪ��
int LocateDoubleLinkedList(pDoubleLinkedList L, ElemType e);
Status DelDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e);
Status DestroyDoubleLinkedList(pDoubleLinkedList L);
int main()
{
    pDoubleLinkedList L;
    ElemType e;
    printf("˫����Ļ�������\n");
    printf("(1)��ʼ��˫����\n");
    InitDoubleLinkedList(&L);
    printf("(2)˫�����Ƿ�Ϊ��\n");
    if (DoubleLinkedListEmpty(L) == TRUE) {
        printf("��\n");

    }else{
        printf("�ǿ�\n");
    }
    printf("(3)��������\n");
    InsertDoubleLinkedList(L, 1, 1);
    InsertDoubleLinkedList(L, 2, 2);
    InsertDoubleLinkedList(L, 3, 3);
    printf("(4)˫�����Ƿ�Ϊ��\n");
    if (DoubleLinkedListEmpty(L) == TRUE) {
        printf("��\n");

    }else{
        printf("�ǿ�\n");
    }
    printf("���˫����\n");
    DispDoubleLinkedList(L);
    printf("(5)��ָ��λ�û�ȡԪ��\n");
    GetElemDoubleLinkedList(L, 1, &e);
    printf("%d\n", e);
    printf("(6)ָ��Ԫ�ص�һ�γ��ֵ�λ�ã�\n");
    printf("%d\n", LocateDoubleLinkedList(L, 1));
    printf("(7)ɾ��ָ��λ�õ�Ԫ��\n");
    DelDoubleLinkedList(L, 1, &e);
    printf("%d\n", e);
    printf("(8)���˫����\n");
    DispDoubleLinkedList(L);
    printf("(9)����˫����\n");
    DestroyDoubleLinkedList(L);
    return 0;
}

//��ʼ��˫����
void InitDoubleLinkedList(pDoubleLinkedList *L){
    (*L) = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

//�п�
Status DoubleLinkedListEmpty(pDoubleLinkedList L){
    return (L->next == NULL);
}

//�������ݣ���ָ��λ�ã�
Status InsertDoubleLinkedList(pDoubleLinkedList L, int i, ElemType e){
    int j = 0;//����
    pDoubleLinkedList p = L, s;//ָ������׽ڵ�
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    //����ǿձ�Ļ�
    if (p == NULL) {
        return 0;
    }else{
       s = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
       s->data = e;
       s->next = NULL;
       s->next = p->next;//����
       if(p->next != NULL)
       p->next->prior = s;
       s->prior = p;
       p->next = s;//���
       return TRUE;
    }
}

//���˫����
void DispDoubleLinkedList(pDoubleLinkedList L){
    pDoubleLinkedList p = L->next;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//��ָ����λ�û�ȡԪ��
void GetElemDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e){
    int j = 0;
    pDoubleLinkedList p = L->next;
    while(p != NULL && j< i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return ;
    }else{
        *e = p->data;
        return;
    }
}

//��ָ��Ԫ��ָ������һ�γ��ֵ�λ��
int LocateDoubleLinkedList(pDoubleLinkedList L, ElemType e){
     int j = 1;
     pDoubleLinkedList p = L->next;
     while(p != NULL){
        if(p->data == e){
            return j;
        }
        p = p->next;
        j++;
     }
}

//ɾ��ָ��λ�õ�˫����Ԫ��(���洢��e��)
Status DelDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e){
    int j = 0;
    pDoubleLinkedList p = L, q;
    while(p !=NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return 0;
    }else{
       q = p->next;
       p->next = q->next;
       q->next->prior = p;
       *e = q->data;
       free(q);
       return 0;
    }
}

//����˫����
Status DestroyDoubleLinkedList(pDoubleLinkedList L){
    pDoubleLinkedList p = L, q = L->next;
    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
}
