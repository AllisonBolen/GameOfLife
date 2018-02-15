#include "functions.h"

int main(int argc, char** argv){
  int row, col;
  char response;
  char* buffer; 
  char** board;
  char fileName;
  char* stringBoard;
  int** checkBoard;
  
  int size = read_file((char*)argv[1], &buffer); 

  boardDimensions(&row, &col);
	
  makeBoard(row, col, &board);  
  populateBoard(board, buffer, row, col);
  printBoard(board, row, col);  

  makeCheck(row, col, &checkBoard);
  populateCheck(row, col, checkBoard);
  printCheckBoard(checkBoard, row, col);
  
  
  char saveFileName[1000];
  char temparray;
	
  userResponse(&temparray);
  response = temparray;
  
  while(response != 'q'){
    printf("\nResponse: %c\n",response);
    printBoard(board, row, col);
	  
    if(response == 'l'){
      free(buffer);
      freeMem(board, row, col);
	    
      getFileFromUser(saveFileName);
      size = read_file(saveFileName, &buffer);
      
      boardDimensions(&row, &col);
      
      makeBoard(row, col, &board);
      populateBoard(board, buffer, row, col);
      printBoard(board, row, col);
    
    }
	  
    else if(response == 's'){
      saveFileTo(saveFileName);
	    
      toStringBoard(board, buffer, row, col);
      size = strlen(buffer);
	    
      write_file(saveFileName, buffer, size);
    
    }
	  
    else if(response == 'c'){
      int n, m;
	    
      for(n = 0; n < row; n++){
        for(m = 0; m < col; m++){
          getNeighbors(board, checkBoard, n, m, row, col);
        }
      }
	    
      for(n = 0; n < row; n++){
        for(m = 0; m < col; m++){
          calcNewBoard(board, checkBoard, n, m);
        }
      }
	    
      printBoard(board, row, col);
	    
    }
	  
    else if(response == 'n'){
      int nums, x, a, b, c, d; 
      getContNumFromUser(&nums);
	    
      for(x = 0; x < nums; x++ ){
	populateCheck(row,col, checkBoard);
	      
        for(a = 0; a < row; a++){
          for(b = 0; b < col; b++){
            getNeighbors(board, checkBoard, a, b, row, col);
	  }
        }
	      
        for(c = 0; c < row; c++){
          for(d = 0; d < col; d++){
            calcNewBoard(board, checkBoard, c, d);
	  }
        }  
	      
        printBoard(board, row, col);
	      
      }
    }
	  
    printBoard(board, row, col);
    toStringBoard(board, buffer, row, col);
	  
    userResponse(&temparray);
    response = temparray;
    printf("\nResponse: %c\n",response);
  
  }
	
  free(buffer);
  freeMem(board, row, col);
  return 0;
 
}
