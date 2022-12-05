#include <stdio.h>

typedef long long ll;

int	main(void)
{
	ll N;
	
	scanf("%lld", &N);
	// printf("%lld %lld %lld\n", N/3 ,N/5 ,N/7);
	// printf("%lld %lld %lld %lld\n", N/(3*5), N/(5*7), N/(3*7) , N/(3*5*7));
	printf("%lld\n", N/3 + N/5 + N/7 - N/(3*5) - N/(5*7) - N/(3*7) + N/(3*5*7));

	// for (ll i = 1; i <= N; i++)
	// {
	// 	if (i % 3 == 0)
	// 		printf("3 i=%lld\n", i);
	// 	if (i % 5 == 0)
	// 		printf("5 i=%lld\n", i);
	// 	if (i % 7 == 0)
	// 		printf("7 i=%lld\n", i);
	// }
	return (0);
}