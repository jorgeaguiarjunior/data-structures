#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include <ctype.h>

struct registro{
	char palavra[100];
	int quantidade;
}typedef registro;

int main(){
	registro *reg;
	FILE *txt;
	char linha[5000];
	char *ultima;
	int index = 0;
	int encontrou = 0;
	
	//setlocale(LC_ALL, "Portuguese-Brazil");
	
	if((txt = fopen("Constituicao.txt", "r")) == NULL){
		printf("Erro ao abrir o arquivo.\n");
	}else{
		while(!feof(txt)){
			fscanf(txt, " %s", linha);
			//Desconsidero algumas pontuações para evitar erros
			for(int i=0; i<strlen(linha); i++){
				if(linha[i] == ',' || linha[i] == '.' || linha[i] == ';' || linha[i] == ':' || linha[i] == '(' || linha[i] == ')'){
					linha[i] = ' ';
				}
			}
			ultima = strtok(linha, " ");
			
			while(ultima != NULL){
				//Converto para minusculo, pois a maior parte do codigo está em minusculo, portanto serão poucas as conversões
				for(int i=0; i<strlen(ultima); i++){
					ultima[i] = tolower(ultima[i]);
				}
				
				//Caso seja a primeira ocorrencia, eu faço um malloc e adiciono um registro
				if(index == 0){
					reg = (registro *) malloc (1 * (sizeof(registro)));
					strcpy(reg[index].palavra, ultima);
					reg[index].quantidade = 1;
					index++;
				}else{
				/*Caso não seja a primeira ocorrencia, eu verifico se a palavra existe, 
				caso ela exista eu adiciono 1 a variavel ocorrencia 
				e somo 1 na quantidade do respectivo registro*/
					for(int i=0; i<index; i++){
						if(strcmp(ultima, reg[i].palavra) == 0){
							reg[i].quantidade++;
							encontrou++;
						}
					}
					/*Se a variavel ocorrencia for 0, então significa que a palavra nunca foi usada, 
					portanto adiciono um novo registro*/
					if(encontrou == 0){
						reg = (registro*) realloc (reg, sizeof(registro) * (index + 1));
						strcpy(reg[index].palavra, ultima);
						reg[index].quantidade = 1;
						index++;
					}
					//zero a variavel encontrou para começar de novo
					encontrou = 0;
				}
				ultima = strtok(NULL, " ");
			}
		}
	}
	fclose(txt);
	//Adiciono o meu registro com as palavras e as ocorrencias em um novo arquivo
	if((txt = fopen("QuantidadeDePalavras.txt", "w+")) == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		for(int i=0; i<index; i++){
			fprintf(txt, "Palavra: %s | Quantidade: %i\n", reg[i].palavra, reg[i].quantidade);
		}
	}
	fclose(txt);
	free(reg);
	return 1;
}
