#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

int BuscaBinaria(int *v, int i, int f, int valor){
	if( i > f)
	    return -1;

	int p = (i+f)/2;

	if( v[p] == valor )
	    return p;

	if(valor > v[p])
	    return BuscaBinaria(v, p+1, f, valor);
	else
		return BuscaBinaria(v, i, p-1, valor);
}

int fibonacci(int numero) {
  if(numero == 1) return 1;
  if(numero == 0) return 0;
  return fibonacci(numero-1) + fibonacci(numero-2);
}

int fatorial(int numero) {
  if(numero <= 1) return 1;
  return (numero * fatorial(numero-1));
}

int tarefa(int numero, int (*rec)(int)) {
  rec(numero);
}
int tarefa2(int *p, int i, int f, int valor, int (*rec)(int*, int, int, int)) {
  rec(p, i, f, valor);
}



int main(int argc, char const *argv[]) {
  int i, x, y;
  int (*recursive[2])(int);
  recursive[0] = fatorial;
  recursive[1] = fibonacci;

  int (*sorting)(int*, int, int, int);
  sorting = &BuscaBinaria;

  puts("Qual número fatorial desejas calcular?: ");
  scanf("%d", &y);
  printf("Fatorial de: %d =  %d\t\n", y, tarefa(y, recursive[0]));


  puts("Qual posição da sequência de fibonacci desejas?: ");
  scanf("%d", &x);
     for (i = 0; i < x; i++) {
        printf("Fibonacci: %d\t\n", tarefa(i, recursive[1]));
     }

     int *p = malloc(sizeof(int) * 10);
     for (i = 0; i < 10; i++) {
       *(p+i) = i * 2;
     }

     for (i = 0; i < 10; i++) {
       printf("%d ", *(p+i));
     }

     printf("\n");

     int k = tarefa2(p, 0, 5, 10, sorting);
     printf("%d\n", k);

     free(p);



  /* Exemplos 2


  puts("Qual número fatorial desejas calcular?: ");
  scanf("%d", &y);
  printf("Fatorial de: %d ' = ' %d\t\n", y, recursive[0](y));

  /////////////////////////

  int *p = malloc(sizeof(int) * 10);
  for (i = 0; i < 10; i++) {
    *(p+i) = i * 2;
  }

  for (i = 0; i < 10; i++) {
    printf("%d ", *(p+i));
  }

  printf("\n");

  int k = BuscaBinaria(p, 0, 5, 10);
  printf("%d\n", k);

  free(p);
*/
  return 0;
}
