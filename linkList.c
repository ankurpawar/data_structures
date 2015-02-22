/*Linked list*/
#include<stdio.h>
#include<malloc.h>

typedef struct node{
	            int data;
		    struct node* next;  
                   } NODE;

typedef struct node* pNODE;


pNODE insertBeg(pNODE,int);
void display(pNODE);
pNODE deleteBeg(pNODE);
pNODE insertEnd(pNODE,int);
pNODE insert_mid(pNODE,int,int);
void delete_mid(pNODE,int);

int main()
{
 pNODE start=NULL;
 int choice=0,isexit=0,data;

 while(!isexit)
 {
   printf("Enter choice\n"
           "1.Insert at begining\n"
           "2.Delete at begining\n"
           "3.Display\n"
           "4.Insert at end\n"
           "5.Insert in middle\n"
           "6.Delete in middle\n" 
           "7.Exit\n");
   scanf("%d",&choice); 
   switch(choice)
   {
     case 1:printf("Enter data\n"); 
	    scanf("%d",&data);
	    start=insertBeg(start,data);
	    //printf("%d\n",start);
	    break; 
   
     case 2:start=deleteBeg(start);
	    //printf("%d\n",start);
	    break; 
    
     case 3:display(start);
	    break; 
   
     case 4:printf("Enter data\n"); 
	    scanf("%d",&data);
	    start=insertEnd(start,data);
            break;
     case 5:printf("Enter data\n");
            scanf("%d",&data);
            start=insert_mid(start,data,3);  
            break;
     case 6:printf("Enter data to be deleted\n");
            scanf("%d",&data);
            delete_mid(start,data);
            break;
     case 7:isexit=1;
	    break; 
	    
     default:printf("Invalid Choice\n");
            break; 	     
   }
    

 }
 

 return 0;
}


/*---------insert at begining------------*/
pNODE  insertBeg(pNODE start,int val)
{
 pNODE p;

 p=(pNODE)malloc(sizeof(NODE));

 p->data=val;

 p->next=start;

 start=p;

 //printf("%d %d\n",p->data,start);
 return start;
}

/*---------display------------*/
void display(pNODE start)
{
  pNODE p=start;
  //printf("%d\n",start);
  
  if(start==NULL)
  {
   printf("Empty List\n"); 
   return; 
  }

  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}


/*--------Delete at begining---------*/
pNODE deleteBeg(pNODE start)
{
  if(start==NULL)
  {
   printf("Empty List\n");
   return NULL;
  }
  
  pNODE p=start;
  start=p->next;
  

  free(p);
  return start;
}


/*--------Insert at end-------------*/
pNODE insertEnd(pNODE start,int data)
{
  pNODE temp,ptr;
  ptr=start;
  temp=(pNODE)malloc(sizeof(NODE));
  
  if(start==NULL)
  {
    temp->data=data;	  
    start=temp;  
  }
  else
  {
     while(ptr->next!=NULL)
     { 
       ptr=ptr->next;
     }
  
    temp->data=data;
    temp->next=NULL;
    ptr->next=temp;
  }

  return start;
}

/*--------Delete at end-------------*/
int delatend(pNODE start)
{
  pNODE ptr=start;
  pNODE prev=NULL;

  while(ptr->next!=NULL)
  {
    prev=ptr;   
    ptr=prev->next;
  }
}

/*--------Insert in middle----------*/
pNODE insert_mid(pNODE start,int data,int pos)
{
  pNODE temp,ptr,prev;
  int i=0;
  ptr=start;
  
  while(ptr!=NULL && i<pos)
  {
    prev=ptr;
    ptr=ptr->next;
    i++;
  } 

  if(ptr!=NULL)
  {
     temp=(pNODE)malloc(sizeof(NODE)); 
     temp->data=data;
     temp->next=ptr;
     prev->next=temp; 
  }
  else
  {
     printf("position out of bound\n");
  }
  return start; 
} 

/*--------Delete in middle----------*/
void delete_mid(pNODE start,int key)
{
  pNODE ptr,prev,r;
  ptr=start;
  while(ptr!=NULL)
  {
     if(ptr->data==key)
         break;
     prev=ptr;
     ptr=ptr->next;
  }
  
  if(ptr==NULL)
  {
     printf("key not found\n");
     return;
  }

  r=ptr->next;
  prev->next=r;
  free(ptr);

}

