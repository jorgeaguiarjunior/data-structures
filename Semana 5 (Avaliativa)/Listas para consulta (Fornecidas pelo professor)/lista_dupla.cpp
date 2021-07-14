#include <stdlib.h>
#include <stdio.h>
#include "lista_dupla.h"


main()
{
printf("----- Inicio do Programa -----\n");

Lista * lis = cria_lista();

verifica_lista(lis);

lis = set_lista(lis,5);
Lista * ult =  lis;
lis = set_lista(lis,4);
lis = set_lista(lis,9);
lis = set_lista(lis,2);
lis = set_lista(lis,1);

printf("\n----- Imprimindo Lista -----\n");
view_lista(lis);


Lista * tmp = find_lista(lis, 9);

if (tmp != NULL)
   printf("Endereço da lista %x\n", tmp);
else 
     printf("Valor não Localizado\n");

printf("\nApagando elemento da lista:Endereco: %x Valor %d \n",tmp,tmp->valor );
lis = delete_elemento(lis, 9);

printf("\n----- Imprimindo Lista Reversa -----\n");
view_lista_rev(ult);
verifica_lista(lis);

printf("\n----- Imprimindo Lista -----\n");
view_lista(lis);
system("pause");
    
}

