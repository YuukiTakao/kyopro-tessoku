#include <stdio.h>


int	search(int *A, int x, int N)
{
	int L = 1;
	int R = N;

	while(L <= R)
	{
		int M = (L + R) / 2;
		if (x < A[M]) 
			R = M - 1;
		if (x == A[M])
			return M;
		if (x > A[M])
			L = M + 1;
	}
	return -1;
}


int	main(void)
{
	int	N, A[100009]; 
	int	X;

	scanf("%d %d", &N, &X);
	// printf("%d %d\n", N, X);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		// printf("%d\n", A[i]);
	}
	printf("%d\n", search(A, X, N));

	return (0);
}