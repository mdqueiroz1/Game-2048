// Matheus Dias de Queiroz matricula: 5213

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define EXIT_ERROR 1
#define EXIT_SUCCESS 0

	int tam_jogo=4,pontuacao=0;
	char jogador[20];

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

	char confirma_usuario,save_usuario[20];
	void game_start();
	
	printf("Bem Vindo!\n");
	printf("Informe o nome de usuario:\n");
	fflush(stdin);
	gets(jogador);
	
	
	
	if(jogador==save_usuario){
		printf("Deseja carregar jogo salvo?(S/N)");
		scanf("%c", &confirma_usuario);
		if(confirma_usuario=='s'||confirma_usuario=='S'){
		//carregar jogo salvo		
		}
	}else{
		printf("Instrucoes: \n\n\tW - Cima\n\nA - Esquerda\tD - Direita\n\n\tS - Baixo\n\nP - Salvar e sair\n");
		printf("Pressione enter para continuar.\n");
		getch();
		game_start(jogador);
	}
}

char recordes(char jogador[20], int pontuacao){
	
	FILE* f;
	char usuario1[20],usuario2[20],usuario3[20];
	int p1,p2,p3,i;
	
	
	if((f= fopen("recordes", "r")) == NULL){
 		printf("Erro na abertura!\n");
 		exit(EXIT_ERROR);
 	}
	
	if(pontuacao!=0){

		fscanf(f,"%s %d",usuario1,&p1);
		fscanf(f,"%s %d",usuario2,&p2);
		fscanf(f,"%s %d",usuario3,&p3);

		if(pontuacao>p1){
			p1=pontuacao;
			strcpy(usuario1,jogador);
		}else if(pontuacao>p2){
					p2=pontuacao;
					strcpy(usuario2,jogador);
				}else	if(pontuacao>p3){
							p3=pontuacao;
							strcpy(usuario3,jogador);
						}
		fclose(f);

		if ((f= fopen("recordes","w")) == NULL){
			printf("Erro na abertura!\n");
			sleep(2);
			exit(EXIT_ERROR);
		}
 		
		fprintf(f,"%s %d\n",usuario1,p1);
		fprintf(f,"%s %d\n",usuario2,p2);
		fprintf(f,"%s %d\n",usuario3,p3);
		fclose(f);
	}else{
 		printf("--------------------------------\n");
		printf("Recordes:\n");
		fscanf(f,"%s %d",usuario1,&p1);
		printf("1o - %s\t%d\n",usuario1,p1);
		fscanf(f,"%s %d",usuario2,&p2);
		printf("2o - %s\t%d\n",usuario2,p2);
		fscanf(f,"%s %d",usuario3,&p3);
		printf("3o - %s\t%d\n",usuario3,p3);
		printf("--------------------------------\n");
		
		
	}
	
	
	printf("Pressione enter para voltar.\n");
	getch();
	fclose(f);
	system("cls");

	menu_jogo();//voltar ao menu principal

	return ;
}

void dificuldade_jogo(){

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
			tam_jogo=6;
		}
		if(dificuldade==2){
			printf("Esta com medo de jogar no dificil, frutinha?\n");
			tam_jogo=5;		
		}
		if(dificuldade==3){
			printf("Mas ce eh o bixao mesmo hein!?\n");
			tam_jogo=4;
		}
		if(dificuldade==1){
			printf("Voce selecionou a dificuldade facil, esta correto?(S/N)\n");
		}else if(dificuldade==2){
				printf("Voce selecionou a dificuldade medio, esta correto?(S/N)\n");
				}else if(dificuldade==3){
					printf("Voce selecionou a dificuldade dificil, esta correto?(S/N)\n");	
					}
		fflush(stdin);
		scanf("%c",&confirma_dificuldade);
	}while(confirma_dificuldade!= 'S'&&confirma_dificuldade!= 's');

		return ;
}

void game_start(char jogador[20]){
	system("cls");
	int lin,col,i,j,cont=0,tabela[tam_jogo][tam_jogo],cont_jogadas=0,inicio;
	
	for(lin=0;lin<tam_jogo;lin++){
		for(col=0;col<tam_jogo;col++){
			tabela[lin][col] = 0;
		}
	}
		
	srand(time(NULL));
	
	do{
		lin=rand()%tam_jogo;
		col=rand()%tam_jogo;
	}while(tabela[lin][col]!=0);

	tabela[lin][col]=2;

	funcionamento(tabela,2,0,jogador,0);
}

