#include <stdio.h>
#include <stdlib.h>
/*
*内容：单链表
*作者：朱国柱
*时间: 2017/11/16
*/

#define TRUE 1
#define FAlSE 0
typedef int Status;
typedef int ElemType;
typedef struct SingleLinkedList{
    ElemType data; //节点数据
    struct SingleLinkedList* next; //节点的后继节点地址
}SingleLinkedList, * pSingleLinkedList;

Status InitSingleLinkedList(pSingleLinkedList *L);//初始话单链表
Status SingleLinkedListEmpty(pSingleLinkedList L);//判空
Status InsertSingleLinkedList(pSingleLinkedList L, int i, ElemType e);//尾插法
void   DispSingleLinkedList(pSingleLinkedList L);//输出元素
int GetLength(pSingleLinkedList L);//求单链表的长度
ElemType GetElemSingleLinkedList(pSingleLinkedList L, int i);//获取指定位置的元素
int LocateSingleLinkedList(pSingleLinkedList L, ElemType e);//获取指定元素的位置
Status DestroySingleLinkedList(pSingleLinkedList L);//销毁单链表
Status DelSingleLinkedList(pSingleLinkedList L, int i, ElemType *e);//删除元素
int main()
{
    SingleLinkedList* L;//单链表指针(即头结点)
    ElemType e;
    printf("\n单链表的基本运算:\n");
    printf("(1)单链表的初始化:\n");
    if(InitSingleLinkedList(&L) == TRUE){
        printf("初始化单链表成功\n");
    }else{
        printf("初始化单链表失败\n");
    }
    printf("(2)单链表的判空:\n");
    if(SingleLinkedListEmpty(L) == TRUE){
        printf("空\n");
    }else{
        printf("非空\n");
    }
    printf("(3)单链表插入元素：\n");
    InsertSingleLinkedList(L, 1, 1);
    InsertSingleLinkedList(L, 2, 2);
    InsertSingleLinkedList(L, 3, 3);
    printf("(4)单链表的判空:\n");
    if(SingleLinkedListEmpty(L) == TRUE){
        printf("空\n");
    }else{
        printf("非空\n");
    }
    printf("(5)输出单链表:\n");
    DispSingleLinkedList(L);
    printf("(6)单链表的长度\n");
    printf("%d", GetLength(L));
    printf("(7)获取指定（第2）位置的元素：\n");
    printf("%d\n", GetElemSingleLinkedList(L, 2));
    printf("(8)获取指定(元素2）元素的位置:\n");
    printf("%d\n", LocateSingleLinkedList(L, 2));
    printf("(9)删除（第1）元素：\n");
    DelSingleLinkedList(L, 1, &e);
    printf("%d\n" , e);
    printf("(10)输出单链表:\n");
    DispSingleLinkedList(L);
    printf("(11)销毁单链表\n");
    DestroySingleLinkedList(L);
    printf("(12)输出单链表:\n");
    //DispSingleLinkedList(L);
    return 0;
}

//初始化单链表
Status InitSingleLinkedList(pSingleLinkedList *L){
    (*L) = (struct SingleLinkedList*)malloc(sizeof(struct SingleLinkedList));
    (*L)->next = NULL;
     return TRUE;
}

//判空
Status SingleLinkedListEmpty(pSingleLinkedList L){
    return (L->next == NULL);
}

//尾插法插入一个元素
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

//输出元素
void DispSingleLinkedList(pSingleLinkedList L){
    pSingleLinkedList p = L->next;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//线性表的长度
int GetLength(pSingleLinkedList L){
    pSingleLinkedList p = L->next;
    int length = 0;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}

//获取指定位置的元素
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

//获取指定元素的位置
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

//删除元素
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
     p->next = q->next;//先连后删
     free(q);
     return 1;
}

//销毁单链表
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


