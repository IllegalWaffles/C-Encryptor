/*

Below is a program to encrypt and decrypt
plaintext files. Utilizes a one-time-pad
style method. This should take a rather long
time to break.

Author - Kuba Gasiorowski

*/

#include "func.h"

int main(int argc, char *argv[])
{
	
	if(argc == 2 && strcmp(argv[1], "-help") == 0)
	{
		
		printf("Usage:\nTODO\n");
		
		return 0;
		
	}
	else if(argc == 3 && strcmp(argv[1], "-e") == 0)
	{
		
		FILE *input;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		encrypt(input, stdout, "");
		return 0;
		
	}
	else if(argc == 3 && strcmp(argv[1], "-d") == 0)
	{
		
		FILE *input;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		decrypt(input, stdout, "");
		return 0;
		
	}
	else if(argc == 4 && strcmp(argv[1], "-e") == 0)
	{
				
		//Encrypt file arguments with default key
		FILE *input, *output;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		output = fopen(argv[3], "w");
		
		encrypt(input, output, "");
		return 0;
			
	}
	else if(argc == 4 && strcmp(argv[1], "-d") == 0)
	{
			
		//Decrypt file arguments with default key
		FILE *input, *output;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		output = fopen(argv[3], "w");
		
		decrypt(input, output, "");
		return 0;
			
	}
	else if(argc == 5 && strcmp(argv[1], "-e") == 0)
	{
	
		//Encrypt file arguments
		FILE *input, *output;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		output = fopen(argv[3], "w");
		
		encrypt(input, output, argv[4]);
		return 0;
			
	}
	else if(argc == 5 && strcmp(argv[1], "-d") == 0)
	{
			
		//Decrypt file arguments
		FILE *input, *output;
		if((input = fopen(argv[2], "r")) == NULL)
		{
			
			printf("ERROR: Could not open input file");
			return 1;
			
		}
		
		output = fopen(argv[3], "w");
		
		decrypt(input, output, argv[4]);
		return 0;
		
	}
	else if(argc == 2 && strcmp(argv[1], "-ui") == 0)
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
					break;//Breaks out of the if
					
				}
				
				printf("Enter the output file:");
				scanf(" %s", outputFileName);
				
				outputFile = fopen(outputFileName, "w");
				
				encrypt(inputFile, outputFile, key);
				
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
					break;//Breaks out of the if
					
				}
				
				printf("Enter the output file:");
				scanf(" %s", outputFileName);
				
				decrypt(inputFile, outputFile, key);
				
			}
		
		
		}
		
	}
	else
	{
		
		printf("Invalid usage. Run with -help for help.");
		return 1;
		
	}
	
	return 0;
	
}


