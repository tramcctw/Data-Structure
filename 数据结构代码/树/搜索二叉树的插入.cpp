#include "stdio.h"
#include "stdlib.h"

typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;	
}Tree;

Tree tree;

void CreateTree(Tree **head){
	int k;
	scanf("%d",&k);
	if(k == -1){
		*head = NULL;
		return;
	}else{
		(*head) = (Tree *)malloc(sizeof(tree));
		if(!(*head)){
			printf("error\n");
			exit(1);
		}else{
			(*head)->Data = k;
			CreateTree(&((*head)->left));
			CreateTree(&((*head)->right));
		}
	}
}

Tree *Insert(Tree *head,int x){
	if(head == NULL){
		head = (Tree *)malloc(sizeof(tree));
		head->Data = x;
		head->left = NULL;
		head->right = NULL;
	}else{
		if(head->Data > x){
			head->left = Insert(head->left,x);
		}
		if(head->Data <= x){
			head->right = Insert(head->right,x);
		}
	}
	return head;
}

int find(Tree *head,int x){
	Tree * T = head;
	while(T){
		if(T->Data > x){
			T = T->left;
		}else if(T->Data < x){
			T = T->right;
		}else{
			return 1;
		}
	}
	return 0;
}


int main()
{
	int x;
	Tree *head;
	CreateTree(&head);
	printf("please input need insert number:");
	scanf("%d",&x);
	Insert(head,x);
	printf("please input need find number:");
	scanf("%d",&x);
	if(find(head,x)){
		printf("find\n");
	}else{
		printf("Not find\n");
	}
    return 0;
}