/*algorithm taken from 
PERMUTATION GENERATION METHODS
Robert Sedgewick
Princeton University
*/
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


int generate_perms(int N, char *arr)
{
	int n, t, M;
	char *c = NULL;
	c = malloc(N * sizeof(char));
	if (!c) {
		perror("error in allocating memory\n");
		exit(EXIT_FAILURE);
	}

	for (n = 0; n < N; n++)
		c[n] = 0;

	print_arr(arr, N);
	for (n = 0; n < N; ) {
		if (c[n] < n) {
			if (n & 0x01)
				swap(&arr[c[n]], &arr[n]);
			else
				swap(&arr[0], &arr[n]);
			c[n]++;
			n = 0;
			print_arr(arr, N);
		} else
			c[n++] = 0;
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

	generate_perms(N, arr);
	return 0;
}
