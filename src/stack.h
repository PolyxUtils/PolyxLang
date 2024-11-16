#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

stack *stack_new (void);
void stack_push (stack **, void *);
void *stack_pop (stack **);
void stack_delete (stack **);

#include "stack.c"

#endif