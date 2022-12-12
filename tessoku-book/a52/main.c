#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector {
	char	**array;
	size_t	len;
	size_t	cap;
	size_t	front_idx;
}	vector;
vector	*new(int cap) {
	vector *self = calloc(1, sizeof(vector));
	if (!self)
		printf("failed vector new...\n");
	self->cap = cap;
	self->len = 0;
	self->front_idx = 0; 
	self->array = calloc(self->cap, sizeof(char *));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
vector	*resize(vector *self, int new_cap) {
	int		new_size = new_cap * sizeof(int);
	char	**tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	pop(vector *self) {
	self->front_idx++;
}
char	*front(vector *self) {
	return self->array[self->front_idx];
}
void	push_back(vector *self, char *elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	self->array[self->len] = calloc(strlen(elem)+9, sizeof(char));
	self->array[self->len] = elem;
	self->len++;
}

int	main(void)
{
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);
	
	int *qs = calloc(Q+1, sizeof(int));
	vector *queue = new(Q+9);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &qs[i]);
		if (qs[i] == 1)
		{
			char *tmp = calloc(20+9, sizeof(char));
			scanf("%s", tmp);
			push_back(queue, tmp);
		}
		else if (qs[i] == 2)
			printf("%s\n", front(queue));
		else if (qs[i] == 3)
			pop(queue);
	}

	return (0);
}
