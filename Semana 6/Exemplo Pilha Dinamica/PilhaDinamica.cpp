#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

int main(){
	Pilha *main_pilha = inicia_pilha();
	int aux = 0;
	
	//Insere
	push(1, main_pilha);
	push(2, main_pilha);
	push(3, main_pilha);
	push(4, main_pilha);
	
	aux = pop(main_pilha);
	printf("Saiu %i\n", aux);
	
	aux = pop(main_pilha);
	printf("Saiu %i\n", aux);
	
	aux = pop(main_pilha);
	printf("Saiu %i\n", aux);
	
	aux = pop(main_pilha);
	printf("Saiu %i\n", aux);

	pilha_libera(main_pilha);
	
	system("pause");
}
