#include <stdio.h>
#include <stdlib.h>
#define maxsize 20


typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree;


typedef struct{
	Tree *Data[maxsize];
	int front;
	int rear;
}Que;

Tree tree;
Que que;

void CreateTree(Tree **head){
	int k;
	scanf("%d",&k);
	if(k == -1){
		*head = NULL;
		return; 
	}else{
		(*head) = (Tree *)malloc(sizeof(tree));
		if(!(*head)){
			printf("error");
			exit(1);
		}else{
			(*head)->Data = k;
			CreateTree(&((*head)->left));
			CreateTree(&((*head)->right));
		}
	}
}

void first(Tree *head){
	if(head == NULL){
		return;
	}else{
		printf("%d ",head->Data);
		first(head->left);
		first(head->right);
	}
}

Que * CreateQue(){
	Que *pt;
	pt = (Que*)malloc(sizeof(que));
	pt->front = pt->rear = 0;
	return pt;
}

int QueIsempty(Que *pt){
	if(pt->rear == pt->front){
		return 1;
	}else{
		return 0;
	}
}

void InQue(Que *pt,Tree *head){
	if((pt->rear + 1)%maxsize == pt->front){
		printf("que is full!\n");
		exit(1);	
	}else{
		pt->rear = (pt->rear + 1)%maxsize;
		pt->Data[pt->rear] = head;
	}
}

Tree* OutQue(Que *pt){
	if(pt->front == pt->rear){
		printf("que is full");
		exit(1);
	}else{
		pt->front = (pt->front + 1)%maxsize;
		return pt->Data[pt->front];
	}
}

void Cccc(Tree *head,Que *pt){
	Tree * p;
	if(head == NULL){
		printf("tree is empty!!\n");
		return;
	}else{
		InQue(pt,head);
		while(!QueIsempty(pt)){
			p = OutQue(pt);
			printf("%d ",p->Data);
			if(p->left)
				InQue(pt,p->left);
			if(p->right)
			InQue(pt,p->right);
		}
	}	
}

int main()
{
    Tree *head;
    Que * pt;
    CreateTree(&head);
    //first(head);
    pt = CreateQue();
   	Cccc(head,pt);
    return 0;
}