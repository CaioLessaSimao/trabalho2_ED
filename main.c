#include "pcnt.h"
#include "fila.h"
#include "filaLaudo.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int prob;
	int tempo = 0;	
	
	ListaPaciente *listaPacientes = ll_create();
	QueueExame *filaExame = qExame_create();
	QueueLaudo *filaLaudo = qLaudo_create();

	RAIO *maquinas[5];
	
	for (int i = 0; i < 5; i++){
		maquinas[i] = create_RAIO(" ", 0);
	}
	
	while (tempo <= 200) {
		srand(time(NULL));
		prob = (rand() % (10 + 1 - 1)) + 1;
		if(prob == 1 || prob == 2){
			paciente *p = cria_paciente(tempo);
			ll_append(listaPacientes, p);
		}
		
		verificaRaioX(maquinas, filaExame, filaLaudo, tempo);

		tempo++;
	}

	
/*	
	// Exemplo de como trabalhar com tempo
	clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Seu código ou processo que você quer medir o tempo aqui

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %f segundos\n", cpu_time_used);
   */
}