int funcionamento(int tabela[tam_jogo][tam_jogo], int cont, int cont_jogadas,char jogador[20],int pontuacao){
	
	int lin,col,r2ou4,i,j;
	char jogada, verifica_recorde;
	
	srand(time(NULL));	
	do{
		lin=rand()%tam_jogo;
		col=rand()%tam_jogo;
	}while(tabela[lin][col]!=0);

	do{
		r2ou4=rand()%5;
	}while(r2ou4%2!=0);
				
	if(r2ou4 == 0){
		tabela[lin][col]=2;
	}else{
		tabela[lin][col]=r2ou4;
	}
	
	if(cont<=((tam_jogo*tam_jogo)-(tam_jogo+tam_jogo+1))){
		system("color 0A");
	}else if(cont>(((tam_jogo*tam_jogo)-(tam_jogo+tam_jogo))&&cont<((tam_jogo*tam_jogo))-1)){
				system("color 0E");
			}else if(cont>=((tam_jogo*tam_jogo))){
						system("color 0C");
					}
					
	//impress�o da tabela do jogo

	printf("Jogador:%s\tPontuacao: %d",jogador,pontuacao);
		printf("\n ---------------------------------------------------------------");
		if(tam_jogo==6){
			printf("--------------------------------");
		}else if(tam_jogo == 5){
				printf("----------------");
			}
		printf("\n");
	for(lin=0;lin<tam_jogo;lin++){
		printf("|");
		
		if(tam_jogo==6){
		printf("\t \t|\t \t|");
		}else if(tam_jogo==5){
				printf("\t \t|");
			}
		printf("\t \t|\t \t|\t \t|\t \t|\n|");
		for(col=0;col<tam_jogo;col++){
			if(tabela[lin][col] == 0){
				printf("\t \t|");
			}else{
				printf("\t%d\t|",tabela[lin][col]);
			}
		}
		printf("\n|\t \t|\t \t|\t \t|\t \t|");
		if(tam_jogo==6){
		printf("\t \t|\t \t|");
		}else if(tam_jogo==5){
				printf("\t \t|");
			}
		
		printf("\n ---------------------------------------------------------------");
		if(tam_jogo==6){
			printf("--------------------------------");
		}else if(tam_jogo == 5){
				printf("----------------");
			}
		printf("\n");
	}
	
	do{
		fflush(stdin);
		printf("Jogada: ");
		jogada=getch();
		jogada=tolower(jogada);
		fflush(stdin);
	}while(jogada!='a' && jogada!='s'&& jogada!='d'&& jogada!='w' && jogada!='p');
	
	switch(jogada){
	
		case 'a':{
		//esquerda(pronto)
			for(lin=0;lin<tam_jogo;lin++){
				for(i=0;i<tam_jogo-1;i++){
					if(tabela[lin][i]==tabela[lin][i+1]){
						tabela[lin][i+1]=tabela[lin][i]+tabela[lin][i+1];
						pontuacao=pontuacao+tabela[lin][i+1];
						tabela[lin][i]=0;
					}
				}
				for(i=0;i<tam_jogo;i++){
					for(j=0;j<tam_jogo-1;j++){
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
			for(lin=tam_jogo-1;lin>=0;lin--){
				for(i=tam_jogo-1;i>=0;i--){
					if(tabela[lin][i]==tabela[lin][i-1]){
						tabela[lin][i-1]=tabela[lin][i]+tabela[lin][i-1];
						pontuacao=pontuacao+tabela[lin][i-1];
						tabela[lin][i]=0;
					}
				}
				for(i=tam_jogo-1;i>=0;i--){
					for(j=tam_jogo-1;j>=1;j--){
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
			for(lin=0;lin<tam_jogo;lin++){
				for(i=0;i<tam_jogo;i++){
					if(tabela[i][lin]==tabela[i+1][lin]){
						tabela[i+1][lin]=tabela[i][lin]+tabela[i+1][lin];
						pontuacao=pontuacao+tabela[i+1][lin];
						tabela[i][lin]=0;
					}
				}
				for(i=0;i<tam_jogo;i++){
					for(j=0;j<tam_jogo-1;j++){
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
			for(lin=tam_jogo-1;lin>=0;lin--){
				for(i=tam_jogo-1;i>=0;i--){
					if(tabela[i][lin]==tabela[i-1][lin]){
						tabela[i-1][lin]=tabela[i][lin]+tabela[i-1][lin];
						pontuacao=pontuacao+tabela[i-1][lin];
						tabela[i][lin]=0;
					}
				}
				for(i=tam_jogo-1;i>=0;i--){
					for(j=tam_jogo-1;j>=1;j--){
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
	for(i=0;i<tam_jogo;i++){
		for(j=0;j<tam_jogo;j++){
			if(tabela[i][j]!=0){
				cont++;
			}
			if(tabela[i][j]==2048){
				system("cls");
				printf("Parabens %s voce ganhou! Pontuacao: %d\n\n",jogador,pontuacao);
				return recordes(jogador, pontuacao);
			}
		}
	}
	
	if(cont==(tam_jogo*tam_jogo)){
		printf("Voce perdeu %s!\nPontuacao: %d \n",jogador,pontuacao);
		return recordes(jogador, pontuacao);
	}else{ 
		return funcionamento(tabela,cont,cont_jogadas+=1,jogador,pontuacao);
	}
	
}

int main(){
	system("color 0A");
		
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
				recordes(jogador,pontuacao);
				break;
			}
			case 3:{
				dificuldade_jogo();
				break;
			}
		}
	}while(menu1!=1);
	
	return 0;
}



