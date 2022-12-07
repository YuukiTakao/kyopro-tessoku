#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	// printf("%d %d\n", N, K);

	char *S;
	S = calloc(N+1, sizeof(char));
	scanf("%s", S);
	// printf("%s\n", S);
	
	int count_one = 0;
	for (int i = 0; S[i] != '\0'; i++)
	{
		if (S[i] == '1')
			count_one++;
	}
	if (count_one % 2 == K % 2)
		printf("Yes\n");
	else
		printf("No\n");

	return (0 );
}