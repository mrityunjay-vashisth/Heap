#include "iostream"


class MinHeap {
public:
	MinHeap(int cap = 0):
		capacity(cap), arr(new int[cap]) {}
	void build_min_heap(int *vals, int n);
	void min_heapify(int key);
	int parent(int key) {return (key - 1)/2;}
	int left_child(int key) {return 2 * key + 1;}
	int right_child(int key) {return 2 * key + 2;}
	void insert_key(int key);
	int extract_key();
	int get_min() {return arr[0];}
	void decrease_key(int key, int val);
	void delete_key(int key);
	void swap(int *x, int *y) {(*x ^= *y), (*y ^= *x), (*x ^= *y);}
	void print();
private:
	int *arr;
	int capacity;
	int heap_size;
};


void
MinHeap::build_min_heap(int *vals, int n) {
	for(int i = 0; i < capacity; i++)
		arr[i] = vals[i];
	heap_size = n;

	print();
	for (int i = (heap_size + 1)/2; i >= 0; i--)
		min_heapify(i);
}


void
MinHeap::min_heapify(int key) {
	int l, r, min = key;
	l = left_child(key);
	r = right_child(key);
	if (l < heap_size && arr[key] > arr[l])
		min = l;
	if (r < heap_size && arr[min] > arr[r])
		min = r;
	if (min != key) {
		swap(&arr[min], &arr[key]);
		min_heapify(min);
	}
}

int
MinHeap::extract_key() {
	if (heap_size < 0) {
		std::cout<<"Heap empty"<<std::endl;
		return INT_MAX;
	}
	int min_val = arr[0];
	arr[0] = arr[heap_size - 1];
	heap_size--;
	min_heapify(0);
	return min_val;
}


void
MinHeap::decrease_key(int key, int val) {
	arr[key] = val;
	while (key != 0 && arr[parent(key)] > arr[key]) {
		swap(&arr[parent(key)], &arr[key]);
		key = parent(key);
	}
}


void
MinHeap::delete_key(int key) {
	decrease_key(key, INT_MIN);
	extract_key();
}


void
MinHeap::print(){
	for (int i = 0; i < heap_size; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}


int main(int argc, char const *argv[])
{
	int val[5] = {5,4,3,0,1};
	MinHeap h(5);
	h.build_min_heap(val, 5);
	h.print();
	std::cout<<"Min Val : = "<<h.extract_key()<<std::endl;
	h.print();
	h.delete_key(2);
	h.print();
	std::cout<<h.get_min()<<std::endl;
	return 0;
}