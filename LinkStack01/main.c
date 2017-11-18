#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef int status;
typedef struct LinkStack{
    ElemType data;
    struct LinkStack* next;
}LinkStack, * pLinkStack;

void InitStack(pLinkStack *s);//��ʼ����ջS
void DestroyStack(pLinkStack S);//������ջS
status StackEmpty(pLinkStack S);//�ж���ջջ��
status Push(pLinkStack S, ElemType e);//��ջ��ջ
status Pop(pLinkStack S, ElemType *e);//��ջ��ջ
status GetTop(pLinkStack S, ElemType *e);//ȡ��ջջ��Ԫ��

int main()
{
    ElemType e;
    pLinkStack s;
    printf("��ջ������:\n");
    printf("(1)��ʼ��˳��ջ��\n");
    InitStack(&s);
    printf("(2)�ж���ջ�Ƿ�Ϊ�գ�\n");
    if(StackEmpty(s) == 1){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(3)���ν������������͵�Ԫ��1��2��3��4��5��ջ\n");
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    Push(s, 5);
    printf("(4)�ж���ջ�Ƿ�Ϊ�գ�\n");
    if(StackEmpty(s) == 1){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(5)��ջ��ջ��\n");
    while(StackEmpty(s) != 1){
        Pop(s, &e);
        printf("%d\n", e);
    }
    printf("(6)�ж���ջ�Ƿ�Ϊ�գ�\n");
    if(StackEmpty(s) == 1){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(7)�ͷŲ�����˳��ջ��\n");
    DestroyStack(s);
    return 0;
}

//��ʼ��˳��ջS
void InitStack(pLinkStack *s){
    *s = (struct LinkStack*)malloc(sizeof(struct LinkStack));
    (*s)->next = NULL;
}

//������ջ
void DestroyStack(pLinkStack S){
    pLinkStack p = S, q = S->next;
	while (q != NULL)
	{	free(p);
		p=q;
		q=p->next;
	}
	free(p);
}

//�ж���ջջ��
status StackEmpty(pLinkStack S){
   if(S->next == NULL){
     return 1;
   }else{
     return 0;
   }
}

//��ջ��ջ
status Push(pLinkStack S, ElemType e){
    pLinkStack p = (struct LinkStack*)malloc(sizeof(struct LinkStack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

//��ջ��ջ
status Pop(pLinkStack S, ElemType *e){
    pLinkStack p;
	if (S->next == NULL)
		return 0;
	p = S->next;
	*e = p->data;
	S->next = p->next;
	free(p);
	return 1;
}

//ȡ��ջջ��Ԫ��
status GetTop(pLinkStack S, ElemType *e){
   if (S->next==NULL)
		return 0;
	*e=S->next->data;
    return 1;
}
