#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 100

typedef struct{
	int item[MAXTAM];
	int topo;
}pilha;

/*
	Aloco um espaço para a minha nova pilha, e digo que o topo é o index 0, e retorno a referencia de memoria da minha pilha
*/
pilha *pilha_inicia(pilha *p){
	p = (pilha*) malloc (1 * sizeof(pilha));
	p->topo = 0;
	return p;
}

/*
	Caso a pilha esteja vazia eu retorno 1, do contrario retorno 0
*/
int pilha_verifica(pilha *p){
	if(p->topo == 0){
		return 1;
	}
	
	return 0;
}

/*
	Caso a pilha esteja cheia eu retorno 1, do contrario retorno 0
*/
int pilha_cheia(pilha *p){
	if(p->topo == MAXTAM){
		return 1;
	}
	
	return 0;
}

/*
	Verifico se minha pilha está cheia, caso esteja eu lanço um aviso,
	do contrario eu digo que o meu elemento no topo é o valor passado por parametro,
	e incremento 1 ao index do meu topo.
*/
void push(pilha *p, int x){
	if(pilha_cheia(p) == 1){
		printf("\nErro: Pilha cheia");
	}else{
		p->item[p->topo] = x;
		p->topo++;
	}
}

/*
	Crio uma variavel int auxiliar, e verifico se a pilha está vazia, caso esteja eu lanço um aviso, do contrario
	eu digo que o valor do meu auxiliar é o valor do meu item no topo (p->topo-1 pois eu sempre incremento 1 após adicionar um
	elemento, portanto tenho que subtrair 1 para saber o index correto do meu topo), após isso eu subtraio 1 do meu topo
	e retorno o valor que foi retirado.
*/
int pop(pilha *p){
	int aux;
	if(pilha_verifica(p) == 1){
		printf("\nErro: Pilha vazia");
	}else{
		aux = p->item[p->topo-1];
		p->topo--; 
		return aux;
	}
}

/*
	Apenas dou um free na minha pilha
*/
void libera_pilha(pilha *p){
	free(p);
}
