#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int Data;
	struct Node *next;
}List;

List list;

typedef struct QNode{
	struct Node *rear;
	struct Node *front;
}Que;

Que que;

Que * CreateQue(){
	Que *head;
	head = (Que *)malloc(sizeof(que));
	head->rear = head->front = NULL;
	return head;					
}

bool isempty(Que *head){
	if(head->front == NULL && head->rear == NULL){
		return true;
	}else{
		return false;
	}
} 

void Insert(Que *head,int x){
	List *p;
	p = (List *)malloc(sizeof(list));
	p->Data = x;
	p->next = NULL;
	if(isempty(head)){
		head->rear = head->front = p;	
	}else{
		head->rear->next = p;
		head->rear = p;
	}
}

int Delete(Que *head){
	int x = -1; 
	List *p;
	if(isempty(head)){
		printf("\nÁ´¶ÓÎª¿Õ£¡\n");
		return -1;	
	}
	if(head->front == head->rear){
		p = head->front;
		head->front = head->rear = NULL;
		x = p->Data;
		free(p);
		return x;	
	}else{
		p = head->front;
		head->front = p->next;
		x = p->Data;
		free(p);
		return x; 
	} 
}

int main(){
	int i = 1;
	Que *head;
	head = CreateQue();
	for(;i<10;i++){
		Insert(head,i);
	}
	for(i = 1;i < 12;i++){
		printf("%d ",Delete(head));
	}
	return 0; 
} 
