#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5
#define isoperator(x) x=='+'||x=='*'||x=='/'||x=='-'||x=='%'||x=='('||x==')' 
typedef char DATA;

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
 int i=0,t2,t1,ri,j=0;
 
 char infixstr[]="234*-",ch,op2,op1; 
 char postfixstr[30];
 STACK s1={};
 s1.top=-1;
 STACK *sp1;
 
 sp1=&s1;
 
 int expLen=strlen(str);

 for( i=0 ; i<expLen ; i++ )
 {
   ch=infixstr[i];
   
   if(isdigit(ch))
   {
     //t1=atoi(&ch);
     postfixstr[j++]=ch; 
   }
   else    
   {
      t1=getToken(ch);
      if(t1==1) /*Right paran*/
      {
        op=0;
        while(op!='(')
        {
          pop(sp1,&ch);
          if(ch==')')
            break;
          op=ch;
          postfixstr[j++]=ch;  
        } 
        
      }
      
      if(t1==0)
      {
        push(sp1,)
      } 
      
   }
}
 //pop(sp1,&r);
 printf("result=%s",postfix); 
 //display(sp1); 

 return 0;
}

int getToken(char ch)
{
  //char ch=*sym[n++];
  switch(ch)
  {
    case '(' :return 0;
    case ')' :return 1;
    case '+' :return 2;
    case '-' :return 3;
    case '/' :return 4;
    case '*' :return 5;
    case '%' :return 6;    
  }

}



/*----------POP data--------------*/
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

/*---------PUSH data--------------*/
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
