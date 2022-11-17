#include <stdio.h>

int	main(void)
{
	int n, k;

	int ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// printf("%d %d %d\n",i, j, k - (i + j));
			if (k - (i + j) >= 1 && k - (i + j) <= n)
				ans++;
		}
	}
	printf("%d\n", ans);
	
	return (0);
}