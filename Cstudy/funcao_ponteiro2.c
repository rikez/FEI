#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	int cod;
	char prod[10];
}produto;

int (*comparable[2])(produto , produto);

void swap(produto * a, produto *b) {
	produto c = *a;
	*a = *b;
	*b = c;
}

void ordenaLista(produto *v, int tam, int (*comparable)) {
	int i, j;
	for(i=0; i < tam-1; i++) {
		for(j=0; j< tam-1; j++) {
			if(comparable(v[j], v[j+1])) swap(&v[j], &v[j+1]);
		}
	}
}

int porCod(produto a, produto b) {
	return a.cod > b.cod;
}

int porCodDesc(produto a, produto b) {
	return a.cod < b.cod;
}

int main() {
	produto x[5];
	x[0].cod = 1;
	strcpy(x[0].prod, "XXX0");
	x[1].cod = 0;
	strcpy(x[1].prod, "XXX1");
	x[2].cod = 50;
	strcpy(x[2].prod, "XXX2");
	x[3].cod = 3;
	strcpy(x[3].prod, "XXX3");
	x[4].cod = 2;
	strcpy(x[4].prod, "XXX4");
	
	comparable[0] = porCod;
	comparable[1] = porCodDesc;
	
	ordenaLista(x, 5, comparable[0]);
	
	return 0;
}
