#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queue queue;

queue *queue_new (void);
void queue_append (queue **, void *);
void *queue_pop (queue **);

#include "queue.c"

#endif