#include <stdio.h>

int	main(void)
{
	int N;

	scanf("%d", &N);
	int A[N+9];
	int key_a[3009];
	for (int i = 1; i <= 3000; i++)
		key_a[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		key_a[A[i]] = 1;
		// printf("key_a=%d\n", key_a[i]);
	}

	int exists_1000_pair = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) 
				continue;
			int x = 1000 - (A[i] + A[j]);
			if (x > 0 && x != A[i] && x != A[j])
			if (key_a[x] == 1)
			{
				// printf("x=%d A[i]=%d A[j]=%d\n", x, A[i],A[j]);
				exists_1000_pair = 1;
				break;
			}
		}
	}
	if (exists_1000_pair == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}