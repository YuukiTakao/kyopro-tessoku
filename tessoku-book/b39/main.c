#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int N, D;

	scanf("%d %d", &N, &D);
	// printf("%d %d\n", N, D);

	int *jobs, *prices;
	jobs = calloc(N+1, sizeof(int));
	prices = calloc(N+1, sizeof(int));

	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &jobs[i], &prices[i]);
		// printf("%d %d\n", jobs[i], prices[i]);
	}

	int ans = 0;
	int *worked = calloc(N+1, sizeof(int));
	for (int i = 1; i <= D; i++) {
		int max_price = 0;
		int max_day = 0;
		for (int j = 1; j <= N; j++) {
			if (jobs[j] <= i && worked[j] == 0) {
				if (max_price < prices[j]) {
					max_price = prices[j];
					max_day = j;
					// printf("day%d jobs[%d]=%d max_day=%d max_price=%d\n", i, j,jobs[j], max_day, max_price);
				}
		// 		// printf("i=%d worked[j]=%d jobs[%d]=%d prices[j]=%d\n", i,  worked[j], j, jobs[j], prices[j]);
			}
		}
		// printf("i=%d max_day=%d max_price=%d\n", i, max_day, max_price);
		ans += max_price;
		worked[max_day] = 1;
	}
	printf("%d\n", ans);

	
	return (0);
}