#include<stdio.h>
#include<stdlib.h>

int *bubblesort(int *v, int n){
	//Algoritmo de Ordenação 
	int i, j = 0, aux;
	while (j < n)
	{
		for(i = 0; i < n-1; i++)
			if(v[i] > v[i + 1]){
				aux=v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		j++;
	}
	return v;
}
