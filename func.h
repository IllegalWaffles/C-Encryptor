#include <stdio.h>

char toChar(int in);
int toInt(char in);

void decrypt(FILE*, FILE*, char[]);
void encrypt(FILE*, FILE*, char[]);

unsigned long hash(char*);
