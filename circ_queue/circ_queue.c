/**
 *
 *Program to demosntrate implementation of
 *circular queue
 *
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int num_elem;
	int max_elem;
	int rear;
	int front;
	int *arr;
} QUEUE;



void make_queue(int max_e,QUEUE *q)
{
	q->arr = malloc(max_e * sizeof(int));
	q->num_elem = 0;
	q->rear = -1;
	q->front = 0;
	q->max_elem = max_e;
}

void display_queue(QUEUE *q)
{
	int i = 0;
	int index = q->front;
	while(i < q->num_elem)
	{
		printf(" %d ",q->arr[index]);
		index++;
		if(index >= q->max_elem)
			index = 0;
		i++;
	}
	printf("\n");	
}

void addto_queue(QUEUE *q,int val)
{
	if(q->num_elem >= q->max_elem)
	{
		printf("Q full\n");
		return ;
	}
	q->num_elem++;
	q->rear++;
	if( q->rear >= q->max_elem)
		q->rear = 0;
	q->arr[q->rear] = val;
}

int removefrom_queue(QUEUE *q)
{
	int val = 0;
	if(q->num_elem <= 0 )
	{
		printf("Q empty");
		return 0;
	}
	q->num_elem--;
	val = q->arr[q->front];
	q->front++;	
	if(q->front >= q->max_elem)
		q->front = 0;
	return val;
}
int main()
{
	int i = 0;
	QUEUE q1;
	make_queue(15,&q1);
	addto_queue(&q1,2);
	addto_queue(&q1,45);
	addto_queue(&q1,0);
	addto_queue(&q1,10);
	addto_queue(&q1,40);
	removefrom_queue(&q1);
	removefrom_queue(&q1);
	//printf("i = %d",i);
	addto_queue(&q1,13);
	display_queue(&q1);
	return EXIT_SUCCESS;
}
