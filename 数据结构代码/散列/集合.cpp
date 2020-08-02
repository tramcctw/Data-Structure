#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 10

typedef struct {
	int data;
	int parent;
}List;

void Create(List *head){
	int i;
	for(i = 0;i < maxsize;i ++){
		scanf("%d %d",&head[i].data,&head[i].parent);
	}
}


int Find(List *head,int x){
	int i;
	for(i = 0;i < maxsize && head[i].data != x;i++);
	if(i >= maxsize){
		return -1;
	}else{
		for(;head[i].parent >= 0;i = head[i].parent);
		return i;
	}
}

void Union(List *head,int x,int y){
	int i,j;
	i = Find(head,x);
	j = Find(head,y);
	if(i == -1 || j == -1){
		printf("没有该元素!\n");
		return;
	}
	if(head[i].data == head[j].data){
		printf("同一个集合！\n");
	}else{
		if(abs(head[i].parent) > abs(head[j].parent)){
			head[i].parent += head[j].parent; 
			head[j].parent = i;
		}else{
			head[i].parent += head[j].parent;
			head[i].parent = j;
		}
	}
}

void print(List *head){
	int i;
	printf("\n");
	for(i = 0;i < maxsize;i ++){
		printf("%d %d\n",head[i].data,head[i].parent);
	}
} 

int main()
{
	List head[maxsize];
	Create(head);
	Union(head,2,8);
	print(head);	
	return 0; 
}