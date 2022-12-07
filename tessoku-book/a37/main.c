#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int	main(void)
{
	ll N, M, B;

	scanf("%lld %lld %lld", &N, &M, &B);
	// printf("%d %d %d\n", N, M, B);

	ll ans = N * M * B;
	ll *a, asum = 0;
	a = calloc(N+1, sizeof(ll));
	for (ll i = 1; i <= N; i++)
	{
		scanf("%lld", &a[i]);
		asum += a[i];
		// printf("%d\n", a[i]);
	}
	ans += asum * M;

	ll *c, csum = 0;
	c = calloc(M+1, sizeof(ll));
	for (ll i = 1; i <= M; i++)
	{
		scanf("%lld", &c[i]);
		csum += c[i];
		// printf("%d\n", c[i]);
	}
	ans += csum * N;
	
	printf("%lld\n", ans);
	return (0);
}