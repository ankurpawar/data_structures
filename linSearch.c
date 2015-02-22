/*Program to implement linear search*/

#define MAX 20

#include<stdio.h>
#include<stdlib.h>

int linsearch(int (*)[],int);

int main()
{
  	
 int arr[MAX],i=0,key;

 /*Seed rand function and assign random value in arr*/
  srand(time(0));
  printf("Elements of the array are ");
  for(i=0;i<MAX;i++)
  {
    arr[i]=rand()%10;
    printf("%d ",arr[i]);
  }

 printf("\n"); 
 printf("enter the key to search \n");
 scanf("%d",&key);
 printf("\n");
 
  /* */
  if(linsearch(&arr,key))
    printf("element found\n");
  else
    printf("not found\n");	 
 
   printf("\n");

   return 0;
}

/*Linear search function*/
int linsearch(int (*p)[MAX],int key)
{
  int len=sizeof(*p)/sizeof(int);
  int i=0;
   
  /*Traverse through each element and compare with key*/   
     while(i<len && *(*p+i)!=key)
    {
     i++;  
    }

    if(i<len)
    {
     printf("index=%d\n",i);	   
     return 1;
    }
    else if(i==len)
         return 0;
}
