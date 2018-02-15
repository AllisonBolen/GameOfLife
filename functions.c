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
  }
  else{
    int sz;
    fseek(in,0L, SEEK_END);
    sz=ftell(in);
    *buffer = malloc(sz * sizeof(char));
    rewind(in);
    fread(*buffer,sz,1,in);
    fclose(in);
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
  fwrite(buffer, sizeof(char), size, out);
  fclose(out);
  return 0;
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
void makeBoard(int row, int col, char ***board){
  int i, j;
  *board = (char **) malloc(row * sizeof(char *));
  for (i=0; i<row; i++){
   (*board)[i] = (char *) malloc(col * sizeof(char));
  }
} 


void populateBoard(char **board, char* buffer,  int row, int col){
  int i, j, count;
  count = 0;
  for (i = 0; i < row; i++){
    for (j = 0; j <= col; j++){
      if(buffer[count] != 10){ // comparing ascii value of new lines to whats in our buffer
        board[i][j] = buffer[count];
        count++;
      }
      else{
        count++;
      }
    }
  }
}

void printBoard(char **board, int row, int col){
  int i, j;
  printf("The board contains:\n");
  for (i = 0; i < row; i++){
    for (j = 0; j < col; j++){
      printf("%c", board[i][j]);
    }
   printf("\n");
  }
  printf("\n");
}

/* * * * * * * * * * * * 
 * user input for board size 
 * params: 
 *   r - num of rows
 *   c - num of cols
 * return: 
 *   nothing 
 * * * * * * * * * * * * */
void boardDimensions(int *row, int *col){
  printf ("\nHow many rows do you have?\n");
  scanf("\n%d",row);
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",col);
}

void printBuffer(char *buffer){
   int i, j;
   printf("The buffer contains: \n");
   for (i = 0; i < strlen(buffer); i++){
   printf("%c", buffer[i]);
   }
}

void saveFileTo(char *fileName){
  printf("\nWhat file would you like to save to:\n");
  printf("\nFile: ");
  scanf("\n%s",fileName);

}

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

void toStringBoard(char **board, char *buffer, int row, int col){
  int i, j, count;
  count = 0;
  for (i = 0; i < row; i++){
    for (j = 0; j <= col; j++){
      if(j == col){
        buffer[count]='\n';
        count++;
      }
      else{
       buffer[count]=board[i][j];
        count++;
      }
    }
  }
  buffer[count] = '\0';
}

void freeMem(char **board, int row, int col){
  int i;
  for (i = 0; i < row; i++){
    free(board[i]);
  }
  free(board);
}

void freeMemCheck(int **checkBoard, int row, int col){
  int i;
  for (i = 0; i < row; i++){
    free(checkBoard[i]);
  }
  free(checkBoard);
}

void makeCheck(int row, int col, int ***checkBoard){
  int i, j;
  *checkBoard = (int **) malloc(row * sizeof(int *));
  for (i=0; i<row; i++){
   (*checkBoard)[i] = (int *) malloc(col * sizeof(int));
  }
}

void populateCheck(int row, int col, int **checkBoard){
  int i, j;
  for(i = 0; i < row; i++){
    for(j = 0;j < col; j++){
      checkBoard[i][j]=0;
    }
  }
}

void printCheckBoard(int **checkBoard, int row, int col){
  int i, j;
  printf("The check board contains:\n");
  for (i = 0; i < row; i++){
    for (j = 0; j < col; j++){
      printf("%d", checkBoard[i][j]);
    }
   printf("\n");
  }
}

void getNeighbors(char **board, int **checkBoard, int i, int j, int row, int col){
  int n, m;
  for(n = i - 1; n <= i+1; n++){
    for(m = j - 1; m <= j+1; m++){
       if((n > -1) &&  (m > -1) && (n < row)  && (m < col)){
        if( n == i && m == j){
          }
         else if(board[n][m]  == '1'){      
          checkBoard[i][j]++;
        }
      }
    }
  }
}

void getFileFromUser(char *fileName){
  printf("\nWhat file would you like to load from:\n");
  printf("\nFile: ");
  scanf("\n%s", fileName);
}

void getContNumFromUser(int *num){
  printf("\nHow many generations would you like to run.\n");
  printf("\nNumber: ");
  scanf("\n%d",num);
}

void calcNewBoard(char **board, int **checkBoard, int i, int j){
  if(board[i][j]=='1' && checkBoard[i][j] < 2){ //overcrowding
    board[i][j]='2';
  }
  else if(board[i][j]=='1' && checkBoard[i][j] > 3){
    board[i][j]='2';
  }
  else if(board[i][j] =='1' && (checkBoard[i][j] == 2 || checkBoard[i][j] == 3)){
    board[i][j]='1';
  }
  else if(board[i][j]=='2' && checkBoard[i][j]==3){
    board[i][j]='1';
  }
  else if(board[i][j]=='0' && checkBoard[i][j]==3){
    board[i][j]='1';
  }
}
