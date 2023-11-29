#ifndef PCNT_H
#define PCNT_H
#include <stdlib.h>
#include "fila.h"
#include "filaLaudo.h"

typedef struct paciente_struct paciente;
typedef struct registro_struct registro;
typedef struct raio_struct RAIO;
typedef struct medi_struct MEDICO;
typedef struct listaPaciente_struct ListaPaciente;
typedef struct nodePaciente_struct NodePaciente;


ListaPaciente *ll_create();

int getIdPaciente(paciente *p);
char *getNome(paciente *paciente);
int Sorteio_Patologias();
void altaPaciente(ListaPaciente *lista, int laudoID);

int getTempoLaudo(paciente *p);
int getTempoEntrada(paciente *p);
int getEstado(paciente *p);

void setTempoLaudo(paciente *p, int v);
void setEstado(paciente *p, int v);

paciente *getPaciente(ListaPaciente *lista, int id);
paciente *cria_paciente(int tempo);
RAIO *create_RAIO(int identificador, int tempo);
MEDICO *create_MEDICO(int identificador, int tempo);

void ll_append(ListaPaciente *lista, paciente *p);
void ll_insert(ListaPaciente *lista, paciente *p);
void verificaRaioX(RAIO **maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante);
void verificaLaudo(MEDICO **medicos, QueueLaudo *filaLaudo, ListaPaciente *lista, int instante, int *tempoPatologia, int *pacientesPatologia,int *ptrLaudo, int *ptrAlta, int *ptrPrazo);


#endif