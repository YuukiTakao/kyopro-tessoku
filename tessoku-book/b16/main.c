#include <stdio.h>
#include <stdlib.h>

int	abs(const int a)
{
	if (a < 0)
		return (a * -1);
	return a;
}

int	min(const int a, const int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	main(void)
{
	int N;

	scanf("%d", &N);

	int *h, *dp;
	h = calloc(N, sizeof(int));
	dp = calloc(N, sizeof(int));
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &h[i]);
	}

	dp[0] = 0;
	dp[1] = abs(h[0] - h[1]);
	// printf("dp[0]=%d\n", dp[0]);
	// printf("dp[1]=%d\n", dp[1]);
	// int k = 2;
	for (int i = 2; i < N; i++)
	{
		if (dp[i-2] + abs(h[i - 2] - h[i]) < dp[i-1] + abs(h[i - 1] - h[i]))
		{
			dp[i] = dp[i-2] + abs(h[i - 2] - h[i]);
			// i += 2;
		}
		else
		{
			dp[i] = dp[i-1] + abs(h[i - 1] - h[i]);
			// i++;
		}
		// printf("i=%d dp[%d]=%d\n", i,i,dp[i]);
		// k++;
	}

	printf("%d\n", dp[N-1]);
	
	
	return (0);
}