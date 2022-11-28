#include <stdio.h>
#include <stdlib.h>

int	is_prime(const int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int N;

	scanf("%d", &N);
	int *X;
	X = calloc(N+1, sizeof(int));

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &X[i]);
		if (is_prime(X[i]) == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	


	return (0);
}