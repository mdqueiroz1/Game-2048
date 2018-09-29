#include<stdio.h>
#include<stdlib.h>
#include<conio.c>

int main(){

	int lin, aux,vet1[4],i;
	//mover para a direita

	for(lin=0;lin<4;lin++){
		vet[lin] = 0;
	}
		vet[3]=1;
		vet[2]=1;
		vet[1]=1;
		lin=3;
	do{

			aux=vet[lin-1];
			vet[lin-1]=vet[lin];
			vet[lin]=aux;
			
			for(i=0;i<4;i++){
			printf("%d",vet[i]);
			}
			getch();
			printf("\n");
			lin--;

	}while(vet[4]!=0);
	

	
	return 0;
}
