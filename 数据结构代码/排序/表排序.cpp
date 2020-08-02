#include <stdio.h>
#define N 7

//不需要移动原始数据只移动指针用于移动比较耗时的情况

void Swap(int *x,int *y){
	int item;
	item = *x;
	*x = *y;
	*y = item;
}

void List_Sort(int str[],int A[]){
	int i,j;
	for(i=1;i<N;i++){
		for(j=i;j > 0 && str[A[j]] < str[A[j-1]];j--){
			Swap(&A[j],&A[j-1]);
		}
	}
}

int main(){
	int i;
	int str[N] = {7,4,6,5,1,2,3};
	int A[N] = {0,1,2,3,4,5,6};
	List_Sort(str,A);
	for(i=0;i<N;i++){
		printf("%d ",str[A[i]]);
	}
	return 0;
} 