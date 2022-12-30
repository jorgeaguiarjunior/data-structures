#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Arvore.h"

//Revisar esse m�todo e o de inser��o, para que seja inserido sempre um galho com 2 folhas
Arv *ensina(Arv *arv){
	Arv *pergunta = NULL;
	Arv *percorre = arv;
	char questao[100], resposta_esquerda[100], resposta_direita[100];

	system("cls");
	printf("--------------ENSINANDO--------------\n\n");
	printf("Qual � a Pergunta? ");
	setbuf(stdin, NULL);
	gets(questao);
	
	printf("Resposta SIM: ");
	setbuf(stdin, NULL);
	gets(resposta_esquerda);
	
	printf("Resposta N�O: ");
	setbuf(stdin, NULL);
	gets(resposta_direita);
	
	pergunta = inserir(pergunta, questao, false);
	pergunta = inserir(pergunta, resposta_esquerda, true);
	pergunta = inserir(pergunta, resposta_direita, false);
	
	if(arv == NULL){
		return pergunta;
	}else{
		while(percorre->direita != NULL){
			percorre = percorre->direita;
		}
		percorre->direita = pergunta;
		return arv;
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Arv *arv = NULL;
	Arv *percorre;
	char questao[100];
	bool resposta;
	int valida_resposta;
	int op, exit = 0;

	
	//Sempre que for uma pergunta, ou uma resposta errada, o arv->resposta vai ser false, portanto ficar� a direita do n� anterior.
	do{
		printf("--------------MENU--------------\n");
		printf("\nDigite [1] para JOGAR\nDigite [0] para SAIR\n\n");
		printf("..: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				if(arv == NULL){ //Se a arvore estiver vazia ele insere o primeiro n�
					printf("\nFugi da escola para comer doritos e jogar vide-game,\nportanto n�o sei nada, me ensina alguma coisa!\n\n");
					system("pause");
					arv = ensina(arv);
				}else{ //Se j� tiver um elemento, ele faz a pergunta
					do{
						system("cls");
						printf("--------------JOGANDO--------------\n");
						exit = 0;
						printf("\nPergunta: \n%s", percorre->conteudo);
						printf("\nResposta [1] SIM | [2] N�O: \n");
						printf("..: ");
						scanf("%d", &valida_resposta);
				
						if(valida_resposta == 1){ //Se a resposta para a pergunta for SIM, ele entra no IF
							percorre = percorre->esquerda; //Eu ando mais uma folha a esquerda
							printf("\nEssa � facil, voc� pensou em ( %s )\n\n", percorre->conteudo);
							exit++; //Somo um ao exit e saio do loop
							system("pause");
						}else{//Se a reposta for N�O e verifico se � a outra resposta
							percorre = percorre->direita; //Eu ando uma folha a direita
							printf("\n� um %s?", percorre->conteudo);
							printf("\nResposta [1] SIM | [2] N�O: \n");
							printf("..: ");
							scanf("%d", &valida_resposta);
							
							if(valida_resposta == 1){ //Se for a resposta da direita eu finalizo
								printf("\nEu sabia desde o inicio que era um ( %s ),\ns� estava te testando...\n\n", percorre->conteudo);
								exit++; //Somo um no exit e saio do loop
								system("pause");
								system("cls");
							}
							
							if(valida_resposta == 2){ //Caso n�o seja a folha da direita
								if(percorre->direita == NULL){ //Caso a folha da direita estiver vazia, ent�o eu ensino o algoritmo novamente
									printf("Ok, eu admito, n�o sei a resposta... Adicione mais uma pergunta para me ajudar a achar a resposta...\n\n");
									system("pause");
									arv = ensina(arv);
									printf("\nObrigado pelos ensinamentos... Vamos de novo!\n\n");
									system("pause");
									exit++; //Somo um no exit e saio do loop
								}
								percorre = percorre->direita; //Se tiver alguem ainda, eu ando mais um a direita
							}
						}
						system("cls");	
					}while(exit == 0);
				}
				break;
			case 0:
				printf("\nJ� cansou? Ent�o bye bye!\n\n");
				system("pause");
				system("cls");
				break;
			default:
				printf("Opcao invalida! Entre com uma alternativa valida!\n\n");
				system("pause");
				system("cls");
				break;
		}
		system("cls");
		percorre = arv;
	}while(op != 0);

}
