#include <stdio.h>
#include <stdlib.h>

long long	min(const long long a, const long long b)
{
	if (a <= b)
		return (a);
	else
		return (b);
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
	// printf("%d %d\n", N, W);

	int *ws, *vs;
	ws = calloc(N+1, sizeof(int));
	vs = calloc(N+1, sizeof(int));
	
	int vmax = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &ws[i], &vs[i]);
		// printf("%d %d\n", ws[i], vs[i]);
		vmax += vs[i];
	}
	// printf("vmax=%d\n", vmax);

	long long **dp;

	dp = calloc(N+1, sizeof(long long *));
	for (int i = 0; i <= N; i++) {
		dp[i] = calloc(vmax+1, sizeof(long long));
		for (int j = 0; j <= vmax; j++)
		{
			dp[i][j] = 100000000000;
			// printf("%lld\n", dp[i][j]);
		}
		// printf("\n");
	}
	dp[0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= vmax+1; j++)
		{
			if (j < vs[i])
				dp[i][j] = dp[i-1][j];
			else
			{
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-vs[i]]+ws[i]);
				// if (dp[i][j] < 100)
				// 	printf("%lld\n", dp[i][j]);	
			}
			
		}
		// printf("\n");
	}

	long long  wmax = 0;
	int maxj = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= vmax; j++)
		{
			if (dp[i][j] <= W)
			{
				// printf("W=%d %d %d %lld\n", W, i, j, dp[i][j]);
				wmax = max(wmax,dp[i][j]);
				maxj = max(maxj, j);
			}
		}
	}
	// printf("wmax=%lld maxj=%d\n", wmax, maxj);
	printf("%d\n", maxj);

	return (0);
}