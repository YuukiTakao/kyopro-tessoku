#include <stdio.h>

int	main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);
	// printf("%d %d\n", A, B);
	int is_divisor = 0;
	for (int i = A; i <= B; i++)
	{
		// printf("i=%d\n", i);
		if (100 % i == 0)
		{
			is_divisor = 1;
			break;
		}
	}
	if (is_divisor == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}