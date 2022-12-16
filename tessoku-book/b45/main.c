#include <stdio.h>

int	main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a+b+c == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}