#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

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

void makeBoard(int *r, int *c, char ***board, char *buffer){
  int i, j, count;
    // allocate space for the rows of the array to hold an array 
    *board = (char **) malloc(*r * sizeof(char *));
    for (i=0; i<*r; i++)
         // allocate space for the array 
         (*board)[i] = (char *) malloc(*c * sizeof(char));
    count = 0; 
    for (i = 0; i < *r; i++){
      for (j = 0; j <= *c; j++){
         if(buffer[count] != 10){ // comparing ascii value of new lines to whats in our buffer
           (*board)[i][j] = buffer[count];  
           count++;
          }
        else{ 
          count++;
         }
       }
     }
    for (i = 0; i < *r; i++){
      for (j = 0; j < *c; j++){
         printf("%c ", (*board)[i][j]);
      }
	printf("\n");
   }
}

void boardDimensions(int *r, int *c){
  printf ("\nHow many rows do you have?\n");
  scanf("\n%d",r);
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",c);
  printf("\nMakeBoard:\n");
  }
