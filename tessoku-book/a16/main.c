#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	N;

	scanf("%d", &N);

	int *A, *B;

	A = calloc(N+1, sizeof(int));
	B = calloc(N+1, sizeof(int));

	for (int i = 2; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 3; i <= N; i++)
	{
		scanf("%d", &B[i]);
	}

	int *DP;
	DP = calloc(N+1, sizeof(int));

	for (int i = 1; i <= N; i++)
	{
		if (i == 2)
		{
			DP[i] = DP[i - 1] + A[i];
			// printf("DP[%d]=%d\n", i, DP[i]);
		}
		else if (i >= 3)
		{
			if (DP[i - 1] + A[i] < DP[i - 2] + B[i])
				DP[i] = DP[i - 1] + A[i];
			else {
				DP[i] = DP[i - 2] + B[i];
				// printf("DP[%d]=%d\n", i, DP[i]);
			}
		}
		// printf("DP[%d]=%d\n", i, DP[i]);
	}
	printf("%d\n", DP[N]);
	return (0);
}