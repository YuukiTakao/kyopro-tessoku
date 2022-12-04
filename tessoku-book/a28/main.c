#include <stdio.h>

int	main(void)
{
	int N;

	scanf("%d", &N);

	char sign[100009];
	long long a[100009];

	for (int i = 1; i <= N; i++)
	{
		scanf("%s %lld", &sign[i], &a[i]);
	}

	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (sign[i] == '+')
			sum += a[i];
		if (sign[i] == '*')
			sum *= a[i];
		if (sign[i] == '-')
			sum -= a[i];

		if (sum < 0)
			sum += 10000;

		sum %= 10000;
		printf("%lld\n", sum);
	}
	// printf("%d\n", N);
	return (0);
}
