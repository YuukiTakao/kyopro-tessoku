#include <stdio.h>

int	main(void)
{
	int N;
	int Q;

	scanf("%d", &N);
	int A[N+9];

	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	scanf("%d", &Q);
	int L[Q+9], R[Q+9];

	for (int i = 1; i <= Q; i++) scanf("%d %d", &L[i], &R[i]);

	int win_s[N+9], lose_s[N+9];
	win_s[0] = 0;
	lose_s[0] = 0;
	// 累積和
	for (int i = 1; i <= N; i++)
	{
		win_s[i] = win_s[i - 1] + A[i];
		int is_lose = 0;
		if (A[i] == 0)
			is_lose = 1;
		lose_s[i] = lose_s[i - 1] + is_lose;
		// printf("win_s[%d]=%d lose_s[%d]=%d\n", i,win_s[i], i,lose_s[i]);
	}
	for (int i = 1; i <= Q; i++)
	{
		int sum_win = win_s[R[i]] - win_s[L[i] - 1];
		int sum_lose = lose_s[R[i]] - lose_s[L[i] - 1];
		if (sum_win - sum_lose < 0)
			printf("lose\n");
		else if (sum_win - sum_lose > 0)
			printf("win\n");
		else
			printf("draw\n");
	}

	return (0);
}