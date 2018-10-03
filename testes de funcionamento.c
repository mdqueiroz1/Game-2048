#include<stdio.h>
#include<stdlib.h>
#include<conio.c>

int tabela[4][4];

int main(){
	
	int lin,col,cont=0,cont_jogadas=0,inicio=0,r2ou4;
	
	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
	
	do{	
		srand(time(NULL));//se deixar o time(null) fora chega no resultado mais rápido.
	
		do{
		lin=rand()%4;
		col=rand()%4;
		}while(tabela[lin][col]!=0);
		
		do{
			r2ou4=rand()%4;
		}while(r2ou4%2!=0);
			
			
		if(r2ou4 == 0){
			tabela[lin][col]=2;
		}else{
			tabela[lin][col]=r2ou4;
		}
		cont_jogadas++;
		inicio++;
	}while(inicio<2);
	
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
		for(lin=0;lin<4;lin++){
			printf("|\t \t|\t \t|\t \t|\t \t|\n|");
			for(col=0;col<4;col++){
				if(tabela[lin][col] == 0){
					printf("\t \t|");
				}else{
					printf("\t%d\t|",tabela[lin][col]);
				}
			}
			printf("\n|\t \t|\t \t|\t \t|\t \t|");
			printf("\n ---------------------------------------------------------------\n");
		
			if(cont==16){
				printf("Voce perdeu!\nPontuacao: \n");//colocar pontuação
			}
	
		}

	return 0;
}
