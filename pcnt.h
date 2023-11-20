#ifndef PCNT_H
#define PCNT_H
#include <stdlib.h>

typedef struct paciente_struct paciente;
typedef struct registro_struct registro;
typedef struct raioX_struct raioX;
typedef struct dynvec_struct DynVec;

DynVec *create(int n_maximo, char tipo);
#endif