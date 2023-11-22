#ifndef FILALAUDO_H
#define FILALAUDO_H

typedef struct queue_struct_laudo QueueLaudo;
typedef struct queue_node_laudo QueueNodeLaudo;
typedef struct registro_struct registro;

QueueLaudo *qLaudo_create();
int qLaudo_is_empty(QueueLaudo *q);
void qLaudo_enqueue(QueueLaudo *q, registro v);
#endif