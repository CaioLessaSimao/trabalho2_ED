#ifndef PCNT_H
#define PCNT_H
#include <stdlib.h>

typedef struct paciente_struct paciente;
typedef struct registro_struct registro;
typedef struct raioX_struct raioX;
typedef struct dynvec_struct DynVec;


DynVec *dv_create(int n_maximo);
void dv_insert(DynVec *lista, void *p);
paciente *cria_paciente(int tempo);
#endif