#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
mudar as cores do prompt para mostrar que o jogador está prestes a perder.
sequencia de cores:verde, amarelo, vermelho. 
*/

int main(){
	system("color 0A");//mudar a prompt p preto com verde
	
	int menu_jogo(void);//menu principal
	void inicio_jogo(void);//1
	void recordes(void);//2	
	void dificuldade_jogo(void);//3
	void game_start(void);
		
	int menu1;	
	do{
		system("cls");//limpar a tela do prompt
		menu1= menu_jogo();
		system("cls");
		
		switch(menu1){
			case 1:{
				inicio_jogo();
				break;
					}
			case 2:{
				recordes();
				break;
			}
			case 3:{
				dificuldade_jogo();
				break;
			}
		}
	}while(menu1!=1);//1 inicia o jogo
	
	return 0;
}

int menu_jogo(void){
	
	int menu1;
	
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
	
	return menu1;

}

void inicio_jogo(void){

	char usuario[10],confirma_usuario,save_usuario[10];
	void game_start(void);
	
	printf("Bem Vindo!\n");
	printf("Informe o nome de usuario:\n");
	fflush(stdin);
	gets(usuario);

	if(usuario==save_usuario){
		printf("Deseja carregar jogo salvo?(S/N)");
		scanf("%c", &confirma_usuario);
		if(confirma_usuario=='s'||confirma_usuario=='S'){
		//carregar jogo salvo		
		}
	}else{
		printf("Instrucoes: \n\n\tW - Cima\n\nA - Esquerda\tD - Direita\n\n\tS - Baixo\n\nP - Salvar e sair\n");
		printf("Pressione enter para continuar.\n");
		getch();
		game_start();
	}
}

void recordes(void){
	printf("--------------------------------\n");
	printf("Recordes:\n");
	printf("1o - %s\t%d\n");//adicionar usuário do jogo já salvo e recorde do mesmo.
	printf("2o - %s\t%d\n");
	printf("3o - %s\t%d\n");
	printf("--------------------------------\n");
	
	printf("Pressione enter para voltar.\n");
	getch();
	printf("~voltou~");
	system("cls");

	menu_jogo();//voltar ao menu principal

	return ;
}

void dificuldade_jogo(void){
	
	int dificuldade;
	char confirma_dificuldade;
	
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
		
		fflush(stdin);
		
		if(dificuldade==1){
			printf("Vejo que temos um bebezao por aqui!\n");
		}
		if(dificuldade==2){
			printf("Esta com medo de jogar no dificil, frutinha?\n");
		}
		if(dificuldade==3){
		printf("Mas ce eh o bixao mesmo hein!?\n");
		}
		
		printf("Voce selecionou a dificuldade %d, esta correto?(S/N)\n",dificuldade);
		fflush(stdin);
		//confirma_dificuldade=getch();
		scanf("%c",&confirma_dificuldade);
	}while(confirma_dificuldade!= 'S'&&confirma_dificuldade!= 's');
	
		return ;
}
/*
se houver uma sequencia de 4 numeros iguais, eles deverão ser adicionados com dois comandos,
e não apenas com um.
*/
void game_start(){
	printf("\n\n~jogo iniciado~\n\n");
	printf("teste completo!\n");
}

