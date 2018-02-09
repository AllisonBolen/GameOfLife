#include <stdio.h>
#include <stdlib.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char* buffer;
  char** board;
  int size = read_file( argv[1], &buffer );
  printf("%s", buffer);
  int r,c,i,j; 
  printf ("\nHow many rows do you have?\n");
  scanf("\n%d",&r);
  printf("\nrows: %d",r);
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",&c);
  printf("\ncolumns: %d",c);
  printf ("\nMakeBoard:\n");
  makeBoard(r, c, &board, buffer);
  printf("\n It didnt work\n ");
  printf("\n");
  return 0;

}
