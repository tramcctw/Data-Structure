#include <stdio.h>
#include <stdlib.h>
#define maxsize 6
#define max 15
typedef struct{
	int Data[max];
	int rear;
	int front;
}Que;

Que que;

int str[][maxsize] = {
					{0,1,1,0,0,1},
					{1,0,1,1,0,0},
					{1,1,0,1,0,1},
					{0,1,1,0,1,0},
					{0,0,0,1,0,1},
					{1,0,1,0,1,0}
};

int dist[maxsize] = {-1,-1,-1,-1,-1,-1};
int path[maxsize] = {0};

Que *CreateQue(){
	Que *pt;
	pt = (Que *)malloc(sizeof(que));
	pt->front = pt->rear = 0;
	return pt;
}

void enque(Que *pt,int x){
	if((pt->rear+1)%max == pt->front){
		printf("full\n");
		exit(1);
	}
	pt->rear = (pt->rear + 1)%max;
	pt->Data[pt->rear] = x;
}

int outque(Que *head){
	int x;
	if(head->rear == head->front){
		printf("empty!\n");
		x = -1;
	}else{
		head->front = (head->front + 1)%max;
		x = head->Data[head->front];
	}
	return x;
}

int Isempty(Que *head){
	int k = 0;
	if(head->front == head->rear){
		k = 1;
	}
	return k;
}

void Unweighted(Que *head,int x){
	int v,i;
	dist[x] = 0;
	enque(head,x);
	while(!Isempty(head)){
		v = outque(head);
		for(i = 0;i < maxsize;i ++){
			if(dist[i] == -1 && str[v][i] == 1){
				dist[i] = dist[v] + 1;
				path[i] = v+1;
				enque(head,i);
			}
		}	
	}
}

int main(){
	int x;
	Que *pt = CreateQue();
	printf("please input node:\n");
	scanf("%d",&x);
	Unweighted(pt,x-1);
	for(x = 0;x < maxsize;x++){
		printf("%d ",dist[x]);
	}
	printf("\n");
	for(x = 0; x < maxsize;x ++){
		printf("%d ",path[x]);
	}
	return 0;
}