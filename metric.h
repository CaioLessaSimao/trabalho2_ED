#ifndef METRIC_H
#define METRIC_H
#include <stdlib.h>
#include "fila.h"
#include "filaLaudo.h"
#include "pcnt.h"

typedef struct patologiaNode patologia;
typedef struct lista_patologia ListaPatologias;


//int Sorteio_Patologias();
ListaPatologias * create_ll_Patologias();
void metricaDoenca(ListaPatologias lista);
void patologiasAppend(ListaPatologias lista, int tempo, int instante);


#endif