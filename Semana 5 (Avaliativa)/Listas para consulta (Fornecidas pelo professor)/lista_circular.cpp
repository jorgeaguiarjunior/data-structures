#include <stdlib.h>
#include <stdio.h>
#include "lista_circular.h"


main()
{
printf("Inicio do Programa Lista Encadeda Circular\n");

Lista * lis = cria_lista(lis);

verifica_lista(lis);

lis = set_lista(lis,5);
lis = set_lista(lis,4);
lis = set_lista(lis,9);
lis = set_lista(lis,2);
lis = set_lista(lis,1);

view_lista(lis);


Lista * ultimo = find_lista(lis, 5);
if (ultimo != NULL)
   printf("Endereço da lista %x do valor %d\n", ultimo, ultimo->valor);
else 
     printf("Valor nao Localizado\n");


lis = delete_elemento(lis, 4);



view_lista(lis);

lis = free_lista(lis);

verifica_lista(lis);

system("pause");
     
      
}

