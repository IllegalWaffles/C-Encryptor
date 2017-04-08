/*

Below is a program to encrypt and decrypt
plaintext files. Utilizes a one-time-pad
style method.

Author - Kuba Gasiorowski

*/

#include "encr_func.h"
#include "helpers.h"
#include <string.h>

static Arg_data *argdata;

int main(int argc, char *argv[])
{

    argdata = parse_args(argv, argc);
    
    if(argdata->error == true)
        usage(EXIT_FAILURE);
    
    if(argdata->ui){

        finish(prgm_ui());

    }else{
    
        FILE *in, *out;
        
        //Parse infile
        if(argdata->infile)
            if((in = fopen(argdata->infile_val, "r")) == NULL){
            
                fprintf(stderr, "Could not open input file \"%s\"\n", argdata->infile_val);
                fflush(stderr);
                finish(EXIT_FAILURE);
                
            }
        else
            in = DEFAULT_FILE_IN;
        
        //Parse outfile
        if(argdata->outfile)
            if((out = fopen(argdata->outfile_val, "w")) == NULL){
            
                fprintf(stderr, "Could not open output file \"%s\"\n", argdata->outfile_val);
                fflush(stderr);
                finish(EXIT_FAILURE);
                
            }
        else
            out = DEFAULT_FILE_OUT;
        
        //Parse key
        char *key = (char*)calloc(MAX_KEY_LENGTH, sizeof(char));
        
        if(argdata->key)
            strcpy(argdata->key_val, key);
        else
            strcpy("", key);
            
        if(argdata->encr){
            
            decrypt(in, out, key);
            
        }else if(argdata->decr){
        
            encrypt(in, out, key);
        
        }else{
        
            fprintf(stderr, "Error: cannot do both or neither encryption and decryption\n");
            fflush(stderr);
            finish(EXIT_FAILURE);
                
        }
    
    }

    finish(EXIT_SUCCESS);
	
}

//Exits the program, freeing all memory in the process
void finish(int retcode){
    
    free(argdata);
    exit(retcode);
    
}
