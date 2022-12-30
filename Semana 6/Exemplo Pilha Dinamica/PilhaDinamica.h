#include<stdio.h>
#include<stdlib.h>

/*
	Crio uma estrutura para o N� da minha pilha, que vai conter a informa��o desse n�, e um ponteiro para o proximo n�.
*/
struct NO{
	int info;
	struct NO *prox;
}typedef NO;

/*
	Crio uma estrutura para a minha Pilha propriamente dita, que vai conter um ponteiro para o n� que est� no topo.
*/
struct Pilha{
	NO *topo;
}typedef Pilha;

/*
	Aloco um espa�o para a minha pilha e digo que o topo � Nulo, e retorno a referencia de memoria para a minha pilha.
*/
Pilha *inicia_pilha(){
	Pilha *p = (Pilha*) malloc (sizeof(Pilha));
	p->topo = NULL;
	return p;
}

/*
	Caso o topo seja nulo, ent�o a minha pilha est� vazia,, nesse caso retorno 1, do contrario retorno 0.
*/
int pilha_vazia(Pilha *p){
	if(p->topo == NULL){
		return 1;
	}
	return 0;
}

/*
	Push (inserir), crio uma estrutura auxiliar para o meu n�, e digo que a informa��o desse n� ser� a informa��o
	passada por parametro, e tamb�m digo que o proximo a esse n� � o topo da minha pilha,
	e por fim atualizo o topo da minha pilha com a referencia de memoria para o meu novo n� inserido.
	A fun��o � void pois n�o preciso retornar nenhuma informa��o, apenas mantenho a referencia de memoria para a minha pilha.
*/
void push(int dado, Pilha *p){
	NO *no = (NO*) malloc (sizeof(NO));
	
	no->info = dado;
	no->prox = p->topo;
	p->topo = no;
}

/*
	Crio uma estrutura auxiliar para o meu N�, e um auxiliar para receber o valor a ser retirado
	Se a pilha estiver vazia eu lan�o um aviso e n�o retiro nada.
	Do contrario eu digo que o meu n� auxiliar receber� a referencia de memoria para o topo,
	e que meu valor auxiliar receber� a informa��o contida nesse n� auxiliar, que � a informa��o do topo.
	Por fim digo que o meu novo topo da pilha � o proximo elemento ap�s o meu n�, ou seja, o elemento anterior
	e dou um free no antigo topo, e retorno o valor.
	(O prox do meu n� � sempre o valor anterior)
*/
int pop(Pilha *p){
	NO *no;
	int value;
	
	if(pilha_vazia(p)){
		printf("Pilha vazia!\n");
	}else{
		no = p->topo;
		value = no->info;
		p->topo = no->prox;
		free(no);
		return value;
	}
}

/*
	Crio uma estrutura auxiliar que receber� a referencia de memoria contida no topo,
	e vou percorrer esse n� at� achar o NULL (fim)
	Crio uma outra estrutura para receber a referencia de memoria para o proximo n�,
	e dou um free no n� do topo, e digo que o meu proximo topo � o meu proximo n�,
	Por fim dou um free na minha pilha.
*/
void pilha_libera(Pilha *p){
	NO *no = p->topo;
	
	while(no != NULL){
		NO *no_prox = no->prox;
		free(no);
		no = no_prox;
	}
	free(p);
}


