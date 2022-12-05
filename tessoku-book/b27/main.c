#include <stdio.h>

int greatest_common_divisor(int a, int b)
{
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int	main(void)
{
	long long A, B;

	scanf("%lld %lld", &A, &B);
	// printf("%d %d\n", A, B);

	if (A <= B)
	{
		long long tmp = A;
		A = B;
		B = tmp;
	}

	long long ans = A / greatest_common_divisor(A, B) * B; 
	printf("%lld\n", ans);
	
	return (0);
}