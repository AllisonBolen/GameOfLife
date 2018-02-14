#include "functions.h"

int main(int argc, char** argv){
  int row, col;
  char response;
  char* buffer; 
  char** board;
  char fileName;
  char stringBoard;
 // char saveFileName;
  char** checkBoard;
 // printBuffer(buffer); 
  // start logic and populate and ize %d", temp);
  // alloc argv[1] is file name from user
  printf("\nfileName: %s", argv[1]);
 // int size;
  int size = read_file((char*)argv[1], &buffer);
  printf("\nsize: %d\n",size); 
 // int temp = size;
  boardDimensions(&row, &col);
  printf("\nrow: %d\ncol: %d\n\n", row, col);  
 // printBuffer(buffer);
  makeBoard(row, col, &board);  
  populateBoard(board, buffer, row, col);
  printBoard(board, row, col);  
  
//  int temp = size; 
  printf("\nsize %d\n", size);

 // printf("\nbuffer before save:\n%s",buffer);

 // userResponse(&response);
 // printf("\nResponse: %c\n",response);

 // printBoard(board, row, col);
  
  char saveFileName[1000];
 // char tempfile = saveFileName;
  char temparray;
  userResponse(&temparray);
  response = temparray;
  
  while(response != 'q'){
  //  printBoard(board, row, col);
  //  userResponse(&temparray);
   // response = temparray;
    printf("\nResponse: %c\n",response);
    printf("\n Board just entering the loop\n");
    printBoard(board, row, col);

    if(response == 'l'){
      free(buffer);
      freeMem(board, row, col);
      
      getFileFromUser(saveFileName);
      
      size = read_file(saveFileName, &buffer);
      printBuffer(buffer);
      
      boardDimensions(&row, &col);
      printf("\nrow: %d\ncol: %d\n\n", row, col);
      
      makeBoard(row, col, &board);
      populateBoard(board, buffer, row, col);
      printBoard(board, row, col);
    
    }
    
    else if(response == 's'){
      printf("\nboard just after entering s loop:\n");
      printBoard(board, row, col);
      saveFileTo(saveFileName);
      printf("\nsaveFileName: %s\n", saveFileName);

      printf("\nsize %d", size);
      printf("\nBuffer after goint into saveFileTo:\n");
      printBuffer(buffer);
      printf("\nBoard after goint into saveFileTo:\n");
      printBoard(board, row, col);
      
      write_file(saveFileName, buffer, size);
      printf("\nBuffer after goint into writeFile:\n");
      printBuffer(buffer);
      printf("\nBoard after goint into writeFile:\n");
      printBoard(board, row, col);
    }

    else if(response == 'c'){

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
