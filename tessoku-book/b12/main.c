#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool	is_lte_middle(float mid, int n)
{
	float x = mid * mid * mid + mid;
	// printf("mid=%lf x=%lf\n", mid, x);
	if (x > n * 1.0)
		return (true);
	else
		return (false);
}

int	main(void)
{
	int N;

	float L = 0, R = 100;

	scanf("%d", &N);
	// printf("%d\n", N);
	// printf("%f %f\n", L, R);

	float mid;
	for (int i = 0; i < 20; i++)
	{
		mid = (L + R) / 2;
		if (is_lte_middle(mid, N))
			R = mid;
		else
			L = mid;
		// printf("L=%f R=%f\n", L, R);
	}
	printf("%f\n", L);
	
	
	return (0);
}