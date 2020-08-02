//一定要注意每次在想要移动指针时，一定要注意它
//之前所指向的对象，可能会影响之后的operation 。。
//感觉算法虽然实现了但不太好，有点浪费存储空间0.0 
//改进可以把原数据改为链表吧。 
#include<stdio.h>
#include<stdlib.h>
#define N 15
#define M 4
#define K 12
typedef struct node{
	int data;
	int flower;
	struct node *next;
}List;

List list;
List *sort[N];
List *color[M];	
	
void Create_Data(List *str){
	int i;
	for(i=0;i<K;i++){
		scanf("%d%d",&str[i].data,&str[i].flower);
		str[i].next = NULL;
	}
}

void CwSort(List p){
		List *q;
		q = (List *)malloc(sizeof(list));
		q->data = p.data;
		q->flower = p.flower;
		q->next = NULL;
		if(sort[p.data] == NULL){
			sort[p.data] = q;
		}else{
			q->next = sort[p.data];
			sort[p.data] = q;		
		}
}

void Cw_Sort(List *str){
	int i;
	for(i=0;i<K;i++){
		CwSort(str[i]);			
	}
}

void ZwSort(List *p){
	List *k;
	p->next = NULL;
	k = color[p->flower];
	if(k == NULL){
		color[p->flower] = p;
	}else{
		while(k->next != NULL){
			k = k->next;
			//printf("ok");
		}
		k->next = p;
	}	
}

void Zw_Sort(){
	int i;
	List *p;
	for(i=0;i<N;i++){
		p = sort[i];
		while(p != NULL){
			//printf("%d ",i);
			//exit(0);
			ZwSort(p);
			p = p->next;
			//printf("ok");
		}
	}
}
	
void print(){
	List *k;
	int i;
	for(i=0;i<M;i++){
		k = color[i];
		while(k != NULL){
			printf("%d %d ",k->data,k->flower);
			k = k->next;
		}
		printf("\n");	
	}
}
	
int main(){
	int i;
	List *p;
	List str[K];
	Create_Data(str);
	printf("\n");
	Cw_Sort(str);
	/*for(i=0;i<N;i++){
		p = sort[i];
		while(p != NULL){
			printf("%d %d\n",p->data,p->flower);
			p = p->next;
		}
	}*/
	Zw_Sort();
	//printf("ok");
	print();
	return 0;	
}