/* Note:Your choice is C IDE */
#include <stdio.h>
#include <stdlib.h>
#define maxsize 15

typedef struct TreeNode{
	int Data;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree;
Tree tree;

typedef struct{
	Tree *Data[maxsize];
	int top;
}Stack;
Stack stack;

void CreateTree(Tree **head){
	int k;
	scanf("%d",&k);
	if(k == -1){
		*head = NULL;	
	}else{
		(*head) = (Tree *)malloc(sizeof(tree));
		if(!(*head)){
			printf("发生错误!\n");
			exit(1);
		}else{
			(*head)->Data = k;
			CreateTree(&((*head)->left));
			CreateTree(&((*head)->right));
		}
	}
}

Stack * CreateStack(){
	Stack *s;
	s = (Stack*)malloc(sizeof(stack));
	s->top = -1;
	return s;	
}

int IsEmpty(Stack *s){
	if(s->top == -1){
		return 1;
	}else{
		return 0;
	}
}

void Push(Stack *s,Tree *node){
	if(s->top == maxsize - 1){
		printf("栈满了!\n");
		exit(1);
	}else{
		s->Data[++(s->top)] = node;
	}
}

Tree * Pop(Stack *s){
	Tree * node;
	if(s->top == -1){
		printf("栈空了!\n");
		exit(1);
	}else{
		node = s->Data[(s->top)--];
		return node;
	}
}

void firstLook(Tree *head){
	Tree *T = head;
	Stack *s = CreateStack();
	while(T || !IsEmpty(s)){
		while(T){
			Push(s,T);
			printf("%5d",T->Data);
			T = T->left;	
		}
		if(!IsEmpty(s)){
			T = Pop(s);
			T = T->right;
		}
	}
}

void middleLook(Tree *head){
	Tree *T = head;
	Stack *s = CreateStack();
	while(T || !IsEmpty(s)){
		while(T){
			Push(s,T);
			T = T->left;	
		}
		if(!IsEmpty(s)){
			T = Pop(s);
			printf("%5d",T->Data);
			T = T->right;
		}
	}
}



int main()
{
   Tree *head;
   CreateTree(&head);
   firstLook(head);
   printf("\n");
   middleLook(head);
   return 0; 
}