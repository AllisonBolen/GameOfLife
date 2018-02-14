#include "functions.h"

int main(int argc, char** argv){
  int row, col;
  char response;
  char* buffer; 
  char** board;
  char fileName;
  char* stringBoard;
  int** checkBoard;
  printf("\nfileName: %s", argv[1]);
  int size = read_file((char*)argv[1], &buffer);
  printf("\nsize: %d\n",size); 

  boardDimensions(&row, &col);
  printf("\nrow: %d\ncol: %d\n\n", row, col);  
  makeBoard(row, col, &board);  
  populateBoard(board, buffer, row, col);
  printBoard(board, row, col);  

  makeCheck(row, col, &checkBoard);
  populateCheck(row, col, checkBoard);
  printCheckBoard(checkBoard, row, col);
  //printf("\nsize %d\n", size);
  
  char saveFileName[1000];
  char temparray;
  userResponse(&temparray);
  response = temparray;
  
  while(response != 'q'){
    printf("\nResponse: %c\n",response);
    printf("\n Board just entering the loop\n");
    printBoard(board, row, col);

    if(response == 'l'){
      free(buffer);
      freeMem(board, row, col);
      
      getFileFromUser(saveFileName);
      
      size = read_file(saveFileName, &buffer);
     // printBuffer(buffer);
      
      boardDimensions(&row, &col);
      printf("\nrow: %d\ncol: %d\n\n", row, col);
      
      makeBoard(row, col, &board);
      populateBoard(board, buffer, row, col);
      printBoard(board, row, col);
    
    }
    
    else if(response == 's'){
     // printf("\nboard just after entering s loop:\n");
     // printBoard(board, row, col);
      saveFileTo(saveFileName);
      printf("\nsaveFileName: %s\n", saveFileName);

     // printf("\nsize %d", size);
     // printf("\nBuffer after goint into saveFileTo:\n");
     // printBuffer(buffer);
     // printf("\nBoard after goint into saveFileTo:\n");
     // printBoard(board, row, col);
      toStringBoard(board, buffer, row, col);
      write_file(saveFileName, buffer, size);
     // printf("\nBuffer after goint into writeFile:\n");
     // printBuffer(buffer);
     // printf("\nBoard after goint into writeFile:\n");
     //  printBoard(board, row, col);
    }

    else if(response == 'c'){
      int n, m;
      for(n = 0; n < row; n++){
        for(m = 0; m < col; m++){
          getNeighbors(board, checkBoard, n, m, row, col);
        }
      }
      printCheckBoard(checkBoard, row, col);
    }

    else if(response == 'n'){

    }

    printf("\nbuffer at the end of loop:\n");
    printBuffer(buffer);
    printf("\nboard at the end of the loop:\n");
    printBoard(board, row, col);
    
    userResponse(&temparray);
    response = temparray;
    printf("\nResponse: %c\n",response);
  }
  // out of loop
  free(buffer);
  freeMem(board, row, col);
  //freemem(checkBoard, row, col);
  return 0;
 }
