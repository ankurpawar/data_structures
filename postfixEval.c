#include<stdio.h>

#define MAX 5

typedef struct stack{int arr[MAX];int top;} STACK;

int push(STACK *,int*);
int pop(STACK *,int*);
int isempty(STACK *);
int isfull(STACK *);
void display(STACK *);

int main()
{
 int i=0;
 STACK s1={};
 s1.top=-1;
 STACK *sp1;
 sp1=&s1;
  
 while(push(sp1,&i))
 {
   printf("i=%d\n",i); 
   i++;
 }

 
 display(sp1);

 while(pop(sp1,&i))
 {
   printf("%d ",i);
 }
 printf("\n");

return 0;
}

int pop(STACK *p1,int *data)
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

int push(STACK *p1,int *data)
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
