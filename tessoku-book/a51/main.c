#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector {
	char	**array;
	int		len;
	int		cap;
}	vector;
vector	*new(int cap) {
	vector *self = calloc(1, sizeof(vector));
	if (!self)
		printf("failed vector new...\n");
	self->cap = cap;
	self->len = 0;
	self->array = calloc(self->cap, sizeof(char *));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
vector	*resize(vector *self, int new_cap) {
	int new_size = new_cap * sizeof(int);
	char **tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	pop_back(vector *self) {
	if (self->len == 0) {
		printf("failed push_back in realloc...\n");
	}
	self->len--;
}
char	*back(vector *self) {
	return self->array[self->len-1];
}
void	push_back(vector *self, char *elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// printf("self->len=%d strlen=%lu elem=%s\n",self->len,strlen(elem), elem);
	self->array[self->len] = calloc(strlen(elem), sizeof(char));
	self->array[self->len] = elem;
	self->len++;
}

int	main(void)
{
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);
	
	int *qs;
	qs = calloc(Q+1, sizeof(int));
	
	vector *stack = new(Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &qs[i]);
		if (qs[i] == 1)
		{
			char *str = calloc(21, sizeof(char));
			scanf("%s", str);
			push_back(stack, str);
			// printf("%d %d %s\n", i, stack->len, stack->array[stack->len]);
		}
		if (qs[i] == 2)
		{
			printf("%s\n", back(stack));
		}
		if (qs[i] == 3)
		{
			pop_back(stack);
		}
	}

	return (0);
}
