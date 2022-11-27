#include <stdio.h>
#include <stdlib.h>

int	min(const int a, const int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	abs(const int a)
{
	if (a < 0)
		return (a * -1);
	return a;
}

int	main(void)
{
	int N;

	scanf("%d", &N);
	int *h;
	h = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &h[i]);
		// printf("%d\n", h[i]);
	}

	int *dp;
	dp = calloc(N+1, sizeof(int));
	
	dp[1] = 0;
	dp[2] = abs(h[1] - h[2]);
	// printf("dp[0]=%d\n", dp[0]);
	// printf("dp[1]=%d\n", dp[1]);
	for (int i = 3; i <= N; i++)
	{
		dp[i] = min(
			dp[i-1] + abs(h[i-1]-h[i]),
			dp[i-2] + abs(h[i-2]-h[i]) 
		);
		// printf("dp[%d]=%d\n", i,dp[i]);
	}
	int *answers;
	answers = calloc(N+1, sizeof(int));

	int k = N;
	int	i = 1;
	while (1)
	{
		answers[i] = k;
		// printf("ans[%d]=%d dp[k-2]=%d abs(%d-%d)=%d\n", i, answers[i], dp[k-2], h[k-2], h[k], abs(h[k-2]-h[k]));
		if (k <= 1)
			break;
		if (dp[k-2] + abs(h[k-2]-h[k]) == dp[k])
		{
			k -=2;
			// printf("minus 2\n");
		}
		else
		{
			k--;
			// printf("minus 1\n");
		}
		i++;
	}

	printf("%d\n", i);

	int tmp = i;
	for (; i >= 1; i--)
	{
		if (tmp > i)
			printf(" ");
		printf("%d", answers[i]);
	}
	printf("\n");
	
	return (0);
}