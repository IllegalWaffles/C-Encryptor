/*

Below is a program to encrypt and decrypt
plaintext files. Utilizes a one-time-pad
style method. This should take a rather long
time to break.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char toChar(int in);
int toInt(char in);

void decrypt(char[], char[], char[]);
void encrypt(char[], char[], char[]);

int strcomp(char[], char[]);
char encryptChar(char, char);
unsigned long hash(char*);

int main(int argc, char *argv[])
{
	
	char input[3], key[1000];
	int fullOutputMode = 1;
	
	if(argc == 1)
		;//Do nothing
	else if(argc == 2 && strcmp(argv[1], "-help") == 0)
	{
		
		printf("Usage:\nTODO\n");
		
		return 0;
		
	}
	else if(argc == 4 && strcmp(argv[1], "-e") == 0)
	{
				
		//Encrypt file arguments with default key
		encrypt(argv[2], argv[3], "");
		return 0;
			
	}
	else if(argc == 4 && strcmp(argv[1], "-d") == 0)
	{
			
		//Decrypt file arguments with default key
		decrypt(argv[2], argv[3], "");
		return 0;
			
	}
	else if(argc == 5 && strcmp(argv[1], "-e") == 0)
	{
	
		//Encrypt file arguments
		encrypt(argv[2], argv[3], argv[4]);
		return 0;
			
	}
	else if(argc == 5 && strcmp(argv[1], "-d") == 0)
	{
			
		//Decrypt file arguments
		decrypt(argv[2], argv[3], argv[4]);
		return 0;
		
	}
	else
	{
		
		printf("Invalid usage. Run with -help for help.");
		return 1;
		
	}
	
	int finished = 0;
	
	printf("Menu:\n\nk - Displays the current encryptor key\nnk - Sets a new encryptor key\n");
	printf("e - Encrypt a file and write it to the given file - you must include file extension (.txt)\n");
	printf("d - Decrypt a file and write the result to a given file - you must include file extension (.txt)\n");
	printf("q - Exit the program\n\n");
		
	key[0] = '\0';
	
	while(!finished){
	
		printf("> ");
		scanf(" %s", input);
		
		if(strcomp(input, "q") || strcomp(input, "exit"))
		{
			
			finished++;
			printf("Exiting... goodbye!");
			
		}
		else if(strcomp(input, "k"))
		{
			
			printf("Current key: %s\n", key);
			
		}
		else if(strcomp(input, "nk"))
		{
			
			printf("Enter a new key:");
			scanf(" %s", key);
			
		}
		else if(strcomp(input, "e"))
		{
			
			char inFile[100], outFile[100];
			
			printf("Enter the input file:");
			scanf(" %s", inFile);
			
			printf("Enter the output file:");
			scanf(" %s", outFile);
			
			encrypt(inFile, outFile, key);
			
		}
		else if(strcomp(input, "d"))
		{
			
			char inFile[100], outFile[100];
			
			printf("Enter the input file:");
			scanf(" %s", inFile);
			
			printf("Enter the output file:");
			scanf(" %s", outFile);
			
			decrypt(inFile, outFile, key);
			
		}
	
	
	}
	
	return 0;
	
}

//Converts an int into the correct char
char toChar(int in)
{
	
	if(in == 95)
		return '\n';
	
	return (char)(in+32);
	
}

//Converts a character into the correct integer
int toInt(char in)
{
	
	if(in == '\n')
		return 95;
	
	return in-32;
	
}

//Encrypts, char by char, FILE in and writes the result to FILE out.
void encrypt(char nameIn[], char nameOut[], char key[])
{
	
	srand(hash(key));
	
	FILE* in = fopen(nameIn, "r");
	FILE* out = fopen(nameOut, "w");
	char c, cipher, keyChar;
	
	//While the input file has text
	while((c = fgetc(in)) != EOF)
	{
	
		//Generate a new key value
		keyChar = (rand()%96) + 32;
		
		//Calculate the cipher value
		cipher = toChar((toInt(c) + toInt(keyChar))%96);
		
		fputc(cipher, out);
	
	}
	
	//Close everything
	fclose(in);
	fclose(out);
	
}

//Decrypts, char by char, FILE in and writes the result to FILE out.
void decrypt(char *nameIn, char *nameOut, char *key)
{
	
	srand(hash(key));
	
	FILE* in = fopen(nameIn, "r");
	FILE* out = fopen(nameOut, "w");
	char c, plainText, keyChar;
	
	//While the input has data
	while((c = fgetc(in)) != EOF)
	{
	
		//Generate a new key value
		keyChar = (rand()%96) + 32;
		
		//Generate the plaintext value
		plainText = toInt(c) - toInt(keyChar);
		
		if(plainText < 0)
			plainText+=96;
		
		plainText = toChar(plainText);
		
		//Write the final char
		fputc(plainText, out);
	
	}
	
	//Close everything
	fclose(in);
	fclose(out);
	
}

//Modified String compare function, simply return 1 if str1 and str2 are equal, 0 otherwise
int strcomp(char str1[], char str2[])
{
	
	return strcmp(str1, str2) == 0;
	
}

//Hashing function - credit goes to dan bernstein
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}
