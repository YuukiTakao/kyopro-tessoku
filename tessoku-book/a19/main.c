#include <stdio.h>
#include <stdlib.h>

long long	yt_pow(const int n, const int pow)
{
	long long ret = n;
	for (int i = 0; i < pow; i++)
	{
		ret *= pow;
	}
	return ret;
}

long long	max(const long long a, const long long b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

int	main(void)
{
	int N, W;

	scanf("%d %d", &N, &W);
	// printf("N=%d W=%d\n", N, W);

	int *ws, *vs;
	ws = calloc(N+1, sizeof(int));
	vs = calloc(N+1, sizeof(int));

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &ws[i], &vs[i]);
		// printf("%d %d\n", ws[i], vs[i]);
	}

	long long **dp;

	dp = calloc(N+1, sizeof(long long *));
	// long long a = -1;
	for (int i = 0; i <= N; i++)
	{
		dp[i] = calloc(W+1, sizeof(long long));
		for (int j = 0; j <= W; j++)
		{
			dp[i][j] =  -100000000;
			// printf("%lld\n", dp[i][j]);
		}
	}
	dp[0][0] = 0;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < ws[i])
				dp[i][j] = dp[i-1][j];
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-ws[i]]+vs[i]);
			}
			// printf("%lld\t\t\t\t", dp[i][j]);
			// fflush(stdout);
		}
		// printf("\n");
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%lld\n", ans);
}