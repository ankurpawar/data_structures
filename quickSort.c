/*Program to implement quick sort*/

#define MAX 10

#include<stdio.h>
#include<stdlib.h>

void quickSort(int (*)[],int,int);
int  partition(int (*)[],int,int);
void printArr(int (*)[]);

int temp[MAX];

int main()
{
  	
 int arr[MAX]={26,5,37,1,61,11,59,15,48,19},i=0;

 /*Seed rand function and assign random value in arr*/
  srand(time(0));
  printf("Elements of the array are\n");
  /*for(i=0;i<MAX;i++)
  {
    arr[i]=rand()%20;
  }*/

  
  
  printArr(&arr);
 
  quickSort(&arr,0,MAX-1);

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

/*quick sort function*/
void quickSort(int (*p)[MAX],int lb,int hb)
{
   int pos;
   if(lb>=hb)
      return;
   
   pos=partition(p,lb,hb);
   quickSort(p,lb,pos-1);  
   quickSort(p,pos+1,hb);
   
   
   /*printArr(p);*/
}

/*Merging two sorted array*/
int partition(int (*p)[MAX],int l,int h)
{
  int pivot=(*p)[l];	
  int down=l,up=h,pos,temp;
  while(down<up)
  {
     while((pivot>=(*p)[down]) && (down < h))
	down++;
  
     while(pivot<(*p)[up])
	up--;

     if(down<up)
     {
       temp=(*p)[down];
       (*p)[down]=(*p)[up];
       (*p)[up]=temp;
     }   
     printArr(p);
  }
  pos=up;
  (*p)[l]=(*p)[pos];
  (*p)[pos]=pivot;
  
  /*printf("%d\n",pos);*/
  printf("\n\n");
  /*printArr(p);*/
  return pos;    
}

