#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include "helpers.h"

char toChar(int in);
int toInt(char in);

void decrypt(FILE*, FILE*, char[]);
void encrypt(FILE*, FILE*, char[]);

unsigned long hash(char*);

#endif