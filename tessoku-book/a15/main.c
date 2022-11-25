#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	cmp_asc(const void *n1, const void *n2)
{
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}

int	search(int *A, int x, int N)
{
	int L = 0;
	int R = N-1;
	while(L <= R)
	{
		int half = (L + R) / 2;
		if (x < A[half]) 
			R = half - 1;
		if (x == A[half])
			return half;
		if (x > A[half])
			L = half + 1;
	}
	return -1;
}

int	main(void)
{
	int	N;

	scanf("%d", &N);
	int *A, *B, *uniq;

	A = calloc(N, sizeof(int));
	B = calloc(N, sizeof(int));
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
		// printf("B[i]=%d\n", B[i]);
	}
	qsort(B, N, sizeof(int), cmp_asc);

	uniq = calloc(N, sizeof(int));
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			uniq[j++] = B[i]; 
			// printf("i=%d  uniq[%d]=%ld\n", i, j, uniq[j]);
		}
		else
		{
			if (B[i - 1] != B[i])
			{
				uniq[j++] = B[i];
				// printf("i=%d  uniq[%d]=%d\n", i, j, uniq[j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int index = search(uniq, A[i], j);

		// printf("i=%d A[i]=%d index=%d\n", i,A[i], index+1);
		if (i > 0)
			printf(" ");
		printf("%d", index+1);
	}
	printf("\n");

	return (0);
}
