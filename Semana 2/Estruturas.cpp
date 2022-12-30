#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 10

struct registro{
	int codigo;
	char nome[100];
	float saldo;
}typedef registro;

//Método simples para impressão dos registros
void imprime_correntista(registro *reg){
	
	printf("____________Todos os correntistas____________\n");
	for(int i=0; i < reg[i].codigo != NULL && i < LEN; i++){
		printf("\nCodigo: %i\n", reg[i].codigo);
		printf("Nome: %s\n", reg[i].nome);
		printf("Saldo: %.2f\n", reg[i].saldo);
	}
	printf("\n");
	system("pause");
	system("cls");
	
}

//Esse método vai procurar o registro e retornar a posicao caso encontrar, ou -1 caso não encontrar
int busca_registro(registro *reg, int cod_busca){
	
	for(int i = 0; reg[i].codigo != NULL && i < LEN; i++){
		if(reg[i].codigo == cod_busca){
			return i;
		}
	}
	return -1;
	
}

//Método responsável por executar a péracao de debito, lança um erro caso o saldo seja insuficiente ou o valor seja nulo ou negativo
char operacao_debito(registro *reg_op){
	
	int cod = NULL;
	int index = NULL;
	float valor_operacao = NULL;
	
	do{
		printf("____________Operacao de Debito____________\n\n");
		printf("Entre com o codigo do registro: ");
		scanf("%i", &cod);
		index = busca_registro(reg_op, cod);
		
		if(index > -1){
			printf("Qual o valor para debito desejado? ");
			scanf("%f", &valor_operacao);
			
			if(valor_operacao <= 0){
				printf("Por favor, entre com um valor maior que ZERO\n\n");
				system("pause");
				system("cls");
			}else if(valor_operacao > reg_op[index].saldo){
				printf("Saldo indisponivel para o debito!\n\n");
				system("pause");
				system("cls");
			}else{
				reg_op[index].saldo = reg_op[index].saldo - valor_operacao;
				system("cls");
				return 'X';
			}
		}else{
			printf("Registro nao encontrado!\n\n");
			system("pause");
			system("cls");
		}
	}while(valor_operacao <= 0 || valor_operacao > reg_op[index].saldo);
}


//Método responsável por executar a péracao de credito, lança um erro caso o valor seja nulo ou negativo
char operacao_credito(registro *reg_op){
	
	int cod = NULL;
	int index = NULL;
	float valor_operacao = NULL;
	
	do{
		printf("____________Operacao de Credito____________\n\n");
		printf("Entre com o codigo do registro: ");
		scanf("%i", &cod);
		index = busca_registro(reg_op, cod);
		if(index > -1){
			printf("Qual o valor para credito desejado? ");
			scanf("%f", &valor_operacao);
			if(valor_operacao > 0){
				reg_op[index].saldo = reg_op[index].saldo + valor_operacao;
				system("cls");
				return 'X';
			}else{
				printf("Por favor, entre com um valor positivo nao nulo.\n\n");
				system("pause");
				system("cls");
			}
		}else{
			printf("Registro nao encontrado!\n\n");
			system("pause");
			system("cls");
		}
	}while(valor_operacao <= 0);
}

//Método responsável por escolher qual a operação desejada e por colher as informações necessárias para cada operação
void operacao(registro *reg){
	char op = NULL;
	int cod = NULL;
	int index = NULL;
	float valor_operacao = NULL;
	
	do{
		printf("____________Operacoes____________\n");
		printf("\nQual operacao deseja efetuar?\n\n");
		printf("Digite (D) para Debito\nDigite (C) para Credito\nOu digite (X) para Sair\n");
		printf("-");
		scanf(" %c", &op);
	
		switch(op){
			case 'D':
				system("cls");
				op = operacao_debito(reg);
			break;
			
			case 'd':
				system("cls");
				op = operacao_debito(reg);
			break;
			
			case 'C':
				system("cls");
				op = operacao_credito(reg);
			break;
			
			case 'c':
				system("cls");
				op = operacao_credito(reg);
			break;
			
			case 'X':
				printf("Operacao finalizada!\n\n");
				system("pause");
				system("cls");
			break;
			
			case 'x':
				printf("Operacao finalizada!\n\n");	
				system("pause");
				system("cls");			
			break;
			
			default:
				printf("Entre com uma opcao valida!\n\n");
				system("pause");
				system("cls");
			break;
		}
	
	}while(op != 'X' && op != 'x');
}

