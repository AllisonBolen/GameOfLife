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
 // printf("%s", buffer);
  int *r, *c;
  char** checkBoard;
  char** newBoard;

  printBuffer(buffer, &r, &c); 
  boardDimensions(&r,&c);
  makeBoard(&r,&c, &board, buffer);
  // allocate stuff for the check boards
  makeCheck(&r, &c, &checkBoard);
  populateCheck(&r, &c, &checkBoard);
  printCheckBoard(&checkBoard, &r, &c); 

  makeBoard(&r, &c, &newBoard, buffer);


  populateBoard(&board, buffer, &r, &c);
  printBoard(&board, &r, &c);

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
      printBuffer(buffer, &row, &col);
      write_file(&saveFileName, buffer, size);
    }

    if(userArray == 'c'){
      // run once for a new single generation
      int i, j, rowNum, colNum;
      boardDimensions(&rowNum, &colNum);
      printf("C 1 gen one\n");
      printCheckBoard(&checkBoard, &r, &c); 
      printBoard(&board, &r, &c);
      printf("\nrow: %d\n",rowNum);
      printf("\ncol: %d\n", colNum);
      //for(i = 0 ; i <  rowNum; i++){
        //for(j = 0; j < colNum; j++){
         printf("this is where i am");
         overCrowding(&buffer, &checkBoard, 0, 0, rowNum, colNum);
        //}
      //}
     printCheckBoard(&checkBoard, &r, &c);
    }

    if(userArray == 'n'){
      // loop for that many generations
    }
    userResponse(&response);
    userArray = response;
  }

  if(userArray == 'q'){
    int m, n;
    printf("\nbuffer before free:\n%s",buffer);
    free(buffer);
    printf("\nbuffer after free:\n%s",buffer);
    
  //  printf("\nboard before free:\n%s",(*board));
    printBoard(&board, &r, &c);
    freeMem(&board, &r, &c);
    printf("\nboard after free:\n");
    printBoard(&board, &r, &c);

   // printf("\nr :%d",r);

/*
    for(n = 0; n <(int)*r; n++){
      for(m = 0; m <(int)*c; m++){
        printf("\nboard: %d\n", board[n][m]);
       // free(board[n][m]);
      }
     // free(board[n]);
    }
 */      //free whole thing
       //    free(board);
       //
    // free(buffer);
    //printf("\nboard after free:\n%s",(*board)[1]);


    // free baords and buffers
 //  freeMem(&*board, &buffer, &r, &c);
    // system exit with  0
    return 0;
  }
  return 0;
}
