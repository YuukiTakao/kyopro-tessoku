#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int	*arr;
	int	len;
	int	cap;
}	ad_list_t;
ad_list_t *arr_resize(ad_list_t *self, int cap) {
	int byte = sizeof(int);
	int size = cap * byte;
	int *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	push_back(ad_list_t *self, int elem) {
	if (self->len >= self->cap)
	{
		if (! arr_resize(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[self->len] = elem;
	self->len++;
}
ad_list_t *array_new(int cap) {
	ad_list_t *self = calloc(1, sizeof(*self));
	if (!self)
		return NULL;
	self->cap = cap;
	self->arr = calloc(self->cap, sizeof(int));
	if (!self->arr) {
		free(self);
		return NULL;
	}
	return self;
}

typedef struct Queue {
	int 	*array;
	int	len;
	int	cap;
	int	front_idx;
}	Queue;
Queue	*new(int cap) {
	Queue *self = calloc(1, sizeof(Queue));
	if (!self)
		printf("failed Queue new...\n");
	self->cap = cap;
	self->len = 0;
	self->front_idx = 0; 
	self->array = calloc(self->cap, sizeof(int));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Queue	*resize(Queue *self, int new_cap) {
	int	new_size = new_cap * sizeof(int);
	int	*tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
int is_empty(Queue *Q) {
	return Q->len == Q->front_idx;
}
void	pop(Queue *self) {
	self->front_idx++;
}
int	front(Queue *self) {
	return self->array[self->front_idx];
}
void	qpush_back(Queue *self, int elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	self->array[self->len] = elem;
	self->len++;
}

int	main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	
	ad_list_t **ad_list = calloc(N+1, sizeof(ad_list_t *));
	for (int i = 0; i < M; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
	
		if (ad_list[A] == NULL) {	
			ad_list[A] = array_new(2);
		}
		if (ad_list[B] == NULL) {
			ad_list[B] = array_new(2);
		}
		push_back(ad_list[A], B);
		push_back(ad_list[B], A);
	}
	int *dist;
	dist = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;

	if (M >= 1) {
		Queue *Q = new(N+1);
		qpush_back(Q, 1);
		while (!is_empty(Q)) {
			int pos = front(Q);
			pop(Q);
			for (int i = 0; i < ad_list[pos]->len; i++) {
				int to = ad_list[pos]->arr[i];
				if (dist[to] == -1) {
					dist[to] = dist[pos] + 1;
					qpush_back(Q, to);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}
	return (0);
}