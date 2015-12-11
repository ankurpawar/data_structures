#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5
#define isoperator(x) x=='+'||x=='*'||x=='/'||x=='-'||x=='%' 
typedef int DATA;

typedef struct stack{
                     DATA arr[MAX];
                     int top;
                    } STACK;

int push(STACK *,DATA*);
int pop(STACK *,DATA*);
int isempty(STACK *);
int isfull(STACK *);
void display(STACK *);

int main()
{
 int i=0,t2,t1,r;
 
 char str[]="234*-",ch,op2,op1; 
 STACK s1={};
 s1.top=-1;
 STACK *sp1;
 
 sp1=&s1;
 
 int expLen=strlen(str);

 for( i=0 ; i<expLen ; i++ )
 {
   ch=str[i];
   
   if(isdigit(ch))
   {
     t1=atoi(&ch);
     push(sp1,&t1); 
   }
   else if(isoperator(ch))   
   {
      pop(sp1,&t2);
      pop(sp1,&t1);
      switch(ch)
      {
        case '+':r=t2+t1;break;
        case '-':r=t2-t1;break;
        case '*':r=t2*t1;break;
        case '/':r=t2/t1;break;
        case '%':r=t2%t1;break;       
      }
      push(sp1,&r); 
      
   }
}
 pop(sp1,&r);
 printf("result=%d",r); 
 display(sp1); 

 return 0;
}

int pop(STACK *p1,DATA *data)
{ 
  int *top=&p1->top;
  if(p1->top==-1)
  {
    printf("stack empty\n");
    return 0;
  }
  else
  {
    *data=p1->arr[(*top)--];
    return 1;
  }
}

int push(STACK *p1,DATA *data)
{
  int *top=&p1->top;
  if(p1->top==MAX-1)
  {
   printf("Stack full\n");
   return 0;
  }
  else
  {
   
   p1->arr[++(*top)]=*data;
   return 1;
  }

 
}

void display(STACK *p1)
{
  int i=0;
  int top=p1->top;
  if(isempty(p1))
  {
    printf("empty list\n");
    return ; 
  }
  for(i=0;i<=top;i++)
  {
    printf("%d ",p1->arr[i]);
  } 
 
 printf("\n");

}

int isempty(STACK *p1)
{
 return (p1->top==-1);
}

int isfull(STACK *p1)
{
 return (p1->top==MAX-1);
}
