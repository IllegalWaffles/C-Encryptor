#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILE_OUT stdout
#define DEFAULT_FILE_IN stdin
#define MAX_STRING_SIZE 256
#define MAX_KEY_LENGTH 1024
#define MAX_INPUT_LENGTH 10

#define usage(EXIT)\
do{\
printf("Usage: encryptor [-h] [[-u] | [-k encrkey] [-d | -e] [-i infile] [-o outfile]]\n");\
printf("\t-h : print this message\n");\
printf("\t-u : run with full ui\n");\
printf("\t-k : run with key encrkey\n");\
printf("\t-e : run encryption\n");\
printf("\t-d : run decryption\n");\
printf("\t-i : run with input file infile\n");\
printf("\t-o : run with output file outfile\n");\
fflush(stdout);\
finish(EXIT);\
}while(0)\

typedef struct argdata {

    bool ui;
    
    bool key;
    char *key_val;
    
    int encr;
    int decr;
    
    bool infile;
    char *infile_val;
    
    bool outfile;
    char *outfile_val;
    
    bool error;
    
} Arg_data;

Arg_data *parse_args(char **argv, int argc);
int prgm_ui();
void finish(int);

#endif

