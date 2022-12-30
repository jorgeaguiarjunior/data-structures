#include <stdlib.h>
#include <stdio.h>
#include "duplamente_encadeada_circular.h"

main()
{
lista * lis = cria_lista();

char nome[100];
int matricula;
int option = 0;
lista *aux;

while(option != 5){
	printf("Entre com opcao desejada:\n");
	printf("[1] Inserir\n[2] Pesquisar\n[3] Remover\n[4] Printar\n[5] Sair\n");
	scanf("%i", &option);
	
	switch(option){
		case 1:
			printf("Digite o nome: ");
			scanf(" %s", nome);
			printf("Digite a matricula: ");
				scanf("%i", &matricula);
			lis = set_lista(lis, matricula, nome);
		break;
		
		case 2:
			printf("Digite a matricula: ");
			scanf("%i", &matricula);
			aux = pesquisa_lista(lis, matricula);
			if(aux == NULL){
				printf("Registro nao localizado!\n");
			}else{
				printf("Registro localizado\nNome: %s\nMatricula: %i\n", aux->nome, aux->matricula);
			}
		break;
		
		case 3:
			printf("Digite a matricula: ");
			scanf("%i", &matricula);
			lis = remove_lista(lis, matricula);
		break;
		
		case 4:
			printf("Lista atualizada de registros:\n");
			print_lista(lis);
		break;
		
		case 5:
			printf("Fim da aplicacao!\n");
		break;
		
		default:
			printf("Entre com uma opcao valida!\n");
		break;
	}
	
	system("pause");
	system("cls");
}
//system("pause");
    
}

