#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8
#define INF 1000L
#define TRUE 1
#define FALSE 0

typedef struct element{
	int key;
	int vertex;
} element;

typedef struct {
	element *heap;
	int heap_size;
} HeapType;

int weight[MAX_VERTICES][MAX_VERTICES] =
{ { 0,3,INF,INF,INF,INF,INF,14 },
{ 3,0,8,INF,INF,INF,INF,10 },
{ INF,8,0,15,2,INF,INF,INF },
{ INF,INF,15,0,INF,INF,INF,INF },
{ INF,INF,2,INF,0,9,4,5 },
{ INF,INF,INF,INF,9,0,INF,INF },
{ INF,INF,INF,INF,4,INF,0,6 },
{ 14,10,INF,INF,5,INF,6,0 } };int dist[MAX_VERTICES];int found[MAX_VERTICES];int parent[MAX_VERTICES];void build_min_heap(HeapType *h)
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
}int delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// Find a smaller child node
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// Move down one level
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item.vertex;
}void decrease_key_min_heap(HeapType *h, int v, int key){
	element temp;
	int i;
	for(i=1;i<h->heap_size+1;i++){
		if(h->heap[i].vertex == v)
			break;
	}
	h->heap[i].key = key;
	while((i != 1) && h->heap[i/2].key > h->heap[i].key){
		temp = h->heap[i];
		h->heap[i] = h->heap[i/2];
		h->heap[i/2] = temp;
		i = i/2;
	}
}void shortest_path(int start){	int u,i,w;	int input_size = MAX_VERTICES;	for(u=0;u<MAX_VERTICES;u++){		dist[u] = INF;		parent[u] = NULL;		found[u] = FALSE;	}	dist[start] = 0;	HeapType *h1 = (HeapType *)malloc(sizeof(HeapType));
	// 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
	h1->heap = (element *)malloc(sizeof(element)*(input_size + 1));	h1->heap_size = MAX_VERTICES;		for(int i=0;i<MAX_VERTICES;i++){		h1->heap[i+1].key = dist[i];		h1->heap[i+1].vertex = i;	}	build_min_heap(h1);	for(i=0;i<input_size-1;i++){		u = delete_min_heap(h1);		found[u] = TRUE;		for(w=0; w<MAX_VERTICES;w++){			if(!found[w]){				if(dist[u]+weight[u][w] < dist[w]){					parent[w] = u;					dist[w] = dist[u]+weight[u][w];					decrease_key_min_heap(h1, w, dist[u]+weight[u][w]);				}			}		}	}}void print_dijkstra(int num){	int i = num;	int count = 0;	int arr[10];	printf("Shortest path: ");	while(i != 0){		arr[count] = parent[i];		count++;		i = parent[i];	}	for(i=count-1;i>=0;i--)		printf("v%d -> ",arr[i]);	printf("v%d\n",num);	printf("Shortest path distance: %d\n",dist[num]);}int main(void){	int num;	printf("Enter arrival vertex:");	scanf("%d",&num);	shortest_path(0);	print_dijkstra(num);}