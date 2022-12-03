#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	max(const int a, const int b, const int c)
{
	int ans = a;
	if (a <= b)
		ans = b;
	
	if (ans <= c)
		ans = c;

	return ans;
}

int	main(void)
{
	char S[2001], T[2001];

	scanf("%s%s", S, T);
	// printf("%s %s\n", S, T);

	int N, M;
	N = strlen(S);
	M = strlen(T);

	int **dp;

	dp = calloc(N+1, sizeof(int *));

	for (int i = 0; i <= N; i++) {
		dp[i] = calloc(M+1, sizeof(int));
		for (int j = 0; j <= M; j++)
		{
			if (i >= 1 && j >= 1 && S[i-1] == T[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]+1);
			else if (i >= 1 && j >= 1)
				dp[i][j] = max(dp[i-1][j], dp[i][j-1], 0);
			else if (i >= 1)
				dp[i][j] = dp[i-1][j];
			else if (j >= 1)
				dp[i][j] = dp[i][j-1];
		}
	}

	printf("%d\n", dp[N][M]);
	return (0);
}