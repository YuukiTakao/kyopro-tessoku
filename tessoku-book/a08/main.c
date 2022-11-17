#include <stdio.h>


int X[1509][1509];
int	Z[1509][1509];

int	main(void)
{
	int	H, W;
	int	Q;
	int	A[100009],B[100009],C[100009],D[100009];
	

	scanf("%d%d", &H, &W);
	// printf("%d %d\n", H, W);

	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= W; j++)
			X[i][j] = 0;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			scanf("%d", &X[i][j]);
	}

	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= W; j++)
			Z[i][j] = 0;
	}

	scanf("%d", &Q);
	// printf("%d\n", Q);

	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
		// printf("%d %d %d %d\n", A[i], B[i], C[i], D[i]);
	}

	for (int j = 1; j <= W; j++) {
		for (int i = 1; i <= H; i++) {
			Z[i][j] = Z[i][j - 1] + X[i][j];
		}
	}

	for (int i = 2; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Z[i][j] = Z[i - 1][j] + Z[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		printf("%d\n", Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[C[i]][B[i]-1] - Z[A[i]-1][D[i]]);
	}
	return (0);
}