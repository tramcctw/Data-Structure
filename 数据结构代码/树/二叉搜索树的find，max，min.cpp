#include <stdio.h>
#include <stdlib.h>

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

int max(Tree *head){
	Tree *T = head;
	while(T->right){
		T = T->right;
	}
	return T->Data;
}

int min(Tree *head){
	Tree *T = head;
	while(T->left){
		T = T->left;
	}
	return T->Data;
}

int main()
{
	int x;
	Tree *head;
	CreateTree(&head);
	printf("please input need find number:");
	scanf("%d",&x);
	if(find(head,x)){
		printf("find\n");
	}else{
		printf("Not find\n");
	}
	printf("max is %d\n",max(head));
	printf("min is %d\n",min(head));
    return 0;
}