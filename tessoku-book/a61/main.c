#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int int_compare(const void * n1, const void * n2) {
	// asc
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}
typedef struct {
	int vertex; // 頂点
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
ad_list_t *array_new(void) {
	ad_list_t *self = calloc(1, sizeof(*self));
	if (!self)
		return NULL;
	self->cap = 100;
	self->arr = calloc(self->cap, sizeof(int));
	if (!self->arr) {
		free(self);
		return NULL;
	}
	return self;
}

int	main(void)
{
	int			N;
	int			M;
	ad_list_t	**ad_list;

	scanf("%d%d", &N, &M);

	ad_list = (ad_list_t **)calloc(N + 2, sizeof(ad_list_t));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (ad_list[a] == NULL)
			ad_list[a] = array_new();

		if (ad_list[b] == NULL)
			ad_list[b] = array_new();
		// printf("i=%d a=%d b=%d\n", i, a, b);
		push_back(ad_list[a], b);
		push_back(ad_list[b], a);
	}

	for (int i = 1; i <= N; i++) {
		if (ad_list[i] != NULL) {
			qsort(ad_list[i]->arr, ad_list[i]->len, sizeof(int), int_compare);
			printf("%d: {", i);
			printf("%d", ad_list[i]->arr[0]);
			for (int j = 1; j < ad_list[i]->len; j++) {
				if (ad_list[i]->arr[j] == ad_list[i]->arr[j-1])
					continue;
				printf(", %d", ad_list[i]->arr[j]);
			}
			printf("}\n");
		} else {
			printf("%d: {}\n", i);
		}
	}
	return (0);
}
