#include "functions.h"

int main(int argc, char** argv){
  /** The row and column of the board **/
  int row, col;

  /** The character for the users response **/
  char response;
	
  /** The buffer that holds what we are doing with the board **/
  char* buffer; 

  /**The board that shows what we are doing each step of the game **/
  char** board;
	
  /** The fileName that we read in **/
  char fileName;

  /** The Board that holds all of the neighbors of each cell in the board */
  int** checkBoard;
  
  /** Creates the size of the board by reading in the file **/
  int size = read_file((char*)argv[1], &buffer);   //reads in the size of the file and saves it to size

  /** Creates an array to pass the FileName to when saving a file **/
  char saveFileName[1000];
	
  /** creates a temperary value to hold manipulate and set equal to the response **/
  char temparray;
  
  //Asks for the board dimensions
  boardDimensions(&row, &col);
	
  //creates the board, and populates it before printing it	
  makeBoard(row, col, &board);  
  populateBoard(board, buffer, row, col);
  printBoard(board, row, col);  

  //creates checkBoard, and populates it
  makeCheck(row, col, &checkBoard);
  populateCheck(row, col, checkBoard);
       	
  //asks the user what they would like to do after reading in their file
  userResponse(&temparray);
  response = temparray;
  
  //loops through the responses and what they do
  while(response != 'q'){
    //prints the response and the board to show the user what they have so far
    printf("\nResponse: %c\n",response);
    printBoard(board, row, col);
	  
    //Executes if the user would like to load a file	  
    if(response == 'l'){
      //frees the old buffer and board to create room for the new one being loaded in
      free(buffer);
      freeMem(board, row, col);
	    
      //Asks the user what file they would like to load in and sets the size to that file
      getFileFromUser(saveFileName);
      size = read_file(saveFileName, &buffer);
      
      //Asks the user for the dimensions of that board being loaded in
      boardDimensions(&row, &col);
      
      //creates the board, and populates it before printing it
      makeBoard(row, col, &board);
      populateBoard(board, buffer, row, col);
      printBoard(board, row, col);
    
    }
	  
    //Executes if the user would like to save a file
    else if(response == 's'){
      //Asks the user what file they would like to save to
      saveFileTo(saveFileName);

      //Converts their board into a string and saves it into the buffer to get ready for writing to the file	    
      toStringBoard(board, buffer, row, col);
      size = strlen(buffer);

      //Writes the buffer to the save file	    
      write_file(saveFileName, buffer, size);
    
    }
	  
    //Executes if the user would like to continue one itteration of the game
    else if(response == 'c'){
      int n, m; //variables that we use for our for loops
	    
      //Loops through the board to find the cells neighbors and adds it to the cell of the checkBoard
      for(n = 0; n < row; n++){
        for(m = 0; m < col; m++){
          getNeighbors(board, checkBoard, n, m, row, col);
        }
      }
	    
      //Compares the board and checkBoard and creates the new board
      for(n = 0; n < row; n++){
        for(m = 0; m < col; m++){
          calcNewBoard(board, checkBoard, n, m);
        }
      }
	    
      //prints the board so the user knows what they did
      printBoard(board, row, col);
	    
    }
	
    //Executes if the user would like to continue multiple itterations of the game
    else if(response == 'n'){
      int nums, x, a, b, c, d; //variables that are used to control our for loops
      getContNumFromUser(&nums); //gets the number of times the user would like to itterate
	    
      //Loops the number of times the user would like to itterate
      for(x = 0; x < nums; x++ ){
	populateCheck(row,col, checkBoard); //populates the checkBoard to be able to write later on
	      
	//Loops through the board to find the cells neighbors and adds it to the cell of the checkBoard
	for(a = 0; a < row; a++){
          for(b = 0; b < col; b++){
            getNeighbors(board, checkBoard, a, b, row, col);
	  }
        }

	//Compares the board and checkBoard and creates the new board
        for(c = 0; c < row; c++){
          for(d = 0; d < col; d++){
            calcNewBoard(board, checkBoard, c, d);
	  }
        }
	
	//prints the boards at each generation completed
	printf("Generation: #%d\n",(x+1));      
        printBoard(board, row, col);
	      
      }
    }
	  
    //prints the board and changes the buffer to contain the values of the board
    //this is for the user to be able to know what they have before being asked what to do next
    printBoard(board, row, col);
    toStringBoard(board, buffer, row, col);
	  
    //asks the user what they would like to do after the previous command executed and prints their response
    userResponse(&temparray);
    response = temparray;
    printf("\nResponse: %c\n",response);
  
  }
	
  //frees the buffer, board, and checkBoard's memory that was allocated then returns 0 to end the game
  free(buffer);
  freeMem(board, row, col);
  freeMemCheck(checkBoard, row, col);	
  return 0;
 
}
