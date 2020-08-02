#include <stdio.h>
#include <stdlib.h>
#define maxsize 20

typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree;

typedef struct{
	int key[maxsize];
	Tree *Data[maxsize];
	int top;
}Stack;
Stack stack;
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
			printf("error!\n");
			exit(1);
		}else{
			(*head)->Data = k;
			CreateTree(&((*head)->left));
			CreateTree(&((*head)->right));
		}
	}
}


Stack *CreateStack(){
	Stack *s;
	int i;
	s = (Stack *)malloc(sizeof(stack));
	for(i = 0; i < maxsize ;i ++){
		s->key[i] = 0;
	}
	s->top = -1;
	return s;
}

Tree *Pop(Stack *s){
	Tree *T;
	if(s->top == -1){
		printf("empty!!\n");
		exit(1);
	}else{
		T = s->Data[(s->top)--];
		return T;
	}
}

Tree *getPop(Stack *s){
	Tree *T;
	if(s->top == -1){
		printf("empty!!\n");
		exit(1);
	}else{
		T = s->Data[(s->top)];
		//s->key[s->top] = 1;
		return T;
	}
}

void push(Stack * s,Tree *head,int k){
	if(s->top == maxsize - 1){
		printf("full\n");
		exit(1);
	}else{
		s->Data[++(s->top)] = head;
		s->key[s->top] = k;
	}
}

void behindLook(Tree *head,Stack *s){
	Tree *T = head;
	while( T!= NULL){
		push(s,T,0);
		T = T->left;
	}
	
	while(s->top != -1){
		T = getPop(s);
		if(T->right == NULL || s->key[s->top] == 1){
			T = Pop(s);
			printf("%5d",T->Data);
		}else{
			s->key[s->top] = 1;
			T = T->right;
			while(T != NULL){
				push(s,T,0);
				T = T->left;
			}
		}
	}
}


int main(){
	Tree *head;
	Stack *s;
	CreateTree(&head);
	s = CreateStack();
	behindLook(head,s);
	return 0;	
}