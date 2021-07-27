#include<stdio.h>
#include<stdlib.h>

/*
	Crio uma estrutura para o Nó da minha pilha, que vai conter a informação desse nó, e um ponteiro para o proximo nó.
*/
struct NO{
	int info;
	struct NO *prox;
}typedef NO;

/*
	Crio uma estrutura para a minha Pilha propriamente dita, que vai conter um ponteiro para o nó que está no topo.
*/
struct Pilha{
	NO *topo;
}typedef Pilha;

/*
	Aloco um espaço para a minha pilha e digo que o topo é Nulo, e retorno a referencia de memoria para a minha pilha.
*/
Pilha *inicia_pilha(){
	Pilha *p = (Pilha*) malloc (sizeof(Pilha));
	p->topo = NULL;
	return p;
}

/*
	Caso o topo seja nulo, então a minha pilha está vazia,, nesse caso retorno 1, do contrario retorno 0.
*/
int pilha_vazia(Pilha *p){
	if(p->topo == NULL){
		return 1;
	}
	return 0;
}

/*
	Push (inserir), crio uma estrutura auxiliar para o meu nó, e digo que a informação desse nó será a informação
	passada por parametro, e também digo que o proximo a esse nó é o topo da minha pilha,
	e por fim atualizo o topo da minha pilha com a referencia de memoria para o meu novo nó inserido.
	A função é void pois não preciso retornar nenhuma informação, apenas mantenho a referencia de memoria para a minha pilha.
*/
void push(int dado, Pilha *p){
	NO *no = (NO*) malloc (sizeof(NO));
	
	no->info = dado;
	no->prox = p->topo;
	p->topo = no;
}

/*
	Crio uma estrutura auxiliar para o meu Nó, e um auxiliar para receber o valor a ser retirado
	Se a pilha estiver vazia eu lanço um aviso e não retiro nada.
	Do contrario eu digo que o meu nó auxiliar receberá a referencia de memoria para o topo,
	e que meu valor auxiliar receberá a informação contida nesse nó auxiliar, que é a informação do topo.
	Por fim digo que o meu novo topo da pilha é o proximo elemento após o meu nó, ou seja, o elemento anterior
	e dou um free no antigo topo, e retorno o valor.
	(O prox do meu nó é sempre o valor anterior)
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
	Crio uma estrutura auxiliar que receberá a referencia de memoria contida no topo,
	e vou percorrer esse nó até achar o NULL (fim)
	Crio uma outra estrutura para receber a referencia de memoria para o proximo nó,
	e dou um free no nó do topo, e digo que o meu proximo topo é o meu proximo nó,
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


