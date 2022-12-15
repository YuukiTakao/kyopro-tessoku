#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct item_t {
	int	value;
	int	priority;
	int	index;
}	item_t;
typedef struct vector {
	item_t	*items;
	size_t	len;
	size_t	cap;
	size_t	front_idx;
}	vector;
int	len(vector *pq) {
	return pq->len;
}
vector	*new(int cap) {
	vector *self = calloc(1, sizeof(vector));
	if (!self)
		printf("failed vector new...\n");
	self->cap = cap;
	self->len = 0;
	self->front_idx = 0; 
	self->items = calloc(self->cap, sizeof(item_t));
	if (self->items == NULL) {
		printf("failed items memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
vector	*resize(vector *self, int new_cap) {
	int		new_size = new_cap * sizeof(item_t);
	item_t	*tmp = realloc(self->items, new_size);
	if (tmp == NULL) {
		printf("failed items realloc...\n");
		return NULL;
	}
	self->items = tmp;
	self->cap = new_cap;
	return self;
}
item_t	front(vector *self) {
	return self->items[0];
}
void	push_back(vector *self, int elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	self->items[self->len].value = elem;
	self->items[self->len].index = self->len;
	self->len++;
}
void	swap(vector *pq, int i, int j) {
	item_t tmp = pq->items[i];
	pq->items[i] = pq->items[j];
	pq->items[j] = tmp;
	pq->items[i].index = i;
	pq->items[j].index = j;
}
int	less(vector *pq, int i, int j) {
	return pq->items[i].value < pq->items[j].value; // asc 
}
void	up(vector *pq, int j) {
	for (;;) {
		int i = (j - 1) / 2; // parent
		if (i == j || less(pq, i, j)) {
			break;
		}
		swap(pq, i, j);
		j = i;
	}
}
int down(vector *pq, int i0, int n) {
	int i = i0;
	for (;;) {
		int j1 = 2*i + 1;
		if (j1 >= n || j1 < 0) { // j1 < 0 after int overflow
			break;
		}
		int max = j1; // left child
		int j2 = j1 + 1;
		if (j2 < n && less(pq, j2, j1)) {
			max = j2; // = 2*i + 2  // right child
		}
		if (!less(pq, max, i)) {
			break;
		}
		swap(pq, i, max);
		i = max;
	}
	return i > i0;
}
void	init(vector *pq) {
	// heapify
	int n = len(pq);
	for (int i = n/2 - 1; i >= 0; i--) {
		down(pq, i, n);
	}
}
void	heap_push(vector *pq, int x) {
	push_back(pq, x);
	up(pq, len(pq)-1);
}
void	heap_fix(vector *pq, int i) {
	if (! down(pq, i, len(pq))) {
		up(pq, i);
	}
}
void	update(vector *pq, int value) {
	pq->items[pq->len].value = value;
	heap_fix(pq, len(pq)-1);
}
item_t	pop (vector *pq) {
	vector *old = pq;
	int n = len(old);
	item_t item = old->items[n-1];
	item_t *old_item = &old->items[n-1];  // avoid memory leak
	old_item = NULL;
	item.index = -1; // for safety
	for (int i = 0; i < n-1; i++)
		pq->items[i] = old->items[i];
	pq->len--;
	return item;
}
item_t	heap_pop(vector *pq) {
	int n = len(pq) - 1;
	swap(pq, 0, n);
	down(pq, 0, n);
	return pop(pq);
}
int	main(void) {
	int Q;
	scanf("%d", &Q);

	int *queries;
	queries = calloc(Q+1, sizeof(int));

	vector *pq;
	pq = new(Q+1);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &queries[i]);
		if (queries[i] == 1) {
			int x;
			scanf("%d", &x);
			heap_push(pq, x);
		}
		else if (queries[i] == 2) {
			printf("%d\n", front(pq).value);
		}
		else if (queries[i] == 3)
			heap_pop(pq);
	}
	
	return (0);
}