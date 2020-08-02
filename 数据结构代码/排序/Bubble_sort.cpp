#include <stdio.h>
#define maxsize 10


void swap(int *str,int i,int j){
	int t;
	t = str[i];
	str[i] = str[j];
	str[j] = t;
}

void Bubble_sort(int *str){
	int flag,i,j;
	for(i=maxsize-1;i > 0;i--){
		flag = 0;
		for(j=0;j < i;j++){
			if(str[j] > str[j+1]){
				swap(str,j,j+1);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}


int main(){
	int i;
	int str[maxsize] = {2,3,4,5,7,8,9,1,6,10};
	Bubble_sort(str);
	for(i=0;i<maxsize;i++)
		printf("%d ",str[i]);
	return 0; 
}