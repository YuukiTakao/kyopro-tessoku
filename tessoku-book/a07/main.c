#include <stdio.h>

int	main(void)
{
	int N, L[100009], R[100009];
	int D, csum[100009], A[100009];

	scanf("%d %d", &D, &N);
	// printf("%d %d\n", D, N);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &L[i], &R[i]);
	
	for (int i = 1; i <= N; i++)
	{
		A[L[i]] += 1;
		A[R[i]+1] -= 1;
	}
	
	csum[0] = 0;
	for (int i = 1; i <= D; i++)
	{
		// printf("%d\n", csum[i]);
		csum[i] = csum[i - 1] + A[i];
	}
	for (int i = 1; i <= D; i++)
	{
		printf("%d\n", csum[i]);
	}
	
	return (0);
}