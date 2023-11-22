#include "pcnt.h"
#include "filaLaudo.h"
#include "fila.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct paciente_struct {
	int id;
	char nome[50];
	char cpf[12];
	int idade;
	int tempoEntrada;
	int tempoLaudo;
};
struct raio_struct{
	char id[12];
	int tempo;
};

struct listaPaciente_struct{
	NodePaciente *first;	
};

struct nodePaciente_struct{
	paciente *info;
	NodePaciente *next;
};


ListaPaciente *ll_create(){
	ListaPaciente *l = (ListaPaciente *)malloc(sizeof(ListaPaciente));
    l->first = NULL; 
	return l;
}

void ll_append(ListaPaciente *lista, paciente *p){
	NodePaciente *n = (NodePaciente *)malloc(sizeof(NodePaciente));
	n->info = p;
	n->next = NULL;
	
	if(lista->first == NULL){
		lista->first = n;
	}
	
	else{
		NodePaciente *j = lista->first;
		while(j->next != NULL){
			j = j->next;
		}

		j->next = n;
	}
}

char *geraCPF(){
	int num;
	char cpf[12];
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
	char cpf[12];
	strcpy(cpf, geraCPF());
	int idade = rand() % (100 + 1);

	paciente *p = (paciente *)malloc(sizeof(paciente));
	strcpy(p->nome, nomes[rand() % (3 + 1)]);
	strcpy(p->cpf,cpf);
	p->idade = idade;
	p->tempoEntrada = tempo;
	p->tempoLaudo = 0;

	return p;
}

void verificaRaioX(RAIO maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante){
	srand(time(NULL));
	for(int i = 0; i < 5; i++){
		if(maquinas[i].tempo == 0){
			if(!qExame_is_empty(filaExame)){
				strcpy(maquinas[i].id, filaExame->first->id);
				maquinas[i].tempo = (rand() % (5 + 1 - 10)) + 10;

				NodePaciente *n = filaExame->first;
				filaExame->first = n->next;
				free(n);
			}
			else{
				if(maquinas[i].tempo == instante){
					registro *r = create_registro(maquinas[i].id, instante);
					if(!qExame_is_empty(filaExame)){
						strcpy(maquinas[i].id, filaExame->first->id);
						maquinas[i].tempo = (rand() % (5 + 1 - 10)) + 10;
					}
					else{
						strcpy(maquinas[i].id, " ");
						maquinas[i].tempo = 0;
					}
				}
			}
		}
	}
}




