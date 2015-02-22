/*Program to implement bubble sort*/

#define MAX 10 

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int (*)[]);

int main()
{
  	
 int arr[MAX],i=0;

 /*Seed rand function and assign random value in arr*/
  srand(time(0));
  printf("Elements of the array are\n");
  for(i=0;i<MAX;i++)
  {
    arr[i]=rand()%20;
    printf("%d ",arr[i]);
  }

  printf("\n"); 
 
  
  bubbleSort(&arr);
   
  for(i=0;i<MAX;i++)
  {
    printf("%d ",arr[i]);
  }

  printf("\n");
  return 0;
}

/*Bubble sort function*/
void bubbleSort(int (*p)[MAX])
{
  int len=sizeof(*p)/sizeof(int);
  int i=0,j=0,temp;
     
  for(i=0;i<len;i++)
  {
    for(j=1;j<len;j++)
    {
        if( (*(*p+j)) < (*(*p+j-1)) )
       {
	 temp=*(*p+j); 
	 *(*p+j)=*(*p+j-1);
	 *(*p+j-1)=temp;
       }
    }
  }
  
}
