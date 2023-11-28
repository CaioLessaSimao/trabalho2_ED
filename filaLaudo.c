#include "filaLaudo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct registro_struct {
  int id;
  int tempo;
  char condicao[20];
};

struct queue_struct_laudo {
  QueueNodeLaudo *front;
  QueueNodeLaudo *rear;
};

struct queue_node_laudo {
  registro *info;
  QueueNodeLaudo *next;
};


static char *sort_condition() {
  char *condition = (char *)malloc(20 * sizeof(char));

  int t = rand() % 3;
  switch (t) {
  case 0:
    strcpy(condition, "normal");
    break;
  case 1:
    strcpy(condition, "perigoso");
    break;
  case 2:
    strcpy(condition, "muito perigoso");
    break;

    return condition;
  }
  return " ";
}


registro *create_registro(QueueLaudo *filaLaudo, int id, int instante) {
  registro *r = (registro *)malloc(sizeof(registro));
  r->id = id;
  r->tempo = instante;
  strcpy(r->condicao, sort_condition());
  return r;
}


QueueLaudo *qLaudo_create() {
  QueueLaudo *q = (QueueLaudo *)malloc(sizeof(QueueLaudo));
  q->front = q->rear = NULL;
  return q;
}


int qLaudo_is_empty(QueueLaudo *q) { return q->front == NULL; }


int getLaudoId(QueueLaudo *FilaLaudo){
  return FilaLaudo->front->info->id;
}


void qLaudo_enqueue(QueueLaudo *q, registro *v) {
  QueueNodeLaudo *node = (QueueNodeLaudo *)malloc(sizeof(QueueNodeLaudo));
  node->info = v;
  node->next = NULL;

  if (qLaudo_is_empty(q))
    q->front = node;
  else
    q->rear->next = node;

  q->rear = node;
}


void retiraLaudo(QueueLaudo *filaLaudo){
  QueueNodeLaudo *n = filaLaudo->front;
  filaLaudo->front = filaLaudo->front->next;
  free(n);
}