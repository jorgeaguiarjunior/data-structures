#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(){
	
	list *main_list;
	
	main_list = inicialize_list();
	
	main_list = add_list(main_list, 1);
	main_list = add_list(main_list, 2);
	main_list = add_list(main_list, 3);
	main_list = add_list(main_list, 4);
	main_list = add_list(main_list, 5);
	
	print_list(main_list);
	
	list *aux = find_list(main_list, 5);
	
	if(check_list(aux) == 5){
		printf("Lista nao encontrada");
	}else{
		printf("O valor %i foi encontrado no endereco de memoria %i\n", aux->info, &aux);
	}
	
	main_list = delete_value(main_list, 3);
	
	print_list(main_list);
	
	free_list(&main_list);
	
	printf("A lista foi excluida!\n ");

	return 1;
}
