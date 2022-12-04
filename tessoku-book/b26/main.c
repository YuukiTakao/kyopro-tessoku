#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N;

	scanf("%d", &N);

	int *deleted;
	deleted = calloc(N+1, sizeof(int));
	for (int i = 2; i*i <= N; i++)
	{
		if (deleted[i] == 1)
			continue;
		
		for (int j = i*i; j <= N; j+=i)
			deleted[j] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		if (deleted[i] == 0)
			printf("%d\n", i);
	}

	return (0);
}