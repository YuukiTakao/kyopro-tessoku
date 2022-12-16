#include <stdio.h>

#define Mod 1000000007
typedef	long long ll;
ll mod_pow(int a, int exp, int M) {
	if (exp == 0)
		return 1;
	ll p = a;
	ll ans = 1;
	for (int i = 0; i < 30; i++) {
		int div = 1 << i;
		// printf("exp=%d (exp / div)=%d 2^%d=%d\n", exp, (exp / div), i, div);
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
	int a, b;
	scanf("%d %d", &a, &b);
	// printf("%d %d\n", a, b);

	printf("%lld\n", mod_pow(a, b, Mod));
	return (0);
}
