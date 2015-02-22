/*Circular Queue*/
#include<stdio.h>

#define MAX 5


typedef struct cQueue{int arr[MAX];int r;int f;int numEl;} QUEUE;

void initQueue(QUEUE *);
void display(QUEUE *);
int isempty(QUEUE *);
int isfull(QUEUE *);
int addatend(QUEUE *i,int *);
int removefront(QUEUE *,int *);

int main()
{
 int i=0,isexit=0,choice,data;
 QUEUE q1;
 QUEUE* pq1;
 pq1=&q1; 
 initQueue(pq1);

 while(!isexit)
 {
   printf("Enter choice\n1.Add at end\n2.Delete from front\n3.Display\n4.Exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1:printf("Enter Data\n");
	    scanf("%d",&data);
	    addatend(pq1,&data);
	    break;

     case 2:if(removefront(pq1,&data))
               printf("element removed=%d\n",data);
	    break;

     case 3:display(pq1);
	    break;
	  
     case 4:isexit=1;	    
	    break;

     default:printf("Invalid choice\n");
	     break;
   }
  
 }
  

 return 0;
}

/*----------Initialize queue----------*/
void initQueue(QUEUE *p1)
{
 p1->r=-1;
 p1->f=0;
 p1->numEl=0;
}

/*----------Is empty----------*/
int isempty(QUEUE *p1)
{
 return ((p1->numEl)==0);
}

/*---------If full-----------*/
int isfull(QUEUE *p1)
{
 return ((p1->numEl)==(MAX));
}

/*---------display-----------*/
void display(QUEUE *p1)
{
  int i;
  int f=p1->f,r=p1->r;

  if(isempty(p1))
     printf("Empty queue\n");
  else
  {
    if(f<=r)
    {
      for(i=f;i<=r;i++)
      {
        printf("%d ",p1->arr[i]);
      }
    }	    
    else
    {
      for(i=f;i<=MAX-1;i++)
      {
        printf("%d ",p1->arr[i]); 
      }
      
      for(i=0;i<=r;i++)
      {
        printf("%d ",p1->arr[i]); 
      }

    }
    printf("\n");
  }

}

/*-------------Remove front element---------*/
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
   *data=p1->arr[*f];
   *f=(*f+1)%MAX;
   p1->numEl--; 
   return 1;
  }
}

/*-----------Insert at end-----------------*/
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
    *r=(*r+1)%MAX;	  
    p1->arr[*r]=*data;
    p1->numEl++;
    return 1;
  }
}
