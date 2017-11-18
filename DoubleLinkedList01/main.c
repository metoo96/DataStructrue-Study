#include <stdio.h>
#include <stdlib.h>
/**
*内容:双链表
*作者:朱国柱
*时间:2017/11/16
*/
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct DoubleLinkedList{
    ElemType data;//数据域
    struct DoubleLinkedList *prior;//前驱节点
    struct DoubleLinkedList *next;//后继节点
}DoubleLinkedList, *pDoubleLinkedList;

void InitDoubleLinkedList(pDoubleLinkedList *L);//初始化双链表
Status DoubleLinkedListEmpty(pDoubleLinkedList L);//判空
Status InsertDoubleLinkedList(pDoubleLinkedList L, int i, ElemType e);//按指定位置插入数据
void DispDoubleLinkedList(pDoubleLinkedList L);//输出双链表
void GetElemDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e);//按指定位置获取元素
int LocateDoubleLinkedList(pDoubleLinkedList L, ElemType e);
Status DelDoubleLinkedList(pDoubleLinkedList L, int i, ElemType *e);
Status DestroyDoubleLinkedList(pDoubleLinkedList L);
int main()
{
    pDoubleLinkedList L;
    ElemType e;
    printf("双链表的基本运算\n");
    printf("(1)初始化双链表\n");
    InitDoubleLinkedList(&L);
    printf("(2)双链表是否为空\n");
    if (DoubleLinkedListEmpty(L) == TRUE) {
        printf("空\n");

    }else{
        printf("非空\n");
    }
    printf("(3)插入数据\n");
    InsertDoubleLinkedList(L, 1, 1);
    InsertDoubleLinkedList(L, 2, 2);
    InsertDoubleLinkedList(L, 3, 3);
    printf("(4)双链表是否为空\n");
    if (DoubleLinkedListEmpty(L) == TRUE) {
        printf("空\n");

    }else{
        printf("非空\n");
    }
    printf("输出双链表\n");
    DispDoubleLinkedList(L);
    printf("(5)按指定位置获取元素\n");
    GetElemDoubleLinkedList(L, 1, &e);
    printf("%d\n", e);
    printf("(6)指定元素第一次出现的位置：\n");
    printf("%d\n", LocateDoubleLinkedList(L, 1));
    printf("(7)删除指定位置的元素\n");
    DelDoubleLinkedList(L, 1, &e);
    printf("%d\n", e);
    printf("(8)输出双链表\n");
    DispDoubleLinkedList(L);
    printf("(9)销毁双链表\n");
    DestroyDoubleLinkedList(L);
    return 0;
}

//初始化双链表
void InitDoubleLinkedList(pDoubleLinkedList *L){
    (*L) = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

//判空
Status DoubleLinkedListEmpty(pDoubleLinkedList L){
    return (L->next == NULL);
}

//插入数据（按指定位置）
Status InsertDoubleLinkedList(pDoubleLinkedList L, int i, ElemType e){
    int j = 0;//索引
    pDoubleLinkedList p = L, s;//指向的是首节点
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    //如果是空表的话
    if (p == NULL) {
        return 0;
    }else{
       s = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
       s->data = e;
       s->next = NULL;
       s->next = p->next;//先连
       if(p->next != NULL)
       p->next->prior = s;
       s->prior = p;
       p->next = s;//后断
       return TRUE;
    }
}

//输出双链表
void DispDoubleLinkedList(pDoubleLinkedList L){
    pDoubleLinkedList p = L->next;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//按指定的位置获取元素
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

//按指定元素指定它第一次出现的位置
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

//删除指定位置的双链表元素(并存储到e中)
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

//销毁双链表
Status DestroyDoubleLinkedList(pDoubleLinkedList L){
    pDoubleLinkedList p = L, q = L->next;
    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
}
