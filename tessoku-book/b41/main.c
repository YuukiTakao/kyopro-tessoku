#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
	int first;
	int second;
}	Pair;
typedef struct vector {
	Pair	*array;
	int		len;
	int		cap;
}	vector;
vector	*new(int cap) {
	vector *self = calloc(1, sizeof(vector));
	if (!self)
		printf("failed vector new...\n");
	self->cap = cap;
	self->len = 0;
	self->array = calloc(self->cap, sizeof(Pair));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
vector	*resize(vector *self, int new_cap) {
	int new_size = new_cap * sizeof(Pair);
	Pair *tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
Pair	pop_back(vector *self) {
	if (self->len == 0) {
		printf("failed push_back in realloc...\n");
	}
	self->len--;
	return self->array[self->len];
}
Pair	back(vector *self) {
	return self->array[self->len-1];
}
void	push_back(vector *self, Pair elem) {
	if (self->len >= self->cap) {
		int add = self->cap * 1.5;
		if (resize(self, add) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// printf("self->len=%d strlen=%lu elem=%s\n",self->len,strlen(elem), elem);
	self->array[self->len] = elem;
	self->len++;
}

int	main(void) {
	int X, Y;

	scanf("%d %d", &X, &Y);
	// printf("%d %d\n", X, Y);

	vector *stack = new(2);

	while (X >= 2 || Y >= 2) {
		Pair pair;
		pair.first = X;
		pair.second = Y;
		// printf("f=%d s=%d\n", pair.first, pair.second);
		push_back(stack, pair);
		
		if (X > Y)
			X -= Y;
		else
			Y -= X;
	}

	printf("%d\n", stack->len);
	int count = stack->len;
	for (int i = 0; i < count; i++) {
		Pair ans = pop_back(stack);
		printf("%d %d\n", ans.first, ans.second);
	}

	return (0);
}