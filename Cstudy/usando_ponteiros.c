#include <stdlib.h>
#include <stdio.h>

/**
A função recebe uma variavel INT, a fim de mudar o valor da variável
**/
void mudaNumero(int numero) {
  numero = 100;
  printf("Numero dentro da funcao SEM PONTEIRO: %d\n", numero);
}


/**
a função recebe um ponteiro(*) de INT, esse ponteiro
nos indica o ENDEREÇO da Memória em que está variável está localizada.
**/
void mudaNumeroNaMemoria(int * ptr) {
  *ptr = 11000000;
  printf("Numero Dentro da funcao com PONTEIRO: %p %i\n", ptr , *ptr);
}

void criandoArrayDePonteiros(int * p, int n) {
  int i;
  p = malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    p[i] = i+5;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n\n");
}

void criandoMatrizDePonteiro(int **p, int l, int c) {
  int i, j;
  p = malloc(sizeof(int*) * l);
  for (i = 0; i < l; i++) {
    *(p+i) = malloc(sizeof(int) * c);
  }

  for (i = 0; i < l; i++) {
     for (j = 0; j < c; j++) {
         *(*(p + i) + j) = j+i;  // i é o indice da linha e j é o da coluna
     }
  }

  for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
      printf("%d", p[i][j]);
      if(j == c - 1) printf("\n");
    }
  }
  printf("\n\n");
}

void freeing(int * p, int n) {
  int i;
  for (i = 0; i < n; i++) {
      free(p);
  }
}


int main() {
  int numero = 15;
  int *ponteiro = &numero; // Declaro novo ponteiro e atribuo o endereço da memoria de número;
  int *ptrArray;
  int **ptrMatriz;
  int n, l, c;
  scanf("%d %d %d", &n, &l, &c);
  mudaNumero(numero);
  printf("Valor real: %d\n", numero);
  mudaNumeroNaMemoria(ponteiro); // poderiamos simplesmente passar &numero como parametro.
  criandoArrayDePonteiros(ptrArray, n);
  criandoMatrizDePonteiro(ptrMatriz, l, c);

  freeing(ptrArray, n);
  freeing(*ptrMatriz, l);

  return 0;
}
