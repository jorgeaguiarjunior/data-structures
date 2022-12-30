#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

void insere_arquivo(Pilha *p){
	FILE *txt;
	if((txt = fopen("Passos.txt", "w"))== NULL){
		printf("Erro ao abrir arquivo!\n");
	}else{
		if(pilha_vazia(p) != 1){
			p = desempilha(p);		
			NO *percorre = p->topo;
			while(percorre != NULL){
				if(strcmp(p->topo->passos, percorre->passos) == 0){
					fprintf(txt, "%s", percorre->passos);
				}else{
					fprintf(txt, "\n%s", percorre->passos);
				}
				percorre = percorre->prox;
			}
		}
	}
	fclose(txt);
}

void insere_passo(char *passo, Pilha *p){
	char *aux;
	if(pilha_vazia(p) == 1){
		printf("Nao existe passos registrados!\n");
	}else if(strcmp(passo, p->topo->passos) == 0){
		pop(p);
	}else{
		printf("A remontagem esta fora de ordem!\n");
	}
}

void le_arquivo(Pilha *p){
	FILE *txt;
	char info[100];
	
	if((txt = fopen("Passos.txt", "r")) == NULL){
		printf("__________________Menu__________________\n\n");
		printf("Ainda nao existe passos salvos!\nEntre com alguns dados!\n");
		system("pause");
		system("cls");
	}else{
		while(!feof(txt)){
			fscanf(txt, " %s", info);
			push(info, p);
		}
	}
}

void menu_principal(){
	printf("__________________Menu__________________\n\n");
	printf("[1] Entrar com o passo de DESMONTAGEM\n");
	printf("[2] Receber o proximo passo de MONTAGEM\n");
	printf("[3] Mostrar todos os passos de MONTAGEM\n");
	printf("[4] Inserir um passo de REMONTAGEM\n");
	printf("[5] SAIR\n");
}

int main(){
	Pilha *main_pilha = inicia_pilha();
	char instrucao[100];
	int op;
	
	le_arquivo(main_pilha);
	
	do{
		menu_principal();
		scanf("%i", &op);
		
		switch(op){
			case 1:
				printf("Entre com o passo:\n");
				scanf(" %s", instrucao);
				push(instrucao, main_pilha);
			break;
			case 2:
				if(pilha_vazia(main_pilha) == 1){
					printf("Nenhum passo registrado!\n");
				}else{
					printf("O proximo passo a ser executado eh: %s\n", main_pilha->topo->passos);
				}
			break;
			case 3:
				if(pilha_vazia(main_pilha) == 1){
					printf("Nenhum passo registrado!\n");
				}else{
					printf("Todos os passos a serem executados:\n");
					print_pilha(main_pilha);
				}
			break;
			case 4:
				printf("Entre com o proximo passo valido para remontagem: ");
				scanf(" %s", instrucao);
				insere_passo(instrucao, main_pilha);
			break;
			case 5:
				insere_arquivo(main_pilha);
				pilha_libera(main_pilha);
				printf("Passos salvos!\n");
			break;
			default:
				printf("Entre com uma opcao valida!\n");
			break;
		}
		system("pause");
		system("cls");
	}while(op != 5);
	
}
