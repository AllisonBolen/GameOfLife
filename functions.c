#include <stdlib.h>
#include <stdio.h>

int read_file( char* filename, char **buffer ){
  FILE* in = fopen(filename, "r");

  int i, j;

  if (in == NULL){
    printf ("file could not be opened!\n");
    exit(1);
  }
  else{
    int sz;
    fseek(in,0L, SEEK_END);
    sz=ftell(in);
    *buffer = malloc(sz * sizeof(char));
    rewind(in);
    fread(*buffer,sz,1,in);
    printf("%s", buffer);

    int r = 5;
    int c = 4;
    char **arr = (int **)malloc(r*sizeof(char *));

   for(i=0; i < r; i++){
        arr[i]=(int *) malloc(c * sizeof(char *));
   }

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            fread(arr[i][j], sz, 1, in);
        }
    }

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%s", arr[i][j]);
        }
       printf("\n");
    }

    return 0;
  }
}

int write_file( char* filename, char *buffer, int size){
  FILE* out = fopen(filename, "w");


}

int makeBoard(char **array, int r, int c){

}
