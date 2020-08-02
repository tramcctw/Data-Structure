#include <stdlib.h>
#include <stdio.h>
#define N 6
#define maxsize 15

typedef struct Que{
	int Data[maxsize];
	int front;
	int rear;
}Que;

typedef struct Node{
	int data;
	struct Node *next;
}List;

Que que;
List list;
List *head[N+1];
int visited[N+1] = {0};

Que * CreateQue(){
	Que *head;
	head = (Que *)malloc(sizeof(que));
	head->front = head->rear = 0;
	return head;
}

void enque(Que *head,int data){
	if((head->rear+1)%maxsize == head->front){
		printf("que full!\n");
		exit(1);
	}else{
		head->rear = (head->rear + 1)%maxsize;
		head->Data[head->rear] = data;
	}
}

int outque(Que *head){
	int k = -1;
	if(head->rear == head->front){
		printf("que empty!\n");
		exit(1);
	}else{
		head->front = (head->front + 1)%maxsize;
		k = head->Data[head->front];	
	}
	return k;
}

int Isempty(Que *head){
	int k = 0;
	if(head->front == head->rear){
		k = 1;
	}
	return k;
}

void Create(int i){
	int k;
	List *p,*p0,*h;
	h = (List *)malloc(sizeof(list));
	h->data = -1;
	h->next = NULL;
	p0 = h;
	scanf("%d",&k);
	while(k != -1){
		p = (List *)malloc(sizeof(list));
		p->data = k;
		p->next = NULL;
		p0->next = p;
		p0 = p;
		scanf("%d",&k);	
	}
	head[i] = h->next;
	free(h);
}

int Find(Que *head,int x){
	int k = 0,i;
	i = (head->front + 1)%maxsize;
	while(i != head->rear){
		if(head->Data[i] == x){
			k = 1;
			break;
		}
		i = (i+1)%maxsize;
	}
	if(head->Data[i] == x){
		k = 1;
	}
	return k;
}

void DFS(int i){
	List * p;
	p = head[i];
	printf("%d ",i);
	visited[i] = 1;
	while(p != NULL){
		if(visited[p->data] == 0){
			DFS(p->data);	
		}
		p = p->next;
	}	
}

void BFS(Que *pt,int i){
	List *p;
	int j;
	enque(pt,i);
	while(!Isempty(pt)){
		j = outque(pt);
		printf("%d ",j);
		visited[j] = 1;
		p = head[j];
		while(p != NULL){
			if(visited[p->data] == 0 && !Find(pt,p->data)){
				enque(pt,p->data);
			}
			p = p->next;
		}
	}
}

int main(){
	int i;
	Que *pt = CreateQue();
	for(i=1;i<N+1;i++){
		Create(i);
	}
	i = 5;
	//DFS(i);
	BFS(pt,i);
	return 0;
}