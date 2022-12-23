#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
	int	*array;
	int	len;
	int	cap;
}	vector;
vector	*new(int cap) {
	vector *self = calloc(1, sizeof(vector));
	if (!self)
		printf("failed vector new...\n");
	self->cap = cap;
	self->len = 0;
	self->array = calloc(self->cap, sizeof(int));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
vector	*resize(vector *self, int new_cap) {
	int new_size = new_cap * sizeof(int);
	int *tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	push_back(vector *self, int elem) {
	// printf("len=%d cap=%d\n", self->len,  self->cap);
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	self->array[self->len] = elem;
	self->len++;
}

void dfs(vector **G, int *visited, int position) {
	visited[position] = 1;
	for (int i = 0; i < G[position]->len; i++) {
		int next = G[position]->array[i];
		if (visited[next] == 0)
			dfs(G, visited, next);
	}
	return ;
}

int	main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	// printf("N=%d M=%d\n", N, M);
	
	if (M == 0) {
		if (N >= 2)
			printf("The graph is not connected.\n");
		else
			printf("The graph is connected.\n");
		return 0;
	}
	vector **G = calloc(N+1, sizeof(vector *));
	for (int i = 1; i <= M; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		if (G[A] == NULL)
			G[A] = new(2);
		if (G[B] == NULL)
			G[B] = new(2);
		push_back(G[A], B);
		push_back(G[B], A);
	}
	int *visited;
	visited = calloc(N+1, sizeof(int));
	dfs(G, visited, 1);

	char *ans = "The graph is connected.";
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0)
			ans = "The graph is not connected.";
	}
	printf("%s\n", ans);

	return (0);
}