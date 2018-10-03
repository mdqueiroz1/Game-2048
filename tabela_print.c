#include<stdio.h>
#include<stdlib.h>
#include<conio.c>
#include<conio.h>

void Printar(int tab[4][4]){
			
	int lin, col;
	
			printf("\n ---------------------------------------------------------------\n");
	for(lin=0;lin<4;lin++){
		printf("|\t \t|\t \t|\t \t|\t \t|\n|");
		for(col=0;col<4;col++){
			if(tab[lin][col] == 0){
				printf("\t \t|");
			}else{
				printf("\t%d\t|",tab[lin][col]);
			}
		}
		printf("\n|\t \t|\t \t|\t \t|\t \t|");
		printf("\n ---------------------------------------------------------------\n");
	}
}

int main(){
	
	int lin,col,i,j,cont=0,tabela[4][4],cont_jogadas=0,inicio,r2ou4;
	
	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
	
	for(inicio=0;inicio<2;inicio++){	
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
	}
	//seleção de cor para o jogo.
	if(cont<=8){
		system("color 0A");
	}
	if(cont>8){
		system("color 0E");
	}
	if(cont==16){
		system("color 0C");
	}
	
	
	
	//impressão da tabela do jogo
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
	}

	Printar(tabela);
	if(cont==16){
		printf("Voce perdeu!\nPontuacao: \n");//colocar pontuação
	}
	
	return 0;
}
