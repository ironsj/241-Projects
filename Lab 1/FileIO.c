#include <stdio.h>
#include <stdlib.h>
int main(int argc)   
{
      if(argc > 1){
      printf("This program does not allow more than one command-line arguments!\n");
      exit(1);
      }
      char ch;
      FILE *in, *out;
      in = fopen ("input.txt","r" );
      out = fopen ("output.txt", "w" );
      if ( in == NULL || out == NULL )	
      {
	printf ( "file could not be opened!\n" );
	exit (1);
      }
      while ( ! feof(in) )   {
	fscanf ( in, "%c", &ch );
	if(ch >= 'A' && ch <= 'Z'){
      	ch = 'a' - 'A' + ch;
      	}
      	else if(ch >= 'a' && ch <= 'z'){
      	ch = ch - 32;
      	}
      	else{
	ch = ch;
	}
	fprintf ( out, "%c", ch );
      }
      fclose(in);
      fclose(out);
      return 0;
}

