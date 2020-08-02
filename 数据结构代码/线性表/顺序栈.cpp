#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10

typedef struct {
	int Data[Maxsize];
	int top;
}Stack;
Stack list;

Stack * CreatStack(){
	Stack *head;
	head = (Stack*)malloc(sizeof(list));
	head->top = -1;
	printf("ÒÑ´´½¨!!\n");
	return head; 
}

bool isEmpty(Stack *head){
	if(head->top == -1){
		return true;
	}else{
		return false;
	}
} 

bool isFull(Stack *head){
	if(head->top == Maxsize-1){
		return true;
	}else{
		return false;
	}
}

void Push(Stack *head,int x){
	if(isFull(head)){
		return; 
	}else{
		head->Data[++(head->top)] = x;
		return; 
	}
}

int Pop(Stack *head){
	int x;
	if(isEmpty(head)){
		x = -1;
	}else{
		x = head->Data[(head->top)--];	
	}	
	return x;
}

int main(){
	int i = 1;
	Stack *head;
	head = CreatStack();
	while(i <= 11){
		Push(head,i);
		i++;	
	}
	while(i--){
		printf("%d ",Pop(head));
	} 
	return 0; 
} 
