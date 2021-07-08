#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(){
	
	list *main_list;
	
	main_list = inicialize_list();
	
	main_list = add_list(main_list, 6);
	main_list = add_list(main_list, 1);
	main_list = add_list(main_list, 3);
	main_list = add_list(main_list, 2);
	main_list = add_list(main_list, 3);
	main_list = add_list(main_list, 3);
	main_list = add_list(main_list, 7);
	main_list = add_list(main_list, 4);
	main_list = add_list(main_list, 9);
	main_list = add_list(main_list, 5);
	main_list = add_list(main_list, 8);
	main_list = add_list(main_list, 10);
	
	print_list(main_list);
	
	list *aux = find_list(main_list, 6);
	
	if(check_list(aux) == 1){
		printf("Valor nao encontrado\n");
	}else{
		printf("O valor %i foi encontrado no endereco de memoria %i\n", aux->info, &aux);
	}
	
	main_list = delete_value(main_list, 3); // Exclui a primeira ocorrencia
	
	print_list(main_list);
	
	free_list(&main_list);
	
	printf("A lista foi excluida!\n ");

	return 1;
}
