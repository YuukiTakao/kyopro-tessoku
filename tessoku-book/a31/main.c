#include <stdio.h>

typedef long long ll;

int	main(void)
{
	ll N;

	scanf("%lld", &N);

	printf("%lld\n", N / 5 + N / 3 - N / 15);
	return (0);
}
