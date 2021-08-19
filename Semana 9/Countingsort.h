#include<stdio.h>
#include<stdlib.h>

int *countingsort(int *array, int size){

	int i, min, max;
	min = max = array[0];

	for(i = 1; i < size; i++){
		if (array[i] < min)
		min = array[i];
		else if (array[i] > max)
			max = array[i]; 
	}
	int range = max - min + 1;
	int *count = (int *) malloc(range * sizeof(int));
	//Marca Todas as prosições com Zero
	for(i = 0; i < range; i++){
		count[i] = 0;
	}
	//Marca as posições ocupadas
	for(i = 0; i < size; i++){
		count[ array[i] - min ]++;
	}

	int j, z = 0;
	//Array recebe as posioes ocupadas
	for(i = min; i <= max; i++){
		for(j = 0; j < count[ i - min ]; j++)
		array[z++] = i;
	}

	free(count);
	return array;
}
