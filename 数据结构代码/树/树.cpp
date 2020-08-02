#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree;

Tree tree;

void  Creat(Tree **head){
    int k;
    scanf("%d",&k);
    if(k == -1){
        *head = NULL;        
    }else{
        (*head) = (Tree *)malloc(sizeof(tree));
         if(!(*head)) 
		 	exit(1);
        (*head)->Data = k;
        Creat(&((*head)->left));
        Creat(&((*head)->right));
    }
}

void firstLook(Tree *head){
	if(head){
		printf("%d ",head->Data);
		firstLook(head->left);
		firstLook(head->right);	
	}
}

void middleLook(Tree *head){
	if(head){
		middleLook(head->left);
		printf("%d ",head->Data);
		middleLook(head->right);
	}
}

void afterLook(Tree * head){      
	if(head){      
		afterLook(head->left);       
		afterLook(head->right);      
		printf("%d ",head->Data);       
	} 
}

int main(){
	Tree *head;
	Creat(&head);
	firstLook(head);
	printf("\n");
	middleLook(head);
	printf("\n");
	afterLook(head);
	return 0;		
}
