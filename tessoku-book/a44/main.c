#include <stdio.h>
#include <stdlib.h>
int	main(void) {
	int N, Q;
	scanf("%d%d", &N, &Q);

	int *A;
	A = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		A[i] = i;
	}

	int is_reverse = 0;
	for (int i = 1; i <= Q; i++) {
		int q, x, y;

		scanf("%d", &q);
		if (q == 1) {
			scanf("%d %d", &x, &y);
			if (is_reverse == 1)
				A[N-x+1] = y;
			else
				A[x] = y;
		}
		else if (q == 2) {
			is_reverse = !is_reverse;
		}
		else if (q == 3) {
			scanf("%d", &x);
			if (is_reverse == 1)
				printf("%d\n", A[N-x+1]);
			else
				printf("%d\n", A[x]);
		}
	}
	return (0);
}