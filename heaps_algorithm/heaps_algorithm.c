/*algorithm taken from wikipedia*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5

void swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void print_arr(char *arr, int n)
{
	int i;
	for (i = 0; i < n ; i++)
		printf("%d ",*(arr + i));
	printf("\n");
}


int generate_perms(int n,int N, char *arr)
{
	int i;
	if(arr == NULL)
		return -1;
	if(n == 1)
		print_arr(arr, N);
	else {
		for (i = 0; i < (n - 1); i++) {
			generate_perms(n - 1, N, arr);
			if (n & 0x01)
				swap(&arr[0], &arr[n-1]);
			else
				swap(&arr[i], &arr[n-1]);
		}
		generate_perms(n - 1, N, arr);
	}
}

int main(int argc, char *argv[])
{
	char *arr;
	int i;
	int N;
	
	if (argc > MAX_NUM)
		printf("to many arguments.maximum 4 allowed\n");
	
	N = argc - 1;
	arr = malloc(N * sizeof(char));
	if (!arr) {
		perror("error in allocating memory\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < N; i++) {
		arr[i] = atoi(argv[i+1]);
	}

	generate_perms(N, N, arr);
	return 0;
}
