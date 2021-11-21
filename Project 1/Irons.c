#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *create_map(char *key);
char encrypt(char ch, char *map);
char decrypt(char ch, char *map);
#define SIZE (100)

int main(int argc, char* argv[])
{  
	int choice;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption\n");
		exit(1);
	}
	

	char key[100];
	strcpy(key, argv[2]);
	char *map = create_map(key);
	

	
	fin = fopen(argv[1], "r");
	fout = fopen(argv[3], "w");
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened!\n");
		exit(1);
	}
	
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		if (strcmp(argv[4],"e")==0)
		{
			fprintf(fout, "%c", encrypt(ch, map));
		}
		else
		{
			fprintf(fout, "%c", decrypt(ch, map));
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char *create_map(char *key)
{
	char alph[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	for(int i=0; key[i]!='\0'; i++)
    	{
    		if(islower(key[i]))
    		{
            		key[i] = key[i] - 32;
            	}
        		
    	}
	char map[100];
	strcpy(map, key);
	strcat (map, alph);
	for(int i = 0; i < strlen(map); i++)
  	{
  		for(int j = i + 1; map[j] != '\0'; j++)
  		{
  			if(map[j] == map[i])  
			{
  				for(int k = j; map[k] != '\0'; k++)
				{
					map[k] = map[k + 1];
				}
 			}
		}
	}
	char *final = malloc(SIZE);
	strcpy(final, map);
	return final;
}

char encrypt(char ch, char *map)
{
	char alphabetU[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetL[] = "abcdefghijklmnopqrstuvwxyz";
	char newAlph[27];
	strcpy(newAlph, map);
	if(isupper(ch))
	{
		for(int i=0; i<strlen(alphabetU); i++)
		{
			if(ch == alphabetU[i])
			{
				ch = newAlph[i];
				return ch;
			}
		}
	}
	if(islower(ch))
	{
		for(int i=0; newAlph[i]!='\0'; i++)
    		{
            		newAlph[i] = newAlph[i] + 32;
        		
    		}
		for(int i=0; i<strlen(alphabetL); i++)
		{
			if(ch == alphabetL[i])
			{
				ch = newAlph[i];
				return ch;
			}
		}
	}
	
	return ch;
}

char decrypt(char ch, char *map)
{
	char alphabetU[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetL[] = "abcdefghijklmnopqrstuvwxyz";
	char newAlph[27];
	strcpy(newAlph, map);
	if(isupper(ch))
	{
		for(int i=0; i<strlen(alphabetU); i++)
		{
			if(ch == newAlph[i])
			{
				ch = alphabetU[i];
				return ch;
			}
		}
	}
	if(islower(ch))
	{
		for(int i=0; newAlph[i]!='\0'; i++)
    		{
            		newAlph[i] = newAlph[i] + 32;
        		
    		}
		for(int i=0; i<strlen(alphabetL); i++)
		{
			if(ch == newAlph[i])
			{
				ch = alphabetL[i];
				return ch;
			}
		}
	}
	
	return ch;
}

