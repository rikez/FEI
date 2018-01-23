#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[55];
  char idade[4];
} contato;

typedef struct{
  contato v[100];
  int t;
} agenda;

agenda a;
agenda* ap;
int tam;

void gravaAgenda(agenda* a){
    FILE* fp = fopen("teste.bin", "w");
    fwrite(a->v, sizeof(contato), a->t, fp);
    printf("GRAVADO!\n\n");
    fclose(fp);
}

agenda* lerAgenda(agenda *a) {
  FILE* fp = fopen("teste.bin", "r");
  int i = 0;

  while(!feof(fp)) {
    fread(a->v+i, sizeof(contato), 1, fp);
    i++;
  }

  tam= i/2;

  fclose(fp);

  return a;
}



void create(agenda *a) {
  int i;
  system("clear");
  printf("Digite seu nome: ");
  fgets(a->v[a->t].nome, 55, stdin);
  printf("\n");
  printf("Digite sua idade: ");
  fgets(a->v[a->t].idade, 4, stdin);
  printf("\n");
  for(i=0; i < strlen(a->v[a->t].nome); i++) {
    if(a->v[a->t].nome[i] == '\n') {
      a->v[a->t].nome[i+1] = '\0';
    }
  }

  for(i=0; i < strlen(a->v[a->t].idade); i++) {
    if(a->v[a->t].idade[i] == '\n') {
      a->v[a->t].idade[i+1] = '\0';
    }
  }

  (a->t) = (a->t) + 1;
 
}

void imprime(agenda *a) {
  int i;
  ap = lerAgenda(a);
  printf("=== Usuários encontrados! ===\n");
  for (i = 0 ; i < tam*2-1; i++) {
    printf("\nNome : %s\n", ap->v[i].nome);
    printf("Idade : %s\n", ap->v[i].idade);
  }

  printf("=== Fim ===");

}

int menu() {
  int op;
  do {
    printf("\n");
    printf("1 - Criar Usuário\n");
    printf("2 - Listar Usuários\n");
    printf("3 - Gravar Usuários\n");
    printf("0 - Tchau Nigger\n");
    scanf("%d", &op);
    getchar();
    if(op==1) {
      create(&a);
    } else if(op==2) {
      imprime(&a);
    } else if (op == 3) {
    	gravaAgenda(&a);
    } else {
      return 0;
    }
  } while(op== 1 || op == 2 || op == 3);

}





int main(int argc, char const *argv[]) {
  a.t=0;
  menu();


  return 0;
}
