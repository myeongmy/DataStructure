#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<limits.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

typedef struct{
	ListNode *head;
	int length;
} LinkedListType;

ListNode * get_node_at(LinkedListType *list, int pos){
	int i;
	ListNode *tmp_node = list->head;
	if(pos<0) return NULL;
	for(i=0;i<pos;i++)
		tmp_node = tmp_node -> link;
	return tmp_node;
}
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
	if(*phead == NULL){
		new_node->link = NULL;
		*phead = new_node;
	}
	else if(p==NULL){
		new_node->link = *phead;
		*phead = new_node;
	}
	else{
		new_node->link = p->link;
		p->link = new_node;
	}
}
void add(LinkedListType *list, int position, element data){
	ListNode *p;
	if((position >=0) && (position <= list->length)){
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		node->data = data;
		p = get_node_at(list,position-1);
		insert_node(&(list->head),p,node);
		list->length++;
	}
}
void add_last(LinkedListType *list, element data){
	add(list,list->length,data);
}
void add_first(LinkedListType *list, element data){
	add(list,0,data);
}
void init(LinkedListType *list){
	if(list == NULL) return;
	list->length = 0;
	list->head = NULL;
}
LinkedListType merge_list(LinkedListType *list1, LinkedListType *list2){
	LinkedListType list3;
	init(&list3);
	ListNode *p;
	ListNode *q;
	p = list1->head;
	q = list2->head;

	if(p == NULL)  //list1이빈리스트인경우
		return *list2;
	if(q == NULL)  //list2가빈리스트인경우
		return *list1;

	while(p != NULL || q != NULL){
		if(p != NULL && q != NULL && p->data <= q->data){
			add_last(&list3,p->data);
			p = p->link;
		}else if(p != NULL && q != NULL && p->data > q->data){
			add_last(&list3,q->data);
			q = q->link;
		}else if(p == NULL && q != NULL){  //leftovers 처리
			add_last(&list3,q->data);
			q = q->link;
		}else if(q==NULL && p != NULL){
			add_last(&list3,p->data);
			p = p->link;
		}
	}
	
	return list3;
}
void display(LinkedListType *list){
	int i;
	ListNode *node = list->head;
	printf("(");
	for(i=0;i<list->length;i++){
		printf("%d ",node->data);
		node = node->link;
	}
	printf(")\n");
}



int main(){
	LinkedListType list1;
	LinkedListType list2;

	init(&list1);
	init(&list2);

	add(&list1,0,25);
	add(&list1,0,20);
	add(&list1,0,15);
	add(&list1,0,10);
	add(&list1,0,5);
	add(&list1,0,2);
	add(&list1,0,1);

	add(&list2,0,30);
	add(&list2,0,18);
	add(&list2,0,15);
	add(&list2,0,8);
	add(&list2,0,7);
	add(&list2,0,3);

	printf("list1: ");
	display(&list1);
	printf("list2: ");
	display(&list2);

	LinkedListType list = merge_list(&list1,&list2);
	printf("Merged list: ");
	display(&list);
}
