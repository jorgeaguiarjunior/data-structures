#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODO{
	int id;
	char modelo[100];
	char sigla[10];
	char companhia[100];
	NODO *prox;
}NODO;

typedef struct Pilha{
	NODO *topo;
}Pilha;


Pilha *inicia_pilha(){
	Pilha *p = (Pilha*) malloc (sizeof(Pilha));
	p->topo = NULL;
	return p;
}

int pilha_vazia(Pilha *p){
	if(p->topo == NULL){
		return 1;
	}
	return 0;
}

void push(Pilha *p, char *modelo_aviao, char *sigla_aviao, char *companhia_aerea, int id_aviao){
	NODO *nodo = (NODO*) malloc (sizeof(NODO));
	nodo->id = id_aviao;
	strcpy(nodo->modelo, modelo_aviao);
	strcpy(nodo->sigla, sigla_aviao);
	strcpy(nodo->companhia, companhia_aerea);
	nodo->prox = p->topo;
	p->topo = nodo;
}

int pop(Pilha *p){
	NODO *nodo;
	
	if(pilha_vazia(p)){
		printf("Pilha vazia!\n");
	}else{
		nodo = p->topo;
		p->topo = nodo->prox;
		free(nodo);
	}
}

void imprime_pilha(Pilha *p){
	system("cls");
	printf("--------------------------------------------------------\n\n");
	NODO *nodo = p->topo;
	int index = 1;
	if(pilha_vazia(p) == 1){
		printf("Pilha vazia !\n\n");
	}else{
		printf("Pilha de avioes no hangar:\n\n");
		printf("--------------------------------------------------------\n\n");
		while(nodo != NULL){
			printf("ID avião: %i\nModelo do Avião: %s\nSigla: %s\nCompanhia Aerea: %s\n\n", nodo->id, nodo->modelo, nodo->sigla, nodo->companhia);
			nodo = nodo->prox;
			index++;
		}
	}
	printf("--------------------------------------------------------\n\n");
}

void libera_pilha(Pilha *p){
	NODO *nodo = p->topo;
	
	while(nodo != NULL){
		NODO *nodo_prox = nodo->prox;
		free(nodo);
		nodo = nodo_prox;
	}
	free(p);
}

int confere_id_pilha(Pilha *p, int id){
	NODO *percorre = p->topo;
	
	while(percorre != NULL){
		if(percorre->id == id){
			return 1;
		}
		percorre = percorre->prox;
	}
	return 0;
}

//Método para retornar uma pilha auxiliar ao contrario, para eu salvar no arquivo da forma correta.
Pilha *desempilhar(Pilha *p){
	Pilha *desempilha = inicia_pilha();
	NODO *aux = p->topo;
	
	for(NODO *aux = p->topo; aux != NULL; aux = aux->prox){
		push(desempilha, aux->modelo, aux->sigla, aux->companhia, aux->id);
	}
	
	return desempilha;
}
