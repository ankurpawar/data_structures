#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int create_stack(int **stack,int *top,int size)
{
	int ret_val = 0;
	*stack = malloc(size * sizeof(int));
	if(*stack)
	{
		*top = -1;
		ret_val = 1;
	}
	else
		ret_val = 0;
	return ret_val;
}

int push(int *stack,int *top,int size,int val)
{
	int ret_val = 0;
	if(stack)
	{
		if(*top < size)
		{
			(*top)++;
			stack[*top] = val;
		}
		else
			printf("stack full \n");
	}

	return ret_val;	

}
int pop(int *stack,int *top,int size,int *val)
{
	int ret_val = 0;
	if(stack)
	{
		if(*top > -1)
		{
			*val = stack[*top];
			(*top)--;
			ret_val = 1;
		}
		else
		{
			ret_val = 0;
			printf("Stack empty\n");
		}
	}
	return ret_val;
}

void display_stack(int *stack,int *top,int size)
{
	int i = 0;
	if(stack)
	{
		for(i = *top ; i > 0 ; i--)
			printf("%d\n",stack[*top]);
	}

}
