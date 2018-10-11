#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
   0_1_2_3_
0 |2 0 4 2
1 |0 0 0 0
2 |0 0 0 0
3 |0 0 0 0 

if(tabela[0][0]==tabela[0][1]){
	tabela[0][0]=tabela[0][0]+tabela[0][1];
}else tabela[0][0+1]
*/

int main(){

int lin,col,i,j,cont=0,tabela[4][4],cont_jogadas=0,pontuacao,inicio,r2ou4;

	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
	
	srand(time(NULL));
	for(i=0;i<2;i++){
		do{
			lin=rand()%4;
			col=rand()%4;
		}while(tabela[lin][col]!=0);
		
		tabela[lin][col]=2;
	}

	for(lin=0;lin<4;lin++){//impressao em tela
		for(col=0;col<4;col++){
			printf("%d",tabela[lin][col]);
		}
		printf("\n");
	}
printf("\n");
	
	for(lin=0;lin<4;lin++){
		while(col<3){
			if(tabela[lin][col]==tabela[lin][col+1]){
				tabela[lin][col]=tabela[lin][col]+tabela[lin][col+1];
				tabela[lin][col+1]=0;
			}else col++;
		}
	}
	
	for(lin=0;lin<4;lin++){//impressao em tela
		for(col=0;col<4;col++){
			printf("%d",tabela[lin][col]);
		}
		printf("\n");
	}
//	funcionamento(tabela,2,0,jogador,0);

	return 0;
}
