#include<stdio.h>



void dinsert_node(DlistNode *before, DlistNode *new_node){
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

//phead������尡��Ű��������
//new_node�»��θǵڿ��߰��ɳ��
void dinsert_last_node(DlistNode *phead, DlistNode *new_node){
	DlistNode *p;
	if(phead->rlink == phead) {
		//����常�����ϴ°��
		new_node->llink = phead;
		new_node->rlink = phead;
		phead->rlink = new_node;
		phead->llink = new_node;
	}else{
		p = phead->rlink;
		while(p->rlink != phead)  //���������ã�°���
			p=p->rlink;
		printf("%x\n",p);
		dinsert_node(p,new_node);
	}
}
