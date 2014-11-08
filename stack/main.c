/**@brief Program to perform stack ops
 *
 * A simple C program to display stack operations
 * using command line.
 */
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main_menu(void);
int operations(int **stack,int choice,int *top_ptr,int *size_ptr);

int main()
{
	int *stack = NULL;
	int top = -1;
	int size = 0;
	int choice = 0;
	int exit_flag = 1;
	while(exit_flag)
	{
		choice = main_menu();
		switch(choice)
		{
			case 1:
			{
				if(!stack)
				{
					printf("Enter size of stack\n");
					scanf("%d",&size);		
					operations(&stack,choice,&top,&size);
				}
				else
					printf("Stack already present\n");
			}
			break;
			case 2:
			{
				if(*stack)
					operations(&stack,choice,&top,&size);	
				else
					printf("operation on empty stack not allowed\n");
			}
			break;
			case 3:
			{
				if(*stack)
					operations(&stack,choice,&top,&size);	
				else
					printf("operation on empty stack not allowed\n");
			}
			case 4:
			{
				operations(&stack,choice,&top,&size);
			}
			break;
			case 5:
			{
				operations(&stack,choice,&top,&size);
			}
			break;
			case 6:
			{	
				operations(&stack,5,&top,&size);
				exit_flag = 0;   	
			}
			break;
			case 7:
			{
				printf("Invalid choice\n");
			}
			break;
		}
	
	}
	return EXIT_SUCCESS;
}

int operations(int **stack,int choice,int *top_ptr,int *size_ptr)
{
	int top = *top_ptr;
	int size = *size_ptr;
	int val = 0;
	switch(choice)
	{
		case 1:
		{
			if(create_stack(stack,&top,size))
				printf("Stack created\n");
			else
				printf("error in creating stack\n");
		}
		break;
		case 2:
		{
			if(push(stack,&top,size,val))
			{
				printf("value pushed %d\n",val);
			}
			else
				printf("error in pushed\n");
		}
		break;
		case 3:
		{
			if(stack)
				pop(stack,&top,size,&val);
			else
				printf("");
		}
		break;
		case 4:
		{
			display_stack(stack,&top,size);		
		}
		break;
	}
	*top_ptr = top;
	*size_ptr = size;
}


int main_menu(void)
{
	int choice = 0;
	printf("---MAIN MENU---\n"
	       "1.Create stack\n"
	       "2.Push\n"
	       "3.Pop\n"
	       "4.Display stack\n"
	       "5.Destroy stack\n"
	       "6.Exit\n");
	scanf("%d",&choice);
	return choice;
}
