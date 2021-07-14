#include <stdlib.h>
#include <stdio.h>

typedef struct lista  Lista;

struct lista
{
       int valor; 
       struct lista * proximo; 
       struct lista * anterior;
       };



Lista * cria_lista(void)
{
 return (NULL);      
}

//Operação SET - setar valor da Lista
Lista * set_lista(Lista * l, int a)
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 novo->valor = a; 
 novo->proximo = l;
 novo->anterior = NULL;
 if (l != NULL)
    l->anterior = novo;
 return(novo);
}

//Mosta Lista
void view_lista(Lista * l)
{
Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          printf("Valor %d - atual: %x \t-  prox: %x \t- ant: %x\n", pl->valor, pl,  pl->proximo, pl->anterior);
      }
}

//Mosta Lista
void view_lista_rev(Lista * l)
{
Lista * pl;
      for (pl = l; pl != NULL; pl = pl->anterior)
      {
          printf("Valor %d - atual: %x \t-  prox: %x \t- ant: %x\n", pl->valor, pl,  pl->proximo, pl->anterior);
      }
}



//Verifica se a lista está Vazia
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
     Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          if (pl->valor == argumento)
             return (pl);
      }
      return(NULL);
}


//Deletar Valor na lista
Lista * delete_elemento(Lista * pl, int argumento)
{
      Lista * anterior = NULL;
      Lista * atual = pl;
      
      
      while (atual != NULL && atual->valor != argumento)
      {
            anterior = atual;
            atual = atual->proximo;
            
      }

      if (atual == NULL)
      {
         printf ("Elemento noo localizado!\n"); 
         return(pl);
      }
      
      if (anterior == NULL)
          pl = pl->proximo; 
      else
      {
          atual->anterior->proximo = atual->proximo;
          atual->proximo->anterior = atual->anterior;
      }
      
      free(atual);
      return(pl);
}


//Liberar a lista
void free_lista(Lista ** pl)
{
      while (*pl != NULL)
      {
           Lista * t = (*pl)->proximo;
           *pl = NULL;
           free(*pl);
           *pl = t;
      }
 }


void imprime_rev (Lista* l)
{
 Lista* p = l; 
if (p) 
{ 
 do {
   printf("%d\n", p->valor); 
   p = p->anterior;
   }
  while (p != l);
} 
}

