#include "filaLaudo.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct registro_struct{
	int id;
	int tempo;
	char condicao[16];
};

struct queue_struct_laudo{
	QueueNodeLaudo *front;
	QueueNodeLaudo *rear;
};

struct queue_node_laudo{
	registro info;
	QueueNodeLaudo *next;
};




QueueLaudo *qLaudo_create(){

	QueueLaudo *q = (QueueLaudo *)malloc(sizeof(QueueLaudo));

	q->front = q->rear = NULL;

	return q;
}

int qLaudo_is_empty(QueueLaudo *q){
   return q->front == NULL;
}

void qLaudo_enqueue(QueueLaudo *q, registro v){
   QueueNodeLaudo *node = (QueueNodeLaudo *)malloc(sizeof(QueueNodeLaudo));
   node->info = v;
   node->next = NULL;

   if (qLaudo_is_empty(q))
      q->front = node;
   else
      q->rear->next = node;

   q->rear = node;
}