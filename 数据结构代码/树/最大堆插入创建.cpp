#include <stdio.h>
#include <stdlib.h>

#define MaxData 1000;

typedef struct Heapstrcut{
	int *Data;
	int size;
	int capacity;
}Heap;

Heap heap;

Heap * Create(){
	Heap * head;
	head = (Heap *)malloc(sizeof(heap));
	head->capacity = 20;
	head->Data = (int *)malloc((head->capacity+1)*sizeof(int));
	head->Data[0] = MaxData;
	head->size = 0;
	return head; 
}

void Insert(Heap *head,int x){
	int i;
	if(head->size == head->capacity){
		printf("fulled\n");
		return;
	}else{
		i = ++ head->size;
		for(;head->Data[i/2] < x;i=i/2){
			head->Data[i] = head->Data[i/2];	
		}
		head->Data[i] = x;
	}
}

int deletes(Heap *head){
	int max,temp,parent,child;
	if(head->size == 0){
		printf("empty!\n");
		return -1;
	}
	max = head->Data[1];
	temp = head->Data[head->size--]; 
	for(parent = 1;2*parent <= head->size; parent = child){
		child = 2*parent;
		if(child+1 <= head->size && head->Data[child] < head->Data[child+1]){
			child ++;
		}
		
		if(temp > head->Data[child])
			break;
		else
			head->Data[parent] = head->Data[child];	
	}
	head->Data[parent] = temp;
	return max;
}

int max(Heap *head){
	return head->Data[1];
}

int main(){
	Heap *head;
	head = Create();
	Insert(head,1);
	Insert(head,2);
	Insert(head,3);
	Insert(head,4);
	Insert(head,5);
	Insert(head,6);	
	Insert(head,7);
	Insert(head,8);
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",max(head));
	return 0;
}