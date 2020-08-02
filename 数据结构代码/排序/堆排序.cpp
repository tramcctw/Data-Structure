#include <stdio.h>
#include <stdlib.h>
#define N 7

typedef struct {
	int Data[N];
	int size;
}Heap;

Heap *heap;

Heap * Create(){
	Heap *pt;
	pt = (Heap *)malloc(sizeof(heap));
	pt->size = -1;
	return pt;
}

//建立的是最大堆

void CreateHeap(Heap *pt,int x){
	int i;
	if(pt->size == N-1){
		printf("full\n");
		return;
	}else{
		pt->size++;
		for(i=pt->size;i/2 >= 0 && i != 0 && x > pt->Data[i/2];){
			pt->Data[i] = pt->Data[i/2];
			i = i/2;
		}
		pt->Data[i] = x;
	}
}

void Adjust(Heap *pt){
	
	int i = 0,child,x;	
	if(pt->size == 0){
	return;
	}
	x = pt->Data[0];
	while(i <= pt->size){
	
			if(i*2 <= pt->size){
				if(i == 0)
				child = 1;
				else
				child = i*2;
				
				if(child+1 <= pt->size && pt->Data[child+1] > pt->Data[child])
					child++;
				if(pt->Data[child] > x){
					pt->Data[i] = pt->Data[child];
					i = child;
				}else{
					break;	
			}			
		}else
			break;	 			
	}
	pt->Data[i] = x;	
}

void Heap_Sort(Heap *pt){
	int i,item;
	i = pt->size;
	for(;i>0;i--){
		item = pt->Data[i];
		pt->Data[i] = pt->Data[0];
		pt->Data[0] = item;
		pt->size--;
		Adjust(pt);
	}
}

int main(){
	Heap *pt;
	int i,k;
	pt = Create();
	printf("input heap please\n");
	for(i=0;i<N;i++){
		scanf("%d",&k);
		CreateHeap(pt,k);
	}
	Heap_Sort(pt);
	for(i=0;i<N;i++){
		printf("%d ",pt->Data[i]);
	}
	return 0;
}