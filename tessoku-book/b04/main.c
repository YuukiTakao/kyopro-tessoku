#include <stdio.h>
#include <stdlib.h>

int	strbin_to_decimal(char *str_bin, int len)
{
	int digit;
	int a;
	int binary;

	a = 1;
	binary = 0;
	for (int i = 1; i <= len; i++)
	{
		digit = (str_bin[len-i]-'0') * a; 
		binary += digit;
		a *= 2;
	}
	return (binary);
}

int	main(void)
{
	char 	*N;
	int		len;

	N = (char *)calloc(10, sizeof(char));

	scanf("%s", N);
	
	len = 0;
	while (N[len] != '\0')
		len++;
	printf("%d\n", strbin_to_decimal(N, len));

	return (0);
}