#include <stdio.h>
#include <stdlib.h>
/*
*@Author zhuguozhu
*@time 2017/10/25
*@content ˳��ջ�ĳ���ջ
*/
#define MAXSIZE 10
typedef int ElemType;
typedef struct Stack{
    ElemType data[MAXSIZE];
    int bottom;
    int top;
    int length;
}Stack, *pStack;

int pop(pStack s);
int push(pStack s, int num);
void init(pStack s);

int main()
{
    int num;
    Stack s;
    init(&s);
    while(1){
        printf("Enter your elem:\n");
        scanf("%d", &num);
        if(num == -1){
            pop(&s);
            continue;
        }
        push(&s, num);
    }
    return 0;
}

void init(pStack s){
    s->top = s->bottom = 0;
    s->length = 0;
}

int pop(pStack s){
    if(s->length <= 0){
        printf("û��ջԪ�ؿ����\n");
        return 0;
    }
    printf("��ջ%d\n", s->data[s->top-1]);
    s->top--;
    s->length--;
    return s->data[s->top-1];
}

int push(pStack s, int num){
    if(s->length == MAXSIZE){
        printf("�����\n");
        return 0;
    }
    s->data[s->top] = num;
    printf("��ջ��%d\n", num);
    s->top++;
    s->length++;
    return num;
}

