/*Program to implement binary search*/

#define MAX 10

#include<stdio.h>
#include<stdlib.h>

int binsearch(int (*)[],int);
int cmpInt(const void *,const void *);

int main()
{
  	
 int arr[MAX],i=0,key;

 /*Seed rand function and assign random value in arr*/
  srand(time(0));
  printf("Elements of the array are ");
  for(i=0;i<MAX;i++)
  {
    arr[i]=rand()%20;
    printf("%d ",arr[i]);
  }

  

  printf("\n"); 
  printf("enter the key to search \n");
  scanf("%d",&key);
  printf("\n");
 
  /* */
  if(binsearch(&arr,key))
    printf("element found\n");
  else
    printf("not found\n");	 
 
   printf("\n");

   return 0;
}

/*compare two int*/
int cmpInt(const void *a,const void *b)
{
   return ( *(int*)a>*(int*)b );
}

/*Binary search function*/
int binsearch(int (*p)[MAX],int key)
{
  int len=sizeof(*p)/sizeof(int);
  int i=len-1,l,h,m;  

  l=0;
  h=len-1;
  m=(l+h)/2;

  qsort(p,MAX,sizeof(int *),cmpInt);
    
  for(i=0;i<MAX;i++)
  {
    printf("%d ",(*p)[i]);
  }

  printf("\n");
  
  while( (l!=h) && (key!=(*p)[m]))
  {
    printf("el=%d l=%d h=%d m=%d\n ",(*p)[m],l,h,m);
    if(key>(*p)[m])
    {
	    l=m+1;
	    m=(l+h)/2;
    }
    else
    {
	    h=m;
	    m=(l+h)/2;
    }
	    
  }

    if(key==(*p)[m])
    {
     printf("index=%d\n",m);	   
     return 1;
    }
    else if(i==len)
         return 0;
}
