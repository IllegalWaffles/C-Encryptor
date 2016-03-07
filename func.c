#include "func.h"

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
void encrypt(FILE *inputFile, FILE *outputFile, char key[])
{
	
	srand(hash(key));
	char c, cipher, keyChar;
	
	//While the input file has text
	while((c = fgetc(inputFile)) != EOF)
	{
	
		//Generate a new key value
		keyChar = (rand()%96) + 32;
		
		//Calculate the cipher value
		cipher = toChar((toInt(c) + toInt(keyChar))%96);
		
		fputc(cipher, outputFile);
	
	}
	
}

//Decrypts, char by char, FILE in and writes the result to FILE out.
void decrypt(FILE *inputFile, FILE *outputFile, char key[])
{
	
	srand(hash(key));
	char c, plainText, keyChar;
	
	//While the input has data
	while((c = fgetc(inputFile)) != EOF)
	{
	
		//Generate a new key value
		keyChar = (rand()%96) + 32;
		
		//Generate the plaintext value
		plainText = toInt(c) - toInt(keyChar);
		
		if(plainText < 0)
			plainText+=96;
		
		plainText = toChar(plainText);
		
		//Write the final char
		fputc(plainText, outputFile);
	
	}
	
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
