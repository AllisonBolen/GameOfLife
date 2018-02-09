#include <stdio.h>
#include <stdlib.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char* buffer;
  char** board;
  int size = read_file( argv[1], &buffer );
  printf("%s", buffer);
  int *r, *c;
  loop(&r,&c);
  makeBoard(&r,&c, &board, buffer);
  return 0;
}
