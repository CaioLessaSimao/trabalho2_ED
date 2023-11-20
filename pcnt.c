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
	void *v;	
};

DynVec *create(int n_maximo, char tipo){
	DynVec *dv = (DynVec *)malloc(sizeof(DynVec));

	dv->n = 0;
	dv->n_max = n_maximo;
	
	switch(tipo){
		case 'P':
			dv->v = (paciente *)malloc(n_maximo * sizeof(paciente));
			break;
		case 'E':
			dv->v = (int *)malloc(n_maximo * sizeof(int));
			break;
		case 'L':
			dv->v = (registro *)malloc(n_maximo * sizeof(registro));
			break;
	}
	return dv;
}

paciente *cria_paciente(int tempo){
	char nomes[4][23] = {"Jorge", "Joao", "Camilly", "Bruna"};
	
	srand(time(NULL));
	int cpf = rand() % (99999999999 + 1 - 10000000000) + 10000000000;
	int idade = rand() % (100 + 1);

	paciente *p = (paciente *)malloc(sizeof(paciente));
	strcpy(p->nome, nomes[rand() % (3 + 1)]);
	p->cpf = cpf;
	p->idade = idade;
	p->tempoEntrada = tempo;
	p->tempoLaudo = 0;


	return p;
}