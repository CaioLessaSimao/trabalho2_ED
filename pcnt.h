#ifndef PCNT_H
#define PCNT_H
#include <stdlib.h>
#include "fila.h"
#include "filaLaudo.h"

typedef struct paciente_struct paciente;
typedef struct registro_struct registro;
typedef struct raio_struct RAIO;
typedef struct listaPaciente_struct ListaPaciente;
typedef struct nodePaciente_struct NodePaciente;


ListaPaciente *ll_create();
paciente *cria_paciente(int tempo);
void ll_append(ListaPaciente *lista, paciente *p);
void ll_insert(ListaPaciente *lista, paciente *p);
void verificaRaioX(RAIO maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante);


#endif