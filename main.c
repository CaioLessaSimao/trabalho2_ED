#include "fila.h"
#include "filaLaudo.h"
#include "pcnt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int prob;
  int tempo = 0;

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

  while (tempo <= 43200) {
    srand(time(NULL)+tempo);
    prob = (rand() % (10 + 1 - 1)) + 1;
    if (prob == 1 || prob == 2) {
      paciente *p = cria_paciente(tempo);
      printf("paciente %d entrou\n", tempo);
      ll_append(listaPacientes, p);

      int idE = getIdPaciente(p);
      qExame_enqueue(filaExame, idE);
    }

    verificaRaioX(maquinas, filaExame, filaLaudo, tempo);

    
    verificaLaudo(medicos, filaLaudo, listaPacientes, tempo);
    
    tempo++;
  }
  return 0;
}