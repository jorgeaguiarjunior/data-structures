#include<stdio.h>
#include<stdlib.h>

#include "Selecao.h"
#include "Bubblesort.h"
#include "Countingsort.h"
#include "Mergesort.h"
#include "Quicksort.h"
#include "Insercao.h"


int main(){
	FILE *txt;
	int vet[200000];
	int tam = 0;
	char buffer[10];
	
	if((txt = fopen("arquivo_vetor.txt", "r")) == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		for(int i = 0; !feof(txt); i++){
			fscanf(txt, "%s", buffer);
			vet[i] = atoi(buffer);
			tam++;
		}
	}
	
	/*
		Retire o comentario do algoritmo que deseja testar, o resultado do teste em segundos está abaixo:
		Countingsort:
		0,10370666666666666666666666666667 segundos
		
		Quicksort:
		0,1404 segundos
		
		Mergesort:
		0,1788 segundos
		
		Inserção:
		32.5 segundos
		
		Seleção:
		56,896666666666666666666666666667 segundos
		
		Bubblesort:
		196.2 segundos
		
	*/
	
	//selecao(vet, tam);
	//bubblesort(vet, tam);
	//countingsort(vet, tam);
	//quicksort(vet, 0, 200000);
	//mergesort(vet, tam);
	//insercao(vet, tam);
	
	printf("Ordenado %i valores\n", tam);
		
	//Laço para printar os elementos, caso queira.
	/*for(int i = 0; i < tam; i++){
		printf("%i\n", vet[i]);
	}*/
}
