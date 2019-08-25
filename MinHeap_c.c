#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int *harr;
	int capacity;
	int heap_size;
}heap_t;

heap_t *CreateHeap(int capacity);
void BuildHeap(heap_t *heap, int *harr, int n);
void Heapify(heap_t *heap, int node);
int LeftChild(heap_t *heap, int i);
int RightChild(heap_t *heap, int i);
void Insert(heap_t *heap, int val);



int 
main() {
	heap_t *heap = CreateHeap(10);
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d ", &arr[i]);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	BuildHeap(heap, arr, 10);
	printf("%d\n", heap->harr[0]);
	return 0;
}

void
Insert(heap_t *heap, int val) {
	int i = heap->heap_size;
	heap->heap_size++;

}

heap_t *
CreateHeap(int capacity) {
	heap_t *heap = (heap_t *) malloc(sizeof(heap_t));
	heap->harr = (int *) malloc(capacity * sizeof(int));
	heap->capacity = capacity;
	heap->heap_size = 0;
	return heap;
}

int
LeftChild(heap_t *heap, int i) {
	if (heap->heap_size < i)
		return -1;
	return 2 * i + 1;
}

int
RightChild(heap_t *heap, int i) {
	if (heap->heap_size < i)
		return -1;
	return 2 * i + 2;
}

void
Heapify(heap_t *heap, int i) {
	int l, r, min;
	l = LeftChild(heap, i);
	r = RightChild(heap, i);
	if (i < 0)
		return;
	if (l != -1 && heap->harr[i] > heap->harr[l])
		min = l;
	else
		min = i;
	if (r != -1 && heap->harr[r] < heap->harr[min])
		min = r;
	if (min != i) {
		int tmp = heap->harr[i];
		heap->harr[i] = heap->harr[min];
		heap->harr[min] = tmp;
	}
	Heapify(heap, min);
}

void
BuildHeap(heap_t *heap, int *harr, int n) {
	for (int i = 0; i < n; i++)
		heap->harr[i] = harr[i];
	heap->heap_size = n;

	for (int i = (heap->heap_size - 1)/2; i >=0; i--)
		Heapify(heap, i);
}

