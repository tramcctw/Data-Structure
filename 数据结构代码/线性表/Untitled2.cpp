//链表 

#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct Node{
	int Data;
	struct Node *next;
}List;

List *list;

List * CreateList(){
	int i;
	List *head,*p,*p0;
	head = (List*)malloc(sizeof(list));
	head->Data = -1;
	head->next = NULL;
	p0 = head;
	for(i = 1;i <= maxsize;i++){
		p = (List*)malloc(sizeof(list));
		p->Data = i;
		p->next = NULL;
		p0->next = p;
		p0 = p;
	}
	return head;
}

List * search(List *head,int i){
	List *p;
	int j = 1;
	if(i < 1){
		printf("位置不合理...\n");
		return NULL;
	}
	p = head->next; 
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(p == NULL){
		printf("没有该元素！！\n");
		return NULL;
	}else{
		return p;
	}
}

void Insert(List *head,int x,int i){
	List *p,*p0;
	if(i == 1){
		p = (List*)malloc(sizeof(list));
		p->Data = x;
		//p->next = NULL;
		p->next = head->next;
		head->next = p;  
		printf("已插入...\n");
	}else{
		p0 = search(head,i-1);
		if(p0 == NULL){
			printf("无法插入,因为链表没有这么长...\n");
			return;
		}else{
			p = (List*)malloc(sizeof(list));
			p->Data = x;
			p->next = p0->next;
			p0->next = p;
			printf("已插入...\n");
		}	
	}		
}

void Delete(List *head,int i){
	List *p,*p0;
	if(i == 1){
		p = head->next;
		head->next = p->next;
		free(p);
		printf("已删除...\n");
	}else{
		p0 = search(head,i-1);
		if(p0 == NULL){
			printf("无法删除,因为链表没有这么长...\n");
			return;
		}else{
			p = p0->next;
			p0->next = p->next;
			free(p);
			printf("已删除...\n");
		}	
	}
}

int Length(List *head){
	int len = 0;
	List *p;
	p = head->next;
	while(p){
		len++;
		p = p->next;
	}
	return len;
}

void print(List *head){
	List *p;
	p = head->next;
	while(p){
		printf("%d ",p->Data);
		p = p->next; 
	}
	printf("\n"); 
}

int main(){
	List *head,*p;
	head = CreateList();
	print(head);
	if(p = search(head,3)){
		printf("%d \n",p->Data);
	}
	printf("%d\n",Length(head));
	Insert(head,100,3);
	print(head);
	printf("%d\n",Length(head));
	Delete(head,3);
	print(head);
	printf("%d\n",Length(head));	
}
