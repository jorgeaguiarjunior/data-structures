#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	Crio uma estrutura para o N� da minha pilha, que vai conter a informa��o desse n�, e um ponteiro para o proximo n�.
*/
struct NO{
	char passos[100];
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
void push(char *dado, Pilha *p){
	NO *no = (NO*) malloc (sizeof(NO));
	
	strcpy(no->passos, dado);
	no->prox = p->topo;
	p->topo = no;
}

/*
	Crio uma estrutura auxiliar para o meu N�,
	Se a pilha estiver vazia eu lan�o um aviso e n�o retiro nada.
	Do contrario eu digo que o meu n� auxiliar receber� a referencia de memoria para o topo,
	Por fim digo que o meu novo topo da pilha � o proximo elemento ap�s o meu n�, ou seja, o elemento anterior
	e dou um free no antigo topo, e retorno o valor.
	(O prox do meu n� � sempre o valor anterior)
*/
void *pop(Pilha *p){
	NO *no;
	
	if(pilha_vazia(p) == 1){
		printf("Pilha vazia!\n");
	}else{
		no = p->topo;
		p->topo = no->prox;
		free(no);
	}
}

/*
	Printa a pilha inteira
*/
void print_pilha(Pilha *p){
	NO *percorre = p->topo;
	int index = 1;
	while(percorre != NULL){
		printf("%i - %s\n", index, percorre->passos);
		percorre = percorre->prox;
		index++;
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

/*
	Crio uma nova pilha que vai receber os valores de tr�s pra frente, ou seja, desempilhados
	e crio um n� auxiliar para percorrer os valores da minha pilha anterior.
	No fim eu libero o espa�o de memoria que estava a minha pilha antiga e retorno o novo endere�o de memoria
*/
Pilha *desempilha(Pilha *p){
	Pilha *d = inicia_pilha();
	NO *aux = p->topo;

	while(aux != NULL){
		push(aux->passos, d);
		aux = aux->prox;
	}
	//pilha_libera(p);
	return d;
}


