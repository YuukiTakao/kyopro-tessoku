#include <stdio.h>
#include <stdlib.h>

typedef	long long ll;

int	main(void) {
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);

	if (N == 1) {
		printf("%d\n", 0);
		return 0;
	}
	int *A;
	A = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		// printf("%d\n", A[i]);
	}
	ll *counts;
	counts = calloc(N+1, sizeof(ll));
	for (int i = 1; i <= N; i++) {
		counts[A[i] % 100]++;
		// printf("i=%d A[i]=%d  A[i]mod100=%d\n", i, A[i], A[i] % 100);
	}
	
	ll ans = 0;
	for (int i = 1; i < 50; i++) {
		ans += counts[i] * counts[100-i];
		// printf("i=%d counts[i]=%d counts[100-i]=%d\n", i, counts[i] , counts[100-i]);
	}
	ans += counts[0] * (counts[0] - 1ll) / 2ll;
	ans += counts[50] * (counts[50] - 1ll) / 2ll;

	printf("%lld\n", ans);
	
	return (0);
}