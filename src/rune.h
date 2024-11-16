#ifndef RUNE_H
#define RUNE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bool.h"

#define WEOW (rune) (EOF & 0xFF)

typedef struct String String;
typedef unsigned int rune;

void String_new(String *);
void String_add(String *, rune);
bool rune_in_String(rune *, rune);
rune String_get(String *, size_t);
void String_put(String *);

rune fgetrune(FILE *);
void putrune(rune *);
size_t rune_strlen(rune *);

#include "rune.c"

#endif