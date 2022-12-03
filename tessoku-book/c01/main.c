#include <stdio.h>

int	main(void)
{
	int N;
	int tax;

	scanf("%d", &N);
	tax = N / 10;
	printf("%d\n", N + tax);
	return (0);
}