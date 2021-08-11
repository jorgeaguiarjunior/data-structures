#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{
	char modelo[100];
	char sigla[10];
	char companhia[30];
	struct NO *prox;	
}NO;

typedef struct Fila{
	NO *inicio;
	NO *fim;
}Fila;

Fila *inicia_fila(){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	
	return f;
}

int fila_vazia(Fila *f){
	if(f->inicio == NULL){
		return 1;
	}else{
		return 0;
	}
}

void insere_fila(Fila *f, char *modelo_aviao, char *sigla_aviao, char *companhia_aerea){
	NO *no = (NO*) malloc (sizeof(NO));
	strcpy(no->modelo, modelo_aviao);
	strcpy(no->sigla, sigla_aviao);
	strcpy(no->companhia, companhia_aerea);
	no->prox = NULL;
	
	if(fila_vazia(f) == 1){
		f->inicio = no;	
	}else{
		f->fim->prox = no;
	}
	f->fim = no;
}

void remove_fila(Fila *f){
	NO *no = f->inicio;

	if(no != NULL){ 
		if(f->fim == f->inicio){
			f->fim = NULL;
			f->inicio = NULL;
			free(no);
		}else{
			f->inicio = no->prox;
			free(no);
		}
	}else{
		printf("Fila vazia!\n");
	}
}

void imprime_fila(Fila *f){
	system("cls");
	printf("--------------------------------------------------------\n\n");
	if(fila_vazia(f) == 1){
		printf("Fila vazia!\n\n");
	}else{
		printf("Fila de avioes no solo:\n\n");
		printf("--------------------------------------------------------\n\n");
		for(NO *no = f->inicio; no != NULL; no = no->prox){
			printf("Modelo do Avião: %s\nSigla: %s\nCompanhia Aerea: %s\n\n", no->modelo, no->sigla, no->companhia);
		}
	}
	printf("--------------------------------------------------------\n\n");
}

void libera_fila(Fila *f){
	while(fila_vazia(f) != 1){
		remove_fila(f);
	}
	free(f);
}
