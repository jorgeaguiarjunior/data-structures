#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
	int id;
	char nome[100];
	int idade;
	Lista *prox;
}Lista;

Lista *inicia_lista(){
	return NULL;
}

int verifica_lista(Lista *l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

Lista *insere_lista(Lista *l, int idade_passageiro, char *nome_passageiro, int id_passageiro){
	Lista *new_element = (Lista*) malloc (1 * sizeof(Lista));
	
	if(verifica_lista(l) == 1 || l->idade <= idade_passageiro){ 
		new_element->idade = idade_passageiro;
		new_element->id = id_passageiro;
		strcpy(new_element->nome, nome_passageiro);
		new_element->prox = l;
		return new_element;
	}else{
		Lista *aux = l;
		for( ; (verifica_lista(aux->prox) != 1 && aux->prox->idade > idade_passageiro); aux = aux->prox);
	
		if(verifica_lista(aux->prox) == 1){ 
			new_element->idade = idade_passageiro;
			new_element->id = id_passageiro;
			strcpy(new_element->nome, nome_passageiro);
			new_element->prox = NULL;
			aux->prox = new_element;
			return l;
		}
		
		if(aux->prox->idade <= idade_passageiro){ 
			new_element->idade = idade_passageiro;
			new_element->id = id_passageiro;
			strcpy(new_element->nome, nome_passageiro);
			new_element->prox = aux->prox;
			aux->prox = new_element;
			return l;
		}
		
	}
}

void imprime_lista(Lista *l){
	system("cls");
	Lista *aux = l;
	printf("--------------------------------------------------------\n\n");
	if(verifica_lista(l) == 1){
		printf("Lista vazia!\n\n");
	}else{
		printf("Lista de passageiros:\n\n");
		printf("--------------------------------------------------------\n\n");
		for(aux = l; verifica_lista(aux) != 1; aux = aux->prox){
			printf("ID: %i\nNome: %s\nIdade: %i\n\n", aux->id, aux->nome, aux->idade);
		}	
	}
	printf("--------------------------------------------------------\n\n");
}

Lista *procura_lista(Lista *l, int id_passageiro){
	Lista *aux;
	
	for(aux = l; verifica_lista(aux) != 1; aux = aux->prox){
		if(aux->id == id_passageiro){
			return aux;
		}
	}
	return NULL;
}

Lista *remove_lista(Lista *l, int id_passageiro){
	Lista *aux = l;
	Lista *del;
	
	if(aux->id == id_passageiro){
		l = aux->prox;
		free(aux);
		return l;
	}
	
	for( ; verifica_lista(aux) != 1; aux = aux->prox){
		if(aux->prox->id == id_passageiro){
			del = aux->prox;
			aux->prox = del->prox;
			free(del);
			return l;
		}
	}
}

int confere_id_lista(Lista *l, int id){
	Lista *percorre = l;
	
	while(percorre != NULL){
		if(percorre->id == id){
			return 1;
		}
		percorre = percorre->prox;
	}
	return 0;
}

void *libera_lista(Lista **pl){
	while (*pl != NULL)
    {
        Lista * t = (*pl)->prox;
        *pl = NULL;
        free(*pl);
        *pl = t;
    }
}
