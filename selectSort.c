/*Program to implement selection sort*/

#define MAX 10 

#include<stdio.h>
#include<stdlib.h>

void selectSort(int (*)[]);

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
 
  
  selectSort(&arr);
   
  for(i=0;i<MAX;i++)
  {
    printf("%d ",arr[i]);
  }

  printf("\n");
  return 0;
}

/*Selection sort function*/
void selectSort(int (*p)[MAX])
{
  int len=sizeof(*p)/sizeof(int);
  int i=0,j=0,temp,min,pos;
     
  for(i=0;i<len;i++)
  {
    min=*(*p+i);	  
    for(j=i+1;j<len;j++)
    {
       if(min>(*(*p+j)))
       {
	 temp=*(*p+j);      
	 *(*p+j)=*(*p+i); 
	 *(*p+i)=temp;
	 min=temp;
       }
      
    }
  
    /*for(j=0;j<len;j++)
    {
      printf("%d ",*(*p+j));
    }
    printf("\n");*/
  }
  
}
