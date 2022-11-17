#include <stdio.h>


int	main(void)
{
	int N, A[100009], csum[100009];
	int Q, L[100009], R[100009];

	scanf("%d %d", &N, &Q);
	
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	for (int i = 1; i <= Q; i++) 
		scanf("%d %d", &L[i], &R[i]);

	csum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		csum[i] = csum[i - 1] + A[i];
		// printf("%d\n", csum[i]);
	}

	for (int i = 1; i <= Q; i++)
	{
		// printf("%d %d %d\n", R[i], L[i]-1,  csum[i]);
		printf("%d\n", csum[R[i]] - csum[L[i] - 1]);
	}
	
	return (0);
}