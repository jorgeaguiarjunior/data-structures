#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int dado;
	struct NO *prox;	
}NO;

typedef struct Fila{
	NO *inicio;
	NO *fim;
}Fila;

//Aloco um espa�o de memoria e inicio a minha fila com o inicio e o fim como null
Fila *inicia_fila(){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	
	return f;
}

//Se o inicio for NULL, ent�o a fila est� vazia
int fila_vazia(Fila *f){
	if(f->inicio == NULL){
		return 1;
	}else{
		return 0;
	}
}

void insere_fila(Fila *f, int valor){
	/*Crio e aloco um espa�o para o meu novo n�
	Como a inser��o � feita sempre no fim, digo que o proximo a esse n� � NULL*/
	NO *no = (NO*) malloc (sizeof(NO));
	no->dado = valor;
	no->prox = NULL;
	
	//Se minha fila estiver vazia, ent�o estarei inserindo o primeiro n�, nesse caso o inicio e fim s�o o respectivo n�
	if(fila_vazia(f) == 1){
		f->inicio = no;	
	}else{ //Do contrario, eu digo que o proximo do ultimo n� � o meu novo n�
		f->fim->prox = no;
	}
	f->fim = no; //Em todos os casos o fim aponta para o novo n�.
}

int remove_fila(Fila *f){
	//Crio um n� auxiliar que recebera a informa��o do primeiro elemento, e crio um valor auxiliar para receber o valor contido nesse n�.
	NO *no = f->inicio;
	int valor;
	//Verifico se tem algum n� na minha fila
	if(no != NULL){ 
		/*Se for o ultimo elemento, eu digo que o inicio e o fim apontam para NULO, 
		e dou um free no meu n�, e digo que o meu valor recebe o dado desse n� */
		if(f->fim == f->inicio){
			f->fim = NULL;
			f->inicio = NULL;
			valor = no->dado;
			free(no);
		}else{
			/*Eu digo que o meu inicio aponta para o proximo a esse n�, e digo que o meu valor recebe o dado desse n� 
			Por fim eu dou um free para liberar o espa�o de memoria alocado nesse n�*/
			f->inicio = no->prox;
			valor = no->dado;
			free(no);
		}
		return valor;
	}else{//Caso n�o tenha nenhum n�, ent�o eu lan�o um aviso e finalizo.
		printf("Lista vazia!\n");
	}
}

//Crio um no auxiliar apontando para o inicio, e percorro at� encontrar o null.
void imprime_fila(Fila *f){
	if(fila_vazia(f) == 1){
		printf("Fila vazia!\n");
	}else{
		for(NO *no = f->inicio; no != NULL; no = no->prox){
			printf("Valor: %i\n", no->dado);
		}
	}
}

//Removo todos os n�s da fila e por fim dou um free nela
void libera_fila(Fila *f){
	int aux;
	while(fila_vazia(f) != 1){
		aux = remove_fila(f);
	//	printf("Removido o elemento %i\n", aux);
	}
	free(f);
}
