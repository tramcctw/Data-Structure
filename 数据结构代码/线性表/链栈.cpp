//Á´Õ»

#include <stdio.h>
#include <stdlib.h>

typedef struct SNode{
	int Data;
	struct SNode *next;
}Stack;

Stack list;

Stack *CreateStack(){
	Stack *head;
	head = (Stack*)malloc(sizeof(list));
	head->next = NULL;
	head->Data = -1;
	return head; 
}

bool IsEmpty(Stack *head){
	if(head->next == NULL){
		printf("is empty!\n");
		return true;
	}else{
		printf("is not empty!\n");
		return false;
	}
}

void Push(Stack*head,int x){
	Stack *p;
	p = (Stack*)malloc(sizeof(list));
	p->Data = x;
	p->next = head->next;
	head->next = p;
	printf("ok!!\n"); 
}

int Pop(Stack *head){
	int x = -1;
	Stack *p;
	if(!IsEmpty(head)){
		p = head->next;
		head->next = p->next;
		x = p->Data;
		free(p);
	}
	return x;
}


int main(){
	Stack *head;
	head = CreateStack();
	Push(head,1);
	Push(head,2);
	Push(head,3);
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	return 0;	
} 
 
