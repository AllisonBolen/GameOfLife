#include "functions.h"

int main(int argc, char** argv){
  int row, col;
  char response;
  char* buffer; 
  char** board;
  char fileName;
  char stringBoard;
  char saveFileName;
  char** checkBoard;
 // printBuffer(buffer); 
  // start logic and populate and ize %d", temp);
  // alloc argv[1] is file name from user
  printf("\nfileName: %s", argv[1]);
 // int size;
  int size = read_file((char*)argv[1], &buffer);
  printf("\nsize: %d\n",size); 
  int temp = size;
  boardDimensions(&row, &col);
  printf("\nrow: %d\ncol: %d\n\n", row, col);  
 // printBuffer(buffer);
  makeBoard(row, col, &board);  
  populateBoard(board, buffer, row, col);
  printBoard(board, row, col);  
  
//  int temp = size; 
  printf("\nsize %d", temp);

  printf("\nbuffer before save:\n%s",buffer);

  userResponse(&response);
  printf("\nResponse: %c\n",response);
  char userArray = response;


  printf("\nuserArray: %c\n", userArray);

  while(userArray != 'q'){
    if(userArray == 'l'){
  
  
     
    }
    
    else if(userArray == 's'){
      printf("\nsize %d", temp);
      printf("\nbuffer before save:\n%s",buffer);
      
     // strcpy(
      saveFileTo(&saveFileName);
      printf("\nsize %d", size);
      printf("\nbuffer before save:\n%s",buffer);
//      printBuffer(buffer);
      write_file(&saveFileName, buffer, size);
      return 0;
    }
  }
  return 0;
 }
