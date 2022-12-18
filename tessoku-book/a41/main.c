#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);

	char *S;
	S = calloc(N+1, sizeof(char));
	scanf("%s", S);

	int seq_r = 0, seq_b = 0;
	int exists_seq_3 = 0;
	for (int i = 0; i < N; i++) {
		// printf("%c", S[i]);
		if (S[i] == 'R') {
			seq_r++;
			seq_b = 0;
		}
		if (S[i] == 'B') {
			seq_b++;
			seq_r = 0;
		}
		if (seq_r >= 3 || seq_b >=3)
			exists_seq_3 = 1;
	}
	if (exists_seq_3 == 1)
		printf("Yes\n");
	else
		printf("No\n");
	
	return (0);
}