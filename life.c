#include <stdio.h>
#include <stdlib.h>
//#include <library.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char* buffer;
  //buffer = malloc(500 * sizeof(char));
  read_file( argv[1], &buffer );
  printf("%s", buffer);

  printf ("\nWould you like to save the file type Y for yes or N for no.\n");
  makeBoard();
  printf("\n It didnt work");
}
