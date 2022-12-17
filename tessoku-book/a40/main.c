#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef	long long ll;

int	main(void) {
	int N;

	scanf("%d", &N);
	
	ll *bars;
	bars = calloc(109, sizeof(ll));
	for (int i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		bars[a]++; 
	}
	ll ans = 0;
	for (int i = 1; i <= 100; i++) {
		ans += bars[i] * (bars[i] - 1) * (bars[i] - 2) / 6;
		// printf("%d %lld %lld\n", i, ans, bars[i]);
	}
	printf("%lld\n", ans);
	return (0);
}