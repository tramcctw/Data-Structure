#include <stdio.h>
#include <stdlib.h>

#define maxsize 10

typedef struct Node{
	int Data[maxsize];
	int last;
}List;

List list;

List *CreateList(){
	List *head;
	head = (List *)malloc(sizeof(list));
	printf("���С��������%d��int����:\n",maxsize);
	for(head->last = 0; head->last < maxsize; head->last ++){
		scanf("%d",&head->Data[head->last]);
	}
	head->last --;
	return head;
} 


int erfen(List *head,int x){
	  int i = 0,j = head->last;
	  int mid,k = -1;
	  
	  while(i <= j){
	  	mid = (i + j)/2;
	  	if(head->Data[mid] > x){
			j = mid - 1; 
		}else{
			if(head->Data[mid] < x){
				i = mid + 1;
			}else{
				return mid;
			}
		} 
	  }
	  
	  return k;
} 



int main(){
	int x;
	List *head;
	head = CreateList();
	x = erfen(head,100);
	if(x == -1){
		printf("û�и�Ԫ�أ�\n");
	}else{
		printf("�и�Ԫ�أ�\n");
	}
	return 0;
}
