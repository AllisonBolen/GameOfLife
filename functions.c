#include <stdlib.h>
#include <stdio.h>

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

void makeBoard(int r, int c, char **board, char buffer){
  int i, j;
    printf("buffer contents: %s\n", buffer);
    printf("row: %d\n", row);
    printf("column: %d\n", col);
    **board = malloc(r * sizeof(char *));
    for (i=0; i<r; i++)
         board[i] = malloc(c * sizeof(char));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         board[i][j] = buffer[1];  // OR *(*(arr+i)+j) = ++count

    for (i = 0; i <  r; i++){
      for (j = 0; j < c; j++){
         printf("%d ", board[i][j]);
      }
	printf("\n");
   }
}

// int r = 5;
// int c = 4;
// char **arr = (int **)malloc(r*sizeof(char *));
//
// for(i=0; i < r; i++){
//     arr[i]=(int *) malloc(c * sizeof(char *));
// }
//
// for(i = 0; i < r; i++){
//     for(j = 0; j < c; j++){
//         fread(arr[i][j], sz, 1, in);
//     }
// }
//
// for(i = 0; i < r; i++){
//     for(j = 0; j < c; j++){
//         printf("%s", arr[i][j]);
//     }
//    printf("\n");
// }
