#include <stdio.h>

#define SIZE 100009

int	main(void)
{
	int	H, W;
	int	N, A[SIZE], B[SIZE], C[SIZE], D[SIZE];

	scanf("%d %d %d", &H, &W, &N);
	// printf("%d %d %d\n", H, W, N);

	int Z[H+5][W+5];

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
		// printf("%d %d %d %d\n", A[i], B[i], C[i], D[i]);
	}

	for (int i = 0; i <= H+1; i++) {
		for (int j = 0; j <= W+1; j++)
			Z[i][j] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		Z[A[i]][B[i]] += 1;
		Z[C[i]+1][D[i]+1] += 1;
		Z[C[i]+1][B[i]] -= 1;
		Z[A[i]][D[i]+1] -= 1;
	}

	for (int j = 1; j <= W; j++) {	
		for (int i = 1; i <= H; i++) {
			Z[i][j] += Z[i][j-1];
			// printf("%d ", Z[i][j]);
		}
		// printf("\n");
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
		{
			Z[i][j] += Z[i-1][j];
			printf("%d", Z[i][j]);
			if (j == W)
				printf("\n");
			else
				printf(" ");
		}
	}
	

	return (0);
}