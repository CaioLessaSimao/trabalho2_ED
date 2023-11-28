#include "metric.h"
#include "pcnt.h"
#include "filaLaudo.h"
#include "fila.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct patologiaNode{
    int info;
    int tempo;
    patologia *next;
};

struct lista_patologias{
    patologia *first;
};

ListaPatologias * create_ll_Patologias(){
    ListaPatologias *l = malloc(sizeof(ListaPatologias));
    l->first = NULL;

    return l;
}

/*
int Sorteio_Patologias(){
    float saudeNormal = 0.3;
    float bronquite = 0.2;
    float pneumonia = 0.2;
    float fraturaFemur = 0.15;
    float apendicite = 0.15;

    srand(time(NULL));

    float randomValue = (float)rand() / RAND_MAX;

    // Verifica em qual intervalo o número aleatório encaixa
    if (randomValue < saudeNormal) {
        return 1;
    } else if (randomValue < saudeNormal + bronquite) {
        return 2;
    } else if (randomValue < saudeNormal + bronquite + pneumonia) {
        return 3;
    } else if (randomValue < saudeNormal + bronquite + pneumonia + fraturaFemur) {
        return 4;
    } else {
        return 5;
    }

    return 1;
}
*/

void patologiasAppend(ListaPatologias lista, int tempo, int instante){
    int doenca = Sorteio_Patologias();

    patologiaNode node = malloc(sizeof(patologiaNode));
    node->next = lista->first;
    node->info = doenca    
    lista->first = node;
}


void metricaDoenca(ListaPatologias lista){
    char tipos[5][25] = {"Saúde Normal", "Bronquite", "Pneumonia", "Fratura de Fêmur", "Apendicite"}

    for (int i = 0; i<5; i++)
    {
        int soma, quant, total, quantT;
        for(patologiaNode *node; node->next != NULL; node = node->next)
        {
            if(i == node->info)
            {
                soma += node->tempo;
                quant++
            }
        }

        printf("O tempo médio para %s foi %d \n", tipos[i], soma/quant);
        total += soma;
        quantT += quant;
    }

    printf("O tempo médio por laudo é %d \n", total/quantT)
}


