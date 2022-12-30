#include<stdio.h>
#include<stdlib.h>

int *selecao(int *num, int n){
	//Algoritmoo de Ordenação
	int i, j, min, q;
	for (i = 0; i < (n-1); i++) {
		min = i;
		for (j = (i+1); j < n; j++) {
			if(num[j] < num[min]) {
				min = j;
			}
		}
		if (i != min) {
			int swap = num[i];
			num[i] = num[min];
			num[min] = swap; 
		} 
	}
	return num;   
}
