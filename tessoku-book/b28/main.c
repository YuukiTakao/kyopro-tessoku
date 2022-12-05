#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N;
	
	scanf("%d", &N);
	// printf("%d\n", N);

	int *fib;

	fib = calloc(N+1, sizeof(int));

	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		fib[i] = (fib[i-1] + fib[i-2]) % 1000000007;
		// printf("%d\n", fib[i]);
	}
	printf("%d\n", fib[N]);


	return (0);
}
