#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"
#include "Bibli.h"

int main(){
	int op;
	Fila *main_fila = inicia_fila();
	Lista *main_lista = inicia_lista();
	Pilha *main_pilha = inicia_pilha();
	main_lista = le_lista(main_lista);
	le_pilha(main_pilha);
	le_fila(main_fila);
	
	setlocale(NULL, "");
	
	do{
		char mod_aviao[100];
		char pref_aviao[10];
		char com_aviao[100];
		char no_passageiro[100];
		int idad_passageiro, id_geral;
		print_menu();
		printf("Entre com uma opção: ");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				imprime_fila(main_fila);
			break;
			
			case 2:
				printf("Entre com o modelo do aviao: ");
				scanf(" %s", mod_aviao);
				printf("Entre com o prefixo do aviao: ");
				scanf(" %s", pref_aviao);
				printf("Entre com a companhia aerea: ");
				scanf(" %s", com_aviao);
				insere_fila(main_fila, mod_aviao, pref_aviao, com_aviao);
			break;
			
			case 3:
				printf("Remoção concluida!\n");
				remove_fila(main_fila);
			break;
			
			case 4:
				imprime_pilha(main_pilha);
			break;
			
			case 5:
				printf("Entre com a ID do aviao: ");
				scanf("%i", &id_geral);
				if(confere_id_pilha(main_pilha, id_geral) == 0){
					printf("Entre com o modelo do aviao: ");
					scanf(" %s", mod_aviao);
					printf("Entre com o prefixo do aviao: ");
					scanf(" %s", pref_aviao);
					printf("Entre com a companhia aerea: ");
					scanf(" %s", com_aviao);
					push(main_pilha, mod_aviao, pref_aviao, com_aviao, id_geral);
				}else{
					printf("ID ja em uso! Verifique os cadastros e escolha uma ID disponivel.\n");
				}
			break;
			
			case 6:
				printf("Remoção concluida!\n");
				pop(main_pilha);
			break;
			
			case 7:
				imprime_lista(main_lista);
			break;
			
			case 8:
				printf("Entre com a ID do passageiro: ");
				scanf("%i", &id_geral);
				if(confere_id_lista(main_lista, id_geral) == 0){
					printf("Entre com o nome do passageiro: ");
					scanf(" %s", no_passageiro);
					printf("Entre com a idade do passageiro: ");
					scanf("%i", &idad_passageiro);
					main_lista = insere_lista(main_lista, idad_passageiro, no_passageiro, id_geral);
				}else{
					printf("ID ja em uso! Verifique os cadastros e escolha uma ID disponivel.\n");
				}
			break;
			
			case 9:
				printf("Entre com a ID do passageiro a ser removido: ");
				scanf("%i", &id_geral);
				main_lista = remove_lista(main_lista, id_geral);
			break;
			
			case 0:
				printf("Fim do programa!");
				salva_arquivos(main_lista, main_pilha, main_fila);
			break;
		}
		system("pause");
		system("cls");
	}while(op != 0);
	
	libera_lista(&main_lista);
	libera_pilha(main_pilha);
	libera_fila(main_fila);
}
