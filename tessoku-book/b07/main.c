#include <stdio.h>

int	main(void)
{
	int T, N;

	scanf("%d %d", &T, &N);
	// printf("T=%d N=%d\n", T, N);

	int X[T+9];
	for (int i = 0; i <= T; i++)
	{
		X[i] = 0;
	}
	int L[N+9], R[N+9];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &L[i], &R[i]);
		X[L[i]] += 1;
		X[R[i]] -= 1;
		// printf("i=%d X[%d]=%d X[%d]=%d\n", i, L[i], X[L[i]], R[i]+1, X[R[i]+1]);
	}
	for (int i = 0; i < T; i++)
	{
		if (i > 0)
			X[i] += X[i - 1];
		printf("%d\n", X[i]);
	}
	
	return (0);
}