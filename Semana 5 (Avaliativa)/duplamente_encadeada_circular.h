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

//Verifica se a lista está Vazia
int verifica_lista(lista * l)
{
if (l == NULL)    
   printf("\nLista Vazia\n"); 
else
    printf("\nLista nao vazia\n"); 
}

/*
	Função para inserção em uma lista duplamente encadeada e circular:
	1º Aloco um espaço de memoria para o meu novo nó da lista (novo);
	2º Insiro as informações passadas por parametro (matricula e nome) nesse nó;
	3º Caso a lista passada por parametro (l), seja Nula, ou seja, vazia, 
	eu apenas digo que o proximo e o anterior ao meu novo nó é ele mesmo, a final, só há ele de nó da lista.
	4º Caso a lista passada por parametro (l) não seja nula, ou seja, tenha algum nó inserido,
	eu digo que o ultimo elemento é o anterior a referencia principal da minha lista,
	depois digo que o proximo ao meu novo é a minha lista;
	que o anterior ao meu novo elemento é o meu ultimo;
	o proximo ao meu ultimo é meu novo;
	e por fim digo que o anterior a minha lista é meu novo, e retorno a referencia de memoria para a minha lista.
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
	1º Verifico se a lista está vazia, se estiver vazia, mando um aviso;
	2º Caso tenha informações na lista, eu percorro até o final da mesma e verifico se a matricula passada por parametro
	bate com a matricula de algum dos registros;
	3º Se a matricula for compativel, então eu retorno a referencia de memoria para o respectivo registro;
	4º Se chegarmos ao fim da lista e não localizarmos o registro, então eu retorno NULL.
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
	1º Verifico se a lista está vazia, se estiver, eu mando um aviso.
	2º Caso não esteja vazia, eu percorro a lista até o fim ou até localizar a matricula 
	3º Ao encontrar o elemento a ser excluido, eu modifico o proximo do meu elemento anterior
	e digo que o proximo a ele é o proximo ao meu elemento a ser excluido,
	depois eu digo que o anterior ao proximo elemento do meu elemento a ser excluido é o anterior do meu elemento a ser excluido.
	4º Verifico se o proximo ao meu elemento a ser excluido é ele mesmo, se for, então ele é o ultimo elemento
	Nesse caso eu retorno NULL.
	5º Se não for o ultimo, então eu verifico se é o primeiro elemento, nesse caso eu retorno o proximo a ele
	e dou free no elemento a ser excluido
	6º Caso nao seja o primeiro nem o ultimo elemento, eu apenas dou free e retorno a referencia para o meu primeiro elemento.
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
