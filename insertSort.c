/*Program to implement insertion sort*/

#define MAX 10

#include<stdio.h>
#include<stdlib.h>

void insertSort(int (*)[]);
void shiftArr(int (*)[],int,int);
void printArr(int (*)[]);

int main()
{
  	
 int arr[MAX],i=0;

 /*Seed rand function and assign random value in arr*/
  srand(time(0));
  printf("Elements of the array are\n");
  for(i=0;i<MAX;i++)
  {
    arr[i]=rand()%20;
  }

  printArr(&arr);
 
  insertSort(&arr);

  printArr(&arr);
  
  return 0;
}

/*Display array function*/
void printArr(int (*p)[MAX])
{
  int i=0;
  for(i=0;i<MAX;i++)
  {
    printf("%d ",(*p)[i]);
  }
  printf("\n");
}

/*insertion sort function*/
void insertSort(int (*p)[MAX])
{
  int len=sizeof(*p)/sizeof(int);
  int i=0,j=0;
     
  for(i=0;i<len;i++)
  {
    for(j=0;j<=i;j++)
    {
       if( (*(*p+i)) < (*(*p+j)))
       {
	 shiftArr(p,j,i);
       }
    }
  
    printArr(p); 
  }

}

/*Shift array from position first to position last*/
void shiftArr(int (*p)[MAX],int first,int last)
{
  int i=0;
  int temp=*(*p+last);

  for(i=last;i>=first;i--)
  {
   *(*p+i)=*(*p+i-1);
  }

  *(*p+first)=temp;
  //printf("%d\n",(*p)[3]);
}
