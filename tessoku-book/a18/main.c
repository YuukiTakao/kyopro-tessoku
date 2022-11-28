#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N, S;
	
	scanf("%d %d", &N, &S);
	
	int *A;
	A = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	int **dp;
	dp = calloc(N+1, sizeof(int *));
	for (int i = 0; i <= N; i++)
	{
		dp[i] = calloc(S+1, sizeof(int));
		dp[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= S; j++)
		{
			if (j < A[i])
			{
				if (dp[i-1][j] == 1)
					dp[i][j] = 1;
			}
			if (j >= A[i])
			{
				if (dp[i-1][j] == 1 || dp[i-1][j-A[i]] == 1)
					dp[i][j] = 1;
			}
		}
	}

	if (dp[N][S] == 1)
		printf("Yes\n");
	else
		printf("No\n");
}