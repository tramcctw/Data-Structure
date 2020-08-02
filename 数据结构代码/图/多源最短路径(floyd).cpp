#include <stdio.h>
#define maxsize 6

int str[][maxsize] = {
					{0,7,9,100,100,14},
					{7,0,10,15,100,100},
					{9,10,0,11,100,2},
					{100,15,11,0,6,100},
					{100,100,100,6,0,9},
					{14,100,2,100,9,0}
};

int D[maxsize][maxsize];
int path[maxsize][maxsize];


void Floyd(){
	int i,j,k;
	for(i=0;i<maxsize;i++){
		for(j=0;j<maxsize;j++){
				D[i][j] = str[i][j];
				path[i][j] = -1;
		}
	}
	
	for(k = 0;k < maxsize;k++){
		for(i=0;i<maxsize;i++){
			for(j=0;j<maxsize;j++){
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k]+D[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int main(){
	int i,j;
	Floyd();
	for(i=0;i<maxsize;i++){
		for(j=0;j<maxsize;j++){
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<maxsize;i++){
		for(j=0;j<maxsize;j++){
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}
	return 0;
}