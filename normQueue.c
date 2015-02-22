#include<stdio.h>

#define MAX 5


typedef struct Queue{int arr[MAX];int r;int f;} QUEUE;

void initQueue(QUEUE *);
void display(QUEUE *);
int isempty(QUEUE *);
int isfull(QUEUE *);
int addatend(QUEUE *i,int *);
int removefront(QUEUE *,int *);

int main()
{
 int i=0,isexit=0,choice,data;
 QUEUE 	q1;
 QUEUE* pq1=&q1;
 initQueue(pq1); 
 while(!isexit)
 {
  printf("Enter choice\n1.Add at end\n2.Remove front\n3.Dsiplay\n4.Exit\n") ;
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter data\n");
	  scanf("%d",&data);
	  addatend(pq1,&data);
          break; 

   case 2:if(removefront(pq1,&data))
             printf("Element removed=%d\n",data);		  
          break;

   case 3:display(pq1);
          break;

   case 4:isexit=1;	  
	  break;  

   default:printf("Invalid Choice\n");
	   break; 
  }

  
 } 

 return 0;
}


/*---------Initialize queue----------*/
void initQueue(QUEUE *p1)
{
 p1->r=-1;
 p1->f=0;
}

/*---------Is empty------------------*/
int isempty(QUEUE *p1)
{
 /*printf("r%d f%d\n",p1->r+1,p1->f);*/
 return ((p1->r+1)==p1->f);
}

/*-----------Is full----------------*/
int isfull(QUEUE *p1)
{
 return ((p1->r)==(MAX-1));
}

/*-----------Display---------------*/
void display(QUEUE *p1)
{
  int i;
  if(isempty(p1))
     printf("Empty queue\n");
  else
  {
    //printf("r%d f%d\n",p1->r,p1->f);
    for(i=p1->f;i<=p1->f;i++)
    {
       printf("%d ",p1->arr[i]); 
    }
  }
  printf("\n");
}

/*----------remove front-------------*/
int removefront(QUEUE *p1,int *data)
{
  int *f=&p1->f;
  if(isempty(p1))
  {
    printf("Queue Empty\n");
    return 0;
  }  
  else
  {
   *data=p1->arr[(*f)++];
   return 1;
  }
}

/*----------add at end----------------*/
int addatend(QUEUE *p1,int *data)
{ 
  int *r=&p1->r;
  if(isfull(p1))
  {
    printf("Queue FUll\n");
    return 0;
  }
  else
  {
    p1->arr[++(*r)]=*data;
    return 1;
  }
}
