#include <stdio.h>
#include <stdlib.h>

//Estrutura para a minha lista encadeada
struct list{
	int info;
	struct list *prox;
}typedef list;

//Método para iniciar a minha lista como nula
list *inicialize_list(){
	return NULL;
}

//Método para conferir se a lista está vazia
int check_list(list *l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*
	Método para adicionar um valor a lista, está errado de acordo com o enunciado (Com ordem de inserção):
	Eu crio e aloco um espaço para o meu novo elemento (new_element), e verifico se a minha lista (l) está vazia (NULL)
	Caso ela esteja vazia, eu adiciono uma informação para o meu novo elemento (new_elememt),
	e digo que o proximo a ele é NULL, ou seja, minha lista nula (l),
	e retorno a referencia de memoria para o meu novo elemento (new_element).
	Caso a lista não esteja vazia, eu crio uma lista auxiliar (aux),
	que vai receber a referencia de memoria para o primeiro elemento da minha lista (l),
	e usarei esse auxiliar para percorrer até o fim não nulo da lista, 
	chegando ao fim da lista eu informo o valor para o meu novo elemento, e digo que o
	proximo ao meu axiliar é o meu novo elemento, e retorno a referencia de memoria para o primeiro elemento, ou seja, minha lista (l).

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
	Método de inserir elementos da forma correta, de acordo com o enunciado. (Com ordem de valores).
	Primeiro eu crio um ponteiro para o meu novo elemento (new_element), e já aloco um espaço de memoria para ele.
	Após isso eu verifico se a minha lista está vazia, ou se a informação da minha lista é maior que a informação passada por parametro.
	Caso alguma dessas situações seja verdadeira, eu insiro o novo elemento no inicio da lista.
	Do contrario eu crio um ponteiro auxiliar para percorrer a minha lista,
	e vou verificando se o proximo a ele é nulo, e também verifico se é maior que o valor do parametro, do contrario eu continuo o for,
	sempre indo para o proximo elemento.
	Se o proximo elemento for nulo, eu insiro no final normalmente, 
	passando o valor para o meu new_element, dizendo que o proximo ao meu novo elemento é NULL e dizendo que o proximo ao meu aux é o
	new element, e retorno a referencia de memoria para o primeiro elemento.
	Se o proximo elemento ao meu auxiliar tiver o valor maior ou igual ao passado por parametro, eu digo que o 
	new_element recebe a informação passada por parametro, depois digo que o proximo a ele é o proximo ao meu auxiliar,
	para assim deixar ele no meio, e digo que o proximo ao meu auxiliar é o meu new_element, 
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
	Método para printar a lista:
	Uso um auxiliar para não perder a referencia de memoria para o primeiro nó da lista,
	percorro o meu auxiliar até que ele seja nulo.
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
	Método para deletar um valor da lista:
	Uso um auxiliar para não perder a referencia de memoria para o primeiro nó da lista,
	Verifico se a primeira posição já contem o valor igual ao que eu quero deletar, se sim, digo que a referencia de memoria para
	a minha lista é o proximo nó ao meu auxiliar, dou um free no endereço de memoria do meu auxiliar e retorno a minha lista
	com o novo endereço de memoria.
	Caso não seja a primeira posição, eu percorro o meu auxiliar até que ele seja nulo, 
	ou até que a informação contida no nó seja igual a informação passada por parametro.
	O parametro fará referencia a informação contida no proximo nó ao nó atual.
	crio uma lista auxiliar (del) que vai receber o endereço de memoria a ser limpo,
	digo que o meu novo proximo é o proximo desse auxiliar e dou free no nó del,
	por fim eu retorno a minha lista l, pois ela contem a referencia para a primeira posição.
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

//Método para limpar a lista
void *free_list(list **pl){
	while (*pl != NULL)
    {
        list * t = (*pl)->prox;
        *pl = NULL;
        free(*pl);
        *pl = t;
    }
}

