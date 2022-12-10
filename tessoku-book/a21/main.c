#include <stdio.h>
#include <stdlib.h>

size_t	max(const size_t a, const size_t b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

int	main(void)
{
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);
	
	int *p, *a;
	p = calloc(N+1, sizeof(int));
	a = calloc(N+1, sizeof(int));
	int **dp;
	dp = calloc(N+1, sizeof(int *));

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &p[i], &a[i]);

		dp[i] = calloc(N+1, sizeof(int));
		// printf("%d %d\n", p[i], a[i]);
	}

	dp[1][N] = 0;
	for (int LEN = N - 2; LEN >= 0; LEN--) {
		for (int l = 1; l <= N - LEN; l++) {
			int r = l + LEN;

			int score1 = 0;
			if (l<=p[l-1] && p[l-1] <= r)
				score1 = a[l-1];

			int score2 = 0;
			if (l<=p[r+1] && p[r+1] <= r)
				score2 = a[r+1];
			
			if (l == 1) {
				dp[l][r] = dp[l][r+1]+score2;
			} else if (r == N) {
				dp[l][r] = dp[l-1][r] + score1;
			} else {
				dp[l][r] = max(dp[l][r+1]+score2, dp[l-1][r] + score1);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, dp[i][i]);
	}
	printf("%d\n", ans);


	return (0);
}
