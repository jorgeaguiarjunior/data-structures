#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"
int main(){
	pilha *p;
	
	p = pilha_inicia(p);
	
	push(p, 1);
	push(p, 2);
	push(p, 3);
	
	int aux;
	aux = pop(p);
	printf("\nSaiu: %i", aux);
		aux = pop(p);
	printf("\nSaiu: %i", aux);
		aux = pop(p);
	printf("\nSaiu: %i", aux);
		aux = pop(p);
	printf("\nSaiu: %i", aux);
}
