#include <stdio.h>
#include <stdbool.h>

bool	is_lte_middle(long int *A, long int mid, long int N, long int K)
{
	// printf("mid=%ld\n", mid);
	long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += mid / A[i];
	}
	
	if (sum >= K)
		return (true);
	else
		return (false);
}

int	main(void)
{
	long int	N;
	long int	K;
	
	scanf("%ld", &N);
	long int A[N];

	scanf("%ld", &K);
	// printf("%ld %ld\n", N, K);

	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &A[i]);
		// printf("%d\n", A[i]);
	}

	long int L = 1, R = 100000000;
	while (L < R)
	{
		long int M = (L + R) / 2;
		if (is_lte_middle(A, M, N, K))
			R = M;
		else
			L = M + 1;
	}
	printf("%ld\n", L);
	
	return (0);
}