#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;	
}Tree;

Tree tree;

void CreateTree(Tree ** head){
	int k;
	scanf("%d",&k);
	if(k == -1){
		*head = NULL;	
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

Tree * FindMin(Tree *head){
	Tree *T;
	T = head;
	while(T->left){
		T = T->left;
	}	
	return T;
}


Tree *Delete(Tree *head,int data){
	Tree *temp;
	if(!head){
		printf("要删除的元素没有找到!\n");
	}else 
	if(head->Data > data){
		 	head->left = Delete(head->left,data);
		 	//printf("OK\n");
	}else 
		if(head->Data < data){
			head->right = Delete(head->right,data);
			//printf("OK\n");
	}else
		if(head->left && head->right){
			temp = FindMin(head->right);		//找到右子树上最小的
			head->Data = temp->Data;
			head->right = Delete(head->right,head->Data);
		}else{
			//printf("OK\n");
			temp = head;
			if(!head->left)
				head = head->right;
			else if(!head->right)
					head = head->left;
			free(temp);
		}	
	return head;	
}

void find(Tree *head,int x){
	Tree *T = head;
	if(T == NULL){
		printf("Not Data\n");
	}else{
	
		while(T){
			if(T->Data < x){
				T = T->right;
			}else if(T->Data > x){
				T = T->left;
			}else{
				printf("find!\n");
				return;
			}
		}
		printf("Not Data\n");
	}	
}

void firstLook(Tree *head){
	if(head){
		printf("%d ",head->Data);
		firstLook(head->left);
		firstLook(head->right);	
	}
}


int main()
{
	Tree *head;
    int x;
    CreateTree(&head);
    //firstLook(head);
    find(head,10);
    printf("please input need del num:");
    scanf("%d",&x);
    Delete(head,x);
    find(head,10);
    firstLook(head);
    return 0;
}