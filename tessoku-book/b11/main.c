#include <stdio.h>
#include <stdlib.h>


int	cmp_asc(const void *n1, const void *n2)
{
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}

int	search(int *dest, int x, int n)
{
	int L = 0;
	int R = n;
	// printf("start=%d %d\n", L, R);
	int M;
	while (L <= R)
	{
		M = (L + R) / 2;
		if (x < dest[M])
			R = M - 1;
		if (x == dest[M])
			return M;
		if (x > dest[M])
			L = M + 1;
	}
	// printf("x=%d L=%d R=%d M-1=%d\n", x, L, R, M-1);
	return L;
}

int	main(void)
{
	int	N;
	int Q;

	scanf("%d", &N);
	int	A[N];
	// printf("%d\n", N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	scanf("%d", &Q);
	int X[Q];
	// printf("%d\n", Q);
	for (int i = 0; i < Q; i++)
		scanf("%d", &X[i]);

	qsort(A, N, sizeof(int), cmp_asc);
	// for (int i = 0; i < N; i++)
	// {
	// 	printf("%d\n", A[i]);
	// }
	
	for (int i = 0; i < Q; i++)
	{
		if (A[N-1] < X[i])
		{
			printf("%d\n", N);
			continue;
		}
		if (A[0] > X[i])
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", search(A, X[i], N));
	}
	
	
	return (0);
}