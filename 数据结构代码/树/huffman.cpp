#include <stdio.h>
#include <stdlib.h>
#define Maxsize 8
#define maxsize 20
int N = 8;

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree;

Tree tree;

Tree *Data[9];

typedef struct{
	Tree *Data[maxsize];
	int front;
	int rear;
}Que;

Que que;

void justify(int i){
	int parent,child,temp;
	temp = Data[i]->data;
	for(parent = i;2*parent <= N;parent = child){
		child = 2*parent;
		if(child+1 <= N && Data[child+1]->data < Data[child]->data){
			child ++;
		}
		if(Data[parent]->data < Data[child]->data){
			break;
		}else{
			Data[parent]->data = Data[child]->data;
		}
	}
	Data[parent]->data = temp;
}


void Create(){
	int i,x;
	Tree *p;
	p = (Tree *)malloc(sizeof(tree));
	p->data = -1;
	p->left = p->right = NULL;
	Data[0] = p; 
	for(i=1;i <= N;i ++){
		scanf("%d",&x);
		p = (Tree *)malloc(sizeof(tree));
		p->data = x;
		p->left = p->right = NULL;
		Data[i] = p;
	}
	for(i = 1;i <= N;i ++){
		if(i*2 <= N && i*2+1 >=N){
			break;
		}
	}
	while(i){
		justify(i);
		i--;
	}
}

Tree * deletes(){
	Tree *p,*temp;
	int parent,child;
	p = Data[1];
	temp = Data[N--];
	for(parent = 1;2*parent <= N;parent = child){
		child = parent*2;
		if(child+1 <= N && Data[child+1]->data < Data[child]->data){
			child ++;
		}
		if(temp->data < Data[child]->data){
			break;
		}else{
			Data[parent] = Data[child];
		}
	}
	Data[parent] = temp;
	return p;
}

void Insert(Tree *head){
	int i = ++N;
	for(;Data[i/2]->data > head->data;i=i/2){
		Data[i] = Data[i/2];
	}
	Data[i] = head;
}

Tree * huffman(){
	Tree *head,*p1,*p2;
	int i;
	for(i=1;i<Maxsize;i++){
		p1 = deletes();
		p2 = deletes();
		head = (Tree *)malloc(sizeof(tree));
		head->data = p1->data + p2->data;
		head->left = p1;
		head->right = p2;
		Insert(head); 
	}
	return Data[1];
}


Que * CreateQue(){
	Que *pt;
	pt = (Que*)malloc(sizeof(que));
	pt->front = pt->rear = 0;
	return pt;
}

int QueIsempty(Que *pt){
	if(pt->rear == pt->front){
		return 1;
	}else{
		return 0;
	}
}

void InQue(Que *pt,Tree *head){
	if((pt->rear + 1)%maxsize == pt->front){
		printf("que is full!\n");
		exit(1);	
	}else{
		pt->rear = (pt->rear + 1)%maxsize;
		pt->Data[pt->rear] = head;
	}
}

Tree* OutQue(Que *pt){
	if(pt->front == pt->rear){
		printf("que is full");
		exit(1);
	}else{
		pt->front = (pt->front + 1)%maxsize;
		return pt->Data[pt->front];
	}
}

void Cccc(Tree *head,Que *pt){
	Tree * p;
	if(head == NULL){
		printf("tree is empty!!\n");
		return;
	}else{
		InQue(pt,head);
		while(!QueIsempty(pt)){
			p = OutQue(pt);
			printf("%d ",p->data);
			if(p->left)
				InQue(pt,p->left);
			if(p->right)
			InQue(pt,p->right);
		}
	}	
}


void main()
{
	int i=0;
	Que *pt;
	pt = CreateQue();
	Tree *head = NULL;
	Create();
	head = huffman();
	Cccc(head,pt);  
}