#include "metric.h"
#include "pcnt.h"
#include "filaLaudo.h"
#include "fila.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void verificaMetricas(paciente *p, int *tempoPatologia, int *pacientesPatologia, int *ptrLaudo, int *ptrAlta, int *ptrPrazo){
    
    if( ( getTempoLaudo(p) - getTempoEntrada(p) ) > 7200 ){
        *ptrPrazo += 1;
    }

    *ptrLaudo += getTempoLaudo(p) - getTempoEntrada(p);
    *ptrAlta += 1;

    switch(getEstado(p)){
        case 0:
            tempoPatologia[0] += getTempoLaudo(p) - getTempoEntrada(p);
            pacientesPatologia[0] += 1;
            break;
        case 1:
            tempoPatologia[1] += getTempoLaudo(p) - getTempoEntrada(p);
            pacientesPatologia[1] += 1;
            break;
        case 2:
            tempoPatologia[2] += getTempoLaudo(p) - getTempoEntrada(p);
            pacientesPatologia[2] += 1;
            break;
        case 3:
            tempoPatologia[3] += getTempoLaudo(p) - getTempoEntrada(p);
            pacientesPatologia[3] += 1;
            break;
        case 4:
            tempoPatologia[4] += getTempoLaudo(p) - getTempoEntrada(p);
            pacientesPatologia[4] += 1;
            break;
        }
}

void resolveMetricas(int *tempoPatologia, int *pacientesPatologia, int laudoTotal, int pacientesAlta, int foraPrazo){
    int mediaLaudo = 0;
    if(pacientesAlta > 0){
        mediaLaudo = laudoTotal / pacientesAlta;
        printf("O tempo medio de laudo e de: %d\n", mediaLaudo);
    }
    else{
        printf("O tempo medio de laudo e de: %d\n", mediaLaudo);
    }
    int mediaPatologia = 0;
    for(int i = 0; i < 5; i++){
        switch(i){
        case 0:
            if(pacientesPatologia[0] > 0){
                mediaPatologia = tempoPatologia[0] / pacientesPatologia[0];
                printf("O tempo medio de laudo para saude normal e de: %d\n", mediaPatologia);
            }
            else{
                printf("O tempo medio de laudo para saude normal e de: %d\n", mediaPatologia);
            }
            break;
        case 1:
            if(pacientesPatologia[1] > 0){
                mediaPatologia = tempoPatologia[1] / pacientesPatologia[1];
                printf("O tempo medio de laudo para bronquite e de: %d\n", mediaPatologia);
            }
            else{
                printf("O tempo medio de laudo para bronquite e de: %d\n", mediaPatologia);
            }
            break;
        case 2:
            if(pacientesPatologia[2] > 0){
                mediaPatologia = tempoPatologia[2] / pacientesPatologia[2];
                printf("O tempo medio de laudo para pneumonia e de: %d\n", mediaPatologia);
            }
            else{
                printf("O tempo medio de laudo para pneumonia e de: %d\n", mediaPatologia);
            }
            break;
        case 3:
            if(pacientesPatologia[3] > 0){
                mediaPatologia = tempoPatologia[3] / pacientesPatologia[3];
                printf("O tempo medio de laudo para fratura no femur e de: %d\n", mediaPatologia);
            }
            else{
                printf("O tempo medio de laudo para fratura no femur e de: %d\n", mediaPatologia);
            }
            break;
        case 4:
            if(pacientesPatologia[4] > 0){
                mediaPatologia = tempoPatologia[4] / pacientesPatologia[4];
                printf("O tempo medio de laudo para apendicite e de: %d\n", mediaPatologia);
            }
            else{
                printf("O tempo medio de laudo para apendicite e de: %d\n", mediaPatologia);
            }
            break;
        }
    }

    printf("O tempo medio de laudo fora do prazo e de: %d\n", foraPrazo);
}



















/*
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


void patologiasAppend(ListaPatologias *lista, int tempo, int instante){
    int doenca = Sorteio_Patologias();

    patologiaNode *node = malloc(sizeof(patologiaNode));
    node->next = lista->first;
    node->info = doenca    
    lista->first = node;
}


void metricaDoenca(ListaPatologias *lista){
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

*/
