#include <stdio.h>

int	main(void)
{
	int n, k, i, j;
	int p[100];
	int q[100];

	scanf("%d %d", &n, &k);
	// printf("%d %d\n", n, k);

	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &q[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (k == p[i] + q[j])
			{
				printf("Yes\n");
				return (0);
			}
		}
	}
	printf("No\n");
	return (0);
}