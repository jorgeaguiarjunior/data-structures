#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

int main(){
	Fila *main_fila = inicia_fila();

	insere_fila(main_fila, 1);
	insere_fila(main_fila, 2);
	insere_fila(main_fila, 3);
	insere_fila(main_fila, 4);
	insere_fila(main_fila, 5);
	
	imprime_fila(main_fila);
	
	printf("Removido o valor: %i\n", remove_fila(main_fila));
	printf("Removido o valor: %i\n", remove_fila(main_fila));
	printf("Removido o valor: %i\n", remove_fila(main_fila));
	
	imprime_fila(main_fila);
	
	libera_fila(main_fila);
}
