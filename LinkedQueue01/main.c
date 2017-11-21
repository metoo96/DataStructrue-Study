#include <stdio.h>
#include <stdlib.h>
/**
*内容： 链队列的基本运算
*作者:  Guozhu Zhu
*时间； 2017/11/20
*/
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;
typedef struct LinkedQueue{
    struct Node* front;
    struct Node* rear;
}LinkedQueue, * pLinkedQueue;
void InitLinkedQueue(pLinkedQueue* Q);//初始化队列
Status LinkedQueueEmpty(pLinkedQueue Q);//判空
Status enLinkedQueue(pLinkedQueue Q, ElemType e);//入队
Status deLinkedQueue(pLinkedQueue Q, ElemType* e);//出队

void DestroyQueue(pLinkedQueue Q);
int main()
{
    pLinkedQueue Q;
    ElemType e;
    printf("链队列的基本运算\n");
    printf("(1)初始化队列\n");
    InitLinkedQueue(&Q);
    printf("(2)判空\n");
    if (LinkedQueueEmpty(Q) == TRUE) {
        printf("空\n");
    } else{
        printf("非空\n");
    }
    printf("(3)入队\n");
    enLinkedQueue(Q, 1);
    enLinkedQueue(Q, 2);
    enLinkedQueue(Q, 3);
    printf("(4)判空\n");
    if (LinkedQueueEmpty(Q) == TRUE) {
        printf("空\n");
    } else{
        printf("非空\n");
    }
    printf("(5)出队\n");
    while(LinkedQueueEmpty(Q) != TRUE){
        deLinkedQueue(Q, &e);
        printf("%d\n", e);
    }
    printf("(6)销毁\n");
    DestroyQueue(Q);
    return 0;
}

//初始化队列
void InitLinkedQueue(pLinkedQueue* Q){
    (*Q) = (struct LinkedQueue*)malloc(sizeof(struct LinkedQueue));
    (*Q)->front = (*Q)->rear = NULL;
}

//判空
Status LinkedQueueEmpty(pLinkedQueue Q){
    return (Q->rear == NULL);
}

//入队
Status enLinkedQueue(pLinkedQueue Q, ElemType e){
    struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL) {		//若链队为空,则新节点是队首节点又是队尾节点
		Q->front = Q->rear = p;
	}else{
	    Q->rear->next = p;	//将*p节点链到队尾,并将rear指向它
		Q->rear = p;
	}
	return TRUE;
}

//出队
Status deLinkedQueue(pLinkedQueue Q, ElemType* e){
    Node *t;
	if (Q->rear == NULL)		//队列为空
		return FALSE;
	t = Q->front;				//t指向第一个数据节点
	if (Q->front == Q->rear)  //队列中只有一个节点时
		Q->front = Q->rear = NULL;
	else					//队列中有多个节点时
		Q->front = Q->front->next;
	(*e) = t->data;
	free(t);
	return TRUE;
}

//队列销毁
void DestroyQueue(pLinkedQueue q)	//销毁队列
{	Node *p = q->front, *r;	//p指向队头数据节点
	if (p != NULL)			//释放数据节点占用空间
	{	r = p->next;
		while (r != NULL)
		{
		    free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);				//释放链队节点占用空间
}


