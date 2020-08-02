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
	//����һ��21������
	head->Data[0] = MaxData;
	//��һ�������ܵ�����ΪͶ��
	head->size = 0;
	return head; 
}

void justify(Heap *head,int i){
	int temp,parent,child;
	temp = head->Data[i];
	 
	for(parent = i;2*parent <= head->size; parent = child){
		child = 2*parent;
		if(child+1 <= head->size && head->Data[child] < head->Data[child+1]){
			child ++;
		}
		//�ҵ��ϴ��һ���ӽڵ�
		if(temp > head->Data[child])
			break;
		else
			head->Data[parent] = head->Data[child];	
	}
	head->Data[parent] = temp;
}

void createHeap(Heap *head){
	int i;
	for(i=1;i<15;i++){
		head->Data[i] = i;
		head->size ++;	
	}
	for(i = 1; i < 15;i++){
		if(i*2 <= head->size && i*2+1 >= head->size)
			break;
			//�ҵ����һ���������Ľ��
	}
	while(i){
		justify(head,i);
		i--;
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

int main(){
	Heap *head;
	head = Create();
	createHeap(head);
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));
	printf("%d\n",deletes(head));  
	return 0;
}
