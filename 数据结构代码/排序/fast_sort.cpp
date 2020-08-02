#include <stdio.h>
#include <stdlib.h>
#define  N 7
#define  Cutoff 3

void Swap(int *x,int *y){
	int item;
	item = *x;
	*x = *y;
	*y = item;
}

int Median(int str[],int Left,int Right){
	int Center;
	Center = (Left+Right)/2;
	if(str[Left] > str[Center])
		Swap(&str[Left],&str[Center]);
	if(str[Left] > str[Right])
		Swap(&str[Left],&str[Right]);
	if(str[Center] > str[Right])
		Swap(&str[Center],&str[Right]);
	Swap(&str[Center],&str[Right-1]);
	return str[Right-1];		
}

void Simple_sort(int *A,int k){
	int i,j,item,p;
	for(i=0;i<k-1;i++){
			item = A[i];
			p = i;
		for(j=i+1;j<k;j++){
			if(item > A[j]){
				p = j;
			   	item = A[j];
			}	
		}
		if(p != i){
			item = A[i];
			A[i] = A[p];
			A[p] = item;
		}
 	}
}

void Quicksort(int str[],int Left,int Right){
	int i,j,Pivot,sum;
	sum = Right-Left+1;
	if(sum < Cutoff){
		Simple_sort(str+Left,sum);			
	}else{
	Pivot = Median(str,Left,Right);  //注意这里都是下标。
	i = Left;
	j = Right-1;
	for(;;){
		while(str[++i] < Pivot){}
		while(str[--j] > Pivot){}
		
		if(i < j){
			Swap(&str[i],&str[j]);
		}else{
			break;
		}
	}
	Swap(&str[i],&str[Right-1]);
	Quicksort(str,Left,i-1);
	Quicksort(str,i+1,Right);
	}
}

void Quick_Sort(int str[]){
	Quicksort(str,0,N-1);
}

int main(){
	int i,str[N] = {1,4,7,2,11,1,1};
	Quick_Sort(str);
	for(i=0;i<N;i++){
		printf("%d ",str[i]);
	}	
	return 0;
} 