#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef int status;
typedef struct LinkStack{
    ElemType data;
    struct LinkStack* next;
}LinkStack, * pLinkStack;

void InitStack(pLinkStack *s);//³õÊ¼»¯Á´Õ»S
void DestroyStack(pLinkStack S);//Ïú»ÙÁ´Õ»S
status StackEmpty(pLinkStack S);//ÅĞ¶ÏÁ´Õ»Õ»¿Õ
status Push(pLinkStack S, ElemType e);//Á´Õ»½øÕ»
status Pop(pLinkStack S, ElemType *e);//Á´Õ»³öÕ»
status GetTop(pLinkStack S, ElemType *e);//È¡Á´Õ»Õ»¶¥ÔªËØ

int main()
{
    ElemType e;
    pLinkStack s;
    printf("Á´Õ»µÄÔËËã:\n");
    printf("(1)³õÊ¼»¯Ë³ĞòÕ»£º\n");
    InitStack(&s);
    printf("(2)ÅĞ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(3)ÒÀ´Î½«ÕûĞÍÊı¾İÀàĞÍµÄÔªËØ1£¬2£¬3£¬4£¬5ÈëÕ»\n");
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    Push(s, 5);
    printf("(4)ÅĞ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(5)Á´Õ»³öÕ»£º\n");
    while(StackEmpty(s) != 1){
        Pop(s, &e);
        printf("%d\n", e);
    }
    printf("(6)ÅĞ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ£º\n");
    if(StackEmpty(s) == 1){
        printf("¿Õ\n");
    }else{
        printf("·Ç¿Õ\n");
    }
    printf("(7)ÊÍ·Å²¢Ïú»ÙË³ĞòÕ»£º\n");
    DestroyStack(s);
    return 0;
}

//³õÊ¼»¯Ë³ĞòÕ»S
void InitStack(pLinkStack *s){
    *s = (struct LinkStack*)malloc(sizeof(struct LinkStack));
    (*s)->next = NULL;
}

//Ïú»ÙÁ´Õ»
void DestroyStack(pLinkStack S){
    pLinkStack p = S, q = S->next;
	while (q != NULL)
	{	free(p);
		p=q;
		q=p->next;
	}
	free(p);
}

//ÅĞ¶ÏÁ´Õ»Õ»¿Õ
status StackEmpty(pLinkStack S){
   if(S->next == NULL){
     return 1;
   }else{
     return 0;
   }
}

//Á´Õ»½øÕ»
status Push(pLinkStack S, ElemType e){
    pLinkStack p = (struct LinkStack*)malloc(sizeof(struct LinkStack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

//Á´Õ»³öÕ»
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

//È¡Á´Õ»Õ»¶¥ÔªËØ
status GetTop(pLinkStack S, ElemType *e){
   if (S->next==NULL)
		return 0;
	*e=S->next->data;
    return 1;
}
