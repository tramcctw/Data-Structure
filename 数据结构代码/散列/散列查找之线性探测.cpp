#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 26

void Insert(char *str[],char *p){
	int i,sum=0;
	i = p[0]-'a';
	if(str[i] == NULL){
		str[i] = p;
	}else{
		while(str[i] != NULL){
			i++;
			sum++; 
			if(i == N){
				i = i%N;
			}
			if(sum == N)
				break;
		}
		str[i] = p;
	}
}

void Create(char* str[]){
	int i;
	char *p;
	for(i=0;i<5;i++){
		p = (char *)malloc(6*sizeof(char));
		scanf("%s",p);
		Insert(str,p);	
	}
}

int Jugement(char *k,char *p){
	int i=0,j=strlen(p),key=1;
	while(j--){
		if(k[i] != p[i]){
			key = 0;
			break;
		}
		i++;
	}
	return key;
}

int Find(char* str[],char *p){
	int i,lenp = strlen(p),lens,sum=0;
	int key = 0;
	i = p[0]-'a';
	if(str[i] == NULL){
		printf("not find!\n");
		return -1;
	}else{
		while(sum < N){
			if(str[i] != NULL)
				lens = strlen(str[i]);
			else{
				break;
			}
			if(lens == lenp && str[i][0] == p[0]){
				key = Jugement(str[i],p);	
			}
			if(key == 1){
				break;
			}
			i++;
			sum++;
		}
		if(key == 0){
			printf("not find!\n");
			return -1;
		}else{
			printf("find!\n");
			return i;
		}
	}
}

int main(){
	int i,pos;
	char* str[N]={NULL},*p;
	p = (char *)malloc(6*sizeof(char));
	Create(str);
	putchar(10);
	for(i=0;i<N;i++){
		if(str[i] != NULL)
		printf("%s\n",str[i]);
	}
	putchar(10);
	i=0;
	while(i<2){ 
		printf("请输入需要查找的数字符串：");
		scanf("%s",p);
		pos = Find(str,p);
		printf("在第%d个位置\n",pos);
		i++;
	} 
	return 0;
}