#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10

typedef struct QNOde{
	int Data[Maxsize];
	int rear;
	int front;
}Que;

Que que;

Que *CreateQue(){
	Que *head;
	head = (Que *)malloc(sizeof(que));
	head->front = 0;
	head->rear = 0;
	return head; 
}

bool isfull(Que *head){
	if((head->rear+1)%Maxsize == head->front){
		return true;
	}else{
		return false;
	}
}

bool isempty(Que *head){
	if(head->front == head->rear){
		return true;
	}else{
		return false;
	}
}

void Insert(Que *head,int x){
	if(!isfull(head)){
		head->Data[++(head->rear)] = x;
		printf("�Ѳ��룡\n");
	}else{
		printf("\n������������\n");
	}
}

int Delete(Que *head){
	int x = -1;
	if(!isempty(head)){
		x = head->Data[++(head->front)];
	}else{
		printf("\n�����ѿգ���\n");	
	}
	return x; 
}

int main(){
	int i = 1;
	Que *head;
	head = CreateQue();
	for(;i<12;i++){
		Insert(head,i);
	}
	
	for(i=1;i<12;i++){
		printf("%d ",Delete(head));
	}
	return 0; 
}
