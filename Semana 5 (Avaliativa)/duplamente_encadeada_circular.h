#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista{
	int matricula;
	char nome[100];
	struct lista *anterior;
	struct lista *proximo;
}typedef lista;

lista *cria_lista(void){
	return (NULL);
}

//Verifica se a lista est� Vazia
int verifica_lista(lista * l)
{
if (l == NULL)    
   printf("\nLista Vazia\n"); 
else
    printf("\nLista nao vazia\n"); 
}

/*
	Fun��o para inser��o em uma lista duplamente encadeada e circular:
	1� Aloco um espa�o de memoria para o meu novo n� da lista (novo);
	2� Insiro as informa��es passadas por parametro (matricula e nome) nesse n�;
	3� Caso a lista passada por parametro (l), seja Nula, ou seja, vazia, 
	eu apenas digo que o proximo e o anterior ao meu novo n� � ele mesmo, a final, s� h� ele de n� da lista.
	4� Caso a lista passada por parametro (l) n�o seja nula, ou seja, tenha algum n� inserido,
	eu digo que o ultimo elemento � o anterior a referencia principal da minha lista,
	depois digo que o proximo ao meu novo � a minha lista;
	que o anterior ao meu novo elemento � o meu ultimo;
	o proximo ao meu ultimo � meu novo;
	e por fim digo que o anterior a minha lista � meu novo, e retorno a referencia de memoria para a minha lista.
*/
lista *set_lista(lista *l, int mat, char *nom){
	lista *novo = (lista*) malloc (1 * sizeof(lista));
	
	novo->matricula = mat;
	strcpy(novo->nome, nom);
	
	if(l == NULL){
		novo->proximo = novo;
		novo->anterior = novo;
		return novo;
	}else{
		lista *ultimo = l->anterior;
		novo->proximo = l;
		novo->anterior = ultimo;
		ultimo->proximo = novo;
		l->anterior = novo;
		return l;
	}
}

/*
	1� Verifico se a lista est� vazia, se estiver vazia, mando um aviso;
	2� Caso tenha informa��es na lista, eu percorro at� o final da mesma e verifico se a matricula passada por parametro
	bate com a matricula de algum dos registros;
	3� Se a matricula for compativel, ent�o eu retorno a referencia de memoria para o respectivo registro;
	4� Se chegarmos ao fim da lista e n�o localizarmos o registro, ent�o eu retorno NULL.
*/
lista *pesquisa_lista(lista *l, int mat){
	lista *aux = l;
	
	if(l == NULL){
		printf("Lista vazia!\n");
	}else{
		do{
			if(aux->matricula == mat){
				return aux;
			}
			aux = aux->proximo;
		}while(aux != l);
		
		return NULL;
	}
}

/*
	1� Verifico se a lista est� vazia, se estiver, eu mando um aviso.
	2� Caso n�o esteja vazia, eu percorro a lista at� o fim ou at� localizar a matricula 
	3� Ao encontrar o elemento a ser excluido, eu modifico o proximo do meu elemento anterior
	e digo que o proximo a ele � o proximo ao meu elemento a ser excluido,
	depois eu digo que o anterior ao proximo elemento do meu elemento a ser excluido � o anterior do meu elemento a ser excluido.
	4� Verifico se o proximo ao meu elemento a ser excluido � ele mesmo, se for, ent�o ele � o ultimo elemento
	Nesse caso eu retorno NULL.
	5� Se n�o for o ultimo, ent�o eu verifico se � o primeiro elemento, nesse caso eu retorno o proximo a ele
	e dou free no elemento a ser excluido
	6� Caso nao seja o primeiro nem o ultimo elemento, eu apenas dou free e retorno a referencia para o meu primeiro elemento.
*/
lista *remove_lista(lista *l, int mat){
	lista *aux = l;
	
	if(l == NULL){
		printf("Lista vazia!\n");
	}else{
		do{
			if(aux->matricula == mat){
				aux->anterior->proximo = aux->proximo;
				aux->proximo->anterior = aux->anterior;
				
				if(aux->proximo == aux){//Verifico se estou excluindo o ultimo elemento.
					free(aux);
					printf("Registro excluido com sucesso!\n");
					return NULL;
				}else if(l == aux){ //Verifico se estou excluindo o primeiro elemento
					l = aux->proximo;
					free(aux);
					printf("Registro excluido com sucesso!\n");
					return l;
				}else{ // Caso contrario eu apenas retorno a referencia para o "primeiro" elemento
					free(aux);
					printf("Registro excluido com sucesso!\n");
					return l;
				}
			}
			aux = aux->proximo;
			
		}while(aux != l);
		
		printf("Informacao nao localizada!\n");
		return l;
	}
}

void print_lista(lista *l){
	
	if(l == NULL){
		printf("Lista vazia!\n");
	}else{
		lista *aux = l;
		do{
			printf("Matricula: %i \nNome: %s\n\n", aux->matricula, aux->nome);
			aux = aux->proximo;
		}while(aux != l);
	}
}

//Liberar a lista
lista *free_lista(lista * pl){
 	lista * inicio = pl;
	if (pl != NULL) 
	do { 
        lista *t = pl->proximo;
		pl = NULL;
		free(pl);	
		pl = t; 
	}while(pl != inicio );
	return (NULL);
 }
