#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
	int conteudo;
	struct arvore *esquerda;
	struct arvore *direita;
}Arv;

Arv *inserir(Arv *raiz, int valor){
	if(raiz == NULL){
		Arv *novo = (Arv*) malloc (sizeof(Arv));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		return novo;
	}else{
		/*
			Essa arvore não armazena numeros repetidos, portanto, se for necessário armazenar algum numero repetido
			devemos escolher em qual dos lados desejamos guardar os valores que se repetem e alterar nos if's abaixo.
		*/
		if(valor < raiz->conteudo){
			raiz->esquerda = inserir(raiz->esquerda, valor);
		}
		if(valor > raiz->conteudo){
			raiz->direita = inserir(raiz->direita, valor);
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

bool buscar(Arv *raiz, int chave){
	if(raiz != NULL){
		if(raiz->conteudo == chave){
			return true;
		}
		if(chave < raiz->conteudo){
			return buscar(raiz->esquerda, chave);
		}
		return buscar(raiz->direita, chave);
	}
	return false;
}

Arv *remover(Arv *raiz, int elemento){
	if(raiz == NULL){ //Caso a arvore esteja vazia retorna NULL
		return NULL;
	}else{ //Do contrario, verifico se o conteudo é o que desejo remover
		if(raiz->conteudo == elemento){ //Remove nó folha
			if(raiz->esquerda == NULL && raiz->direita == NULL){ //Se o nó for um nó folha, ou seja, sem ninguém depois, eu simplesmente dou free
				free(raiz);
				return NULL;
			}else{ //Remove nó com apenas um filho
				if(raiz->esquerda == NULL || raiz->direita == NULL){ //Eu verifico qual dos lados possui um elemento
					Arv *aux; //Ponteiro auxiliar para guarda o nó do filho, para ele ser o filho do nó a cima.
					if(raiz->esquerda != NULL){ //Verifico se o nó filho está na esquerda e salvo no aux
						aux = raiz->esquerda;
					}else{ //Verifico se o filho está na direita e salvo no aux
						aux = raiz->direita;
					}
					free(raiz);
					return aux; //Retorno meu auxiliar que vai ficar abaixo do nó anterior ao excluido.
				}else{ //Caso o nó tenha informação de ambos os lados eu procuro o elemento mais proximo do valor.
					Arv *aux = raiz->esquerda;
					while(aux->direita != NULL){
						aux = aux->direita;
					}
					raiz->conteudo = aux->conteudo;
					aux->conteudo = elemento;
					raiz->esquerda = remover(raiz->esquerda, elemento);
					return raiz;
				}
			}
		}else{ //Do contrario verifico se o elemento é menor ou maior do que o que desejo remover, indo pra esquerda ou direita dependendo do caso
			if(elemento < raiz->conteudo){
				raiz->esquerda = remover(raiz->esquerda, elemento);
			}else{
				raiz->direita = remover(raiz->direita, elemento);
			}
			return raiz;
		}
	}
}

void imprimir(Arv *raiz){ //Essa função imprime os elementos de acordo com sua posição na arvore, ou seja, quem está a direita e esquerda de quem.
	if(raiz != NULL){
		imprimir(raiz->esquerda);
		printf("%d", raiz->conteudo);
		imprimir(raiz->direita);
	}
}
