#include <stdio.h>

int	main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);
	// printf("N=%d K=%d\n", N, K);
	if (K >= 2*N-2 && K % 2 == 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return (0);
}