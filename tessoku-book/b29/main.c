#include <stdio.h>

#define Mod 1000000007
typedef long long ll;
ll mod_pow(ll a, ll exp, ll M) {
	if (exp == 0)
		return 1;
	ll p = a;
	ll ans = 1;
	for (int i = 0; i < 60; i++) {
		ll div = 1LL << i;
		// printf("exp=%lld (exp / div)=%lld 2^%d=%lld\n", exp, (exp / div), i, div);
		if ((exp / div) % 2 == 1) {
			ans = (ans * p) % M;
			// printf("ans=%lld p=%lld\n\n", ans, p);
		}
		p = (p * p) % M;
	}
	return ans;
}

int	main(void)
{
	ll a;
	ll b;
	scanf("%lld %lld", &a, &b);

	ll M = 1000000007;
	printf("%lld\n", mod_pow(a, b, M));
	return (0);
}