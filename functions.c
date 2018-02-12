#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"


/* * * * * * * * * * * * 
 * read file
 * params: 
 *   filename - name of file to read from
 *   buffer - id arrray to read contents into
 * return: 
 *   the size of the file read in, warning: includes the '\n' line bytes 
 * * * * * * * * * * * * */
int read_file( char* filename, char **buffer ){
  FILE* in = fopen(filename, "r");

  if (in == NULL){
    printf ("file could not be opened!\n");
    return -1;
    exit(1);
  }
  else{
    int sz;
    fseek(in,0L, SEEK_END);
    sz=ftell(in);
    *buffer = malloc(sz * sizeof(char));
    rewind(in);
   // char fName[1000] = "";
   // fName = *buffer;
   // strcpy(fName, *buffer);
   // free(*buffer);
   // printf("fName: %s\n",fName);
    fread(*buffer,sz,1,in);
  //  fread(*buffer,sz,1,in);
    return sz;
  }
}


/* * * * * * * * * * * *
 * write file
 * params:
 *   filename - name of file to read from
 *   buffer - id arrray to read contents into
 *   size -  the size to loop to for the file to be read completely
 * return:
 *   an int but why?
 * * * * * * * * * * * * * */
int write_file( char* filename, char *buffer, int size){
  FILE* out = fopen(filename, "w");
  int cols,rows;
  printf("\nHow many rows do you have?\n");
  scanf("\n%d",&rows);
 // printf("\nHow many columns do you have?\n");
 // scanf("\n%d",&cols);
  int i; 
  int j;
  char temparray[size];
  printf("Buffer:\n%s\n", buffer);
  for(i=0; i<size+rows; i++){
    printf("buffer at i: %c\n",buffer[i]);
    temparray[i] = buffer[i];
//    if(j==cols){
  //   fprintf(out, "%c", temparray[i]);
   //  j = 0;
   // }
    fprintf(out, "%c",temparray[i]);
   // j++;
  }
  printf("File has been saved successfully would you like to do anything else?\n");
}


/* * * * * * * * * * * *
 * allocate the board space
 * params:
 *   c - number of cols
 *   r - number of rows
 *   buffer - id arrray to read contents into
 *   board - the 2d array to store teh chars in
 * return:
 *   nothing
 * source: https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
 * * * * * * * * * * * * */
void makeBoard(int *r, int *c, char ***board, char *buffer){
  int i, j, count;
    // allocate space for the rows of the array to hold an array 
    *board = (char **) malloc(*r * sizeof(char *));
    //char fBoard[1000] = "";
   // char fBoArr[1000] = "";
   // strcpy(fBoard, *board);
   // free(*board);
    for (i=0; i<*r; i++){
         // allocate space for the array 
         (*board)[i] = (char *) malloc(*c * sizeof(char));
//	 strcpy(fBoArr,((*board)[i]));
//	 fBoard[i] = fBoArr;
//	 free((*board)[i]);
    }
  //  free(*board);
}

void makeCheck(int *r, int *c, int ***checkBoard){
  int i, j, count;
  // allocate space for the rows of the array to hold an array
  *checkBoard = (int **) malloc(*r * sizeof(int *));
  for (i=0; i<*r; i++)
    // allocate space for the array
    (*checkBoard)[i] = (int *) malloc(*c * sizeof(int));
}

