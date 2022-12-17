#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	long long ll;

ll	min_int(const ll a, const ll b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
int	main(void)
{
	int D, N;
	scanf("%d%d", &D, &N);
	// printf("%d %d\n", D, N);

	long long csum[D+5];
	// csum = calloc(D+1, sizeof(int));
	memset(csum, 25, sizeof(csum));
	
	if (N == 0) {
		printf("%d\n", D*24);
		return 0;
	}
		
	
	for (int i = 1; i <= N; i++) {
		int L, R, H;
		scanf("%d %d %d", &L, &R, &H);
		// printf("L=%d R=%d H=%d\n", L, R, H);
		for (int j = L; j <= R; j++) {
			csum[j] = min_int(csum[j], H);
			// printf("j=%d csum[%d]=%d H=%d\n", j, csum[j], j, H);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= D; i++) {
		// printf("i=%d csum[i]=%d\n", i, csum[i]);
		ans += csum[i];
	}
	printf("%lld\n", ans);
	return (0);
}