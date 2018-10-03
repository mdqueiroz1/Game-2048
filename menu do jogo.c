#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
mudar as cores do prompt para mostrar que o jogador est� prestes a perder.
sequencia de cores:verde, amarelo, vermelho. 
*/

int menu_jogo(){
	
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

void inicio_jogo(){

	char usuario[10],confirma_usuario,save_usuario[10];
	void game_start();
	
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

void recordes(){
	printf("--------------------------------\n");
	printf("Recordes:\n");
	printf("1o - %s\t%d\n");//adicionar usu�rio do jogo j� salvo e recorde do mesmo.
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

int dificuldade_jogo(){
	
	int dificuldade;
	char confirma_dificuldade;
	
	/*
	na sele��o de dificuldade adicionar e tentar rodar zoeira na escolha do usuario.
	dificil - Mas c� � o bix�o mesmo hein?
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
	
		return dificuldade;
}

void game_start(){
	printf("\n\n~jogo iniciado~\n\n");
	system("cls");
	int lin,col,i,j,cont=0,tabela[4][4],cont_jogadas=0,pontuacao,inicio,r2ou4;
	
	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
		
	srand(time(NULL));//se deixar o time(null) fora chega no resultado mais r�pido.
	
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

	funcionamento(tabela,2,0);

	return ;
}

int funcionamento(int tabela[4][4], int cont, int cont_jogadas){//n�o testado, terminar o retorno e recurs�o.
	
	int lin,col,r2ou4;
	char jogada;
	
	srand(time(NULL));	
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
	
	if(cont<=8){
		system("color 0A");
	}else if(cont>8){
				system("color 0E");
			}else if(cont<=15){
						system("color 0C");
					}
					
	//impress�o da tabela do jogo
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
	
	scanf("%c", &jogada);
	switch(jogada){
		case 'a':{
			
			break;
		}
		case 'd':{
			
			break;
		}
		case 'w':{
			
			break;
		}
		case 's':{
			
			break;
		}
		case 'p':{
			//inserir save do jogo
			return 0;
			break;
		}
	}
	printf("%d %d",cont,cont_jogadas);
	system("cls");
	if(cont==16){
		printf("Voce perdeu!\nPontuacao: \n");//colocar pontua��o
		return 0;
	}else{ 
		return funcionamento(tabela,cont+=1,cont_jogadas+=1);
	}
	
}

int main(){
	system("color 0A");//mudar a prompt p preto com verde
	
	int dificuldade;
		
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
				dificuldade=dificuldade_jogo();
				break;
			}
		}
	}while(menu1!=1);//1 inicia o jogo
	
	return 0;
}