int conta_registros(registro *reg){
	int qtd = 0;
	
	while(reg[qtd].codigo != 0 && qtd < LEN){
		qtd++;
	}
	
	return qtd;
}

//Método de cadastro, todos os codigo são unicos, portanto codigos repetidos não serão aceitos.
void cadastra_correntista(registro *reg){
	char valida = NULL;
	FILE *txt;
	int cod = NULL;
	int index = conta_registros(reg);
	
	if((txt = fopen("Registro.txt", "a+")) == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		while((index < LEN) && (valida != '2')){
			do{
				system("cls");
				printf("____________Cadastro de Correntistas____________\n");
			
				printf("\nCodigo do correntista, use valores positivos: ");
				scanf("%i", &cod);
				
				if(cod < 1){
					printf("Entre com um codigo maior ou igual a 1.\n");
					system("pause");
				}
			}while(cod < 1);
			
			if(busca_registro(reg, cod) == -1){
				reg[index].codigo = cod;
				printf("\nEntre com o nome do correntista: ");
				scanf(" %s", reg[index].nome);
				
				printf("\nEntre com o saldo inicial do correntista: ");
				scanf("%f", &reg[index].saldo);
				
				if(index != 0){
					fprintf(txt, "\n");
				}
				fprintf(txt, "%i;%s;%.2f", reg[index].codigo, reg[index].nome, reg[index].saldo);
				
				printf("\nEntre com qualquer tecla para CONTINUAR ou (2) Para SAIR: ");
				scanf(" %c", &valida);
				
				index++;		
			}else{
				printf("Codigo ja em uso, entre com um novo codigo.\n\n");
				system("pause");
			}
			system("cls");
		}
	}
	if(index == LEN){
		printf("____________Cadastro de Correntistas____________\n");
		printf("\nLimite de cadastros foi alcancado!\n");
		system("pause");
		system("cls");
	}
	fclose(txt);
}

//Carrega os registros salvos e retorna 0, caso não exista, retorna 1 e gera um aviso pedindo para cadastrar correntistas.
int carrega_registros(registro *reg){
	FILE *txt;
	char *ultima;
	char linha[1024];
	
	if((txt = fopen("Registro.txt", "r")) == NULL){
		printf("Voce nao possui correntistas cadastrados\n");
		return 1;
	}else{
		for(int i=0; !feof(txt); i++){
			fgets(linha, 1024, txt);
			ultima = strtok(linha, ";");
			
			for(int j = 0; ultima != NULL; j++){
				if(j == 0){
					reg[i].codigo = atof(ultima);
				}else if(j == 1){
					strcpy(reg[i].nome, ultima);
				}else{
					reg[i].saldo = atof(ultima);
				}
					ultima = strtok (NULL, ";");
			}
		}
	}
	fclose(txt);
	return 0;
}

int main(void){
	registro registro_correntista[LEN];
	memset(registro_correntista, NULL, LEN);
	int option = NULL;
	
	printf("____________Carregando Correntistas____________\n\n");
	if(carrega_registros(registro_correntista) == 1 || registro_correntista[0].codigo == NULL){
		
		printf("Para executar operacoes, cadastre alguns correntistas. \n\n");
		system("pause");
		system("cls");
		cadastra_correntista(registro_correntista);
	}
	
	system("cls");
	do{
		printf("____________Menu Principal____________\n\n");
		printf("(1) Para CADASTRAR correntistas \n(2) Para executar OPERACOES \n(3) Para IMPRIMIR correntistas \n(4) para SAIR\n");
		printf("-");
		scanf(" %c", &option);
		
		switch(option){
			case '1':
				system("cls");
				cadastra_correntista(registro_correntista);
			break;
			
			case '2':
				system("cls");
				operacao(registro_correntista);
			break;
			
			case '3':
				system("cls");
				imprime_correntista(registro_correntista);
			break;
			
			case '4':
				printf("Operacao finalizada!\n\n");
				system("pause");
				system("cls");
			break;
			
			default:
				printf("Entre com uma opcao valida!\n");
			break;
		}
	}while(option != '4' && option != '4');

}
