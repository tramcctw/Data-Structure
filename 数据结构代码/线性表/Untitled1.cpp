//���Ա��˳��洢 
 
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

typedef struct node{
	int data[maxsize];
	int last;
}List;

List list;

List * MakeEmpty(){
	List * head;
	head = (List *)malloc(sizeof(list));
	head->last = -1;
	return head;
}

void Insert(List *head,int n,int x){
	int i;
	
	if(head->last == maxsize-1){
		printf("��������\n");
		return; 
	}
	if(n<1 || n > maxsize){
		printf("����λ�ò�����\n");
		return;
	}
	for(i = head->last;i >= n-1;i--){
		head->data[i+1] = head->data[i];
	}
	head->data[n-1] = x;
	head->last++;
	return;
} 

void Delete(List *head,int n){
	int i;
	
	if(n < 1 || n > maxsize){
		printf("ɾ��λ�ò�������\n");
		return; 
	}
	
	for(i = n-1;i < head->last;i++){
		head->data[i] = head->data[i+1];
	}
	head->last--;
	printf("��ɾ��!\n"); 
	return;
}

void search(List *head,int x){
	int i;
	if(head->last == -1){
		printf("��Ϊ�գ���\n");
		return; 
	}
	for(i = 0;i <= head->last;i++){
		if(head->data[i] == x){
			printf("�и�Ԫ�أ���\n");
			return;
		}
	}
	printf("û�и�Ԫ�أ���\n");
	return; 
}

void print(List *head){
	int i;
	if(head->last == -1){
		printf("��գ���\n");
		return;
	}
	for(i = 0;i < head->last;i ++){
		printf("%d ",head->data[i]);
	}
	printf("\n");
}

//���� ɾ�� ���� 

int main(){
	int i=1;	
	List *head;
	head = MakeEmpty();
	while(i <= 20){
		Insert(head,i,i);
		i++;	
	}
	print(head);
	search(head,3);
	Delete(head,3);
	print(head);
	search(head,3);
} 
