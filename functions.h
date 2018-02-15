#ifndef H_FUNCTIONS
#define H_FUNCTIONS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//read the file, place into buffer
int read_file( char* filename, char **buffer ); 

//write to a file using data inside the buffer. Use size to stop reading buffer.
int write_file( char* filename, char *buffer, int size ); 

//create space in memory using maloc. pass in a triple pointer because board is a char** and we are 
//& it before we pass it in causing it to be a triple pointer. We use r and c as the row and columns for spaces to allocate.
void makeBoard(int row, int col, char ***board); 

//print the board to the screen pass the board along with it's row and col to be able to print the board at [row][col]. 
//The board should just be the board and not the pointer to the board because we are not over writing the board
void printBoard(char **board, int row, int col); 

//this will take values from buffer and copy them into the board at position [i][j] i<row and j<col.
void populateBoard(char **board, char* buffer, int row, int col); 

//print the buffer to the screen
void printBuffer(char *buffer); 

//grab the users response to what they would like to do next: 
//i.e.: s,l,q,c,n ..... save, load, quit, continue, continue multiple
void userResponse(char *resp); 

// grab the user response to where the user would like to save the file to
void saveFileTo(char *fileName); 

//grab everything in board and store it into stringBoard which is a 1D array of strings.
void toStringBoard(char **board, char* stringBoard, int row, int col); 

//free memory in the rows that were allocated then free the entire board.
void freeMem(char **board, int row, int col);

//allocate memory for the board that calculates neighbors
void makeCheck(int row, int col, int ***checkBoard);

//populates checkboard with all zeros and prepares it for neighbor calculation.
void populateCheck(int row, int col, int **checkBoard);

//print the checkboard to the screen for testing purposes
void printCheckBoard(int **checkBoard, int row, int col);

//check board for neighbers in all of the eight spots 
//arround the position at i, j and if they are 1 incriment checkBoard at position i,j.
void getNeighbors(char **board, int **checkBoard, int i, int j, int row, int col);

//Get the user imput for th efile they would like to load in.
void getFileFromUser(char *fileName);

//Get the number of continue iterations that the user would like to do.
void getContNumFromUser(int *num); 

//Ask the user for board dimensions.
void boardDimensions(int *row, int *col);

// free the mem for checkboard
void freeMemCheck(int **checkBoard, int row, int col); 

//generate the next genration with this
void calcNewBoard(char **board, int **checkBoard, int i, int j);
#endif
