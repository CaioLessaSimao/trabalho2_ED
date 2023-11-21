#include <stdio.h>
#include <time.h>
#include "pcnt.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int prob;
	int tempo = 0;	
	
	DynVec *listaPacientes = dv_create(10000);
	Queue *filaExame = q_create();
	Queue *filaLaudo = q_create();;

	raioX *maquina[5];
	
	while (tempo <= 200) {
		srand(time(NULL));
		prob = rand() % (10 + 1 - 1) + 1;
		if(prob == 1 || prob == 2){
			paciente *p = cria_paciente(tempo);
			p = (void) p;
			dv_insert(listaPacientes, p);
		}
		/*
		if sizeof(maquinas) < 5{
			struct raioX
			tempoFinal = rand(5,10);
			paciente = id paciente;
		}
		
		verificaRaioX(*raiox){
			verificar se um exame acabou:
				Se sim;
					retira o exame da lista
					cria um registro(id paciente, instante de tempo, condição)
					adiciona o registro na fila para laudo
		}

		*/
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