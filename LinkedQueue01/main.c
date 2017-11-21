#include <stdio.h>
#include <stdlib.h>
/**
*���ݣ� �����еĻ�������
*����:  Guozhu Zhu
*ʱ�䣻 2017/11/20
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
void InitLinkedQueue(pLinkedQueue* Q);//��ʼ������
Status LinkedQueueEmpty(pLinkedQueue Q);//�п�
Status enLinkedQueue(pLinkedQueue Q, ElemType e);//���
Status deLinkedQueue(pLinkedQueue Q, ElemType* e);//����

void DestroyQueue(pLinkedQueue Q);
int main()
{
    pLinkedQueue Q;
    ElemType e;
    printf("�����еĻ�������\n");
    printf("(1)��ʼ������\n");
    InitLinkedQueue(&Q);
    printf("(2)�п�\n");
    if (LinkedQueueEmpty(Q) == TRUE) {
        printf("��\n");
    } else{
        printf("�ǿ�\n");
    }
    printf("(3)���\n");
    enLinkedQueue(Q, 1);
    enLinkedQueue(Q, 2);
    enLinkedQueue(Q, 3);
    printf("(4)�п�\n");
    if (LinkedQueueEmpty(Q) == TRUE) {
        printf("��\n");
    } else{
        printf("�ǿ�\n");
    }
    printf("(5)����\n");
    while(LinkedQueueEmpty(Q) != TRUE){
        deLinkedQueue(Q, &e);
        printf("%d\n", e);
    }
    printf("(6)����\n");
    DestroyQueue(Q);
    return 0;
}

//��ʼ������
void InitLinkedQueue(pLinkedQueue* Q){
    (*Q) = (struct LinkedQueue*)malloc(sizeof(struct LinkedQueue));
    (*Q)->front = (*Q)->rear = NULL;
}

//�п�
Status LinkedQueueEmpty(pLinkedQueue Q){
    return (Q->rear == NULL);
}

//���
Status enLinkedQueue(pLinkedQueue Q, ElemType e){
    struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL) {		//������Ϊ��,���½ڵ��Ƕ��׽ڵ����Ƕ�β�ڵ�
		Q->front = Q->rear = p;
	}else{
	    Q->rear->next = p;	//��*p�ڵ�������β,����rearָ����
		Q->rear = p;
	}
	return TRUE;
}

//����
Status deLinkedQueue(pLinkedQueue Q, ElemType* e){
    Node *t;
	if (Q->rear == NULL)		//����Ϊ��
		return FALSE;
	t = Q->front;				//tָ���һ�����ݽڵ�
	if (Q->front == Q->rear)  //������ֻ��һ���ڵ�ʱ
		Q->front = Q->rear = NULL;
	else					//�������ж���ڵ�ʱ
		Q->front = Q->front->next;
	(*e) = t->data;
	free(t);
	return TRUE;
}

//��������
void DestroyQueue(pLinkedQueue q)	//���ٶ���
{	Node *p = q->front, *r;	//pָ���ͷ���ݽڵ�
	if (p != NULL)			//�ͷ����ݽڵ�ռ�ÿռ�
	{	r = p->next;
		while (r != NULL)
		{
		    free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);				//�ͷ����ӽڵ�ռ�ÿռ�
}


