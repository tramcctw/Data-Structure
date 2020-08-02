#include <stdio.h>
#define maxsize 10

void Insertaion_sort(int *str){
	int i,j,temp;
	for(i = 1;i < maxsize;i++){
		temp = str[i];
		for(j = i;j > 0; j--){
			if(temp < str[j-1]){
				str[j] = str[j-1];	
			}else{
				break;
			}
		}
		str[j] = temp;
	}
}


int main(){
	int i;
	int str[maxsize] = {2,3,4,5,7,8,9,1,6,10};
	Insertaion_sort(str);
	for(i=0;i<maxsize;i++)
		printf("%d ",str[i]);
	return 0; 
}