//一个数组两个栈 

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 15

typedef struct DStack{
	int Data[Maxsize];
	int top1;
	int top2;
}Stack;

Stack list;

Stack* StackCreate(){
	Stack *head;
	head = (Stack*)malloc(sizeof(list));
	head->top1 = -1;
	head->top2 = Maxsize;
	return head;
}

bool isfull(Stack *head){
	if(head->top2 - head->top1 == 1){
		printf("is full!\n");
		return true;
	}else{
		printf("is not full!\n");
		return false;
	}
}

bool isempty(Stack *head,int tag){
	if(head->top1 == -1 && tag == 0){
		printf("letf satck is empty!\n");
		return true;
	}else{
		printf("is not empty!\n");
		return false;
	}
	
	if(head->top2 == Maxsize && tag == 1){
		printf("right satck is empty!\n");
		return true;
	}else{
		printf("is not empty!\n");
		return false;
	}
}

void Push(Stack *head,int x,int tag){
	if(isfull(head)){
		printf("stack is full.cannot push!\n");
		return;
	}else{
		if(tag == 0){
			head->Data[++(head->top1)] = x;	
		}else{
			head->Data[--(head->top2)] = x;
		}
		printf("ok!!\n");
		return;	
	} 
}

int Pop(Stack *head,int tag){
	int x = -1;
	if(!isempty(head,tag)){
		if(tag == 0){
			x = head->Data[(head->top1)--];
		}else{
			x = head->Data[(head->top2)++]; 
		}
	}else{
		printf("you need push stack is empty can not pop!\n");
	}
	return x;
}

int main(){
	int x;
	Stack *head;
	head = StackCreate();
	Push(head,100,1);
	Push(head,10,0);
	printf("%d\n",Pop(head,1));
	printf("%d\n",Pop(head,0));
	return 0;
} 
