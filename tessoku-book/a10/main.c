#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	N;
	int D;
	int A[100009], P[100009], Q[100009];
	int	L[100009], R[100009];

	scanf("%d", &N);
	// printf("N=%d\n", N);
	
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	P[1] = A[1];
	for (int i = 2; i <= N; i++)
	{
		if (P[i - 1] < A[i])
			P[i] = A[i];
		else
			P[i] = P[i - 1];
		// printf("i=%d P=%d\n", i,P[i]);
	}

	Q[N] = A[N];
	for (int i = N - 1; i >= 1; i--)
	{
		if (Q[i + 1] < A[i])
			Q[i] = A[i];
		else
			Q[i] = Q[i + 1];
		// printf(" i=%d Q=%d\n", i,Q[i]);
	}

	scanf("%d", &D);
	// printf("D=%d\n", D);

	for (int i = 1; i <= D; i++)
	{
		scanf("%d %d", &L[i], &R[i]);
		// int ans = 0;
		// printf("%d %d\n", L[i], R[i]);
		if (P[L[i]-1] < Q[R[i]+1])
			printf("%d\n", Q[R[i]+1]);
		else
			printf("%d\n", P[L[i]-1]);
	}
	
	return (0);
}

