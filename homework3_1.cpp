#include<stdio.h>



void dinsert_node(DlistNode *before, DlistNode *new_node){
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

//phead는헤드노드가리키는포인터
//new_node는새로맨뒤에추가될노드
void dinsert_last_node(DlistNode *phead, DlistNode *new_node){
	DlistNode *p;
	if(phead->rlink == phead) {
		//헤드노드만존재하는경우
		new_node->llink = phead;
		new_node->rlink = phead;
		phead->rlink = new_node;
		phead->llink = new_node;
	}else{
		p = phead->rlink;
		while(p->rlink != phead)  //마지막노드찾는과정
			p=p->rlink;
		printf("%x\n",p);
		dinsert_node(p,new_node);
	}
}
