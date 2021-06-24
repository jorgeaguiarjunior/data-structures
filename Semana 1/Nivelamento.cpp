#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QTD_NOTAS 4

//Estrutura com os dados do aluno, eu não entendi quantas notas tem que ter, então considerei que sejam 4.
struct registro_aluno{
	char nome[100];
	float notas[QTD_NOTAS];
};

//Variavel global contendo os registros dos alunos.
struct registro_aluno alunos[1000];
//Ponteiro para o meu arquivo
FILE *txt;
char linha[1024];
char *ultima;

//Variavel contendo a ultima posicao livre.
int posicao = 0;

//Método para carregamento dos arquivos.
void carrega_registros(){
	if((txt = fopen("Arquivo.txt", "r")) == NULL){
		printf(" Erro ao abrir arquivo");
	}else{
		for(int i=0; !feof(txt); i++){
			fgets(linha, 1024, txt);
			ultima = strtok(linha, ";");
		
			for(int j=0; ultima != NULL; j++){
				if(j == 0){
					strcpy(alunos[i].nome, ultima);
				}else{
					alunos[i].notas[j-1] = atof(ultima);
				}
				ultima = strtok (NULL, ";");
			}
			posicao = i;
		}
	}
	fclose(txt);
}

//Método para criar um novo registro, ainda sem salvar no arquivo.
void cria_registro(){
	system("cls");
	printf("_____________Novo Registro_____________\n\n");
	printf(" Qual o nome do novo aluno? ");
	scanf(" %s", alunos[posicao].nome);
	
	for(int i=0; i < QTD_NOTAS; i++){
		printf(" Digite a %i nota: ", (i+1));
		scanf("%f", &alunos[posicao].notas[i]);
	}
	
	printf(" Registro criado com sucesso!\n\n");
	posicao++;
	system("pause");
}

//Método para salvar todos os registros no arquivo, com separação de ;
void salva_registros(){
	system("cls");
	printf("_____________Salvando registros_____________\n\n");
	if((txt = fopen("Arquivo.txt", "w")) == NULL){
		printf(" Erro ao abrir arquivo");
	}else{
		for(int i=0; i<posicao; i++){
			fprintf(txt, "%s;", alunos[i].nome);
			for(int j=0; j< QTD_NOTAS-1; j++){
				fprintf(txt, "%.2f;", alunos[i].notas[j]);
			}
			fprintf(txt, "%.2f\n", alunos[i].notas[QTD_NOTAS-1]);
		}
		printf("Arquivos salvos com sucesso!\n\n");
	}
	fclose(txt);
	system("pause");
}

//Método para procurar o registro e mostrar a media, como no enunciado não dizia nada sobre retornar, eu fiz em void e só printei na tela.
void procura_registros(){
	system("cls");
	printf("_____________Procurando registros_____________\n\n");
	char nome_aluno[100];
	float media = 0;
	printf(" Digite o nome do aluno: ");
	scanf("%s", nome_aluno);
	
	for(int i=0; i<posicao; i++){
		if(strcmp(nome_aluno, alunos[i].nome) == 0){
			for(int j = 0; j < QTD_NOTAS; j++){
				media += alunos[i].notas[j];
			}
			printf(" Nome: %s\n Media das notas: %.2f\n\n", alunos[i].nome, media/QTD_NOTAS);
			break;
		}else if(i == posicao-1 && strcmp(nome_aluno, alunos[posicao-1].nome) != 0){
			printf(" Nao foi encontrado o registro!\n\n");
		}
	}
	system("pause");
}

int main(){
	//Variavel para guardar a opção do menu principal
	char option;
	
	carrega_registros();
	//Menu principal
	do{
		system("cls");
		
		printf("_____________Menu Principal_____________\n\n");
		
		printf(" 1) Novo Registro\n");
		
		printf(" 2) Salvar todos no arquivo TXT\n");
		
		printf(" 3) Pesquisar Nome de Aluno\n");
		
		printf(" 4) Sair\n\n");
		
		printf(" Entre com a opcao desejada: ");
		scanf(" %c", &option);
		
		switch(option){
			case '1':
				cria_registro();
			break;
			case '2':
				salva_registros();
			break;
			case '3':
				procura_registros();
			break;
			case '4':
				printf(" Fim de execucao!\n");
			break;
			default:
				printf(" Entre com uma opcao valida!\n\n ");
				system("pause");
			break;
		}
	}while(option != '4');
}
