#include "pcnt.h"
#include "filaLaudo.h"
#include "fila.h"
#include "metric.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct paciente_struct {
  int id;
  char nome[50];
  char cpf[15];
  int idade;
  int tempoEntrada;
  int tempoLaudo;
  int estado;
};

struct raio_struct{
  int id;
  int tempo;
};

struct medi_struct{
  int id;
  int tempo;
};

struct listaPaciente_struct{
  NodePaciente *first;	
};

struct nodePaciente_struct{
  paciente *info;
  NodePaciente *next;
};


paciente *getPaciente(ListaPaciente *lista, int id){
  NodePaciente *node = (NodePaciente*)malloc(sizeof(NodePaciente));
  for(node = lista->first; node->next != NULL; node = node->next){
      if(node->info->id == id){
        return node->info;
      }
  }
  return NULL;
}


int getIdPaciente(paciente *p){
  return p->id;
}

int getTempoLaudo(paciente *p){
  return p->tempoLaudo;
}

int getTempoEntrada(paciente *p){
  return p->tempoEntrada;
}

int getEstado(paciente *p){
  return p->estado;
}

void setTempoLaudo(paciente *p, int v){
  p->tempoLaudo = v;
}

void setEstado(paciente *p, int v){
  p->estado = v;
}


void imprimirRaio(RAIO *raio) {
  printf("ID: %d, Tempo: %d\n", raio->id, raio->tempo); 
}


RAIO *create_RAIO(int identificador, int tempo){
  RAIO *r = (RAIO *)malloc(sizeof(RAIO));
  r->id = identificador;
  r->tempo = tempo;
  return r;
}

MEDICO *create_MEDICO(int identificador, int tempo){
  MEDICO *m = (MEDICO *)malloc(sizeof(MEDICO));
  m->id = identificador;
  m->tempo = tempo;
  return m;
}

char* getNome(paciente *paciente){
  return paciente->nome;
}


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
  char *cpf = malloc(12 * sizeof(char));
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
  p->id = tempo;
  p->idade = idade;
  p->tempoEntrada = tempo;
  p->tempoLaudo = 0;

  return p;
}


void altaPaciente(ListaPaciente *lista, int idAlta){
  
  paciente *p = getPaciente(lista, idAlta);

  NodePaciente *node = lista->first;      
  NodePaciente *prev = NULL;             

  while (node != NULL) {
    
    if (node->info == p)  {
      if (prev == NULL) {
        lista->first = node->next;
      } 
      else{ 
        prev->next = node->next;
      }
      free(node);
      return;
    } 
    else {
      prev = node;
      node = node->next;
    }
  }
  
}


int Sorteio_Patologias(){
    int numero = rand() % 100 + 1;

  switch (numero) {
    case 1 ... 30:
      return 0;
    case 31 ... 50:
      return 1;
    case 51 ... 70:
      return 2;
    case 71 ... 85:
      return 3;
    case 86 ... 100:
      return 4;
  }
}

void verificaRaioX(RAIO **maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante){
  srand(time(NULL));
  
  for(int i = 0; i < 5; i++){
    if(maquinas[i]->tempo == 0){              
      if(!qExame_is_empty(filaExame)){
        maquinas[i]->id = getIdExame(filaExame);
        retiraNo(filaExame);
        maquinas[i]->tempo = ((rand() % (5 + 1 - 10)) + 10) + instante;  
      }
    }  
    else{

      if(maquinas[i]->tempo >= instante){     
        registro *r = create_registro(filaLaudo, maquinas[i]->id, instante);
        qLaudo_enqueue(filaLaudo, r);

        //levando proximo paciente para fazer raio X
        if(!qExame_is_empty(filaExame)){
          maquinas[i]->id = getIdExame(filaExame);
          retiraNo(filaExame);
          maquinas[i]->tempo = (rand() % ((5 + 1 - 10)) + 10) + instante;
        }
        else{
          maquinas[i]->id = -1;
          maquinas[i]->tempo = 0;
        }
      }
    }
  }
}


void verificaLaudo(MEDICO **medicos, QueueLaudo *filaLaudo, ListaPaciente *lista, int instante, int *tempoPatologia, int *pacientesPatologia,int *ptrLaudo, int *ptrAlta, int *ptrPrazo){
  srand(time(NULL));

  for(int i = 0; i < 3; i++){
    if (medicos[i]->tempo == 0){          
      if(!qLaudo_is_empty(filaLaudo)){
        medicos[i]->id = getLaudoId(filaLaudo);
        retiraLaudo(filaLaudo);
        medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
      }
    }
    else{
      if(medicos[i]->tempo == instante){     
        int idAlta = medicos[i]->id;
        
        paciente *p = getPaciente(lista, idAlta);
        
        setTempoLaudo(p, instante);
        setEstado(p, Sorteio_Patologias());

        altaPaciente(lista, idAlta);

        verificaMetricas(p, tempoPatologia, pacientesPatologia, ptrLaudo, ptrAlta, ptrPrazo);


        if(!qLaudo_is_empty(filaLaudo)){   
          medicos[i]->id = getLaudoId(filaLaudo);
          retiraLaudo(filaLaudo);

          medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
        }
        else{
          medicos[i]->id = -1;
          medicos[i]->tempo = 0;
        }
      }
    }
  }
}
