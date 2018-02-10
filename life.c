#include <stdio.h>
#include <stdlib.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char response;
  char* buffer;
  char* fileName;
  char** board;
  char* saveFileName;
  int size = read_file( argv[1], &buffer );
  printf("%s", buffer);
  int *r, *c;
  boardDimensions(&r,&c);
  makeBoard(&r,&c, &board, buffer);

  userResponse(&response);
  printf("\nResponse: %c\n",response);
  char userArray = response;

  printf("\nuserArray: %c\n", userArray);

  while(userArray != 'q'){
    if(userArray == 'l'){
      getFileFromUser(&saveFileName);

      // free all boards and buffers
    //  freeMem(&board, &buffer, &r, &c);
      // read from filename
      // ask for loop nums?
    }
    
    if(userArray == 's'){
      // write to file
      int row, col;
      saveFileTo(&saveFileName);
      boardDimensions(&row,&col);
      int size = (row *col);
      printf("\nsize %d", size);
      printf("\nbuffer before save:\n%s",buffer);
      write_file(&saveFileName, buffer, size);
    }

    if(userArray == 'c'){
      // run once for a new single generation
    }

    if(userArray == 'n'){
      // loop for that many generations
    }
    userResponse(&response);
    userArray = response;
  }

  if(userArray == 'q'){
    // free baords and buffers
    freeMem(&board, &buffer, &r, &c);
    // system exit with  0
    return 0;
  }
  return 0;
}
