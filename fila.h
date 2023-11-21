#ifndef FILA_H
#define FILA_H

typedef struct queue_struct Queue;
typedef struct queue_node QueueNode;

Queue *q_create(char tipo);
int q_is_empty(Queue *q);
void q_enqueue(Queue *q, void v);
#endif