#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 10

typedef struct fila{
	int inicio, fim;
	int info[MAXTAM];
}Fila;

//Aloco um espa�o para minha fila e digo que o inicio e fim s�o 0.
Fila *cria_fila(void){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	f->inicio = f->fim = 0;
	return f;
}

//Fun��o para incrementar 1 no posi��o do fim, e verificar se a fila est� cheia
int incr(int fim){
	if(fim == MAXTAM -1){
		return 0;
	}
	return fim + 1;
}

int vazia(Fila *f){
	//Retorna verdadeiro ou falso
	return (f->inicio == f->fim);
}

void insere(Fila *f, int v){
	//Se o retorno da fun��o incr for igual a 0 ent�o a fila est� cheia
	if(incr(f->fim) == f->inicio){
		printf("Capacidade da fila estourou!\n");
		exit(1);
	}
	//Insere elemento na proxima posi��o livre
	f->info[f->fim] = v;
	f->fim = incr(f->fim);
}

//Fun��o para retirar um valor da fila (Conferir funcionamento quando a fila estiver cheia)
int retira(Fila *f){
	int v;
	
	if(vazia(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	
	v = f->info[f->inicio];
	f->inicio = incr(f->inicio);
	return v;
}

void libera(Fila *f){
	free(f);
}

void imprime(Fila *f){
	for(int indice = f->inicio; indice < f->fim; indice++){
		printf("Imprimindo Fila %i\n", f->info[indice]);
	}
}

