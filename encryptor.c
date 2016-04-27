/*

Below is a program to encrypt and decrypt
plaintext files. Utilizes a one-time-pad
style method. This should take a rather long
time to break.

Author - Kuba Gasiorowski

*/

#include "func.h"
#include <String.h>

/*

	Usages:
		no arguments - run with ui
		three arguments - first flag determines encrypt or decrypt,
						  second arg is input file,
						  third arg is output file,
						  reads in key value				  
		

*/


int main(int argc, char *argv[])
{
		
	if(argc == 1)
	{
		
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
				printf("Exiting... goodbye!");
				
			}
			else if(strcmp(input, "k") == 0)
			{
				
				printf("Current key: %s\n", key);
				
			}
			else if(strcmp(input, "nk") == 0)
			{
				
				printf("Enter a new key:");
				scanf(" %[^\n]%*c", key);
				
			}
			else if(strcmp(input, "e") == 0)
			{
				
				char inputFileName[100], outputFileName[100];
				FILE *inputFile, *outputFile;
				
				printf("Enter the input file:");
				scanf(" %s", inputFileName);
				
				if((inputFile = fopen(inputFileName, "r"))==NULL)
				{
					
					printf("ERROR: Could not open input file");
					continue;//Breaks out of the if
					
				}
				
				printf("Enter the output file:");
				scanf(" %s", outputFileName);
				
				if((outputFile = fopen(outputFileName, "w"))==NULL)
				{
					
					printf("ERROR: Could not open output file");
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
					
					printf("ERROR: Could not open input file");
					continue;
					
				}
				
				printf("Enter the output file:");
				scanf(" %s", outputFileName);
				
				if((outputFile = fopen(outputFileName, "w"))==NULL)
				{
					
					printf("ERROR: Could not open output file");
					continue;
					
				}
				
				decrypt(inputFile, outputFile, key);
				
				fclose(inputFile);
				fclose(outputFile);
				
			}
			else
			{
			
				printf("Error: Invalid input\n");
			
			}
		
		
		}
		
	}else if(argc == 4){
		
		char *flag, key[100];
		FILE *input, *output;
		
		flag = argv[1];
		
		if((input = fopen(argv[2],"r")) == NULL)
		{
		
			printf("ERROR: Could not open input file");
			return 1;
		
		}
		
		if((output = fopen(argv[3], "w")) == NULL)
		{
		
			printf("ERROR: Could not open input file");
			return 1;
		
		}
		
		printf("Enter a key:");
		scanf(" %[^\n]%*c", key);
		
		if(strcmp(flag, "-d") == 0)
		{
		
			printf("test 2");
			decrypt(input,output,key);
		
		}
		else if(strcmp(flag, "-e") == 0)
		{
		
			encrypt(input,output,key);
			
		}
	
	}
	else
	{
		
		printf("Usage:\n");
	
	}
	
	return 0;
	
}


