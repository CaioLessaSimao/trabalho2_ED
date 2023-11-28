#include "fila.h"
#include "pcnt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct queue_struct_exame {
  QueueNodeExame *front;
  QueueNodeExame *rear;
};

struct queue_node_exame {
  int id;
  QueueNodeExame *next;
};


QueueExame *qExame_create() {
  QueueExame *q = (QueueExame *)malloc(sizeof(QueueExame));
  q->front = q->rear = NULL;
  return q;
}


int qExame_is_empty(QueueExame *q) { return q->front == NULL; }


int getIdExame(QueueExame *q) {
  return q->front->id;
}


void qExame_enqueue(QueueExame *q, int v) {
  QueueNodeExame *node = (QueueNodeExame *)malloc(sizeof(QueueNodeExame));
  node->id = v;
  node->next = NULL;

  if (qExame_is_empty(q))
    q->front = node;
  else
    q->rear->next = node;

  q->rear = node;
}




void retiraNo(QueueExame *fila) {
  QueueNodeExame *n = fila->front;
  fila->front = n->next;
  free(n);
}
