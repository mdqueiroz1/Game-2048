#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


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

	char usuario[20],confirma_usuario,save_usuario[20];
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
		game_start(usuario);
	}
}

void recordes(){
	printf("--------------------------------\n");
	printf("Recordes:\n");
	printf("1o - %s\t%d\n");//adicionar usuário do jogo já salvo e recorde do mesmo.
	printf("2o - %s\t%d\n");
	printf("3o - %s\t%d\n");
	printf("--------------------------------\n");
	
	printf("Pressione enter para voltar.\n");
	getch();
	system("cls");

	menu_jogo();//voltar ao menu principal

	return ;
}

int dificuldade_jogo(){
	
	int dificuldade;
	char confirma_dificuldade;
	
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
		scanf("%c",&confirma_dificuldade);
	}while(confirma_dificuldade!= 'S'&&confirma_dificuldade!= 's');
	
		return dificuldade;
}

void game_start(char jogador[20]){
	system("cls");
	int lin,col,i,j,cont=0,tabela[4][4],cont_jogadas=0,pontuacao,inicio;
	
	for(lin=0;lin<4;lin++){
		for(col=0;col<4;col++){
			tabela[lin][col] = 0;
		}
	}
		
	srand(time(NULL));
	
	do{
		lin=rand()%4;
		col=rand()%4;
	}while(tabela[lin][col]!=0);

	tabela[lin][col]=2;

	funcionamento(tabela,2,0,jogador,0);
}

int funcionamento(int tabela[4][4], int cont, int cont_jogadas,char jogador[20],int pontuacao){
	
	int lin,col,r2ou4,i,j;
	char jogada;
	
	srand(time(NULL));	
	do{
		lin=rand()%4;
		col=rand()%4;
	}while(tabela[lin][col]!=0);

	do{
		r2ou4=rand()%5;
	}while(r2ou4%2!=0);
				
	if(r2ou4 == 0){
		tabela[lin][col]=2;
	}else{
		tabela[lin][col]=r2ou4;
	}
	
	if(cont<=8){
		system("color 0A");
	}else if(cont>8&&cont<15){
				system("color 0E");
			}else if(cont>=15){
						system("color 0C");
					}
					
	//impressão da tabela do jogo
	printf("Jogador:%s\tPontuacao: %d",jogador,pontuacao);
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
	
	do{
		fflush(stdin);
		printf("Jogada: ");
		scanf("%c",&jogada);
		jogada=tolower(jogada);
		fflush(stdin);
	}while(jogada!='a' && jogada!='s'&& jogada!='d'&& jogada!='w' && jogada!='p');
	
	switch(jogada){
	
		case 'a':{
		//esquerda(pronto)
	for(lin=0;lin<4;lin++){
				for(i=0;i<3;i++){
				if(tabela[lin][i]==tabela[lin][i+1]){
					tabela[lin][i+1]=tabela[lin][i]+tabela[lin][i+1];
					pontuacao=pontuacao+tabela[lin][j];
					tabela[lin][i]=0;
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
			break;
		}
	
		case 'd':{
			//direita(teste)
			for(lin=3;lin>=0;lin--){
				for(i=3;i>=0;i--){
					if(tabela[lin][i]==tabela[lin][i-1]){
						tabela[lin][i-1]=tabela[lin][i]+tabela[lin][i-1];
						pontuacao=pontuacao+tabela[lin][i-1];
						tabela[lin][i]=0;
					}
				}
				for(i=3;i>=0;i--){
					for(j=3;j>=1;j--){
						if(tabela[lin][j]==0){
							tabela[lin][j]=tabela[lin][j-1];
							tabela[lin][j-1]=0;
						}
					}
				}
			}
			break;
		}
	
		case 'w':{
			//cima(teste)
			for(lin=0;lin<4;lin++){
				for(i=0;i<4;i++){
					if(tabela[i][lin]==tabela[i+1][lin]){
						tabela[i+1][lin]=tabela[i][lin]+tabela[i+1][lin];
						pontuacao=pontuacao+tabela[i+1][lin];
						tabela[i][lin]=0;
					}
				}
				for(i=0;i<4;i++){
					for(j=0;j<3;j++){
						if(tabela[j][lin]==0){
							tabela[j][lin]=tabela[j+1][lin];
							tabela[j+1][lin]=0;
						}
					}
				}
			}
			break;
		}
	
		case 's':{
			//baixo()
			for(lin=3;lin>=0;lin--){
				for(i=3;i>=0;i--){
					if(tabela[i][lin]==tabela[i-1][lin]){
						tabela[i-1][lin]=tabela[i][lin]+tabela[i-1][lin];
						pontuacao=pontuacao+tabela[i-1][lin];
						tabela[i][lin]=0;
					}
				}
				for(i=3;i>=0;i--){
					for(j=3;j>=1;j--){
						if(tabela[j][lin]==0){
							tabela[j][lin]=tabela[j-1][lin];
							tabela[j-1][lin]=0;
						}
					}
				}
			}
			break;
		}
		
		case 'p':{
			//inserir save do jogo
			return 0;
			break;
		}
	}

	system("cls");
	
	cont=0;//contagem de espacos vazios
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(tabela[i][j]!=0){
				cont++;
			}
			if(tabela[i][j]==2048){
				system("cls");
				printf("Parabens %s voce ganhou! Pontuacao: %d\n\n",jogador,pontuacao);
				return 0;
			}
		}
	}
	
	if(cont==15){
		printf("Voce perdeu %s!\nPontuacao: %d \n",jogador,pontuacao);
		return 0;
	}else{ 
		return funcionamento(tabela,cont,cont_jogadas+=1,jogador,pontuacao);
	}
	
}

int main(){
	system("color 0A");
	
	int dificuldade;
		
	int menu1;
	do{
		system("cls");
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
	}while(menu1!=1);
	
	return 0;
}



