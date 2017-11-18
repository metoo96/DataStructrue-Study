#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;
typedef int status;
typedef struct SqStack{
    ElemType data[MAXSIZE];
    int top;//ջ��
}SqStack, * pSqStack;

void InitStack(pSqStack *S);//��ʼ��˳��ջS
void DestroyStack(pSqStack S);//����˳��ջS
status StackEmpty(pSqStack S);//�ж�˳��ջջ��
status Push(pSqStack S, ElemType e);//˳��ջ��ջ
status Pop(pSqStack S, ElemType *e);//˳��ջ��ջ
status GetTop(pSqStack S, ElemType *e);//ȡ˳��ջջ��Ԫ��

int main()
{
    ElemType e;
    SqStack *s;
    printf("˳��ջ������:\n");
    printf("(1)��ʼ��˳��ջ��\n");
    InitStack(&s);
    printf("(2)�ж�˳ջ�Ƿ�Ϊ�գ�\n");
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
    GetTop(s, &e);
    printf("GetTop:%d:\n", e);
    printf("(4)�ж�˳ջ�Ƿ�Ϊ�գ�\n");
    if(StackEmpty(s) == 1){
        printf("��\n");
    }else{
        printf("�ǿ�\n");
    }
    printf("(5)˳��ջ��ջ��\n");
    while(StackEmpty(s) != 1){
        Pop(s, &e);
        printf("%d\n", e);
    }
    printf("(6)�ж�˳ջ�Ƿ�Ϊ�գ�\n");
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
void InitStack(pSqStack *S){
    *S = ((struct SqStack*)malloc(sizeof(struct SqStack)));
    (*S)->top = -1;
}

//����˳��ջS
void DestroyStack(pSqStack S){
    free(S);
}

//�ж�˳��ջջ��
status StackEmpty(pSqStack S){
    if(S->top == -1){
        return 1;
    }else{
        return 0;
    }
}

//˳��ջ��ջ
status Push(pSqStack S, ElemType e){
    if(S->top > MAXSIZE-1){
        return 0;
    }
    S->top++;
    S->data[S->top] = e;
    return 1;
}

//˳��ջ��ջ
status Pop(pSqStack S, ElemType *e){
    if(S->top == -1){
        return 0;
    }
    *e = S->data[S->top];
    S->top--;
    return 1;
}

//ȡ˳��ջջ��Ԫ��
status GetTop(pSqStack S, ElemType *e){
    if(S->top == -1){
        return 0;
    }
    *e = S->data[S->top];
    return 1;
}



