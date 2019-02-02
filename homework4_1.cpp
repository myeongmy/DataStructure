// linked_stack.cpp : Defines the entry point for the console application.

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct StackNode { // simple linked list가 아닌 circular doubly linked list로 구현하기 위해 노드 구성 요소 변경
	element item;
	struct StackNode *llink;
	struct StackNode *rlink;
} StackNode;

typedef struct {
	StackNode topnode;    // head node의 역할
} LinkedStackType;

// 초기화 함수
// topnode(headnode)의 포인터는 모두 자기 자신을 가리키게 초기화
void init(LinkedStackType *s)   
{
	s->topnode.llink = &(s->topnode);
	s->topnode.rlink = &(s->topnode);
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
	return (s->topnode.llink == &(s->topnode) && s->topnode.rlink == &(s->topnode));
}

// 삽입 함수
void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n"); 
			return;
	}

	else {
		if(is_empty(s)){     // 공백 리스트(topnode만 있는 경우)인 경우
		temp->item = item;
		temp->llink = &(s->topnode);
		temp->rlink = &(s->topnode);
		s->topnode.llink = temp;
		s->topnode.rlink = temp;
		}else{
			temp->item = item;
			temp->rlink = s->topnode.rlink;
			temp->llink = &(s->topnode);
			s->topnode.rlink->llink = temp;
			s->topnode.rlink = temp;
			
		}
	}
}

//삭제 함수
element pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		StackNode *temp = s->topnode.rlink;
		element item = temp->item;
		s->topnode.rlink = temp->rlink;
		temp->rlink->llink = &(s->topnode);
		free(temp);
		return item;
	}
}

//피크 함수
element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {		
		return s->topnode.rlink->item;
	}
}

void main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}



