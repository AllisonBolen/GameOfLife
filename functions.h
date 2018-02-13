#ifndef H_FUNCTIONS
#define H_FUNCTIONS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size );
void makeBoard(int r, int c, int **board);
void printBoard(int board, int row, int col);
void printBuffer(char *buffer);
#endif
