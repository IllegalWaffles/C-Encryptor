#include "helpers.h"
#include "encr_func.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

Arg_data *parse_args(char **argv, int argc){
    
    Arg_data *argdata = (Arg_data*)calloc(1, sizeof(Arg_data));
    argdata->encr = -1;
    argdata->decr = -1;
    
    if(argc == 1){
        
        argdata->error = true;
        return argdata;
        
    }
    
    opterr = 0;
    
    unsigned char c = 0;
    while((c = getopt(argc, argv, "hukdeio")) != -1){
    
        switch(c){
            
            case 'h':
                usage(EXIT_SUCCESS);
                break;
            case 'u':
                argdata->ui = true;
                return argdata;
                
            case 'k':
                argdata->key = true;
                if(optarg == NULL) //-k was passed, but no input file name
                {
                    
                    argdata->error = true;
                    return argdata;
                    
                }
                
                argdata->key_val = (char *)calloc(MAX_STRING_SIZE, sizeof(char));
                strcpy(argdata->key_val, optarg);
                break;
            case 'i':
                argdata->infile = true;
                if(optarg == NULL) //-i was passed, but no input file name
                {
                    
                    argdata->error = true;
                    return argdata;
                    
                }
                
                argdata->infile = (char *)calloc(MAX_STRING_SIZE, sizeof(char));
                strcpy(argdata->infile_val, optarg);
                break;
            case 'o':
                argdata->outfile = true;
                if(optarg == NULL) //-o was passed, but no input file name
                {
                    
                    argdata->error = true;
                    return argdata;
                    
                }
                
                argdata->outfile = (char *)calloc(MAX_STRING_SIZE, sizeof(char));
                strcpy(argdata->outfile_val, optarg);
                break;
            case 'd':
                if(argdata->decr != -1 || argdata->encr != -1){
                    
                    argdata->error = true;
                    return argdata;
                    
                }
                
                argdata->decr = true;
                break;
            case 'e':
                if(argdata->decr != -1 || argdata->encr != -1){
                    
                    argdata->error = true;
                    return argdata;
                    
                }
                
                argdata->encr = true;
                break;
            case '?':
            default: //Unexpected input
                argdata->error = true;
                return argdata;
        
        }
    
    }
    
    return argdata;
    
}

int prgm_ui(){
    
    int finished = 0;
    char input[3], key[1000];

    printf("Menu:\n\nk - Displays the current encryptor key\nnk - Sets a new encryptor key\n");
    printf("e - Encrypt a file and write it to the given file - you must include file extension (.txt)\n");
    printf("d - Decrypt a file and write the result to a given file - you must include file extension (.txt)\n");
    printf("q - Exit the program\n\n");

    key[0] = '\0';

    while(!finished){

        printf("> ");
        scanf(" %s", input);

        if(strcmp(input, "q") == 0 || strcmp(input, "exit") == 0)
        {

            finished++;
            fprintf(stdout, "Exiting... goodbye!");

        }
        else if(strcmp(input, "k") == 0)
        {

            fprintf(stdout, "Current key: %s\n", key);

        }
        else if(strcmp(input, "nk") == 0)
        {

            fprintf(stdout, "Enter a new key:");
            scanf(" %[^\n]%*c", key);

        }
        else if(strcmp(input, "e") == 0)
        {

            char inputFileName[100], outputFileName[100];
            FILE *inputFile, *outputFile;

            fprintf(stdout, "Enter the input file:");
            scanf(" %s", inputFileName);

            if((inputFile = fopen(inputFileName, "r"))==NULL)
            {

                fprintf(stderr, "ERROR: Could not open input file");
                continue;//Breaks out of the if

            }

            fprintf(stdout, "Enter the output file:");
            scanf(" %s", outputFileName);

            if((outputFile = fopen(outputFileName, "w"))==NULL)
            {

                fprintf(stderr, "ERROR: Could not open output file");
                continue;

            }

            encrypt(inputFile, outputFile, key);

            fclose(inputFile);
            fclose(outputFile);

        }
        else if(strcmp(input, "d") == 0)
        {

            char inputFileName[100], outputFileName[100];
            FILE *inputFile, *outputFile;

            printf("Enter the input file:");
            scanf(" %s", inputFileName);

            if((inputFile = fopen(inputFileName, "r"))==NULL)
            {

                fprintf(stderr, "ERROR: Could not open input file");
                continue;

            }

            printf("Enter the output file:");
            scanf(" %s", outputFileName);

            if((outputFile = fopen(outputFileName, "w"))==NULL)
            {

                fprintf(stderr, "ERROR: Could not open output file");
                continue;

            }

            decrypt(inputFile, outputFile, key);

            fclose(inputFile);
            fclose(outputFile);

        }
        else
        {

            fprintf(stderr, "Error: Invalid input\n");

        }

    }
    
    return 0;//Program exited normally
    
}