#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);

	// printf("%d %d %d\n", N, A, B);
	int *dp;
	dp = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		if (i >= A && dp[i - A] == 0)
			dp[i] = 1;
		else if (i >= B && dp[i - B] == 0)
			dp[i] = 1;
	}
	if (dp[N] == 1)
		printf("First\n");
	else
		printf("Second\n");
	return (0);
}