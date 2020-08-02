#include<stdio.h>
#define N 11
#define M 13

void BucketSort(int str[],int k){
	str[k]++;
}

void Bucket_sort(int A[]){
	int i,j,str[N] = {0};
	for(i=0;i<M;i++){
		BucketSort(str,A[i]);
	}
	for(i=0;i<N;i++){
		if(str[i] != 0){
			for(j=0;j<str[i];j++){
				printf("%d ",i);
			}
		}
	}
}

int main(){
	int A[M] = {7,1,0,2,3,6,5,4,8,9,4,1,2};
	Bucket_sort(A);
	return 0;
}//基本可以达到O(N)的时间复杂度
//但是当N>>M时并不划算，浪费大量空间！