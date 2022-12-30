#include<stdio.h>
#include<stdlib.h>
#include "Arvore.h"

int main(){
	int op, valor;
	
	Arv *arv = NULL;
	
	do{
		printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Remover\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				printf("\nFim.\n");
				break;
			case 1:
				printf("\nDigite um valor: ");
				scanf("%d", &valor);
				arv = inserir(arv, valor);
				break;
			case 2:
				printf("\nImpressao da arvore:\n");
				imprimir(arv);
				printf("\nTamanho: %d\n", tamanho(arv));
				break;
			case 3:
				printf("Qual valor deseja buscar? ");
				scanf("%d", &valor);
				if(buscar(arv, valor)){
					printf("O valor %d foi encontrado!\n", valor);
				}else{
					printf("O valor %d nao foi encontrado!\n", valor);
				}
				break;
			case 4:
				printf("Qual valor deseja remover? ");
				scanf("%d", &valor);
				arv = remover(arv, valor);
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	}while(op != 0);
}
