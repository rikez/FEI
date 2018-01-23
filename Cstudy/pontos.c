#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float x;
	float y;
}ponto;

typedef struct {
	ponto ret;
	float area;
}ret;

typedef struct {
	ponto c;
	float raio;
}circulo;

typedef struct {
	ponto q;
	float area;
}quad;

float dist(ponto a, ponto b) {
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - b.x, 2));
}

float areaCirc(circulo c) {
	return M_PI * pow(c.raio, 2);
}

float areaRet(ret r) {
	return r.ret.x * r.ret.y;
}

void construtor(ponto * p) {
	p->x = 0;
	p->y = 0;
}

ponto criaPonto() {
	ponto p;
	puts("Ponto X:");
	scanf("%f", &p.x);
	puts("Ponto Y");
	scanf("%f", &p.y);
	
	return p;
}

void imprime(ponto p) {
	printf("X : %.1f | Y: %.1f\n", p.x, p.y);
}

int main() {
int i;
	ponto p[50]; 
	for(i=0;i<50;i++) {
		construtor(&p[i]);
		imprime(p[i]);
	}
	
	
	ponto p2 = criaPonto();
	circulo c;
	ret r;
	printf("%f\n", areaCirc(c));
	printf("%f", areaRet(r));
}





