#include <stdlib.h>
#include <stdio.h>

int read_file( char* filename, char **buffer ){
  FILE* in = fopen(filename, "r");

  
  if (in == NULL){
    printf ("file could not be opened!\n");
    exit(1);
  }
  else{
    printf("Please enter the number of rows.\n");
    int row;
    scanf(" %d", &row);
    printf("Please enter the number of columns.\n");
    int column;
    scanf(" %d", &column);
    *buffer = malloc(row * column * sizeof(char));
    printf("%d%d\n", row,column);
    
    while ( ! feof(filename) ) {
      fscanf (filename, "%d", &ch );
      
    }

    return 0;
  }
}


int write_file( char* filename, char *buffer, int size){
  FILE* out = fopen(filename, "w");
  
  
}

