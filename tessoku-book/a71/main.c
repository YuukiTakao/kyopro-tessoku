#include <stdio.h>
#include <stdlib.h>

int	cmp_asc(const void *n1, const void *n2) {
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}
int	cmp_desc(const void *n1, const void *n2) {
	if (*(int *)n1 < *(int *)n2)
		return 1;
	else if (*(int *)n1 > *(int *)n2)
		return -1;
	else
		return 0;
}
int	main(void) {
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);

	int *A;
	int *B;
	A = calloc(N, sizeof(int));
	B = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int j = 0; j < N; j++) {
		scanf("%d", &B[j]);
	}
	
	qsort(A, N, sizeof(int), cmp_asc);
	qsort(B, N, sizeof(int), cmp_desc);

	int sum = 0;
	for (int k = 0; k < N; k++) {
		// printf("k=%d A=%d B=%d\n",k, A[k], B[k]);
		sum += A[k] * B[k];
	}
	printf("%d\n", sum);

	return (0);
}