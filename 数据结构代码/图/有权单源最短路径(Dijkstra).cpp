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

int dist[maxsize];
int path[maxsize] = {0};
int island[maxsize] = {-1,-1,-1,-1,-1,-1};

int findmin(){
	int i,k = -1;
	int min = 100;
	for(i = 0;i < maxsize;i ++){
		if(dist[i] < min && island[i] == -1){
			min = dist[i];
			k = i;
		}
	}
	return k;
}

void Dijkstra(int x){
	int i,v;
	for(i=0;i<maxsize;i++){
			dist[i] = str[x][i];
	}
	island[x] = 1;
	while(true){
		v = findmin();
		if(v == -1){
			break;
		}
		island[v] = 1;
		for(i=0;i<maxsize;i++){
			if(island[i] == -1 && dist[v] + str[v][i] < dist[i]){
				dist[i] = dist[v] + str[v][i];
				path[i] = v+1;
			}	
		}
	}
}

int main(){
	int x;
	printf("please input node:\n");
	scanf("%d",&x);
	Dijkstra(x-1);
	for(x=0;x<maxsize;x++){
		printf("%d ",dist[x]);
	}
	printf("\n");
	for(x=0;x<maxsize;x++){
		printf("%d ",path[x]);
	}
	return 0;
}