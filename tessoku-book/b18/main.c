#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int N, S;
	
	scanf("%d %d", &N, &S);
	// printf("%d %d\n", N, S);

	int *A;
	A = calloc(N+9, sizeof(int));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		// printf("%d\n", A[i]);
	}

	int **dp;
	dp = calloc(N+9, sizeof(int *));

	
	for (int i = 0; i <= N; i++)
	{
		dp[i] = calloc(S+9, sizeof(int));
		if (i >= 1)
			dp[0][i] = 0;
	}
	dp[0][0] = 1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++)
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
	// DPテーブル確認
	// for (int i = 0; i <= N; i++) {
	// 	for (int j = 0; j <= S; j++)
	// 	{
	// 		printf("%d ", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }

	if (dp[N][S] == 0)
	{
		printf("-1\n");
		return (0);
	}

	int *restore;
	restore = calloc(N+9, sizeof(int));

	int k = 1;
	int i = N;
	int j = S;
	for (;;) 
	{
		if (i <= 0)
			break;
		if (dp[i-1][j] == 1)
		{
			i--;
			continue;
		}
		restore[k] = i;
		// printf("i=%d restore[k]=%d\n", i, restore[k]);
		j = j - A[i];
		i--;
		k++;
	}
	printf("%d\n", k-1);
	for (int l = k-1; l >= 1; l--)
	{
		if (l < k-1)
			printf(" ");
		printf("%d", restore[l]);
	}
	printf("\n");

	return (0);
}