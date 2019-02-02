
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
	ListNode *tail;
	int length;
} ListType;

#define TRUE 1
#define FALSE 0

int is_empty(ListType *list){
	if(list->head == NULL && list->tail == NULL)  // �󸮽�Ʈ
		return 1;
	else
		return 0;
}

int get_length(ListType *list){
	return list->length;
}

ListNode * get_node_at(ListType *list, int pos){
	int i;
	ListNode *tmp_node = list->head;
	if(pos<0) return NULL;
	for(i=0;i<pos;i++)
		tmp_node = tmp_node -> link;
	return tmp_node;
}
void insert_node(ListNode **phead, ListNode **ptail, ListNode *p, ListNode *new_node){
	if(*phead == NULL && *ptail == NULL){   // ���鸮��Ʈ�ΰ��
		new_node->link = NULL;
		*phead = new_node;
		*ptail = new_node;
	}
	else if(p==NULL){  // p�� null�̸�ù��°���λ���
		new_node->link = *phead;
		*phead = new_node;
	}
	else{
		if(p == *ptail) *ptail = new_node; // �������������ϴ°��
		new_node->link = p->link;
		p->link = new_node;
	}
}

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}
void add(ListType *list, int position, element data){
	ListNode *p;
	if((position >=0) && (position <= list->length)){
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		if(node == NULL) error("Memory allocation error");
		node->data = data;
		p = get_node_at(list,position-1);
		insert_node(&(list->head),&(list->tail),p,node);
		list->length++;
	}
}
void add_last(ListType *list, element data){
	add(list,list->length,data);
}
void add_first(ListType *list, element data){
	add(list,0,data);
}
void remove_node(ListNode **phead, ListNode **ptail, ListNode *p, ListNode *removed){
	if(*phead == *ptail){ //��尡�ϳ��ΰ��
		*phead = NULL;
		*ptail = NULL;
	}
	if (p == NULL){
		*(phead) = (*phead)->link;
	}else{
		if(removed == *ptail) *ptail = p; //��������带�����ϴ°��
		p->link = removed->link;
	}
	free(removed);
}

void deletion(ListType *list, int pos){
	if(!is_empty(list) && (pos>= 0) && (pos< list->length)){
		ListNode *p = get_node_at(list,pos-1);
		ListNode *removed = get_node_at(list,pos);
		remove_node(&(list->head),&(list->tail),p,removed);
		list->length--;
	}
}
void delete_first(ListType *list){
	deletion(list,0);
}
void delete_last(ListType *list){
	deletion(list,list->length-1);
}

void init(ListType *list){
	if(list == NULL) return;
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
}
element get_entry(ListType *list, int pos){
	ListNode *p;
	if(pos>= list->length) error("��ġ����");
	p = get_node_at(list,pos);
	return p->data;
}
void display(ListType *list){
	int i;
	ListNode *node = list->head;
	printf("(");
	for(i=0;i<list->length;i++){
		printf("%d ",node->data);
		node = node->link;
	}
	printf(")\n");
}
int is_in_list(ListType *list, element item){
	ListNode *p;
	p = list->head;
	while((p!=NULL)){
		if(p->data == item)
			break;
		p=p->link;
	}
	if(p=NULL) return FALSE;
	else return TRUE;
}


int main(){
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);

	deletion(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);

	printf("%s\n",is_in_list(&list1, 20) == TRUE ? "TRUE": "FALSE");
	printf("%d\n",get_entry(&list1,0));
	
}
