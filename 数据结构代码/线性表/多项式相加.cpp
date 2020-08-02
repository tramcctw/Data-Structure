#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct Node{
	int expon;
	int coef;
	struct Node *next; 
}List;

List list;

List * CreateList(){
	List *head,*p,*p0;
	head = (List *)malloc(sizeof(list));
	head->next = NULL;
	p0 = head;
	int expon,coef;
	printf("please Input Data input -1 and -1 over\n");
	scanf("%d %d",&expon,&coef);
	while(expon != -1 || coef != -1){
		p = (List *)malloc(sizeof(list));
		p->expon = expon;
		p->coef = coef;
		p->next = NULL;
		p0->next = p;
		p0 = p;
		scanf("%d %d",&expon,&coef);	
	}
	p = head;
	head = head->next;
	free(p);
	return head; 	
}

int Compare(int x,int y){
	if(abs(x)> abs(y)){
		return 1;
	}else{
		if(abs(x) < abs(y)){
			return -1;
		}else{
			return 0;
		}
	}
}

void Attach(int expon,int coef,List **rear){
	List *p;
	p = (List *)malloc(sizeof(list));
	p->expon = expon;
	p->coef = coef;
	p->next = NULL;
	(*rear)->next = p;
	*rear = p;	
}

List * PolyAdd(List *p1,List *p2){
	int sum;
	List *front,*rear;
	List *head;
	head = (List *)malloc(sizeof(list));
	front = rear = head; 
	while(p1 && p2)
	{
		switch(Compare(p1->coef,p2->coef)){
			case 1:
					Attach(p1->expon,p1->coef,&rear);
					p1 = p1->next;
					break; 
			case -1:
					Attach(p2->expon,p2->coef,&rear);
					p2 = p2->next;
					break;  
			case 0:
					sum = p1->expon + p2->expon;
					if(sum) Attach(sum,p1->coef,&rear);
					p1 = p1->next;
					p2 = p2->next;
					break;		
		}
	}
	while(p1){
		Attach(p1->expon,p1->coef,&rear);
		p1 = p1->next; 
	}
	while(p2){
		Attach(p2->expon,p2->coef,&rear);
		p2 = p2->next; 
	}
	rear->next = NULL;
	front = front->next;
	free(head);
	return front; 
}

void print(List *head){
	List *p;
	p = head;
	while(p){
		printf("%d %d\n",p->expon,p->coef);
		p = p->next;
	}
}

int main(){
	List *p1,*p2,*head;
	p1 = CreateList();
	p2 = CreateList();
	head = PolyAdd(p1,p2);
	print(head);
	return 0; 	
}
 
