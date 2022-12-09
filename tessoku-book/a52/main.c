#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);

	int *qs, count = 1, start = 1;
	char **queue;
	qs = calloc(Q+1, sizeof(int));
	queue = calloc(Q+1, sizeof(char *));
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d", &qs[i]);
		if (qs[i] == 1)
		{
			queue[count] = calloc(20+5, sizeof(char));
			scanf("%s", queue[count]);
			count++;
		}
		else if (qs[i] == 2)
			printf("%s\n", queue[start]);
		else if (qs[i] == 3)
			start++;
	}

	return (0);
}
