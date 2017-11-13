#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//定义ElemType数据元素类型
//定义单链表结点存储结构与数据类型
typedef int ElemType;
typedef int status;
typedef struct SingleLinkList{
    ElemType data;
    struct SingleLinkList* next;
}SingleLinkList, * pSingleLinkList;

void InitList(pSingleLinkList L);//初始化线性表，创建头结点
void DestroyList(pSingleLinkList L);//销毁线性表
status ListEmpty(pSingleLinkList L);//判断线性表是否为空
int  ListLength(pSingleLinkList L);//求线性表的长度
void DispList(pSingleLinkList L);//输出线性表
void GetElem(pSingleLinkList L, int i, ElemType *e);//求线性表中第i个数据元素值,其值放入e中
int  LocateElem(pSingleLinkList L, ElemType e);//按元素值e查找位置
void ListInsert(pSingleLinkList L, int i, ElemType e);//在第i个位置插入数据元素e
status ListDelete(pSingleLinkList L, int i, ElemType *e);//删除第i个数据元素，其值放到e中

int main()
{
    SingleLinkList linkList;
    ElemType e;
    printf("单链表的基本运算如下:\n");
    printf("(1)初始话单链表\n");
    InitList(&linkList);
    printf("(2)依次采用尾插法插入1，2，3，4，5元素\n");
    ListInsert(&linkList, 1, 1);
    ListInsert(&linkList, 2, 2);
    ListInsert(&linkList, 3, 3);
    ListInsert(&linkList, 4, 4);
    ListInsert(&linkList, 5, 5);
    printf("(3)依次输出单链表元素\n");
    DispList(&linkList);
    /*printf("(4)单链表的长度:%d\n", ListLength(&linkList));
    printf("(5)判断单链表是否为空\n");
    if(ListEmpty(&linkList) == 1){
        printf("空\n");
    }else{
        printf("不为空\n");
    }
    GetElem(&linkList, 1, &e);
    e = 1;
    printf("(6)按元素值e查找位置\n");
    printf("%d", LocateElem(&linkList, e));
    printf("(7)删除第i个数据元素，其值放在e中\n");
    if(ListDelete(&linkList, 1, &e) == 1){
        printf("删除成功\n");
    }else{
        printf("删除失败\n");
    }
    DestroyList(&linkList);
    printf("%d", e);
    */return 0;
}

//初始化单链表
void InitList(pSingleLinkList L){
    L = (struct SingleLinkList*)malloc(sizeof(SingleLinkList));
    L->next = NULL;
}

//插入数据元素
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

//输出单链表元素
void DispList(pSingleLinkList L){
    pSingleLinkList p = L->next;
    while(p != NULL){
        printf("%d", p->data);
        p = p->next;
    }
    return ;
}

//求线性表的长度
int  ListLength(pSingleLinkList L){
    int length = 0;
    pSingleLinkList p = L->next;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}

//判断线性表是否为空
status ListEmpty(pSingleLinkList L){
    if(L->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

//求线性表中第i个数据元素值,其值放入e中
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

//按元素值e查找位置
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

//删除第 i个元素，将返回值存在e中
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

//销毁单链表
void DestroyList(pSingleLinkList L){
    pSingleLinkList p = L->next, q;
    while(p != NULL){
        q = p;
        free(q);
        p = p->next;
    }
}







