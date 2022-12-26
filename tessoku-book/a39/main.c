#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
	int first;
	int second;
}	Pair;
int	cmp_asc(const void *n1, const void *n2) {
	Pair *a = (Pair *)n1;
	Pair *b = (Pair *)n2;
	if (a->second > b->second)
		return 1;
	else if (a->second < b->second)
		return -1;
	else
		return 0;
}

int	main(void) {
	int N;

	scanf("%d", &N);
	// printf("%d\n", N);
	int *L, *R;
	L = calloc(N+1, sizeof(int));
	R = calloc(N+1, sizeof(int));

	Pair *pairs = calloc(N, sizeof(Pair));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &L[i], &R[i]);
		pairs[i].first = L[i];
		pairs[i].second = R[i];
	}
	qsort(pairs, N, sizeof(Pair), cmp_asc);

	int current = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		// printf("pairs[i].first=%d pairs[i].second=%d\n", pairs[i].first, pairs[i].second);
		if (current <= pairs[i].first) {
			current = pairs[i].second;
			ans++;
		}
	}
	printf("%d\n", ans);

	return (0);
}