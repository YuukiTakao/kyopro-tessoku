#include <stdio.h>


int sum(int *S, int l, int r)
{
	return (S[r] - S[l - 1]);
}

int	main(void)
{
	int N;
	int	K;

	scanf("%d %d", &N, &K);
	int A[N+9];
	// printf("%d %d\n", N, K);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		// printf("%d\n", A[i]);
	}

	int S[N+9];
	S[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		S[i] = S[i - 1] + A[i];
	}

	int R[N+9];
	for (int i = 1; i <= N; i++) {
		if (i == 1) R[i] = 0;
		else R[i] = R[i - 1];
		while (R[i] < N && sum(S, i, R[i]+1) <= K)
		{
			R[i] += 1;
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans += (R[i] - i + 1);
	}
	printf("%lld\n", ans);
	
	
	return (0);
}