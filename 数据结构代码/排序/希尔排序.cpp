#include <stdio.h>
#define maxsize 15


//每次隔5个，隔3个 最后隔一个来消除逆序对，比如隔3消除每一个隔3的逆序对 
void Shell_sort(int *str){
	int D,i,j,temp;
	for(D=maxsize/2;D>0;D=D/2){
		for(i=D;i<maxsize;i++){
			temp = str[i];
			for(j=i;str[j-D]>temp && j-D >=0;j=j-D){
					str[j] = str[j-D];
			}
			str[j] = temp;
		}
	}
}


int main(){
	int i;
	int str[maxsize] = {1,2,3,4,5,6,7,8,4,8,2,1,2,3,4};
	Shell_sort(str);
	for(i=0;i<maxsize;i++){
		printf("%d ",str[i]);
	}
	return 0;
}