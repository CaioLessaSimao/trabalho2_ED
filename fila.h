#ifndef FILA_H
#define FILA_H


typedef struct queue_struct_exame QueueExame;
typedef struct queue_node_exame QueueNodeExame;

QueueExame *qExame_create();
int getIdExame(QueueExame *fila);
void retiraNo(QueueExame *fila);
int qExame_is_empty(QueueExame *q);
void qExame_enqueue(QueueExame *q, int v);


#endif