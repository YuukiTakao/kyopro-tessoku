#include <stdio.h>
#include <stdlib.h>

typedef long long tdarray_t;

void	tdarray(tdarray_t **td_array, int N, int W, tdarray_t init)
{
	for (int i = 0; i <= N; i++)
	{
		td_array[i] = calloc(W+1, sizeof(long long));
		for (int j = 0; j <= W; j++)
		{
			td_array[i][j] =  init;
		}
	}
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

	tdarray_t **dp;
	
	dp = calloc(N+1, sizeof(tdarray_t *));
	tdarray(dp, N, W, (tdarray_t)-1000000000);
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

	tdarray_t ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%lld\n", ans);
}