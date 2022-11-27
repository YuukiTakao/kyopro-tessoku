#include <stdio.h>
#include <stdlib.h>

int	min(const int a, const int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	main(void)
{
	int N;

	scanf("%d", &N);

	int *A, *B;
	A = calloc(N+1, sizeof(int));
	B = calloc(N+1, sizeof(int));

	for (int i = 2; i <= N; i++)
		scanf("%d", &A[i]);
	for (int i = 3; i <= N; i++)
		scanf("%d", &B[i]);

	int *P, *answers;
	P = calloc(N+1, sizeof(int));
	answers = calloc(N+1, sizeof(int));

	P[1] = 0;
	P[2] = A[2];

	for (int k = 3; k <= N; k++)
		P[k] = min(P[k - 1] + A[k], P[k - 2] + B[k]);

	int place = N;
	int j = 1;
	while (1)
	{
		answers[j] = place;
		if (place == 1)
			break;
		if (P[place-1] + A[place] == P[place])
			place = place - 1;
		else
			place = place - 2;
		j++;
	}
	
	printf("%d\n", j);
	int ans_size = j;
	for (; j >= 1; j--)
	{
		if (j < ans_size)
			printf(" ");
		printf("%d", answers[j]);
	}
	printf("\n");
	return (0);
}