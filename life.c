#include <stdio.h>
#include <stdlib.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char response;
  char* buffer;
  char** board;
  int size = read_file( argv[1], &buffer );
  printf("%s", buffer);
  int *r, *c;
  boardDimensions(&r,&c);
  makeBoard(&r,&c, &board, buffer);
  return 0;




  while(response != 'q'){
    //  calc board?
    // after each check ask user what they want

    // if resp = s
    // write to file
    // ask again?

    // if resp load
    // free all boards and buffers
    // read from filename
    // ask for loop nums?

    // if resp = c
    // run once for a new single generation
    // ask for what to do next
 
    // if reps = cn
    // loop for that many generations
    // ask user what to do next
  }
    // if resp = q
    // free baords and buffers
    // system exit with  0
}
