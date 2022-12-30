#include <stdlib.h>
#include <stdio.h>
#include "FilaEstatica.h"

int main (void)
{
	Fila *f = cria_fila();
	insere(f,1);
	insere(f,2);
	insere(f,3);
	insere(f,4);
	insere(f,5);
	insere(f,6);
	insere(f,7);
	insere(f,8);
	insere(f,9);

	imprime(f);
	printf("Primeiro elemento: %i\n", retira(f));
	insere(f,1);
	printf("Configuracao da fila:\n");
	imprime(f);
	libera(f);
	system("pause");
}
