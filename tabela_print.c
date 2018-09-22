#include<stdio.h>
#include<stdlib.h>
#include<conio.c>

int main(){
	
	int i,j,cont=0,tabela[4][4];
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			tabela[i][j] = 1;
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(tabela[i][j]!=0){
			cont++;
			}
		}
	}
	
	if(cont<=8){
		system("color 0A");
	}
	if(cont>8){
		system("color 0E");
	}
	if(cont==16){
		system("color 0C");
	}
		printf("\n ---------------------------------------------------------------\n");
	for(i=0;i<4;i++){
		printf("|\t \t|\t \t|\t \t|\t \t|\n|");
		for(j=0;j<4;j++){
			if(tabela[i][j] == 0){
				printf("\t \t|");
			}else{
				printf("\t%d\t|",tabela[i][j]);
			}
		}
		printf("\n|\t \t|\t \t|\t \t|\t \t|");
		printf("\n ---------------------------------------------------------------\n");
	}
	if(cont==16){
		printf("Voce perdeu!\nPontuacao: \n");
	}
	
	return 0;
}
