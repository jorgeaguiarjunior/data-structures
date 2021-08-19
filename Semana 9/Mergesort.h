#include<stdio.h>
#include<stdlib.h>

void merge(int *vec, int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;
	tmp = (int*) malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1); 
	}
	mid = vecSize / 2;
	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i; 
		}else {
		   tmp[k] = vec[j];
			++j; 
		}
		++k; 
	}
	if (i == mid) {
		while (j < vecSize) {
			tmp[k] = vec[j];
			++j;
			++k; 
		} 
	} else {
		while (i < mid) {
			tmp[k] = vec[i];
			++i;
			++k; 
		}
	}
	
	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i]; 
	}
	free(tmp);
}

int *mergesort(int *vec, int vecSize) {
	int mid;
	if (vecSize > 1) {
		mid = vecSize / 2;
		mergesort(vec, mid);
		mergesort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
	return vec;
}
