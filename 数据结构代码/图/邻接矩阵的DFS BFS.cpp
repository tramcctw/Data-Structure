#include <stdio.h>
#include <stdlib.h>
#define maxsize 6
#define max 15

typedef struct {
	int Data[15];
	int front;
	int rear;
}Que;

Que que;

int visited[6] = {0};

Que * CreateQue(){
	Que *head;
	head = (Que *)malloc(sizeof(que));
	head->front = head->rear = 0;
	return head;
}

void enque(Que *head,int data){
	if((head->rear+1)%max == head->front){
		printf("que full!\n");
		exit(1);
	}else{
		head->rear = (head->rear + 1)%max;
		head->Data[head->rear] = data;
	}
}

int outque(Que *head){
	int k = -1;
	if(head->rear == head->front){
		printf("que empty!\n");
		exit(1);
	}else{
		head->front = (head->front + 1)%max;
		k = head->Data[head->front];	
	}
	return k;
}

int Isempty(Que *head){
	int k = 1;
	if(head->front != head->rear){
		k = 0;
	}
	return k;
}

void BFS(Que *head,int str[][6],int i){
	int j;
	enque(head,i);
	while(!Isempty(head)){
		i = outque(head);
		visited[i] = 1;
		for(j = 0;j < maxsize;j ++){
			if(str[i][j] == 1 && visited[j] == 0){
				enque(head,j);
			}	
		}	
	}
}

int main(){
	int i = 1;
	Que *head = CreateQue();
	int str[][6] = {
					{0,1,1,0,0,1},
					{1,0,1,1,0,0},
					{1,1,0,1,0,1},
					{0,1,1,0,1,0},
					{0,0,0,1,0,1},
					{1,0,1,0,1,0}
					};
	
	BFS(head,str,i-1);
	for(i = 0;i < maxsize;i ++){
		printf("%d ",visited[i]);
	}
	return 0;
}