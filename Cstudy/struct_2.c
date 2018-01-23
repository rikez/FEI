#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[55];
	float p1;
	float p2;
	float p3;
} aluno;

void notas(aluno* a) {
	puts("P1: ");
	scanf("%f", &(a->p1));
	puts("P2: ");
	scanf("%f", &(a->p2));
}


float calcMedia(aluno* a) {
	float media = ((a->p1*0.4)+(a->p2*0.6));
	return media;
}

void construtor(aluno* a, char * nome) {
	strcpy(a->nome, nome);
	a->p1 = 0;
	a->p2 = 0;
	a->p3 = 0;
}


int main() {
	aluno a[5];
	
	aluno a2;
	int i;
	
	for(i=0; i<5;i++) {
		construtor(a+i, "SemNome");
	}
	//notas(a);
	for(i=0; i < 5; i++) {
		printf("%s ", a[i].nome);
		printf("%.1f ", a[i].p1);
		printf("%.1f ", a[i].p2);
		puts("");	
	}
	notas(a);
	printf("%.1f\n",calcMedia(a));
	return 0;
}



