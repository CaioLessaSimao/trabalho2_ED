#include "pcnt.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct paciente_struct {
	int id;
	char nome[50];
	int cpf;
	int idade;
	int tempoEntrada;
	int tempoLaudo;
};

struct registro_struct{
	int id;
	int tempo;
	char condicao[16];
};

struct raioX_struct{
	int id;
	int tempo;
};

struct dynvec_struct{
	int n;
	int n_max;
	paciente *v;	
};


DynVec *dv_create(int n_maximo){
	DynVec *dv = (DynVec *)malloc(sizeof(DynVec));

	dv->n = 0;
	dv->n_max = n_maximo;
	dv->v = (paciente *)malloc(n_maximo * sizeof(paciente));
	
	return dv;
}

void dv_insert(DynVec *lista, paciente *p){
	printf("Chegou");
	if(lista->n == lista->n_max){
		//realloc()
	}
	lista->v[++lista->n] = p;
}

char *geraCPF(){
	int num;
	char cpf[12]
	srand(time(NULL));
	for(int i = 0; i < 12; i++){
		num = rand() % (10 + 1);
		cpf[i] = (char)num;
	}
	return cpf;
}

paciente *cria_paciente(int tempo){
	char nomes[4][23] = {"Jorge", "Joao", "Camilly", "Bruna"};
	
	srand(time(NULL));
	char cpf[12] = geraCPF();
	int idade = rand() % (100 + 1);

	paciente *p = (paciente *)malloc(sizeof(paciente));
	strcpy(p->nome, nomes[rand() % (3 + 1)]);
	strcpy(p->cpf,cpf);
	p->idade = idade;
	p->tempoEntrada = tempo;
	p->tempoLaudo = 0;

	return p;
}