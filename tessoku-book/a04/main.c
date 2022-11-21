#include <stdio.h>

int	main(void)
{
	int		n;
	char	ans[10+1]; // 0 - 9 - 10(null)
	int		binary[10];

	scanf("%d", &n);
	int i;
	for (i = 0; n > 0; i++)
	{
		// printf("i=%d %d %d\n", i, n , n % 2);
		binary[i] = n % 2;
		n = n / 2;
	}
	int k = 0;
	for (int j = 0; j < 10; j++)
	{
		if (i <= j) // 4桁(0-3)の２進数の場合、まで0埋め
			ans[9-j] = 0 + '0';
		else
		{
			ans[9-j] = binary[k] + '0';
			k++;
		}
	}
	printf("%s\n", ans);
	return (0);
	
}