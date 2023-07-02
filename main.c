#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct stack{
    int data[max];
    int top;
}stack;

void init(stack *);
int is_full(stack *);
int is_empty(stack *);
int push(stack *,int);
int pop(stack *s);


int main()
{
int number,k;
stack s;
init(&s);
//22
printf("\nenter the number to convert decimal to binary:");
scanf("%d",&number);
while(number!=0)
{
    k=number%2;
    push(&s,k);
    number=number/2;
}
printf("\nthe binary number after conversion is:");
while(pop(&s)!=0)
{
    pop(&s);
}


    return 0;
}

void init(stack *s)
{
    s->top=-1;
}
int is_empty(stack *s)
{
    if(s->top==-1){
        return 0;}
    else{
        return 1;
    }
}
int is_full(stack *s)
{
    if(s->top==max-1){
        return 0;
    }
    else{
        return 1;
        }
}

int push(stack *s,int value)
{
    if(is_full(s)){
        s->top=s->top+1;
        s->data[s->top]=value;
        printf("value pushed is:%d\n",s->data[s->top]);
        return 1;
    }
    else{
        return 0;
    }

}
int pop(stack *s)
{
    if(is_empty(s))
    {
        printf("%d",s->data[s->top]);
        s->top=s->top-1;
        return 1;
    }
    else
    {
        return 0;
    }
}
