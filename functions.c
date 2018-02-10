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
  int cols;
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",&cols);
  int i; 
  int j;
  char temparray[size];
  printf("Buffer:\n%s\n", buffer);
  for(i=0; i<size+cols; i++){
    printf("buffer at i: %c\n",buffer[i]);
    temparray[i] = buffer[i];
    if(j==cols){
     fprintf(out, "%c", temparray[i]);
     j = 0;
    }
    fprintf(out, "%c",temparray[i]);
    j++;
  }
  printf("File has been saved successfully would you like to do anything else?\n");
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

void userResponse(char *resp){
  printf("\nWhat would you like to do next?\n");
  printf("\nSave: s\n");
  printf("\nLoad: l\n");
  printf("\nContinue Once: c\n");
  printf("\nContinue Multiple: n\n");
  printf("\nQuit: q\n");
  printf("\nYour response: ");
  scanf("\n%s",resp);
}

void getFileFromUser(char *fileName){
  printf("\nWhat file would you like to read from:\n");
  printf("\nFile: ");
  scanf("\n%s", fileName);
}

void saveFileTo(char *fileName){
  printf("\nWhat file would you like to save to:\n");
  printf("\nFile: ");
  scanf("\n%s", fileName);

}

void freeMem(char ***board, char **buffer, int *r, int *c){
  int i;
  //free columns
  for(i = 0; i < *r; i++){
    free((*board)[i]);
  }
  //free whole thing
  free((*board));
}
