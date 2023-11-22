#include "fila.h"
#include "pcnt.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct queue_struct_exame{
	QueueNodeExame *front;
	QueueNodeExame *rear;
};

struct queue_node_exame{
	char id[12];
	QueueNodeExame *next;
};

QueueExame *qExame_create(){

	QueueExame *q = (QueueExame *)malloc(sizeof(QueueExame));

	q->front = q->rear = NULL;

	return q;
}

int qExame_is_empty(QueueExame *q){
   return q->front == NULL;
}

void qExame_enqueue(QueueExame *q, char v[12]){
   QueueNodeExame *node = (QueueNodeExame *)malloc(sizeof(QueueNodeExame));
   strcpy(node->id, v);
   node->next = NULL;

   if (qExame_is_empty(q))
      q->front = node;
   else
      q->rear->next = node;

   q->rear = node;
}

char *getIdExame(QueueExame *fila){
   return fila->front->id;
}

void retiraNo(QueueExame *fila){
   QueueNodeExame *n = fila->front;
   fila->front = n->next;
   free(n);
}


