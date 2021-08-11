void print_menu(){
	printf("--------------------------------------------------------\n\n");
	printf("Sistema de Controle de Aeroporto de Litoral Norte de RS\n\n");
	printf("--------------------------------------------------------\n\n");
	printf("[1] Listar todos os aviões em Solo\n\n");
	printf("[2] Adicionar avião em solo\n\n");
	printf("[3] Remover avião em solo\n\n");
	printf("[4] Listas todos os aviões no Hangar\n\n");
	printf("[5] Adicionar avião no hangar\n\n");
	printf("[6] Remover avião no hangar\n\n");
	printf("[7] Listar todos os Passageiros\n\n");
	printf("[8] Adicionar um Passageiro\n\n");
	printf("[9] Remover um Passageiro\n\n");
	printf("[0] Sair & Salvar Dados\n\n");
	printf("--------------------------------------------------------\n");
}

Lista *le_lista(Lista *l){
	FILE *txt_lista;
	char linha[1024];
	char *ultima;
	int id_aux, idade_aux;
	char nome_aux[100];
	
	if((txt_lista = fopen("Lista-Passageiros.txt", "r")) == NULL){
		printf("Erro ao ler a lista de passageiros!\n");
	}else{
		while(!feof(txt_lista)){
			fgets(linha, 1024, txt_lista);
			
			if(linha[0] != '\000' && linha[0] != '\n'){ 
				ultima = strtok(linha, "|");
				for(int index = 0; ultima != NULL; index++){ 
					if(index == 0){
						id_aux = atof(ultima);
					}else if(index == 1){
						strcpy(nome_aux, ultima);
					}else{
						idade_aux = atof(ultima);
					}
					ultima = strtok (NULL, "|");
				}
				l = insere_lista(l, idade_aux, nome_aux, id_aux);
				memset(linha, 0, 1024);
			}
		}
	}
	fclose(txt_lista);
	return l;
}

void le_pilha(Pilha *p){
	FILE *txt_pilha;
	char linha[1024];
	char *ultima;
	int id_aux;
	char prefixo[30], modelo_aux[100], companhia_aux[100];
	
	if((txt_pilha = fopen("Avioes-Hangar.txt", "r")) == NULL){
		printf("Erro ao ler a pilha de avioes no hangar!\n");
	}else{
		while(!feof(txt_pilha)){
			fgets(linha, 1024, txt_pilha);
			
			if(linha[0] != '\000' && linha[0] != '\n'){ //Confiro se não é apenas um Enter
				ultima = strtok(linha, "|");
				for(int i=0; ultima != NULL; i++){
					if(i == 0){
						id_aux = atof(ultima);
					}else if(i == 1){
						strcpy(modelo_aux, ultima);
					}else if(i == 2){
						strcpy(prefixo, ultima);
					}else if(i == 3){
						strcpy(companhia_aux, ultima);
						ultima == NULL;
					}
					ultima = strtok(NULL, "|");
				}
				push(p, modelo_aux, prefixo, companhia_aux, id_aux);
				memset(linha, 0, 1024);
			}
		}
	}
	fclose(txt_pilha);
}

void le_fila(Fila *f){
	FILE *txt_fila;
	char linha[1024];
	char *ultima;
	char prefixo[30], modelo_aux[100], companhia_aux[100];
	
	if((txt_fila = fopen("Avioes-Solo.txt", "r")) == NULL){
		printf("Erro ao ler a fila de avioes no solo!\n");
	}else{
		while(!feof(txt_fila)){
			fgets(linha, 1024, txt_fila);
			
			if(linha[0] != '\000' && linha[0] != '\n'){ //Confiro se não é apenas um Enter
				ultima = strtok(linha, "|");
				for(int i=0; ultima != NULL; i++){
				if(i == 0){
					strcpy(modelo_aux, ultima);
				}else if(i == 1){
					strcpy(prefixo, ultima);
				}else if(i == 2){
					strcpy(companhia_aux, ultima);
				}
				ultima = strtok(NULL, "|");
			}
				insere_fila(f, modelo_aux, prefixo, companhia_aux);
				memset(linha, 0, 1024);
			}
		}
	}
	fclose(txt_fila);
}

void salva_arquivos(Lista *li, Pilha *pi, Fila *fi){
	FILE *txt_li, *txt_pi, *txt_fi;
	
	if((txt_li = fopen("Lista-Passageiros.txt", "w")) == NULL){
		printf("Erro ao salvar passageiros.\n");
	}else{
		for(Lista *aux_li = li; aux_li != NULL; aux_li = aux_li->prox){
			fprintf(txt_li, "%i|%s|%i\n", aux_li->id, aux_li->nome, aux_li->idade);
		}
	}
	fclose(txt_li);
	
	if((txt_pi = fopen("Avioes-Hangar.txt", "w")) == NULL){
		printf("Erro ao salvar avioes no hangar.\n");
	}else{
		Pilha *pi_aux = desempilhar(pi);
		for(NODO *aux_nodo = pi_aux->topo; aux_nodo != NULL; aux_nodo = aux_nodo->prox){
			fprintf(txt_pi, "%i|%s|%s|%s\n", aux_nodo->id, aux_nodo->modelo, aux_nodo->sigla, aux_nodo->companhia);
		}
	}
	fclose(txt_pi);
	
	if((txt_fi = fopen("Avioes-Solo.txt", "w")) == NULL){
		printf("Erro ao salvar avioes no solo.\n");
	}else{
		for(NO *aux_no = fi->inicio; aux_no != NULL; aux_no = aux_no->prox){
			fprintf(txt_fi, "%s|%s|%s\n", aux_no->modelo, aux_no->sigla, aux_no->companhia);
		}
	}
	fclose(txt_fi);
}
