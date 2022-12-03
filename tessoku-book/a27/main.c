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
	int A, B;

	scanf("%d %d", &A, &B);

	printf("%d\n", greatest_common_divisor(A, B));
	return (0);
}