/* * * * * * * * * * * * 
 * print the board
 * params: 
 *   board - contents of game
 *   r - num of rows
 *   c - num of cols
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void printBoard(char ***board, int *r, int *c){
  int i, j;
  printf("The board contains:\n");
  for (i = 0; i < *r; i++){
    for (j = 0; j < *c; j++){
      printf("%c", (*board)[i][j]);
    }
    printf("\n");
  }
}

void printCheckBoard(int ***board, int *r, int *c){
  int i, j;
  printf("The check board contains:\n");
  for (i = 0; i < *r; i++){
    for (j = 0; j < *c; j++){
      printf("%d", (*board)[i][j]);
    }
    printf("\n");
  }
}


/* * * * * * * * * * * * 
 * print the buffer
 * params: 
 *   buffer - contents of the buffer
 *   r - num of rows
 *   c - num of cols
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void printBuffer(char *buffer){
  int i, j;
  printf("The buffer contains: \n");
  for (i = 0; i < strlen(buffer); i++){
    printf("%c", buffer[i]);
  }
}


/* * * * * * * * * * * * 
 * populate the board
 * params: 
 *   board - contents of game
 *   r - num of rows
 *   c - num of cols
 *   buffer - the contents read from the file 
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void populateBoard(char ***board, char *buffer,  int *r, int *c){
  int i, j, count;
  count = 0;
  for (i = 0; i < *r; i++){
    for (j = 0; j <= *c; j++){
      if(buffer[count] != 10){ // comparing ascii value of new lines to whats in our buffer
        (*board)[i][j] = buffer[count];
        count++;
      }
      else{
        count++;
      }
    }
  }
}

void populateCheck(int *r, int *c, int ***checkBoard){
int i, j, count;
  for (i = 0; i < *r; i++){
    for (j = 0; j <= *c; j++){
      (*checkBoard)[i][j] = 0;
    }
  }  
}

/* * * * * * * * * * * * 
 * user input for board size 
 * params: 
 *   r - num of rows
 *   c - num of cols
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void boardDimensions(int *r, int *c){
  printf ("\nHow many rows do you have?\n");
  scanf("\n%d",r);
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",c);
  printf("\nMakeBoard:\n");
  }


/* * * * * * * * * * * * 
 * user input continuing the game or not 
 * params: 
 *   resp - user response
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void userResponse(char *resp){
  printf("\nWhat would you like to do next?\n");
  printf("\nSave: s\n");
  printf("\nLoad: l\n");
  printf("\nContinue Once: c\n");
  printf("\nContinue Multiple: n\n");
  printf("\nQuit: q\n");
  printf("\nYour response: ");
  scanf("\n%s",resp);
}


/* * * * * * * * * * * * 
 * user input for filename
 * params: 
 *   filename - user entered filename
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void getFileFromUser(char *fileName){
  printf("\nWhat file would you like to read from:\n");
  printf("\nFile: ");
  scanf("\n%s", fileName);
}


/* * * * * * * * * * * * 
 * user input or saving to a file 
 * params: 
 *   resp - user response
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void saveFileTo(char *fileName){
  printf("\nWhat file would you like to save to:\n");
  printf("\nFile: ");
  scanf("\n%s", fileName);

}


/* * * * * * * * * * * * 
 * free mem
 * params: 
 *   resp - user response
 * return: 
 *   nothing 
 * source: https://stackoverflow.com/questions/1824363/dynamic-allocation-deallocation-of-2d-3d-arrays
 * * * * * * * * * * * */
//void freeMem(char*** board, char **buffer, int *r, int *c){
void freeMem(char ***board, int *r, int *c) {
   int i, j;
   printf("\n*r: %d\n", *r);
   printf("\n*c: %d\n", *c);
   printf("The board contains:\n");
  // for(i = *r; i > -1; i--){
   // for(j=*c; j > -1; j--){      
    for (i = 0; i < *r; i++){
//       for (j = 0; j < *c; j++){
	   printf("1st free:\n");
	   printf("%s\n", (*board)[i]);
	   free((*board)[i]);
	  // printf("After free:\n");
	  // printf("%c\n", (*board)[i]);
//	 }
//	printf("%c
	//printf("2nd free:\n");
//	free(board[i]);
      }
      printf("final free:\n");
      free(**board);

}
/*      
  
  int i, j;
    //free columns
    printf("\n*r: %d\n", *r);
   // printf("\nr: %d\n", r);
    printf("\n*c: %d\n", *c);
   // printf("\nc: %d\n", c);
    printf("\nbuffer: %d\n", **buffer);
   // printf("\nboard: %d\n", **board);



    for(i = 0; i <= *r; i++){
      for(j = 0; j <= *c+1; j++){
        printf("\nboard: %d\n", board[i][j]);
	free(board[i][j]);
      }
      free(board[i]);
    }
    //free whole thing
    free(board);
}
*/
/*
void freeMem(char ***board, char **buffer, int *r, int *c){
  int i;
  //free columns
  for(i = 0; i < *r; i++){
    free((*board)[i]);
  }
  //free whole thing
  free((*board));
}

*/

void getNeighbors(char ***board, int ***checkBoard, int i, int j , int r, int c){
  int n, m;
  printf("\ni = %d", i);
  printf("\nj = %d", j);
  printf("\nr = %d", r);
  printf("\nc = %d", c);
  printf("\ncheckboard[%d][%d] = %d",i,j, (*checkBoard)[i][j]);
  for(n = i-1; n <= i+1; n++ ){
    printf("\nn = %d",n);
    for(m = j-1; m <= j+1; m++){
      printf("\nm = %d",m); 
     //if(n > -1 &&  m > -1 && n < r && m < c){
       if(n>-1){
         printf("\n HERE ONE");
         if(m> -1){ 
           printf("\n HERE TWO");
           if(n < r){
             printf("\n HERE THREE");
            if(m < c){
               printf("\n HERE FOUR");  
               printf("\nbefore ---- board[%d][%d] = %c", n, m, board[n][m]);
               printf("\nbefore ---- board[1][0] = %c", board[1][0]); 
               int thing = (int) board[n][m];
               if(thing  == 49){ 
                 printf("HERE FIVE");
                 //checkBoard[j][i] = (*checkBoard)[i][j] + 1;
                 printf("checkboard[%d][%d] = %d",i,j, (*checkBoard)[i][j]);
        }
      //}
      }
      }
      }
     }
    }
  }
}

void OverCrowding(){ 
    
}

void underPopulation(){

}

void survival(){

}

void zombie(){

}
