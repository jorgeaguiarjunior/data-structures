#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arvore{
	char conteudo[100];
	bool resposta; //Se for true vai para a esquerda, se for false vai para a direita, e se for uma nova pergunta vai para a direita.
	struct arvore *esquerda; //Sim
	struct arvore *direita; //Não
}Arv;

Arv *inserir(Arv *raiz, char *questao, bool resp){
	if(raiz == NULL){
		Arv *novo = (Arv*) malloc (sizeof(Arv));
		strcpy(novo->conteudo, questao);
		novo->resposta = resp;
		novo->esquerda = NULL;
		novo->direita = NULL;
		return novo;
	}else{
		if(resp == true){
			raiz->esquerda = inserir(raiz->esquerda, questao, resp);
		}else{
			raiz->direita = inserir(raiz->direita, questao, resp);
		}
		return raiz;
	}
}

int tamanho(Arv *raiz){
	if(raiz != NULL){
		return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
	}
	return 0;
}

void imprimir(Arv *raiz){ //Essa função imprime os elementos de acordo com sua posição na arvore, ou seja, quem está a direita e esquerda de quem.
	if(raiz != NULL){
		imprimir(raiz->esquerda);
		printf("  --  Conteudo: %s, Resposta: %d  --  ", raiz->conteudo, raiz->resposta);
		imprimir(raiz->direita);
	}
}
