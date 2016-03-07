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
	else
	{
		
		printf("Invalid usage. Run with -help for help.");
		return 1;
		
	}
	
	return 0;
	
}


