#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);


	int *qs;
	qs = calloc(Q+1, sizeof(int));
	
	char **str;
	str = calloc(Q+1, sizeof(char *));
	int push_count = 0; 
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &qs[i]);
		if (qs[i] == 1)
		{
			str[++push_count] = calloc(25, sizeof(char));
			scanf("%s", str[push_count]);
			// printf("%d %d %s\n", i, push_count, str[push_count]);
		}
		if (qs[i] == 2)
		{
			printf("%s\n", str[push_count]);
		}
		if (qs[i] == 3)
		{
			str[push_count--] = calloc(25, sizeof(char));
		}
	}

	return (0);
}