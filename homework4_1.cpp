// linked_stack.cpp : Defines the entry point for the console application.

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct StackNode { // simple linked list�� �ƴ� circular doubly linked list�� �����ϱ� ���� ��� ���� ��� ����
	element item;
	struct StackNode *llink;
	struct StackNode *rlink;
} StackNode;

typedef struct {
	StackNode topnode;    // head node�� ����
} LinkedStackType;

// �ʱ�ȭ �Լ�
// topnode(headnode)�� �����ʹ� ��� �ڱ� �ڽ��� ����Ű�� �ʱ�ȭ
void init(LinkedStackType *s)   
{
	s->topnode.llink = &(s->topnode);
	s->topnode.rlink = &(s->topnode);
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType *s)
{
	return (s->topnode.llink == &(s->topnode) && s->topnode.rlink == &(s->topnode));
}

// ���� �Լ�
void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n"); 
			return;
	}

	else {
		if(is_empty(s)){     // ���� ����Ʈ(topnode�� �ִ� ���)�� ���
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

//���� �Լ�
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

//��ũ �Լ�
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



