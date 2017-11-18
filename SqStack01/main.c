#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;
typedef int status;
typedef struct SqStack{
    ElemType data[MAXSIZE];
    int top;//Õ»¶¥
}SqStack, * pSqStack;

void InitStack(pSqStack *S);//³õÊ¼»¯Ë³ÐòÕ»S
void DestroyStack(pSqStack S);//Ïú»ÙË³ÐòÕ»S
status StackEmpty(pSqStack S);//ÅÐ¶ÏË³ÐòÕ»Õ»¿Õ
status Push(pSqStack S, ElemType e);//Ë³ÐòÕ»½øÕ»
status Pop(pSqStack S, ElemType *e);//Ë³ÐòÕ»³öÕ»
status GetTop(pSqStack S, ElemType *e);//È¡Ë³ÐòÕ»Õ»¶¥ÔªËØ

int main()
{
    ElemType e;
    SqStack *s;
    printf("Ë³ÐòÕ»µÄÔËËã:\n");
    printf("(1)³õÊ¼»¯Ë³ÐòÕ»£º\n");
    InitStack(&s);
    printf("(2)ÅÐ¶ÏË³Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(3)ÒÀ´Î½«ÕûÐÍÊý¾ÝÀàÐÍµÄÔªËØ1£¬2£¬3£¬4£¬5ÈëÕ»\n");
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    Push(s, 5);
    GetTop(s, &e);
    printf("GetTop:%d:\n", e);
    printf("(4)ÅÐ¶ÏË³Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(5)Ë³ÐòÕ»³öÕ»£º\n");
    while(StackEmpty(s) != 1){
        Pop(s, &e);
        printf("%d\n", e);
    }
    printf("(6)ÅÐ¶ÏË³Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(7)ÊÍ·Å²¢Ïú»ÙË³ÐòÕ»£º\n");
    DestroyStack(s);
    return 0;
}

//³õÊ¼»¯Ë³ÐòÕ»S
void InitStack(pSqStack *S){
    *S = ((struct SqStack*)malloc(sizeof(struct SqStack)));
    (*S)->top = -1;
}

//Ïú»ÙË³ÐòÕ»S
void DestroyStack(pSqStack S){
    free(S);
}

//ÅÐ¶ÏË³ÐòÕ»Õ»¿Õ
status StackEmpty(pSqStack S){
    if(S->top == -1){
        return 1;
    }else{
        return 0;
    }
}

//Ë³ÐòÕ»½øÕ»
status Push(pSqStack S, ElemType e){
    if(S->top > MAXSIZE-1){
        return 0;
    }
    S->top++;
    S->data[S->top] = e;
    return 1;
}

//Ë³ÐòÕ»³öÕ»
status Pop(pSqStack S, ElemType *e){
    if(S->top == -1){
        return 0;
    }
    *e = S->data[S->top];
    S->top--;
    return 1;
}

//È¡Ë³ÐòÕ»Õ»¶¥ÔªËØ
status GetTop(pSqStack S, ElemType *e){
    if(S->top == -1){
        return 0;
    }
    *e = S->data[S->top];
    return 1;
}



