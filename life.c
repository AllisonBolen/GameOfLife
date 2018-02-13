#include "functions.h"

int main(int argc, int** argv[]){
  
  int row, col;
  char response;
  char* buffer; 
  int* board;
  char fileName, saveFileName;
  char** checkBoard;
 // printBuffer(buffer); 
  // start logic and populate and malloc argv[1] is file name from user
  printf("\nfileName: %s", argv[1]);
 // int size;
  int size = read_file((char*)argv[1], &buffer);
  printf("\nsize: %d\n",size); 
  boardDimensions(&row, &col);
  printf("\nrow: %d\ncol: %d\n\n", row, col);  
  printBuffer(buffer);
  makeBoard(row, col, &board);  
  
  return 0;
 }
