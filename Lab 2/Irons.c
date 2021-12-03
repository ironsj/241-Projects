#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k);

int main(int argc, char* argv[])
{  
	int choice, key;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption\n");
		exit(1);
	}
	
	char word[5];
	strcpy(word, argv[2]);
	int a[4] = {};
	for(int i=0; i<4; ++i)
	{
		a[i]=word[i] - 'A';
	}
	
	int n = 0;
	key = a[n];
	if (strcmp(argv[4],"d")==0)  //decryption
	{
		key = -key;
	}
	
    	fin = fopen(argv[1], "r");
	fout = fopen(argv[3], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened!\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt_decrypt(ch, key));
		n = (n+1) % 4;
		key = a[n];
		if (strcmp(argv[4],"d")==0)
		{
			key = -key;
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt_decrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}

