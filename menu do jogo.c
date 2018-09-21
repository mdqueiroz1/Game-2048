#include<stdio.h>
#include<stdlib.h>

//menu do jogo
int main(){

	int menu1, dificuldade;
	char c_get;

	printf("--------------------------------\n");//30linhas
	printf("--------------MENU--------------\n");
	printf("--------------------------------\n");
	printf("1- Iniciar Jogo\n");
	printf("2- Ver Recordes\n");
	printf("3- Definir Dificuldade\n");
	printf("--------------------------------\n");

	do{
	scanf("%d", &menu1);
	}while(menu1<=0||menu1>4);

	switch(menu1){
		case 1:{
			printf("Bem Vindo!");
			printf("Informe o nome de usuário:\n");

			printf("Instruções: ... ... ...");
			/*
			w - cima
			a - esquerda
			s - baixo
			d - direita
			*/
			printf("Pressione enter para continuar.\n");
			getchar();
			printf("jogo iniciado");//iniciar o jogo.
			break;
		}
		case 2:{
			printf("--------------------------------\n");
			printf("Recordes:\n");
			printf("1o - %s\t%d\n");//adicionar usuário do jogo já salvo e recorde do mesmo.
			printf("2o - %s\t%d\n");
			printf("3o - %s\t%d\n");
			printf("Pressione enter para voltar.\n");
			printf("--------------------------------\n");
			getchar();
			printf("voltou");//return menu_jogo;

			break;
		}
		case 3:{
			printf("--------------------------------\n");
			printf("Dificuldade:\n");
			printf("1- Facil\n");
			printf("2- Medio\n");
			printf("3- Dificil\n");
			printf("--------------------------------\n");

				do{
					printf("Selecione a dificuldade.\n");
					scanf("%d",&dificuldade);
					if(dificuldade<=0||dificuldade>3){
						printf("Numero de dificuldade invalido.\n");
					}
				}while(dificuldade<=0||dificuldade>3);


			break;
		}
	}

	return 0;
}
