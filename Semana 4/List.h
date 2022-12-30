#include <stdio.h>
#include <stdlib.h>

//Estrutura para a minha lista encadeada
struct list{
	int info;
	struct list *prox;
}typedef list;

//M�todo para iniciar a minha lista como nula
list *inicialize_list(){
	return NULL;
}

//M�todo para conferir se a lista est� vazia
int check_list(list *l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*
	M�todo para adicionar um valor a lista, est� errado de acordo com o enunciado (Com ordem de inser��o):
	Eu crio e aloco um espa�o para o meu novo elemento (new_element), e verifico se a minha lista (l) est� vazia (NULL)
	Caso ela esteja vazia, eu adiciono uma informa��o para o meu novo elemento (new_elememt),
	e digo que o proximo a ele � NULL, ou seja, minha lista nula (l),
	e retorno a referencia de memoria para o meu novo elemento (new_element).
	Caso a lista n�o esteja vazia, eu crio uma lista auxiliar (aux),
	que vai receber a referencia de memoria para o primeiro elemento da minha lista (l),
	e usarei esse auxiliar para percorrer at� o fim n�o nulo da lista, 
	chegando ao fim da lista eu informo o valor para o meu novo elemento, e digo que o
	proximo ao meu axiliar � o meu novo elemento, e retorno a referencia de memoria para o primeiro elemento, ou seja, minha lista (l).

list *add_list(list *l, int value){
	list *new_element = (list*) malloc (sizeof(list));;
	
	if(check_list(l) == 1){
		new_element->info = value;
		new_element->prox = l;
		return new_element;
	}
	
	list *aux;
	for(aux = l; check_list(aux->prox) != 1; aux = aux->prox);
	new_element->info = value;
	new_element->prox = NULL;
	aux->prox = new_element;
	return l;
}
*/

/*
	M�todo de inserir elementos da forma correta, de acordo com o enunciado. (Com ordem de valores).
	Primeiro eu crio um ponteiro para o meu novo elemento (new_element), e j� aloco um espa�o de memoria para ele.
	Ap�s isso eu verifico se a minha lista est� vazia, ou se a informa��o da minha lista � maior que a informa��o passada por parametro.
	Caso alguma dessas situa��es seja verdadeira, eu insiro o novo elemento no inicio da lista.
	Do contrario eu crio um ponteiro auxiliar para percorrer a minha lista,
	e vou verificando se o proximo a ele � nulo, e tamb�m verifico se � maior que o valor do parametro, do contrario eu continuo o for,
	sempre indo para o proximo elemento.
	Se o proximo elemento for nulo, eu insiro no final normalmente, 
	passando o valor para o meu new_element, dizendo que o proximo ao meu novo elemento � NULL e dizendo que o proximo ao meu aux � o
	new element, e retorno a referencia de memoria para o primeiro elemento.
	Se o proximo elemento ao meu auxiliar tiver o valor maior ou igual ao passado por parametro, eu digo que o 
	new_element recebe a informa��o passada por parametro, depois digo que o proximo a ele � o proximo ao meu auxiliar,
	para assim deixar ele no meio, e digo que o proximo ao meu auxiliar � o meu new_element, 
	e retorno a referencia para o primeiro elemento.
*/
list *add_list(list *l, int value){
	list *new_element = (list*) malloc (1 * sizeof(list));
	
	if(check_list(l) == 1 || l->info > value){ // Insiro no inicio
		new_element->info = value;
		new_element->prox = l;
		return new_element;
	}else{
		list *aux = l;
		for( ; (check_list(aux->prox) != 1 && aux->prox->info < value); aux = aux->prox);
	
		if(check_list(aux->prox) == 1){ // Insiro no final
			new_element->info = value;
			new_element->prox = NULL;
			aux->prox = new_element;
			return l;
		}
		
		if(aux->prox->info >= value){ // Insiro no meio
			new_element->info = value;
			new_element->prox = aux->prox;
			aux->prox = new_element;
			return l;
		}
		
	}
}

/*
	M�todo para printar a lista:
	Uso um auxiliar para n�o perder a referencia de memoria para o primeiro n� da lista,
	percorro o meu auxiliar at� que ele seja nulo.
*/
void print_list(list *l){
	list *aux = l;
	
	for(aux = l; check_list(aux) != 1; aux = aux->prox){
		printf("%i\n", aux->info);
	}
}

list *find_list(list *l, int value){
	list *aux;
	
	for(aux = l; check_list(aux) != 1; aux = aux->prox){
		if(aux->info == value){
			return aux;
		}
	}
	return NULL;
}

/*
	M�todo para deletar um valor da lista:
	Uso um auxiliar para n�o perder a referencia de memoria para o primeiro n� da lista,
	Verifico se a primeira posi��o j� contem o valor igual ao que eu quero deletar, se sim, digo que a referencia de memoria para
	a minha lista � o proximo n� ao meu auxiliar, dou um free no endere�o de memoria do meu auxiliar e retorno a minha lista
	com o novo endere�o de memoria.
	Caso n�o seja a primeira posi��o, eu percorro o meu auxiliar at� que ele seja nulo, 
	ou at� que a informa��o contida no n� seja igual a informa��o passada por parametro.
	O parametro far� referencia a informa��o contida no proximo n� ao n� atual.
	crio uma lista auxiliar (del) que vai receber o endere�o de memoria a ser limpo,
	digo que o meu novo proximo � o proximo desse auxiliar e dou free no n� del,
	por fim eu retorno a minha lista l, pois ela contem a referencia para a primeira posi��o.
*/
list *delete_value(list *l, int value){
	list *aux = l;
	list *del;
	
	if(aux->info == value){
		l = aux->prox;
		free(aux);
		return l;
	}
	
	for( ; check_list(aux) != 1; aux = aux->prox){
		if(aux->prox->info == value){
			del = aux->prox;
			aux->prox = del->prox;
			free(del);
			return l;
		}
	}
}

//M�todo para limpar a lista
void *free_list(list **pl){
	while (*pl != NULL)
    {
        list * t = (*pl)->prox;
        *pl = NULL;
        free(*pl);
        *pl = t;
    }
}

