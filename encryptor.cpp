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

void decryptFile(char[], char[], char[]);
void encryptFile(char[], char[], char[]);

int strcomp(char[], char[]);
char encryptChar(char, char);
unsigned long hash(char*);

int main()
{
	
	int finished = 0;
	
	printf("Menu:\n\nk - Displays the current encryptor key\nnk - Sets a new encryptor key\n");
	printf("ef - Encrypt a file and write it to the given file - you must include file extension (.txt)\n");
	printf("df - Decrypt a file and write the result to a given file - you must include file extension (.txt)\n");
	printf("q - Exit the program\n\n");
	
	char input[3], key[1000];
		
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
		else if(strcomp(input, "ef"))
		{
			
			char inFile[100], outFile[100];
			
			printf("Enter the input file:");
			scanf(" %s", inFile);
			
			printf("Enter the output file:");
			scanf(" %s", outFile);
			
			encryptFile(inFile, outFile, key);
			
		}
		else if(strcomp(input, "df"))
		{
			
			char inFile[100], outFile[100];
			
			printf("Enter the input file:");
			scanf(" %s", inFile);
			
			printf("Enter the output file:");
			scanf(" %s", outFile);
			
			decryptFile(inFile, outFile, key);
			
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
void encryptFile(char nameIn[], char nameOut[], char key[])
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
		
		//If the character to write is a newline (\n)
		//Write a new line to the file
		//if(cipher == '\n')
			//fprintf(out, "\n");
		//else
			fputc(cipher, out);
	
	}
	
	//Close everything
	fclose(in);
	fclose(out);
	
}

//Decrypts, char by char, FILE in and writes the result to FILE out.
void decryptFile(char nameIn[], char nameOut[], char key[])
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

//Modified String compare function, simply return 1 if str1 and str2 are equal
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
