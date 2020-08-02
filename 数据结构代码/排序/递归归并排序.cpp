#include <stdio.h>
#include <stdlib.h>
#define N 7

void Merge(int str[],int A[],int L,int R,int RightEnd){
	int sum,LeftEnd,i;
	i = L;
	LeftEnd = R-1;
	sum = RightEnd-L+1;
	while(L <= LeftEnd && R <= RightEnd){
		if(str[L] < str[R])
			A[i++] = str[L++];
		else
			A[i++] = str[R++];
	}
	while(L <= LeftEnd){
		A[i++] = str[L++];
	}
	while(R <= RightEnd){
		A[i++] = str[R++];
	}
	for(i=0;i<sum;i++,RightEnd--){
		str[RightEnd] = A[RightEnd];
	}
}

void Sort_Merge(int str[],int A[],int L,int RightEnd){
	int Center;
	if(L < RightEnd){
		Center = (L+RightEnd)/2;
		Sort_Merge(str,A,L,Center);
		Sort_Merge(str,A,Center+1,RightEnd);
		Merge(str,A,L,Center+1,RightEnd);
	}
}

void Merge_Sort(int str[]){
	int *A;
	A = (int *)malloc(N*sizeof(int));
	if(A != NULL){
		Sort_Merge(str,A,0,N-1);
		free(A); 
	}else{
		printf("¿Õ¼äÒÑÂú£¡");
		exit(1);
	}
}

int main(){
	int i;
	int str[N] = {7,6,1,4,2,3,5};
	Merge_Sort(str);
	for(i=0;i<N;i++){
		printf("%d ",str[i]);
	}
	return 0;
}