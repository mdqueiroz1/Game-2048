#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
mudar as cores do prompt para mostrar que o jogador está prestes a perder.
sequencia de cores:verde, amarelo, vermelho. 
*/
menu_jogo(){
	printf("--------------------------------\n");//30linhas
	printf("--------------MENU--------------\n");
	printf("--------------------------------\n");
	printf("1- Iniciar Jogo\n");
	printf("2- Ver Recordes\n");
	printf("3- Definir Dificuldade\n");
	printf("--------------------------------\n");
}
//menu do jogo
int main(){
	system("color 0A");//mudar a prompt p preto com verde
	int menu1, dificuldade;
	char usuario[10],confirma_dificul;

	printf("--------------------------------\n");//30linhas
	printf("--------------MENU--------------\n");
	printf("--------------------------------\n");
	printf("1- Iniciar Jogo\n");
	printf("2- Ver Recordes\n");
	printf("3- Definir Dificuldade\n");
	printf("--------------------------------\n");

	do{
	scanf("%d", &menu1);
		if(menu1<=0||menu1>4){
			printf("Numero de menu invalido.\n");
		}
	}while(menu1<=0||menu1>4);
		
	system("cls");//limpar a tela do prompt, comando da biblioteca conio.c
	
	switch(menu1){
		case 1:{
			printf("Bem Vindo!\n");
			printf("Informe o nome de usuario:\n");
			getchar();
			printf("Instrucoes: \nW - Cima\nA - Esquerda\nS - Baixo\nD - Direita\nP - Salvar e sair\n");
			printf("Pressione enter para continuar.\n");
			getchar();
			printf("~jogo iniciado~");//game_start();
			break;
		}
		case 2:{
			printf("--------------------------------\n");
			printf("Recordes:\n");
			printf("1o - %s\t%d\n");//adicionar usuário do jogo já salvo e recorde do mesmo.
			printf("2o - %s\t%d\n");
			printf("3o - %s\t%d\n");
			printf("--------------------------------\n");
			
			printf("Pressione enter para voltar.\n");
			getchar();
			printf("~voltou~");
			system("cls");
			menu_jogo();//voltar ao menu principal
			
			break;
		}
		case 3:{
			/*
			na seleção de dificuldade adicionar e tentar rodar zoeira na escolha do usuario.
			dificil - Mas cê é o bixão mesmo hein?
			medio - ?
			facil - Vejo que temos um bebezao por aqui!
			*/
			printf("--------------------------------\n");
			printf("Dificuldade:\n");
			printf("1- Facil\n");
			printf("2- Medio\n");
			printf("3- Dificil\n");
			printf("--------------------------------\n");
			do{
				do{
					printf("Selecione a dificuldade.\n");
					scanf("%d",&dificuldade);
					if(dificuldade<=0||dificuldade>3){
						printf("Numero de dificuldade invalido.\n");
					}
				}while(dificuldade<=0||dificuldade>3);
				/*
				na seleção de dificuldade adicionar e tentar rodar zoeira na escolha do usuario.
				dificil - Mas cê é o bixão mesmo hein?
				medio - ?
				facil - Vejo que temos um bebezao por aqui!
				*/
				if(dificuldade==1){
					printf("Vejo que temos um bebezao por aqui!\n");
				}
				if(dificuldade==2){
					printf("alguma coisa\n");
				}
				if(dificuldade==3){
					printf("Mas ce eh o bixao mesmo hein!?\n");
				}
				
				printf("Voce selecionou a dificuldade %d, esta correto?(S/N)\n",dificuldade);
				scanf("%c",&confirma_dificul);
			}while(confirma_dificul!= 'S'||confirma_dificul!= 's');
			break;
		}
	}

	return 0;
}
