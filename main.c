#include "fila.h"
#include "metric.h"
#include "filaLaudo.h"
#include "pcnt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
  int prob;
  int tempo = 0;
  
  int *tempoPatologia = (int *)malloc(5 * sizeof(int));
  for(int i = 0; i< 5; i++){
    tempoPatologia[i] = 0;
  }

  int *pacientesPatologia = (int *)malloc(5 * sizeof(int));
  for(int i = 0; i< 5; i++){
    pacientesPatologia[i] = 0;
  }
  
  int laudoTotal = 0;
  int *ptrLaudo = &laudoTotal;

  int pacientesAlta = 0;
  int *ptrAlta = &pacientesAlta;

  int foraPrazo = 0;
  int *ptrPrazo = &foraPrazo;

  ListaPaciente *listaPacientes = ll_create();
  QueueExame *filaExame = qExame_create();
  QueueLaudo *filaLaudo = qLaudo_create();

  RAIO  *maquinas[5];
  MEDICO *medicos[3];

  for (int i = 0; i < 5; i++) {
    maquinas[i] = create_RAIO(-1, 0);
  }

  for (int i = 0; i < 5; i++) {
    medicos[i] = create_MEDICO(-1, 0);
  }
  
  while (tempo <= 43700) {
    
    srand(time(NULL));
    prob = (rand() % (10 + 1 - 1)) + 1;


    if (prob == 1 || prob == 2) {
      paciente *p = cria_paciente(tempo);
      ll_append(listaPacientes, p);

      int idE = getIdPaciente(p);
      qExame_enqueue(filaExame, idE);
    }

    verificaRaioX(maquinas, filaExame, filaLaudo, tempo);

    verificaLaudo(medicos, filaLaudo, listaPacientes, tempo, tempoPatologia, pacientesPatologia,ptrLaudo, ptrAlta, ptrPrazo);

    if(tempo % 10 == 0){
      resolveMetricas(tempoPatologia, pacientesPatologia, laudoTotal, pacientesAlta, foraPrazo);
    }

    sleep(5);
    tempo++;
  }
  
  return 0;
}