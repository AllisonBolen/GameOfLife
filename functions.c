#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_file( char* filename, char **buffer ){
  FILE* in = fopen(filename, "r");

  if (in == NULL){
    printf ("file could not be opened!\n");
    return -1;
    exit(1);
  }
  else{
    int sz;
    fseek(in,0L, SEEK_END);
    sz=ftell(in);
    *buffer = malloc(sz * sizeof(char));
    rewind(in);
    fread(*buffer,sz,1,in);
    return sz;
  }
}

int write_file( char* filename, char *buffer, int size){
  FILE* out = fopen(filename, "w");
}

void makeBoard(int r, int c, char ***board, char *buffer){
  int i, j, count;
  for (i = 0; i < strlen(buffer); i++){
    if(buffer[i] == '\n'){
    }
    else{
      printf("A: %c, ", buffer[i]);
    }               
	printf("\n");
  }

    //allocate space for the rows of the array to hold an array
    *board = (char **) malloc(r * sizeof(char *));
    for (i=0; i<r; i++)
         // allocate space for the array 
         (*board)[i] = (char *) malloc(c * sizeof(char));
    count = 0; 
    for (i = 0; i < r; i++){
      for (j = 0; j < c; j++){
         if(buffer[count] != 10){
           printf("B: %c\n", buffer[count]);
           (*board)[i][j] = buffer[count];  
           count++;
          }
        else{ 
          count = count + 2;
         }
       }
     }
    for (i = 0; i <  r; i++){
      for (j = 0; j < c; j++){
         printf("%c ", (*board)[i][j]);
      }
	printf("\n");
   }
}
