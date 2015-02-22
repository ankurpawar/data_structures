/*Program to implement merge sort*/

#define MAX 10

#include<stdio.h>
#include<stdlib.h>

void mergeSort(int (*)[],int,int);
void merge(int (*)[],int,int);
void printArr(int (*)[]);

int temp[MAX];

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
 
  mergeSort(&arr,0,MAX-1);

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

/*merge sort function*/
void mergeSort(int (*p)[MAX],int l,int h)
{
   int m=(l+h)/2;

   if(l==h)
      return;
   
   mergeSort(p,l,m);  
   mergeSort(p,m+1,h);
   
   merge(p,l,h);
   printArr(p);
}

/*Merging two sorted array*/
void merge(int (*p)[MAX],int l,int h)
{
  int m=(l+h)/2;	
  int i=l,j=m+1,k=l;

  while(i<=m && j<=h)
  {
    if((*p)[i]<(*p)[j])
      temp[k++]=(*p)[i++];
    else
      temp[k++]=(*p)[j++];	    
  }

  while(i<=m)
     temp[k++]=(*p)[i++];

  while(j<=h)
     temp[k++]=(*p)[j++];

  for(i=l;i<=h;i++)
     (*p)[i]=temp[i];

}

