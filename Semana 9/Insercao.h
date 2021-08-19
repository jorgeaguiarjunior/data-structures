#include<stdio.h>
#include<stdlib.h>

int *insercao(int *v, int n){
	int i, j, chave;
    
	for(j=1; j<n; j++){
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave) {
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = chave;
	}
	
	return v;
}
