#include <stdio.h>
int	main(void)
{
	int	n, x;
	int	a[101];

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == x)
		{
			printf("Yes\n");
			return (0);
		}
	}
	printf("No\n");

	return (0);
}