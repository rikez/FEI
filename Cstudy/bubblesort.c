#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaLinear(int v[], int n, int valor) {
	if(n <= 0) return -1;
	if(valor==v[n])return valor;
	return buscaLinear(v,n-1,valor);
}

/*int buscaLinearMenorNumero(int v[], int n) {
 //if(n < 0) return -1;
 if(n == 0) return v[0];
 int aux;
 if(v[n-1] < v[n-2]) {
 	aux = v[n-1];
 	v[n-1] = v[n-2];
 	v[n-2]=aux;
 }
 buscaLinearMenorNumero(v, n-1);
}*/

int menorNum(int v[], int i, int f, int aux, int min) {
	if(i == f) return min;

	if(v[i] < min) {
		min = v[i];	
		aux = i + 1;
	}
	return menorNum(v, i+1, f, aux, min);
}

void merge(int v[], int inicio, int metade, int fim) {
	int tamanhoAtual = fim - inicio + 1;
	int *v2 = malloc(sizeof(int) * tamanhoAtual);
	int copiaInicio = inicio;
	int metadeFim = metade+1;
	int indice = 0;
	while(metadeFim <= fim || copiaInicio <= metade) {
		if(metadeFim <= fim && (copiaInicio <= metade && v[metadeFim] < v[copiaInicio] || copiaInicio > metade)) {
			v2[indice] = v[metadeFim];
			metadeFim++;
		} else {
			v2[indice] = v[copiaInicio];
			copiaInicio++;
		}
		indice++;
	}
	memcpy(v+inicio, v2, sizeof(int) * tamanhoAtual);
	
	free(v2);
}

void mergeSort(int v[], int inicio, int fim) {
	if(inicio == fim) return;
	int metade = (inicio + fim)/2;
	mergeSort(v, inicio, metade);
	mergeSort(v, metade+1, fim);
	merge(v, inicio, metade, fim);
}

void bubbleSort(int *v, int tam) {
	int i;
	int aux;
	if(tam > 0) {
		for(i = 0; i < tam-1; i++) {
			if(v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		bubbleSort(v, tam-1);
	}
}

int main() {
	int array[10] = {9,8,7,6,4,-50,-20,7,9,-90};
	int i = buscaLinear(array, 10, -1000);
	printf("N: %d\n", i);
	
	/*int j = buscaLinearMenorNumero(array, 10);
	printf("N: %d\n", j);*/
	
	int j = menorNum(array, 1, 10, 0, array[0]);
	printf("N: %d\n", j);
	
	/*mergeSort(array, 0, 9);
	for(i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}*/
/*	int aux;
	for(i=0; i < 9; i++) {
		for(j=0;j < 9;j++) {
			if(array[j] > array[j+1]) {
				aux = array[j];
				array[j]=array[j+1];
				array[j+1] = aux;
			}
		}
	}*/
	
	//bubbleSort(array, 10);
	for(i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}
