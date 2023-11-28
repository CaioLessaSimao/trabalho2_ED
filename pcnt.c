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
    NodePaciente *node = malloc(sizeof(NodePaciente));
    NodePaciente *n    = malloc(sizeof(NodePaciente));

    if(lista->first->info->id == idAlta){
        lista->first = lista->first->next;
    }

    for(node = lista->first; node->next->next != NULL; node = node->next){
        if(node->next->info->id == idAlta){

            n = node->next;
            node->next = node->next->next;
            free(n);
        }
    }
}


int Sorteio_Patologias(){
    float saudeNormal = 0.3;
    float bronquite = 0.2;
    float pneumonia = 0.2;
    float fraturaFemur = 0.15;
    float apendicite = 0.15;

    srand(time(NULL));

    float randomValue = (float)rand() / RAND_MAX;

    // Verifica em qual intervalo o número aleatório encaixa
    if (randomValue < saudeNormal) {
        return 2;
    } else if (randomValue < saudeNormal + bronquite) {
        return 3;
    } else if (randomValue < saudeNormal + bronquite + pneumonia) {
        return 4;
    } else if (randomValue < saudeNormal + bronquite + pneumonia + fraturaFemur) {
        return 5;
    } else {
        return 6;
    }

    return 2;
}


void verificaRaioX(RAIO **maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante){
  srand(time(NULL));
  
  for(int i = 0; i < 5; i++){
    if(maquinas[i]->tempo == 0){              //verifica se a máquina está livre
      
      if(!qExame_is_empty(filaExame)){
        maquinas[i]->id = getIdExame(filaExame);
        retiraNo(filaExame);
        maquinas[i]->tempo = ((rand() % (5 + 1 - 10)) + 10) + instante; //adicionei o instante atual 
      }
    }  
    else{
      //printf("tempo maquina[%d]: %d, tempo atual: %d\n", i, maquinas[i]->tempo, instante);
      if(maquinas[i]->tempo >= instante){     //verifica se terminou o raio X
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


void verificaLaudo(MEDICO **medicos, QueueLaudo *filaLaudo, ListaPaciente *lista, int instante){
  srand(time(NULL));
  
  for(int i = 0; i < 3; i++){
    if (medicos[i]->tempo == 0){          //verifica se o médico está livre
      if(!qLaudo_is_empty(filaLaudo)){
        medicos[i]->id = getLaudoId(filaLaudo);
        retiraLaudo(filaLaudo);
        printf("sendo atendido\n");
        medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
      }
    }
    else{
      if(medicos[i]->tempo == instante){    //verifica se o laudo foi emitido  
        int idAlta = medicos[i]->id;
        paciente *p = getPaciente(lista, idAlta);
        //p->tempoLaudo = instante;                 - Devia funcionar
        //p->estado     = Sorteio_Patologias();     - Devia funcionar

        printf("paciente %d saiu do hospital\n", idAlta);

        //altaPaciente(lista, idAlta);


        if(!qLaudo_is_empty(filaLaudo)){    //chama próximo da lista
          medicos[i]->id = getLaudoId(filaLaudo);
          retiraLaudo(filaLaudo);
          printf("sendo atendido\n");
          medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
        }
        else{
          medicos[i]->id = -1;
          medicos[i]->tempo = 0;
        }
        
        //medirTempo( resultadoLaudo );

        
      }
      /*else{
        strcpy(medicos[i]->id, " ");
        medicos[i]->tempo = 0;
      }*/
    }
  }
}
