//menu do jogo
#include<stdio.h>


int main(){
	
	int menu1, volta=1;
	
	printf("--------------------------------\n");//30linhas
	printf("--------------MENU--------------\n");
	printf("--------------------------------\n");
	printf("1- Novo Jogo\n");
	printf("2- Ver Recordes\n");
	printf("3- Definir Dificuldade\n");
	printf("4- Continuar Jogo Salvo\n\n");
	printf("--------------------------------\n");
	
	do{
	scanf("%d", menu1);
	}while(menu1<=0||menu1>5);
	
	switch(menu1){
		case 1:{
			printf("Bem Vindo!");
			printf("Instruções: ... ... ...");
			printf("Pressione enter para continuar.\n");
			getch();
			printf("jogo iniciado");//iniciar o jogo.
			break;
		}
		case 2:{
			printf("Recordes:\n");
			printf("1o - %s\t%d\n");//adicionar usuário para salvar o jogo e recorde do mesmo.
			printf("2o - %s\t%d\n");
			printf("3o - %s\t%d\n");
			printf("Pressione enter para voltar.\n");
			getch();
			printf("voltou.");//return menu_jogo;
			
			break;
		}
		case 3:{
			printf("--------------------------------\n");
			printf("Dificuldade:\n");
			printf("1- Facil\n");
			printf("2- Medio\n");
			printf("3- Dificil\n");
			break;
		}
	}
	
	return 0;
}
