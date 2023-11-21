#include "fila.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct queue_struct{
	QueueNode *front;
	QueueNode *rear;
};

struct queue_node{
	void info;
	QueueNode *next;
};

Queue *q_create(char tipo){

	Queue *q = (Queue *)malloc(sizeof(Queue));

	q->front = q->rear = NULL;

	return q;
}

int q_is_empty(Queue *q){
   return q->front == NULL;
}

void q_enqueue(Queue *q, void v){
   QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
   node->info = v;
   node->next = NULL;

   if (q_is_empty(q))
      q->front = node;
   else
      q->rear->next = node;

   q->rear = node;
}


