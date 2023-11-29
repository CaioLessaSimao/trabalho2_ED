#ifndef METRIC_H
#define METRIC_H
#include <stdlib.h>
#include "fila.h"
#include "filaLaudo.h"
#include "pcnt.h"



void verificaMetricas(paciente *p, int *tempoPatologia, int *pacientesPatologia, int *ptrLaudo, int *ptrAlta, int *ptrPrazo);
void resolveMetricas(int *tempoPatologia, int *pacientesPatologia, int laudoTotal, int pacientesAlta, int foraPrazo);

/*
typedef struct patologiaNode patologia;
typedef struct lista_patologia ListaPatologias;


//int Sorteio_Patologias();
ListaPatologias * create_ll_Patologias();
void metricaDoenca(ListaPatologias *lista);
void patologiasAppend(ListaPatologias *lista, int tempo, int instante);
*/

#endif