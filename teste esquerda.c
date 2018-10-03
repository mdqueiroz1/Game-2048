#include<stdio.h>
#include<stdlib.h>
#include<conio.c>

int main(){
	
	int lin,col,i,j,cont=0,tabela[4][4],cont_jogadas=0,inicio,r2ou4;

	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
	tabela[1][3]=2;
	tabela[1][2]=2;
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			printf("%d",tabela[j][i]);
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
//jogando para a esquerda <-
	for(lin=0;lin<4;lin++){
		for(i=0;i<4;i++){
			for(j=1;j<4;j++){
				if(i!=j){
					if(tabela[lin][i]==tabela[lin][j]){
						tabela[lin][j]=tabela[lin][i]+tabela[lin][j];
						tabela[lin][i]=0;
					}
				}
			}
		}
		
	
		for(i=0;i<4;i++){
			for(j=0;j<3;j++){
				if(tabela[lin][j]==0){
					tabela[lin][j]=tabela[lin][j+1];
					tabela[lin][j+1]=0;
				}
			}
		}
	}	
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			printf("%d",tabela[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
