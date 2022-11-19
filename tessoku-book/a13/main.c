#include <stdio.h>

int	main(void)
{
	int N;
	int	K;

	// 入力
	scanf("%d %d", &N, &K);
	// printf("%d %d\n", N, K);
	int	A[N+1];
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	
	// しゃくとり法
	int R[N+1];
	for (int i = 1; i <= N; i++)
	{
		if (i == 1) 
			R[i] = 1;
		else
			R[i] = R[i - 1];

		while (R[i] < N && A[R[i]+1]-A[i] <= K)
		{
			R[i]++;
		}
		// printf("R=%d\n", R[i]);
	}

	long int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans += (R[i] - i);
		// printf("R[i]=%d i=%d ans=%ld\n", R[i], i, ans);
	}
	printf("%ld\n", ans);

	return (0);
}