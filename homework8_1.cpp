
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#define MAX_ELEMENT 2000
typedef struct element{
	int key;
} element;

typedef struct {
	element *heap;
	int heap_size;
} HeapType;


// Initialization
void init(HeapType *h) {
	h->heap_size = 0;
}

void decrease_key_min_heap(HeapType *h, int i, int key){
	int temp;

	if(key >= h->heap[i].key)
		printf("new key is smaller than current key\n");
	h->heap[i].key = key;
	while((i != 1) && h->heap[i/2].key > h->heap[i].key){
		temp = h->heap[i].key;
		h->heap[i].key = h->heap[i/2].key;
		h->heap[i/2].key = temp;
		i = i/2;
	}
}

void increase_key_min_heap(HeapType *h, int i, int key){
	int temp;

	if(key <= h->heap[i].key)
		printf("new key is not larger than current key\n");
	h->heap[i].key = key;
	while(i <= h->heap_size && 2*i <= h->heap_size){
		if(h->heap[2*i].key <= h->heap[2*i+1].key){
			temp = h->heap[i].key;
			h->heap[i].key = h->heap[2*i].key;
			h->heap[2*i].key = temp;
			i = 2*i;
		}else{
			temp = h->heap[i].key;
			h->heap[i].key = h->heap[2*i+1].key;
			h->heap[2*i+1].key = temp;
			i = 2*i+1;
		}
		
	}
}

void build_min_heap(HeapType *h)
{
	int i;
	int temp;
	int child;
	int parent;
	for(i = h->heap_size/2;i >=1;i--){
		child = 2*i;
		parent = i;
		while(child <= h->heap_size){
		if(child+1 < h->heap_size && h->heap[child].key > h->heap[child+1].key){
			child++;
		}
		if(h->heap[parent].key <= h->heap[child].key) break;
		temp = h->heap[parent].key;
		h->heap[parent].key = h->heap[child].key;
		h->heap[child].key = temp;
		parent = child;
		child *= 2;
		}
	}
}

void main()
{
	int input_size = 10;	
	
	HeapType *h1 = (HeapType *)malloc(sizeof(HeapType));
	// 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
	h1->heap = (element *)malloc(sizeof(element)*(input_size + 1));

	h1->heap[1].key = 1;
	h1->heap[2].key = 4;
	h1->heap[3].key = 2;
	h1->heap[4].key = 7;
	h1->heap[5].key = 5;
	h1->heap[6].key = 3;
	h1->heap[7].key = 3;
	h1->heap[8].key = 7;
	h1->heap[9].key = 8;
	h1->heap[10].key = 9;

	h1->heap_size = input_size;

	build_min_heap(h1);
	
    printf("Input data\n");
	for (int i = 0; i < input_size; i++)	printf("%d\n", h1->heap[i + 1].key);
	printf("\n");
	
	decrease_key_min_heap(h1, 4, 3);
	increase_key_min_heap(h1, 3, 10);
	printf("result\n");
	for (int i = 0; i < input_size; i++)	printf("%d\n", h1->heap[i + 1].key);
	printf("\n");
	
}