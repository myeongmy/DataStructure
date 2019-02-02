#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct TreeNode{
	int key;
	struct TreeNode *left;
	struct TreeNode *right;
};

void insert_node(TreeNode **root, int key){
	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;

	while(t != NULL){
		if(t->key == key) return;
		p = t;
		if(key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	n = (TreeNode *)malloc(sizeof(TreeNode));
	n->key = key;
	n->left = n->right = NULL;
	if(p != NULL){
		if(key < p->key)
			p->left = n;
		else
			p->right = n;
	}else
		*root = n;
}

void print_result(TreeNode *root){
	if(root != NULL){
		print_result(root->left);
		printf("%d\n",root->key);
		print_result(root->right);
	}
}
void main(){
	int input_size = 1000;
	int data_maxval = 10000;

	int *input = (int *)malloc(input_size*sizeof(int));
	
	TreeNode *root = NULL;
	for(int i=0;i<input_size;i++){
		input[i] = rand() % data_maxval;
		insert_node(&root,input[i]);
	}
	
	print_result(root);
}
