#include <stdlib.h>
#include <stdio.h>

typedef struct lista  Lista;

struct lista
{
       int valor; 
       struct lista * proximo; 
       };

//Opera��o Criacao 
Lista * cria_lista(Lista * l)
{
 return(NULL);
}



//Opera��o SET - setar valor da Lista
Lista * set_lista(Lista * l, int a)
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 {
   novo->valor = a; 
   
   //Verifica se eh o unico elemento
   if (l == NULL)
   {
   	novo->proximo = novo;
   }
   else 
   {
   //Atualiza o Ultimo elemento
   	novo->proximo = l->proximo;
    l->proximo = novo;
	}
   
 }
 return(novo);
}

//Mosta Lista
void view_lista(Lista * l)
{
Lista * pl = l;

if (l != NULL) do { /* se n�o vazia , percorre */

	printf("%d\n", l->valor); /* imprime informa��o do n� */
	l = l->proximo; /* avan�a para o pr�ximo n� */

	} while (pl != l );
}

//Verifica se a lista est� Vazia
int verifica_lista(Lista * l)
{
if (l == NULL)    
   printf("\nLista Vazia\n"); 
else
    printf("\nLista nao vazia\n"); 
}

//Procura um Valor na Lista
Lista * find_lista(Lista * l, int argumento)
{
     Lista * pl =l;
	 if (pl != NULL) do { /* se n�o vazia , percorre */
  			if (pl->valor == argumento)
             	return (pl);
			pl = pl->proximo; /* avan�a para o pr�ximo n� */
	} while (pl != l );
    return(NULL);
}


//Deletar Valor na lista
Lista * delete_elemento(Lista * l, int argumento)
{
    Lista * endereco_aser_deletado=NULL;
    Lista * endereco_anterior=l;
    
	Lista * pl =l;
		 if (l != NULL) do { 
	  			if (l->valor == argumento)
	  			{
					endereco_aser_deletado = l;
				 	break;
				}
				endereco_anterior = l;
				l = l->proximo; 
			} while (pl != l );

      //Verifica se nao Achou
	  if (endereco_aser_deletado == NULL)
      {
         printf ("Elemento nao localizado!\n"); 
         return(pl);
      }
      //Verifica se l = endereco_aser_deletado
      //Entao precisa localizar o anterior
	  if (l=endereco_anterior) do { 
	  			endereco_anterior = l;
				l = l->proximo;
	  			if (l->valor == argumento)
	  			{
					endereco_aser_deletado = l;
				 	break;
				}
				endereco_anterior = l;
				l = l->proximo; 
			} while (pl != l );
	  
	  
	  endereco_anterior->proximo = l->proximo;
      free(endereco_aser_deletado);
      return(endereco_anterior->proximo);
}


//Liberar a lista
Lista * free_lista(Lista * pl)
{
     	Lista * inicio = pl;
		 if (pl != NULL) do { 
	  		        Lista * t = pl->proximo;
					pl = NULL;
           			free(pl);	
					pl = t; 
			} while (pl != inicio );
return (NULL);
 }

