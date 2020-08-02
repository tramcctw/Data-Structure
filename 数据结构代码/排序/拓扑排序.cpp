#include <stdio.h>
#include <stdlib.h>
#define Maxsize 16

int str[Maxsize][Maxsize] = {0};

typedef struct {
	int Data[Maxsize];
	int front;
	int rear;
}Que;

Que qu;

Que *Create(){
	Que *pt;
	pt = (Que *)malloc(sizeof(qu));
	pt->front = pt->rear = 0;
	return pt;
}

void Push(Que *pt,int x){
	if((pt->rear+1)%Maxsize == pt->front){
		printf("full!\n");
		exit(0);
	}else
	pt->rear = (pt->rear+1)%Maxsize;
	pt->Data[pt->rear] = x;
}

int Pop(Que *pt){
	int x = -1;
	if(pt->front == pt->rear){
		printf("empty!\n");
	}else{
	pt->front = (pt->front+1)%Maxsize;
	x = pt->Data[pt->front]; 	
	}
	return x;
}

void TopSort(Que *pt){
	int i,j,k,sum = 0,h;
	for(j=1;j<Maxsize;j++){
		k = 0;
		for(i=1;i<Maxsize;i++){
			if(str[i][j] == 1){
				k = 1;
			}
		}
		if(k == 0){
		Push(pt,j);	
		}
	}
	while((k = Pop(pt)) != -1){
		sum++;
		printf("%d ",k);
		for(i=1;i<Maxsize;i++){
			if(str[k][i] == 1){
			str[k][i] = 0;
			h = 0;
				for(j=1;j<Maxsize;j++){
					if(str[j][i] == 1){
						h = 1;
					}	
				}
				if(h == 0){
					Push(pt,i);		
				}	
			}
		}
	}
	if(sum != Maxsize-1){
		printf("The Gragh have loose!");
	}
}

int main(){
	Que *pt;
	int i,j,k,D[Maxsize][7];
	pt = Create();
	for(i=1;i<Maxsize;i++){
		j = 1;
		k = 0;
		while(k != -1){
			scanf("%d",&k);
			D[i][j] = k;
			j++;
		}	
	}
	
	for(i=1;i<Maxsize;i++){
		j = 1;
		while(D[i][j] != -1){
			str[i][D[i][j]] = 1;
			j++;
		}
	}
	
	TopSort(pt);
	return 0;
}
