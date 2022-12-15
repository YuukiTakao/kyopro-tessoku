#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	// printf("%d %d\n", N, M);

	int *A;
	A = calloc(M+1, sizeof(int));
	int *ac;
	ac = calloc(N+1, sizeof(int));
	for (int i = 1; i <= M; i++) {
		scanf("%d", &A[i]);
		ac[A[i]]++;
		// printf("i=%d acA[i]=%d\n", i, ac[A[i]]);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", M - ac[i]);
	}
	
	return (0);
}